# d3d9_wrapper

[![Build status](https://ci.appveyor.com/api/projects/status/4dxo5hw1sq6p67lx?svg=true)](https://ci.appveyor.com/project/megai2/d3d9-wrapper)

Wrapper for d3d9 API that includes hooking and custom d3d9 loading

## How API functions are hooked?

API functions is wrapped around with event triggers this way:

```
wrapped_API_function(params) {
  trigger_event(API_function_pre, params);
  ret = API_function(params)
  trigger_event(API_function_post, params, ret);
}
```

Currently only IDirect3D9 and IDirect3DDevice9 calls are wrapped.

## How to work with this?

Here is quick sample on how to draw something before Present call

```
#include "gw2al_d3d9_wrapper.h"
#include "gw2al_api.h"

gw2al_api_ret gw2addon_load(gw2al_core_vtable* core_api)
{
  //get loader api
	gw2al_core_vtable* gAPI = core_api;

  //get d3d9 wrapper enable_event function
	D3D9_wrapper d3d9_wrap;
	d3d9_wrap.enable_event = (pD3D9_wrapper_enable_event)gAPI->query_function(gAPI->hash_name((wchar_t*)D3D9_WRAPPER_ENABLE_EVENT_FNAME));  
  
  //enable IDirect3DDevice9::Present pre API-call event
  d3d9_wrap.enable_event(METH_DEV_Present, WRAP_CB_PRE);
  
  //watch for this event with OnDevPrePresent callback
  D3D9_WRAPPER_WATCH_EVENT(L"change_me", L"D3D9_PRE_DEV_Present", DrawSomethingBeforePresent, 0);    
}

void DrawSomethingBeforePresent(D3D9_wrapper_event_data* evd)
{
  //evd contains pointers to API return data and original call stack pointer
  //TODO: draw something
}

```

Look include/gw2al_d3d9_wrapper.h for details.

# Installation

1. Download and extract the archive `d3d9_wrapper_*.zip` found in the [latest release](https://github.com/gw2-addon-loader/d3d9_wrapper/releases/latest).
2. Ensure there is an `addons` folder inside your GW2 installation directory. If there is not, create one yourself. With the default game install path, the result would be `C:\Program Files\Guild Wars 2\addons`.
3. Place the extracted folder `d3d9_wrapper` inside the `addons` folder.
