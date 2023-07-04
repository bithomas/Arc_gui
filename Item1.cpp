// Item1.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item1.h"
#include "HardwareInfo.h"

// CItem1 dialog

IMPLEMENT_DYNAMIC(CItem1, CMFCPropertyPage)

CItem1::CItem1()
	: CMFCPropertyPage(IDD_ITEM_1)
{
    ReadSystemInfo();
    GdiplusStartupInput gdiplusStartupInput;
    GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
}

void CItem1::ReadSystemInfo()
{

	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);

    string hardwareInf = GetHardwareInfo();
    CString strInfo(hardwareInf.c_str());
    m_strSysInfo = strInfo;
   
}

CItem1::~CItem1()
{
    GdiplusShutdown(m_gdiplusToken);
}

void CItem1::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SYS_INFO, m_strSysInfo);
    CFont* font = new CFont();

    font->CreatePointFont(80, L"Tahoma");

    SetFont(font);
    GetDlgItem(IDC_EDIT_SYS_INFO)->SetFont(font);
}
void CItem1::OnPaint() {
    if (m_hdc) {
        Graphics g1(m_hdc);
        SolidBrush Whitebrush(Color(255, 255, 255));
        g1.FillRectangle(&Whitebrush, Gdiplus::Rect(m_rect.left, m_rect.top, m_rect.Width(), m_rect.Height()));
    }
}
BOOL  CItem1::OnEraseBkgnd(CDC* pDC) {
    return FALSE;
}



BEGIN_MESSAGE_MAP(CItem1, CMFCPropertyPage)
    ON_WM_PAINT()
    

END_MESSAGE_MAP()


// CItem1 message handlers
