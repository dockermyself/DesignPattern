//
// Created by feng on 2020/11/18.
//

#ifndef DESIGNPATTERN_TEMPLATEMETHOD_H
#define DESIGNPATTERN_TEMPLATEMETHOD_H

#include <opencv2/opencv.hpp>
class TemplateMethod {
    cv::Mat _img;
public:
    void method(){
        _img = read();
        if(doProcess()){
            Process();
        }
        show(_img);
    }

private:
    virtual cv::Mat read() = 0;
    void Process(){
         cv::cvtColor(_img,_img,cv::COLOR_BGR2GRAY);
    }
    virtual bool doProcess(){
        return true;
    }
    virtual void show(cv::Mat _img) = 0;
};


class ImageProcess : public TemplateMethod{
private:
    cv::Mat read() override;
    void show(cv::Mat img) override;
};
void testTemplateMethod();
#endif //DESIGNPATTERN_TEMPLATEMETHOD_H
