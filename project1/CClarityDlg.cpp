#include "pch.h"
#include "project1.h"
#include "CClarityDlg.h"
#include "project1View.h"
#include "afxdialogex.h"

IMPLEMENT_DYNAMIC(CClarityDlg, CDialogEx)

CClarityDlg::CClarityDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_CLARITY, pParent)
	, m_amount(40)
{
}

CClarityDlg::~CClarityDlg()
{
}

void CClarityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_CLARITY_AMOUNT, m_sliderAmount);
}

BEGIN_MESSAGE_MAP(CClarityDlg, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()

void CClarityDlg::SetTargetView(Cproject1View* pView)
{
	m_pTargetView = pView;
}

BOOL CClarityDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_sliderAmount.SetRange(-100, 100, TRUE);
	m_sliderAmount.SetPos(m_amount);
	m_sliderAmount.SetTicFreq(50);

	UpdateLabel();

	if (m_pTargetView)
		m_pTargetView->ApplyLiveClarity(m_amount);

	return TRUE;
}

void CClarityDlg::UpdateLabel()
{
	CString text;
	text.Format(_T("Clarity: %+d"), m_amount);
	SetDlgItemText(IDC_STATIC_CLARITY_TEXT, text);
}

void CClarityDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (pScrollBar == (CScrollBar*)&m_sliderAmount)
	{
		m_amount = m_sliderAmount.GetPos();
		UpdateLabel();

		if (m_pTargetView)
			m_pTargetView->ApplyLiveClarity(m_amount);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CClarityDlg::OnOK()
{
	CDialogEx::OnOK();
}

void CClarityDlg::OnCancel()
{
	if (m_pTargetView)
		m_pTargetView->RevertToOriginal();

	CDialogEx::OnCancel();
}

