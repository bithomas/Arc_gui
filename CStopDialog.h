#pragma once
#include <vector>

// CStopDialog dialog

class CStopDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStopDialog)

public:
	CStopDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStopDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_STOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//CComboBox m_timerStop;
	
	CComboBox m_timerstopstring;
	afx_msg void OnCbnSelchangeComboStop();
	std::vector <CString> m_vecTimer;
	int SetValue(CString str);
	int GetValue(CString& str);
	CString m_Data;
};
