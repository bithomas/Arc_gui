#pragma once


// CFolderAfterEdit dialog

class CFolderAfterEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CFolderAfterEdit)

public:
	CFolderAfterEdit(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CFolderAfterEdit();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FOLDER_EDIT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
