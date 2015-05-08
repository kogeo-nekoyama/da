cmake_minimum_required(VERSION 2.8)
project(DA)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./build)

include_directories(
  "~/caffe/include"
  "/usr/local/cuda-6.5/include"
  "./inc"
  )
link_directories(
  "~/caffe/build/lib"
  "/usr/local/cuda/lib64"
  )

add_executable(
  DA
  src/main.cpp
  src/da.cpp
  )
set_target_properties(
  DA
  PROPERTIES
  COMPILE_FLAGS "-pg -std=c++1y -O2"
  )
target_link_libraries(
  DA
  glog
  opencv_core
  opencv_imgproc
  opencv_highgui
  )

project(da)
add_library(
  da STATIC
  src/da.cpp
  )
set_target_properties(
  da
  PROPERTIES
  COMPILE_FLAGS "-pg -std=c++1y -O2"
  )
target_link_libraries(
  da
  glog
  opencv_core
  opencv_imgproc
  opencv_highgui
  )
install(
  TARGETS da
  #LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  )
install(
  FILES inc/da.h
  DESTINATION include/da
  )