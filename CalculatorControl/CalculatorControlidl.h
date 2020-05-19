

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Jun 08 17:55:14 2018
 */
/* Compiler settings for CalculatorControl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CalculatorControlidl_h__
#define __CalculatorControlidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DCalculatorControl_FWD_DEFINED__
#define ___DCalculatorControl_FWD_DEFINED__
typedef interface _DCalculatorControl _DCalculatorControl;

#endif 	/* ___DCalculatorControl_FWD_DEFINED__ */


#ifndef ___DCalculatorControlEvents_FWD_DEFINED__
#define ___DCalculatorControlEvents_FWD_DEFINED__
typedef interface _DCalculatorControlEvents _DCalculatorControlEvents;

#endif 	/* ___DCalculatorControlEvents_FWD_DEFINED__ */


#ifndef __CalculatorControl_FWD_DEFINED__
#define __CalculatorControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CalculatorControl CalculatorControl;
#else
typedef struct CalculatorControl CalculatorControl;
#endif /* __cplusplus */

#endif 	/* __CalculatorControl_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_CalculatorControl_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_CalculatorControl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_CalculatorControl_0000_0000_v0_0_s_ifspec;


#ifndef __CalculatorControlLib_LIBRARY_DEFINED__
#define __CalculatorControlLib_LIBRARY_DEFINED__

/* library CalculatorControlLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_CalculatorControlLib;

#ifndef ___DCalculatorControl_DISPINTERFACE_DEFINED__
#define ___DCalculatorControl_DISPINTERFACE_DEFINED__

/* dispinterface _DCalculatorControl */
/* [uuid] */ 


EXTERN_C const IID DIID__DCalculatorControl;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("832E3E67-3909-4F14-BDE5-FAC01E4A17BB")
    _DCalculatorControl : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCalculatorControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCalculatorControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCalculatorControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCalculatorControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCalculatorControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCalculatorControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCalculatorControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCalculatorControl * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCalculatorControlVtbl;

    interface _DCalculatorControl
    {
        CONST_VTBL struct _DCalculatorControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCalculatorControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCalculatorControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCalculatorControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCalculatorControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCalculatorControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCalculatorControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCalculatorControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCalculatorControl_DISPINTERFACE_DEFINED__ */


#ifndef ___DCalculatorControlEvents_DISPINTERFACE_DEFINED__
#define ___DCalculatorControlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DCalculatorControlEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DCalculatorControlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5CC74BA3-6875-4496-962E-93E0775E21D6")
    _DCalculatorControlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCalculatorControlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCalculatorControlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCalculatorControlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCalculatorControlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCalculatorControlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCalculatorControlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCalculatorControlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCalculatorControlEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DCalculatorControlEventsVtbl;

    interface _DCalculatorControlEvents
    {
        CONST_VTBL struct _DCalculatorControlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCalculatorControlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCalculatorControlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCalculatorControlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCalculatorControlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCalculatorControlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCalculatorControlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCalculatorControlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCalculatorControlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CalculatorControl;

#ifdef __cplusplus

class DECLSPEC_UUID("16C40025-1142-4E30-A991-0397253B393A")
CalculatorControl;
#endif
#endif /* __CalculatorControlLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


