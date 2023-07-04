#pragma once
#include "afxdialogex.h"


// CTAB4 dialog

class CTAB4 : public CDialogEx
{
	DECLARE_DYNAMIC(CTAB4)

public:
	CTAB4(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTAB4();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
