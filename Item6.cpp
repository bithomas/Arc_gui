// Item6.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item6.h"


// CItem6 dialog

IMPLEMENT_DYNAMIC(CItem6, CMFCPropertyPage)

CItem6::CItem6()
	: CMFCPropertyPage(IDD_ITEM_6)
{

}

CItem6::~CItem6()
{
}

void CItem6::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}

BOOL  CItem6::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
}

BEGIN_MESSAGE_MAP(CItem6, CMFCPropertyPage)
END_MESSAGE_MAP()


// CItem6 message handlers
