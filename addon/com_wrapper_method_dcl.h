#pragma once

#include "stdafx.h"

#define CUSTOM_ENDLINE_DEF ;

#define WRAPPED_METH_PREFIX(b) wrap_pass_dev_##b
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_dev_##b
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dev_##b
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_dev_##b
#include "com_wrapper_dev_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_obj_##b
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_obj_##b
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_obj_##b
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_obj_##b
#include "com_wrapper_obj_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_dev11_##b
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_dev11_##b
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dev11_##b
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_dev11_##b
#include "com_wrapper_dev11_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_swc_##b
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_swc_##b
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_swc_##b
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_swc_##b
#include "com_wrapper_swc_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pass_dxgi_##b
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_pre_dxgi_##b
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_post_dxgi_##b
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

#define WRAPPED_METH_PREFIX(b) wrap_prepost_dxgi_##b
#include "com_wrapper_dxgi_methods.inc"
#undef WRAPPED_METH_PREFIX

#undef CUSTOM_ENDLINE_DEF
