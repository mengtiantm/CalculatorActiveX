// CalculatorControlCtrl.cpp : Implementation of the CCalculatorControlCtrl ActiveX Control class.

#include "stdafx.h"
#include "CalculatorControl.h"
#include "CalculatorControlCtrl.h"
#include "CalculatorControlPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CCalculatorControlCtrl, COleControl)

// Message map

BEGIN_MESSAGE_MAP(CCalculatorControlCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// Dispatch map

BEGIN_DISPATCH_MAP(CCalculatorControlCtrl, COleControl)
	DISP_FUNCTION_ID(CCalculatorControlCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_STOCKPROP_BACKCOLOR()
	DISP_FUNCTION_ID(CCalculatorControlCtrl, "SetNumber", dispidSetNumber, SetNumber, VT_EMPTY, VTS_I4 VTS_I4 VTS_I4)
	DISP_FUNCTION_ID(CCalculatorControlCtrl, "Arithmetic", dispidArithmetic, Arithmetic, VT_I4, VTS_I4 VTS_I4 VTS_I4)
	DISP_PROPERTY_NOTIFY_ID(CCalculatorControlCtrl, "Direction", dispidDirection, m_Direction, OnDirectionChanged, VT_BOOL)
END_DISPATCH_MAP()

// Event map

BEGIN_EVENT_MAP(CCalculatorControlCtrl, COleControl)
	EVENT_CUSTOM_ID("SecondMsg", eventidSecondMsg, SecondMsg, VTS_BSTR)
	EVENT_CUSTOM_ID("FirstMsg", eventidFirstMsg, FirstMsg, VTS_BSTR)
	EVENT_STOCK_CLICK()
	EVENT_CUSTOM_ID("TestEvent", eventidTestEvent, TestEvent, VTS_BSTR)
END_EVENT_MAP()

// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CCalculatorControlCtrl, 1)
	PROPPAGEID(CCalculatorControlPropPage::guid)
END_PROPPAGEIDS(CCalculatorControlCtrl)

// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCalculatorControlCtrl, "CALCULATORCONTRO.CalculatorControCtrl.1",
	0x16c40025, 0x1142, 0x4e30, 0xa9, 0x91, 0x3, 0x97, 0x25, 0x3b, 0x39, 0x3a)

// Type library ID and version

IMPLEMENT_OLETYPELIB(CCalculatorControlCtrl, _tlid, _wVerMajor, _wVerMinor)

// Interface IDs

const IID IID_DCalculatorControl = { 0x832E3E67, 0x3909, 0x4F14, { 0xBD, 0xE5, 0xFA, 0xC0, 0x1E, 0x4A, 0x17, 0xBB } };
const IID IID_DCalculatorControlEvents = { 0x5CC74BA3, 0x6875, 0x4496, { 0x96, 0x2E, 0x93, 0xE0, 0x77, 0x5E, 0x21, 0xD6 } };

// Control type information

static const DWORD _dwCalculatorControlOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCalculatorControlCtrl, IDS_CALCULATORCONTROL, _dwCalculatorControlOleMisc)
/**********************************************************************************************************/
BEGIN_INTERFACE_MAP(CCalculatorControlCtrl, COleControl)
	INTERFACE_PART(CCalculatorControlCtrl, IID_IObjectSafety, ObjSafe)
END_INTERFACE_MAP()

ULONG FAR EXPORT CCalculatorControlCtrl::XObjSafe::AddRef()
{
	METHOD_PROLOGUE(CCalculatorControlCtrl, ObjSafe);
	return pThis->ExternalAddRef();
}

ULONG FAR EXPORT CCalculatorControlCtrl::XObjSafe::Release()
{
	METHOD_PROLOGUE(CCalculatorControlCtrl, ObjSafe);
	return pThis->ExternalRelease();
}

HRESULT FAR EXPORT CCalculatorControlCtrl::XObjSafe::QueryInterface(REFIID iid, void FAR* FAR* ppvObj)
{
	METHOD_PROLOGUE(CCalculatorControlCtrl, ObjSafe);
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj);
}

const DWORD dwSupportedBits = INTERFACESAFE_FOR_UNTRUSTED_CALLER | INTERFACESAFE_FOR_UNTRUSTED_DATA;
const DWORD dwNotSupportedBits = ~dwSupportedBits;

//////////////////////////////////////////////////////////////////////////
// CCalculatorControlCtrl::XObjSafe::GetInterfaceSafetyOptions
// Allows container to query what interfaces are safe for what. We're
// optimizing significantly by ignoring which interface the caller is
// asking for.

HRESULT STDMETHODCALLTYPE CCalculatorControlCtrl::XObjSafe::GetInterfaceSafetyOptions(REFIID riid,
	DWORD __RPC_FAR *pdwSupportedOptions,
	DWORD __RPC_FAR *pdwEnabledOptions)
{
	METHOD_PROLOGUE(CCalculatorControlCtrl, ObjSafe);
	HRESULT retval = ResultFromScode(S_OK);

	// does interface exist?
	IUnknown FAR* punkInterface;

	retval = pThis->ExternalQueryInterface(&riid, (void * *)&punkInterface);
	if (retval != E_NOINTERFACE)
		punkInterface->Release(); // release it--just checking!

	// we support both kinds of safety and have always both set,
	// regardless of interface
	*pdwSupportedOptions = *pdwEnabledOptions = dwSupportedBits;
	return retval; // E_NOINTERFACE if QI failed
}

/////////////////////////////////////////////////////////////////////////////
// CCalculatorControlCtrl::XObjSafe::SetInterfaceSafetyOptions
// Since we're always safe, this is a no-brainer--but we do check to make
// sure the interface requested exists and that the options we're asked to
// set exist and are set on (we don't support unsafe mode).

HRESULT STDMETHODCALLTYPE CCalculatorControlCtrl::XObjSafe::SetInterfaceSafetyOptions(REFIID riid,
	DWORD dwOptionSetMask,
	DWORD dwEnabledOptions)
{
	METHOD_PROLOGUE(CCalculatorControlCtrl, ObjSafe);

	// does interface exist?
	IUnknown FAR* punkInterface;

	pThis->ExternalQueryInterface(&riid, (void * *)&punkInterface);
	if (punkInterface) { // interface exists
		punkInterface->Release(); // release it--just checking!
	}
	else { // interface doesn't exist
		return ResultFromScode(E_NOINTERFACE);
	}

	// can't set bits we don't support
	if (dwOptionSetMask & dwNotSupportedBits) {
		return ResultFromScode(E_FAIL);
	}

	// can't set bits we do support to zero
	dwEnabledOptions &= dwSupportedBits;

	// (we already know there are no extra bits in mask )
	if ((dwOptionSetMask & dwEnabledOptions) != dwOptionSetMask) {
		return ResultFromScode(E_FAIL);
	}

	// don't need to change anything since we're always safe
	return ResultFromScode(S_OK);
}
/**********************************************************************************************************/
// CCalculatorControlCtrl::CCalculatorControlCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CCalculatorControlCtrl

BOOL CCalculatorControlCtrl::CCalculatorControlCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CALCULATORCONTROL,
			IDB_CALCULATORCONTROL,
			afxRegApartmentThreading,
			_dwCalculatorControlOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CCalculatorControlCtrl::CCalculatorControlCtrl - Constructor

CCalculatorControlCtrl::CCalculatorControlCtrl()
{
	InitializeIIDs(&IID_DCalculatorControl, &IID_DCalculatorControlEvents);
	// TODO: Initialize your control's instance data here.
	SetInitialSize(300, 300);
	m_a = 1;
	m_b = 1;
	m_c = 2;
	m_Direction = TRUE;
}

// CCalculatorControlCtrl::~CCalculatorControlCtrl - Destructor

CCalculatorControlCtrl::~CCalculatorControlCtrl()
{
	// TODO: Cleanup your control's instance data here.
}

// CCalculatorControlCtrl::OnDraw - Drawing function

void CCalculatorControlCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	/*pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);*/
	// 设置控件的背景颜色为象牙灰
	CBrush brush(RGB(251, 255, 242));
	pdc->FillRect(rcBounds, &brush);
	// 设置文本字体的颜色、对齐方式、背景透明 
	pdc->SetTextColor(RGB(255, 255, 255));
	pdc->SetTextAlign(TA_CENTER);
	pdc->SetBkMode(TRANSPARENT);
	// 绘制3个圆  
	// 设置圆的背景色为黑色  
	CBrush brushCircle(RGB(0, 0, 0));
	// 设置圆心位置  
	POINT p1 = { 70, 150 };
	POINT p2 = { 230, p1.y };
	POINT p3 = { (p1.x + p2.x) / 2, m_Direction ? p1.y + 60 : p1.y - 60 };
	// 设置圆的半径  
	int radious = 18;
	// 画圆  
	CBrush *pBrush = pdc->SelectObject(&brushCircle);
	pdc->Ellipse(p1.x - radious, p1.y - radious, p1.x + radious, p1.y + radious);
	pdc->Ellipse(p2.x - radious, p2.y - radious, p2.x + radious, p2.y + radious);
	pdc->Ellipse(p3.x - radious, p3.y - radious, p3.x + radious, p3.y + radious);
	// 连接线  
	pdc->MoveTo(p1);
	pdc->LineTo(p3);
	pdc->LineTo(p2);
	// 在圆中写入数值
	CString strMsg;
	strMsg.Format(L"%d", m_a);
	pdc->TextOut(p1.x, p1.y - 9, strMsg);
	strMsg.Format(L"%d", m_b);
	pdc->TextOut(p2.x, p2.y - 9, strMsg);
	strMsg.Format(L"%d", m_c);
	pdc->TextOut(p3.x, p3.y - 9, strMsg);

}

// CCalculatorControlCtrl::DoPropExchange - Persistence support

void CCalculatorControlCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}


// CCalculatorControlCtrl::OnResetState - Reset control to default state

void CCalculatorControlCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


// CCalculatorControlCtrl::AboutBox - Display an "About" box to the user

void CCalculatorControlCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_CALCULATORCONTROL);
	dlgAbout.DoModal();
}


// CCalculatorControlCtrl message handlers

void CCalculatorControlCtrl::SetNumber(LONG num1, LONG num2, LONG type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	m_a = num1;
	m_b = num2;
	m_c = Arithmetic(num1, num2, type);
	// 重绘控件，调用我们的MCd函数结算结果并显示  
	Invalidate();
}


LONG CCalculatorControlCtrl::Arithmetic(LONG num1, LONG num2, LONG type)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here
	long iRet = 0;
	if (type == 1)// addition
	{
		iRet = num1 + num2;
	}
	else if (type == 2)// Subtraction
	{
		iRet = num1 - num2;
	}
	else if (type == 3)// multiplication
	{
		iRet = num1 * num2;
	}
	else// division
	{
		iRet = num1 / num2;
	}
	return iRet;
}


void CCalculatorControlCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	/*CString strMsgValue;
	strMsgValue.Format(L"%d", m_c);
	if (InCircle(point))
		FirstMsg(strMsgValue);
*/
	COleControl::OnLButtonDown(nFlags, point);
}


void CCalculatorControlCtrl::OnDirectionChanged()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your property handler code here
	Invalidate();
	SetModifiedFlag();
}

BOOL CCalculatorControlCtrl::InCircle(CPoint& point)
{
	CRect rc;
	GetClientRect(rc);
	// Determine radii
	double a = (rc.right - rc.left) / 2;
	double b = (rc.bottom - rc.top) / 2;

	// Determine x, y
	double x = point.x - (rc.left + rc.right) / 2;
	double y = point.y - (rc.top + rc.bottom) / 2;

	// Apply ellipse formula
	return ((x * x) / (a * a) + (y * y) / (b * b) <= 1);
}


void CCalculatorControlCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	TestEvent(L"My Event Test");
	COleControl::OnLButtonDblClk(nFlags, point);
}
