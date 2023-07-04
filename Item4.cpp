// CItem4.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item4.h"


// CItem4 dialog

IMPLEMENT_DYNAMIC(CItem4, CMFCPropertyPage)

CItem4::CItem4()
	: CMFCPropertyPage(IDD_ITEM_4)
{
	

	//m_pTabCtrl =  (CTabCtrl*)GetDlgItem(IDC_TAB1);

	
}

CItem4::~CItem4()
{
}

BOOL CItem4::OnInitDialog()
{
	CMFCPropertyPage::OnInitDialog();

	m_pTabCtrl = (CTabCtrl*)GetDlgItem(IDC_TAB1);
	if (m_pTabCtrl->GetItemCount() > 0)
	{
		return TRUE;
	}
	m_tab1.Create(IDD_TAB1, m_pTabCtrl);
	m_tab1.ShowWindow(FALSE);
	TCITEM item1, item2, item3, item4;

	item1.mask = TCIF_TEXT | TCIF_PARAM;
	item1.lParam = (LPARAM)&m_tab1;
	item1.pszText = _T("File Encryption Analysis");

	m_pTabCtrl->InsertItem(0, &item1);

	m_tab2.Create(IDD_TAB2, m_pTabCtrl);
	m_tab2.ShowWindow(FALSE);
	item2.mask = TCIF_TEXT | TCIF_PARAM;
	item2.lParam = (LPARAM)&m_tab2;
	item2.pszText = _T("Shutdown Analysis");

	m_pTabCtrl->InsertItem(1, &item2);

	m_tab3.Create(IDD_TAB3, m_pTabCtrl);
	m_tab3.ShowWindow(FALSE);
	item3.mask = TCIF_TEXT | TCIF_PARAM;
	item3.lParam = (LPARAM)&m_tab3;
	item3.pszText = _T("Landmine Analysis");

	m_pTabCtrl->InsertItem(2, &item3);

	m_tab4.Create(IDD_TAB4, m_pTabCtrl);
	m_tab4.ShowWindow(FALSE);
	item4.mask = TCIF_TEXT | TCIF_PARAM;
	item4.lParam = (LPARAM)&m_tab4;
	item4.pszText = _T("Symlink Analysis");

	m_pTabCtrl->InsertItem(3, &item4);
	m_pTabCtrl->SetCurSel(0);
	return TRUE;
}

BOOL  CItem4::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
}
//
//void CItem4::DoDataExchange(CDataExchange* pDX)
//{
//	CMFCPropertyPage::DoDataExchange(pDX);
//
//	m_pTabCtrl = (CTabCtrl*)GetDlgItem(IDC_TAB1);
//	if (m_pTabCtrl->GetItemCount() > 0)
//	{
//		return;
//	}
//	m_tab1.Create(IDD_TAB1, m_pTabCtrl);
//	TCITEM item1, item2, item3, item4;
//
//	item1.mask = TCIF_TEXT | TCIF_PARAM;
//	item1.lParam = (LPARAM)&m_tab1;
//	item1.pszText = _T("File Encryption Analysis");
//
//	m_pTabCtrl->InsertItem(0, &item1);
//
//	m_tab2.Create(IDD_TAB2, m_pTabCtrl);
//	item2.mask = TCIF_TEXT | TCIF_PARAM;
//	item2.lParam = (LPARAM)&m_tab2;
//	item2.pszText = _T("Shutdown Analysis");
//
//	m_pTabCtrl->InsertItem(1, &item2);
//
//	m_tab3.Create(IDD_TAB3, m_pTabCtrl);
//	item3.mask = TCIF_TEXT | TCIF_PARAM;
//	item3.lParam = (LPARAM)&m_tab3;
//	item3.pszText = _T("Landmine Analysis");
//
//	m_pTabCtrl->InsertItem(2, &item3);
//	m_tab4.Create(IDD_TAB4, m_pTabCtrl);
//	item4.mask = TCIF_TEXT | TCIF_PARAM;
//	item4.lParam = (LPARAM)&m_tab4;
//	item4.pszText = _T("Symlink Analysis");
//
//	m_pTabCtrl->InsertItem(3, &item4);
//}


BEGIN_MESSAGE_MAP(CItem4, CMFCPropertyPage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CItem4::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CItem4 message handlers


void CItem4::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	TCITEM *item = NULL;
	if (m_pTabCtrl) {
		int nSelect = m_pTabCtrl->GetCurSel();
		CRect rect;
		m_pTabCtrl->GetClientRect(rect);
		if (nSelect == 0)
		{
			
			m_tab1.SetWindowPos( NULL, rect.left + 5, rect.top + 25, rect.right -10, rect.bottom -35, SWP_SHOWWINDOW);
			m_tab2.ShowWindow(SW_HIDE);
			m_tab3.ShowWindow(SW_HIDE);
			m_tab4.ShowWindow(SW_HIDE);
		}
		else if (nSelect == 1)
		{
			m_tab2.SetWindowPos(NULL, rect.left + 5, rect.top + 25, rect.right-10, rect.bottom -35, SWP_SHOWWINDOW);
			m_tab1.ShowWindow(SW_HIDE);
			m_tab3.ShowWindow(SW_HIDE);
			m_tab4.ShowWindow(SW_HIDE);
		}
		else if (nSelect == 2)
		{
			m_tab3.SetWindowPos(NULL, rect.left + 5, rect.top + 25, rect.right - 10, rect.bottom - 35, SWP_SHOWWINDOW);;
			m_tab1.ShowWindow(SW_HIDE);
			m_tab2.ShowWindow(SW_HIDE);
			m_tab4.ShowWindow(SW_HIDE);
		}
		else if (nSelect == 3)
		{
			m_tab4.SetWindowPos(NULL, rect.left + 5, rect.top + 25, rect.right - 10, rect.bottom - 35, SWP_SHOWWINDOW);
			m_tab1.ShowWindow(SW_HIDE);
			m_tab2.ShowWindow(SW_HIDE);
			m_tab3.ShowWindow(SW_HIDE);
		}
	}
	*pResult = 0;

}
