
// ArcGUIDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ArcGUI.h"
#include "ArcGUIDlg.h"
#include "afxdialogex.h"
#include "resource.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CArcGUIDlg dialog



CArcGUIDlg::CArcGUIDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INNDATA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pNavList = NULL;
}

void CArcGUIDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_WELCOME, m_staticWelcomeText);
	DDX_Control(pDX, IDC_STATIC_LOGO, m_LogoImage);
}

BEGIN_MESSAGE_MAP(CArcGUIDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CArcGUIDlg message handlers

BOOL CArcGUIDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	GdiplusStartupInput gdiplusStartupInput;
	GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Initialize members here
	
	m_dlgPropSheet.Create(this, WS_CHILD | WS_VISIBLE , 0);
	m_dlgPropSheet.ModifyStyleEx(0, WS_EX_CONTROLPARENT| WS_TABSTOP);
	CRect rcSheet;
	m_dlgPropSheet.GetWindowRect(&rcSheet);
	ScreenToClient(&rcSheet);
	m_dlgPropSheet.SetWindowPos(NULL, rcSheet.left, rcSheet.top + 50, rcSheet.right, rcSheet.bottom,
		 SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	font1 = new CFont();

	font1->CreatePointFont(160, L"Arial");

	m_staticWelcomeText.SetFont(font1);
	m_staticWelcomeText.ShowWindow(SW_HIDE);
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CArcGUIDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CArcGUIDlg::DrawLogo()
{
	CRect rect;
	m_LogoImage.GetClientRect(&rect);
	Graphics graphics(m_LogoImage.GetDC()->m_hDC);
	Image image(L"LogoKapalya.png", FALSE);
	graphics.DrawImage(&image, Gdiplus::Rect(rect.left, rect.top +10, 200, rect.Height()/2),0,0, image.GetWidth(), image.GetHeight() ,UnitPixel);

}
void CArcGUIDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		

	}
	else
	{
		CDialogEx::OnPaint();
		

	}
	m_dlgPropSheet.RedrawList();
	DrawLogo();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CArcGUIDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CArcGUIDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	return (HBRUSH)GetStockObject(WHITE_BRUSH);
}
