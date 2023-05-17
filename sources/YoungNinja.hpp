#pragma once

#include <iostream>
#include "Ninja.hpp"
static const int DEFAULT_HIT_POINTS_YOUNG = 100;
static const int DEFAULT_SPEED_YOUNG = 14;

namespace ariel {
    class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string & name, Point location) : Ninja(DEFAULT_SPEED_YOUNG, name, location, DEFAULT_HIT_POINTS_YOUNG){}
//        ~YoungNinja() override = default;
    };
}