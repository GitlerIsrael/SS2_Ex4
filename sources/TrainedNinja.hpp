#pragma once

#include <iostream>
#include "Ninja.hpp"

static const int DEFAULT_HIT_POINTS_TRAINED = 120;
static const int DEFAULT_SPEED_TRAINED = 12;


namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string & name,Point location) : Ninja(DEFAULT_SPEED_TRAINED, name, location, DEFAULT_HIT_POINTS_TRAINED) {}
//        ~TrainedNinja() override = default;
    };
}