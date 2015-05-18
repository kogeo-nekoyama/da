cmake_minimum_required(VERSION 2.8)
project(DA)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./build)

include_directories(
  "./inc"
  )
link_directories(
  )

add_executable(
  DA
  src/main.cpp
  src/da.cpp
  )
set_target_properties(
  DA
  PROPERTIES
  COMPILE_FLAGS "-std=c++1y -O2"
  )
target_link_libraries(
  DA
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
  COMPILE_FLAGS "-std=c++1y -O2"
  )
target_link_libraries(
  da
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
