#include <iostream>

#include "da.h"

int main(int argc, char** argv){
  if(argc < 3){
    std::cout << "Usage : da in_path out_path" << std::endl;
  }
  std::string in_path(argv[1]);
  std::string out_path(argv[2]);
  DA da;

  cv::imwrite(out_path, da(cv::imread(in_path)));

  return 0;
}