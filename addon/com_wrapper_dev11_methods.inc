#define WRAP_METH_NAME QueryInterface
WRAPPED_METH_DECL(WRAP_METH_NAME)(WRAPPED_THIS_ REFIID v1, void** v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME AddRef
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME

#define WRAP_METH_NAME Release
WRAPPED_METH_DECL_(ULONG, WRAP_METH_NAME)(WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF 
#undef WRAP_METH_NAME

        #define WRAP_METH_NAME CreateBuffer
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_BUFFER_DESC *v1,
            /* [annotation] */ 
              const D3D11_SUBRESOURCE_DATA *v2,
            /* [annotation] */ 
              ID3D11Buffer **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
        #define WRAP_METH_NAME CreateTexture1D
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_TEXTURE1D_DESC *v1,
            /* [annotation] */ 
              const D3D11_SUBRESOURCE_DATA *v2,
            /* [annotation] */ 
              ID3D11Texture1D **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
        #define WRAP_METH_NAME CreateTexture2D
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_TEXTURE2D_DESC *v1,
            /* [annotation] */ 
              const D3D11_SUBRESOURCE_DATA *v2,
            /* [annotation] */ 
              ID3D11Texture2D **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        
        #define WRAP_METH_NAME CreateTexture3D
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_TEXTURE3D_DESC *v1,
            /* [annotation] */ 
            _In_reads_opt_(_Inexpressible_(pDesc->MipLevels))  const D3D11_SUBRESOURCE_DATA *v2,
            /* [annotation] */ 
              ID3D11Texture3D **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateShaderResourceView
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11Resource *v1,
            /* [annotation] */ 
              const D3D11_SHADER_RESOURCE_VIEW_DESC *v2,
            /* [annotation] */ 
              ID3D11ShaderResourceView **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateUnorderedAccessView
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11Resource *v1,
            /* [annotation] */ 
              const D3D11_UNORDERED_ACCESS_VIEW_DESC *v2,
            /* [annotation] */ 
              ID3D11UnorderedAccessView **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateRenderTargetView
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11Resource *v1,
            /* [annotation] */ 
              const D3D11_RENDER_TARGET_VIEW_DESC *v2,
            /* [annotation] */ 
              ID3D11RenderTargetView **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateDepthStencilView
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11Resource *v1,
            /* [annotation] */ 
              const D3D11_DEPTH_STENCIL_VIEW_DESC *v2,
            /* [annotation] */ 
              ID3D11DepthStencilView **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateInputLayout
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_INPUT_ELEMENT_DESC *v1,
            /* [annotation] */ 
              UINT v2,
            /* [annotation] */ 
              const void *v3,
            /* [annotation] */ 
              SIZE_T v4,
            /* [annotation] */ 
              ID3D11InputLayout **v5) WRAP_CALLTHRU_V5 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateVertexShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11VertexShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateGeometryShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11GeometryShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateGeometryShaderWithStreamOutput
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              const D3D11_SO_DECLARATION_ENTRY *v3,
            /* [annotation] */ 
              UINT v4,
            /* [annotation] */ 
              const UINT *v5,
            /* [annotation] */ 
              UINT v6,
            /* [annotation] */ 
              UINT v7,
            /* [annotation] */ 
              ID3D11ClassLinkage *v8,
            /* [annotation] */ 
              ID3D11GeometryShader **v9) WRAP_CALLTHRU_V9 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreatePixelShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11PixelShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateHullShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11HullShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateDomainShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11DomainShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateComputeShader
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const void *v1,
            /* [annotation] */ 
              SIZE_T v2,
            /* [annotation] */ 
              ID3D11ClassLinkage *v3,
            /* [annotation] */ 
              ID3D11ComputeShader **v4) WRAP_CALLTHRU_V4 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateClassLinkage
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11ClassLinkage **v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateBlendState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_BLEND_DESC *v1,
            /* [annotation] */ 
              ID3D11BlendState **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateDepthStencilState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_DEPTH_STENCIL_DESC *v1,
            /* [annotation] */ 
              ID3D11DepthStencilState **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateRasterizerState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_RASTERIZER_DESC *v1,
            /* [annotation] */ 
              ID3D11RasterizerState **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateSamplerState
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_SAMPLER_DESC *v1,
            /* [annotation] */ 
              ID3D11SamplerState **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateQuery
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_QUERY_DESC *v1,
            /* [annotation] */ 
              ID3D11Query **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreatePredicate
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_QUERY_DESC *v1,
            /* [annotation] */ 
              ID3D11Predicate **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateCounter
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_COUNTER_DESC *v1,
            /* [annotation] */ 
              ID3D11Counter **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CreateDeferredContext
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            UINT v1,
            /* [annotation] */ 
              ID3D11DeviceContext **v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME OpenSharedResource
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              HANDLE v1,
            /* [annotation] */ 
              REFIID v2,
            /* [annotation] */ 
              void **v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CheckFormatSupport
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              DXGI_FORMAT v1,
            /* [annotation] */ 
              UINT *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CheckMultisampleQualityLevels
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              DXGI_FORMAT v1,
            /* [annotation] */ 
              UINT v2,
            /* [annotation] */ 
              UINT *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CheckCounterInfo
        WRAPPED_METH_DECL_(void, WRAP_METH_NAME) ( WRAPPED_THIS_
            /* [annotation] */ 
              D3D11_COUNTER_INFO *v1) WRAP_CALLTHRU_V1_ CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CheckCounter
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              const D3D11_COUNTER_DESC *v1,
            /* [annotation] */ 
              D3D11_COUNTER_TYPE *v2,
            /* [annotation] */ 
              UINT *v3,
            /* [annotation] */ 
            _Out_writes_opt_(*pNameLength)  LPSTR v4,
            /* [annotation] */ 
              UINT *v5,
            /* [annotation] */ 
            _Out_writes_opt_(*pUnitsLength)  LPSTR v6,
            /* [annotation] */ 
              UINT *v7,
            /* [annotation] */ 
            _Out_writes_opt_(*pDescriptionLength)  LPSTR v8,
            /* [annotation] */ 
              UINT *v9) WRAP_CALLTHRU_V9 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME CheckFeatureSupport
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            D3D11_FEATURE v1,
            /* [annotation] */ 
              void *v2,
            UINT v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetPrivateData
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              REFGUID v1,
            /* [annotation] */ 
            _Inout_  UINT *v2,
            /* [annotation] */ 
            _Out_writes_bytes_opt_(*pDataSize)  void *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME SetPrivateData
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              REFGUID v1,
            /* [annotation] */ 
              UINT v2,
            /* [annotation] */ 
            _In_reads_bytes_opt_(DataSize)  const void *v3) WRAP_CALLTHRU_V3 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME SetPrivateDataInterface
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              REFGUID v1,
            /* [annotation] */ 
              const IUnknown *v2) WRAP_CALLTHRU_V2 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetFeatureLevel
        WRAPPED_METH_DECL_(D3D_FEATURE_LEVEL, WRAP_METH_NAME) ( WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetCreationFlags
        WRAPPED_METH_DECL_(UINT, WRAP_METH_NAME) ( WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetDeviceRemovedReason
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetImmediateContext
        WRAPPED_METH_DECL_(void, WRAP_METH_NAME)( WRAPPED_THIS_
            /* [annotation] */ 
              ID3D11DeviceContext **v1) WRAP_CALLTHRU_V1_ CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME SetExceptionMode
        WRAPPED_METH_DECL(WRAP_METH_NAME)( WRAPPED_THIS_
            UINT v1) WRAP_CALLTHRU_V1 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
        #define WRAP_METH_NAME GetExceptionMode
        WRAPPED_METH_DECL_(UINT, WRAP_METH_NAME)( WRAPPED_THIS) WRAP_CALLTHRU_V0 CUSTOM_ENDLINE_DEF
#undef WRAP_METH_NAME
