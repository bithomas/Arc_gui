// CStartDialog.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "CStartDialog.h"
#include "afxdialogex.h"


// CStartDialog dialog

IMPLEMENT_DYNAMIC(CStartDialog, CDialogEx)

CStartDialog::CStartDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_START, pParent)
{

}

CStartDialog::~CStartDialog()
{
}

void CStartDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ReleaseToken);
}


BEGIN_MESSAGE_MAP(CStartDialog, CDialogEx)
END_MESSAGE_MAP()


// CStartDialog message handlers


BOOL CStartDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_ReleaseToken.SetWindowText(m_value);

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
BOOL CStartDialog::DestroyWindow()
{
	m_ReleaseToken.GetWindowText(m_value);
	return CDialog::DestroyWindow();
}
