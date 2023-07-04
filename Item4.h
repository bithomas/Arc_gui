#pragma once
#include "afxdialogex.h"
#include "CTAB1.h""
#include "CTAB2.h"
#include "CTAB3.h""
#include "CTAB4.h"
// CItem4 dialog

class CItem4 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem4)

public:
	CItem4();   // standard constructor
	BOOL OnInitDialog();
	virtual ~CItem4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_4 };
#endif

protected:
	//virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	BOOL  OnEraseBkgnd(CDC* pDC);
private:
	CTabCtrl* m_pTabCtrl;
	CTAB1 m_tab1;
	CTAB2 m_tab2;
	CTAB3 m_tab3;
	CTAB4 m_tab4;
};
