#pragma once
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus.lib")
#include <afxpropertypage.h>
#include "Item1.h"
#include "Item2.h"
#include "Item3.h"
#include "Item4.h"
#include "Item5.h"
#include "Item6.h"
#include "ListEx.h"
#include <vector>
using namespace LISTEX;

#define IDC_TABLIST 11007

// CLifePlanningSheet

class CArcGUIPropSheelDlg : public CMFCPropertySheet
{
    DECLARE_DYNAMIC(CArcGUIPropSheelDlg)

public:
    CArcGUIPropSheelDlg();
    virtual ~CArcGUIPropSheelDlg();


    // Overrides
    void OnPaint();
    void Draw_Borders(CDC* pDC);
    BOOL  OnEraseBkgnd(CDC* pDC);
    afx_msg void OnDrawItem(int  nCtlId, LPDRAWITEMSTRUCT lpdrawItemStruct);
    void DrawListBackground();
    void DrawListItem(LPDRAWITEMSTRUCT lpdrawItemStruct);
    HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
    void OnLBNTabChange();
    BOOL OnInitDialog();
    void RedrawList() {
        Invalidate();
    }

private:
    CItem1 m_Item1;
    CItem2 m_Item2;
    CItem3 m_Item3;
    CItem4 m_Item4;
    CItem5 m_Item5;
    CItem6 m_Item6;
    CRect m_listRect;
    CListBox m_listBox;
    CFont m_font;
    DRAWITEMSTRUCT m_drawitemstruct[10];
    int m_ntabCnt;
    bool bdrawList;

protected:
    ULONG_PTR m_gdiplusToken;
    DECLARE_MESSAGE_MAP()
    HICON m_hIcon;
};

