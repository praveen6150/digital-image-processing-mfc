#pragma once
#include "afxdialogex.h"


// CBitPlaneDlg dialog

class CBitPlaneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBitPlaneDlg)

public:
	CBitPlaneDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBitPlaneDlg();
	int m_nBitPlane; 
	CSliderCtrl m_sliderBit;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BITPLANE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	DECLARE_MESSAGE_MAP()
};
