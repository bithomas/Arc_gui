// CFolderAdd.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "CFolderAdd.h"
#include "afxdialogex.h"


// CFolderAdd dialog

IMPLEMENT_DYNAMIC(CFolderAdd, CDialogEx)

CFolderAdd::CFolderAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	m_OkName = _T("Add");
	m_bDisable = true;
}

CFolderAdd::~CFolderAdd()
{
}
BOOL CFolderAdd::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_FolderCombo.AddString(_T("Every min"));
	m_FolderCombo.AddString(_T("5 mins"));
	m_FolderCombo.AddString(_T("30 mins"));
	m_FolderCombo.AddString(_T("1 hr"));
	m_FolderCombo.AddString(_T("3 hrs"));
	m_FolderCombo.AddString(_T("6 hrs"));
	m_FolderCombo.SetCurSel(0);
	m_editfolderpath.SetWindowTextW(m_structFolderData.strFolderPath);
	m_bYes.SetCheck(m_structFolderData.bEncrypt[0]);
	m_bNo.SetCheck(m_structFolderData.bEncrypt[1]);
	m_bSys.SetCheck(m_structFolderData.bExtension[0]);
	m_binf.SetCheck(m_structFolderData.bExtension[1]);
	m_bcat.SetCheck(m_structFolderData.bExtension[2]);
	GetDlgItem(IDOK)->SetWindowText(m_OkName);
	int l_nCurrentSelection = m_FolderCombo.FindStringExact(0, m_structFolderData.strTimer);
	if (-1 == l_nCurrentSelection)
		m_FolderCombo.SetCurSel(0);
	else
		m_FolderCombo.SetCurSel(l_nCurrentSelection);
	m_FolderCombo.EnableWindow(m_bDisable);
	m_editfolderpath.EnableWindow(m_bDisable);
	m_bYes.EnableWindow(m_bDisable);
	m_bNo.EnableWindow(m_bDisable);
	m_bSys.EnableWindow(m_bDisable);
	m_binf.EnableWindow(m_bDisable);
	m_bcat.EnableWindow(m_bDisable);
	return TRUE;

}

void CFolderAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_FOLDER, m_FolderCombo);
	DDX_Control(pDX, IDC_EDIT_FOLDER, m_editfolderpath);
	DDX_Control(pDX, IDC_CHECK_YES, m_bYes);
	DDX_Control(pDX, IDC_CHECK_NO, m_bNo);
	DDX_Control(pDX, IDC_CHECK5, m_bSys);
	DDX_Control(pDX, IDC_CHECK6, m_binf);
	DDX_Control(pDX, IDC_CHECK7, m_bcat);
}

int CFolderAdd::SetFolderData(folderdata structFolderData)
{
	m_structFolderData = structFolderData;
	return 1;
}
folderdata& CFolderAdd::GetFolderData()
{
	return m_structFolderData;
}
BEGIN_MESSAGE_MAP(CFolderAdd, CDialogEx)
	
	ON_CBN_SELCHANGE(IDC_COMBO_FOLDER, &CFolderAdd::OnCbnSelchangeComboFolder)
	ON_BN_CLICKED(IDOK, &CFolderAdd::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_NO, &CFolderAdd::OnBnClickedCheckNo)
	ON_BN_CLICKED(IDC_CHECK_YES, &CFolderAdd::OnBnClickedCheckYes)
END_MESSAGE_MAP()


// CFolderAdd message handlers




BOOL CFolderAdd::DestroyWindow()
{
	// TODO: Add your specialized code here and/or call the base class
	int l_nCurrentSelection = m_FolderCombo.GetCurSel();
	m_FolderCombo.GetLBText(l_nCurrentSelection, m_strtimer);
	m_structFolderData.strTimer = m_strtimer;
	m_editfolderpath.GetWindowText(m_structFolderData.strFolderPath);
	m_structFolderData.bEncrypt[0]= m_bYes.GetCheck();
	m_structFolderData.bEncrypt[1] =m_bNo.GetCheck();
	m_structFolderData.bExtension[0] = m_bSys.GetCheck();
	m_structFolderData.bExtension[1] =  m_binf.GetCheck();
	m_structFolderData.bExtension[2] =  m_bcat.GetCheck();
	

	return CDialogEx::DestroyWindow();
}


void CFolderAdd::OnCbnSelchangeComboFolder()
{
	int l_nCurrentSelection = m_FolderCombo.GetCurSel();
	m_FolderCombo.GetLBText(l_nCurrentSelection, m_strtimer);
	// TODO: Add your control notification handler code here
}

int CFolderAdd::SetFolderName(CString strOkName)
{
	m_OkName = strOkName;
	return 1;
}

void CFolderAdd::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	//return;
	CDialogEx::OnOK();
}


void CFolderAdd::OnBnClickedCheckNo()
{
	m_bYes.SetCheck(FALSE);
	// TODO: Add your control notification handler code here
}


void CFolderAdd::OnBnClickedCheckYes()
{
	m_bNo.SetCheck(FALSE);
	// TODO: Add your control notification handler code here
}

int CFolderAdd::SetCtrlStates(bool bDisable)
{
	m_bDisable = bDisable;
	return 1;
}
