// CStopNextDlg.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "CStopNextDlg.h"
#include "afxdialogex.h"


// CStopNextDlg dialog

IMPLEMENT_DYNAMIC(CStopNextDlg, CDialogEx)

CStopNextDlg::CStopNextDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STOP_NEXT_DLG, pParent)
{

}

CStopNextDlg::~CStopNextDlg()
{
}

void CStopNextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CStopNextDlg, CDialogEx)
END_MESSAGE_MAP()


// CStopNextDlg message handlers


BOOL CStopNextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CWnd* pWnd = GetDlgItem(IDC_STATIC_STOP);
	if (pWnd && pWnd->GetSafeHwnd())
	{
		pWnd->SetWindowText(m_Data);
	}
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
int CStopNextDlg::SetValue(CString str)
{
	m_Data = str;
	return 1;
}
int CStopNextDlg::GetValue(CString& str)
{
	str = m_Data;
	return 1;
}