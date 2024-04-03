//
// Created by feng on 2020/11/17.
//

#ifndef DESIGNPATTERN_FLYWEIGHT_H
#define DESIGNPATTERN_FLYWEIGHT_H


#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include <mutex>
#include <atomic>
class Piece {
    const std::string _color;
    const int _radius;
    std::atomic<bool > _active {false};

public:
    explicit Piece(const std::string &color, int radius = 10, bool active = false);
    virtual void put(int x,int y, const cv::Mat& img) = 0;

    const std::string &getColor() const;

    int getRadius() const;
    bool setActive(bool active,bool expected);
    bool isActive() const;
};

class BlackPiece : public Piece{
public:
    BlackPiece():Piece("black") {}
    void put(int x, int y, const cv::Mat& img) override;
};
class WhitePiece : public Piece{
public:
    WhitePiece():Piece("white") {}
    void put(int x, int y, const cv::Mat& img) override;
};

//享元工厂方法
class FlyweightFactory{
    std::vector<Piece*> _piecesPool;
    std::mutex lock;
public:
    Piece* CreatPiece(const std::string& color);
    int poolSize() const {
        return _piecesPool.size();
    }

};
void testFlyweight();
#endif //DESIGNPATTERN_FLYWEIGHT_H
