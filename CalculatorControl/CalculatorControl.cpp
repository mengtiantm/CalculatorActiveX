// CalculatorControl.cpp : Implementation of CCalculatorControlApp and DLL registration.

#include "stdafx.h"
#include "CalculatorControl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCalculatorControlApp theApp;

const GUID CDECL _tlid = { 0x91D72424, 0x8F6F, 0x4BB8, { 0x86, 0x64, 0x86, 0xDC, 0xE7, 0x7E, 0x44, 0x1A } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCalculatorControlApp::InitInstance - DLL initialization

BOOL CCalculatorControlApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CCalculatorControlApp::ExitInstance - DLL termination

int CCalculatorControlApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
