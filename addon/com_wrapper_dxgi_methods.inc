//IUnknown

#define WRAP_METH_NAME QueryInterface
WRAPPED_METH_DECL(WRAP_METH_NAME)(WRAPPED_THIS_ REFIID v1, void** v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME AddRef
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME Release
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// obj
#define WRAP_METH_NAME SetPrivateData
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFGUID v1,
            /* [in] */ UINT v2,
            /* [annotation][in] */ 
            _In_reads_bytes_(DataSize)  const void *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME SetPrivateDataInterface
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFGUID v1,
            /* [annotation][in] */ 
            _In_opt_  const IUnknown *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

#define WRAP_METH_NAME GetPrivateData
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFGUID v1,
            /* [annotation][out][in] */ 
            _Inout_  UINT *v2,
            /* [annotation][out] */ 
            _Out_writes_bytes_(*pDataSize)  void *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

#define WRAP_METH_NAME GetParent
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFIID v1,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// dxgi 

#define WRAP_METH_NAME EnumAdapters
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ UINT v1,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME MakeWindowAssociation
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            HWND v1,
            UINT v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME GetWindowAssociation
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  HWND *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME   

#define WRAP_METH_NAME CreateSwapChain
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  IUnknown *v1,
            /* [annotation][in] */ 
            _In_  DXGI_SWAP_CHAIN_DESC *v2,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME CreateSoftwareAdapter
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ HMODULE v1,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

// dxgi1 

#define WRAP_METH_NAME EnumAdapters1
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ UINT v1,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIAdapter1 **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME 

#define WRAP_METH_NAME IsCurrent
        WRAPPED_METH_DECL_(BOOL, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// dxgi2

#define WRAP_METH_NAME IsWindowedStereoEnabled
        WRAPPED_METH_DECL_(BOOL, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME   

#define WRAP_METH_NAME CreateSwapChainForHwnd
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  IUnknown *v1,
            /* [annotation][in] */ 
            _In_  HWND v2,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *v3,
            /* [annotation][in] */ 
            _In_opt_  const DXGI_SWAP_CHAIN_FULLSCREEN_DESC *v4,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *v5,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **v6) WRAP_CALLTHRU_V6 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME        

#define WRAP_METH_NAME CreateSwapChainForCoreWindow
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  IUnknown *v1,
            /* [annotation][in] */ 
            _In_  IUnknown *v2,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *v3,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *v4,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **v5) WRAP_CALLTHRU_V5 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME        

#define WRAP_METH_NAME GetSharedResourceAdapterLuid
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
            _In_  HANDLE v1,
            /* [annotation] */ 
            _Out_  LUID *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME RegisterStereoStatusWindow
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  HWND v1,
            /* [annotation][in] */ 
            _In_  UINT v2,
            /* [annotation][out] */ 
            _Out_  DWORD *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME RegisterStereoStatusEvent
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  HANDLE v1,
            /* [annotation][out] */ 
            _Out_  DWORD *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME UnregisterStereoStatus
        WRAPPED_METH_DECL_(void, WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][in] */ 
            _In_  DWORD v1) WRAP_CALLTHRU_V1_ CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME RegisterOcclusionStatusWindow
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  HWND v1,
            /* [annotation][in] */ 
            _In_  UINT v2,
            /* [annotation][out] */ 
            _Out_  DWORD *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME RegisterOcclusionStatusEvent
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  HANDLE v1,
            /* [annotation][out] */ 
            _Out_  DWORD *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME UnregisterOcclusionStatus
        WRAPPED_METH_DECL_(void, WRAP_METH_NAME)( WRAPPED_THIS_  
            /* [annotation][in] */ 
            _In_  DWORD v1) WRAP_CALLTHRU_V1_ CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME CreateSwapChainForComposition
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  IUnknown *v1,
            /* [annotation][in] */ 
            _In_  const DXGI_SWAP_CHAIN_DESC1 *v2,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *v3,
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGISwapChain1 **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// dxgi3    

#define WRAP_METH_NAME GetCreationFlags
        WRAPPED_METH_DECL_(UINT, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// dxgi4

#define WRAP_METH_NAME EnumAdapterByLuid
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
            _In_  LUID v1,
            /* [annotation] */ 
            _In_  REFIID v2,
            /* [annotation] */ 
            _COM_Outptr_  void **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME EnumWarpAdapter
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
            _In_  REFIID v1,
            /* [annotation] */ 
            _COM_Outptr_  void **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

// dxgi5

#define WRAP_METH_NAME CheckFeatureSupport
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            DXGI_FEATURE v1,
            /* [annotation] */ 
            _Inout_updates_bytes_(FeatureSupportDataSize)  void *v2,
            UINT v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME
