#pragma once
#include "afxdialogex.h"


// CItem6 dialog

class CItem6 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem6)

public:
	CItem6();   // standard constructor
	virtual ~CItem6();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL  OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
