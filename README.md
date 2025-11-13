# EdgeViewer – Real-Time Edge Detection (Android + C++ + OpenCV)

A minimal Android project that performs **real-time edge detection** using:

- **Java** (Android)
- **JNI + C++**
- **OpenCV** (Canny edge detection)
- **OpenGL ES 2.0** (Rendering)
- **TypeScript Web Viewer** for displaying a processed sample frame

Designed as part of an RnD Intern technical assessment.

---

## 🚀 Features
- Real-time camera preview  
- Frame processing via **native C++ + OpenCV**  
- Canny edge detection  
- Output rendered using **OpenGL ES**  
- Minimal TypeScript web viewer  

---

## 🏗 Architecture
```
Camera → Java → JNI → C++ (OpenCV) → RGBA Output → OpenGL ES → Screen
Web Viewer → Shows exported processed frame
```

---

## 📁 Project Structure
```
app/
 ├─ java/com/example/edgeviewer/     # MainActivity, GLRenderer, JNI wrapper
 ├─ cpp/                              # native-lib.cpp, CMakeLists
 ├─ jniLibs/                          # libopencv_java4.so for all ABIs
web/
 ├─ index.html
 ├─ main.ts
 ├─ tsconfig.json
```

---
