#pragma once


// CStartDialog dialog

class CStartDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CStartDialog)

public:
	CStartDialog(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CStartDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_START };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL DestroyWindow();

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ReleaseToken;
	
	CString m_value;
	CString GetValue() const { return m_value; }
	void SetValue(const CString& value) { m_value = value; }
};
