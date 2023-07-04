// Item5.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item5.h"


// CItem5 dialog

IMPLEMENT_DYNAMIC(CItem5, CMFCPropertyPage)

CItem5::CItem5()
	: CMFCPropertyPage(IDD_ITEM_5)
{

}

CItem5::~CItem5()
{
}

void CItem5::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}

BOOL  CItem5::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
}

BEGIN_MESSAGE_MAP(CItem5, CMFCPropertyPage)
END_MESSAGE_MAP()


// CItem5 message handlers
