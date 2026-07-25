#include "pch.h"
#include "project1.h"
#include "CSplitToneDlg.h"
#include "project1View.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CSplitToneDlg, CDialogEx)

CSplitToneDlg::CSplitToneDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SPLITTONE, pParent)
	, m_shadowTint(RGB(60, 100, 160))     // cool blue default for shadows
	, m_highlightTint(RGB(230, 170, 100)) // warm orange default for highlights
	, m_balance(0)
	, m_intensity(50)
{
}

CSplitToneDlg::~CSplitToneDlg()
{
}

void CSplitToneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_SPLITTONE_BALANCE, m_sliderBalance);
	DDX_Control(pDX, IDC_SLIDER_SPLITTONE_INTENSITY, m_sliderIntensity);
}

BEGIN_MESSAGE_MAP(CSplitToneDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_SHADOW_TINT, &CSplitToneDlg::OnBnClickedButtonShadowTint)
	ON_BN_CLICKED(IDC_BUTTON_HIGHLIGHT_TINT, &CSplitToneDlg::OnBnClickedButtonHighlightTint)
END_MESSAGE_MAP()

void CSplitToneDlg::SetTargetView(Cproject1View* pView)
{
	m_pTargetView = pView;
}

BOOL CSplitToneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_sliderBalance.SetRange(-100, 100, TRUE);
	m_sliderBalance.SetPos(m_balance);
	m_sliderBalance.SetTicFreq(50);

	m_sliderIntensity.SetRange(0, 100, TRUE);
	m_sliderIntensity.SetPos(m_intensity);
	m_sliderIntensity.SetTicFreq(25);

	UpdateShadowButtonLabel();
	UpdateHighlightButtonLabel();
	UpdateBalanceLabel();
	UpdateIntensityLabel();

	// Apply immediately so the initial state is reflected on the canvas right away
	UpdateLive();

	return TRUE;
}

void CSplitToneDlg::UpdateShadowButtonLabel()
{
	CString text;
	text.Format(_T("Shadow: R%d G%d B%d"), GetRValue(m_shadowTint), GetGValue(m_shadowTint), GetBValue(m_shadowTint));
	SetDlgItemText(IDC_BUTTON_SHADOW_TINT, text);
}

void CSplitToneDlg::UpdateHighlightButtonLabel()
{
	CString text;
	text.Format(_T("Highlight: R%d G%d B%d"), GetRValue(m_highlightTint), GetGValue(m_highlightTint), GetBValue(m_highlightTint));
	SetDlgItemText(IDC_BUTTON_HIGHLIGHT_TINT, text);
}

void CSplitToneDlg::UpdateBalanceLabel()
{
	CString text;
	text.Format(_T("Balance: %+d"), m_balance);
	SetDlgItemText(IDC_STATIC_BALANCE_TEXT, text);
}

void CSplitToneDlg::UpdateIntensityLabel()
{
	CString text;
	text.Format(_T("Intensity: %d%%"), m_intensity);
	SetDlgItemText(IDC_STATIC_INTENSITY_TEXT, text);
}

void CSplitToneDlg::OnBnClickedButtonShadowTint()
{
	CColorDialog dlg(m_shadowTint, CC_FULLOPEN, this);
	if (dlg.DoModal() == IDOK)
	{
		m_shadowTint = dlg.GetColor();
		UpdateShadowButtonLabel();
		UpdateLive();
	}
}

void CSplitToneDlg::OnBnClickedButtonHighlightTint()
{
	CColorDialog dlg(m_highlightTint, CC_FULLOPEN, this);
	if (dlg.DoModal() == IDOK)
	{
		m_highlightTint = dlg.GetColor();
		UpdateHighlightButtonLabel();
		UpdateLive();
	}
}

void CSplitToneDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar*)&m_sliderBalance)
	{
		m_balance = m_sliderBalance.GetPos();
		UpdateBalanceLabel();
	}
	else if (pScrollBar == (CScrollBar*)&m_sliderIntensity)
	{
		m_intensity = m_sliderIntensity.GetPos();
		UpdateIntensityLabel();
	}

	UpdateLive();

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CSplitToneDlg::UpdateLive()
{
	if (m_pTargetView)
		m_pTargetView->ApplyLiveSplitTone(m_shadowTint, m_highlightTint, m_balance, m_intensity);
}

void CSplitToneDlg::OnOK()
{
	CDialogEx::OnOK();
}

void CSplitToneDlg::OnCancel()
{
	if (m_pTargetView)
		m_pTargetView->RevertToOriginal();

	CDialogEx::OnCancel();
}
