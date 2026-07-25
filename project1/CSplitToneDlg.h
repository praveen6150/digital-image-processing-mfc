#pragma once
#include "afxdialogex.h"

class Cproject1View;

class CSplitToneDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSplitToneDlg)

public:
	CSplitToneDlg(CWnd* pParent = nullptr);
	virtual ~CSplitToneDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SPLITTONE };
#endif

	void SetTargetView(Cproject1View* pView);

	COLORREF m_shadowTint;
	COLORREF m_highlightTint;
	int m_balance;      // -100 to 100
	int m_intensity;    // 0 to 100

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonShadowTint();
	afx_msg void OnBnClickedButtonHighlightTint();

	CSliderCtrl m_sliderBalance;
	CSliderCtrl m_sliderIntensity;

	Cproject1View* m_pTargetView = nullptr;

	void UpdateShadowButtonLabel();
	void UpdateHighlightButtonLabel();
	void UpdateBalanceLabel();
	void UpdateIntensityLabel();
	void UpdateLive();

	DECLARE_MESSAGE_MAP()
};

