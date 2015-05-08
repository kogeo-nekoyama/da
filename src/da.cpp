#include "da.h"

std::random_device DA::rd;
std::mt19937 DA::mt = std::mt19937(DA::rd());

cv::Mat DA::operator()(cv::Mat mat){
  static std::uniform_int_distribution<> type(0, 3);
  switch(type(mt)){
  case 0:
    scaling(mat);
  case 1:
    rotation(mat);
  case 2:
    horizontal_reflection(mat);
    translation(mat);
    break;
  case 3:
    affine(mat);
    break;
  }
  return mat;
}

void DA::rotation(cv::Mat& mat){
  static std::uniform_real_distribution<> angle(-10.0, 10.0);
  cv::Point2f center(mat.cols / 2.0, mat.rows / 2.0);
  auto angle_ = angle(mt);
  auto rot_mat = cv::getRotationMatrix2D(center, angle_, 1.0);
  cv::warpAffine(mat, mat, rot_mat, mat.size());
  std::cout << "rotation : angle is " << angle_ << std::endl;
}

void DA::horizontal_reflection(cv::Mat& mat){
  cv::flip(mat, mat, 1);
  std::cout << "horizontal_reflection" << std::endl;
}

void DA::scaling(cv::Mat& mat){
  static std::uniform_real_distribution<> scale(0.8, 1.25);
  cv::Point2f center(mat.cols / 2.0, mat.rows / 2.0);
  auto scale_ = scale(mt);
  auto rot_mat = cv::getRotationMatrix2D(center, 0.0, scale_);
  cv::warpAffine(mat, mat, rot_mat, mat.size());
  std::cout << "scaling : scale_ is " << scale_ << std::endl;
}

void DA::translation(cv::Mat& mat){
  std::uniform_real_distribution<> x(-mat.cols / 32.0, mat.cols / 32.0);
  std::uniform_real_distribution<> y(-mat.rows / 32.0, mat.rows / 32.0);
  cv::Point2f mov(x(mt), y(mt));
  cv::Point2f tl(0, 0);
  cv::Point2f br(mat.cols, mat.rows);
  cv::Point2f tr(br.x, tl.y);

  cv::Point2f a_tl = tl + mov;
  cv::Point2f a_br = br + mov;
  cv::Point2f a_tr = tr + mov;

  cv::Point2f before[3] = {tl, br, tr};
  cv::Point2f after[3] = {a_tl, a_br, a_tr};

  auto tra_mat = getAffineTransform(before, after);
  cv::warpAffine(mat, mat, tra_mat, mat.size());
  std::cout << "translation : mov is " << mov << std::endl;
}

void DA::affine(cv::Mat& mat){
  std::uniform_real_distribution<> x(-mat.cols / 16.0, mat.cols / 16.0);
  std::uniform_real_distribution<> y(-mat.rows / 16.0, mat.rows / 16.0);

  cv::Point2f tl(0, 0);
  cv::Point2f br(mat.cols, mat.rows);
  cv::Point2f tr(br.x, tl.y);

  cv::Point2f a_tl = tl + cv::Point2f(x(mt), y(mt));
  cv::Point2f a_br = br + cv::Point2f(x(mt), y(mt));
  cv::Point2f a_tr = tr + cv::Point2f(x(mt), y(mt));

  cv::Point2f before[3] = {tl, br, tr};
  cv::Point2f after[3] = {a_tl, a_br, a_tr};

  auto tra_mat = getAffineTransform(before, after);
  cv::warpAffine(mat, mat, tra_mat, mat.size());
  std::cout << "affine : tra_mat is " << tra_mat << std::endl;
}