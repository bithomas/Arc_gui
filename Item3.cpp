// Item3.cpp : implementation file
//

#include "pch.h"
#include "ArcGUI.h"
#include "afxdialogex.h"
#include "Item3.h"
#include <string>
#include <iostream>
#include <sstream>
#include <processthreadsapi.h>
#include <Windows.h>
#include <Psapi.h>
#include "resource.h"
using namespace std;

// CItem3 dialog

IMPLEMENT_DYNAMIC(CItem3, CMFCPropertyPage)

CItem3::CItem3()
	: CMFCPropertyPage(IDD_ITEM_3)
{

}

CItem3::~CItem3()
{
}

void CItem3::DoDataExchange(CDataExchange* pDX)
{
	CMFCPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CItem3, CMFCPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON_KILLPROCESS, &CItem3::OnBnClickedButton1)
END_MESSAGE_MAP()


// CItem3 message handlers

BOOL  CItem3::OnEraseBkgnd(CDC* pDC) {
	return FALSE;
}

void CItem3::OnBnClickedButton1()
{
	
	LPTSTR lpWord = new TCHAR[MAX_PATH + 1];
	if (lpWord)
	{
		memset(lpWord, '\0', MAX_PATH + 1 * sizeof(TCHAR));
		GetDlgItemText(IDC_EDIT1, lpWord, MAX_PATH);
	}
	wstring pid(lpWord);
	delete[]lpWord;
	lpWord = NULL;

	if (pid.empty())
	{
		::MessageBox(NULL, L"Enter valid process id", L"pid", MB_OK);
	}

	wstringstream ss(pid);
	unsigned int dword_pid;
	ss >> dword_pid;
	CStringW str;
	str.Format(L"Entered Process ID is:%d", dword_pid);
	SetDlgItemText(IDC_STATIC_2, str );

	try
	{
		const auto process_to_kill = OpenProcess(PROCSS_TERMINATE, false, dword_pid);
		TerminateProcess(process_to_kill, 1);
		CloseHandle(process_to_kill);
		
	}
	catch (...)
	{
		::MessageBox(NULL, L"Exception while trying to kill pid", L"pid", MB_OK);
	}
	// TODO: Add your control notification handler code here
}
