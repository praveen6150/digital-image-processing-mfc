// project1View.h : interface of the Cproject1View class
//

#pragma once

#include "project1Doc.h"
#include <vector>
#include <random>
//#include "CColorReplaceDlg.h"

class CHistogramDlg;
class CColorReplaceDlg;
class CColorPopDlg;

class Cproject1View : public CScrollView
{
protected: // create from serialization only
	Cproject1View() noexcept;
	DECLARE_DYNCREATE(Cproject1View)
	BOOL   m_bPreviewRotationActive = FALSE;
	double m_previewRotationAngle = 0.0;
	std::mt19937 m_noiseGenerator;
	double m_zoomFactor = 1.0;
	bool m_bFitToScreen;
	float m_fZoomScale;

public:
	Cproject1Doc* GetDocument() const;
	BOOL m_bFitToWindow;
	CImage m_imgBackup;
	CHistogramDlg* m_pHistDlg; // <-- 2. ADD THIS LINE TO TRACK THE OPENED WINDOW
	std::vector<BYTE> m_pixelBackupBuffer;
	// HSV processing functions
	void ApplyLiveHSV(int hDeg, int sSat, int vVal);
	void ApplyLiveHSVPreview(int hDeg, int sSat, int vVal, CImage* pSmallImg);
	// Operations
	void StartColorPickerTracking2(CColorPopDlg* pDlg);
	void StopColorPickerTracking2();

public:

	// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	void OnInitialUpdate();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	void StartColorPickerTracking(CColorReplaceDlg* pDlg);
	void StopColorPickerTracking();

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = nullptr);

	// Implementation
	template<typename Func>
	void ProcessPixels(Func pfnPixelOp);

	static HHOOK s_hColorPickerHook;
	static Cproject1View* s_pActiveColorPickerView;
	static LRESULT CALLBACK ColorPickerHookProc(int nCode, WPARAM wParam, LPARAM lParam);

	CColorReplaceDlg* m_pColorPickerDlg = nullptr;

	void HandleColorPickerHover(CPoint screenPt);
	BOOL HandleColorPickerClick(CPoint screenPt);
	BOOL GetPixelColorAtScreenPoint(CPoint screenPt, COLORREF& outColor);
	BOOL IsScreenPointOverDialog(CPoint screenPt);

	static HHOOK s_hColorPickerHook2;
	static Cproject1View* s_pActiveColorPickerView2;
	static LRESULT CALLBACK ColorPickerHookProc2(int nCode, WPARAM wParam, LPARAM lParam);

	CColorPopDlg* m_pColorPopDlg = nullptr;

	void HandleColorPickerHover2(CPoint screenPt);
	BOOL HandleColorPickerClick2(CPoint screenPt);
	BOOL IsScreenPointOverDialog2(CPoint screenPt);



public:
	virtual ~Cproject1View();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void RotateImage90(CImage& img);
	void RotateImage270(CImage& img);
	void RotateArbitrary(double angleDegrees);
	void RotateImageArbitrary(CImage& img, double angleDegrees);
	int ComputeOtsuThreshold(const std::vector<int>& histogram, int totalPixels);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void BoxBlurLuminance(float* lumData, int width, int height, int radius);
protected:
	//afx_msg void OnColorsHsvadjustment();
	DECLARE_MESSAGE_MAP()
	
public:
	afx_msg void ApplyCurvesLUT(const BYTE lut[256]);
	afx_msg void OnViewFittowindow();
	afx_msg void OnDestroy();
	afx_msg void OnUpdateViewFittowindow(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPointInvertcolors();
	afx_msg void OnPointBrightnessContrast();
	afx_msg void ApplyLiveBrightnessContrast(int bPos, int cPos);
	afx_msg void ApplyLiveHSI(int hDeg, int sSat, int iInt);
	afx_msg void ApplyLiveYCbCr(int yOffset, int cbOffset, int crOffset);
	afx_msg void OnPointprocessHsi();
	afx_msg void OnPointprocessLuminance();
	afx_msg void OnPointHistogramEqualization();
	afx_msg void ApplyLiveGamma(double gammaVal);
	afx_msg void OnPointprocessHistogramgraph();
	afx_msg void OnPointprocessGammacorrection();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void ApplyLiveHSIPreview(int hDeg, int sSat, int iInt, CImage* pSmallImg);
	afx_msg void OnPointprocessSolarization();
	void ApplyLiveSolarization(int threshold);
	void ApplyLivePosterization(int levels);
	void ApplyLiveBitPlane(int bitPlane);
	afx_msg void OnPointprocessPosterization();
	afx_msg void OnPointprocessBitplane();
	afx_msg void OnPointprocessContraststretch();
	void ApplyLiveContrastStretch(int minVal, int maxVal);
	afx_msg void OnPointprocessColorbalance();
	void ApplyLiveColorBalance(int deltaR, int deltaG, int deltaB);
	afx_msg void OnNeighborhoodprocessingAverageblur();
	afx_msg void OnNeighborhoodprocessingGaussianblur();
	afx_msg void OnNeighborhoodprocessingLowpassfilter();
	afx_msg void OnNeighborhoodprocessingHighpassfilter();
	afx_msg void OnNeighborhoodprocessingMedianfilter();
	afx_msg void OnNeighborhoodprocessingSobeledgedetection();
	afx_msg void OnNeighborhoodprocessingKrishedgedetection();
	afx_msg void OnNeighborhoodprocessingPrewittedgedetection();
	afx_msg void OnSpatialdomainfilteringScharredgedetection();
	afx_msg void OnSpatialdomainfilteringLaplacianofgaussian();
	afx_msg void OnSpatialdomainfilteringCannyedgedetector32810();
	afx_msg void OnSpatialdomainfilteringLaplacianfilter();
	afx_msg void OnSpatialdomainfilteringFrei();
	afx_msg void OnSpatialdomainfilteringRobertscrossoperator();
	afx_msg void OnSpatialdomainfilteringDifferenceofgaussians();
	afx_msg void OnSpatialdomainfilteringMarr();
	afx_msg void OnSpatialdomainfilteringKayyalioperator();
	afx_msg void OnSpatialdomainfilteringRobinsoncompassoperator();
	afx_msg void OnSpatialdomainfilteringNevatia();
	afx_msg void OnSpatialdomainfilteringDerichefilter();
	afx_msg void OnSpatialdomainfilteringUnsharpmasking();
	afx_msg void OnSpatialdomainfilteringEmbossfilter();
	afx_msg void OnSpatialdomainfilteringGredientmagnitude();
	afx_msg void OnSpatialdomainfilteringBilateralfilter();
	afx_msg void OnSpatialdomainfilteringNon();
	afx_msg void OnSpatialdomainfilteringWienerfilter();
	afx_msg void OnSpatialdomainfilteringErosion();
	afx_msg void OnSpatialdomainfilteringDomainfilteringopening();
	afx_msg void OnSpatialdomainfilteringDomainfilteringclosing();
	afx_msg void OnSpatialdomainfilteringDomainfilteringmorphologicalgradient();
	afx_msg	void OnTransformFlip();
	afx_msg void OnImageFlipRotate();
	afx_msg void FlipHorizontal();
	afx_msg void FlipVertical();
	afx_msg void Rotate180();
	afx_msg void Rotate90();
	afx_msg void Rotate270();
	afx_msg void SetPreviewRotationAngle(double angle, BOOL bActive);
	afx_msg void DrawArbitraryRotationPreview(CDC* pDC, CImage& srcImg, double angleDegrees);
	afx_msg void OnColorsHsvadjustment();
	afx_msg void OnPointprocessConverttograyscale();
	afx_msg void OnPointprocessHsl();
	afx_msg void ApplyLiveHsl(int hOffset, int sOffset, int lOffset);
	afx_msg void OnPointprocessLogtransformation();
	afx_msg void ApplyLiveLog(double cVal);
	afx_msg void ApplyLiveInverseLog(double cVal);
	afx_msg void OnPointprocessInverselogtransformation();
	afx_msg void OnPointprocessGrayslicing();
	afx_msg void ApplyLiveGraySlicing(int lowVal, int highVal, BOOL bPreserveBG);
	afx_msg void ApplyLivePseudoColor(int mapIndex, int shiftValue = 0);
	afx_msg void OnColorprocessPseudocoloring();
	afx_msg void OnPointprocessOtsuthreshold();
	afx_msg void ApplyOtsuThresholdWithValue(int thresholdValue);
	afx_msg void ApplyOtsuThreshold(bool preview);
	afx_msg void RestoreOriginalPixels();
	afx_msg void OnPointprocessBinarythreshold();
	afx_msg void ApplyBinaryThreshold(int thresholdValue);
	afx_msg void ApplyLevelsAdjustment(int blackPoint, int whitePoint, double gamma);
	afx_msg void ApplySigmoidContrast(double gain, int midpoint);
	afx_msg void ApplySepiaTone(double intensity);
	afx_msg void OnPointprocessLevelsadjustment();
	afx_msg void OnPointprocessSigmoidcontrast();
	afx_msg void OnPointprocessSepiatone();
	afx_msg void OnPointprocessCurvesadjustment();
	afx_msg void ApplyChannelIsolation(int channel);
	afx_msg void OnPointprocessChannelisolation();
	afx_msg void ApplyDuotone(COLORREF shadowColor, COLORREF highlightColor);
	afx_msg void OnPointprocessDuotone();
	afx_msg void ApplyGaussianNoise(int stdDev);
	afx_msg void OnPointprocessGaussiannoise();
	afx_msg void ApplySaltPepperNoise(double probability);
	afx_msg void OnPointprocessSaltpeppernoise();
	afx_msg	void ApplyVignette(double strength);
	afx_msg void OnPointprocessVignette();
	afx_msg void OnColorModelCmykConversion();
	afx_msg void ApplyCmykFilter(int cOffset, int mOffset, int yOffset, int kOffset);
	afx_msg void OnPointprocessCmyk();
	afx_msg void OnPointprocessQuantumsim();
	afx_msg void ApplyQuantumSim(int levels, double uncertainty);
	afx_msg void OnPointprocessQuantumdpp();
	afx_msg void ApplyQuantumDPP(int gridSpacing, int repulsionRadius, double entanglementStrength, int dotSize);
	afx_msg void RevertToOriginal();
	afx_msg void ApplyLiveColorize(int hue, int saturationPercent);
	afx_msg void OnPointprocessColorize();
	afx_msg void ApplyLiveVibrance(int amount);
	afx_msg void OnPointprocessVibrance();
	afx_msg void ApplyLiveWhiteBalance(int temperature, int tint);
	afx_msg void OnPointprocessWhitebalance();
	afx_msg void OnPointprocessAutolevels();
	afx_msg void ApplyLiveColorReplace(COLORREF targetColor, COLORREF replaceColor, int tolerance);
	afx_msg void OnPointprocessColorreplace();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void ApplyLiveExposure(int exposureStops100);
	afx_msg void OnPointprocessExposure();
	afx_msg void OnPointprocessAutowhitebalance();
	afx_msg void ApplyLiveLuv(int deltaL, int deltaU, int deltaV);
	afx_msg void OnPointprocessCieluv();
	afx_msg void ApplyLiveLiftGammaGain(int liftR100, int liftG100, int liftB100, int gammaR100, int gammaG100, int gammaB100, int gainR100, int gainG100, int gainB100);
	afx_msg void OnPointprocessLiftgammagain();
	afx_msg void OnPointprocessColorpop();
	afx_msg void ApplyLiveBleachBypass(int intensityPercent);
	afx_msg void ApplyLiveColorPop(COLORREF targetColor, int hueTolerance);
	afx_msg void OnPointprocessBleachbypass();
	afx_msg void ApplyLiveClarity(int amount);
	afx_msg void OnSpatialdomainfilteringClarity();
};

#ifndef _DEBUG  // debug version in project1View.cpp
inline Cproject1Doc* Cproject1View::GetDocument() const
{
	return reinterpret_cast<Cproject1Doc*>(m_pDocument);
}
#endif




