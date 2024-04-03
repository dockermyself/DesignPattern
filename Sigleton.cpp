//
// Created by feng on 2020/11/12.
//

#include "Sigleton.h"

Sigleton_01::Sigleton * Sigleton_01::Sigleton::instance_ = new Sigleton();
Sigleton_02::Sigleton * Sigleton_02::Sigleton::instance_ = nullptr;
std::mutex&& Sigleton_02::Sigleton::lock_ = std::mutex();