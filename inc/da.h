#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <random>

class DA{
public:
  cv::Mat operator()(cv::Mat mat);
private:
  static std::random_device rd;
  static std::mt19937 mt;

  void rotation(cv::Mat& mat);
  void horizontal_reflection(cv::Mat& mat);
  void scaling(cv::Mat& mat);
  void translation(cv::Mat& mat);
  void affine(cv::Mat& mat);
};