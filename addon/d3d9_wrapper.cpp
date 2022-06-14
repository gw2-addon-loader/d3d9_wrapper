#include "stdafx.h"
#include "build_version.h"
#include <string>

//gw2addon_get_description
//gw2addon_load
//gw2addon_unload

gw2al_addon_dsc gAddonDeps[] = {
	GW2AL_CORE_DEP_ENTRY,
	{0,0,0,0,0,0}
};

gw2al_addon_dsc gAddonDsc = {
	L"d3d9_wrapper",
	L"Wrapper for d3d9 API that includes hooking and custom d3d9 loading",
	2,
	0,
	BUILD_VERSION_REV,
	gAddonDeps
};

HMODULE custom_d3d9_module;
HMODULE custom_d3d11_module;
HMODULE custom_dxgi_module;
gw2al_hashed_name eventEnableProcName;

gw2al_core_vtable* instance::api = NULL;

IDirect3D9* OnD3D9Create()
{
	wchar_t infoBuf[4096];
	GetSystemDirectory(infoBuf, 4096);
	lstrcatW(infoBuf, L"\\d3d9.dll");

	wchar_t* (*GetD3D9CustomLib)() = (wchar_t* (*)())gAPI->query_function(gAPI->hash_name(L"D3D_wrapper_custom_d3d9_lib_query"));

	if (GetD3D9CustomLib)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading custom lib from D3D_wrapper_custom_d3d9_lib_query");
		custom_d3d9_module = LoadLibraryW(GetD3D9CustomLib());
	}
	else {
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading system d3d9");
		custom_d3d9_module = LoadLibraryW(infoBuf);
	}
	
	if (!custom_d3d9_module)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"d3d9 library failed to load");
		return 0;
	}

	typedef IDirect3D9* (WINAPI* Direct3DCreate9Func)(UINT sdkver);

	Direct3DCreate9Func d3d9create_fun = (Direct3DCreate9Func)GetProcAddress(custom_d3d9_module, "Direct3DCreate9");

	if (!d3d9create_fun)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"no Direct3DCreate9 found in d3d9.dll");
		return 0;
	}

	IDirect3D9* res = d3d9create_fun(D3D_SDK_VERSION);

	if (!res)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Direct3DCreate9 failed");
		return 0;
	}
	
	return wrap_CreateObj(res);
}

#define DX11_CREATE_FDEF IDXGIAdapter* pAdapter, D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D3D_FEATURE_LEVEL* pFeatureLevels, UINT FeatureLevels, UINT SDKVersion, const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, IDXGISwapChain** ppSwapChain, ID3D11Device5** ppDevice, D3D_FEATURE_LEVEL* pFeatureLevel, ID3D11DeviceContext** ppImmediateContext
#define DX11_CREATE_PLIST pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, ppImmediateContext

static int insideD3D11DeviceCreate = 0;

HRESULT OnD3D11Create(DX11_CREATE_FDEF)
{
	wchar_t infoBuf[4096];
	GetSystemDirectory(infoBuf, 4096);
	lstrcatW(infoBuf, L"\\d3d11.dll");

	wchar_t* (*GetD3D11CustomLib)() = (wchar_t* (*)())gAPI->query_function(gAPI->hash_name(L"D3D_wrapper_custom_d3d11_lib_query"));

	if (GetD3D11CustomLib)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading custom lib from D3D_wrapper_custom_d3d11_lib_query");
		custom_d3d11_module = LoadLibraryW(GetD3D11CustomLib());
	}
	else {
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading system d3d11");
		custom_d3d11_module = LoadLibraryW(infoBuf);
	}

	if (!custom_d3d11_module)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"d3d11 library failed to load");
		return 0;
	}

	typedef HRESULT (WINAPI* D3D11CreateDeviceAndSwapChainFunc)(DX11_CREATE_FDEF);

	D3D11CreateDeviceAndSwapChainFunc d3d11create_fun = (D3D11CreateDeviceAndSwapChainFunc)GetProcAddress(custom_d3d11_module, "D3D11CreateDeviceAndSwapChain");

	if (!d3d11create_fun)
	{
		gAPI->log_text(LL_ERR, L"d3d9_wrapper", L"no D3D11CreateDeviceAndSwapChain found in d3d11.dll");
		return 0;
	}

	++insideD3D11DeviceCreate;
	HRESULT res = d3d11create_fun(DX11_CREATE_PLIST);
	--insideD3D11DeviceCreate;

	if (res != S_OK)
	{
		wchar_t buf[1024];
		wsprintfW(buf, L"D3D11CreateDeviceAndSwapChain failed: 0x%x", std::to_wstring(res).c_str());
		gAPI->log_text(LL_ERR, L"d3d9_wrapper", buf);
		return 0;
	}

	if (insideD3D11DeviceCreate == 0)
	{
		*ppDevice = wrap_CreateDevice11(*ppDevice);
		if (ppSwapChain)
			*ppSwapChain = (IDXGISwapChain*)wrap_CreateSwapchain((IDXGISwapChain4*)*ppSwapChain);
	}

	return res;
}

static int insideDXGICreate = 0;

HRESULT OnDXGICreate(UINT ver, UINT Flags, REFIID riid, void** ppFactory)
{
	typedef HRESULT(WINAPI* DXGIFactoryCreate0)(REFIID riid, void** ppFactory);
	typedef HRESULT(WINAPI* DXGIFactoryCreate1)(REFIID riid, void** ppFactory);
	typedef HRESULT(WINAPI* DXGIFactoryCreate2)(UINT Flags, REFIID riid, void** ppFactory);

	wchar_t infoBuf[4096];
	GetSystemDirectory(infoBuf, 4096);
	lstrcatW(infoBuf, L"\\dxgi.dll");

	wchar_t* (*GetDXGICustomLib)() = (wchar_t* (*)())gAPI->query_function(gAPI->hash_name(L"D3D_wrapper_custom_dxgi_lib_query"));


	if (GetDXGICustomLib)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading custom lib from D3D_wrapper_custom_dxgi_lib_query");
		custom_dxgi_module = LoadLibraryW(GetDXGICustomLib());
	}
	else {
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"Loading system dxgi");
		custom_dxgi_module = LoadLibraryW(infoBuf);
	}

	if (!custom_dxgi_module)
	{
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", L"dxgi library failed to load");
		return 0;
	}


	DXGIFactoryCreate0 origDXGI0 = (DXGIFactoryCreate0)GetProcAddress(custom_dxgi_module, "CreateDXGIFactory");
	DXGIFactoryCreate1 origDXGI1 = (DXGIFactoryCreate1)GetProcAddress(custom_dxgi_module, "CreateDXGIFactory1");
	DXGIFactoryCreate2 origDXGI2 = (DXGIFactoryCreate2)GetProcAddress(custom_dxgi_module, "CreateDXGIFactory2");

	HRESULT ret;

	++insideDXGICreate;
	switch (ver)
	{
	case 0:
		ret = origDXGI0(riid, ppFactory);
		break;
	case 1:
		ret = origDXGI1(riid, ppFactory);
		break;
	case 2:
		ret = origDXGI2(Flags, riid, ppFactory);
		break;
	default:
		ret = E_UNEXPECTED;
	}
	--insideDXGICreate;

	if (ret != S_OK)
	{
		wchar_t buf[1024];
		wsprintfW(buf, L"CreateDXGIFactory failed: 0x%x", std::to_wstring(ret).c_str());
		gAPI->log_text(LL_INFO, L"d3d9_wrapper", buf);
		return 0;
	}

	if (insideDXGICreate == 0)
	{
		*ppFactory = wrap_CreateDXGI(*ppFactory);
	}

	return ret;
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

typedef struct d3d9_dev_Release_cp {
	union {
		IDirect3DDevice9* d9;
		ID3D11Device5* d11;
	} udev;
} d3d9_dev_Release_cp;

typedef struct dxgi_CreateSwapChain_cp {
	IDXGIFactory5* dxgi;
	IUnknown* inDevice;
	DXGI_SWAP_CHAIN_DESC* desc;
	IDXGISwapChain4** ppSwapchain;
} dxgi_CreateSwapChain_cp;

typedef struct iunk_QueryInterface_cp {
	IUnknown* base;
	REFIID iid;
	void** rptr;
} iunk_QueryInterface_cp;
#pragma pack(pop)

IDirect3DDevice9* hwDevice = nullptr;
ID3D11Device5* hwDevice11 = nullptr;

void OnPostSWCQueryInterface(wrap_event_data* data)
{
	//FIXME: looks like wrapped object will leak
	iunk_QueryInterface_cp* apiParams = (iunk_QueryInterface_cp*)data->stackPtr;

	*apiParams->rptr = (IDXGISwapChain4*)wrap_CreateSwapchain((IDXGISwapChain4*)*apiParams->rptr);
}

void OnPostDXGICreateSwapChain(wrap_event_data* data)
{
	dxgi_CreateSwapChain_cp* apiParams = (dxgi_CreateSwapChain_cp*)data->stackPtr;

	*apiParams->ppSwapchain = wrap_CreateSwapchain(*apiParams->ppSwapchain);
}

void OnPostDeviceCreate(wrap_event_data* data)
{
	d3d9_obj_CreateDevice_cp* apiParams = (d3d9_obj_CreateDevice_cp*)data->stackPtr;

	*apiParams->ret = wrap_CreateDevice(*apiParams->ret);
	
	//i guess this one device should be created one time thru entire gw2 run,
	//so we track can track unload of addons on it
	if (apiParams->v2 == D3DDEVTYPE_HAL)
	{
		hwDevice = *apiParams->ret;
	}
}

void OnPostWrappedRelease(wrap_event_data* data)
{
	d3d9_dev_Release_cp* apiParams = (d3d9_dev_Release_cp*)data->stackPtr;

	if (*((LONG*)data->ret) == 0)
	{
		if (apiParams->udev.d9 == hwDevice)
			gAPI->client_unload();

		free(*data->stackPtr);
	}
}

void OnPostWrapped11Release(wrap_event_data* data)
{
	d3d9_dev_Release_cp* apiParams = (d3d9_dev_Release_cp*)data->stackPtr;

	if (*((LONG*)data->ret) == 0)
	{
		if (apiParams->udev.d11 == hwDevice11)
			gAPI->client_unload();

		free(*data->stackPtr);
	}
}

void OnPostObjWrappedRelease(wrap_event_data* data)
{
	if (*((LONG*)data->ret) == 0)
		free(*data->stackPtr);
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

	eventEnableProcName = gAPI->hash_name(L"D3D_wrapper_enable_event");

	gAPI->register_function(&OnD3D9Create, GW2AL_CORE_FUNN_D3DCREATE_HOOK);
	gAPI->register_function(&OnD3D11Create, GW2AL_CORE_FUNN_D3D11CREATE_HOOK);
	gAPI->register_function(&OnDXGICreate, GW2AL_CORE_FUNN_DXGICREATE_HOOK);
	gAPI->register_function(&d3d9_wrapper_enable_event, eventEnableProcName);

	wrap_InitEvents();
	
	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_OBJ_CreateDevice")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostDeviceCreate,
		-1
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_DEV_Release")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostWrappedRelease,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_OBJ_Release")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostObjWrappedRelease,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_DEV11_Release")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostWrapped11Release,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_SWC_Release")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostObjWrappedRelease,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_DXGI_Release")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostObjWrappedRelease,
		0
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_DXGI_CreateSwapChain")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostDXGICreateSwapChain,
		-1
	);

	gAPI->watch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_SWC_QueryInterface")),
		gAPI->hash_name(L"d3d9 wrapper"),
		(gw2al_api_event_handler)&OnPostSWCQueryInterface,
		-1
	);

	d3d9_wrapper_enable_event(METH_OBJ_CreateDevice, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_DXGI_CreateSwapChain, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_SWC_QueryInterface, WRAP_CB_POST);

	d3d9_wrapper_enable_event(METH_OBJ_Release, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_DEV_Release, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_DEV11_Release, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_SWC_Release, WRAP_CB_POST);
	d3d9_wrapper_enable_event(METH_DXGI_Release, WRAP_CB_POST);

	return GW2AL_OK;
}

gw2al_api_ret gw2addon_unload(int gameExiting)
{
	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_OBJ_CreateDevice")),
		gAPI->hash_name(L"d3d9 wrapper")
	);

	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_DEV_Release")),
		gAPI->hash_name(L"d3d9 wrapper")
	);

	gAPI->unwatch_event(
		gAPI->query_event(gAPI->hash_name(L"D3D9_POST_OBJ_Release")),
		gAPI->hash_name(L"d3d9 wrapper")
	);

	gAPI->unregister_function(eventEnableProcName);
	gAPI->unregister_function(GW2AL_CORE_FUNN_D3DCREATE_HOOK);

	if (custom_d3d11_module)
		FreeLibrary(custom_d3d11_module);

	return GW2AL_OK;
}