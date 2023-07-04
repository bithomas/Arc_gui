#pragma once


// CStopNextDlg dialog

class CStopNextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStopNextDlg)

public:
	CStopNextDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStopNextDlg();
	CString m_Data;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STOP_NEXT_DLG};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	int SetValue(CString str);
	int GetValue(CString& str);
	
};
