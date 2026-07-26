// ChannelMixerDlg.cpp
#include "pch.h"
#include "project1.h"
#include "ChannelMixerDlg.h"
#include "project1View.h"
#include "resource.h"

IMPLEMENT_DYNAMIC(CChannelMixerDlg, CDialogEx)

CChannelMixerDlg::CChannelMixerDlg(CWnd* pParent)
	: CDialogEx(IDD_CHANNELMIXER, pParent)
	, m_redWeight(30)
	, m_greenWeight(59)
	, m_blueWeight(11)
{
}

CChannelMixerDlg::~CChannelMixerDlg()
{
}

void CChannelMixerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_COMBO_PRESET, m_comboPreset);
}

BEGIN_MESSAGE_MAP(CChannelMixerDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_CBN_SELCHANGE(IDC_COMBO_PRESET, &CChannelMixerDlg::OnCbnSelchangeComboPreset)
END_MESSAGE_MAP()

BOOL CChannelMixerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Weights in percent, -200% to +200% -- doesn't need to sum to 100
	m_sliderRed.SetRange(-200, 200);
	m_sliderGreen.SetRange(-200, 200);
	m_sliderBlue.SetRange(-200, 200);

	m_sliderRed.SetPos(m_redWeight);
	m_sliderGreen.SetPos(m_greenWeight);
	m_sliderBlue.SetPos(m_blueWeight);

	m_comboPreset.AddString(_T("Neutral (Standard B&W)"));
	m_comboPreset.AddString(_T("Red Filter (Darken Skies)"));
	m_comboPreset.AddString(_T("Orange Filter"));
	m_comboPreset.AddString(_T("Yellow-Green Filter"));
	m_comboPreset.AddString(_T("Infrared Simulation"));
	m_comboPreset.AddString(_T("Custom"));
	m_comboPreset.SetCurSel(0);

	UpdateValueLabels();
	ApplyPreview();

	return TRUE;
}

void CChannelMixerDlg::OnHScroll(UINT nSFlags, UINT nPos, CScrollBar* pScrollBar)
{
	m_redWeight = m_sliderRed.GetPos();
	m_greenWeight = m_sliderGreen.GetPos();
	m_blueWeight = m_sliderBlue.GetPos();

	m_comboPreset.SetCurSel(5); // switch to "Custom" once user drags manually

	UpdateValueLabels();
	ApplyPreview();

	CDialogEx::OnHScroll(nSFlags, nPos, pScrollBar);
}

void CChannelMixerDlg::OnCbnSelchangeComboPreset()
{
	ApplyPreset(m_comboPreset.GetCurSel());
}

void CChannelMixerDlg::ApplyPreset(int presetIndex)
{
	switch (presetIndex)
	{
	case 0: m_redWeight = 30;  m_greenWeight = 59;  m_blueWeight = 11;  break; // Neutral (luminance-matched)
	case 1: m_redWeight = 100; m_greenWeight = 0;   m_blueWeight = 0;   break; // Red filter
	case 2: m_redWeight = 60;  m_greenWeight = 30;  m_blueWeight = 10;  break; // Orange filter
	case 3: m_redWeight = 10;  m_greenWeight = 70;  m_blueWeight = 20;  break; // Yellow-Green filter
	case 4: m_redWeight = -50; m_greenWeight = 100; m_blueWeight = 150; break; // Infrared-style
	default: return; // Custom -- leave sliders as user set them
	}

	m_sliderRed.SetPos(m_redWeight);
	m_sliderGreen.SetPos(m_greenWeight);
	m_sliderBlue.SetPos(m_blueWeight);

	UpdateValueLabels();
	ApplyPreview();
}

void CChannelMixerDlg::UpdateValueLabels()
{
	CString s;
	s.Format(_T("R: %d%%"), m_redWeight);   SetDlgItemText(IDC_STATIC_RED_VAL, s);
	s.Format(_T("G: %d%%"), m_greenWeight); SetDlgItemText(IDC_STATIC_GREEN_VAL, s);
	s.Format(_T("B: %d%%"), m_blueWeight);  SetDlgItemText(IDC_STATIC_BLUE_VAL, s);
}

void CChannelMixerDlg::ApplyPreview()
{
	if (m_pTargetView)
		m_pTargetView->ApplyLiveChannelMixer(m_redWeight, m_greenWeight, m_blueWeight);
}

void CChannelMixerDlg::OnCancel()
{
	if (m_pTargetView)
		m_pTargetView->RevertToOriginal();

	CDialogEx::OnCancel();
}
