#pragma once
#include "afxdialogex.h"
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")

// CItem1 dialog
// Id Range for dermoscopy button 

class CItem1 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem1)

public:
	CItem1();   // standard constructor
	virtual ~CItem1();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	void ReadSystemInfo();
	void OnPaint();
	BOOL  OnEraseBkgnd(CDC* pDC);
	ULONG_PTR m_gdiplusToken;
	afx_msg void OnListExGetDispInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListExGetColor(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListExGetIcon(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListExGetToolTip(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListHdrIconClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListHdrRClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListDataChanged(NMHDR* pNMHDR, LRESULT* pResult);
	void SortVecData();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strSysInfo;
	CRect m_rect;
	HDC m_hdc;

};
