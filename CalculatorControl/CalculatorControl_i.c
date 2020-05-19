

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, LIBID_CalculatorControlLib,0x91D72424,0x8F6F,0x4BB8,0x86,0x64,0x86,0xDC,0xE7,0x7E,0x44,0x1A);


MIDL_DEFINE_GUID(IID, DIID__DCalculatorControl,0x832E3E67,0x3909,0x4F14,0xBD,0xE5,0xFA,0xC0,0x1E,0x4A,0x17,0xBB);


MIDL_DEFINE_GUID(IID, DIID__DCalculatorControlEvents,0x5CC74BA3,0x6875,0x4496,0x96,0x2E,0x93,0xE0,0x77,0x5E,0x21,0xD6);


MIDL_DEFINE_GUID(CLSID, CLSID_CalculatorControl,0x16C40025,0x1142,0x4E30,0xA9,0x91,0x03,0x97,0x25,0x3B,0x39,0x3A);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



