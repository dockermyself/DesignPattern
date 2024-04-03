//
// Created by feng on 2020/11/12.
//

#ifndef DESIGNPATTERN_SIGLETON_H
#define DESIGNPATTERN_SIGLETON_H
#include <mutex>

namespace Sigleton_01{
    class Sigleton {
        static Sigleton * instance_;
    public:
        static Sigleton *  getInstance(){
            return instance_;
        }
    private:
        Sigleton() = default;
    };
}



namespace Sigleton_02{
    class Sigleton{
        static Sigleton * instance_;
        static std::mutex&& lock_;
    public:
        static Sigleton* getInstance(){
            if(instance_ == nullptr){
                std::lock_guard<std::mutex> g(lock_);
                if(instance_ == nullptr){
                    instance_ = new Sigleton();
                }
            }
            return instance_;
        }
    private:
        Sigleton() = default;
    };
}
#endif //DESIGNPATTERN_SIGLETON_H
