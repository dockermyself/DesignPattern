//
// Created by feng on 2020/11/17.
//

#include "Flyweight.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
using namespace std;
void BlackPiece::put(int x, int y, const cv::Mat& img) {
    cv::circle(img,cv::Point(x,y),getRadius(),\
    cv::Scalar(0,0,0),getRadius()*2);
    setActive(false, true);

}


void WhitePiece::put(int x, int y, const cv::Mat& img) {
    cv::circle(img,cv::Point(x,y),getRadius(),\
    cv::Scalar(255,255,255),getRadius()*2);
    setActive(false, true);
}

Piece::Piece(const string &color, int radius, bool active) : _color(color), _radius(radius), _active(active) {}

const string &Piece::getColor() const {
    return _color;
}

int Piece::getRadius() const {
    return _radius;
}

bool Piece::isActive() const {
    return _active;
}

bool Piece::setActive(bool active, bool expected) {
    return _active.compare_exchange_weak(expected,active);
}


Piece *FlyweightFactory::CreatPiece(const std::string &color) {
    if(color != "black" && color != "white"){
        cout << "don't have this color\n" << endl;
        return nullptr;
    }
    lock_guard<mutex> g(lock);
    for(auto piece : _piecesPool){
        if(!piece->isActive() && piece->getColor() == color && piece->setActive(true, false)){
            return piece;
        }
    }
    Piece* piece = nullptr;
    if(color == "white"){
        cout << "new white piece" << endl;
        piece = new WhitePiece();

    } else{
        cout << "new black piece" << endl;
        piece = new BlackPiece();
    }
    _piecesPool.push_back(piece);
    piece->setActive(true, false);
    return piece;
}

void testFlyweight(){
    vector<thread*> v_thread;
    FlyweightFactory factory;

    cv::Mat img(1000,1000,CV_8UC3,cv::Scalar(150,150,150));
    for(int i = 0;i <= 25 ; ++i){
        cv::line(img,cv::Point(0,i*40),cv::Point(1000,i*40),\
                cv::Scalar(0,255,0),2);
        cv::line(img,cv::Point(i*40,0),cv::Point(i*40,1000),\
                cv::Scalar(0,255,0),2);
    }
    for(int i = 0;i <= 200;++i){
        auto* thread_pt = new thread([&factory,img]{
            Piece* black = factory.CreatPiece(random() % 2 == 0 ? "black" : "white");
            black->put((int)(random()%24+1)*40,(int)(random()%24+1)*40,img);
        });
        v_thread.push_back(thread_pt);
    }


    for(auto t : v_thread){
        t->join();
    }
    cout << "pool size:" <<  factory.poolSize() << endl;
    cv::namedWindow("piece show",cv::WINDOW_NORMAL);

    cv::imshow("piece show",img);
    cv::waitKey(0);
}