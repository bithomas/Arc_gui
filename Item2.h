#pragma once
#include "afxdialogex.h"
#include "ListEx.h"
#include <vector>
#include <gdiplus.h>
#include "CFolderAdd.h"
#include "CStartDialog.h"
#include "CStopDialog.h"
#include "CStopNextDlg.h"
#include "CFolderAfterEdit.h"
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")
#define ID_START_ADD_BTN	 1014
namespace GDI_Button
{
	class CGdipButton;
}
enum eButtonList
{
	ID_ADD_BTN = ID_START_ADD_BTN + 1,
	ID_DELTE_BTN,
	ID_PLAY_BTN,
	ID_STOP_BTN,
};
using namespace LISTEX;

struct VIRTLISTDATA
{
	std::wstring wstr0;      //Arbitrary data...
	std::wstring wstr1;
	std::wstring wstr2 = _T("15-Dec-22 15:45:23");
	std::wstring wstr3 = _T("Details ... .. ");
	bool fIcon{ false };    //Does this row have an icon.
	bool fColor{ true };   //Does this row have color.
	bool fToolTip{ false }; //Tooltip row.
	LISTEXCOLOR clr{ RGB(210, 222, 238) };     //Row color.
};
// Item2 dialog

class CItem2 : public CMFCPropertyPage
{
	DECLARE_DYNAMIC(CItem2)

public:
	CItem2();   // standard constructor
	virtual ~CItem2();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ITEM_2 };
#endif

protected:
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL  OnEraseBkgnd(CDC* pDC);
	afx_msg void OnListExGetDispInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListExGetColor(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListExGetIcon(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListDataChanged(NMHDR* pNMHDR, LRESULT* pResult);
	IListExPtr m_pList{ CreateListEx() };
	CMenu m_menuCell;
	CMenu m_menuList;
	CMenu m_menuHdr;
	std::vector<VIRTLISTDATA> m_vecData{ };
	CImageList m_stImgList;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnLvnItemchangingListex(NMHDR* pNMHDR, LRESULT* pResult);
	CString m_tokenstr;
	CString m_strTimer;
	folderdata m_structdata;
	bool m_bProcessStop;
	CString IsProcessStopped(bool bProcessStop);
	CString MonthString(int vlaue);
	bool DataSame(folderdata old, folderdata newdata);
	afx_msg void OnLvnItemchangedListex(NMHDR* pNMHDR, LRESULT* pResult);
};

constexpr auto IDC_LIST_MENU_CELL_FIRST = 0x1;
constexpr auto IDC_LIST_MENU_CELL_SECOND = 0x2;
constexpr auto IDC_LIST_MENU_GLOBAL_FIRST = 0x3;
constexpr auto IDC_LIST_MENU_GLOBAL_SECOND = 0x4;
constexpr auto IDC_LIST_MENU_HDR_BEGIN = 0x5;