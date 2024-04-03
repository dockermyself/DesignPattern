//
// Created by feng on 2020/11/18.
//

#include "TemplateMethod.h"

cv::Mat ImageProcess::read() {
    return cv::imread("/home/feng/documents/background/background.jpg");
}

void ImageProcess::show(cv::Mat img) {
    cv::namedWindow("show",cv::WINDOW_NORMAL);
    cv::imshow("show",img);
    cv::waitKey(0);
}


void testTemplateMethod(){
    ImageProcess process;
    process.method();
}