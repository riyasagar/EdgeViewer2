cmake_minimum_required(VERSION 3.18.1)

project("edgeviewer")

# Build our own native-lib
add_library(
        native-lib
        SHARED
        native-lib.cpp
)

# Import OpenCV native lib
add_library(opencv_java4 SHARED IMPORTED)
set_target_properties(opencv_java4 PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libopencv_java4.so)

# Log library (Android logging)
find_library(log-lib log)

# Link everything
target_link_libraries(
        native-lib
        opencv_java4
        ${log-lib}
)
