#pragma once
#include "afxdialogex.h"


// CItem5 dialog

class CItem5 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem5)

public:
	CItem5();   // standard constructor
	virtual ~CItem5();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL  OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};
