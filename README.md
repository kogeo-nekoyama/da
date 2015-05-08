DataAugumentationLib
========
--------
画像データセットの水増しライブラリ  
中身はOpenCVのラッピング  


必要なもの
--------
OpenCV  
GCC 4.8.2 or later  


使い方
--------
1. 実行ファイルの場合  
DA in_path out_path  
2. ライブラリの場合  
#include <da.h>  
DA da;  
cv::Mat out = da(cv::Mat in);  