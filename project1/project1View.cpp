// project1View.cpp : implementation of the Cproject1View class

#include "pch.h"
#include "framework.h"
#include "resource.h"
#ifndef SHARED_HANDLERS
#include "project1.h"
#endif
#include "project1Doc.h"
#include "project1View.h"
#include "CBrightnessContrastDlg.h"
#include "CHsiDlg.h"
#include "CYcbCrDlg.h"
#include "CHistogramDlg.h"
#include "CGammaDlg.h"
#include <cmath>
#include "CSolarizationDlg.h"
#include "CPosterizationDlg.h"
#include "CBitPlaneDlg.h"
#include "CColorBalanceDlg.h"
#include <new>
#include <vector>
#include <random>
#include <chrono>
#include "MainFrm.h"
#include "CFlipRotateDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CContrastStretchDlg.h"
#include "CFlipRotateDlg.h"
#include "CHsvDlg.h"
#include "CHslDlg.h"
#include "CLogTransformDlg.h"
#include "CInverseLogTransformDlg.h"
#include "CGraySlicingDlg.h"
#include "CPseudoColorDlg.h"
#include "COtsuThresholdDlg.h"
#include "CBinaryThresholdDlg.h"
#include "CLevelsAdjustmentDlg.h"
#include "CSigmoidContrastDlg.h"
#include "CSepiaToneDlg.h"
#include "CCurvesAdjustmentDlg.h"
#include "CCurveControl.h"
#include "CChannelIsolationDlg.h"
#include "CDuotoneDlg.h"
#include "CGaussianNoiseDlg.h"
#include "CSaltPepperNoiseDlg.h"
#include "CVignetteDlg.h"
#include "CCmykDlg.h"
#include "CQuantumSimDlg.h"
#include "CQuantumDPPDlg.h"
#include "CColorizeDlg.h"
#include "CVibranceDlg.h"
#include "CWhiteBalanceDlg.h"
#include "CColorReplaceDlg.h"
#include "CExposureDlg.h"
#include "CLuvDlg.h"
#include "CLiftGammaGainDlg.h"
#include "CColorPopDlg.h"
#include "CBleachBypassDlg.h"
#include "CClarityDlg.h"
#include "CSplitToneDlg.h"
#include "ChannelMixerDlg.h"

IMPLEMENT_DYNCREATE(Cproject1View, CScrollView)

BEGIN_MESSAGE_MAP(Cproject1View, CScrollView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_COMMAND(ID_VIEW_FITTOWINDOW, &Cproject1View::OnViewFittowindow)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FITTOWINDOW, &Cproject1View::OnUpdateViewFittowindow)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_COMMAND(ID_POINT_INVERTCOLORS, &Cproject1View::OnPointInvertcolors)
	ON_COMMAND(ID_POINT_BRIGHTNESS_CONTRAST, &Cproject1View::OnPointBrightnessContrast)
	ON_COMMAND(ID_POINTPROCESS_HSI, &Cproject1View::OnPointprocessHsi)
	ON_COMMAND(ID_POINTPROCESS_LUMINANCE, &Cproject1View::OnPointprocessLuminance)
	ON_COMMAND(ID_POINT_HISTOGRAM_EQUALIZATION, &Cproject1View::OnPointHistogramEqualization)
	ON_COMMAND(ID_POINTPROCESS_HISTOGRAMGRAPH, &Cproject1View::OnPointprocessHistogramgraph)
	ON_COMMAND(ID_POINTPROCESS_GAMMACORRECTION, &Cproject1View::OnPointprocessGammacorrection)
	ON_COMMAND(ID_POINTPROCESS_SOLARIZATION, &Cproject1View::OnPointprocessSolarization)
	ON_COMMAND(ID_POINTPROCESS_POSTERIZATION, &Cproject1View::OnPointprocessPosterization)
	ON_COMMAND(ID_POINTPROCESS_BITPLANE, &Cproject1View::OnPointprocessBitplane)
	ON_COMMAND(ID_POINTPROCESS_CONTRASTSTRETCH, &Cproject1View::OnPointprocessContraststretch)
	ON_COMMAND(ID_POINTPROCESS_COLORBALANCE, &Cproject1View::OnPointprocessColorbalance)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_AVERAGEBLUR, &Cproject1View::OnNeighborhoodprocessingAverageblur)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_GAUSSIANBLUR, &Cproject1View::OnNeighborhoodprocessingGaussianblur)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_LOWPASSFILTER, &Cproject1View::OnNeighborhoodprocessingLowpassfilter)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_HIGHPASSFILTER, &Cproject1View::OnNeighborhoodprocessingHighpassfilter)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_MEDIANFILTER, &Cproject1View::OnNeighborhoodprocessingMedianfilter)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_SOBELEDGEDETECTION, &Cproject1View::OnNeighborhoodprocessingSobeledgedetection)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_KRISHEDGEDETECTION, &Cproject1View::OnNeighborhoodprocessingKrishedgedetection)
	ON_COMMAND(ID_NEIGHBORHOODPROCESSING_PREWITTEDGEDETECTION, &Cproject1View::OnNeighborhoodprocessingPrewittedgedetection)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_SCHARREDGEDETECTION, &Cproject1View::OnSpatialdomainfilteringScharredgedetection)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_LAPLACIANOFGAUSSIAN, &Cproject1View::OnSpatialdomainfilteringLaplacianofgaussian)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_CANNYEDGEDETECTOR32810, &Cproject1View::OnSpatialdomainfilteringCannyedgedetector32810)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_LAPLACIANFILTER, &Cproject1View::OnSpatialdomainfilteringLaplacianfilter)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_FREI, &Cproject1View::OnSpatialdomainfilteringFrei)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_ROBERTSCROSSOPERATOR, &Cproject1View::OnSpatialdomainfilteringRobertscrossoperator)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_DIFFERENCEOFGAUSSIANS, &Cproject1View::OnSpatialdomainfilteringDifferenceofgaussians)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_MARR, &Cproject1View::OnSpatialdomainfilteringMarr)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_KAYYALIOPERATOR, &Cproject1View::OnSpatialdomainfilteringKayyalioperator)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_ROBINSONCOMPASSOPERATOR, &Cproject1View::OnSpatialdomainfilteringRobinsoncompassoperator)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_NEVATIA, &Cproject1View::OnSpatialdomainfilteringNevatia)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_DERICHEFILTER, &Cproject1View::OnSpatialdomainfilteringDerichefilter)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_UNSHARPMASKING, &Cproject1View::OnSpatialdomainfilteringUnsharpmasking)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_EMBOSSFILTER, &Cproject1View::OnSpatialdomainfilteringEmbossfilter)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_GREDIENTMAGNITUDE, &Cproject1View::OnSpatialdomainfilteringGredientmagnitude)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_BILATERALFILTER, &Cproject1View::OnSpatialdomainfilteringBilateralfilter)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_NON, &Cproject1View::OnSpatialdomainfilteringNon)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_WIENERFILTER, &Cproject1View::OnSpatialdomainfilteringWienerfilter)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_EROSION, &Cproject1View::OnSpatialdomainfilteringErosion)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_DOMAINFILTERINGOPENING, &Cproject1View::OnSpatialdomainfilteringDomainfilteringopening)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_DOMAINFILTERINGCLOSING, &Cproject1View::OnSpatialdomainfilteringDomainfilteringclosing)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_DOMAINFILTERINGMORPHOLOGICALGRADIENT, &Cproject1View::OnSpatialdomainfilteringDomainfilteringmorphologicalgradient)
	ON_COMMAND(ID_TRANSFORM_FLIP, &Cproject1View::OnImageFlipRotate)
	ON_COMMAND(IDD_DIALOG_HSV, &Cproject1View::OnColorsHsvadjustment)
	ON_COMMAND(ID_POINTPROCESS_HUE32840, &Cproject1View::OnColorsHsvadjustment)
	ON_COMMAND(ID_POINTPROCESS_CONVERTTOGRAYSCALE, &Cproject1View::OnPointprocessConverttograyscale)
	ON_COMMAND(ID_POINTPROCESS_HUE32842, &Cproject1View::OnPointprocessHsl)
	ON_COMMAND(ID_INTENSITYANDMAPPINGTRANSFORMATION_LOGTRANSFORMATION, &Cproject1View::OnPointprocessLogtransformation)
	ON_COMMAND(ID_INTENSITYANDMAPPINGTRANSFORMATION_INVERSELOGTRANSFORMATION, &Cproject1View::OnPointprocessInverselogtransformation)
	ON_COMMAND(ID_INTENSITYANDMAPPINGTRANSFORMATION_GRAYSLICING, &Cproject1View::OnPointprocessGrayslicing)
	ON_COMMAND(ID_COLORANDVISUALIZATION_PSEUDO, &Cproject1View::OnColorprocessPseudocoloring)
	ON_COMMAND(ID_POINTPROCESS_OTSUTHRESHOLD, &Cproject1View::OnPointprocessOtsuthreshold)
	ON_COMMAND(ID_POINTPROCESS_BINARYTHRESHOLD, &Cproject1View::OnPointprocessBinarythreshold)
	ON_COMMAND(ID_BASICINTENSITYTRANSFORMATIONS_LEVELADJUSTMENT, &Cproject1View::OnPointprocessLevelsadjustment)
	ON_COMMAND(ID_POINTPROCESS_SIGMOIDCONTRAST, &Cproject1View::OnPointprocessSigmoidcontrast)
	ON_COMMAND(ID_POINTPROCESS_SEPIATONE, &Cproject1View::OnPointprocessSepiatone)
	ON_COMMAND(ID_POINTPROCESS_CURVESADJUSTMENT, &Cproject1View::OnPointprocessCurvesadjustment)
	ON_COMMAND(ID_POINTPROCESS_CHANNELISOLATION, &Cproject1View::OnPointprocessChannelisolation)
	ON_COMMAND(ID_POINTPROCESS_DUOTONE, &Cproject1View::OnPointprocessDuotone)
	ON_COMMAND(ID_POINTPROCESS_GAUSSIANNOISE, &Cproject1View::OnPointprocessGaussiannoise)
	ON_COMMAND(ID_POINTPROCESS_SALTPEPPERNOISE, &Cproject1View::OnPointprocessSaltpeppernoise)
	ON_COMMAND(ID_POINTPROCESS_VIGNETTE, &Cproject1View::OnPointprocessVignette)
	ON_COMMAND(ID_POINTPROCESS_CMYK, &Cproject1View::OnPointprocessCmyk)
	ON_COMMAND(ID_POINTPROCESS_QUANTUMSIM, &Cproject1View::OnPointprocessQuantumsim)
	ON_COMMAND(ID_POINTPROCESS_QUANTUMDPP, &Cproject1View::OnPointprocessQuantumdpp)
	ON_WM_MOUSEWHEEL()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_POINTPROCESS_COLORIZE, &Cproject1View::OnPointprocessColorize)
	ON_COMMAND(ID_POINTPROCESS_VIBRANCE, &Cproject1View::OnPointprocessVibrance)
	ON_COMMAND(ID_POINTPROCESS_WHITEBALANCE, &Cproject1View::OnPointprocessWhitebalance)
	ON_COMMAND(ID_POINTPROCESS_AUTOLEVELS, &Cproject1View::OnPointprocessAutolevels)
	ON_COMMAND(ID_POINTPROCESS_COLORREPLACE, &Cproject1View::OnPointprocessColorreplace)
	ON_COMMAND(ID_POINTPROCESS_EXPOSURE, &Cproject1View::OnPointprocessExposure)
	ON_COMMAND(ID_POINTPROCESS_AUTOWHITEBALANCE, &Cproject1View::OnPointprocessAutowhitebalance)
	ON_COMMAND(ID_POINTPROCESS_CIELUV, &Cproject1View::OnPointprocessCieluv)

	ON_COMMAND(ID_POINTPROCESS_LIFTGAMMAGAIN, &Cproject1View::OnPointprocessLiftgammagain)
	ON_COMMAND(ID_POINTPROCESS_COLORPOP, &Cproject1View::OnPointprocessColorpop)
	ON_COMMAND(ID_POINTPROCESS_BLEACHBYPASS, &Cproject1View::OnPointprocessBleachbypass)
	ON_COMMAND(ID_SPATIALDOMAINFILTERING_CLARITY, &Cproject1View::OnSpatialdomainfilteringClarity)
	ON_COMMAND(ID_POINTPROCESS_SPLITTONE, &Cproject1View::OnPointprocessSplittone)
	ON_COMMAND(ID_POINTPROCESS_CHANNELMIXERBW, &Cproject1View::OnPointprocessChannelmixerbw)
END_MESSAGE_MAP()


HHOOK Cproject1View::s_hColorPickerHook = NULL;
Cproject1View* Cproject1View::s_pActiveColorPickerView = nullptr;

HHOOK Cproject1View::s_hColorPickerHook2 = NULL;
Cproject1View* Cproject1View::s_pActiveColorPickerView2 = nullptr;


static double g_srgbToLinearLUT[256];
static bool g_lutInitialized = false;

static void InitSrgbLUT()
{
	if (g_lutInitialized) return;
	for (int i = 0; i < 256; i++)
	{
		double c = i / 255.0;
		g_srgbToLinearLUT[i] = (c <= 0.04045) ? (c / 12.92) : pow((c + 0.055) / 1.055, 2.4);
	}
	g_lutInitialized = true;
}

static double LinearToSrgb(double c)
{
	double v = (c <= 0.0031308) ? (c * 12.92) : (1.055 * pow(c, 1.0 / 2.4) - 0.055);
	v *= 255.0;
	return (v < 0.0) ? 0.0 : (v > 255.0 ? 255.0 : v);
}

static const double Xn = 95.0489, Yn = 100.0, Zn = 108.8840;

static double LabF(double t)
{
	const double delta = 6.0 / 29.0;
	return (t > delta * delta * delta) ? cbrt(t) : (t / (3.0 * delta * delta) + 4.0 / 29.0);
}

static double LabFInv(double t)
{
	const double delta = 6.0 / 29.0;
	return (t > delta) ? (t * t * t) : (3.0 * delta * delta * (t - 4.0 / 29.0));
}

static double un_prime = (4.0 * Xn) / (Xn + 15.0 * Yn + 3.0 * Zn);
static double vn_prime = (9.0 * Yn) / (Xn + 15.0 * Yn + 3.0 * Zn);



template<typename Func>
void Cproject1View::ProcessPixels(Func pfnPixelOp)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull()) return;

	int nWidth = pDoc->m_image.GetWidth();
	int nHeight = pDoc->m_image.GetHeight();
	int nStride = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Dynamically calculate bytes per pixel (3 for 24-bit, 4 for 32-bit)
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	if (bytesPerPixel < 3) return; // Skip if it's grayscale/indexed

	for (int y = 0; y < nHeight; ++y)
	{
		BYTE* pRow = pBits + (y * nStride);
		for (int x = 0; x < nWidth; ++x)
		{
			int offset = x * bytesPerPixel;
			// Dynamically processes the correct B, G, R memory positions
			pfnPixelOp(pRow[offset], pRow[offset + 1], pRow[offset + 2]);
		}
	}
	pDoc->UpdateAllViews(NULL);
}

Cproject1View::Cproject1View() noexcept
	: m_noiseGenerator((unsigned int)std::chrono::steady_clock::now().time_since_epoch().count())
{
	// TODO: add construction code here
	m_bFitToWindow = FALSE;
	m_pHistDlg = nullptr;
}

Cproject1View::~Cproject1View()
{
}
void Cproject1View::OnDestroy()
{
	// Make sure the non-modal histogram dialog doesn't outlive the view
	if (m_pHistDlg != nullptr && ::IsWindow(m_pHistDlg->m_hWnd))
	{
		m_pHistDlg->DestroyWindow();   
		
		// triggers OnNcDestroy() now, while m_pView is still valid
		// Note: OnNcDestroy() does "delete this", so m_pHistDlg is now a dangling
		// pointer in the VIEW's own member — but we're about to be destroyed too,
		// so this is safe. Just don't touch m_pHistDlg after this point.
	}
	CScrollView::OnDestroy();
}

BOOL Cproject1View::PreCreateWindow(CREATESTRUCT& cs)
{
	return CScrollView::PreCreateWindow(cs);
}

void Cproject1View::OnDraw(CDC* pDC)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	CRect rectClient;
	GetClientRect(&rectClient);

	// 1. Double Buffering Setup
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap memBitmap;
	memBitmap.CreateCompatibleBitmap(pDC, rectClient.Width(), rectClient.Height());
	CBitmap* pOldBitmap = memDC.SelectObject(&memBitmap);

	// 2. Clear the memory buffer background
	CBrush bgBrush(GetSysColor(COLOR_WINDOW));
	memDC.FillRect(&rectClient, &bgBrush);

	// 3. Check for the EXACT live preview flag managed by the slider dialog
	if (m_bPreviewRotationActive)
	{
		// Draw the preview directly onto our off-screen memory context buffer
		DrawArbitraryRotationPreview(&memDC, pDoc->m_image, m_previewRotationAngle);
	}
	else if (m_bFitToWindow)
	{
		int imgWidth = pDoc->m_image.GetWidth();
		int imgHeight = pDoc->m_image.GetHeight();

		double destAspect = (double)rectClient.Width() / rectClient.Height();
		double srcAspect = (double)imgWidth / imgHeight;
		int drawWidth = rectClient.Width();
		int drawHeight = rectClient.Height();
		int startX = 0;
		int startY = 0;

		if (destAspect > srcAspect)
		{
			drawWidth = (int)(rectClient.Height() * srcAspect);
			startX = (rectClient.Width() - drawWidth) / 2;
		}
		else
		{
			drawHeight = (int)(rectClient.Width() / srcAspect);
			startY = (rectClient.Height() - drawHeight) / 2;
		}

		memDC.SetStretchBltMode(COLORONCOLOR);
		pDoc->m_image.StretchBlt(memDC.GetSafeHdc(), startX, startY, drawWidth, drawHeight, 0, 0, imgWidth, imgHeight, SRCCOPY);
	}
	else
	{
		CPoint scrollPos = GetScrollPosition();

		int imgWidth = pDoc->m_image.GetWidth();
		int imgHeight = pDoc->m_image.GetHeight();

		// Which portion of the SOURCE IMAGE is visible, accounting for zoom
		double srcX = scrollPos.x / m_zoomFactor;
		double srcY = scrollPos.y / m_zoomFactor;
		double srcW = rectClient.Width() / m_zoomFactor;
		double srcH = rectClient.Height() / m_zoomFactor;

		// Clamp so we never read past the image's actual bounds
		if (srcX + srcW > imgWidth)  srcW = imgWidth - srcX;
		if (srcY + srcH > imgHeight) srcH = imgHeight - srcY;

		if (srcW > 0 && srcH > 0 && srcX < imgWidth && srcY < imgHeight)
		{
			int destW = (int)(srcW * m_zoomFactor);
			int destH = (int)(srcH * m_zoomFactor);

			memDC.SetStretchBltMode(COLORONCOLOR);
			pDoc->m_image.StretchBlt(
				memDC.GetSafeHdc(),
				0, 0, destW, destH,
				(int)srcX, (int)srcY, (int)srcW, (int)srcH,
				SRCCOPY
			);
		}
	}

	// 4. Single hardware copy to physical display instantly (Zero Flicker)
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &memDC, 0, 0, SRCCOPY);

	// Cleanup
	memDC.SelectObject(pOldBitmap);
}

void Cproject1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc && !pDoc->m_image.IsNull())
	{
		int imgW = pDoc->m_image.GetWidth();
		int imgH = pDoc->m_image.GetHeight();

		// ── Step 1: Get usable screen area (excludes taskbar) ──────────────
		RECT workArea;
		SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);
		int screenW = workArea.right - workArea.left;
		int screenH = workArea.bottom - workArea.top;

		// ── Step 2: Measure the MDI main frame chrome overhead ─────────────
		// This accounts for: main title bar + menu bar + toolbar + status bar
		// so the child window fits INSIDE all of them, not behind them.
		CFrameWnd* pMainFrame = (CFrameWnd*)AfxGetMainWnd();
		int chromeH = 0;
		int chromeW = 0;

		if (pMainFrame)
		{
			RECT mainRect;
			pMainFrame->GetWindowRect(&mainRect);

			RECT clientRect;
			pMainFrame->GetClientRect(&clientRect);

			// Chrome = total frame size minus its usable client area
			chromeW = (mainRect.right - mainRect.left) - clientRect.right;
			chromeH = (mainRect.bottom - mainRect.top) - clientRect.bottom;
		}

		// ── Step 3: Also account for MDI child frame border & title bar ────
		int childTitleH = GetSystemMetrics(SM_CYCAPTION);   // Child title bar
		int childBorderW = GetSystemMetrics(SM_CXSIZEFRAME) * 2;
		int childBorderH = GetSystemMetrics(SM_CYSIZEFRAME) * 2;

		// ── Step 4: Compute the true available canvas space ────────────────
		int targetW = (int)(screenW * 0.95) - chromeW - childBorderW;
		int targetH = (int)(screenH * 0.95) - chromeH - childBorderH - childTitleH;

		// ── Step 5: Decide fit mode ────────────────────────────────────────
		if (imgW > targetW || imgH > targetH)
		{
			m_bFitToWindow = TRUE;

			// Compute child window size that contains the image aspect ratio
			// while staying within targetW x targetH
			double scaleW = (double)targetW / imgW;
			double scaleH = (double)targetH / imgH;
			double scale = min(scaleW, scaleH); // Pick the tightest fit

			// ⭐ UPDATE 1: Store the true scale ratio into your zoom tracking variable!
			m_zoomFactor = scale;

			int fitImgW = (int)(imgW * scale);
			int fitImgH = (int)(imgH * scale);

			// Add child chrome back to get the full child window size
			int childW = fitImgW + childBorderW;
			int childH = fitImgH + childBorderH + childTitleH;

			// Resize and reposition the MDI child frame
			CFrameWnd* pFrame = GetParentFrame();
			if (pFrame)
			{
				CWnd* pMDIClient = pMainFrame ? pMainFrame->GetWindow(GW_CHILD) : nullptr;
				int originX = 0, originY = 0;
				if (pMDIClient)
				{
					RECT mdiRect;
					pMDIClient->GetWindowRect(&mdiRect);
					originX = mdiRect.left;
					originY = mdiRect.top;
				}

				pFrame->SetWindowPos(
					&CWnd::wndTop,
					0,
					0,
					childW,
					childH,
					SWP_SHOWWINDOW
				);
			}

			// Apply fit-to-window scaling
			CRect rectClient;
			GetClientRect(&rectClient);
			if (rectClient.Width() > 0 && rectClient.Height() > 0)
				SetScaleToFitSize(rectClient.Size());
		}
		else
		{
			// Small image → 1:1 native pixel mode
			m_bFitToWindow = FALSE;
			m_zoomFactor = 1.0;
			SetScrollSizes(MM_TEXT, CSize(imgW, imgH));
			ResizeParentToFit(TRUE);
		}
	}
	else
	{
		SetScrollSizes(MM_TEXT, CSize(100, 100));
	}
}

// Cproject1View printing
BOOL Cproject1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	return DoPreparePrinting(pInfo);
}

void Cproject1View::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	CScrollView::OnPrepareDC(pDC, pInfo);
	if (!pInfo) 
	{
		pDC->SetViewportOrg(0, 0);
	}
}

void Cproject1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void Cproject1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

// Cproject1View diagnostics
#ifdef _DEBUG
void Cproject1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cproject1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cproject1Doc* Cproject1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cproject1Doc)));
	return (Cproject1Doc*)m_pDocument;
}
#endif //_DEBUG
void Cproject1View::OnViewFittowindow()
{
	m_bFitToWindow = !m_bFitToWindow;

	if (m_bFitToWindow)
	{
		// ✅ Set scale ONCE here, not repeatedly in OnDraw
		CRect rectClient;
		GetClientRect(&rectClient);
		SetScaleToFitSize(rectClient.Size());
	}
	else
	{
		Cproject1Doc* pDoc = GetDocument();
		if (pDoc && !pDoc->m_image.IsNull())
		{
			CSize sizeTotal(pDoc->m_image.GetWidth(), pDoc->m_image.GetHeight());
			SetScrollSizes(MM_TEXT, sizeTotal);
		}
	}

	Invalidate(FALSE);
}

void Cproject1View::OnUpdateViewFittowindow(CCmdUI* pCmdUI)
{
	// Check or uncheck the menu item dynamically based on the current state
	pCmdUI->SetCheck(m_bFitToWindow);
}

BOOL Cproject1View::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
		// return CScrollView::OnEraseBkgnd(pDC);
}

void Cproject1View::OnPointInvertcolors()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP(); // Bits per pixel (usually 24 or 32 for color images)

	// We only process standard 24-bit (RGB) or 32-bit (RGBA) images for now
	if (bpp < 24)
	{
		AfxMessageBox(_T("Only 24-bit or 32-bit images are supported for direct pointer modification right now."));
		return;
	}

	// 1. Get the base address pointer and the row stride (pitch)
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();
	int pitch = pDoc->m_image.GetPitch();
	int bytesPerPixel = bpp / 8;

	// 2. Multi-row memory array processing loop
	for (int y = 0; y < height; y++)
	{
		// Calculate exactly where row 'y' starts in the raw memory block
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			// Calculate the memory offset for the specific pixel (x) in this row
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			// Note: Windows stores pixels in BGR order in memory (Blue, Green, Red)
			pPixel[0] = 255 - pPixel[0]; // Invert Blue
			pPixel[1] = 255 - pPixel[1]; // Invert Green
			pPixel[2] = 255 - pPixel[2]; // Invert Red

			// If it's a 32-bit image, pPixel[3] is the Alpha channel (transparency). 
			// We leave Alpha alone so the image doesn't turn invisible!
		}
	}

	// 3. Force the window to cleanly repaint the modified memory block without blinking
	Invalidate(FALSE);
}
void Cproject1View::OnPointBrightnessContrast()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. Instantiate the slider dialog frame
	CBrightnessContrastDlg dlg;

	// 2. LINK THE DIALOG POINTER LIVE RIGHT HERE SO IT CAN TALK BACK TO THIS VIEW
	dlg.m_pView = this;

	// 3. Open the Dialog Window modal
	if (dlg.DoModal() == IDCANCEL)
	{
		// EXTRA PROTECTION UX: If the user clicks Cancel, discard the live slider 
		// tweaks and instantly restore our workspace from the pristine original backup copy.
		pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
		pDoc->m_image.ReleaseDC();

		// Repaint back to normal state
		Invalidate(FALSE);
	}
}

void Cproject1View::ApplyLiveBrightnessContrast(int bPos, int cPos)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull())
		return;

	// Restore original image canvas state
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();

	if (bpp < 24) return;

	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();
	int pitch = pDoc->m_image.GetPitch();
	int bytesPerPixel = bpp / 8;

	// --- OPTIMIZED CALIBRATION MATH FOR FULL BLACK/WHITE EXTENSION ---

	// Brightness Mapping: Range -255 to +255
	double brightnessOffset = (bPos / 100.0) * 255.0;

	// Contrast Mapping: Range 0.0x to 4.0x
	double contrastFactor = 1.0;
	if (cPos >= 0)
	{
		contrastFactor = 1.0 + (cPos / 100.0) * 3.0; // Slides right: 1.0x -> 4.0x multiplier
	}
	else
	{
		contrastFactor = 1.0 + (cPos / 100.0);       // Slides left:  1.0x -> 0.0x (flattens to gray)
	}

	// High-performance pointer direct-memory modification sweep
	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			for (int c = 0; c < 3; c++)
			{
				double originalValue = pPixel[c];
				double newValue = originalValue;

				// 1. First adjust contrast relative to the standard midpoint intensity (128)
				newValue = 128.0 + (originalValue - 128.0) * contrastFactor;

				// 2. Then apply the brightness offset shift
				newValue += brightnessOffset;

				// HARD BOUNDS PROTECTION: Force absolute black/white saturation drops
				if (bPos == -100) newValue = 0.0;   // Absolute minimum brightness = Pure Black
				if (bPos == 100)  newValue = 255.0; // Absolute maximum brightness = Pure White
				if (cPos == -100) newValue = 128.0; // Absolute minimum contrast = Complete Flat Gray

				// Final clipping guards
				if (newValue > 255.0) newValue = 255.0;
				if (newValue < 0.0)   newValue = 0.0;

				pPixel[c] = (BYTE)newValue;
			}
		}
	}
	// Update canvas layout view
	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessHsi()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull()) return;

	CHsiDlg dlg;
	dlg.m_pView = this;

	if (dlg.DoModal() == IDCANCEL)
	{
		// OPTIMIZED Cancel fallback: Restore clear original backup copy using full block copy
		if (!pDoc->m_imageOriginal.IsNull())
		{
			int pitch = pDoc->m_imageOriginal.GetPitch();
			int height = pDoc->m_imageOriginal.GetHeight();
			BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
			BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

			if (pitch < 0)
			{
				BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
				BYTE* pDstStart = pDstBits + (pitch * (height - 1));
				memcpy(pDstStart, pSrcStart, abs(pitch) * height);
			}
			else
			{
				memcpy(pDstBits, pSrcBits, pitch * height);
			}
		}
		Invalidate(FALSE);
		UpdateWindow();
	}
}

void Cproject1View::ApplyLiveHSI(int hDeg, int sSat, int iInt)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// 1. Reset current live image to original data first using safe block copy
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	// 2. Precalculate normalized tuning variables
	double hueShift = hDeg / 360.0;
	double satFactor = 1.0 + (sSat / 100.0);
	double intOffset = (iInt / 100.0);

	// 3. Fire up the high-speed processing template with an in-place Lambda!
	ProcessPixels([=](BYTE& b, BYTE& g, BYTE& r)
		{
			// Read and normalize BGR channel values
			double B = b / 255.0;
			double G = g / 255.0;
			double R = r / 255.0;

			// --- RGB to HSI ---
			double maxC = max(R, max(G, B));
			double minC = min(R, min(G, B));
			double delta = maxC - minC;

			// Intensity
			double I = (R + G + B) / 3.0;

			// Saturation
			double S = (I > 0.0) ? (delta / (maxC + 0.0001)) : 0.0;

			// Hue (0.0 to 1.0)
			double H = 0.0;
			if (delta > 0.0001)
			{
				if (maxC == R)       H = fmod((G - B) / delta, 6.0) / 6.0;
				else if (maxC == G)  H = ((B - R) / delta + 2.0) / 6.0;
				else                 H = ((R - G) / delta + 4.0) / 6.0;

				if (H < 0.0) H += 1.0;
			}

			// --- Apply HSI adjustments ---
			H += hueShift;
			if (H > 1.0) H -= 1.0;
			if (H < 0.0) H += 1.0;

			S = max(0.0, min(1.0, S * satFactor));
			I = max(0.0, min(1.0, I + intOffset));

			// --- HSI back to RGB ---
			double newR, newG, newB;
			if (S == 0.0)
			{
				newR = newG = newB = I;
			}
			else
			{
				double h6 = H * 6.0;
				int    hi = (int)h6 % 6;
				double f = h6 - (int)h6;
				double p = I * (1.0 - S);
				double q = I * (1.0 - S * f);
				double t = I * (1.0 - S * (1.0 - f));

				switch (hi)
				{
				case 0:  newR = I; newG = t; newB = p; break;
				case 1:  newR = q; newG = I; newB = p; break;
				case 2:  newR = p; newG = I; newB = t; break;
				case 3:  newR = p; newG = q; newB = I; break;
				case 4:  newR = t; newG = p; newB = I; break;
				default: newR = I; newG = p; newB = q; break;
				}
			}

			// Write modified channels directly back through our references
			b = (BYTE)max(0.0, min(255.0, newB * 255.0));
			g = (BYTE)max(0.0, min(255.0, newG * 255.0));
			r = (BYTE)max(0.0, min(255.0, newR * 255.0));
		});

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessLuminance()
{
	// TODO: Add your command handler code here
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. Instantiate the HSI slider dialog frame
	CYcbCrDlg dlg;

	// 2. Link the dialog pointer live so it can talk back to this view canvas
	dlg.m_pView = this;

	// 3. Open the Dialog Window modally
	if (dlg.DoModal() == IDCANCEL)
	{
		// If the user clicks Cancel, discard the live tweaks and restore original backup copy
		if (!pDoc->m_imageOriginal.IsNull())
		{
			pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
			pDoc->m_image.ReleaseDC();
		}

		// Repaint back to standard state
		Invalidate(FALSE);
	}
}

void Cproject1View::ApplyLiveYCbCr(int yOffset, int cbOffset, int crOffset)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull())
		return;

	// 1. Restore the image canvas state to the pristine original backup copy
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return; // Support 24-bit RGB and 32-bit RGBA images

	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();
	int   pitch = pDoc->m_image.GetPitch();
	int   bytesPerPix = bpp / 8;

	// Convert your slider luminance offset percentage (-100 to 100) to an exact 0-255 scaling factor
	double lumaShift = (yOffset / 100.0) * 255.0;

	// High-performance pointer direct-memory loop
	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPix);

			// Read standard raw Windows BGR values
			double B = pPixel[0];
			double G = pPixel[1];
			double R = pPixel[2];

			// --- A. RGB TO YCBCR TRANSFORMATION (ITU-R BT.601 standard) ---
			double Y = 0.29900 * R + 0.58700 * G + 0.11400 * B;
			double Cb = -0.16874 * R - 0.33126 * G + 0.50000 * B + 128.0;
			double Cr = 0.50000 * R - 0.41869 * G - 0.08131 * B + 128.0;

			// --- B. APPLY SLIDER SHIFTS ---
			Y += lumaShift;
			Cb += cbOffset;
			Cr += crOffset;

			// --- C. YCBCR BACK TO RGB TRANSFORMATION ---
			double newR = Y + 1.40200 * (Cr - 128.0);
			double newG = Y - 0.34414 * (Cb - 128.0) - 0.71414 * (Cr - 128.0);
			double newB = Y + 1.77200 * (Cb - 128.0);

			// --- D. CLIPPING PROTECTION GUARDS (Keep colors within valid 0-255 byte limits) ---
			if (newR > 255.0) newR = 255.0; if (newR < 0.0) newR = 0.0;
			if (newG > 255.0) newG = 255.0; if (newG < 0.0) newG = 0.0;
			if (newB > 255.0) newB = 255.0; if (newB < 0.0) newB = 0.0;

			// Write adjusted color bytes back to the live pixel pointer
			pPixel[0] = (BYTE)newB;
			pPixel[1] = (BYTE)newG;
			pPixel[2] = (BYTE)newR;
			// Alpha channel (pPixel[3]) is safely untouched for 32-bit images
		}
	}
	// 4. Force window to cleanly repaint the workspace matrix
	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointHistogramEqualization()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. Initialize image properties
	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return; // Works on 24-bit RGB and 32-bit RGBA images

	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();
	int   pitch = pDoc->m_image.GetPitch();
	int   bytesPerPix = bpp / 8;
	int   totalPixels = width * height;

	// 2. Allocate and compute the histogram (using average intensity for color images)
	int hist[256] = { 0 };

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPix);

			// Calculate standard grayscale intensity value for this pixel
			int intensity = (int)(0.299 * pPixel[2] + 0.587 * pPixel[1] + 0.114 * pPixel[0]);
			hist[intensity]++;
		}
	}

	// 3. Compute the Cumulative Distribution Function (CDF)
	int cdf[256] = { 0 };
	int cumulativeSum = 0;
	int cdfMin = -1;

	for (int i = 0; i < 256; i++)
	{
		cumulativeSum += hist[i];
		cdf[i] = cumulativeSum;

		// Track the first non-zero cumulative value to act as our scale baseline
		if (cdfMin == -1 && hist[i] > 0)
		{
			cdfMin = cdf[i];
		}
	}

	// 4. Generate the equalized Lookup Table (LUT) mapping array
	BYTE lut[256] = { 0 };
	if (totalPixels - cdfMin > 0)
	{
		for (int i = 0; i < 256; i++)
		{
			// Standard Equalization Formula: round( (cdf(i) - cdf_min) / (total_pixels - cdf_min) * 255 )
			double equalizedValue = ((double)(cdf[i] - cdfMin) / (totalPixels - cdfMin)) * 255.0;

			if (equalizedValue > 255.0) equalizedValue = 255.0;
			if (equalizedValue < 0.0) equalizedValue = 0.0;

			lut[i] = (BYTE)equalizedValue;
		}
	}

	// 5. Apply the Equalized mapping back to all RGB channels proportionally
	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPix);

			// Map each channel through the calculated luminance scaling LUT
			pPixel[0] = lut[pPixel[0]]; // Blue
			pPixel[1] = lut[pPixel[1]]; // Green
			pPixel[2] = lut[pPixel[2]]; // Red
		}
	}

	// 6. Force frame repaint update
	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessHistogramgraph()
{
	// TODO: Add your command handler code here
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. If the window is already open, simply bring it to the front focus
	if (m_pHistDlg != nullptr && ::IsWindow(m_pHistDlg->m_hWnd))
	{
		m_pHistDlg->SetForegroundWindow();
		return;
	}

	// 2. Allocate and instantiate the class on the heap memory space
	m_pHistDlg = new CHistogramDlg(this);
	m_pHistDlg->m_pView = this; // Bind the parent view callback hook

	// 3. Create the window non-modally from the dialog resource template
	if (m_pHistDlg->Create(IDD_DIALOG_HISTOGRAM, this))
	{
		m_pHistDlg->ShowWindow(SW_SHOW); // Pop it up live!
	}
}

void Cproject1View::OnPointprocessGammacorrection()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	// 1. Safe vector reservation
	m_pixelBackupBuffer.resize(totalBytes);

	// Get the actual raw start of the bitmap buffer allocation block
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		// If bottom-up bitmap, GetBits() points to the LAST row in memory layout
		pImgBits += pitch * (height - 1);
	}

	// 2. Perform a clean raw block copy
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CGammaDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore pristine memory on cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyLiveGamma(double gammaVal)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	// Both pointers now point explicitly to the base byte index of the memory allocation blocks
	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pDstBase += pitch * (height - 1);
	}
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// 1. Generate Fast Look-Up Table
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		double normalized = i / 255.0;
		double corrected = std::pow(normalized, gammaVal);
		lut[i] = (BYTE)(corrected * 255.0 + 0.5);
	}

	// 2. Safely cycle through indices matching the source structure exactly
	for (int y = 0; y < height; y++)
	{
		// Use positive absolute step offsets so both structures step forward identically
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // Blue
			pDstPixel[1] = lut[pSrcPixel[1]]; // Green
			pDstPixel[2] = lut[pSrcPixel[2]]; // Red
		}
	}

	// 3. Frame redraw request
	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSize(UINT nType, int cx, int cy)
{
	CScrollView::OnSize(nType, cx, cy);

	if (m_bFitToWindow && cx > 0 && cy > 0)
	{
		SetScaleToFitSize(CSize(cx, cy));
	}
}

void Cproject1View::ApplyLiveHSIPreview(int hDeg, int sSat, int iInt, CImage* pSmallImg)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || !pSmallImg || pSmallImg->IsNull()) return;

	// ── Step 1: Reset preview image from original ──────────────────────────
	int fullW = pDoc->m_imageOriginal.GetWidth();
	int fullH = pDoc->m_imageOriginal.GetHeight();
	int prevW = pSmallImg->GetWidth();
	int prevH = pSmallImg->GetHeight();

	HDC hdcSrc = pDoc->m_imageOriginal.GetDC();
	HDC hdcDest = pSmallImg->GetDC();

	// ✅ Use HALFTONE for correct downscaling of bottom-up DIBs (BMP/JPEG)
	::SetStretchBltMode(hdcDest, HALFTONE);
	::SetBrushOrgEx(hdcDest, 0, 0, NULL); // Required after HALFTONE mode

	::StretchBlt(hdcDest, 0, 0, prevW, prevH,
		hdcSrc, 0, 0, fullW, fullH, SRCCOPY);

	pDoc->m_imageOriginal.ReleaseDC();
	pSmallImg->ReleaseDC();

	// ── Step 2: Apply HSI to the small preview (same math, tiny pixel count) ─
	int   bpp = pSmallImg->GetBPP();
	BYTE* pBits = (BYTE*)pSmallImg->GetBits();
	int   pitch = pSmallImg->GetPitch();
	int   bytesPerPix = bpp / 8;

	double hueShift = hDeg / 360.0;
	double satFactor = 1.0 + (sSat / 100.0);
	double intOffset = (iInt / 100.0);

	for (int y = 0; y < prevH; y++)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < prevW; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPix);

			double B = pPixel[0] / 255.0;
			double G = pPixel[1] / 255.0;
			double R = pPixel[2] / 255.0;

			double maxC = max(R, max(G, B));
			double minC = min(R, min(G, B));
			double delta = maxC - minC;
			double I = (R + G + B) / 3.0;
			double S = (I > 0.0) ? (delta / (maxC + 0.0001)) : 0.0;
			double H = 0.0;

			if (delta > 0.0001)
			{
				if (maxC == R) H = fmod((G - B) / delta, 6.0) / 6.0;
				else if (maxC == G) H = ((B - R) / delta + 2.0) / 6.0;
				else                H = ((R - G) / delta + 4.0) / 6.0;
				if (H < 0.0) H += 1.0;
			}

			H += hueShift;
			if (H > 1.0) H -= 1.0;
			if (H < 0.0) H += 1.0;
			S = max(0.0, min(1.0, S * satFactor));
			I = max(0.0, min(1.0, I + intOffset));

			double newR, newG, newB;
			if (S == 0.0)
			{
				newR = newG = newB = I;
			}
			else
			{
				double h6 = H * 6.0;
				int    hi = (int)h6 % 6;
				double f = h6 - (int)h6;
				double p = I * (1.0 - S);
				double q = I * (1.0 - S * f);
				double t = I * (1.0 - S * (1.0 - f));
				switch (hi)
				{
				case 0: newR = I; newG = t; newB = p; break;
				case 1: newR = q; newG = I; newB = p; break;
				case 2: newR = p; newG = I; newB = t; break;
				case 3: newR = p; newG = q; newB = I; break;
				case 4: newR = t; newG = p; newB = I; break;
				default:newR = I; newG = p; newB = q; break;
				}
			}

			pPixel[0] = (BYTE)max(0.0, min(255.0, newB * 255.0));
			pPixel[1] = (BYTE)max(0.0, min(255.0, newG * 255.0));
			pPixel[2] = (BYTE)max(0.0, min(255.0, newR * 255.0));
		}
	}

	// ── Step 3: StretchBlt small result back up to full display image ──────
	HDC hdcSmall = pSmallImg->GetDC();
	HDC hdcFull = pDoc->m_image.GetDC();

	// ✅ HALFTONE handles bottom-up DIB orientation correctly for BMP/JPEG
	::SetStretchBltMode(hdcFull, HALFTONE);
	::SetBrushOrgEx(hdcFull, 0, 0, NULL);

	::StretchBlt(hdcFull, 0, 0, fullW, fullH,
		hdcSmall, 0, 0, prevW, prevH, SRCCOPY);

	pDoc->m_image.ReleaseDC();
	pSmallImg->ReleaseDC();
}

void Cproject1View::OnPointprocessSolarization()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull()) return;

	CSolarizationDlg dlg;
	dlg.m_nIntensity = 128; // Default midpoint value

	if (dlg.DoModal() == IDOK)
	{
		// User clicked OK: Apply the final selected slider value permanently
		ApplyLiveSolarization(dlg.m_nIntensity);
	}
	else
	{
		// OPTIMIZED Cancel fallback: Safe single-block copy handling both top-down and bottom-up bitmaps
		int pitch = pDoc->m_imageOriginal.GetPitch();
		int height = pDoc->m_imageOriginal.GetHeight();

		BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
		BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

		if (pitch < 0)
		{
			// Move pointers to the absolute lowest memory address for bottom-up bitmaps
			BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
			BYTE* pDstStart = pDstBits + (pitch * (height - 1));
			memcpy(pDstStart, pSrcStart, abs(pitch) * height);
		}
		else
		{
			// Standard top-down layout
			memcpy(pDstBits, pSrcBits, pitch * height);
		}

		// Redraw the view canvas back to its original clean state
		Invalidate(FALSE);
		UpdateWindow();
	}
}

void Cproject1View::ApplyLiveSolarization(int threshold)
{
	if (threshold < 1) threshold = 1;

	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;
	if (bytesPerPixel < 3) return; // Only operate if color image

	// Generate Look-Up Table (LUT)
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		if (i < threshold)
		{
			double val = (255.0 * i * (2 * threshold - i)) / (double)(threshold * threshold);
			lut[i] = (BYTE)(val > 255.0 ? 255.0 : (val < 0.0 ? 0.0 : val));
		}
		else
		{
			double val = (255.0 * (255 - i) * (255 + i - 2 * threshold)) / (double)((255 - threshold) * (255 - threshold));
			lut[i] = (BYTE)(val > 255.0 ? 255.0 : (val < 0.0 ? 0.0 : val));
		}
	}

	int nWidth = pDoc->m_imageOriginal.GetWidth();
	int nHeight = pDoc->m_imageOriginal.GetHeight();
	int nPitch = pDoc->m_imageOriginal.GetPitch();

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	// Compact row runner with register-friendly indexing
	for (int y = 0; y < nHeight; ++y)
	{
		BYTE* pSrcRow = pSrcBits + (y * nPitch);
		BYTE* pDstRow = pDstBits + (y * nPitch);

		for (int x = 0; x < nWidth; ++x)
		{
			int offset = x * bytesPerPixel;
			pDstRow[offset] = lut[pSrcRow[offset]];     // Blue
			pDstRow[offset + 1] = lut[pSrcRow[offset + 1]]; // Green
			pDstRow[offset + 2] = lut[pSrcRow[offset + 2]]; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLivePosterization(int levels)
{
	if (levels < 2) levels = 2;

	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch(); // Safe negative/positive pitch tracking
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// 1. Precalculate a mapping Look-Up Table (LUT) for quantization
	BYTE lut[256];
	int numAreas = levels - 1;
	for (int i = 0; i < 256; i++)
	{
		// Divide into discrete steps and scale back up to the 0-255 boundary
		int bucket = (int)((i * levels) / 256.0);
		double targetVal = (bucket * 255.0) / numAreas;

		if (targetVal > 255.0) targetVal = 255.0;
		if (targetVal < 0.0) targetVal = 0.0;
		lut[i] = (BYTE)targetVal;
	}

	// 2. Process image channels row-by-row safely
	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // Blue
			pDstPixel[1] = lut[pSrcPixel[1]]; // Green
			pDstPixel[2] = lut[pSrcPixel[2]]; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessPosterization()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull()) return;

	CPosterizationDlg dlg;
	dlg.m_nLevels = 8; // Default value: split image into 8 clean color bands

	if (dlg.DoModal() == IDOK)
	{
		ApplyLivePosterization(dlg.m_nLevels);
	}
	else
	{
		// Cancel fallback: Safely restore from our baseline image buffer back to m_image row-by-row
		BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
		BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
		int width = pDoc->m_imageOriginal.GetWidth();
		int height = pDoc->m_imageOriginal.GetHeight();
		int pitch = pDoc->m_imageOriginal.GetPitch();
		int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

		for (int y = 0; y < height; y++)
		{
			memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
		}

		Invalidate(FALSE);
		UpdateWindow();
	}
}
void Cproject1View::ApplyLiveBitPlane(int bitPlane)
{
	if (bitPlane < 0) bitPlane = 0;
	if (bitPlane > 7) bitPlane = 7;

	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Mask for the bit position (e.g., bit 7 = 10000000)
	BYTE mask = (1 << bitPlane);

	// Precalculate LUT for speed: 0 stays 0, non-zero becomes 255
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		lut[i] = (i & mask) ? 255 : 0;
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Apply bit mask independently to Blue, Green, and Red
			pDstPixel[0] = lut[pSrcPixel[0]]; // Blue channel bit plane
			pDstPixel[1] = lut[pSrcPixel[1]]; // Green channel bit plane
			pDstPixel[2] = lut[pSrcPixel[2]]; // Red channel bit plane
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessBitplane()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CBitPlaneDlg dlg;
	dlg.m_nBitPlane = 7; // Default to MSB (Bit 7)

	if (dlg.DoModal() == IDOK)
	{
		ApplyLiveBitPlane(dlg.m_nBitPlane);
	}
	else
	{
		// Safe restore on Cancel for both top-down and bottom-up images
		int pitch = pDoc->m_imageOriginal.GetPitch();
		int height = pDoc->m_imageOriginal.GetHeight();
		BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
		BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
		size_t totalBytes = (size_t)abs(pitch) * height;

		if (pitch < 0) {
			BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
			BYTE* pDstStart = pDstBits + (pitch * (height - 1));
			memcpy(pDstStart, pSrcStart, totalBytes);
		}
		else {
			memcpy(pDstBits, pSrcBits, totalBytes);
		}

		Invalidate(FALSE);
		UpdateWindow();
	}
}

void Cproject1View::OnPointprocessContraststretch()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull()) return;

	CContrastStretchDlg dlg;
	dlg.m_nMin = 0;   // Default baseline floor
	dlg.m_nMax = 255; // Default baseline ceiling

	if (dlg.DoModal() == IDOK)
	{
		ApplyLiveContrastStretch(dlg.m_nMin, dlg.m_nMax);
	}
	else
	{
		// Cancel: Restore original state
		BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
		BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
		int width = pDoc->m_imageOriginal.GetWidth();
		int height = pDoc->m_imageOriginal.GetHeight();
		int pitch = pDoc->m_imageOriginal.GetPitch();
		int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

		for (int y = 0; y < height; y++)
		{
			memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
		}

		Invalidate(FALSE);
		UpdateWindow();
	}
}


void Cproject1View::ApplyLiveContrastStretch(int minVal, int maxVal)
{
	if (minVal >= maxVal) maxVal = minVal + 1;

	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Build the Contrast LUT map
	BYTE lut[256];
	double range = (double)(maxVal - minVal);

	for (int i = 0; i < 256; i++)
	{
		if (i <= minVal)
		{
			lut[i] = 0;
		}
		else if (i >= maxVal)
		{
			lut[i] = 255;
		}
		else
		{
			double stretched = ((i - minVal) / range) * 255.0;
			lut[i] = (BYTE)(stretched + 0.5); // rounding
		}
	}

	// Row-by-row rendering step
	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // Blue
			pDstPixel[1] = lut[pSrcPixel[1]]; // Green
			pDstPixel[2] = lut[pSrcPixel[2]]; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessColorbalance()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull()) return;

	CColorBalanceDlg dlg;
	dlg.m_nRed = 0;
	dlg.m_nGreen = 0;
	dlg.m_nBlue = 0;

	if (dlg.DoModal() == IDOK)
	{
		ApplyLiveColorBalance(dlg.m_nRed, dlg.m_nGreen, dlg.m_nBlue);
	}
	else
	{
		// Safe single-block copy handling both top-down and bottom-up bitmaps
		int pitch = pDoc->m_imageOriginal.GetPitch();
		int height = pDoc->m_imageOriginal.GetHeight();

		BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
		BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

		if (pitch < 0)
		{
			// For bottom-up images, GetBits() points to the start of the last row.
			// We move the pointers to the absolute lowest memory address before copying.
			BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
			BYTE* pDstStart = pDstBits + (pitch * (height - 1));
			memcpy(pDstStart, pSrcStart, abs(pitch) * height);
		}
		else
		{
			// Standard top-down layout
			memcpy(pDstBits, pSrcBits, pitch * height);
		}

		Invalidate(FALSE);
		UpdateWindow();
	}
}

void Cproject1View::ApplyLiveColorBalance(int deltaR, int deltaG, int deltaB)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;
	if (bytesPerPixel < 3) return; // Only operate if color image

	// 1. Precalculate your fast LUT arrays with clamping logic
	BYTE lutR[256], lutG[256], lutB[256];
	for (int i = 0; i < 256; i++)
	{
		int valR = i + deltaR;
		int valG = i + deltaG;
		int valB = i + deltaB;

		lutR[i] = (BYTE)(valR < 0 ? 0 : (valR > 255 ? 255 : valR));
		lutG[i] = (BYTE)(valG < 0 ? 0 : (valG > 255 ? 255 : valG));
		lutB[i] = (BYTE)(valB < 0 ? 0 : (valB > 255 ? 255 : valB));
	}

	// 2. Utilize our core metrics
	int nWidth = pDoc->m_imageOriginal.GetWidth();
	int nHeight = pDoc->m_imageOriginal.GetHeight();
	int nPitch = pDoc->m_imageOriginal.GetPitch();

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	// 3. Compact row runner
	for (int y = 0; y < nHeight; ++y)
	{
		BYTE* pSrcRow = pSrcBits + (y * nPitch);
		BYTE* pDstRow = pDstBits + (y * nPitch);

		for (int x = 0; x < nWidth; ++x)
		{
			// Direct indexing eliminates extra pixel pointer arithmetic calculations 
			pDstRow[x * bytesPerPixel] = lutB[pSrcRow[x * bytesPerPixel]];
			pDstRow[x * bytesPerPixel + 1] = lutG[pSrcRow[x * bytesPerPixel + 1]];
			pDstRow[x * bytesPerPixel + 2] = lutR[pSrcRow[x * bytesPerPixel + 2]];
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingAverageblur()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Safely copy original data to destination first to handle the outer borders cleanly
	for (int y = 0; y < height; y++)
	{
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	int rowsToProcess = height;
	if (pMainFrame) pMainFrame->StartProgress(rowsToProcess);

	BeginWaitCursor();
	int lastPercent = -1;

	// Outer loops stay 1 pixel away from the absolute edges
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			// $3 \times 3$ Kernel Window
			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					sumB += pSrcPixelNeighbor[0];
					sumG += pSrcPixelNeighbor[1];
					sumR += pSrcPixelNeighbor[2];
				}
			}

			pDstPixel[0] = (BYTE)(sumB / 9);
			pDstPixel[1] = (BYTE)(sumG / 9);
			pDstPixel[2] = (BYTE)(sumR / 9);
		}
		int currentPercent = (y * 100) / height;
		if (currentPercent > lastPercent)
		{
			if (pMainFrame)
			{
				pMainFrame->UpdateProgress(y);
				pMainFrame->RefreshProgressBar();
			}
			  lastPercent = currentPercent;
		}
	}
	EndWaitCursor();
	if (pMainFrame) {
		pMainFrame->EndProgress();
	}
	Invalidate(FALSE); 
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingGaussianblur()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define the $3 \times 3$ Gaussian weight mask static array
	int gaussKernel[3][3] = {
		{ 1, 2, 1 },
		{ 2, 4, 2 },
		{ 1, 2, 1 }
	};

	for (int y = 0; y < height; y++)
	{
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int weight = gaussKernel[ky + 1][kx + 1];

					sumB += pSrcPixelNeighbor[0] * weight;
					sumG += pSrcPixelNeighbor[1] * weight;
					sumR += pSrcPixelNeighbor[2] * weight;
				}
			}

			// Divide by 16 (the total sum of our weight coefficients)
			pDstPixel[0] = (BYTE)(sumB / 16);
			pDstPixel[1] = (BYTE)(sumG / 16);
			pDstPixel[2] = (BYTE)(sumR / 16);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingLowpassfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	int lpKernel[3][3] = {
		{ 1, 1, 1 },
		{ 1, 2, 1 },
		{ 1, 1, 1 }
	};
	int divisor = 10; // Sum of all elements in the mask

	for (int y = 0; y < height; y++)
	{
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int weight = lpKernel[ky + 1][kx + 1];

					sumB += pSrcPixelNeighbor[0] * weight;
					sumG += pSrcPixelNeighbor[1] * weight;
					sumR += pSrcPixelNeighbor[2] * weight;
				}
			}

			pDstPixel[0] = (BYTE)(sumB / divisor);
			pDstPixel[1] = (BYTE)(sumG / divisor);
			pDstPixel[2] = (BYTE)(sumR / divisor);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingHighpassfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Classic sharpening/high-pass kernel mapping
	int hpKernel[3][3] = {
		{ -1, -1, -1 },
		{ -1,  9, -1 }, // Using 9 retains a crisp backdrop layer along with edges
		{ -1, -1, -1 }
	};

	for (int y = 0; y < height; y++)
	{
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int weight = hpKernel[ky + 1][kx + 1];

					sumB += pSrcPixelNeighbor[0] * weight;
					sumG += pSrcPixelNeighbor[1] * weight;
					sumR += pSrcPixelNeighbor[2] * weight;
				}
			}

			// Safe clamping logic to prevent underflow or overflow
			pDstPixel[0] = (BYTE)(sumB < 0 ? 0 : (sumB > 255 ? 255 : sumB));
			pDstPixel[1] = (BYTE)(sumG < 0 ? 0 : (sumG > 255 ? 255 : sumG));
			pDstPixel[2] = (BYTE)(sumR < 0 ? 0 : (sumR > 255 ? 255 : sumR));
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingMedianfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Fill background border safely first
	for (int y = 0; y < height; y++)
	{
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	// Process interior window
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Arrays to store 9 neighborhood channel intensities
			int arrB[9], arrG[9], arrR[9];
			int count = 0;

			// Collect values
			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					arrB[count] = pSrcPixelNeighbor[0];
					arrG[count] = pSrcPixelNeighbor[1];
					arrR[count] = pSrcPixelNeighbor[2];
					count++;
				}
			}

			// Simple Insertion Sort for Blue
			for (int i = 1; i < 9; i++) {
				int key = arrB[i]; int j = i - 1;
				while (j >= 0 && arrB[j] > key) { arrB[j + 1] = arrB[j]; j--; }
				arrB[j + 1] = key;
			}
			// Simple Insertion Sort for Green
			for (int i = 1; i < 9; i++) {
				int key = arrG[i]; int j = i - 1;
				while (j >= 0 && arrG[j] > key) { arrG[j + 1] = arrG[j]; j--; }
				arrG[j + 1] = key;
			}
			// Simple Insertion Sort for Red
			for (int i = 1; i < 9; i++) {
				int key = arrR[i]; int j = i - 1;
				while (j >= 0 && arrR[j] > key) { arrR[j + 1] = arrR[j]; j--; }
				arrR[j + 1] = key;
			}

			// Pick index 4 (the 5th element is the true middle median value)
			pDstPixel[0] = (BYTE)arrB[4];
			pDstPixel[1] = (BYTE)arrG[4];
			pDstPixel[2] = (BYTE)arrR[4];
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingSobeledgedetection()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define Sobel Horizontal (Gx) and Vertical (Gy) masks
	int Gx[3][3] = {
		{ -1, 0, 1 },
		{ -2, 0, 2 },
		{ -1, 0, 1 }
	};
	int Gy[3][3] = {
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 }
	};

	// Initialize the destination image with pure black borders safely
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Process interior canvas pixels
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			int sumX_B = 0, sumY_B = 0;
			int sumX_G = 0, sumY_G = 0;
			int sumX_R = 0, sumY_R = 0;

			// Apply masks over the neighborhood window
			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					int wx = Gx[ky + 1][kx + 1];
					int wy = Gy[ky + 1][kx + 1];

					sumX_B += pSrcPixelNeighbor[0] * wx;
					sumY_B += pSrcPixelNeighbor[0] * wy;

					sumX_G += pSrcPixelNeighbor[1] * wx;
					sumY_G += pSrcPixelNeighbor[1] * wy;

					sumX_R += pSrcPixelNeighbor[2] * wx;
					sumY_R += pSrcPixelNeighbor[2] * wy;
				}
			}

			// Compute total edge magnitude approximate mapping
			int magB = abs(sumX_B) + abs(sumY_B);
			int magG = abs(sumX_G) + abs(sumY_G);
			int magR = abs(sumX_R) + abs(sumY_R);

			// Clamp results to maximum limits safely
			pDstPixel[0] = (BYTE)(magB > 255 ? 255 : magB); // Blue Edge
			pDstPixel[1] = (BYTE)(magG > 255 ? 255 : magG); // Green Edge
			pDstPixel[2] = (BYTE)(magR > 255 ? 255 : magR); // Red Edge
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingKrishedgedetection()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define the 8 Kirsch direction kernels
	int K[8][3][3] = {
		{ { 5,  5,  5}, {-3,  0, -3}, {-3, -3, -3} }, // N
		{ { 5,  5, -3}, { 5,  0, -3}, {-3, -3, -3} }, // NW
		{ { 5, -3, -3}, { 5,  0, -3}, { 5, -3, -3} }, // W
		{ {-3, -3, -3}, { 5,  0, -3}, { 5,  5, -3} }, // SW
		{ {-3, -3, -3}, {-3,  0, -3}, { 5,  5,  5} }, // S
		{ {-3, -3, -3}, {-3,  0,  5}, {-3,  5,  5} }, // SE
		{ {-3, -3,  5}, {-3,  0,  5}, {-3, -3,  5} }, // E
		{ {-3,  5,  5}, {-3,  0,  5}, {-3, -3, -3} }  // NE
	};

	// Initialize edge viewport boundaries to black
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Process internal spatial canvas pixels
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			int maxB = 0, maxG = 0, maxR = 0;

			// Evaluate all 8 directional filters
			for (int d = 0; d < 8; d++)
			{
				int sumB = 0, sumG = 0, sumR = 0;

				for (int ky = -1; ky <= 1; ky++)
				{
					BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
					for (int kx = -1; kx <= 1; kx++)
					{
						BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
						int weight = K[d][ky + 1][kx + 1];

						sumB += pSrcPixelNeighbor[0] * weight;
						sumG += pSrcPixelNeighbor[1] * weight;
						sumR += pSrcPixelNeighbor[2] * weight;
					}
				}

				// Check if this direction yielded a stronger structural change
				if (abs(sumB) > maxB) maxB = abs(sumB);
				if (abs(sumG) > maxG) maxG = abs(sumG);
				if (abs(sumR) > maxR) maxR = abs(sumR);
			}

			// Write out clamped structural edge magnitudes
			pDstPixel[0] = (BYTE)(maxB > 255 ? 255 : maxB);
			pDstPixel[1] = (BYTE)(maxG > 255 ? 255 : maxG);
			pDstPixel[2] = (BYTE)(maxR > 255 ? 255 : maxR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnNeighborhoodprocessingPrewittedgedetection()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define Prewitt Horizontal (Gx) and Vertical (Gy) masks
	int Gx[3][3] = {
		{ -1, 0, 1 },
		{ -1, 0, 1 },
		{ -1, 0, 1 }
	};
	int Gy[3][3] = {
		{ -1, -1, -1 },
		{  0,  0,  0 },
		{  1,  1,  1 }
	};

	// Clear boundaries to black
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Loop through internal pixels
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			int sumX_B = 0, sumY_B = 0;
			int sumX_G = 0, sumY_G = 0;
			int sumX_R = 0, sumY_R = 0;

			// Apply $3 \times 3$ window matrix
			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					int wx = Gx[ky + 1][kx + 1];
					int wy = Gy[ky + 1][kx + 1];

					sumX_B += pSrcPixelNeighbor[0] * wx;
					sumY_B += pSrcPixelNeighbor[0] * wy;

					sumX_G += pSrcPixelNeighbor[1] * wx;
					sumY_G += pSrcPixelNeighbor[1] * wy;

					sumX_R += pSrcPixelNeighbor[2] * wx;
					sumY_R += pSrcPixelNeighbor[2] * wy;
				}
			}

			// Total gradient magnitude calculation
			int magB = abs(sumX_B) + abs(sumY_B);
			int magG = abs(sumX_G) + abs(sumY_G);
			int magR = abs(sumX_R) + abs(sumY_R);

			// Clamp out to bounds
			pDstPixel[0] = (BYTE)(magB > 255 ? 255 : magB);
			pDstPixel[1] = (BYTE)(magG > 255 ? 255 : magG);
			pDstPixel[2] = (BYTE)(magR > 255 ? 255 : magR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringScharredgedetection()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define Scharr Horizontal (Gx) and Vertical (Gy) optimized kernels
	int Gx[3][3] = {
		{  -3, 0,  3 },
		{ -10, 0, 10 },
		{  -3, 0,  3 }
	};
	int Gy[3][3] = {
		{  -3, -10, -3 },
		{   0,   0,  0 },
		{   3,  10,  3 }
	};

	// Clear borders to black safely
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Process interior pixels
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			int sumX_B = 0, sumY_B = 0;
			int sumX_G = 0, sumY_G = 0;
			int sumX_R = 0, sumY_R = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					int wx = Gx[ky + 1][kx + 1];
					int wy = Gy[ky + 1][kx + 1];

					sumX_B += pSrcPixelNeighbor[0] * wx;
					sumY_B += pSrcPixelNeighbor[0] * wy;

					sumX_G += pSrcPixelNeighbor[1] * wx;
					sumY_G += pSrcPixelNeighbor[1] * wy;

					sumX_R += pSrcPixelNeighbor[2] * wx;
					sumY_R += pSrcPixelNeighbor[2] * wy;
				}
			}

			int magB = abs(sumX_B) + abs(sumY_B);
			int magG = abs(sumX_G) + abs(sumY_G);
			int magR = abs(sumX_R) + abs(sumY_R);

			pDstPixel[0] = (BYTE)(magB > 255 ? 255 : magB);
			pDstPixel[1] = (BYTE)(magG > 255 ? 255 : magG);
			pDstPixel[2] = (BYTE)(magR > 255 ? 255 : magR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringLaplacianofgaussian()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define the 5x5 Laplacian of Gaussian discrete mask matrix
	int logKernel[5][5] = {
		{  0,  0, -1,  0,  0 },
		{  0, -1, -2, -1,  0 },
		{ -1, -2, 16, -2, -1 },
		{  0, -1, -2, -1,  0 },
		{  0,  0, -1,  0,  0 }
	};

	// Initialize the whole destination image buffer to black
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Outer loops stay 2 pixels away from borders due to the 5x5 mask size
	for (int y = 2; y < height - 2; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 2; x < width - 2; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			int sumB = 0, sumG = 0, sumR = 0;

			// 5x5 Neighborhood Loop matrix traversal
			for (int ky = -2; ky <= 2; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -2; kx <= 2; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int weight = logKernel[ky + 2][kx + 2];

					sumB += pSrcPixelNeighbor[0] * weight;
					sumG += pSrcPixelNeighbor[1] * weight;
					sumR += pSrcPixelNeighbor[2] * weight;
				}
			}

			// Since Laplacian values can be negative, take the absolute value and clamp
			int absB = abs(sumB);
			int absG = abs(sumG);
			int absR = abs(sumR);

			pDstPixel[0] = (BYTE)(absB > 255 ? 255 : absB);
			pDstPixel[1] = (BYTE)(absG > 255 ? 255 : absG);
			pDstPixel[2] = (BYTE)(absR > 255 ? 255 : absR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringCannyedgedetector32810()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Allocate dynamic buffers for intermediate tracking stages
	int totalPixels = width * height;
	int* pGray = new int[totalPixels];
	int* pBlurred = new int[totalPixels];
	int* pMag = new int[totalPixels];
	int* pAngle = new int[totalPixels];

	// 1. Convert source image to Grayscale intensity
	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pSrcRow + (x * bytesPerPixel);
			pGray[y * width + x] = (int)(0.299 * pPixel[2] + 0.587 * pPixel[1] + 0.114 * pPixel[0]);
		}
	}

	// 2. Stage 1: 3x3 Gaussian Smooth Filter to suppress sensor noise
	int gauss[3][3] = { {1,2,1}, {2,4,2}, {1,2,1} };
	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int sum = 0;
			for (int ky = -1; ky <= 1; ky++) {
				for (int kx = -1; kx <= 1; kx++) {
					sum += pGray[(y + ky) * width + (x + kx)] * gauss[ky + 1][kx + 1];
				}
			}
			pBlurred[y * width + x] = sum / 16;
		}
	}

	// 3. Stage 2: Sobel Gradient Direction and Magnitude Extraction
	int Gx[3][3] = { {-1,0,1}, {-2,0,2}, {-1,0,1} };
	int Gy[3][3] = { {-1,-2,-1}, {0,0,0}, {1,2,1} };

	memset(pMag, 0, totalPixels * sizeof(int));
	memset(pAngle, 0, totalPixels * sizeof(int));

	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int sumX = 0, sumY = 0;
			for (int ky = -1; ky <= 1; ky++) {
				for (int kx = -1; kx <= 1; kx++) {
					int val = pBlurred[(y + ky) * width + (x + kx)];
					sumX += val * Gx[ky + 1][kx + 1];
					sumY += val * Gy[ky + 1][kx + 1];
				}
			}
			pMag[y * width + x] = abs(sumX) + abs(sumY);

			// Approximate the sector angle into 4 generic orientations
			double angle = atan2(sumY, sumX) * 180.0 / 3.14159265;
			if (angle < 0) angle += 180.0;

			if ((angle >= 0 && angle < 22.5) || (angle >= 157.5 && angle <= 180)) pAngle[y * width + x] = 0;     // Horizontal
			else if (angle >= 22.5 && angle < 67.5)  pAngle[y * width + x] = 45;    // Diagonal up-right
			else if (angle >= 67.5 && angle < 112.5) pAngle[y * width + x] = 90;    // Vertical
			else if (angle >= 112.5 && angle < 157.5) pAngle[y * width + x] = 135;  // Diagonal up-left
		}
	}

	// Initialize destination workspace canvas to black
	for (int y = 0; y < height; y++) {
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Define Hysteresis thresholds
	int highThreshold = 50;
	int lowThreshold = 20;

	// 4. Stage 3 & 4: Non-Maximum Suppression (Thinning) and Hysteresis Thresholding
	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			int idx = y * width + x;
			int mag = pMag[idx];

			if (mag < lowThreshold) continue; // Discard weak values immediately

			int n1 = 0, n2 = 0;
			int dir = pAngle[idx];

			// Evaluate neighbors based on gradient orientation direction
			if (dir == 0) {
				n1 = pMag[y * width + (x + 1)];
				n2 = pMag[y * width + (x - 1)];
			}
			else if (dir == 45) {
				n1 = pMag[(y - 1) * width + (x + 1)];
				n2 = pMag[(y + 1) * width + (x - 1)];
			}
			else if (dir == 90) {
				n1 = pMag[(y - 1) * width + x];
				n2 = pMag[(y + 1) * width + x];
			}
			else if (dir == 135) {
				n1 = pMag[(y - 1) * width + (x - 1)];
				n2 = pMag[(y + 1) * width + (x + 1)];
			}

			// Suppress non-maximum pixels to 0 if they aren't local peaks
			if (mag >= n1 && mag >= n2)
			{
				if (mag >= highThreshold)
				{
					// Locked in strong structural edge pixel
					BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
					pDstPixel[0] = 255; pDstPixel[1] = 255; pDstPixel[2] = 255;
				}
				else
				{
					// Intermediary candidate check: check connection to local strong edges
					bool connected = false;
					for (int ny = -1; ny <= 1 && !connected; ny++) {
						for (int nx = -1; nx <= 1; nx++) {
							if (pMag[(y + ny) * width + (x + nx)] >= highThreshold) {
								connected = true;
								break;
							}
						}
					}
					if (connected) {
						BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
						pDstPixel[0] = 255; pDstPixel[1] = 255; pDstPixel[2] = 255;
					}
				}
			}
		}
	}

	// Clean up heap buffers memory allocations safely
	delete[] pGray;
	delete[] pBlurred;
	delete[] pMag;
	delete[] pAngle;

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringLaplacianfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Omnidirectional $3\times3$ Laplacian kernel
	int lapKernel[3][3] = {
		{ 1,  1, 1 },
		{ 1, -8, 1 },
		{ 1,  1, 1 }
	};

	// Clear boundaries to black
	for (int y = 0; y < height; y++) {
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int weight = lapKernel[ky + 1][kx + 1];

					sumB += pSrcPixelNeighbor[0] * weight;
					sumG += pSrcPixelNeighbor[1] * weight;
					sumR += pSrcPixelNeighbor[2] * weight;
				}
			}

			// Take absolute value to show both positive and negative transitions as white lines
			int absB = abs(sumB);
			int absG = abs(sumG);
			int absR = abs(sumR);

			pDstPixel[0] = (BYTE)(absB > 255 ? 255 : absB);
			pDstPixel[1] = (BYTE)(absG > 255 ? 255 : absG);
			pDstPixel[2] = (BYTE)(absR > 255 ? 255 : absR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringFrei()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Define Frei-Chen Orthogonal Base Mask Multipliers
	double sqrt2 = sqrt(2.0);
	double M1[3][3] = {
		{ 1.0,  sqrt2,  1.0 },
		{ 0.0,    0.0,  0.0 },
		{-1.0, -sqrt2, -1.0 }
	};
	double M2[3][3] = {
		{ 1.0,  0.0, -1.0 },
		{ sqrt2, 0.0, -sqrt2 },
		{ 1.0,  0.0, -1.0 }
	};

	// Factor constant: 2 * sqrt(2)
	double denom = 2.0 * sqrt2;

	for (int y = 0; y < height; y++) {
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			double sumX_B = 0, sumY_B = 0;
			double sumX_G = 0, sumY_G = 0;
			double sumX_R = 0, sumY_R = 0;

			for (int ky = -1; ky <= 1; ky++)
			{
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++)
				{
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);

					double w1 = M1[ky + 1][kx + 1];
					double w2 = M2[ky + 1][kx + 1];

					sumX_B += pSrcPixelNeighbor[0] * w1;
					sumY_B += pSrcPixelNeighbor[0] * w2;

					sumX_G += pSrcPixelNeighbor[1] * w1;
					sumY_G += pSrcPixelNeighbor[1] * w2;

					sumX_R += pSrcPixelNeighbor[2] * w1;
					sumY_R += pSrcPixelNeighbor[2] * w2;
				}
			}

			// Final projection vector length magnitude division
			int magB = (int)(sqrt((sumX_B * sumX_B) + (sumY_B * sumY_B)) / denom);
			int magG = (int)(sqrt((sumX_G * sumX_G) + (sumY_G * sumY_G)) / denom);
			int magR = (int)(sqrt((sumX_R * sumX_R) + (sumY_R * sumY_R)) / denom);

			pDstPixel[0] = (BYTE)(magB > 255 ? 255 : magB);
			pDstPixel[1] = (BYTE)(magG > 255 ? 255 : magG);
			pDstPixel[2] = (BYTE)(magR > 255 ? 255 : magR);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringRobertscrossoperator()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Clear the destination buffer to pure black first
	for (int y = 0; y < height; y++)
	{
		memset(pDstBits + (y * pitch), 0, width * bytesPerPixel);
	}

	// Process up to width-1 and height-1 for the 2x2 window matrix
	for (int y = 0; y < height - 1; y++)
	{
		BYTE* pSrcRowCurrent = pSrcBits + (y * pitch);
		BYTE* pSrcRowNext = pSrcBits + ((y + 1) * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 0; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Fetch the 2x2 neighborhood pixel pointers
			BYTE* pP00 = pSrcRowCurrent + (x * bytesPerPixel);       // Current Pixel (x, y)
			BYTE* pP11 = pSrcRowNext + ((x + 1) * bytesPerPixel); // Diagonal Right Down (x+1, y+1)
			BYTE* pP10 = pSrcRowNext + (x * bytesPerPixel);       // Directly Down (x, y+1)
			BYTE* pP01 = pSrcRowCurrent + ((x + 1) * bytesPerPixel); // Directly Right (x+1, y)

			// Process Blue, Green, and Red channels
			for (int c = 0; c < 3; c++)
			{
				// Cross gradient calculation math
				int gx = pP00[c] - pP11[c];
				int gy = pP01[c] - pP10[c];

				int mag = abs(gx) + abs(gy);

				// Clamp and assign directly
				pDstPixel[c] = (BYTE)(mag > 255 ? 255 : mag);
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringDifferenceofgaussians()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Use absolute pitch value to ensure safe buffer allocation sizing
	int absPitch = abs(pitch);
	int totalBytes = height * absPitch;

	//BYTE* pWideBlurBits = new(std::nothrow) BYTE[totalBytes];
	BYTE* pWideBlurBits = new BYTE[totalBytes];
	if (!pWideBlurBits) return; // Fail-safe check

	// Pre-populate with the original image data to handle borders cleanly
	for (int y = 0; y < height; y++)
	{
		memcpy(pWideBlurBits + (y * absPitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	// 1. STAGE 1: Compute the Tighter Blur (3x3 Gaussian) directly into destination image
	int g3[3][3] = {
		{ 1, 2, 1 },
		{ 2, 4, 2 },
		{ 1, 2, 1 }
	};

	for (int y = 0; y < height; y++) {
		memcpy(pDstBits + (y * pitch), pSrcBits + (y * pitch), width * bytesPerPixel);
	}

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);
		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++) {
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++) {
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int w = g3[ky + 1][kx + 1];
					sumB += pSrcPixelNeighbor[0] * w;
					sumG += pSrcPixelNeighbor[1] * w;
					sumR += pSrcPixelNeighbor[2] * w;
				}
			}
			pDstPixel[0] = (BYTE)(sumB / 16);
			pDstPixel[1] = (BYTE)(sumG / 16);
			pDstPixel[2] = (BYTE)(sumR / 16);
		}
	}

	// 2. STAGE 2: Compute the Wider Blur (5x5 Gaussian) into our safe heap buffer
	int g5[5][5] = {
		{ 1,  4,  7,  4, 1 },
		{ 4, 16, 26, 16, 4 },
		{ 7, 26, 41, 26, 7 },
		{ 4, 16, 26, 16, 4 },
		{ 1,  4,  7,  4, 1 }
	};
	int g5Sum = 273;

	for (int y = 2; y < height - 2; y++)
	{
		BYTE* pWideRow = pWideBlurBits + (y * absPitch);
		for (int x = 2; x < width - 2; x++)
		{
			BYTE* pWidePixel = pWideRow + (x * bytesPerPixel);
			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -2; ky <= 2; ky++) {
				BYTE* pSrcRowNeighbor = pSrcBits + ((y + ky) * pitch);
				for (int kx = -2; kx <= 2; kx++) {
					BYTE* pSrcPixelNeighbor = pSrcRowNeighbor + ((x + kx) * bytesPerPixel);
					int w = g5[ky + 2][kx + 2];
					sumB += pSrcPixelNeighbor[0] * w;
					sumG += pSrcPixelNeighbor[1] * w;
					sumR += pSrcPixelNeighbor[2] * w;
				}
			}
			pWidePixel[0] = (BYTE)(sumB / g5Sum);
			pWidePixel[1] = (BYTE)(sumG / g5Sum);
			pWidePixel[2] = (BYTE)(sumR / g5Sum);
		}
	}

	// 3. STAGE 3: Absolute subtraction difference mapping
	for (int y = 2; y < height - 2; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);
		BYTE* pWideRow = pWideBlurBits + (y * absPitch);

		for (int x = 2; x < width - 2; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);
			BYTE* pWidePixel = pWideRow + (x * bytesPerPixel);

			for (int c = 0; c < 3; c++)
			{
				int diff = abs(pDstPixel[c] - pWidePixel[c]);
				diff *= 4; // Contrast boost mapping amplification

				pDstPixel[c] = (BYTE)(diff > 255 ? 255 : diff);
			}
		}
	}

	delete[] pWideBlurBits;

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringMarr()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bpp = pDoc->m_imageOriginal.GetBPP();
	int bytesPerPix = bpp / 8;

	// ── Step 1: Convert to Grayscale ──────────────────────────────────────
	std::vector<double> gray(width * height);
	for (int y = 0; y < height; y++) {
		BYTE* row = pSrcBits + y * pitch;
		for (int x = 0; x < width; x++) {
			BYTE* px = row + x * bytesPerPix;
			gray[y * width + x] = 0.299 * px[2] + 0.587 * px[1] + 0.114 * px[0];
		}
	}

	// ── Step 2: Apply Normalized 7x7 LoG kernel ───────────────────────────
	double log7[7][7] = {
		{  0,  0, -1, -1, -1,  0,  0 },
		{  0, -1, -3, -3, -3, -1,  0 },
		{ -1, -3,  0,  7,  0, -3, -1 },
		{ -1, -3,  7, 24,  7, -3, -1 },
		{ -1, -3,  0,  7,  0, -3, -1 },
		{  0, -1, -3, -3, -3, -1,  0 },
		{  0,  0, -1, -1, -1,  0,  0 }
	};

	// Normalize the kernel dynamically (Sum of positive components = 52.0)
	for (int ky = 0; ky < 7; ky++) {
		for (int kx = 0; kx < 7; kx++) {
			log7[ky][kx] /= 52.0;
		}
	}

	std::vector<double> logResult(width * height, 0.0);

	// Process internal elements with full 7x7 reach (-3 to 3)
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			double sum = 0.0;
			for (int ky = -3; ky <= 3; ky++) {
				int ny = min(max(y + ky, 0), height - 1); // Clamp boundary rows
				for (int kx = -3; kx <= 3; kx++) {
					int nx = min(max(x + kx, 0), width - 1);  // Clamp boundary cols
					sum += gray[ny * width + nx] * log7[ky + 3][kx + 3];
				}
			}
			logResult[y * width + x] = sum;
		}
	}

	// ── Step 3: Precise Zero-Crossing Filter ──────────────────────────────
	// High threshold to suppress grass texture and fine hair details
	double threshold = 12.0;

	for (int y = 0; y < height; y++) {
		BYTE* pDstRow = pDstBits + y * pitch;
		for (int x = 0; x < width; x++) {
			BYTE* pDst = pDstRow + x * bytesPerPix;

			// Handle boundary pixels cleanly (force background)
			if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
				pDst[0] = pDst[1] = pDst[2] = 0;
				continue;
			}

			// Fetch 4 key directional neighbors
			double left = logResult[y * width + (x - 1)];
			double right = logResult[y * width + (x + 1)];
			double top = logResult[(y - 1) * width + x];
			double bottom = logResult[(y + 1) * width + x];

			bool isEdge = false;

			// Check opposite pairs for valid zero crossing signs and distance magnitude
			if ((left * right < 0) && (abs(left - right) > threshold)) isEdge = true;
			else if ((top * bottom < 0) && (abs(top - bottom) > threshold)) isEdge = true;

			if (isEdge) {
				pDst[0] = pDst[1] = pDst[2] = 255; // Crisp White Edge
			}
			else {
				pDst[0] = pDst[1] = pDst[2] = 0;   // Clean Black Background
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringKayyalioperator()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPix = pDoc->m_imageOriginal.GetBPP() / 8;

	// Kayyali diagonal masks
	// NE/SW diagonal
	int kNESW[3][3] = {
		{  6,  0, -6 },
		{  0,  0,  0 },
		{ -6,  0,  6 }
	};
	// NW/SE diagonal
	int kNWSE[3][3] = {
		{ -6,  0,  6 },
		{  0,  0,  0 },
		{  6,  0, -6 }
	};

	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch, width * bytesPerPix);

	for (int y = 1; y < height - 1; y++) {
		BYTE* pDstRow = pDstBits + y * pitch;
		for (int x = 1; x < width - 1; x++) {
			BYTE* pDst = pDstRow + x * bytesPerPix;

			int nesw_B = 0, nesw_G = 0, nesw_R = 0;
			int nwse_B = 0, nwse_G = 0, nwse_R = 0;

			for (int ky = -1; ky <= 1; ky++) {
				BYTE* pSrcRow = pSrcBits + (y + ky) * pitch;
				for (int kx = -1; kx <= 1; kx++) {
					BYTE* pSrc = pSrcRow + (x + kx) * bytesPerPix;
					int wNE = kNESW[ky + 1][kx + 1];
					int wNW = kNWSE[ky + 1][kx + 1];
					nesw_B += pSrc[0] * wNE; nesw_G += pSrc[1] * wNE; nesw_R += pSrc[2] * wNE;
					nwse_B += pSrc[0] * wNW; nwse_G += pSrc[1] * wNW; nwse_R += pSrc[2] * wNW;
				}
			}

			// Gradient magnitude = max of both diagonal responses
			auto clamp = [](int v) { return (BYTE)(v > 255 ? 255 : (v < 0 ? 0 : v)); };

			int magB = (int)sqrt((double)(nesw_B * nesw_B + nwse_B * nwse_B));
			int magG = (int)sqrt((double)(nesw_G * nesw_G + nwse_G * nwse_G));
			int magR = (int)sqrt((double)(nesw_R * nesw_R + nwse_R * nwse_R));

			pDst[0] = clamp(magB);
			pDst[1] = clamp(magG);
			pDst[2] = clamp(magR);
		}
	}

	Invalidate(FALSE); UpdateWindow();
}


void Cproject1View::OnSpatialdomainfilteringRobinsoncompassoperator()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPix = pDoc->m_imageOriginal.GetBPP() / 8;

	// 8 Robinson compass direction masks (N, NE, E, SE, S, SW, W, NW)
	int masks[8][3][3] = {
		// N
		{{ 1,  2,  1}, { 0,  0,  0}, {-1, -2, -1}},
		// NE
		{{ 0,  1,  2}, {-1,  0,  1}, {-2, -1,  0}},
		// E
		{{-1,  0,  1}, {-2,  0,  2}, {-1,  0,  1}},
		// SE
		{{-2, -1,  0}, {-1,  0,  1}, { 0,  1,  2}},
		// S
		{{-1, -2, -1}, { 0,  0,  0}, { 1,  2,  1}},
		// SW
		{{ 0, -1, -2}, { 1,  0, -1}, { 2,  1,  0}},
		// W
		{{ 1,  0, -1}, { 2,  0, -2}, { 1,  0, -1}},
		// NW
		{{ 2,  1,  0}, { 1,  0, -1}, { 0, -1, -2}}
	};

	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch, width * bytesPerPix);

	for (int y = 1; y < height - 1; y++) {
		BYTE* pDstRow = pDstBits + y * pitch;
		for (int x = 1; x < width - 1; x++) {
			BYTE* pDst = pDstRow + x * bytesPerPix;

			int maxB = 0, maxG = 0, maxR = 0;

			// Take the maximum response across all 8 compass directions
			for (int d = 0; d < 8; d++) {
				int sB = 0, sG = 0, sR = 0;
				for (int ky = -1; ky <= 1; ky++) {
					BYTE* pSrcRow = pSrcBits + (y + ky) * pitch;
					for (int kx = -1; kx <= 1; kx++) {
						BYTE* pSrc = pSrcRow + (x + kx) * bytesPerPix;
						int w = masks[d][ky + 1][kx + 1];
						sB += pSrc[0] * w;
						sG += pSrc[1] * w;
						sR += pSrc[2] * w;
					}
				}
				// Use absolute value of response
				if (abs(sB) > maxB) maxB = abs(sB);
				if (abs(sG) > maxG) maxG = abs(sG);
				if (abs(sR) > maxR) maxR = abs(sR);
			}

			pDst[0] = (BYTE)(maxB > 255 ? 255 : maxB);
			pDst[1] = (BYTE)(maxG > 255 ? 255 : maxG);
			pDst[2] = (BYTE)(maxR > 255 ? 255 : maxR);
		}
	}

	Invalidate(FALSE); UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringNevatia()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPix = pDoc->m_imageOriginal.GetBPP() / 8;

	// 6 Nevatia-Babu 5x5 masks (0°, 30°, 60°, 90°, 120°, 150°)
	int masks[6][5][5] = {
		// 0° (horizontal)
		{{ 100, 100, 100, 100, 100},
		 { 100, 100, 100, 100, 100},
		 {   0,   0,   0,   0,   0},
		 {-100,-100,-100,-100,-100},
		 {-100,-100,-100,-100,-100}},
		 // 30°
		 {{ 100, 100, 100, 100, 100},
		  { 100, 100, 100,  78, -32},
		  { 100,  92,   0, -92,-100},
		  {  32, -78,-100,-100,-100},
		  {-100,-100,-100,-100,-100}},
		  // 60°
		  {{ 100, 100, 100,  32,-100},
		   { 100, 100,  92, -78,-100},
		   { 100, 100,   0,-100,-100},
		   { 100,  78, -92,-100,-100},
		   { 100, -32,-100,-100,-100}},
		   // 90° (vertical)
		   {{ 100, 100,   0,-100,-100},
			{ 100, 100,   0,-100,-100},
			{ 100, 100,   0,-100,-100},
			{ 100, 100,   0,-100,-100},
			{ 100, 100,   0,-100,-100}},
			// 120°
			{{-100,  32, 100, 100, 100},
			 {-100, -78,  92, 100, 100},
			 {-100,-100,   0, 100, 100},
			 {-100,-100, -92,  78, 100},
			 {-100,-100,-100, -32, 100}},
			 // 150°
			 {{-100,-100,-100,-100,-100},
			  {  32, -78,-100,-100,-100},
			  { 100,  92,   0, -92,-100},
			  { 100, 100, 100,  78, -32},
			  { 100, 100, 100, 100, 100}}
	};

	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch, width * bytesPerPix);

	for (int y = 2; y < height - 2; y++) {
		BYTE* pDstRow = pDstBits + y * pitch;
		for (int x = 2; x < width - 2; x++) {
			BYTE* pDst = pDstRow + x * bytesPerPix;

			int maxB = 0, maxG = 0, maxR = 0;

			for (int d = 0; d < 6; d++) {
				int sB = 0, sG = 0, sR = 0;
				for (int ky = -2; ky <= 2; ky++) {
					BYTE* pSrcRow = pSrcBits + (y + ky) * pitch;
					for (int kx = -2; kx <= 2; kx++) {
						BYTE* pSrc = pSrcRow + (x + kx) * bytesPerPix;
						int w = masks[d][ky + 2][kx + 2];
						sB += pSrc[0] * w;
						sG += pSrc[1] * w;
						sR += pSrc[2] * w;
					}
				}
				if (abs(sB) > maxB) maxB = abs(sB);
				if (abs(sG) > maxG) maxG = abs(sG);
				if (abs(sR) > maxR) maxR = abs(sR);
			}

			// Scale down (mask weights sum to ~500)
			maxB /= 500; maxG /= 500; maxR /= 500;

			pDst[0] = (BYTE)(maxB > 255 ? 255 : maxB);
			pDst[1] = (BYTE)(maxG > 255 ? 255 : maxG);
			pDst[2] = (BYTE)(maxR > 255 ? 255 : maxR);
		}
	}

	Invalidate(FALSE); UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringDerichefilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	int totalPixels = width * height;

	float* pGray = new float[totalPixels];
	float* pGx = new float[totalPixels];
	float* pGy = new float[totalPixels];
	float* pTemp = new float[totalPixels]; // Intermediate staging buffer

	// 1. Convert to Grayscale
	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pSrcRow + (x * bytesPerPixel);
			pGray[y * width + x] = (float)(0.299 * pPixel[2] + 0.587 * pPixel[1] + 0.114 * pPixel[0]);
		}
	}

	// 2. Set up Filter Parameters
	float alpha = 1.5f;
	float e_alpha = exp(-alpha);

	float b1 = -2.0f * e_alpha;
	float b2 = e_alpha * e_alpha;

	// Derivative Coefficients
	float k_dev = -((1.0f - e_alpha) * (1.0f - e_alpha)) / (1.0f + 2.0f * alpha * e_alpha - e_alpha * e_alpha);
	float da1 = k_dev * e_alpha;
	float da2 = -da1;

	// Smoothing Coefficients
	float k_smooth = ((1.0f - e_alpha) * (1.0f - e_alpha)) / (1.0f + 2.0f * alpha * e_alpha - e_alpha * e_alpha);
	float sa0 = k_smooth;
	float sa1 = k_smooth * (alpha - 1.0f) * e_alpha;
	float sa2 = k_smooth * (alpha + 1.0f) * e_alpha;
	float sa3 = -k_smooth * e_alpha * e_alpha;

	float* y1 = new float[max(width, height)];
	float* y2 = new float[max(width, height)];

	// ==========================================
	// 3. COMPUTE HORIZONTAL DERIVATIVE (Gx)
	// Step A: Smooth Vertically (Columns)
	// ==========================================
	for (int x = 0; x < width; x++)
	{
		y1[0] = sa0 * pGray[x];
		y1[1] = sa0 * pGray[width + x] + sa1 * pGray[x] - b1 * y1[0];
		for (int y = 2; y < height; y++) {
			y1[y] = sa0 * pGray[y * width + x] + sa1 * pGray[(y - 1) * width + x] - b1 * y1[y - 1] - b2 * y1[y - 2];
		}

		y2[height - 1] = 0;
		y2[height - 2] = sa2 * pGray[(height - 1) * width + x];
		for (int y = height - 3; y >= 0; y--) {
			y2[y] = sa2 * pGray[(y + 1) * width + x] + sa3 * pGray[(y + 2) * width + x] - b1 * y2[y + 1] - b2 * y2[y + 2];
		}

		for (int y = 0; y < height; y++) {
			pTemp[y * width + x] = y1[y] + y2[y];
		}
	}

	// Step B: Differentiate Horizontally (Rows) on the smoothed pTemp
	for (int y = 0; y < height; y++)
	{
		int rowOffset = y * width;

		y1[0] = 0;
		y1[1] = da1 * pTemp[rowOffset];
		for (int x = 2; x < width; x++) {
			y1[x] = da1 * pTemp[rowOffset + x - 1] - b1 * y1[x - 1] - b2 * y1[x - 2];
		}

		y2[width - 1] = 0;
		y2[width - 2] = da2 * pTemp[rowOffset + width - 1];
		for (int x = width - 3; x >= 0; x--) {
			y2[x] = da2 * pTemp[rowOffset + x + 1] - b1 * y2[x + 1] - b2 * y2[x + 2];
		}

		for (int x = 0; x < width; x++) {
			pGx[rowOffset + x] = y1[x] + y2[x];
		}
	}

	// ==========================================
	// 4. COMPUTE VERTICAL DERIVATIVE (Gy)
	// Step A: Smooth Horizontally (Rows)
	// ==========================================
	for (int y = 0; y < height; y++)
	{
		int rowOffset = y * width;

		y1[0] = sa0 * pGray[rowOffset];
		y1[1] = sa0 * pGray[rowOffset + 1] + sa1 * pGray[rowOffset] - b1 * y1[0];
		for (int x = 2; x < width; x++) {
			y1[x] = sa0 * pGray[rowOffset + x] + sa1 * pGray[rowOffset + x - 1] - b1 * y1[x - 1] - b2 * y1[x - 2];
		}

		y2[width - 1] = 0;
		y2[width - 2] = sa2 * pGray[rowOffset + width - 1];
		for (int x = width - 3; x >= 0; x--) {
			y2[x] = sa2 * pGray[rowOffset + x + 1] + sa3 * pGray[rowOffset + x + 2] - b1 * y2[x + 1] - b2 * y2[x + 2];
		}

		for (int x = 0; x < width; x++) {
			pTemp[rowOffset + x] = y1[x] + y2[x];
		}
	}

	// Step B: Differentiate Vertically (Columns) on the smoothed pTemp
	for (int x = 0; x < width; x++)
	{
		y1[0] = 0;
		y1[1] = da1 * pTemp[x];
		for (int y = 2; y < height; y++) {
			y1[y] = da1 * pTemp[(y - 1) * width + x] - b1 * y1[y - 1] - b2 * y1[y - 2];
		}

		y2[height - 1] = 0;
		y2[height - 2] = da2 * pTemp[(height - 1) * width + x];
		for (int y = height - 3; y >= 0; y--) {
			y2[y] = da2 * pTemp[(y + 1) * width + x] - b1 * y2[y + 1] - b2 * y2[y + 2];
		}

		for (int y = 0; y < height; y++) {
			pGy[y * width + x] = y1[y] + y2[y];
		}
	}

	// 5. COMBINE MAGNITUDE AND MAP TO DIB FRAME BUFFER
	for (int y = 0; y < height; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);
		int rowOffset = y * width;

		for (int x = 0; x < width; x++)
		{
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			float gx = pGx[rowOffset + x];
			float gy = pGy[rowOffset + x];

			int magnitude = (int)sqrt((gx * gx) + (gy * gy));

			// High contrast boost normalization clamp
			magnitude *= 5;
			BYTE edgeVal = (BYTE)(magnitude > 255 ? 255 : magnitude);

			pDstPixel[0] = edgeVal;
			pDstPixel[1] = edgeVal;
			pDstPixel[2] = edgeVal;
		}
	}

	// Clean up
	delete[] pGray;
	delete[] pGx;
	delete[] pGy;
	delete[] pTemp;
	delete[] y1;
	delete[] y2;

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnSpatialdomainfilteringUnsharpmasking()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// ── Unsharp Masking Parameters ────────────────────────────────────────
	// amount:  how much sharpening (1.0 = standard, 2.0 = aggressive)
	// radius:  blur kernel size (5x5 Gaussian)
	// threshold: minimum edge strength to sharpen (0 = sharpen everything)
	float amount = 1.5f;  // Sharpening strength
	int   threshold = 8;     // Ignore tiny differences below this value

	int totalPixels = width * height;

	// ── Step 1: Create blurred version using 5x5 Gaussian ─────────────────
	float gaussian5[5][5] = {
		{ 1,  4,  7,  4, 1},
		{ 4, 16, 26, 16, 4},
		{ 7, 26, 41, 26, 7},
		{ 4, 16, 26, 16, 4},
		{ 1,  4,  7,  4, 1}
	};
	float g5Sum = 273.0f;

	std::vector<float> blurred(totalPixels * 3, 0.0f); // BGR channels

	for (int y = 2; y < height - 2; y++)
	{
		for (int x = 2; x < width - 2; x++)
		{
			float sumB = 0, sumG = 0, sumR = 0;
			for (int ky = -2; ky <= 2; ky++) {
				BYTE* pRow = pSrcBits + ((y + ky) * pitch);
				for (int kx = -2; kx <= 2; kx++) {
					BYTE* pPx = pRow + ((x + kx) * bytesPerPixel);
					float w = gaussian5[ky + 2][kx + 2];
					sumB += pPx[0] * w;
					sumG += pPx[1] * w;
					sumR += pPx[2] * w;
				}
			}
			int idx = y * width + x;
			blurred[idx * 3 + 0] = sumB / g5Sum;
			blurred[idx * 3 + 1] = sumG / g5Sum;
			blurred[idx * 3 + 2] = sumR / g5Sum;
		}
	}

	// ── Step 2: Unsharp mask = original + amount * (original - blurred) ───
	for (int y = 2; y < height - 2; y++)
	{
		BYTE* pSrcRow = pSrcBits + (y * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 2; x < width - 2; x++)
		{
			BYTE* pSrc = pSrcRow + (x * bytesPerPixel);
			BYTE* pDst = pDstRow + (x * bytesPerPixel);
			int   idx = y * width + x;

			for (int c = 0; c < 3; c++)
			{
				float original = (float)pSrc[c];
				float blur = blurred[idx * 3 + c];
				float diff = original - blur;

				// Only sharpen if the difference exceeds threshold
				// (avoids amplifying noise in flat areas)
				float sharpened = original;
				if (fabsf(diff) > threshold)
					sharpened = original + amount * diff;

				// Clamp to valid byte range
				if (sharpened > 255.0f) sharpened = 255.0f;
				else if (sharpened < 0.0f)   sharpened = 0.0f;

				pDst[c] = (BYTE)sharpened;
			}
		}
	}

	// Copy border pixels unchanged
	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch,
			min(2, width) * bytesPerPixel);

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringEmbossfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// ── Emboss kernel — light from top-left (classic Photoshop emboss) ────
	//  -2 -1  0
	//  -1  1  1
	//   0  1  2
	int emboss[3][3] = {
		{ -2, -1,  0 },
		{ -1,  1,  1 },
		{  0,  1,  2 }
	};

	// Copy borders unchanged
	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch,
			width * bytesPerPixel);

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDst = pDstRow + (x * bytesPerPixel);

			int sumB = 0, sumG = 0, sumR = 0;

			for (int ky = -1; ky <= 1; ky++) {
				BYTE* pSrcRow = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++) {
					BYTE* pSrc = pSrcRow + ((x + kx) * bytesPerPixel);
					int   w = emboss[ky + 1][kx + 1];
					sumB += pSrc[0] * w;
					sumG += pSrc[1] * w;
					sumR += pSrc[2] * w;
				}
			}

			// Add 128 bias — shifts result to mid-gray so both
			// raised (bright) and lowered (dark) relief is visible
			sumB += 128; sumG += 128; sumR += 128;

			pDst[0] = (BYTE)(sumB > 255 ? 255 : (sumB < 0 ? 0 : sumB));
			pDst[1] = (BYTE)(sumG > 255 ? 255 : (sumG < 0 ? 0 : sumG));
			pDst[2] = (BYTE)(sumR > 255 ? 255 : (sumR < 0 ? 0 : sumR));
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringGredientmagnitude()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// ── Sobel kernels for X and Y gradients ───────────────────────────────
	int sobelX[3][3] = {
		{ -1,  0,  1 },
		{ -2,  0,  2 },
		{ -1,  0,  1 }
	};
	int sobelY[3][3] = {
		{ -1, -2, -1 },
		{  0,  0,  0 },
		{  1,  2,  1 }
	};

	int totalPixels = width * height;

	// ── Compute gradient magnitude for each channel ───────────────────────
	std::vector<float> magB(totalPixels, 0.0f);
	std::vector<float> magG(totalPixels, 0.0f);
	std::vector<float> magR(totalPixels, 0.0f);

	float globalMax = 1e-6f;

	for (int y = 1; y < height - 1; y++)
	{
		for (int x = 1; x < width - 1; x++)
		{
			int gxB = 0, gxG = 0, gxR = 0;
			int gyB = 0, gyG = 0, gyR = 0;

			for (int ky = -1; ky <= 1; ky++) {
				BYTE* pRow = pSrcBits + ((y + ky) * pitch);
				for (int kx = -1; kx <= 1; kx++) {
					BYTE* pPx = pRow + ((x + kx) * bytesPerPixel);
					int   wx = sobelX[ky + 1][kx + 1];
					int   wy = sobelY[ky + 1][kx + 1];
					gxB += pPx[0] * wx; gyB += pPx[0] * wy;
					gxG += pPx[1] * wx; gyG += pPx[1] * wy;
					gxR += pPx[2] * wx; gyR += pPx[2] * wy;
				}
			}

			int idx = y * width + x;
			magB[idx] = sqrtf((float)(gxB * gxB + gyB * gyB));
			magG[idx] = sqrtf((float)(gxG * gxG + gyG * gyG));
			magR[idx] = sqrtf((float)(gxR * gxR + gyR * gyR));

			// Track global max for normalization
			if (magB[idx] > globalMax) globalMax = magB[idx];
			if (magG[idx] > globalMax) globalMax = magG[idx];
			if (magR[idx] > globalMax) globalMax = magR[idx];
		}
	}

	// ── Write normalized output ───────────────────────────────────────────
	// Fill borders black first
	for (int y = 0; y < height; y++)
		memset(pDstBits + y * pitch, 0, width * bytesPerPixel);

	for (int y = 1; y < height - 1; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);
		for (int x = 1; x < width - 1; x++)
		{
			BYTE* pDst = pDstRow + (x * bytesPerPixel);
			int   idx = y * width + x;

			// ✅ Auto-normalized — full color gradient magnitude map
			// Each channel independently normalized for maximum detail
			pDst[0] = (BYTE)((magB[idx] / globalMax) * 255.0f); // B
			pDst[1] = (BYTE)((magG[idx] / globalMax) * 255.0f); // G
			pDst[2] = (BYTE)((magR[idx] / globalMax) * 255.0f); // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringBilateralfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	int   radius = 5;
	float sigmaSp = 10.0f;
	float sigmaInt = 30.0f;

	float twoSigmaSp2 = 2.0f * sigmaSp * sigmaSp;
	float twoSigmaInt2 = 2.0f * sigmaInt * sigmaInt;

	const int kernelSize = 2 * radius + 1;
	std::vector<float> spatialWeights(kernelSize * kernelSize);
	for (int ky = -radius; ky <= radius; ky++)
		for (int kx = -radius; kx <= radius; kx++)
		{
			float spatialDist = (float)(ky * ky + kx * kx);
			spatialWeights[(ky + radius) * kernelSize + (kx + radius)] =
				expf(-spatialDist / twoSigmaSp2);
		}

	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch,
			width * bytesPerPixel);

	// ── Set up progress bar ─────────────────────────────────────────────
	CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
	int rowsToProcess = height - 2 * radius;
	if (pMainFrame) pMainFrame->StartProgress(rowsToProcess);

	BeginWaitCursor();

	int rowCounter = 0;
	for (int y = radius; y < height - radius; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = radius; x < width - radius; x++)
		{
			BYTE* pCenter = pSrcBits + (y * pitch) + (x * bytesPerPixel);
			BYTE* pDst = pDstRow + (x * bytesPerPixel);

			double sumB = 0, sumG = 0, sumR = 0;
			double weightSum = 0;

			for (int ky = -radius; ky <= radius; ky++)
			{
				BYTE* pSrcRow = pSrcBits + ((y + ky) * pitch);
				for (int kx = -radius; kx <= radius; kx++)
				{
					BYTE* pNeighbor = pSrcRow + ((x + kx) * bytesPerPixel);

					float wSpatial = spatialWeights[(ky + radius) * kernelSize + (kx + radius)];

					float dB = (float)(pNeighbor[0] - pCenter[0]);
					float dG = (float)(pNeighbor[1] - pCenter[1]);
					float dR = (float)(pNeighbor[2] - pCenter[2]);
					float intensityDist = dB * dB + dG * dG + dR * dR;
					float wIntensity = expf(-intensityDist / twoSigmaInt2);

					float w = wSpatial * wIntensity;

					sumB += pNeighbor[0] * w;
					sumG += pNeighbor[1] * w;
					sumR += pNeighbor[2] * w;
					weightSum += w;
				}
			}

			if (weightSum > 0) {
				pDst[0] = (BYTE)(sumB / weightSum);
				pDst[1] = (BYTE)(sumG / weightSum);
				pDst[2] = (BYTE)(sumR / weightSum);
			}
		}

			// ── Update progress once per row ────────────────────────────────
		rowCounter++;
		if (pMainFrame && (rowCounter % 4 == 0)) // throttle updates, every 4 rows
		{
			pMainFrame->UpdateProgress(rowCounter);
			pMainFrame->RefreshProgressBar();   // ← fixed: uses public helper instead
		}
	}

	EndWaitCursor();
	if (pMainFrame) pMainFrame->EndProgress();

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringNon()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// ── Parameters ────────────────────────────────────────────────────────
	int   patchRadius = 3;    // Patch comparison radius (7x7 patch)
	int   searchRadius = 10;   // Search window radius
	float h = 10.0f;           // Filter strength 
	int patchDims = (2 * patchRadius + 1) * (2 * patchRadius + 1) * 3;
	float h2 = h * h * patchDims;

	// Copy borders unchanged
	for (int y = 0; y < height; y++) {
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch, width * bytesPerPixel);
	}

	int border = patchRadius + searchRadius;
	int uiUpdateCounter = 0;

	for (int y = border; y < height - border; y++)
	{
		// Keep UI responsive every 5 rows
		if (++uiUpdateCounter % 5 == 0) {
			MSG msg;
			while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
				::TranslateMessage(&msg);
				::DispatchMessage(&msg);
			}

			// CRITICAL SAFETY CHECK: If the user closed the window/view 
			// during PeekMessage, abort immediately to prevent a crash!
			if (!::IsWindow(m_hWnd)) {
				return;
			}
		}

		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = border; x < width - border; x++)
		{
			BYTE* pDst = pDstRow + (x * bytesPerPixel);

			double sumB = 0, sumG = 0, sumR = 0;
			double weightSum = 0;
			double maxWeight = 0;

			for (int sy = -searchRadius; sy <= searchRadius; sy++)
			{
				int cy = y + sy;
				BYTE* pCndCenterRow = pSrcBits + (cy * pitch);

				for (int sx = -searchRadius; sx <= searchRadius; sx++)
				{
					int cx = x + sx;
					double patchDist = 0;

					for (int py = -patchRadius; py <= patchRadius; py++)
					{
						BYTE* pRefRow = pSrcBits + ((y + py) * pitch);
						BYTE* pCndRow = pSrcBits + ((cy + py) * pitch);

						BYTE* pRef = pRefRow + ((x - patchRadius) * bytesPerPixel);
						BYTE* pCnd = pCndRow + ((cx - patchRadius) * bytesPerPixel);

						for (int px = -patchRadius; px <= patchRadius; px++)
						{
							float d0 = (float)(pRef[0] - pCnd[0]);
							float d1 = (float)(pRef[1] - pCnd[1]);
							float d2 = (float)(pRef[2] - pCnd[2]);

							patchDist += (d0 * d0) + (d1 * d1) + (d2 * d2);

							pRef += bytesPerPixel;
							pCnd += bytesPerPixel;
						}
					}

					double w = exp(-patchDist / h2);
					if (w > maxWeight) maxWeight = w;

					BYTE* pCndPixel = pCndCenterRow + (cx * bytesPerPixel);
					sumB += pCndPixel[0] * w;
					sumG += pCndPixel[1] * w;
					sumR += pCndPixel[2] * w;
					weightSum += w;
				}
			}

			BYTE* pSelf = pSrcBits + (y * pitch) + (x * bytesPerPixel);
			sumB += pSelf[0] * maxWeight;
			sumG += pSelf[1] * maxWeight;
			sumR += pSelf[2] * maxWeight;
			weightSum += maxWeight;

			if (weightSum > 0) {
				pDst[0] = (BYTE)(sumB / weightSum);
				pDst[1] = (BYTE)(sumG / weightSum);
				pDst[2] = (BYTE)(sumR / weightSum);
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringWienerfilter()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// ── Parameters ────────────────────────────────────────────────────────
	int   radius = 3;    // Local window radius (7x7)
	float noiseVar = 25.0f; // Assumed noise variance (sigma^2)
	// Higher = more smoothing

	int windowSize = (2 * radius + 1) * (2 * radius + 1);

	// Copy borders unchanged
	for (int y = 0; y < height; y++)
		memcpy(pDstBits + y * pitch, pSrcBits + y * pitch,
			width * bytesPerPixel);

	for (int y = radius; y < height - radius; y++)
	{
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = radius; x < width - radius; x++)
		{
			BYTE* pDst = pDstRow + (x * bytesPerPixel);

			// Process each channel independently
			for (int c = 0; c < 3; c++)
			{
				// ── Step 1: Compute local mean ────────────────────────────
				float localMean = 0;
				for (int ky = -radius; ky <= radius; ky++) {
					BYTE* pRow = pSrcBits + ((y + ky) * pitch);
					for (int kx = -radius; kx <= radius; kx++) {
						BYTE* pPx = pRow + ((x + kx) * bytesPerPixel);
						localMean += pPx[c];
					}
				}
				localMean /= windowSize;

				// ── Step 2: Compute local variance ────────────────────────
				float localVar = 0;
				for (int ky = -radius; ky <= radius; ky++) {
					BYTE* pRow = pSrcBits + ((y + ky) * pitch);
					for (int kx = -radius; kx <= radius; kx++) {
						BYTE* pPx = pRow + ((x + kx) * bytesPerPixel);
						float diff = pPx[c] - localMean;
						localVar += diff * diff;
					}
				}
				localVar /= windowSize;

				// ── Step 3: Wiener formula ────────────────────────────────
				// output = mean + max(0, localVar - noiseVar) / localVar
				//                * (pixel - mean)
				BYTE* pSrcPx = pSrcBits + (y * pitch) + (x * bytesPerPixel);
				float pixel = (float)pSrcPx[c];

				float signalVar = localVar - noiseVar;
				if (signalVar < 0) signalVar = 0;

				float result;
				if (localVar < 1e-6f)
					result = localMean;
				else
					result = localMean + (signalVar / localVar) * (pixel - localMean);

				// Clamp
				if (result > 255.0f) result = 255.0f;
				else if (result < 0.0f)   result = 0.0f;

				pDst[c] = (BYTE)result;
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


static void MorphErode(BYTE* pSrc, BYTE* pDst,
	int width, int height,
	int pitch, int bytesPerPixel, int radius);

static void MorphDilate(BYTE* pSrc, BYTE* pDst,
	int width, int height,
	int pitch, int bytesPerPixel, int radius);

// Helper: returns a "logical" pointer into buf that behaves like CImage::GetBits().
// Handles bottom-up DIBs where pitch is negative — in that case GetBits() points
// at the LAST row in memory so that p + y*pitch (negative) walks backward
// correctly as y increases. Plain std::vector buffers need the same offset.
static BYTE* MakeLogicalPtr(std::vector<BYTE>& buf, int height, int pitch)
{
	BYTE* p = buf.data();
	if (pitch < 0)
		p += (height - 1) * abs(pitch);
	return p;
}

void Cproject1View::OnSpatialdomainfilteringErosion()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	MorphErode(pSrcBits, pDstBits, width, height, pitch, bytesPerPixel, 2);

	Invalidate(FALSE);
	UpdateWindow();
}

static void MorphErode(BYTE* pSrc, BYTE* pDst,
	int width, int height,
	int pitch, int bytesPerPixel, int radius)
{
	for (int y = 0; y < height; y++)
		memcpy(pDst + y * pitch, pSrc + y * pitch, width * bytesPerPixel);

	for (int y = radius; y < height - radius; y++)
	{
		BYTE* pDstRow = pDst + (y * pitch);
		for (int x = radius; x < width - radius; x++)
		{
			BYTE* pDstPx = pDstRow + (x * bytesPerPixel);
			int minB = 255, minG = 255, minR = 255;

			for (int ky = -radius; ky <= radius; ky++) {
				BYTE* pSrcRow = pSrc + ((y + ky) * pitch);
				for (int kx = -radius; kx <= radius; kx++) {
					BYTE* pSrcPx = pSrcRow + ((x + kx) * bytesPerPixel);
					if (pSrcPx[0] < minB) minB = pSrcPx[0];
					if (pSrcPx[1] < minG) minG = pSrcPx[1];
					if (pSrcPx[2] < minR) minR = pSrcPx[2];
				}
			}
			pDstPx[0] = (BYTE)minB;
			pDstPx[1] = (BYTE)minG;
			pDstPx[2] = (BYTE)minR;
		}
	}
}

void Cproject1View::OnSpatialdomainfilteringDomainfilteringopening()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Opening = Erosion followed by Dilation
	int totalBytes = height * abs(pitch);
	std::vector<BYTE> buffer(totalBytes);
	BYTE* pIntermediate = MakeLogicalPtr(buffer, height, pitch);

	// Step 1: Erode original → intermediate
	MorphErode(pSrcBits, pIntermediate,
		width, height, pitch, bytesPerPixel, 2);

	// Step 2: Dilate intermediate → destination
	MorphDilate(pIntermediate, pDstBits,
		width, height, pitch, bytesPerPixel, 2);

	Invalidate(FALSE);
	UpdateWindow();
}

static void MorphDilate(BYTE* pSrc, BYTE* pDst,
	int width, int height,
	int pitch, int bytesPerPixel, int radius)
{
	for (int y = 0; y < height; y++)
		memcpy(pDst + y * pitch, pSrc + y * pitch, width * bytesPerPixel);

	for (int y = radius; y < height - radius; y++)
	{
		BYTE* pDstRow = pDst + (y * pitch);
		for (int x = radius; x < width - radius; x++)
		{
			BYTE* pDstPx = pDstRow + (x * bytesPerPixel);
			int maxB = 0, maxG = 0, maxR = 0;

			for (int ky = -radius; ky <= radius; ky++) {
				BYTE* pSrcRow = pSrc + ((y + ky) * pitch);
				for (int kx = -radius; kx <= radius; kx++) {
					BYTE* pSrcPx = pSrcRow + ((x + kx) * bytesPerPixel);
					if (pSrcPx[0] > maxB) maxB = pSrcPx[0];
					if (pSrcPx[1] > maxG) maxG = pSrcPx[1];
					if (pSrcPx[2] > maxR) maxR = pSrcPx[2];
				}
			}
			pDstPx[0] = (BYTE)maxB;
			pDstPx[1] = (BYTE)maxG;
			pDstPx[2] = (BYTE)maxR;
		}
	}
}

void Cproject1View::OnSpatialdomainfilteringDomainfilteringclosing()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	// Closing = Dilation followed by Erosion
	// Fills small dark gaps/holes while preserving main structures
	int totalBytes = height * abs(pitch);
	std::vector<BYTE> buffer(totalBytes);
	BYTE* pIntermediate = MakeLogicalPtr(buffer, height, pitch);

	// Step 1: Dilate original → intermediate
	MorphDilate(pSrcBits, pIntermediate,
		width, height, pitch, bytesPerPixel, 2);

	// Step 2: Erode intermediate → destination
	MorphErode(pIntermediate, pDstBits,
		width, height, pitch, bytesPerPixel, 2);

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringDomainfilteringmorphologicalgradient()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	int totalBytes = height * abs(pitch);

	std::vector<BYTE> dilBuf(totalBytes);
	std::vector<BYTE> eroBuf(totalBytes);

	BYTE* pDilated = MakeLogicalPtr(dilBuf, height, pitch);
	BYTE* pEroded = MakeLogicalPtr(eroBuf, height, pitch);

	// Step 1: Compute dilation and erosion of original
	MorphDilate(pSrcBits, pDilated,
		width, height, pitch, bytesPerPixel, 1);
	MorphErode(pSrcBits, pEroded,
		width, height, pitch, bytesPerPixel, 1);

	// Step 2: Gradient = Dilation - Erosion
	// The difference highlights boundaries between bright and dark regions
	for (int y = 0; y < height; y++)
	{
		BYTE* pDilRow = pDilated + (y * pitch);
		BYTE* pEroRow = pEroded + (y * pitch);
		BYTE* pDstRow = pDstBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pDil = pDilRow + (x * bytesPerPixel);
			BYTE* pEro = pEroRow + (x * bytesPerPixel);
			BYTE* pDst = pDstRow + (x * bytesPerPixel);

			// Absolute difference per channel
			pDst[0] = (BYTE)abs((int)pDil[0] - (int)pEro[0]); // B
			pDst[1] = (BYTE)abs((int)pDil[1] - (int)pEro[1]); // G
			pDst[2] = (BYTE)abs((int)pDil[2] - (int)pEro[2]); // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnTransformFlip()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CFlipRotateDlg dlg;
	if (dlg.DoModal() != IDOK) return;

	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	int width = pDoc->m_imageOriginal.GetWidth();
	int height = pDoc->m_imageOriginal.GetHeight();
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int bytesPerPixel = pDoc->m_imageOriginal.GetBPP() / 8;

	switch (dlg.m_op)
	{
	case OP_FLIP_H:
	{
		for (int y = 0; y < height; y++)
		{
			BYTE* pSrcRow = pSrcBits + (y * pitch);
			BYTE* pDstRow = pDstBits + (y * pitch);
			for (int x = 0; x < width; x++)
			{
				BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
				BYTE* pDstPixel = pDstRow + ((width - 1 - x) * bytesPerPixel);
				memcpy(pDstPixel, pSrcPixel, bytesPerPixel);
			}
		}
		break;
	}
	case OP_FLIP_V:
	{
		for (int y = 0; y < height; y++)
		{
			BYTE* pSrcRow = pSrcBits + (y * pitch);
			BYTE* pDstRow = pDstBits + ((height - 1 - y) * pitch);
			memcpy(pDstRow, pSrcRow, width * bytesPerPixel);
		}
		break;
	}
	case OP_ROTATE_90:
	{
		int dstPitch = pDoc->m_image.GetPitch();
		for (int y = 0; y < height; y++)
		{
			BYTE* pSrcRow = pSrcBits + (y * pitch);
			for (int x = 0; x < width; x++)
			{
				BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
				int dstX = height - 1 - y;
				int dstY = x;
				BYTE* pDstPixel = pDstBits + (dstY * dstPitch) + (dstX * bytesPerPixel);
				memcpy(pDstPixel, pSrcPixel, bytesPerPixel);
			}
		}
		break;
	}
	case OP_ROTATE_180:
	{
		for (int y = 0; y < height; y++)
		{
			BYTE* pSrcRow = pSrcBits + (y * pitch);
			BYTE* pDstRow = pDstBits + ((height - 1 - y) * pitch);
			for (int x = 0; x < width; x++)
			{
				BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
				BYTE* pDstPixel = pDstRow + ((width - 1 - x) * bytesPerPixel);
				memcpy(pDstPixel, pSrcPixel, bytesPerPixel);
			}
		}
		break;
	}
	case OP_ROTATE_270:
	{
		int dstPitch = pDoc->m_image.GetPitch();
		for (int y = 0; y < height; y++)
		{
			BYTE* pSrcRow = pSrcBits + (y * pitch);
			for (int x = 0; x < width; x++)
			{
				BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
				int dstX = y;
				int dstY = width - 1 - x;
				BYTE* pDstPixel = pDstBits + (dstY * dstPitch) + (dstX * bytesPerPixel);
				memcpy(pDstPixel, pSrcPixel, bytesPerPixel);
			}
		}
		break;
	}
	default:
		return;
	}

	// Double buffering handles drawing smoothly inside OnDraw
	Invalidate(FALSE);
}

void Cproject1View::OnImageFlipRotate()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CFlipRotateDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK) return;

	switch (dlg.m_op)
	{
	case OP_FLIP_H:           FlipHorizontal(); break;
	case OP_FLIP_V:           FlipVertical();   break;
	case OP_ROTATE_90:        Rotate90();       break;
	case OP_ROTATE_180:       Rotate180();      break;
	case OP_ROTATE_270:       Rotate270();      break;
	case OP_ROTATE_ARBITRARY: RotateArbitrary((double)dlg.m_arbitraryAngle); break;
	}

	CSize newSize(pDoc->m_image.GetWidth(), pDoc->m_image.GetHeight());
	SetScrollSizes(MM_TEXT, newSize);
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	Invalidate(FALSE);
}

void Cproject1View::FlipHorizontal()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	for (int y = 0; y < height; y++)
	{
		BYTE* row = pBits + y * pitch;
		for (int x = 0; x < width / 2; x++)
		{
			BYTE* left = row + x * bpp;
			BYTE* right = row + (width - 1 - x) * bpp;
			for (int c = 0; c < bpp; c++)
				std::swap(left[c], right[c]);
		}
	}
}

void Cproject1View::FlipVertical()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = abs(pitch);
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	BYTE* temp = new BYTE[absPitch];
	for (int y = 0; y < height / 2; y++)
	{
		BYTE* topRow = pBits + y * pitch;
		BYTE* bottomRow = pBits + (height - 1 - y) * pitch;
		memcpy(temp, topRow, absPitch);
		memcpy(topRow, bottomRow, absPitch);
		memcpy(bottomRow, temp, absPitch);
	}
	delete[] temp;
}

void Cproject1View::Rotate180()
{
	FlipHorizontal();
	FlipVertical();
}

void Cproject1View::Rotate90()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	RotateImage90(pDoc->m_image);
	RotateImage90(pDoc->m_imageOriginal);
}

void Cproject1View::Rotate270()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	RotateImage270(pDoc->m_image);
	RotateImage270(pDoc->m_imageOriginal);
}

void Cproject1View::RotateImage90(CImage& img)
{
	int srcW = img.GetWidth();
	int srcH = img.GetHeight();
	int bpp = img.GetBPP() / 8;

	CImage dst;
	dst.Create(srcH, srcW, img.GetBPP());

	BYTE* pSrc = (BYTE*)img.GetBits();
	BYTE* pDst = (BYTE*)dst.GetBits();
	int srcPitch = img.GetPitch();
	int dstPitch = dst.GetPitch();

	for (int y = 0; y < srcH; y++)
	{
		for (int x = 0; x < srcW; x++)
		{
			BYTE* srcPixel = pSrc + y * srcPitch + x * bpp;
			int dstX = srcH - 1 - y;
			int dstY = x;
			BYTE* dstPixel = pDst + dstY * dstPitch + dstX * bpp;
			memcpy(dstPixel, srcPixel, bpp);
		}
	}
	img.Destroy();
	img.Attach(dst.Detach());
}

void Cproject1View::RotateImage270(CImage& img)
{
	int srcW = img.GetWidth();
	int srcH = img.GetHeight();
	int bpp = img.GetBPP() / 8;

	CImage dst;
	dst.Create(srcH, srcW, img.GetBPP());

	BYTE* pSrc = (BYTE*)img.GetBits();
	BYTE* pDst = (BYTE*)dst.GetBits();
	int srcPitch = img.GetPitch();
	int dstPitch = dst.GetPitch();

	for (int y = 0; y < srcH; y++)
	{
		for (int x = 0; x < srcW; x++)
		{
			BYTE* srcPixel = pSrc + y * srcPitch + x * bpp;
			int dstX = y;
			int dstY = srcW - 1 - x;
			BYTE* dstPixel = pDst + dstY * dstPitch + dstX * bpp;
			memcpy(dstPixel, srcPixel, bpp);
		}
	}
	img.Destroy();
	img.Attach(dst.Detach());
}

void Cproject1View::RotateArbitrary(double angleDegrees)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	RotateImageArbitrary(pDoc->m_image, angleDegrees);
	RotateImageArbitrary(pDoc->m_imageOriginal, angleDegrees);
}

void Cproject1View::RotateImageArbitrary(CImage& img, double angleDegrees)
{
	if (img.IsNull()) return;

	int srcW = img.GetWidth();
	int srcH = img.GetHeight();

	double angleRad = angleDegrees * 3.14159265358979 / 180.0;
	double cosA = fabs(cos(angleRad));
	double sinA = fabs(sin(angleRad));

	int dstW = (int)ceil(srcW * cosA + srcH * sinA);
	int dstH = (int)ceil(srcW * sinA + srcH * cosA);

	HBITMAP hSrcBmp = (HBITMAP)img;
	Gdiplus::Bitmap* pSrcBmp = Gdiplus::Bitmap::FromHBITMAP(hSrcBmp, NULL);
	if (!pSrcBmp) return;

	Gdiplus::Bitmap dstBmp(dstW, dstH, PixelFormat32bppARGB);
	Gdiplus::Graphics graphics(&dstBmp);
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQualityBicubic);

	graphics.Clear(Gdiplus::Color(255, 255, 255, 255));

	graphics.TranslateTransform((Gdiplus::REAL)(dstW / 2.0), (Gdiplus::REAL)(dstH / 2.0));
	graphics.RotateTransform((Gdiplus::REAL)angleDegrees);
	graphics.DrawImage(pSrcBmp, -srcW / 2, -srcH / 2, srcW, srcH);

	delete pSrcBmp;

	HBITMAP hDstBmp = NULL;
	dstBmp.GetHBITMAP(Gdiplus::Color(255, 255, 255), &hDstBmp);

	img.Destroy();
	img.Attach(hDstBmp);
}

void Cproject1View::SetPreviewRotationAngle(double angle, BOOL bActive)
{
	m_previewRotationAngle = angle;
	m_bPreviewRotationActive = bActive;

	// Triggers OnDraw to seamlessly compile the new rotation position off-screen
	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::DrawArbitraryRotationPreview(CDC* pTargetDC, CImage& srcImg, double angleDegrees)
{
	CRect rectClient;
	GetClientRect(&rectClient);

	// ❌ REMOVED: pTargetDC->FillRect(&rectClient, &bgBrush);
	// We no longer clear the screen here because OnDraw already handled clearing 
	// the background inside the off-screen memory buffer.

	int srcW = srcImg.GetWidth();
	int srcH = srcImg.GetHeight();

	HBITMAP hSrcBmp = (HBITMAP)srcImg;
	Gdiplus::Bitmap* pBmp = Gdiplus::Bitmap::FromHBITMAP(hSrcBmp, NULL);
	if (!pBmp) return;

	// ✅ FIX: Bind the GDI+ graphics engine to the target context handle passed from OnDraw
	Gdiplus::Graphics graphics(pTargetDC->GetSafeHdc());
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeAntiAlias);
	graphics.SetInterpolationMode(Gdiplus::InterpolationModeBilinear);

	double angleRad = angleDegrees * 3.14159265358979 / 180.0;
	double cosA = fabs(cos(angleRad));
	double sinA = fabs(sin(angleRad));
	double rotatedW = srcW * cosA + srcH * sinA;
	double rotatedH = srcW * sinA + srcH * cosA;

	double scale = min(rectClient.Width() / rotatedW, rectClient.Height() / rotatedH);
	scale = min(scale, 1.0);

	graphics.TranslateTransform(
		(Gdiplus::REAL)(rectClient.Width() / 2.0),
		(Gdiplus::REAL)(rectClient.Height() / 2.0));
	graphics.RotateTransform((Gdiplus::REAL)angleDegrees);
	graphics.ScaleTransform((Gdiplus::REAL)scale, (Gdiplus::REAL)scale);

	graphics.DrawImage(pBmp, -srcW / 2, -srcH / 2, srcW, srcH);

	delete pBmp;
}

void Cproject1View::ApplyLiveHSV(int hDeg, int sSat, int vVal)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// 1. Reset current working canvas from pristine copy via raw memory block block copy
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	// 2. Precalculate normalized tuning inputs
	double hueShift = hDeg / 360.0;
	double satFactor = 1.0 + (sSat / 100.0);
	double valOffset = (vVal / 100.0);

	// 3. Process via high-speed engine lambda transformation
	ProcessPixels([=](BYTE& b, BYTE& g, BYTE& r)
		{
			double B = b / 255.0;
			double G = g / 255.0;
			double R = r / 255.0;

			// --- RGB to HSV ---
			double maxC = max(R, max(G, B));
			double minC = min(R, min(G, B));
			double delta = maxC - minC;

			double V = maxC;
			double S = (V > 0.0001) ? (delta / V) : 0.0;

			double H = 0.0;
			if (delta > 0.0001)
			{
				if (maxC == R)      H = fmod((G - B) / delta, 6.0) / 6.0;
				else if (maxC == G) H = ((B - R) / delta + 2.0) / 6.0;
				else                H = ((R - G) / delta + 4.0) / 6.0;

				if (H < 0.0) H += 1.0;
			}

			// --- Apply HSV adjustments ---
			H += hueShift;
			if (H > 1.0) H -= 1.0;
			if (H < 0.0) H += 1.0;

			S = max(0.0, min(1.0, S * satFactor));
			V = max(0.0, min(1.0, V + valOffset));

			// --- HSV back to RGB ---
			double newR, newG, newB;
			if (S == 0.0)
			{
				newR = newG = newB = V;
			}
			else
			{
				double h6 = H * 6.0;
				int    hi = (int)h6 % 6;
				double f = h6 - (int)h6;
				double p = V * (1.0 - S);
				double q = V * (1.0 - S * f);
				double t = V * (1.0 - S * (1.0 - f));

				switch (hi)
				{
				case 0:  newR = V; newG = t; newB = p; break;
				case 1:  newR = q; newG = V; newB = p; break;
				case 2:  newR = p; newG = V; newB = t; break;
				case 3:  newR = p; newG = q; newB = V; break;
				case 4:  newR = t; newG = p; newB = V; break;
				default: newR = V; newG = p; newB = q; break;
				}
			}

			b = (BYTE)max(0.0, min(255.0, newB * 255.0));
			g = (BYTE)max(0.0, min(255.0, newG * 255.0));
			r = (BYTE)max(0.0, min(255.0, newR * 255.0));
		});

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveHSVPreview(int hDeg, int sSat, int vVal, CImage* pSmallImg)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || !pSmallImg || pSmallImg->IsNull()) return;

	int fullW = pDoc->m_imageOriginal.GetWidth();
	int fullH = pDoc->m_imageOriginal.GetHeight();
	int prevW = pSmallImg->GetWidth();
	int prevH = pSmallImg->GetHeight();

	HDC hdcSrc = pDoc->m_imageOriginal.GetDC();
	HDC hdcDest = pSmallImg->GetDC();

	::SetStretchBltMode(hdcDest, HALFTONE);
	::SetBrushOrgEx(hdcDest, 0, 0, NULL);
	::StretchBlt(hdcDest, 0, 0, prevW, prevH, hdcSrc, 0, 0, fullW, fullH, SRCCOPY);

	pDoc->m_imageOriginal.ReleaseDC();
	pSmallImg->ReleaseDC();

	int   bpp = pSmallImg->GetBPP();
	BYTE* pBits = (BYTE*)pSmallImg->GetBits();
	int   pitch = pSmallImg->GetPitch();
	int   bytesPerPix = bpp / 8;

	double hueShift = hDeg / 360.0;
	double satFactor = 1.0 + (sSat / 100.0);
	double valOffset = (vVal / 100.0);

	// High-speed index tracking loop for preview window bounds
	for (int y = 0; y < prevH; ++y)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < prevW; ++x)
		{
			int offset = x * bytesPerPix;

			double B = pRow[offset] / 255.0;
			double G = pRow[offset + 1] / 255.0;
			double R = pRow[offset + 2] / 255.0;

			double maxC = max(R, max(G, B));
			double minC = min(R, min(G, B));
			double delta = maxC - minC;

			double V = maxC;
			double S = (V > 0.0001) ? (delta / V) : 0.0;
			double H = 0.0;

			if (delta > 0.0001)
			{
				if (maxC == R)      H = fmod((G - B) / delta, 6.0) / 6.0;
				else if (maxC == G) H = ((B - R) / delta + 2.0) / 6.0;
				else                H = ((R - G) / delta + 4.0) / 6.0;
				if (H < 0.0) H += 1.0;
			}

			H += hueShift;
			if (H > 1.0) H -= 1.0;
			if (H < 0.0) H += 1.0;

			S = max(0.0, min(1.0, S * satFactor));
			V = max(0.0, min(1.0, V + valOffset));

			double newR, newG, newB;
			if (S == 0.0)
			{
				newR = newG = newB = V;
			}
			else
			{
				double h6 = H * 6.0;
				int    hi = (int)h6 % 6;
				double f = h6 - (int)h6;
				double p = V * (1.0 - S);
				double q = V * (1.0 - S * f);
				double t = V * (1.0 - S * (1.0 - f));

				switch (hi)
				{
				case 0:  newR = V; newG = t; newB = p; break;
				case 1:  newR = q; newG = V; newB = p; break;
				case 2:  newR = p; newG = V; newB = t; break;
				case 3:  newR = p; newG = q; newB = V; break;
				case 4:  newR = t; newG = p; newB = V; break;
				default: newR = V; newG = p; newB = q; break;
				}
			}

			pRow[offset] = (BYTE)max(0.0, min(255.0, newB * 255.0));
			pRow[offset + 1] = (BYTE)max(0.0, min(255.0, newG * 255.0));
			pRow[offset + 2] = (BYTE)max(0.0, min(255.0, newR * 255.0));
		}
	}

	HDC hdcSmall = pSmallImg->GetDC();
	HDC hdcFull = pDoc->m_image.GetDC();

	::SetStretchBltMode(hdcFull, HALFTONE);
	::SetBrushOrgEx(hdcFull, 0, 0, NULL);
	::StretchBlt(hdcFull, 0, 0, fullW, fullH, hdcSmall, 0, 0, prevW, prevH, SRCCOPY);

	pDoc->m_image.ReleaseDC();
	pSmallImg->ReleaseDC();
}

void Cproject1View::OnColorsHsvadjustment()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
	{
		AfxMessageBox(_T("No active image found to process!"));
		return;
	}

	CHsvDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDCANCEL)
	{
		// OPTIMIZED: Revert working image back via safe, fast full memory-block copy
		if (!pDoc->m_imageOriginal.IsNull())
		{
			int pitch = pDoc->m_imageOriginal.GetPitch();
			int height = pDoc->m_imageOriginal.GetHeight();
			BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
			BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

			if (pitch < 0) {
				memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
			}
			else {
				memcpy(pDstBits, pSrcBits, pitch * height);
			}
		}

		Invalidate(FALSE);
		UpdateWindow();
	}
}

void Cproject1View::OnPointprocessConverttograyscale()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc) return;

	// Assuming your image is stored as m_image in the Document class
	if (pDoc->m_image.IsNull()) return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP(); // Bits Per Pixel (e.g., 24 or 32)

	// Scenario 1: If it's already an 8-bit grayscale or 1-bit binary image, do nothing
	if (bpp < 24)
	{
		return;
	}

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Loop through every pixel row by row to handle Windows bitmap memory layout safely
	for (int y = 0; y < height; y++)
	{
		// Get the pointer to the start of the current row
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			// Point to the specific pixel's channels
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			// Windows bitmaps store colors in BGR order natively:
			BYTE blue = pPixel[0];
			BYTE green = pPixel[1];
			BYTE red = pPixel[2];

			// Fast integer bit-shifted Luminosity Method 
			// Equivalent to: (0.299 * R) + (0.587 * G) + (0.114 * B)
			BYTE gray = (BYTE)((red * 77 + green * 150 + blue * 29) >> 8);

			// Force all channels to match the gray value
			pPixel[0] = gray; // B
			pPixel[1] = gray; // G
			pPixel[2] = gray; // R

		}
	}

	Invalidate();
}

void Cproject1View::OnPointprocessHsl()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. Instantiate the HSL slider dialog frame
	CHslDlg dlg;

	// 2. Link the dialog pointer live so it can talk back to this view canvas
	dlg.m_pView = this;

	// 3. Open the Dialog Window modally
	if (dlg.DoModal() == IDCANCEL)
	{
		// If the user clicks Cancel, discard the live tweaks and restore original backup copy
		if (!pDoc->m_imageOriginal.IsNull())
		{
			pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
			pDoc->m_image.ReleaseDC();
		}

		// Repaint back to standard state
		Invalidate(FALSE);
	}
}
void Cproject1View::ApplyLiveHsl(int hOffset, int sOffset, int lOffset)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// --- Restore pristine original into the working canvas first ---
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();

	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0] / 255.0;
			double g = pPixel[1] / 255.0;
			double r = pPixel[2] / 255.0;

			double maxColor = max(r, max(g, b));
			double minColor = min(r, min(g, b));
			double delta = maxColor - minColor;

			double h = 0.0, s = 0.0, l = (maxColor + minColor) / 2.0;

			if (delta != 0.0)
			{
				s = (l <= 0.5) ? (delta / (maxColor + minColor)) : (delta / (2.0 - maxColor - minColor));

				if (maxColor == r)
					h = (g - b) / delta + (g < b ? 6.0 : 0.0);
				else if (maxColor == g)
					h = (b - r) / delta + 2.0;
				else
					h = (r - g) / delta + 4.0;

				h *= 60.0;
			}

			h += hOffset;
			if (h >= 360.0) h -= 360.0;
			if (h < 0.0) h += 360.0;

			s += (sOffset / 100.0);
			s = max(0.0, min(1.0, s));

			l += (lOffset / 100.0);
			l = max(0.0, min(1.0, l));

			double newR = l, newG = l, newB = l;

			if (s != 0.0)
			{
				double q = (l < 0.5) ? (l * (1.0 + s)) : (l + s - l * s);
				double p = 2.0 * l - q;

				auto HueToRGB = [](double p, double q, double t) {
					if (t < 0.0) t += 1.0;
					if (t > 1.0) t -= 1.0;
					if (t < 1.0 / 6.0) return p + (q - p) * 6.0 * t;
					if (t < 1.0 / 2.0) return q;
					if (t < 2.0 / 3.0) return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
					return p;
					};

				newR = HueToRGB(p, q, (h / 360.0) + 1.0 / 3.0);
				newG = HueToRGB(p, q, (h / 360.0));
				newB = HueToRGB(p, q, (h / 360.0) - 1.0 / 3.0);
			}

			pPixel[0] = (BYTE)(newB * 255.0 + 0.5);
			pPixel[1] = (BYTE)(newG * 255.0 + 0.5);
			pPixel[2] = (BYTE)(newR * 255.0 + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessLogtransformation()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pImgBits += pitch * (height - 1);
	}
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CLogTransformDlg dlg(this);
	dlg.m_pView = this; // Pass this view pointer to the dialog!

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore original on cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyLiveLog(double cVal)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pDstBase += pitch * (height - 1);
	}
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// Fast Look-Up Table for live updates
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		double logValue = cVal * std::log(1.0 + i);
		if (logValue > 255.0) logValue = 255.0;
		if (logValue < 0.0)   logValue = 0.0;
		lut[i] = (BYTE)(logValue + 0.5);
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // B
			pDstPixel[1] = lut[pSrcPixel[1]]; // G
			pDstPixel[2] = lut[pSrcPixel[2]]; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveInverseLog(double cVal)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pDstBase += pitch * (height - 1);
	}
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// Generate Fast Look-Up Table for Exponential/Inverse Log mapping
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		// Formula: s = c * (exp(r / 255.0) - 1)
		double invLogValue = cVal * (std::exp(i / 255.0) - 1.0);

		if (invLogValue > 255.0) invLogValue = 255.0;
		if (invLogValue < 0.0)   invLogValue = 0.0;

		lut[i] = (BYTE)(invLogValue + 0.5);
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // Blue
			pDstPixel[1] = lut[pSrcPixel[1]]; // Green
			pDstPixel[2] = lut[pSrcPixel[2]]; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessInverselogtransformation()
{
		Cproject1Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc || pDoc->m_image.IsNull())
			return;
	
		int height = pDoc->m_image.GetHeight();
		int pitch = pDoc->m_image.GetPitch();
		int absPitch = std::abs(pitch);
		size_t totalBytes = (size_t)absPitch * height;
	
		m_pixelBackupBuffer.resize(totalBytes);
		BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
		if (pitch < 0) {
			pImgBits += pitch * (height - 1);
		}
		std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);
	
		CInverseLogTransformDlg dlg(this);
		dlg.m_pView = this;
	
		if (dlg.DoModal() == IDOK)
		{
			pDoc->SetModifiedFlag(TRUE);
			pDoc->UpdateAllViews(NULL);
		}
		else
		{
			// Rollback on cancel
			std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
			pDoc->UpdateAllViews(NULL);
		}

}

void Cproject1View::OnPointprocessGrayslicing()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pImgBits += pitch * (height - 1);
	}
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CGraySlicingDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore untouched original on cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyLiveGraySlicing(int lowVal, int highVal, BOOL bPreserveBG)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pDstBase += pitch * (height - 1);
	}
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// Generate Fast Look-Up Table for Slicing mapping
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		if (i >= lowVal && i <= highVal)
		{
			lut[i] = 255; // Sliced range lights up to bright white
		}
		else
		{
			lut[i] = bPreserveBG ? (BYTE)i : 0; // Keep background original vs drop to black
		}
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// For RGB/Grayscale applications, evaluate intensity
			// If dealing with pure color images, calculating gray intensity maps perfectly
			BYTE intensity = (BYTE)(0.299 * pSrcPixel[2] + 0.587 * pSrcPixel[1] + 0.114 * pSrcPixel[0]);

			if (intensity >= lowVal && intensity <= highVal)
			{
				pDstPixel[0] = 255; // B
				pDstPixel[1] = 255; // G
				pDstPixel[2] = 255; // R
			}
			else
			{
				if (bPreserveBG)
				{
					pDstPixel[0] = pSrcPixel[0];
					pDstPixel[1] = pSrcPixel[1];
					pDstPixel[2] = pSrcPixel[2];
				}
				else
				{
					pDstPixel[0] = 0;
					pDstPixel[1] = 0;
					pDstPixel[2] = 0;
				}
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLivePseudoColor(int mapIndex, int shiftValue)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pDstBase += pitch * (height - 1);
	}
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// 1. Build Pre-calculated Look-Up Tables for Blue, Green, and Red channels
	BYTE lutB[256], lutG[256], lutR[256];

	for (int i = 0; i < 256; i++)
	{
		if (mapIndex == 0) // JET MAP (Blue -> Cyan -> Green -> Yellow -> Red)
		{
			// Red profile
			if (i < 96)       lutR[i] = 0;
			else if (i < 160) lutR[i] = (BYTE)(4 * (i - 96));
			else if (i < 224) lutR[i] = 255;
			else              lutR[i] = (BYTE)(255 - 4 * (i - 224));

			// Green profile
			if (i < 32)       lutG[i] = 0;
			else if (i < 96)  lutG[i] = (BYTE)(4 * (i - 32));
			else if (i < 160) lutG[i] = 255;
			else if (i < 224) lutG[i] = (BYTE)(255 - 4 * (i - 160));
			else              lutG[i] = 0;

			// Blue profile
			if (i < 32)       lutB[i] = (BYTE)(128 + 4 * i);
			else if (i < 96)  lutB[i] = 255;
			else if (i < 160) lutB[i] = (BYTE)(255 - 4 * (i - 96));
			else              lutB[i] = 0;
		}
		else if (mapIndex == 1) // HOT MAP (Black -> Red -> Yellow -> White)
		{
			lutR[i] = (i < 96) ? (BYTE)(i * 255 / 95) : 255;
			lutG[i] = (i < 96) ? 0 : ((i < 192) ? (BYTE)((i - 96) * 255 / 95) : 255);
			lutB[i] = (i < 192) ? 0 : (BYTE)((i - 192) * 255 / 63);
		}
		else // COOL MAP (Cyan to Magenta gradient)
		{
			lutR[i] = (BYTE)i;
			lutG[i] = (BYTE)(255 - i);
			lutB[i] = 255;
		}
	}

	// 2. Process image pixel channels using our maps
	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Calculate overall gray intensity step first to accurately map colors
			BYTE gray = (BYTE)(0.299 * pSrcPixel[2] + 0.587 * pSrcPixel[1] + 0.114 * pSrcPixel[0]);

			// Apply the slider shift value using modulo arithmetic to cycle smoothly
			int shiftedColorIndex = (gray + shiftValue) % 256;

			// Assign false color lookups directly to image memory bounds
			pDstPixel[0] = lutB[shiftedColorIndex]; // Blue
			pDstPixel[1] = lutG[shiftedColorIndex]; // Green
			pDstPixel[2] = lutR[shiftedColorIndex]; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

// Ensure proper spacing and separate function definitions
void Cproject1View::OnColorprocessPseudocoloring()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pImgBits += pitch * (height - 1);
	}
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CPseudoColorDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore untouched original on user cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}


// Computes the optimal threshold using Otsu's method given a 256-bin histogram
int Cproject1View::ComputeOtsuThreshold(const std::vector<int>& histogram, int totalPixels)
{
	double sumAll = 0;
	for (int i = 0; i < 256; i++)
		sumAll += i * histogram[i];

	double sumBackground = 0;
	int weightBackground = 0;
	int weightForeground = 0;

	double maxVariance = 0;
	int optimalThreshold = 0;

	for (int t = 0; t < 256; t++)
	{
		weightBackground += histogram[t];
		if (weightBackground == 0) continue;

		weightForeground = totalPixels - weightBackground;
		if (weightForeground == 0) break;

		sumBackground += (double)(t * histogram[t]);

		double meanBackground = sumBackground / weightBackground;
		double meanForeground = (sumAll - sumBackground) / weightForeground;

		// Between-class variance — Otsu's criterion to maximize
		double betweenVariance = (double)weightBackground * (double)weightForeground *
			(meanBackground - meanForeground) * (meanBackground - meanForeground);

		if (betweenVariance > maxVariance)
		{
			maxVariance = betweenVariance;
			optimalThreshold = t;
		}
	}

	return optimalThreshold;
}

void Cproject1View::OnPointprocessOtsuthreshold()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;

	if (bytesPerPixel < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	// Back up original pixels so Cancel can restore them, same pattern as Pseudo-Color
	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	// Build the grayscale histogram from the backup (the untouched original)
	std::vector<int> histogram(256, 0);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pSrcBase + (y * absPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			BYTE gray = (BYTE)(0.299 * pPixel[2] + 0.587 * pPixel[1] + 0.114 * pPixel[0]);
			histogram[gray]++;
		}
	}

	int totalPixels = width * height;
	int threshold = ComputeOtsuThreshold(histogram, totalPixels);

	// Show the preview dialog with the computed value
	COtsuThresholdDlg dlg(this);
	dlg.m_pView = this;
	dlg.m_computedThreshold = threshold;

	// Apply live preview immediately using the computed threshold
	ApplyOtsuThresholdWithValue(threshold);

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore original on Cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

// Applies binary thresholding at the given value directly to the doc's live bits
void Cproject1View::ApplyOtsuThresholdWithValue(int thresholdValue)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			BYTE gray = (BYTE)(0.299 * pSrcPixel[2] + 0.587 * pSrcPixel[1] + 0.114 * pSrcPixel[0]);
			BYTE binary = (gray > thresholdValue) ? 255 : 0;

			pDstPixel[0] = binary; // B
			pDstPixel[1] = binary; // G
			pDstPixel[2] = binary; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::RestoreOriginalPixels()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	// Safety check: buffer must match the image's current byte size,
	// otherwise a stale/mismatched backup could corrupt memory
	if (m_pixelBackupBuffer.size() != totalBytes)
		return;

	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) {
		pImgBits += pitch * (height - 1);
	}

	std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointprocessBinarythreshold()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	// Back up original pixels so Cancel can restore them
	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CBinaryThresholdDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Restore original on Cancel
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

// Applies binary thresholding at the given user-selected value, reading from
// the untouched backup and writing to the live doc bits, so repeated slider
// drags never compound on top of an already-thresholded image.
void Cproject1View::ApplyBinaryThreshold(int thresholdValue)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			BYTE gray = (BYTE)(0.299 * pSrcPixel[2] + 0.587 * pSrcPixel[1] + 0.114 * pSrcPixel[0]);

			// This is the core "if/else" logic the feature description asks for
			BYTE binary = (gray > thresholdValue) ? 255 : 0;

			pDstPixel[0] = binary; // B
			pDstPixel[1] = binary; // G
			pDstPixel[2] = binary; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessLevelsadjustment()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	// Back up original pixels so Cancel can restore them
	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CLevelsAdjustmentDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

// Applies the black-point/white-point/gamma remapping to each channel
// independently, reading from the untouched backup buffer so repeated
// slider drags never compound.
void Cproject1View::ApplyLevelsAdjustment(int blackPoint, int whitePoint, double gamma)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// Build a 256-entry LUT once, since black/white/gamma apply identically
	// to every pixel regardless of position — same optimization as your
	// Pseudo-Color feature's per-channel LUTs.
	BYTE lut[256];
	double range = (double)(whitePoint - blackPoint);
	if (range < 1.0) range = 1.0; // safety guard against divide-by-zero

	for (int i = 0; i < 256; i++)
	{
		double normalized = (i - blackPoint) / range;

		if (normalized < 0.0) normalized = 0.0;
		if (normalized > 1.0) normalized = 1.0;

		double output = 255.0 * pow(normalized, 1.0 / gamma);

		if (output < 0.0)   output = 0.0;
		if (output > 255.0) output = 255.0;

		lut[i] = (BYTE)(output + 0.5); // round to nearest
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Apply the same LUT to each channel independently —
			// this preserves color, unlike your grayscale-based features
			pDstPixel[0] = lut[pSrcPixel[0]]; // B
			pDstPixel[1] = lut[pSrcPixel[1]]; // G
			pDstPixel[2] = lut[pSrcPixel[2]]; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessSigmoidcontrast()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CSigmoidContrastDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

 //Applies an S-curve intensity mapping using gain (steepness) and midpoint
 //(curve center), rescaled so the endpoints always anchor to pure black/white.


void Cproject1View::ApplySigmoidContrast(double gain, int midpoint)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	double midNorm = midpoint / 255.0; // midpoint as 0.0-1.0

	// Precompute the sigmoid at the two extremes for endpoint rescaling
	double fAt0 = 1.0 / (1.0 + exp(gain * midNorm));
	double fAt1 = 1.0 / (1.0 + exp(-gain * (1.0 - midNorm)));
	double denom = fAt1 - fAt0;
	if (std::abs(denom) < 1e-6) denom = 1e-6; // safety guard against divide-by-zero

	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		double x = i / 255.0;
		double fx = 1.0 / (1.0 + exp(-gain * (x - midNorm)));

		double output = (fx - fAt0) / denom;

		if (output < 0.0) output = 0.0;
		if (output > 1.0) output = 1.0;

		lut[i] = (BYTE)(output * 255.0 + 0.5); // scale back to 0-255, round
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Apply to each channel independently — preserves color,
			// same principle as your Levels Adjustment feature
			pDstPixel[0] = lut[pSrcPixel[0]]; // B
			pDstPixel[1] = lut[pSrcPixel[1]]; // G
			pDstPixel[2] = lut[pSrcPixel[2]]; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplySepiaTone(double intensity)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			// Source is BGR order
			double B = pSrcPixel[0];
			double G = pSrcPixel[1];
			double R = pSrcPixel[2];

			// Classic sepia matrix
			double sepiaR = 0.393 * R + 0.769 * G + 0.189 * B;
			double sepiaG = 0.349 * R + 0.686 * G + 0.168 * B;
			double sepiaB = 0.272 * R + 0.534 * G + 0.131 * B;

			if (sepiaR > 255.0) sepiaR = 255.0;
			if (sepiaG > 255.0) sepiaG = 255.0;
			if (sepiaB > 255.0) sepiaB = 255.0;

			// Blend original and sepia by intensity
			double finalR = R * (1.0 - intensity) + sepiaR * intensity;
			double finalG = G * (1.0 - intensity) + sepiaG * intensity;
			double finalB = B * (1.0 - intensity) + sepiaB * intensity;

			pDstPixel[0] = (BYTE)(finalB + 0.5); // B
			pDstPixel[1] = (BYTE)(finalG + 0.5); // G
			pDstPixel[2] = (BYTE)(finalR + 0.5); // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointprocessSepiatone()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CSepiaToneDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}


void Cproject1View::ApplyCurvesLUT(const BYTE lut[256])
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			pDstPixel[0] = lut[pSrcPixel[0]]; // B
			pDstPixel[1] = lut[pSrcPixel[1]]; // G
			pDstPixel[2] = lut[pSrcPixel[2]]; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
} 

void Cproject1View::OnPointprocessCurvesadjustment()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CCurvesAdjustmentDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		// Standardized safe fallback restoration matching your HSI/HSL implementation
		if (!pDoc->m_imageOriginal.IsNull())
		{
			pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
			pDoc->m_image.ReleaseDC();
		}
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyChannelIsolation(int channel)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			BYTE B = pSrcPixel[0];
			BYTE G = pSrcPixel[1];
			BYTE R = pSrcPixel[2];

			// channel: 0=Red, 1=Green, 2=Blue - zero out the other two
			pDstPixel[0] = (channel == 2) ? B : 0; // Blue
			pDstPixel[1] = (channel == 1) ? G : 0; // Green
			pDstPixel[2] = (channel == 0) ? R : 0; // Red
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointprocessChannelisolation()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CChannelIsolationDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}


void Cproject1View::ApplyDuotone(COLORREF shadowColor, COLORREF highlightColor)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// Extract R/G/B from each COLORREF once, outside the pixel loop
	int shadowR = GetRValue(shadowColor);
	int shadowG = GetGValue(shadowColor);
	int shadowB = GetBValue(shadowColor);
	int highR = GetRValue(highlightColor);
	int highG = GetGValue(highlightColor);
	int highB = GetBValue(highlightColor);

	// Build a 256-entry LUT for each output channel, since the gradient
	// only depends on gray intensity, same optimization as your other features
	BYTE lutR[256], lutG[256], lutB[256];
	for (int i = 0; i < 256; i++)
	{
		double t = i / 255.0;
		lutR[i] = (BYTE)(shadowR + t * (highR - shadowR) + 0.5);
		lutG[i] = (BYTE)(shadowG + t * (highG - shadowG) + 0.5);
		lutB[i] = (BYTE)(shadowB + t * (highB - shadowB) + 0.5);
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			BYTE gray = (BYTE)(0.299 * pSrcPixel[2] + 0.587 * pSrcPixel[1] + 0.114 * pSrcPixel[0]);

			pDstPixel[0] = lutB[gray]; // B
			pDstPixel[1] = lutG[gray]; // G
			pDstPixel[2] = lutR[gray]; // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessDuotone()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CDuotoneDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}

}


void Cproject1View::ApplyGaussianNoise(int stdDev)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// If there's no noise to add, just copy the original through unchanged
	// and skip creating a normal_distribution entirely (sigma=0 is invalid).
	if (stdDev <= 0)
	{
		size_t totalBytes = (size_t)absPitch * height;
		std::memcpy(pDstBase, pSrcBase, totalBytes);
		Invalidate(FALSE);
		UpdateWindow();
		return;
	}

	std::normal_distribution<double> dist(0.0, (double)stdDev);

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			for (int c = 0; c < 3; c++)
			{
				double noise = dist(m_noiseGenerator);
				double result = pSrcPixel[c] + noise;

				if (result < 0.0)   result = 0.0;
				if (result > 255.0) result = 255.0;

				pDstPixel[c] = (BYTE)(result + 0.5);
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessGaussiannoise()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CGaussianNoiseDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplySaltPepperNoise(double probability)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	std::uniform_real_distribution<double> dist(0.0, 1.0);

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			double r = dist(m_noiseGenerator);

			if (probability > 0.0 && r < probability / 2.0)
			{
				// "Pepper" - pure black
				pDstPixel[0] = 0;
				pDstPixel[1] = 0;
				pDstPixel[2] = 0;
			}
			else if (probability > 0.0 && r < probability)
			{
				// "Salt" - pure white
				pDstPixel[0] = 255;
				pDstPixel[1] = 255;
				pDstPixel[2] = 255;
			}
			else
			{
				// Unaffected - copy through unchanged
				pDstPixel[0] = pSrcPixel[0];
				pDstPixel[1] = pSrcPixel[1];
				pDstPixel[2] = pSrcPixel[2];
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessSaltpeppernoise()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CSaltPepperNoiseDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyVignette(double strength)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	double centerX = width / 2.0;
	double centerY = height / 2.0;
	double maxDist = std::sqrt(centerX * centerX + centerY * centerY);
	if (maxDist < 1.0) maxDist = 1.0; // safety guard for tiny images

	for (int y = 0; y < height; y++)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		double dy = y - centerY;

		for (int x = 0; x < width; x++)
		{
			BYTE* pSrcPixel = pSrcRow + (x * bytesPerPixel);
			BYTE* pDstPixel = pDstRow + (x * bytesPerPixel);

			double dx = x - centerX;
			double dist = std::sqrt(dx * dx + dy * dy);
			double normalizedDist = dist / maxDist;

			double darkenFactor = 1.0 - (strength * normalizedDist * normalizedDist);
			if (darkenFactor < 0.0) darkenFactor = 0.0;
			if (darkenFactor > 1.0) darkenFactor = 1.0;

			pDstPixel[0] = (BYTE)(pSrcPixel[0] * darkenFactor + 0.5); // B
			pDstPixel[1] = (BYTE)(pSrcPixel[1] * darkenFactor + 0.5); // G
			pDstPixel[2] = (BYTE)(pSrcPixel[2] * darkenFactor + 0.5); // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointprocessVignette()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CVignetteDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyCmykFilter(int cOffset, int mOffset, int yOffset, int kOffset)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();

	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Convert -128..+128 slider range into a -1.0..+1.0 offset
	double offsetC = cOffset / 128.0;
	double offsetM = mOffset / 128.0;
	double offsetY = yOffset / 128.0;
	double offsetK = kOffset / 128.0;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0] / 255.0;
			double g = pPixel[1] / 255.0;
			double r = pPixel[2] / 255.0;

			double maxRGB = max(r, max(g, b));
			double k = 1.0 - maxRGB;
			double c = (k < 1.0) ? (1.0 - r - k) / (1.0 - k) : 0.0;
			double m = (k < 1.0) ? (1.0 - g - k) / (1.0 - k) : 0.0;
			double y_cmyk = (k < 1.0) ? (1.0 - b - k) / (1.0 - k) : 0.0;

			// Add the offset instead of scaling, then clamp
			c = max(0.0, min(1.0, c + offsetC));
			m = max(0.0, min(1.0, m + offsetM));
			y_cmyk = max(0.0, min(1.0, y_cmyk + offsetY));
			k = max(0.0, min(1.0, k + offsetK));

			double r_new = (1.0 - c) * (1.0 - k);
			double g_new = (1.0 - m) * (1.0 - k);
			double b_new = (1.0 - y_cmyk) * (1.0 - k);

			pPixel[0] = static_cast<BYTE>(max(0.0, min(1.0, b_new)) * 255.0 + 0.5);
			pPixel[1] = static_cast<BYTE>(max(0.0, min(1.0, g_new)) * 255.0 + 0.5);
			pPixel[2] = static_cast<BYTE>(max(0.0, min(1.0, r_new)) * 255.0 + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessCmyk()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	// 1. Instantiate the CMYK slider dialog frame
	CCmykDlg dlg;

	// 2. Link the dialog pointer live so it can talk back to this view canvas
	dlg.m_pView = this;

	// 3. Open the Dialog Window modally
	if (dlg.DoModal() == IDCANCEL)
	{
		// If the user clicks Cancel, discard live tweaks and restore original backup copy
		if (!pDoc->m_imageOriginal.IsNull())
		{
			pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
			pDoc->m_image.ReleaseDC();
		}

		// Repaint back to standard state
		Invalidate(FALSE);
	}
}

void Cproject1View::OnPointprocessQuantumsim()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull()) return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CQuantumSimDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

void Cproject1View::ApplyQuantumSim(int levels, double uncertainty)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty()) return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);

	BYTE* pDstBase = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pDstBase += pitch * (height - 1);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	if (levels < 2) levels = 2;
	double levelSize = 256.0 / levels;
	double sigma = (uncertainty > 0.001) ? uncertainty : 0.001;

	// 1. PRECOMPUTE WAVE FUNCTION LUT MATRIX
	// For every possible input intensity value (0-255), precalculate candidates and normalized ranges
	int lutNumCandidates[256];
	int lutCandidates[256][3];
	double lutProbs[256][3];

	for (int i = 0; i < 256; ++i)
	{
		double position = i / levelSize;
		int baseLevel = (int)std::floor(position);
		double probSum = 0.0;
		int numC = 0;

		for (int offset = -1; offset <= 1; ++offset)
		{
			int k = baseLevel + offset;
			if (k < 0 || k >= levels) continue;

			double diff = k - position;
			double prob = std::exp(-(diff * diff) / (2.0 * sigma * sigma));

			lutCandidates[i][numC] = k;
			lutProbs[i][numC] = prob;
			probSum += prob;
			numC++;
		}

		if (probSum < 1e-12) probSum = 1e-12;

		// Normalize and transform to cumulative probabilities to save calculation inside the loop
		double cumulative = 0.0;
		for (int cIdx = 0; cIdx < numC; ++cIdx)
		{
			cumulative += (lutProbs[i][cIdx] / probSum);
			lutProbs[i][cIdx] = cumulative;
		}
		lutNumCandidates[i] = numC;
	}

	std::uniform_real_distribution<double> dist(0.0, 1.0);

	// 2. OPTIMIZED PIXEL RUNNER
	for (int y = 0; y < height; ++y)
	{
		BYTE* pSrcRow = pSrcBase + (y * absPitch);
		BYTE* pDstRow = pDstBase + (y * absPitch);

		for (int x = 0; x < width; ++x)
		{
			int offset = x * bytesPerPixel;

			// Handle B, G, R components directly 
			for (int c = 0; c < 3; ++c)
			{
				BYTE inputVal = pSrcRow[offset + c];
				int numC = lutNumCandidates[inputVal];

				// Roll the quantum dice
				double r = dist(m_noiseGenerator);
				int collapsedLevel = lutCandidates[inputVal][0];

				for (int i = 0; i < numC; ++i)
				{
					if (r <= lutProbs[inputVal][i])
					{
						collapsedLevel = lutCandidates[inputVal][i];
						break;
					}
				}

				double output = collapsedLevel * levelSize + levelSize / 2.0;
				if (output < 0.0)   output = 0.0;
				if (output > 255.0) output = 255.0;

				pDstRow[offset + c] = (BYTE)(output + 0.5);
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessQuantumdpp()
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull())
		return;

	int bpp = pDoc->m_image.GetBPP();
	if (bpp / 8 < 3)
	{
		AfxMessageBox(_T("This feature requires a 24-bit or 32-bit color image."));
		return;
	}

	int height = pDoc->m_image.GetHeight();
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	size_t totalBytes = (size_t)absPitch * height;

	m_pixelBackupBuffer.resize(totalBytes);
	BYTE* pImgBits = (BYTE*)pDoc->m_image.GetBits();
	if (pitch < 0) pImgBits += pitch * (height - 1);
	std::memcpy(m_pixelBackupBuffer.data(), pImgBits, totalBytes);

	CQuantumDPPDlg dlg(this);
	dlg.m_pView = this;

	if (dlg.DoModal() == IDOK)
	{
		pDoc->SetModifiedFlag(TRUE);
		pDoc->UpdateAllViews(NULL);
	}
	else
	{
		std::memcpy(pImgBits, m_pixelBackupBuffer.data(), totalBytes);
		pDoc->UpdateAllViews(NULL);
	}
}

// Heuristic DPP-inspired stippling: places dots via weighted random
// sampling with local repulsion (mimicking DPP-style negative correlation
// between nearby points), plus a non-local "entangled" suppression rule
// that instantly reduces sampling probability near the mirrored position
// of each accepted point - a stylistic mechanic inspired by quantum
// entanglement's non-local correlation, NOT a real quantum computation
// or a rigorous spectral DPP sample.
void Cproject1View::ApplyQuantumDPP(int gridSpacing, int repulsionRadius, double entanglementStrength, int dotSize)
{
	Cproject1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc || pDoc->m_image.IsNull() || m_pixelBackupBuffer.empty())
		return;

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bytesPerPixel = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	int absPitch = std::abs(pitch);
	BYTE* pSrcBase = m_pixelBackupBuffer.data();

	// --- Step 1: cap total candidates for performance regardless of spacing ---
	const int MAX_CANDIDATES = 10000;
	double idealSpacing = std::sqrt((double)(width * height) / MAX_CANDIDATES);
	//int effectiveSpacing = (int)std::max((double)gridSpacing, std::ceil(idealSpacing));
	int effectiveSpacing = (int)(std::max)((double)gridSpacing, std::ceil(idealSpacing));
	if (effectiveSpacing < 2) effectiveSpacing = 2;

	// --- Step 2: build weighted candidate list (darker pixels = higher weight) ---
	struct QCandidate { int x, y; double weight; BYTE b, g, r; };
	std::vector<QCandidate> candidates;

	for (int y = 0; y < height; y += effectiveSpacing)
	{
		BYTE* pRow = pSrcBase + (y * absPitch);
		for (int x = 0; x < width; x += effectiveSpacing)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			BYTE b = pPixel[0], g = pPixel[1], r = pPixel[2];
			BYTE gray = (BYTE)(0.299 * r + 0.587 * g + 0.114 * b);

			double weight = (255.0 - gray) / 255.0 + 0.05; // small floor so light areas still get some dots
			candidates.push_back({ x, y, weight, b, g, r });
		}
	}

	if (candidates.empty())
		return;

	// --- Step 3: greedy weighted sampling with repulsion + entangled suppression ---
	std::vector<QCandidate> selectedPoints;
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	double repulsionSigma = repulsionRadius / 2.0;
	if (repulsionSigma < 0.5) repulsionSigma = 0.5;

	int safetyLimit = (int)candidates.size(); // never select more points than candidates exist
	int iterations = 0;

	while (iterations < safetyLimit)
	{
		iterations++;

		double totalWeight = 0.0;
		for (auto& c : candidates) totalWeight += c.weight;
		if (totalWeight < 1e-6) break; // everything sufficiently suppressed - stop

		double r = dist(m_noiseGenerator) * totalWeight;
		double cumulative = 0.0;
		int selectedIdx = -1;

		for (size_t i = 0; i < candidates.size(); i++)
		{
			cumulative += candidates[i].weight;
			if (r <= cumulative) { selectedIdx = (int)i; break; }
		}
		if (selectedIdx < 0) selectedIdx = (int)candidates.size() - 1;

		QCandidate chosen = candidates[selectedIdx];
		selectedPoints.push_back(chosen);
		candidates[selectedIdx].weight = 0.0;

		// --- Local repulsion: suppress nearby candidates (DPP-inspired) ---
		for (auto& c : candidates)
		{
			if (c.weight <= 0.0) continue;
			double dx = c.x - chosen.x;
			double dy = c.y - chosen.y;
			double distSq = dx * dx + dy * dy;
			if (distSq < (double)(repulsionRadius * repulsionRadius) * 4.0)
			{
				double factor = std::exp(-distSq / (2.0 * repulsionSigma * repulsionSigma));
				c.weight *= (1.0 - factor * 0.9); // never fully zero via repulsion alone
			}
		}

		// --- Non-local "entangled" suppression: mirror position through center ---
		if (entanglementStrength > 0.001)
		{
			int mirrorX = width - 1 - chosen.x;
			int mirrorY = height - 1 - chosen.y;

			for (auto& c : candidates)
			{
				if (c.weight <= 0.0) continue;
				double dx = c.x - mirrorX;
				double dy = c.y - mirrorY;
				double distSq = dx * dx + dy * dy;
				if (distSq < (double)(repulsionRadius * repulsionRadius) * 4.0)
				{
					double factor = std::exp(-distSq / (2.0 * repulsionSigma * repulsionSigma));
					c.weight *= (1.0 - factor * 0.9 * entanglementStrength);
				}
			}
		}
	}

	// --- Step 4: render the stippled result ---
	HDC hDC = pDoc->m_image.GetDC();
	CDC* pDC = CDC::FromHandle(hDC);

	CRect fullRect(0, 0, width, height);
	pDC->FillSolidRect(&fullRect, RGB(255, 255, 255)); // white canvas background

	for (const auto& pt : selectedPoints)
	{
		CBrush brush(RGB(pt.r, pt.g, pt.b));
		CBrush* pOldBrush = pDC->SelectObject(&brush);
		CPen pen(PS_NULL, 0, RGB(pt.r, pt.g, pt.b)); // no visible outline
		CPen* pOldPen = pDC->SelectObject(&pen);

		pDC->Ellipse(pt.x - dotSize, pt.y - dotSize, pt.x + dotSize, pt.y + dotSize);

		pDC->SelectObject(pOldPen);
		pDC->SelectObject(pOldBrush);
	}

	pDoc->m_image.ReleaseDC();

	Invalidate(FALSE);
	UpdateWindow();
}

BOOL Cproject1View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull())
		return CScrollView::OnMouseWheel(nFlags, zDelta, pt);

	// ⭐ FIX: Handle breaking out of Fit to Window BEFORE doing coordinate math
	if (m_bFitToWindow)
	{
		m_bFitToWindow = FALSE;

		// Reinitialize CScrollView's canvas sizes to match your true fitted zoom factor.
		// This ensures GetScrollPosition() and internal dimensions report correctly.
		int imgWidth = pDoc->m_image.GetWidth();
		int imgHeight = pDoc->m_image.GetHeight();
		CSize currentFitSize((int)(imgWidth * m_zoomFactor), (int)(imgHeight * m_zoomFactor));
		SetScrollSizes(MM_TEXT, currentFitSize);
	}

	// Convert the cursor's screen position to this view's client coordinates
	CPoint ptClient(pt);
	ScreenToClient(&ptClient);

	// Figure out which exact IMAGE pixel is currently under the cursor...
	CPoint scrollPos = GetScrollPosition();
	double imgX = (scrollPos.x + ptClient.x) / m_zoomFactor;
	double imgY = (scrollPos.y + ptClient.y) / m_zoomFactor;

	// Adjust the zoom factor - 10% per wheel notch
	const double zoomStep = 1.1;
	if (zDelta > 0)
		m_zoomFactor *= zoomStep;
	else
		m_zoomFactor /= zoomStep;

	// Clamp to a sensible range: 10% to 800%
	if (m_zoomFactor < 0.1) m_zoomFactor = 0.1;
	if (m_zoomFactor > 8.0) m_zoomFactor = 8.0;

	// Resize the scrollable "virtual canvas" to match the new zoom level
	int imgWidth = pDoc->m_image.GetWidth();
	int imgHeight = pDoc->m_image.GetHeight();
	CSize newDocSize((int)(imgWidth* m_zoomFactor), (int)(imgHeight* m_zoomFactor));
	SetScrollSizes(MM_TEXT, newDocSize);

	// Recompute where that same image pixel now sits at the new zoom level,
	// then scroll so it lands back under the cursor
	CPoint docPtAfter((int)(imgX* m_zoomFactor), (int)(imgY* m_zoomFactor));
	CPoint newScrollPos(docPtAfter.x - ptClient.x, docPtAfter.y - ptClient.y);

	if (newScrollPos.x < 0) newScrollPos.x = 0;
	if (newScrollPos.y < 0) newScrollPos.y = 0;

	ScrollToPosition(newScrollPos);

	Invalidate(FALSE);
	return TRUE;
}


void Cproject1View::RevertToOriginal()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplyLiveColorize(int hue, int saturationPercent)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first — same discipline as your other live filters
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	double h = hue / 360.0;              // normalize hue to 0-1
	double s = saturationPercent / 100.0; // normalize saturation to 0-1

	auto HueToRGB = [](double p, double q, double t) {
		if (t < 0.0) t += 1.0;
		if (t > 1.0) t -= 1.0;
		if (t < 1.0 / 6.0) return p + (q - p) * 6.0 * t;
		if (t < 1.0 / 2.0) return q;
		if (t < 2.0 / 3.0) return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
		return p;
		};

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0] / 255.0;
			double g = pPixel[1] / 255.0;
			double r = pPixel[2] / 255.0;

			// --- Compute luminance (perceived brightness) — this becomes our L ---
			double l = 0.299 * r + 0.587 * g + 0.114 * b;

			// --- Build RGB from fixed Hue/Saturation + this pixel's own Lightness ---
			double newR, newG, newB;

			if (s == 0.0)
			{
				// Zero saturation = pure grayscale, no tint at all
				newR = newG = newB = l;
			}
			else
			{
				double q = (l < 0.5) ? (l * (1.0 + s)) : (l + s - l * s);
				double p = 2.0 * l - q;

				newR = HueToRGB(p, q, h + 1.0 / 3.0);
				newG = HueToRGB(p, q, h);
				newB = HueToRGB(p, q, h - 1.0 / 3.0);
			}

			pPixel[0] = (BYTE)(newB * 255.0 + 0.5);
			pPixel[1] = (BYTE)(newG * 255.0 + 0.5);
			pPixel[2] = (BYTE)(newR * 255.0 + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessColorize()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CColorizeDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	// Commit the effect permanently into m_imageOriginal, same pattern as your CIELab handler
	pDoc->m_image.BitBlt(pDoc->m_imageOriginal.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_imageOriginal.ReleaseDC();

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplyLiveVibrance(int amount)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first — same discipline as your other live filters
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	double vibAmount = amount / 100.0;   // -1.0 to 1.0

	auto HueToRGB = [](double p, double q, double t) {
		if (t < 0.0) t += 1.0;
		if (t > 1.0) t -= 1.0;
		if (t < 1.0 / 6.0) return p + (q - p) * 6.0 * t;
		if (t < 1.0 / 2.0) return q;
		if (t < 2.0 / 3.0) return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
		return p;
		};

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0] / 255.0;
			double g = pPixel[1] / 255.0;
			double r = pPixel[2] / 255.0;

			// --- RGB to HSL ---
			double maxColor = max(r, max(g, b));
			double minColor = min(r, min(g, b));
			double delta = maxColor - minColor;

			double h = 0.0, s = 0.0, l = (maxColor + minColor) / 2.0;

			if (delta != 0.0)
			{
				s = (l <= 0.5) ? (delta / (maxColor + minColor)) : (delta / (2.0 - maxColor - minColor));

				if (maxColor == r)
					h = (g - b) / delta + (g < b ? 6.0 : 0.0);
				else if (maxColor == g)
					h = (b - r) / delta + 2.0;
				else
					h = (r - g) / delta + 4.0;

				h /= 6.0; // normalize to 0-1
			}

			// --- The key vibrance formula: boost scales DOWN as saturation increases ---
			double newS = s + (vibAmount * (1.0 - s));
			newS = max(0.0, min(1.0, newS));

			// --- HSL back to RGB (lightness stays exactly as-is) ---
			double newR = l, newG = l, newB = l;

			if (newS != 0.0)
			{
				double q = (l < 0.5) ? (l * (1.0 + newS)) : (l + newS - l * newS);
				double p = 2.0 * l - q;

				newR = HueToRGB(p, q, h + 1.0 / 3.0);
				newG = HueToRGB(p, q, h);
				newB = HueToRGB(p, q, h - 1.0 / 3.0);
			}

			pPixel[0] = (BYTE)(newB * 255.0 + 0.5);
			pPixel[1] = (BYTE)(newG * 255.0 + 0.5);
			pPixel[2] = (BYTE)(newR * 255.0 + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessVibrance()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CVibranceDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	pDoc->m_image.BitBlt(pDoc->m_imageOriginal.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_imageOriginal.ReleaseDC();

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveWhiteBalance(int temperature, int tint)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Temperature: scale factor for Red vs Blue (opposite directions)
	// Positive temperature = warmer (boost R, reduce B); negative = cooler (boost B, reduce R)
	double tempShift = (temperature / 100.0) * 60.0;   // up to +-60 units on R/B

	// Tint: scale factor for Green vs Red+Blue (opposite directions)
	// Positive tint = magenta (boost R and B, reduce G); negative = green (boost G, reduce R and B)
	double tintShift = (tint / 100.0) * 60.0;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);

		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0];
			double g = pPixel[1];
			double r = pPixel[2];

			// --- Temperature: R up / B down, or vice versa ---
			r += tempShift;
			b -= tempShift;

			// --- Tint: G up / R+B down, or vice versa ---
			g += tintShift;
			r -= tintShift * 0.5;
			b -= tintShift * 0.5;

			// --- Clamp to valid byte range ---
			r = max(0.0, min(255.0, r));
			g = max(0.0, min(255.0, g));
			b = max(0.0, min(255.0, b));

			pPixel[0] = (BYTE)(b + 0.5);
			pPixel[1] = (BYTE)(g + 0.5);
			pPixel[2] = (BYTE)(r + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessWhitebalance()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CWhiteBalanceDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	pDoc->m_image.BitBlt(pDoc->m_imageOriginal.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_imageOriginal.ReleaseDC();

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessAutolevels()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	// Restore pristine original first, then compute + apply the stretch on top of it
	pDoc->m_imageOriginal.BitBlt(pDoc->m_image.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_image.ReleaseDC();

	int width = pDoc->m_image.GetWidth();
	int height = pDoc->m_image.GetHeight();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// --- Pass 1: find min/max for each channel independently ---
	BYTE minR = 255, maxR = 0;
	BYTE minG = 255, maxG = 0;
	BYTE minB = 255, maxB = 0;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			BYTE b = pPixel[0];
			BYTE g = pPixel[1];
			BYTE r = pPixel[2];

			if (b < minB) minB = b;
			if (b > maxB) maxB = b;
			if (g < minG) minG = g;
			if (g > maxG) maxG = g;
			if (r < minR) minR = r;
			if (r > maxR) maxR = r;
		}
	}

	// --- Guard against flat/degenerate channels (avoid divide-by-zero) ---
	int rangeR = maxR - minR; if (rangeR == 0) rangeR = 1;
	int rangeG = maxG - minG; if (rangeG == 0) rangeG = 1;
	int rangeB = maxB - minB; if (rangeB == 0) rangeB = 1;

	// --- Pass 2: apply the stretch: newValue = (value - min) * 255 / range ---
	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * pitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			int b = pPixel[0];
			int g = pPixel[1];
			int r = pPixel[2];

			int newB = ((b - minB) * 255) / rangeB;
			int newG = ((g - minG) * 255) / rangeG;
			int newR = ((r - minR) * 255) / rangeR;

			newB = max(0, min(255, newB));
			newG = max(0, min(255, newG));
			newR = max(0, min(255, newR));

			pPixel[0] = (BYTE)newB;
			pPixel[1] = (BYTE)newG;
			pPixel[2] = (BYTE)newR;
		}
	}

	// Commit permanently into m_imageOriginal, same pattern as your other one-shot filters
	pDoc->m_image.BitBlt(pDoc->m_imageOriginal.GetDC(), 0, 0, SRCCOPY);
	pDoc->m_imageOriginal.ReleaseDC();

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplyLiveColorReplace(COLORREF targetColor, COLORREF replaceColor, int tolerance)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// 1. Restore pristine original first using high-speed block copy
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	// 2. Extract targets
	int targetR = GetRValue(targetColor);
	int targetG = GetGValue(targetColor);
	int targetB = GetBValue(targetColor);

	int replaceR = GetRValue(replaceColor);
	int replaceG = GetGValue(replaceColor);
	int replaceB = GetBValue(replaceColor);

	// Precalculate squared tolerance to completely remove 'sqrt' from the loop
	double tol = (double)tolerance;
	if (tol < 1.0) tol = 1.0;
	double tolSq = tol * tol;

	// 3. Fire up the high-speed processing template!
	ProcessPixels([=](BYTE& b, BYTE& g, BYTE& r)
		{
			int dr = r - targetR;
			int dg = g - targetG;
			int db = b - targetB;

			// Squared Euclidean distance calculation
			double distSq = (double)(dr * dr + dg * dg + db * db);

			if (distSq <= tolSq)
			{
				// Soft blend calculation using fast square roots only when a pixel qualifies
				double dist = sqrt(distSq);
				double blendFactor = 1.0 - (dist / tol);

				r = (BYTE)max(0, min(255, (int)(r + (replaceR - r) * blendFactor)));
				g = (BYTE)max(0, min(255, (int)(g + (replaceG - g) * blendFactor)));
				b = (BYTE)max(0, min(255, (int)(b + (replaceB - b) * blendFactor)));
			}
		});

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessColorreplace()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CColorReplaceDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already cleanly reverted m_image via block copy

	// OK Clicked: Synchronize the pristine original backup with our final image state safely
	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::StartColorPickerTracking(CColorReplaceDlg* pDlg)
{
	m_pColorPickerDlg = pDlg;
	s_pActiveColorPickerView = this;
	s_hColorPickerHook = SetWindowsHookEx(WH_MOUSE_LL, ColorPickerHookProc, AfxGetInstanceHandle(), 0);
}

void Cproject1View::StopColorPickerTracking()
{
	if (s_hColorPickerHook)
	{
		UnhookWindowsHookEx(s_hColorPickerHook);
		s_hColorPickerHook = NULL;
	}
	s_pActiveColorPickerView = nullptr;
	m_pColorPickerDlg = nullptr;
}

LRESULT CALLBACK Cproject1View::ColorPickerHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0 && s_pActiveColorPickerView != nullptr)
	{
		MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
		CPoint screenPt(pMouseStruct->pt.x, pMouseStruct->pt.y);

		if (wParam == WM_MOUSEMOVE)
		{
			s_pActiveColorPickerView->HandleColorPickerHover(screenPt);
		}
		else if (wParam == WM_LBUTTONDOWN)
		{
			BOOL bHandled = s_pActiveColorPickerView->HandleColorPickerClick(screenPt);
			if (bHandled)
				return 1; // swallow only clicks that actually landed on the canvas
		}
	}

	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

// Checks whether a screen point is currently over the (still-visible, non-modal-hidden) dialog,
// since the dialog no longer hides itself and may visually overlap the canvas.
BOOL Cproject1View::IsScreenPointOverDialog(CPoint screenPt)
{
	if (m_pColorPickerDlg && ::IsWindow(m_pColorPickerDlg->GetSafeHwnd()))
	{
		CRect dlgRect;
		m_pColorPickerDlg->GetWindowRect(&dlgRect);
		if (dlgRect.PtInRect(screenPt))
			return TRUE;
	}
	return FALSE;
}

BOOL Cproject1View::GetPixelColorAtScreenPoint(CPoint screenPt, COLORREF& outColor)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull()) return FALSE;

	CPoint clientPt = screenPt;
	ScreenToClient(&clientPt);

	CRect rectClient;
	GetClientRect(&rectClient);
	if (!rectClient.PtInRect(clientPt)) return FALSE;

	int imgWidth = pDoc->m_image.GetWidth();
	int imgHeight = pDoc->m_image.GetHeight();

	int pixelX, pixelY;

	if (m_bFitToWindow)
	{
		double destAspect = (double)rectClient.Width() / rectClient.Height();
		double srcAspect = (double)imgWidth / imgHeight;
		int drawWidth = rectClient.Width();
		int drawHeight = rectClient.Height();
		int startX = 0, startY = 0;

		if (destAspect > srcAspect)
		{
			drawWidth = (int)(rectClient.Height() * srcAspect);
			startX = (rectClient.Width() - drawWidth) / 2;
		}
		else
		{
			drawHeight = (int)(rectClient.Width() / srcAspect);
			startY = (rectClient.Height() - drawHeight) / 2;
		}

		pixelX = (int)((clientPt.x - startX) * ((double)imgWidth / drawWidth));
		pixelY = (int)((clientPt.y - startY) * ((double)imgHeight / drawHeight));
	}
	else
	{
		CPoint scrollPos = GetScrollPosition();
		pixelX = clientPt.x + scrollPos.x;
		pixelY = clientPt.y + scrollPos.y;
	}

	if (pixelX < 0 || pixelX >= imgWidth || pixelY < 0 || pixelY >= imgHeight)
		return FALSE;

	int bpp = pDoc->m_image.GetBPP() / 8;
	int pitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	BYTE* pPixel = pBits + (pixelY * pitch) + (pixelX * bpp);
	outColor = RGB(pPixel[2], pPixel[1], pPixel[0]);
	return TRUE;
}

void Cproject1View::HandleColorPickerHover(CPoint screenPt)
{
	if (IsScreenPointOverDialog(screenPt))
		return; // over the dialog — let it manage its own cursor/hover normally

	COLORREF color;
	if (GetPixelColorAtScreenPoint(screenPt, color))
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		if (m_pColorPickerDlg)
			m_pColorPickerDlg->OnHoverColorUpdate(color);
	}
}

BOOL Cproject1View::HandleColorPickerClick(CPoint screenPt)
{
	if (IsScreenPointOverDialog(screenPt))
		return FALSE; // not our click — let the dialog's own controls handle it normally

	COLORREF color;
	if (GetPixelColorAtScreenPoint(screenPt, color))
	{
		if (m_pColorPickerDlg)
			m_pColorPickerDlg->OnEyedropperColorPicked(color);
		return TRUE; // handled — swallow so it doesn't do anything else
	}

	return FALSE; // clicked inside the view but outside actual image bounds
}

void Cproject1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CView::OnLButtonDown(nFlags, point);
}

void Cproject1View::ApplyLiveExposure(int exposureStops100)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first — same discipline as your other live filters
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Convert stops (as an integer *100) into the actual multiplier: 2^stops
	double stops = exposureStops100 / 100.0;
	double multiplier = pow(2.0, stops);

	// Precompute a 256-entry lookup table — same optimization idea as your LAB LUT
	BYTE lut[256];
	for (int i = 0; i < 256; i++)
	{
		double v = i * multiplier;
		v = max(0.0, min(255.0, v));
		lut[i] = (BYTE)(v + 0.5);
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			pPixel[0] = lut[pPixel[0]];   // B
			pPixel[1] = lut[pPixel[1]];   // G
			pPixel[2] = lut[pPixel[2]];   // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}




void Cproject1View::OnPointprocessExposure()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CExposureDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessAutowhitebalance()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	// Restore pristine original first, then compute + apply the correction on top of it
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// --- Pass 1: compute average R, G, B across the whole image ---
	double sumR = 0.0, sumG = 0.0, sumB = 0.0;
	long long pixelCount = (long long)width * height;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			sumB += pPixel[0];
			sumG += pPixel[1];
			sumR += pPixel[2];
		}
	}

	double avgR = sumR / pixelCount;
	double avgG = sumG / pixelCount;
	double avgB = sumB / pixelCount;

	// Guard against a fully black image (avoid divide-by-zero)
	if (avgR < 1.0) avgR = 1.0;
	if (avgG < 1.0) avgG = 1.0;
	if (avgB < 1.0) avgB = 1.0;

	// --- The Gray World correction: target = overall average brightness ---
	double avgGray = (avgR + avgG + avgB) / 3.0;

	double scaleR = avgGray / avgR;
	double scaleG = avgGray / avgG;
	double scaleB = avgGray / avgB;

	// --- Pass 2: apply per-channel scale via lookup tables (fast, same idea as your Exposure LUT) ---
	BYTE lutR[256], lutG[256], lutB[256];
	for (int i = 0; i < 256; i++)
	{
		lutR[i] = (BYTE)max(0.0, min(255.0, i * scaleR + 0.5));
		lutG[i] = (BYTE)max(0.0, min(255.0, i * scaleG + 0.5));
		lutB[i] = (BYTE)max(0.0, min(255.0, i * scaleB + 0.5));
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			pPixel[0] = lutB[pPixel[0]];
			pPixel[1] = lutG[pPixel[1]];
			pPixel[2] = lutR[pPixel[2]];
		}
	}

	// Commit permanently into m_imageOriginal, same pattern as your other one-shot filters
	int commitPitch = pDoc->m_image.GetPitch();
	BYTE* pCommitSrc = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pCommitDst = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (commitPitch < 0) {
		memcpy(pCommitDst + (commitPitch * (height - 1)), pCommitSrc + (commitPitch * (height - 1)), abs(commitPitch) * height);
	}
	else {
		memcpy(pCommitDst, pCommitSrc, commitPitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplyLiveLuv(int deltaL, int deltaU, int deltaV)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	InitSrgbLUT();

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			BYTE Bb = pPixel[0], Gb = pPixel[1], Rb = pPixel[2];

			// --- RGB -> XYZ (using your existing LUT) ---
			double rl = g_srgbToLinearLUT[Rb];
			double gl = g_srgbToLinearLUT[Gb];
			double bl = g_srgbToLinearLUT[Bb];

			double X = rl * 0.4124564 + gl * 0.3575761 + bl * 0.1804375;
			double Y = rl * 0.2126729 + gl * 0.7151522 + bl * 0.0721750;
			double Z = rl * 0.0193339 + gl * 0.1191920 + bl * 0.9503041;

			// --- XYZ -> LUV ---
			double denom = X + 15.0 * Y + 3.0 * Z;
			double u_prime = (denom > 1e-10) ? (4.0 * X) / denom : 0.0;
			double v_prime = (denom > 1e-10) ? (9.0 * Y) / denom : 0.0;

			double yr = Y * 100.0 / Yn;   // scale to 0-100 range, matching Xn/Yn/Zn convention
			double L = LabF(yr / 100.0) * 116.0 - 16.0;
			if (L < 0.0) L = 0.0;

			double U = 13.0 * L * (u_prime - un_prime);
			double V = 13.0 * L * (v_prime - vn_prime);

			// --- Apply slider deltas ---
			L += deltaL;
			U += deltaU;
			V += deltaV;

			L = max(0.0, min(100.0, L));

			// --- LUV -> XYZ ---
			double Y2;
			if (L > 8.0)
				Y2 = Yn * pow((L + 16.0) / 116.0, 3.0);
			else
				Y2 = Yn * (L / 903.3);

			double u2_prime = (L > 1e-6) ? (U / (13.0 * L) + un_prime) : un_prime;
			double v2_prime = (L > 1e-6) ? (V / (13.0 * L) + vn_prime) : vn_prime;

			double X2, Z2;
			if (v2_prime > 1e-10)
			{
				X2 = Y2 * (9.0 * u2_prime) / (4.0 * v2_prime);
				Z2 = Y2 * (12.0 - 3.0 * u2_prime - 20.0 * v2_prime) / (4.0 * v2_prime);
			}
			else
			{
				X2 = 0.0;
				Z2 = 0.0;
			}

			// --- XYZ -> RGB ---
			double rl2 = (X2 / 100.0) * 3.2404542 + (Y2 / 100.0) * -1.5371385 + (Z2 / 100.0) * -0.4985314;
			double gl2 = (X2 / 100.0) * -0.9692660 + (Y2 / 100.0) * 1.8760108 + (Z2 / 100.0) * 0.0415560;
			double bl2 = (X2 / 100.0) * 0.0556434 + (Y2 / 100.0) * -0.2040259 + (Z2 / 100.0) * 1.0572252;

			pPixel[0] = (BYTE)(LinearToSrgb(bl2) + 0.5);
			pPixel[1] = (BYTE)(LinearToSrgb(gl2) + 0.5);
			pPixel[2] = (BYTE)(LinearToSrgb(rl2) + 0.5);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}
void Cproject1View::OnPointprocessCieluv()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CLuvDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveLiftGammaGain(
	int liftR100, int liftG100, int liftB100,
	int gammaR100, int gammaG100, int gammaB100,
	int gainR100, int gainG100, int gainB100)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// Convert scaled slider integers into real values
	double liftR = liftR100 / 100.0, liftG = liftG100 / 100.0, liftB = liftB100 / 100.0;
	double gammaR = gammaR100 / 100.0, gammaG = gammaG100 / 100.0, gammaB = gammaB100 / 100.0;
	double gainR = gainR100 / 100.0, gainG = gainG100 / 100.0, gainB = gainB100 / 100.0;

	// Guard against zero/negative gamma (would blow up pow())
	if (gammaR < 0.01) gammaR = 0.01;
	if (gammaG < 0.01) gammaG = 0.01;
	if (gammaB < 0.01) gammaB = 0.01;

	// Precompute a 256-entry LUT per channel — same optimization as your Exposure/AutoWB filters
	BYTE lutR[256], lutG[256], lutB[256];

	auto buildLut = [](BYTE* lut, double lift, double gamma, double gain)
		{
			double invGamma = 1.0 / gamma;
			for (int i = 0; i < 256; i++)
			{
				double v = i / 255.0;                  // normalize to 0-1
				v = v * gain + lift;                    // apply gain (highlights) and lift (shadows)
				if (v < 0.0) v = 0.0;                    // clamp before pow() to avoid NaN on negative base
				v = pow(v, invGamma);                   // apply gamma (midtones)
				v *= 255.0;
				v = max(0.0, min(255.0, v));
				lut[i] = (BYTE)(v + 0.5);
			}
		};

	buildLut(lutR, liftR, gammaR, gainR);
	buildLut(lutG, liftG, gammaG, gainG);
	buildLut(lutB, liftB, gammaB, gainB);

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			pPixel[0] = lutB[pPixel[0]];   // B
			pPixel[1] = lutG[pPixel[1]];   // G
			pPixel[2] = lutR[pPixel[2]];   // R
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessLiftgammagain()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CLiftGammaGainDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::StartColorPickerTracking2(CColorPopDlg* pDlg)
{
	m_pColorPopDlg = pDlg;
	s_pActiveColorPickerView2 = this;
	s_hColorPickerHook2 = SetWindowsHookEx(WH_MOUSE_LL, ColorPickerHookProc2, AfxGetInstanceHandle(), 0);
}

void Cproject1View::StopColorPickerTracking2()
{
	if (s_hColorPickerHook2)
	{
		UnhookWindowsHookEx(s_hColorPickerHook2);
		s_hColorPickerHook2 = NULL;
	}
	s_pActiveColorPickerView2 = nullptr;
	m_pColorPopDlg = nullptr;
}

LRESULT CALLBACK Cproject1View::ColorPickerHookProc2(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0 && s_pActiveColorPickerView2 != nullptr)
	{
		MSLLHOOKSTRUCT* pMouseStruct = (MSLLHOOKSTRUCT*)lParam;
		CPoint screenPt(pMouseStruct->pt.x, pMouseStruct->pt.y);

		if (wParam == WM_MOUSEMOVE)
		{
			s_pActiveColorPickerView2->HandleColorPickerHover2(screenPt);
		}
		else if (wParam == WM_LBUTTONDOWN)
		{
			BOOL bHandled = s_pActiveColorPickerView2->HandleColorPickerClick2(screenPt);
			if (bHandled)
				return 1;
		}
	}
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}

BOOL Cproject1View::IsScreenPointOverDialog2(CPoint screenPt)
{
	if (m_pColorPopDlg && ::IsWindow(m_pColorPopDlg->GetSafeHwnd()))
	{
		CRect dlgRect;
		m_pColorPopDlg->GetWindowRect(&dlgRect);
		if (dlgRect.PtInRect(screenPt))
			return TRUE;
	}
	return FALSE;
}

void Cproject1View::HandleColorPickerHover2(CPoint screenPt)
{
	if (IsScreenPointOverDialog2(screenPt))
		return;

	COLORREF color;
	if (GetPixelColorAtScreenPoint(screenPt, color))   // reused from your existing Color Replace code
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
		if (m_pColorPopDlg)
			m_pColorPopDlg->OnHoverColorUpdate(color);
	}
}

BOOL Cproject1View::HandleColorPickerClick2(CPoint screenPt)
{
	if (IsScreenPointOverDialog2(screenPt))
		return FALSE;

	COLORREF color;
	if (GetPixelColorAtScreenPoint(screenPt, color))
	{
		if (m_pColorPopDlg)
			m_pColorPopDlg->OnEyedropperColorPicked(color);
		return TRUE;
	}
	return FALSE;
}

void Cproject1View::ApplyLiveColorPop(COLORREF targetColor, int hueTolerance)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// --- Compute target hue (0-360) from targetColor ---
	int tr = GetRValue(targetColor), tg = GetGValue(targetColor), tb = GetBValue(targetColor);
	double trf = tr / 255.0, tgf = tg / 255.0, tbf = tb / 255.0;

	double tMax = max(trf, max(tgf, tbf));
	double tMin = min(trf, min(tgf, tbf));
	double tDelta = tMax - tMin;

	double targetHue = 0.0;
	if (tDelta > 0.0001)
	{
		if (tMax == trf)      targetHue = fmod(((tgf - tbf) / tDelta), 6.0);
		else if (tMax == tgf) targetHue = ((tbf - trf) / tDelta) + 2.0;
		else                  targetHue = ((trf - tgf) / tDelta) + 4.0;
		targetHue *= 60.0;
		if (targetHue < 0.0) targetHue += 360.0;
	}
	// If target color is itself gray/neutral (tDelta near 0), targetHue stays 0 — an edge case,
	// but a reasonable fallback since there's no meaningful hue to isolate anyway.

	double tol = (double)hueTolerance;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			double b = pPixel[0] / 255.0;
			double g = pPixel[1] / 255.0;
			double r = pPixel[2] / 255.0;

			double maxC = max(r, max(g, b));
			double minC = min(r, min(g, b));
			double delta = maxC - minC;

			double hue = 0.0;
			if (delta > 0.0001)
			{
				if (maxC == r)      hue = fmod(((g - b) / delta), 6.0);
				else if (maxC == g) hue = ((b - r) / delta) + 2.0;
				else                hue = ((r - g) / delta) + 4.0;
				hue *= 60.0;
				if (hue < 0.0) hue += 360.0;
			}

			// --- Circular hue distance (wraparound-aware, e.g. 350 vs 10 = 20 apart, not 340) ---
			double hueDist = fabs(hue - targetHue);
			if (hueDist > 180.0) hueDist = 360.0 - hueDist;

			// --- Grayscale luminance for this pixel (used when outside tolerance) ---
			BYTE gray = (BYTE)(0.299 * pPixel[2] + 0.587 * pPixel[1] + 0.114 * pPixel[0] + 0.5);

			if (hueDist <= tol)
			{
				// Within range — keep full color, pixel unchanged
			}
			else
			{
				// Outside range — soft blend toward grayscale near the edge for a smooth transition
				double blendZone = 20.0; // degrees of soft falloff beyond the hard tolerance
				double blendFactor = min(1.0, (hueDist - tol) / blendZone);

				pPixel[0] = (BYTE)(pPixel[0] + (gray - pPixel[0]) * blendFactor);
				pPixel[1] = (BYTE)(pPixel[1] + (gray - pPixel[1]) * blendFactor);
				pPixel[2] = (BYTE)(pPixel[2] + (gray - pPixel[2]) * blendFactor);
			}
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessColorpop()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CColorPopDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveBleachBypass(int intensityPercent)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();
	size_t totalBytes = (size_t)abs(pitch) * height;

	// Safe buffer restore for both top-down and bottom-up DIBs
	if (pitch < 0) {
		BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
		BYTE* pDstStart = pDstBits + (pitch * (height - 1));
		memcpy(pDstStart, pSrcStart, totalBytes);
	}
	else {
		memcpy(pDstBits, pSrcBits, totalBytes);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return; // Only process true-color images (24bpp / 32bpp)

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	double intensity = intensityPercent / 100.0; // 0.0 to 1.0 overall blend strength

	// --- Precompute S-curve contrast LUT ---
	double steepness = 6.0;
	BYTE contrastLut[256];
	double minCurve = 1.0 / (1.0 + exp(steepness));
	double maxCurve = 1.0 / (1.0 + exp(-steepness));

	for (int i = 0; i < 256; i++)
	{
		double x = (i - 127.5) / 127.5;
		double curved = 1.0 / (1.0 + exp(-steepness * x));
		double normalized = (curved - minCurve) / (maxCurve - minCurve);
		contrastLut[i] = (BYTE)max(0.0, min(255.0, normalized * 255.0 + 0.5));
	}

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			BYTE origB = pPixel[0];
			BYTE origG = pPixel[1];
			BYTE origR = pPixel[2];

			// Step 1: partial desaturation toward luminance
			BYTE gray = (BYTE)(0.299 * origR + 0.587 * origG + 0.114 * origB + 0.5);

			double desatAmount = 0.6;
			double b1 = origB + (gray - origB) * desatAmount;
			double g1 = origG + (gray - origG) * desatAmount;
			double r1 = origR + (gray - origR) * desatAmount;

			// Step 2: apply S-curve contrast boost
			BYTE b2 = contrastLut[(BYTE)(b1 + 0.5)];
			BYTE g2 = contrastLut[(BYTE)(g1 + 0.5)];
			BYTE r2 = contrastLut[(BYTE)(r1 + 0.5)];

			// Step 3: blend against original
			pPixel[0] = (BYTE)(origB + (b2 - origB) * intensity);
			pPixel[1] = (BYTE)(origG + (g2 - origG) * intensity);
			pPixel[2] = (BYTE)(origR + (r2 - origR) * intensity);
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessBleachbypass()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CBleachBypassDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // User canceled

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	size_t totalBytes = (size_t)abs(pitch) * height;

	// Commit preview changes back to m_imageOriginal on OK
	if (pitch < 0) {
		BYTE* pSrcStart = pSrcBits + (pitch * (height - 1));
		BYTE* pDstStart = pDstBits + (pitch * (height - 1));
		memcpy(pDstStart, pSrcStart, totalBytes);
	}
	else {
		memcpy(pDstBits, pSrcBits, totalBytes);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

// Fast separable box blur using a sliding-window sum — O(width*height) regardless of radius
void Cproject1View::BoxBlurLuminance(float* lumData, int width, int height, int radius)
{
	std::vector<float> temp(width * height);

	// --- Horizontal pass ---
	for (int y = 0; y < height; y++)
	{
		float sum = 0.0f;
		int count = 0;
		float* row = lumData + (y * width);
		float* outRow = temp.data() + (y * width);

		for (int x = -radius; x <= radius; x++)
		{
			int cx = max(0, min(width - 1, x));
			sum += row[cx];
			count++;
		}
		outRow[0] = sum / count;

		for (int x = 1; x < width; x++)
		{
			int addX = min(width - 1, x + radius);
			int subX = max(0, x - radius - 1);
			sum += row[addX] - row[subX];
			outRow[x] = sum / (2 * radius + 1);
		}
	}

	// --- Vertical pass (reads temp, writes back into lumData) ---
	std::vector<float> colBuf(height);
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
			colBuf[y] = temp[y * width + x];

		float sum = 0.0f;
		int count = 0;
		for (int y = -radius; y <= radius; y++)
		{
			int cy = max(0, min(height - 1, y));
			sum += colBuf[cy];
			count++;
		}
		lumData[x] = sum / count;

		for (int y = 1; y < height; y++)
		{
			int addY = min(height - 1, y + radius);
			int subY = max(0, y - radius - 1);
			sum += colBuf[addY] - colBuf[subY];
			lumData[y * width + x] = sum / (2 * radius + 1);
		}
	}
}

void Cproject1View::ApplyLiveClarity(int amount)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	// --- Step 1: extract luminance into a float buffer ---
	std::vector<float> luminance(width * height);
	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			luminance[y * width + x] = 0.299f * pPixel[2] + 0.587f * pPixel[1] + 0.114f * pPixel[0];
		}
	}

	// --- Step 2: blur a COPY of luminance ---
	std::vector<float> blurred = luminance;
	int radius = max(4, min(width, height) / 40);
	BoxBlurLuminance(blurred.data(), width, height, radius);

	double strength = amount / 100.0;   // -1.0 to 1.0
	const double MAX_BOOST = 1.6;       // multiplier controlling how strong the effect gets at +/-100

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);
			int idx = y * width + x;

			float origLum = luminance[idx];
			float blurLum = blurred[idx];
			float localContrast = origLum - blurLum;

			// --- Additive boost, symmetric in both directions ---
			float boost = (float)(localContrast * strength * MAX_BOOST);

			int newB = (int)(pPixel[0] + boost + 0.5f);
			int newG = (int)(pPixel[1] + boost + 0.5f);
			int newR = (int)(pPixel[2] + boost + 0.5f);

			pPixel[0] = (BYTE)max(0, min(255, newB));
			pPixel[1] = (BYTE)max(0, min(255, newG));
			pPixel[2] = (BYTE)max(0, min(255, newR));
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnSpatialdomainfilteringClarity()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CClarityDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::ApplyLiveSplitTone(COLORREF shadowTint, COLORREF highlightTint, int balance, int intensityPercent)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	int shadowR = GetRValue(shadowTint), shadowG = GetGValue(shadowTint), shadowB = GetBValue(shadowTint);
	int highR = GetRValue(highlightTint), highG = GetGValue(highlightTint), highB = GetBValue(highlightTint);

	double intensity = intensityPercent / 100.0;
	// Balance shifts the midpoint of the shadow/highlight blend — -100 pushes the crossover
	// point darker (more of the image treated as "highlight"), +100 pushes it brighter
	double balanceOffset = (balance / 100.0) * 64.0;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			BYTE b = pPixel[0], g = pPixel[1], r = pPixel[2];
			double lum = 0.299 * r + 0.587 * g + 0.114 * b;

			// Shift the crossover point by balance, then compute shadow/highlight weights
			double adjustedLum = lum - balanceOffset;
			double highlightWeight = adjustedLum / 255.0;
			highlightWeight = max(0.0, min(1.0, highlightWeight));
			double shadowWeight = 1.0 - highlightWeight;

			// Blend original color toward shadow tint (weighted by shadowWeight)
			// and toward highlight tint (weighted by highlightWeight), each scaled by intensity
			double newR = r + (shadowR - r) * shadowWeight * intensity + (highR - r) * highlightWeight * intensity;
			double newG = g + (shadowG - g) * shadowWeight * intensity + (highG - g) * highlightWeight * intensity;
			double newB = b + (shadowB - b) * shadowWeight * intensity + (highB - b) * highlightWeight * intensity;

			pPixel[0] = (BYTE)max(0.0, min(255.0, newB + 0.5));
			pPixel[1] = (BYTE)max(0.0, min(255.0, newG + 0.5));
			pPixel[2] = (BYTE)max(0.0, min(255.0, newR + 0.5));
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::OnPointprocessSplittone()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CSplitToneDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}

void Cproject1View::ApplyLiveChannelMixer(int redWeight, int greenWeight, int blueWeight)
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_image.IsNull() || pDoc->m_imageOriginal.IsNull()) return;

	// Restore pristine original first
	int pitch = pDoc->m_imageOriginal.GetPitch();
	int height = pDoc->m_imageOriginal.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_imageOriginal.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_image.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	int width = pDoc->m_image.GetWidth();
	int bpp = pDoc->m_image.GetBPP();
	if (bpp < 24) return;

	int bytesPerPixel = bpp / 8;
	int dstPitch = pDoc->m_image.GetPitch();
	BYTE* pBits = (BYTE*)pDoc->m_image.GetBits();

	double wR = redWeight / 100.0;
	double wG = greenWeight / 100.0;
	double wB = blueWeight / 100.0;

	for (int y = 0; y < height; y++)
	{
		BYTE* pRow = pBits + (y * dstPitch);
		for (int x = 0; x < width; x++)
		{
			BYTE* pPixel = pRow + (x * bytesPerPixel);

			BYTE b = pPixel[0], g = pPixel[1], r = pPixel[2];

			// Weighted sum, NOT required to normalize to 100 -- over/under-driving
			// individual channels is what gives the filter-glass look
			double gray = r * wR + g * wG + b * wB;
			BYTE grayByte = (BYTE)max(0.0, min(255.0, gray + 0.5));

			pPixel[0] = grayByte;
			pPixel[1] = grayByte;
			pPixel[2] = grayByte;
		}
	}

	Invalidate(FALSE);
	UpdateWindow();
}


void Cproject1View::OnPointprocessChannelmixerbw()
{
	Cproject1Doc* pDoc = GetDocument();
	if (!pDoc || pDoc->m_imageOriginal.IsNull() || pDoc->m_image.IsNull()) return;

	CChannelMixerDlg dlg;
	dlg.SetTargetView(this);

	if (dlg.DoModal() != IDOK)
		return; // OnCancel already reverted m_image

	int pitch = pDoc->m_image.GetPitch();
	int height = pDoc->m_image.GetHeight();
	BYTE* pSrcBits = (BYTE*)pDoc->m_image.GetBits();
	BYTE* pDstBits = (BYTE*)pDoc->m_imageOriginal.GetBits();

	if (pitch < 0) {
		memcpy(pDstBits + (pitch * (height - 1)), pSrcBits + (pitch * (height - 1)), abs(pitch) * height);
	}
	else {
		memcpy(pDstBits, pSrcBits, pitch * height);
	}

	Invalidate(FALSE);
	UpdateWindow();
}
