#include "stdafx.h"

#undef WRAPPED_METH_DECL_
#define WRAPPED_METH_DECL_(a,b) WRAPPED_METH_PREFIX(b)

#define CUSTOM_ENDLINE_DEF 

static void* wrap_pass_vtable[METHOD_WRAP_COUNT+1] = {
	
#define WRAPPED_METH_PREFIX(b) wrap_pass_dev_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_obj_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_dev11_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_swc_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_dxgi_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

	0
};

static void* wrap_pre_vtable[METHOD_WRAP_COUNT+1] = {

#define WRAPPED_METH_PREFIX(b) wrap_pre_dev_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_obj_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_dev11_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_swc_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_dxgi_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

	0
};

static void* wrap_post_vtable[METHOD_WRAP_COUNT+1] = {

#define WRAPPED_METH_PREFIX(b) wrap_post_dev_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_obj_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dev11_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_swc_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dxgi_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

	0
};

static void* wrap_prepost_vtable[METHOD_WRAP_COUNT+1] = {

#define WRAPPED_METH_PREFIX(b) wrap_prepost_dev_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_obj_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_dev11_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_swc_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dxgi_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

	0
};

#undef CUSTOM_ENDLINE_DEF 

static void** wrap_vtable_arr[] = {
	wrap_pass_vtable,
	wrap_pre_vtable,
	wrap_post_vtable,
	wrap_prepost_vtable
};

void* g_main_vtable[METHOD_WRAP_COUNT];

gw2al_event_id preCallEvents[METHOD_WRAP_COUNT];
gw2al_event_id postCallEvents[METHOD_WRAP_COUNT];

IDirect3DDevice9 * wrap_CreateDevice(IDirect3DDevice9 * origDev)
{
	wrapped_com_obj* ret = (wrapped_com_obj*)malloc(sizeof(wrapped_com_obj));

	ret->vtable = (com_vtable*)&g_main_vtable[METH_DEV_QueryInterface];
	ret->orig_dev = origDev;

	return (IDirect3DDevice9*)ret;
}

IDirect3D9 * wrap_CreateObj(IDirect3D9 * origObj)
{
	wrapped_com_obj* ret = (wrapped_com_obj*)malloc(sizeof(wrapped_com_obj));

	ret->vtable = (com_vtable*)&g_main_vtable[METH_OBJ_QueryInterface];
	ret->orig_obj = origObj;

	return (IDirect3D9*)ret;
}

ID3D11Device5* wrap_CreateDevice11(ID3D11Device5* origDev)
{
	wrapped_com_obj * ret = (wrapped_com_obj*)malloc(sizeof(wrapped_com_obj));

	ret->vtable = (com_vtable*)&g_main_vtable[METH_DEV11_QueryInterface];
	ret->orig_dev11 = origDev;

	return (ID3D11Device5*)ret;
}

IDXGISwapChain4* wrap_CreateSwapchain(IDXGISwapChain4* origSwc)
{
	wrapped_com_obj* ret = (wrapped_com_obj*)malloc(sizeof(wrapped_com_obj));

	ret->vtable = (com_vtable*)&g_main_vtable[METH_SWC_QueryInterface];
	ret->orig_swc = origSwc;

	return (IDXGISwapChain4*)ret;
}

void* wrap_CreateDXGI(void* origDXGI)
{
	wrapped_com_obj* ret = (wrapped_com_obj*)malloc(sizeof(wrapped_com_obj));

	ret->vtable = (com_vtable*)&g_main_vtable[METH_DXGI_QueryInterface];
	ret->orig_dxgi = (IDXGIFactory5*)origDXGI;

	return (void*)ret;
}

void wrap_SwitchMethod(d3d9_vtable_method method, vtable_wrap_mode mode)
{
	g_main_vtable[method] = wrap_vtable_arr[mode][method];
}

void wrap_InvokeEvent(d3d9_vtable_method method, UINT isPre, wrapped_com_obj** stackPtr, void* ret)
{
	//megai2: maybe passing api return in pre event is too much, but adding that later for some reason will be bad thing
	wrap_event_data eventData = {
		ret,
		stackPtr
	};

	if (isPre)
		gAPI->trigger_event(preCallEvents[method], &eventData);
	else 
		gAPI->trigger_event(postCallEvents[method], &eventData);
}

void wrap_InitEvents()
{
	#undef WRAPPED_METH_DECL_
	#define CUSTOM_ENDLINE_DEF 
	#define WRAPPED_METH_DECL_(a,b) WRAPPED_METH_PREFIX(b)
	#define EVENT_NAME_STR_S(a) L#a
	#define EVENT_NAME_STR(a,b) EVENT_NAME_STR_S(D3D9_## b ## a)

	//megai2: event name is like D3D9_POST_DEV_Present

	#define WRAPPED_METH_PREFIX(b) \
		 preCallEvents[METH_DEV_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DEV_##b, PRE_))); \
		postCallEvents[METH_DEV_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DEV_##b, POST_))); \
		g_main_vtable[METH_DEV_##b] = wrap_pass_vtable[METH_DEV_##b]; \
		__SPECIAL_IGNORANCE
	#include "com_wrapper_dev_methods.inc"
	#undef WRAPPED_METH_PREFIX	

	#define WRAPPED_METH_PREFIX(b) \
		 preCallEvents[METH_OBJ_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(OBJ_##b, PRE_))); \
		postCallEvents[METH_OBJ_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(OBJ_##b, POST_))); \
		g_main_vtable[METH_OBJ_##b] = wrap_pass_vtable[METH_OBJ_##b]; \
		__SPECIAL_IGNORANCE
	#include "com_wrapper_obj_methods.inc"
	#undef WRAPPED_METH_PREFIX

	#define WRAPPED_METH_PREFIX(b) \
		 preCallEvents[METH_DEV11_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DEV11_##b, PRE_))); \
		postCallEvents[METH_DEV11_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DEV11_##b, POST_))); \
		g_main_vtable[METH_DEV11_##b] = wrap_pass_vtable[METH_DEV11_##b]; \
		__SPECIAL_IGNORANCE
	#include "com_wrapper_dev11_methods.inc"
	#undef WRAPPED_METH_PREFIX

	#define WRAPPED_METH_PREFIX(b) \
		 preCallEvents[METH_SWC_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(SWC_##b, PRE_))); \
		postCallEvents[METH_SWC_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(SWC_##b, POST_))); \
		g_main_vtable[METH_SWC_##b] = wrap_pass_vtable[METH_SWC_##b]; \
		__SPECIAL_IGNORANCE
	#include "com_wrapper_swc_methods.inc"
	#undef WRAPPED_METH_PREFIX

	#define WRAPPED_METH_PREFIX(b) \
		 preCallEvents[METH_DXGI_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DXGI_##b, PRE_))); \
		postCallEvents[METH_DXGI_##b] = gAPI->query_event(gAPI->hash_name((wchar_t*)EVENT_NAME_STR(DXGI_##b, POST_))); \
		g_main_vtable[METH_DXGI_##b] = wrap_pass_vtable[METH_DXGI_##b]; \
		__SPECIAL_IGNORANCE
	#include "com_wrapper_dxgi_methods.inc"
	#undef WRAPPED_METH_PREFIX

}
