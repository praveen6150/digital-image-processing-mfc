// ChannelMixerDlg.h
#pragma once
#include "afxdialogex.h"

class Cproject1View;

class CChannelMixerDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CChannelMixerDlg)

public:
	CChannelMixerDlg(CWnd* pParent = nullptr);
	virtual ~CChannelMixerDlg();

	void SetTargetView(Cproject1View* pView) { m_pTargetView = pView; }

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHANNELMIXER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	virtual void OnCancel();

	afx_msg void OnHScroll(UINT nSFlags, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCbnSelchangeComboPreset();

	DECLARE_MESSAGE_MAP()

private:
	Cproject1View* m_pTargetView = nullptr;

	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderBlue;
	CComboBox   m_comboPreset;

	int m_redWeight;
	int m_greenWeight;
	int m_blueWeight;

	void UpdateValueLabels();
	void ApplyPreview();
	void ApplyPreset(int presetIndex);
};
