
// ArcGUIDlg.h : header file
//

#pragma once
#include "ArcGUIPropSheelDlg.h"
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")
// CArcGUIDlg dialog
class CArcGUIDlg : public CDialogEx
{
// Construction
public:
	CArcGUIDlg(CWnd* pParent = nullptr);	// standard constructor 

	CArcGUIPropSheelDlg m_dlgPropSheet;
	CWnd* pNavList;

	~CArcGUIDlg()

	{
		delete font1;
		GdiplusShutdown(m_gdiplusToken);
	}

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INNDATA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void DrawLogo();
	DECLARE_MESSAGE_MAP()
public:
	// Displays welcome text
	CStatic m_staticWelcomeText;
	CFont* font1;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_LogoImage;
	ULONG_PTR m_gdiplusToken;
};
