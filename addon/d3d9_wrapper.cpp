#include "stdafx.h"
#include "build_version.h"

//gw2addon_get_description
//gw2addon_load
//gw2addon_unload

gw2al_addon_dsc gAddonDeps[] = {
	{
		L"loader_core",
		L"whatever",
		0,
		1,
		1,
		0
	},
	{0,0,0,0,0,0}
};

gw2al_addon_dsc gAddonDsc = {
	L"d3d9_wrapper",
	L"Wrapper for d3d9 API that includes hooking and custom d3d9 loading",
	1,
	0,
	BUILD_VERSION_REV,
	gAddonDeps
};

HMODULE custom_d3d9_module;
gw2al_hashed_name eventEnableProcName;

gw2al_core_vtable* instance::api = NULL;

IDirect3D9* OnD3D9Create()
{
	wchar_t infoBuf[4096];
	GetSystemDirectory(infoBuf, 4096);
	lstrcatW(infoBuf, L"\\d3d9.dll");

	wchar_t* (*GetD3D9CustomLib)() = (wchar_t* (*)())gAPI->query_function(gAPI->hash_name((wchar_t*)L"D3D_wrapper_custom_d3d9_lib_query"));

	if (GetD3D9CustomLib)
	{
		gAPI->log_text(LL_INFO, (wchar_t*)L"d3d9_wrapper", (wchar_t*)L"Loading custom lib from D3D_wrapper_custom_d3d9_lib_query");
		custom_d3d9_module = LoadLibraryW(GetD3D9CustomLib());
	}
	else {
		gAPI->log_text(LL_INFO, (wchar_t*)L"d3d9_wrapper", (wchar_t*)L"Loading system d3d9");
		custom_d3d9_module = LoadLibraryW(infoBuf);
	}
	
	if (!custom_d3d9_module)
	{
		gAPI->log_text(LL_INFO, (wchar_t*)L"d3d9_wrapper", (wchar_t*)L"d3d9 library failed to load");
		return 0;
	}

	typedef IDirect3D9* (WINAPI* Direct3DCreate9Func)(UINT sdkver);

	Direct3DCreate9Func d3d9create_fun = (Direct3DCreate9Func)GetProcAddress(custom_d3d9_module, "Direct3DCreate9");

	if (!d3d9create_fun)
	{
		gAPI->log_text(LL_INFO, (wchar_t*)L"d3d9_wrapper", (wchar_t*)L"no Direct3DCreate9 found in d3d9.dll");
		return 0;
	}

	IDirect3D9* res = d3d9create_fun(D3D_SDK_VERSION);

	if (!res)
	{
		gAPI->log_text(LL_INFO, (wchar_t*)L"d3d9_wrapper", (wchar_t*)L"Direct3DCreate9 failed");
		return 0;
	}
	
	return wrap_CreateObj(res);
}

gw2al_addon_dsc* gw2addon_get_description()
{
	return &gAddonDsc;
}

#pragma pack(push, 1)
typedef struct d3d9_obj_CreateDevice_cp {
	IDirect3D9* obj;
	UINT pad0;
	UINT v1;
	UINT pad1;
	D3DDEVTYPE v2;
	HWND v3;
	UINT pad2;
	DWORD v4;
	D3DPRESENT_PARAMETERS* v5;
	IDirect3DDevice9** ret;
} d3d9_obj_CreateDevice_cp;
#pragma pack(pop)

void OnPostDeviceCreate(wrap_event_data* data)
{
	d3d9_obj_CreateDevice_cp* apiParams = (d3d9_obj_CreateDevice_cp*)data->stackPtr;

	*apiParams->ret = wrap_CreateDevice(*apiParams->ret);
}

void OnPostWrappedRelease(wrap_event_data* data)
{
	if (*((LONG*)data->ret) == 0)
	{
		free(*data->stackPtr);
	}
}

void OnPostObjWrappedRelease(wrap_event_data* data)
{
	if (*((LONG*)data->ret) == 0)
	{
		free(*data->stackPtr);

		//TODO: find  more nice way to detect client unload
		gAPI->client_unload();
	}
}

vtable_wrap_mode d3d9_wrapper_event_state[METHOD_WRAP_COUNT] = { WRAP_PASSTHRU };

void d3d9_wrapper_enable_event(d3d9_vtable_method method, vtable_wrap_mode mode)
{
	if (method >= METHOD_WRAP_COUNT)
		return;

	if (d3d9_wrapper_event_state[method] == WRAP_CB_PRE_POST)
		return;

	if (d3d9_wrapper_event_state[method] != mode)
	{
		switch (d3d9_wrapper_event_state[method])
		{
			case WRAP_PASSTHRU:
			{
				wrap_SwitchMethod(method, mode);
				d3d9_wrapper_event_state[method] = mode;
			}
			break;
			case WRAP_CB_PRE:
			{
				if (mode > WRAP_CB_PRE)
				{
					wrap_SwitchMethod(method, WRAP_CB_PRE_POST);
					d3d9_wrapper_event_state[method] = WRAP_CB_PRE_POST;
				}
			}
			break;
			case WRAP_CB_POST:
			{
				if ((mode != WRAP_CB_POST) && (mode != WRAP_PASSTHRU))
				{
					wrap_SwitchMethod(method, WRAP_CB_PRE_POST);
					d3d9_wrapper_event_state[method] = WRAP_CB_PRE_POST;
				}
			}
			break;
		}
	}
}

gw2al_api_ret gw2addon_load(gw2al_core_vtable* core_api)
{
	gAPI = core_api;

	eventEnableProcName = gAPI->hash_name((wchar_t*)L"D3D_wrapper_enable_event");

	gAPI->register_function(&OnD3D9Create, GW2AL_CORE_FUNN_D3DCREATE_HOOK);
	gAPI->register_function(&d3d9_wrapper_enable_event, eventEnableProcName);

	wrap_InitEvents();
	
	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_OBJ_CreateDevice")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostDeviceCreate,
		-1
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_DEV_Release")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostWrappedRelease,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_OBJ_Release")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostObjWrappedRelease,
		0
	);

	d3d9_wrapper_enable_event(METH_OBJ_CreateDevice, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_OBJ_Release, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_DEV_Release, WRAP_CB_POST);

	return GW2AL_OK;
}

gw2al_api_ret gw2addon_unload(int gameExiting)
{
	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_OBJ_CreateDevice")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper")
	);

	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_DEV_Release")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper")
	);

	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name((wchar_t*)L"D3D9_POST_OBJ_Release")),
		gAPI->hash_name((wchar_t*)L"d3d9 wrapper")
	);

	gAPI->unregister_function(eventEnableProcName);
	gAPI->unregister_function(GW2AL_CORE_FUNN_D3DCREATE_HOOK);

	if (custom_d3d9_module)
		FreeLibrary(custom_d3d9_module);

	return GW2AL_OK;
}