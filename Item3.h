#pragma once
#include "afxdialogex.h"


// CItem3 dialog
const DWORD PROCSS_TERMINATE = 0x0001;
class CItem3 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem3)

public:
	CItem3();   // standard constructor
	virtual ~CItem3();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL  OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
