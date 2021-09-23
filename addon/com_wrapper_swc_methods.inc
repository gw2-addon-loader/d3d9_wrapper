#define WRAP_METH_NAME QueryInterface
WRAPPED_METH_DECL(WRAP_METH_NAME)(WRAPPED_THIS_ REFIID v1, void** v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME AddRef
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME Release
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME


//obj

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

#define WRAP_METH_NAME GetDevice
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFIID v1,
            /* [annotation][retval][out] */ 
            _COM_Outptr_  void **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

//swapchain

        #define WRAP_METH_NAME Present
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ UINT v1,
            /* [in] */ UINT v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetBuffer
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ UINT v1,
            /* [annotation][in] */ 
            _In_  REFIID v2,
            /* [annotation][out][in] */ 
            _COM_Outptr_  void **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME SetFullscreenState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ BOOL v1,
            /* [annotation][in] */ 
            _In_opt_  IDXGIOutput *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetFullscreenState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_opt_  BOOL *v1,
            /* [annotation][out] */ 
            _COM_Outptr_opt_result_maybenull_  IDXGIOutput **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetDesc
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME ResizeBuffers
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [in] */ UINT v1,
            /* [in] */ UINT v2,
            /* [in] */ UINT v3,
            /* [in] */ DXGI_FORMAT v4,
            /* [in] */ UINT v5) WRAP_CALLTHRU_V5 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME ResizeTarget
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  const DXGI_MODE_DESC *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetContainingOutput
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _COM_Outptr_  IDXGIOutput **v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetFrameStatistics
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_FRAME_STATISTICS *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetLastPresentCount
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  UINT *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

//swapchain1

#define WRAP_METH_NAME GetDesc1
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_DESC1 *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME GetFullscreenDesc
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_SWAP_CHAIN_FULLSCREEN_DESC *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME GetHwnd
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  HWND *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME GetCoreWindow
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  REFIID v1,
            /* [annotation][out] */ 
            _COM_Outptr_  void **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME Present1
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [in] */ UINT v1,
            /* [in] */ UINT v2,
            /* [annotation][in] */ 
            _In_  const DXGI_PRESENT_PARAMETERS *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME IsTemporaryMonoSupported
        WRAPPED_METH_DECL_(BOOL, WRAP_METH_NAME)( WRAPPED_THIS ) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME GetRestrictToOutput
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  IDXGIOutput **v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME SetBackgroundColor
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  const DXGI_RGBA *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME GetBackgroundColor
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_RGBA *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME SetRotation
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][in] */ 
            _In_  DXGI_MODE_ROTATION v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
#define WRAP_METH_NAME GetRotation
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation][out] */ 
            _Out_  DXGI_MODE_ROTATION *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

//swapchain2

#define WRAP_METH_NAME SetSourceSize
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            UINT v1,
            UINT v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME GetSourceSize
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][out] */ 
            _Out_  UINT *v1,
            /* [annotation][out] */ 
            _Out_  UINT *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME SetMaximumFrameLatency
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            UINT v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME GetMaximumFrameLatency
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][out] */ 
            _Out_  UINT *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME GetFrameLatencyWaitableObject
        WRAPPED_METH_DECL_(HANDLE, WRAP_METH_NAME) ( WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME SetMatrixTransform
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            const DXGI_MATRIX_3X2_F *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME GetMatrixTransform
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][out] */ 
            _Out_  DXGI_MATRIX_3X2_F *v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
//swapchain3

#define WRAP_METH_NAME GetCurrentBackBufferIndex
        WRAPPED_METH_DECL_(UINT, WRAP_METH_NAME) ( WRAPPED_THIS)  WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME CheckColorSpaceSupport
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE v1,
            /* [annotation][out] */ 
            _Out_  UINT *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME SetColorSpace1
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][in] */ 
            _In_  DXGI_COLOR_SPACE_TYPE v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME  

#define WRAP_METH_NAME ResizeBuffers1
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][in] */ 
            _In_  UINT v1,
            /* [annotation][in] */ 
            _In_  UINT v2,
            /* [annotation][in] */ 
            _In_  UINT v3,
            /* [annotation][in] */ 
            _In_  DXGI_FORMAT v4,
            /* [annotation][in] */ 
            _In_  UINT v5,
            /* [annotation][in] */ 
            _In_reads_(BufferCount)  const UINT *v6,
            /* [annotation][in] */ 
            _In_reads_(BufferCount)  IUnknown *const *v7) WRAP_CALLTHRU_V7 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
//swapchain4

#define WRAP_METH_NAME SetHDRMetaData
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_ 
            /* [annotation][in] */ 
            _In_  DXGI_HDR_METADATA_TYPE v1,
            /* [annotation][in] */ 
            _In_  UINT v2,
            /* [annotation][size_is][in] */ 
            _In_reads_opt_(Size)  void *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME