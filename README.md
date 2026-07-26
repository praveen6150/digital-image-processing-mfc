# Digital Image Processing App

A Windows desktop application built with MFC (Microsoft Foundation Classes) and C++, implementing a wide range of digital image processing techniques — from basic point operations to advanced spatial-domain filters and geometric transforms.

---

## 📷 Screenshots

| Main Interface | Processing Canvas |
|---|---|
|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/aa45f30f-699f-4867-9c28-b000389f0c29" />|<img width="1366" height="769" alt="prewitt-edge detection" src="https://github.com/user-attachments/assets/80f99ecb-ee5d-4340-9089-ffa0a2bac841" />|
|<img width="1366" height="769" alt="lcrcb" src="https://github.com/user-attachments/assets/d78dbafb-4e26-4187-a374-a73fe751b726" />|<img width="1366" height="769" alt="hsi" src="https://github.com/user-attachments/assets/7272bcf0-19b0-4611-a2ce-36f4d1efc46b" />|
|<img width="1366" height="769" alt="histogram" src="https://github.com/user-attachments/assets/671717ad-ce61-430c-865c-882a38547260" />|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/879b5bf3-a575-4faf-b39d-159cc732394c" />|
|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/34f8a06c-5b74-414f-aecb-17e68026ae59" />|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/fbf37bf7-b0af-4cd9-9530-4db226ce226e" />|
|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/fe86efcc-1f59-45df-af8b-879f90e65939" />|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/79214b66-2d4c-4335-a358-f034c9fc3750" />|
<img width="1366" height="768" alt="image" src="https://github.com/user-attachments/assets/c8145203-bbac-41dc-9cf2-c6be63aa9636" />
|<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/c6e42d1e-073e-46f4-865c-a0635a18ede3" />||

---

## ✨ Features

### 🟨 Point Process Framework

* **Grayscale Conversion**
  * Convert to Gray Scale
* **Basic Intensity Transformations**
  * Brightness/Contrast
  * Contrast Stretching
  * Gamma Correction (Power-Law Transformations)
  * Invert Colors
  * Inverse Log Transformation
  * Log Transformation
  * Level Adjustment
  * Sigmoid / S-Curve Contrast
  * Curves Adjustment
  * Exposure Adjustment
* **Piecewise-Linear / Bit-Level Transformations**
  * Bitplane
  * Gray Slicing
  * Posterization
  * Binary Thresholding
* **Histogram Processing**
  * Histogram Equalization
  * Histogram Graph
  * Otsu's Auto Threshold
  * Auto Levels
* **Special / Artistic Effects**
  * Solarization (The Sabattier Effect)
  * Sepia Tone
  * Gaussian Noise
  * Salt-and-Pepper Noise
  * Vignette Effect
  * Quantum Point Process (Simulated)
  * Quantum DPP Stippling (Experimental)
  * Selective Color Replace
  * Color Pop
  * Bleach Bypass
  * Clarity / Dehaze
* **Color Model Transformation**
  * Color Balance
  * Hue-Saturation-Intensity
  * Hue-Saturation-Lightness
  * Hue-Saturation-Value
  * Luminance (Y)-Cb-Cr
  * Channel Isolation
  * Cyan-Magenta-Yellow-Black(K)
  * Vibrance
  * White Balance
  * Auto White Balance
  * CIE LUV
  * Lift/Gamma/Gain (3-Way Color)
  * Split Toning
  * Live Channel Mixer
* **Color and Visualization**
  * Pseudo-Coloring/False Coloring
  * Duotone
  * Colorize

---

### 🟩 Spatial Domain Filtering

* **Smoothing _Blurring (Low-Pass)**
  * Average Blur
  * Gaussian Blur
  * Low Pass Filter
  * Median Filter
  * Bilateral Filter
  * Non-Local means Filter
  * Wiener Filter
* **Edge Detection (Gradient-Based)**
  * Roberts Cross Operator
  * Sobel Edge Detection
  * Prewitt Edge Detection
  * Scharr Edge Detection
  * Frei-Chen Edge Detector
  * Kayyali Operator
  * Gradient Magnitude
* **Advanced Edge _Surface Detectors**
  * Laplacian Filter
  * Laplacian of Gaussian (LoG)
  * Difference of Gaussians (DoG)
  * Marr-Hildreth Edge Detector
  * Canny Edge Detector
  * Deriche Filter
* **Compass _Directional Operators**
  * Krisch Edge Detection
  * Robinson Compass Operator
  * Nevatia-Babu Operator
* **Sharpness _Contrast Enhancement**
  * High Pass Filter
  * Unsharp Masking
  * Emboss Filter
* **Morphological Filters**
  * Erosion/Dilation
  * Domain Filtering Opening
  * Domain Filtering Closing
  * Domain Filtering Morphological Gradient

---

### 🟦 Geometric Transformations

* **Orientation Flipping:** Flip Horizontal / Vertical
* **Fixed Rotations:** Rotate 90° / 180° / 270°
* **Free Rotations:** Arbitrary-angle rotation (0°–360°) with a live, real-time canvas preview while dragging the tracking slider.

---

## 🛠️ Built With

* **Language:** C++
* **Framework:** MFC (Microsoft Foundation Classes)
* **Graphics Engine:** GDI / GDI+ (for image rendering and arbitrary-angle rotation canvas live previews)
* **Pixel Manipulation:** `CImage` Class (for deep, pixel-level manipulation and multi-format support)
* **IDE:** Visual Studio

---

## 🚀 Getting Started

### Prerequisites
* Windows 10 or Windows 11
* Visual Studio 2022 (or later) with the **Desktop development with C++** workload and the **C++ MFC for latest v143 build tools** component installed.

### Build & Run
1. Clone the repository:
   ```bash
   git clone [https://github.com/praveen6150/digital-image-processing-mfc.git](https://github.com/praveen6150/digital-image-processing-mfc.git)
