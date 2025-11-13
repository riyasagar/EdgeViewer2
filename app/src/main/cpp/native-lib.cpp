#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

extern "C"
JNIEXPORT jintArray JNICALL
Java_com_example_edgeviewer_NativeLib_processFrame(
        JNIEnv *env,
        jobject /* this */,
        jbyteArray frameData,
        jint width,
        jint height) {

    // Convert NV21 byte array to Mat
    jbyte *dataPtr = env->GetByteArrayElements(frameData, nullptr);
    Mat yuv(height + height / 2, width, CV_8UC1, (unsigned char *) dataPtr);
    Mat bgr, edges;

    // Convert NV21 (camera) to BGR
    cvtColor(yuv, bgr, COLOR_YUV2BGR_NV21);

    // Convert to grayscale
    cvtColor(bgr, edges, COLOR_BGR2GRAY);

    // Apply Canny Edge Detection
    Canny(edges, edges, 80, 150);

    // Convert edge image to RGBA for Android Bitmap
    Mat rgba;
    cvtColor(edges, rgba, COLOR_GRAY2RGBA);

    // Prepare output jintArray
    int size = width
