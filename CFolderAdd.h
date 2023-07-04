#pragma once

struct folderdata
{
	CString strFolderPath;      //Arbitrary data...
	bool bEncrypt[2] = {false };
	bool bExtension[3] = { false };
	CString strTimer;
};
struct folderdlgStates
{
	bool bEditBox = true;
	bool bYes = true;
	bool bNo = true;
	bool bSys = true;
	bool binf = true;
	bool bcat = true;
	bool btimer = true;
};

// CFolderAdd dialog

class CFolderAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CFolderAdd)

public:
	CFolderAdd(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFolderAdd();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	// //CComboBox TimerBox;	// //CComboBox TimerBox;
	CComboBox m_FolderCombo;
	CEdit m_editfolderpath;
	folderdata m_structFolderData;
	int SetFolderData(folderdata structFolderData);
	//int GetFolderData(folderdata& structFolderData);
	folderdata& CFolderAdd::GetFolderData();
	int SetFolderName(CString strOkName);
	CButton m_bYes;
	CButton m_bNo;
	CButton m_bSys;
	CButton m_binf;
	CButton m_bcat;
	CString m_strtimer;
	CString m_OkName;
	virtual BOOL DestroyWindow();
	afx_msg void OnCbnSelchangeComboFolder();
	afx_msg void OnBnClickedOk();
	int SetCtrlStates(bool bDisable);
	afx_msg void OnBnClickedCheckNo();
	afx_msg void OnBnClickedCheckYes();
	bool m_bDisable;
};
