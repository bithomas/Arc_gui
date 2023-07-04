// CStopDialog.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "CStopDialog.h"
#include "afxdialogex.h"


// CStopDialog dialog

IMPLEMENT_DYNAMIC(CStopDialog, CDialogEx)

CStopDialog::CStopDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_STOP, pParent)
{

}

CStopDialog::~CStopDialog()
{
}
BOOL CStopDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_timerstopstring.AddString(_T("5 mins"));
	m_timerstopstring.AddString(_T("30 mins"));
	m_timerstopstring.AddString(_T("1 hr"));
	m_timerstopstring.AddString(_T("3 hrs"));
	m_timerstopstring.AddString(_T("6 hrs"));
	m_timerstopstring.SetCurSel(0);
	//m_timerstopstring.AddString(m_vecTimer);
	//Sm_timerstopstring.
	return TRUE;
}
void CStopDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO1, m_timerStop);
	DDX_Control(pDX, IDC_COMBO_STOP, m_timerstopstring);
}


BEGIN_MESSAGE_MAP(CStopDialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_STOP, &CStopDialog::OnCbnSelchangeComboStop)
END_MESSAGE_MAP()


// CStopDialog message handlers


void CStopDialog::OnCbnSelchangeComboStop()
{
	int l_nCurrentSelection = m_timerstopstring.GetCurSel();
	m_timerstopstring.GetLBText(l_nCurrentSelection, m_Data);
}

int CStopDialog::SetValue(CString str)
{
	m_Data = str;
	return 1;
}
int CStopDialog::GetValue(CString& str)
{
	str = m_Data;
	return 1;
}