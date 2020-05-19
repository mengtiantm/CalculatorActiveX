#pragma once

// CalculatorControlCtrl.h : Declaration of the CCalculatorControlCtrl ActiveX Control class.
#include <objsafe.h>

// CCalculatorControlCtrl : See CalculatorControlCtrl.cpp for implementation.

class CCalculatorControlCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCalculatorControlCtrl)

	DECLARE_INTERFACE_MAP()
	BEGIN_INTERFACE_PART(ObjSafe, IObjectSafety)
		STDMETHOD_(HRESULT, GetInterfaceSafetyOptions) (
		REFIID riid,
		DWORD __RPC_FAR *pdwSupportedOptions,
		DWORD __RPC_FAR *pdwEnabledOptions);

		STDMETHOD_(HRESULT, SetInterfaceSafetyOptions) (
			REFIID riid,
			DWORD dwOptionSetMask,
			DWORD dwEnabledOptions);
	END_INTERFACE_PART(ObjSafe);

// Constructor
public:
	CCalculatorControlCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CCalculatorControlCtrl();

	DECLARE_OLECREATE_EX(CCalculatorControlCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CCalculatorControlCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCalculatorControlCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CCalculatorControlCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		eventidTestEvent = 6L,
		eventidFirstMsg = 5L,
		eventidSecondMsg = 4L,
		dispidDirection = 6,
		dispidArithmetic = 3L,
		dispidSetNumber = 2L,
	};
protected:
	void SetNumber(LONG num1, LONG num2, LONG type);
	LONG Arithmetic(LONG num1, LONG num2, LONG type);


private:
	long m_a;
	long m_b;
	long m_c;
	
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
protected:
	void OnDirectionChanged();
	BOOL InCircle(CPoint& point);
	VARIANT_BOOL m_Direction;

	void SecondMsg(LPCTSTR eValue)
	{
		FireEvent(eventidSecondMsg, EVENT_PARAM(VTS_BSTR), eValue);
	}

	void FirstMsg(LPCTSTR eValue)
	{
		FireEvent(eventidFirstMsg, EVENT_PARAM(VTS_BSTR), eValue);
	}

	void TestEvent(LPCTSTR msg)
	{
		FireEvent(eventidTestEvent, EVENT_PARAM(VTS_BSTR), msg);
	}
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

