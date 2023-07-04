#include "pch.h"
#include "resource.h"
#include "ArcGUIPropSheelDlg.h"

// CItem1 dialog

IMPLEMENT_DYNAMIC(CArcGUIPropSheelDlg, CMFCPropertySheet)


CArcGUIPropSheelDlg::CArcGUIPropSheelDlg()
{
    AddPage(&m_Item1);
    AddPage(&m_Item2);
    AddPage(&m_Item3);
    AddPage(&m_Item4);
    AddPage(&m_Item5);
    AddPage(&m_Item6);
    EnablePageHeader(0);
    SetLook(CMFCPropertySheet::PropSheetLook_List, 200);

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

}

BOOL CArcGUIPropSheelDlg::OnInitDialog()
{
	CMFCPropertySheet::OnInitDialog();
	CRect rect;
	m_wndList.GetClientRect(&rect);
	CRect rect2;
	this->GetWindowRect(&rect2);
	this->ScreenToClient(&rect2);
	//GetDlgItem(IDD_ITEM_2)->SetWindowPos(NULL, 0, 0, 950, 522, SWP_NOZORDER);
	rect.right += 10;
	rect.bottom += 3;
	//rect.right += 10;
	//rect.bottom = rect2.bottom;
	m_wndList.ShowWindow(SW_HIDE);
	m_listBox.Create(WS_CHILD | WS_VISIBLE | WS_VSCROLL| WS_CLIPSIBLINGS | LBS_OWNERDRAWVARIABLE|
		LBS_NOTIFY | LBS_HASSTRINGS , rect, this, IDC_TABLIST);
	m_font.CreatePointFont(130, L"MS Gothic");
	//m_listBox.SetFont(&m_font);
	
	CString str;
	for (int k = 0; k < m_wndList.GetCount(); k++) {
		m_wndList.GetText(k, str);
		m_listBox.AddString(str);
		m_listBox.SetItemHeight(k, 40);
	}
	
	m_listBox.UpdateData(false);
	m_listBox.SetCurSel(0);


	SetActivePage(m_listBox.GetCurSel());

	//SetActivePage(2);
	return TRUE;
}


CArcGUIPropSheelDlg::~CArcGUIPropSheelDlg()
{
	GdiplusShutdown(m_gdiplusToken);
}
void CArcGUIPropSheelDlg::Draw_Borders(CDC* pDC)
{
	CRect rect;
	Graphics g(pDC->m_hDC);
	GetClientRect(rect);
	SolidBrush brush(Gdiplus::Color(255, 255,255));
	g.FillRectangle(&brush, rect.left, rect.top, rect.Width(), rect.Height());
	DrawListBackground();
	
}

void CArcGUIPropSheelDlg::DrawListBackground()
{
	CRect rect;
	SolidBrush Whitebrush(Color(255, 255, 255));
	GetTabControl()->GetClientRect(&rect);
	Graphics g(GetTabControl()->GetDC()->m_hDC);
	g.FillRectangle(&Whitebrush, Gdiplus::Rect(rect.left, rect.top, rect.Width(), rect.Height()));
	m_Item1.m_hdc = GetTabControl()->GetDC()->m_hDC;
	m_Item1.m_rect = rect;

	
}

void CArcGUIPropSheelDlg::DrawListItem(LPDRAWITEMSTRUCT lpdrawItemStruct)
{
	    TCHAR achBuffer[255];
		Graphics g(lpdrawItemStruct->hDC);
		SolidBrush brush(Color(30, 63, 94));
		SolidBrush selectedBrush(Color(18, 43, 64));
		SolidBrush textBrush(Color(255, 255, 255));
		Gdiplus::Font font(&FontFamily(L"MS Gothic"), 10, FontStyleRegular);
		int nBottom = GetTabControl()->GetItemCount() * abs(lpdrawItemStruct->rcItem.top - lpdrawItemStruct->rcItem.bottom);
		::SendMessage(lpdrawItemStruct->hwndItem, LB_GETTEXT, lpdrawItemStruct->itemID, (LPARAM)achBuffer);
		DrawListBackground();
		CRect itemRect(lpdrawItemStruct->rcItem.left, lpdrawItemStruct->rcItem.top, lpdrawItemStruct->rcItem.right, lpdrawItemStruct->rcItem.bottom);
		g.FillRectangle(&brush, Gdiplus::Rect(itemRect.left, itemRect.top, itemRect.Width(), itemRect.Height()));


		if (lpdrawItemStruct->itemAction == ODA_SELECT || lpdrawItemStruct->itemAction == ODA_DRAWENTIRE) {
			if (lpdrawItemStruct->itemState & ODS_SELECTED) {
				g.FillRectangle(&selectedBrush, Gdiplus::Rect(itemRect.left, itemRect.top, itemRect.Width(), itemRect.Height()));
			}

		}
		else if (lpdrawItemStruct->itemAction == ODA_FOCUS) {
			g.FillRectangle(&selectedBrush, Gdiplus::Rect(itemRect.left, itemRect.top, itemRect.Width(), itemRect.Height()));

		}

		g.DrawString(achBuffer, -1, &font, Gdiplus::PointF(itemRect.left + 25, itemRect.top + 15), &textBrush);
}

void CArcGUIPropSheelDlg::OnPaint() 
{
	CPaintDC pDC(this);
	
	Draw_Borders(&pDC);
	CMFCPropertySheet::OnPaint();
}

BOOL  CArcGUIPropSheelDlg::OnEraseBkgnd(CDC* pDC) {
	//CMFCPropertySheet::OnEraseBkgnd(pDC);
	
	Draw_Borders(pDC);
	return FALSE;
}

afx_msg void CArcGUIPropSheelDlg::OnDrawItem(int  nCtlId, LPDRAWITEMSTRUCT lpdrawItemStruct) {

	if (nCtlId == IDC_TABLIST) {
		DrawListItem(lpdrawItemStruct);
	}
	else {
		CMFCPropertySheet::OnDrawItem(nCtlId, lpdrawItemStruct);
	}

}

 HBRUSH CArcGUIPropSheelDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) {
	 if (pWnd->GetDlgCtrlID() == IDC_TABLIST)
	 {
	/*	 pDC->SetBkColor(RGB(30, 63, 94));
		 pDC->SetTextColor(RGB(255, 255, 255));*/
		 return CreateSolidBrush(RGB(30, 63, 94));;
	 }
	

}
 void CArcGUIPropSheelDlg::OnLBNTabChange() {
	 SetActivePage(m_listBox.GetCurSel());
	 UpdateWindow();
 }
BEGIN_MESSAGE_MAP(CArcGUIPropSheelDlg, CMFCPropertySheet)
	ON_WM_PAINT()
    ON_WM_ERASEBKGND()
	ON_WM_DRAWITEM()
	ON_WM_CTLCOLOR()
	ON_LBN_SELCHANGE(IDC_TABLIST,OnLBNTabChange)

END_MESSAGE_MAP()



