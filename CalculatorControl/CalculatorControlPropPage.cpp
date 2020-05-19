// CalculatorControlPropPage.cpp : Implementation of the CCalculatorControlPropPage property page class.

#include "stdafx.h"
#include "CalculatorControl.h"
#include "CalculatorControlPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCalculatorControlPropPage, COlePropertyPage)

// Message map

BEGIN_MESSAGE_MAP(CCalculatorControlPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCalculatorControlPropPage, "CALCULATORCONT.CalculatorContPropPage.1",
	0x2a19241a, 0x2cbd, 0x4916, 0x87, 0x4c, 0x78, 0xe, 0xb3, 0x90, 0xdb, 0xb4)

// CCalculatorControlPropPage::CCalculatorControlPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CCalculatorControlPropPage

BOOL CCalculatorControlPropPage::CCalculatorControlPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CALCULATORCONTROL_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CCalculatorControlPropPage::CCalculatorControlPropPage - Constructor

CCalculatorControlPropPage::CCalculatorControlPropPage() :
	COlePropertyPage(IDD, IDS_CALCULATORCONTROL_PPG_CAPTION)
{
}

// CCalculatorControlPropPage::DoDataExchange - Moves data between page and properties

void CCalculatorControlPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CCalculatorControlPropPage message handlers
