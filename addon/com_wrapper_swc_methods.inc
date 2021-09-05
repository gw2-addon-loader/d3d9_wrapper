#define WRAP_METH_NAME QueryInterface
WRAPPED_METH_DECL(WRAP_METH_NAME)(WRAPPED_THIS_ REFIID v1, void** v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME AddRef
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME Release
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

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
