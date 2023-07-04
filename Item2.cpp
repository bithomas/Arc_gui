// CItem2.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item2.h"
#include <algorithm>
#include "ArcGUIPropSheelDlg.h"


auto g_iVirtualDataSize{3};
auto g_iDataSize{3};//Ravi
auto g_iColumns{ 5 };
// Item2 dialog

IMPLEMENT_DYNAMIC(CItem2, CMFCPropertyPage)

CItem2::CItem2()
	: CMFCPropertyPage(IDD_ITEM_2)
{
	m_tokenstr = _T("XJID789374");
	m_strTimer = _T("30 mins");
	m_bProcessStop = false;
}

CItem2::~CItem2()
{
}
CString CItem2::IsProcessStopped(bool bProcessStop)
{
	if(bProcessStop == false)
		return _T("Running");
	else
		return _T("Stopped");
}

CString CItem2::MonthString(int vlaue)
{
	switch (vlaue)
	{
		case 1 :
			return _T("Jan");
			break;
		case 2:
			return _T("Feb");
			break;
		case 3:
			return _T("Mar");
			break;
		case 4:
			return _T("Apr");
			break;
		case 5:
			return _T("May");
			break;
		case 6:
			return _T("Jun");
			break;
		case 7:
			return _T("July");
			break;
		case 8:
			return _T("Aug");
			break;
		case 9:
			return _T("Sep");
			break;
		case 10:
			return _T("Oct");
			break;
		case 11:
			return _T("Nov");
			break;
		case 12:
			return _T("Dec");
			break;
	}
}
BOOL CItem2::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();
	LISTEXCREATE lcs;
	lcs.uID = IDC_LISTEX;
	lcs.pParent = this;
	lcs.fDialogCtrl = true;
	lcs.dwHdrHeight = 30;
	lcs.fSortable = true;
	lcs.stColor.clrHdrText = RGB(252, 255, 255);
	CRect Itemrect;
	this->GetWindowRect(&Itemrect);
	ScreenToClient(&Itemrect);
	int Width = Itemrect.Width();
	Width = Width - 200;
	CRect lrect;
	//GetDlgItem(IDD_INNDATA_DIALOG)->GetWindowRect(&lrect);
	//ScreenToClient(&lrect);
	/*GetDlgItem(IDC_TABLIST)->GetWindowRect(&lrect);
	ScreenToClient(&lrect);*/
	int width = 990;
	GetDlgItem(IDC_LISTEX)->SetWindowPos(NULL, 0, 30, width, 522, SWP_NOZORDER);
	//GetDlgItem(IDC_LISTEX)->SetWindowPos()
		//l_pDeviceTabWnd->SetWindowPos(NULL, PANEL2_BORDER_THICKNESS, (PANEL2_BORDER_THICKNESS + TAB_CONTROL_HEIGHT), (m_rcPanel2Rect.Width() - (2 * PANEL2_BORDER_THICKNESS)), (m_rcPanel2Rect.Height() - (TAB_CONTROL_HEIGHT + (2 * PANEL2_BORDER_THICKNESS))), SWP_NOZORDER);
	int ColumnWidth = (width - 16) / 5;
	m_pList->Create(lcs);
	m_pList->InsertColumn(0, L"File/Folder", 0, ColumnWidth, -1, LVCFMT_LEFT);
	m_pList->SetHdrColumnColor(0, RGB(106, 153, 207));
	//m_pList->SetColumnWidth(0, Width / 5);
	//First (0 index) column is always left aligned by default.
	//To change its alignment SetColumn() must be called explicitly.
	LVCOLUMNW stCol{ };
	stCol.mask = LVCF_FMT;
	stCol.fmt = LVCFMT_CENTER;
	m_pList->SetColumn(0, &stCol);

	//Header menu
	std::wstring headerdata[5] = { L"File/Folder", L"Status" , L"Last Scan at", L"Scan Details", L"Last 5 Scans" };
	for (int i = 1; i < g_iColumns; ++i) {
		auto wstrName = headerdata[i];// std::wstring(L"Test column ") + std::to_wstring(i);
		m_pList->InsertColumn(i, wstrName.data(), LVCFMT_CENTER, ColumnWidth, -1, LVCFMT_CENTER);
		m_pList->SetHdrColumnColor(i, RGB(106, 153, 207));
		//m_pList->SetColumnWidth(i, Width / 5);
	}

	m_pList->SetHdrColumnColor(0, RGB(106, 153, 207));
	//For Virtual list.
	//Sample data for Virtual mode (LVS_OWNERDATA).
	CString Path[3] = {
		_T("C:\\ProgramFiles"),
		_T("C:\\Desktop"),
		_T("C:\\Downloads") 
	};
	/*CString Path[30] = {
		_T("C:\\ProgramFiles")
	};*/
	//bool Stopped[30] = { false };
	bool Stopped[3] = { false };
	VIRTLISTDATA llistdata;
	for (unsigned i = 0; i < g_iDataSize; ++i) {
		llistdata.wstr0 = Path[i];
		llistdata.wstr1 = IsProcessStopped(Stopped[i]);
		if (Stopped[i] == true)
			llistdata.clr = LISTEXCOLOR{ RGB(210, 210, 210) };
		else
			llistdata.clr = LISTEXCOLOR{ RGB(210, 222, 238) };
		CString Year = CTime::GetCurrentTime().Format("%Y");
		CString Month = CTime::GetCurrentTime().Format("%m");
		CString UpdateMonth = MonthString(_wtoi(Month));
		CString day = CTime::GetCurrentTime().Format("%m");
		CString Time = CTime::GetCurrentTime().Format("%H:%M:%S");
		CString Scan = day + _T("-") + UpdateMonth + _T("-") + Year + _T(" ") + Time;
		llistdata.wstr2 = Scan;
		m_vecData.emplace_back(llistdata);
	}
	m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL); //Amount of Virtual items.

	return TRUE;
}
void CItem2::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}

BOOL  CItem2::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
}
void CItem2::OnListExGetDispInfo(NMHDR* pNMHDR, LRESULT* /*pResult*/)
{
	const auto pDispInfo = reinterpret_cast<NMLVDISPINFOW*>(pNMHDR);
	LVITEMW* pItem = &pDispInfo->item;
	const auto index = pItem->iItem < g_iDataSize ? pItem->iItem : 1;

	if (pItem->mask & LVIF_TEXT) {
		switch (pItem->iSubItem) {
		case 0:
			pItem->pszText = m_vecData.at(static_cast<size_t>(index)).wstr0.data();
			break;
		case 1:
			pItem->pszText = m_vecData.at(static_cast<size_t>(index)).wstr1.data();
			break;
		case 2:
			pItem->pszText = m_vecData.at(static_cast<size_t>(index)).wstr2.data();
			break;
		case 3:
			pItem->pszText = m_vecData.at(static_cast<size_t>(index)).wstr3.data();
			break;
		}
	}
}

void CItem2::OnListExGetColor(NMHDR* pNMHDR, LRESULT* /*pResult*/)
{
	//Virtual data colors.
	const auto pNMI = reinterpret_cast<NMITEMACTIVATE*>(pNMHDR);
	if (pNMI->iItem < 0 || pNMI->iSubItem < 0)
		return;

	if (pNMI->iSubItem == 1) { //Column number 1 (for all rows) colored to RGB(0, 220, 220).
		static LISTEXCOLOR clr{ RGB(0, 220, 220), RGB(0, 0, 0) };
		pNMI->lParam = reinterpret_cast<LPARAM>(&clr);
	}

	const auto index = pNMI->iItem < g_iDataSize ? pNMI->iItem : 1;
	if (m_vecData.at(static_cast<size_t>(index)).fColor)
		pNMI->lParam = reinterpret_cast<LPARAM>(&m_vecData.at(static_cast<size_t>(index)).clr);
}

void CItem2::OnListExGetIcon(NMHDR* pNMHDR, LRESULT* /*pResult*/)
{
}

void CItem2::OnListDataChanged(NMHDR* pNMHDR, LRESULT* /*pResult*/)
{
}

BEGIN_MESSAGE_MAP(CItem2, CMFCPropertyPage)
	ON_NOTIFY(LVN_GETDISPINFOW, IDC_LISTEX, &CItem2::OnListExGetDispInfo)
	ON_NOTIFY(LISTEX_MSG_GETCOLOR, IDC_LISTEX, &CItem2::OnListExGetColor)
	ON_NOTIFY(LISTEX_MSG_GETICON, IDC_LISTEX, &CItem2::OnListExGetIcon)
	ON_NOTIFY(LISTEX_MSG_DATACHANGED, IDC_LISTEX, &CItem2::OnListDataChanged)
	ON_BN_CLICKED(IDC_BUTTON1, &CItem2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CItem2::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CItem2::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CItem2::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CItem2::OnBnClickedButton5)
	ON_NOTIFY(LVN_ITEMCHANGING, IDC_LISTEX, &CItem2::OnLvnItemchangingListex)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTEX, &CItem2::OnLvnItemchangedListex)
END_MESSAGE_MAP()


// Item2 message handlers


void CItem2::OnBnClickedButton1()
{
	CFolderAdd dlg;
	folderdata l_strcutdatd;
	dlg.SetFolderData(l_strcutdatd);
	dlg.SetFolderName(_T("ADD"));
	if(IDCANCEL == dlg.DoModal())
	{
		return;
	}
	m_structdata = dlg.GetFolderData();
	g_iVirtualDataSize = g_iVirtualDataSize + 1;
	g_iDataSize = g_iDataSize + 1;
	m_bProcessStop = false;
	//std::string vec((LPCTSTR)m_structdata.strFolderPath.GetString());
	VIRTLISTDATA llistdata;
	llistdata.wstr0 = m_structdata.strFolderPath;
	llistdata.wstr1 = IsProcessStopped(m_bProcessStop);
	CString Year = CTime::GetCurrentTime().Format("%Y");
	CString Month = CTime::GetCurrentTime().Format("%m");
	CString UpdateMonth = MonthString(_wtoi(Month));
	CString day = CTime::GetCurrentTime().Format("%m");
	CString Time = CTime::GetCurrentTime().Format("%H:%M:%S");
	CString Scan = day + _T("-") + UpdateMonth + _T("-") + Year + _T(" ") + Time;
	llistdata.wstr2 = Scan;
	m_vecData.emplace_back(llistdata);
	
	m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL);

	// TODO: Add your control notification handler code here
}


void CItem2::OnBnClickedButton2()
{
	int l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 3)
		return;

	g_iDataSize = g_iDataSize - 1;
	g_iVirtualDataSize = g_iVirtualDataSize - 1;
	m_vecData.erase(m_vecData.begin() + l_nrow );
	m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL);
	// TODO: Add your control notification handler code here
}


void CItem2::OnBnClickedButton4()
{
	int l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 3)
		return;
	CStartDialog dlg;
	dlg.SetValue(m_tokenstr);
	if (IDCANCEL == dlg.DoModal())
		return;
	l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 0)
		return;
	m_bProcessStop = false;
	m_vecData[l_nrow].wstr1 = IsProcessStopped(m_bProcessStop);
	m_vecData[l_nrow].clr = LISTEXCOLOR{ RGB(210, 222, 238) };//Row number 7 (for all columns) colored to RGB(0, 220, 0).
	//m_pList->Refres
	CString Year = CTime::GetCurrentTime().Format("%Y");
	CString Month = CTime::GetCurrentTime().Format("%m");
	CString UpdateMonth = MonthString(_wtoi(Month));
	CString day = CTime::GetCurrentTime().Format("%m");
	CString Time = CTime::GetCurrentTime().Format("%H:%M:%S");
	CString Scan = day + _T("-") + UpdateMonth + _T("-") + Year + _T(" ") + Time;
	m_vecData[l_nrow].wstr2 = Scan;
	m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL); //Amount of Virtual items.
	// TODO: Add your control notification handler code here
}


void CItem2::OnBnClickedButton3()
{
	int l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 3)
		return;
	CStopDialog dlg;
	if (IDCANCEL == dlg.DoModal())
	{
		return;
	}
	CStopNextDlg dlg2;
	dlg.GetValue(m_strTimer);
	dlg2.SetValue(_T("Scan stopped for ") + m_strTimer + _T(" and release token is ") + m_tokenstr);
	if (IDOK != dlg2.DoModal())
	{
		return;
	}
	m_bProcessStop = true;
	l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 0)
		return;
	m_vecData[l_nrow].wstr1 = IsProcessStopped(m_bProcessStop);
	m_vecData[l_nrow].clr = LISTEXCOLOR{ RGB(210, 210, 210) };//Row number 7 (for all columns) colored to RGB(0, 220, 0).
	//m_pList->Refres
	CString Year = CTime::GetCurrentTime().Format("%Y");
	CString Month = CTime::GetCurrentTime().Format("%m");
	CString UpdateMonth = MonthString(_wtoi(Month));
	CString day = CTime::GetCurrentTime().Format("%m");
	CString Time = CTime::GetCurrentTime().Format("%H:%M:%S");
	CString Scan = day + _T("-") + UpdateMonth + _T("-") + Year + _T(" ") + Time;
	m_vecData[l_nrow].wstr2 = Scan;
	m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL); //Amount of Virtual items.
	// TODO: Add your control notification handler code here
}


void CItem2::OnBnClickedButton5()
{
	int l_nrow = m_pList->GetSelectionMark();
	if (l_nrow < 0)
		return;
	if (l_nrow < 3)
	{
		CFolderAdd dlg;
		dlg.SetCtrlStates(false);
		m_structdata.strFolderPath = m_pList->GetItemText(l_nrow, 0);
		dlg.SetFolderData(m_structdata);
		dlg.SetFolderName(_T("OK"));
		dlg.DoModal();
		return;
	}


	m_structdata.strFolderPath = m_pList->GetItemText(l_nrow, 0);

	CFolderAdd dlg1;
	dlg1.SetFolderData(m_structdata);
	dlg1.SetFolderName(_T("OK"));
	if (IDCANCEL == dlg1.DoModal())
	{
		return;
	}
	folderdata l_current;
	l_current = dlg1.GetFolderData();
	if (DataSame(m_structdata, l_current) == true)
		return;
	CFolderAfterEdit dlg2;
	//dlg2.DoModal();
	if (IDOK == dlg2.DoModal())
	{
		m_structdata = dlg1.GetFolderData();
		m_vecData[l_nrow].wstr0 = m_structdata.strFolderPath;
		m_pList->SetItemCountEx(g_iVirtualDataSize, LVSICF_NOSCROLL); //Amount of Virtual items.

	}
	else
	{
		dlg1.SetFolderData(m_structdata);
		if (IDCANCEL == dlg1.DoModal())
		{
			return;
		}
	}
}
bool CItem2::DataSame(folderdata old, folderdata newdata)
{
	bool DataSame = false;
	if (old.bEncrypt[0] != newdata.bEncrypt[0])
		return DataSame;
	if (old.bEncrypt[1] != newdata.bEncrypt[1])
		return DataSame;
	if (old.bExtension[0] != newdata.bExtension[0])
		return DataSame;
	if (old.bExtension[1] != newdata.bExtension[1])
		return DataSame;
	if (old.bExtension[2] != newdata.bExtension[2])
		return DataSame;
	if (old.strFolderPath == newdata.strFolderPath)
		 DataSame = true;
	else
		DataSame = false;
	if (old.strTimer == newdata.strTimer)
		DataSame = true;
	else
		DataSame = false;
	return DataSame;


}

void CItem2::OnLvnItemchangingListex(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
		// do stuff...

	*pResult = 0;
	
}


void CItem2::OnLvnItemchangedListex(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMListView = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	if ((pNMListView->uChanged & LVIF_STATE) &&
			(pNMListView->uOldState & LVNI_SELECTED) !=
			(pNMListView->uNewState & LVNI_SELECTED))
	{
		// do stuff...
		if (pNMListView->iItem < 3)
		{
			GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);

		}
		else
		{
			if (_T("Running" == m_vecData[pNMListView->iItem].wstr1))
			{
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
			}
			else
			{
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
			}
			GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
			
			
		}

	}
	// TODO: Add your control notification handler code here
	*pResult = 0;
	UpdateWindow();
}
