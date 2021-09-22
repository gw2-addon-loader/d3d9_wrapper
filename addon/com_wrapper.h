#pragma once

#include "stdafx.h"

typedef struct com_vtable {
	void* methods[1024];
} com_vtable;

#pragma pack(push, 1)
typedef struct wrapped_com_obj {
	com_vtable* vtable;
	union {
		IDirect3D9* orig_obj;
		IDirect3DDevice9* orig_dev;
		ID3D11Device5* orig_dev11;
		IDXGISwapChain* orig_swc;
	};
} wrapped_com_obj;
#pragma pack(pop)

#define WRAPPED_METH_DECL_(a,b) WRAPPED_METH_PREFIX(b)
#define WRAPPED_METH_DECL(b) WRAPPED_METH_DECL_(HRESULT, b)

#define WRAPPED_THIS wrapped_com_obj* _this
#define WRAPPED_THIS_ wrapped_com_obj* _this,

#define WRAP_CALLTHRU_V0
#define WRAP_CALLTHRU_V1
#define WRAP_CALLTHRU_V2
#define WRAP_CALLTHRU_V3
#define WRAP_CALLTHRU_V4
#define WRAP_CALLTHRU_V5
#define WRAP_CALLTHRU_V6
#define WRAP_CALLTHRU_V7
#define WRAP_CALLTHRU_V8
#define WRAP_CALLTHRU_V9
#define WRAP_CALLTHRU_V10
#define WRAP_CALLTHRU_V11
#define WRAP_CALLTHRU_V12

#define WRAP_CALLTHRU_V0_
#define WRAP_CALLTHRU_V1_
#define WRAP_CALLTHRU_V2_
#define WRAP_CALLTHRU_V3_
#define WRAP_CALLTHRU_V4_
#define WRAP_CALLTHRU_V5_
#define WRAP_CALLTHRU_V6_
#define WRAP_CALLTHRU_V7_
#define WRAP_CALLTHRU_V8_
#define WRAP_CALLTHRU_V9_
#define WRAP_CALLTHRU_V10_
#define WRAP_CALLTHRU_V11_
#define WRAP_CALLTHRU_V12_

#define __SPECIAL_IGNORANCE(...) 

#define CUSTOM_ENDLINE_DEF 

typedef enum d3d9_vtable_method {

#define WRAPPED_METH_PREFIX(b) METH_DEV_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) METH_OBJ_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) METH_DEV11_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) METH_SWC_##b, __SPECIAL_IGNORANCE
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

	METHOD_WRAP_COUNT
} d3d9_vtable_method;

#undef CUSTOM_ENDLINE_DEF
#undef WRAPPED_METH_DECL_
#define WRAPPED_METH_DECL_(a,b) a WINAPI WRAPPED_METH_PREFIX(b)

typedef enum vtable_wrap_mode {
	WRAP_PASSTHRU = 0,
	WRAP_CB_PRE = 1,
	WRAP_CB_POST = 2,
	WRAP_CB_PRE_POST = 3
} vtable_wrap_mode;

IDirect3DDevice9* wrap_CreateDevice(IDirect3DDevice9* origDev);
IDirect3D9* wrap_CreateObj(IDirect3D9* origObj);
ID3D11Device5* wrap_CreateDevice11(ID3D11Device5* origDev);
IDXGISwapChain* wrap_CreateSwapchain(IDXGISwapChain* origSwc);

typedef struct wrap_event_data {
	void* ret;
	wrapped_com_obj** stackPtr;
} wrap_event_data;

void wrap_SwitchMethod(d3d9_vtable_method method, vtable_wrap_mode mode);

void wrap_InvokeEvent(d3d9_vtable_method method, UINT isPre, wrapped_com_obj** stackPtr, void* ret);

void wrap_InitEvents();

