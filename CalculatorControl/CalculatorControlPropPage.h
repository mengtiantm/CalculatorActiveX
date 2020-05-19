#pragma once

// CalculatorControlPropPage.h : Declaration of the CCalculatorControlPropPage property page class.


// CCalculatorControlPropPage : See CalculatorControlPropPage.cpp for implementation.

class CCalculatorControlPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCalculatorControlPropPage)
	DECLARE_OLECREATE_EX(CCalculatorControlPropPage)

// Constructor
public:
	CCalculatorControlPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_CALCULATORCONTROL };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

