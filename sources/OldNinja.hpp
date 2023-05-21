#pragma once

#include <iostream>
#include "Ninja.hpp"

static const int DEFAULT_HIT_POINTS_OLD = 150;
static const int DEFAULT_SPEED_OLD = 8;

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(const std::string & name, Point location) : Ninja(DEFAULT_SPEED_OLD, name, location, DEFAULT_HIT_POINTS_OLD) {}
    };
}