#pragma once
#include "afxdialogex.h"

class Cproject1View;

class CClarityDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CClarityDlg)

public:
	CClarityDlg(CWnd* pParent = nullptr);
	virtual ~CClarityDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CLARITY };
#endif

	void SetTargetView(Cproject1View* pView);

	int m_amount;   // -100 to 100

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	CSliderCtrl m_sliderAmount;
	Cproject1View* m_pTargetView = nullptr;

	void UpdateLabel();

	DECLARE_MESSAGE_MAP()
};
