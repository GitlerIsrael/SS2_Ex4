#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel {
    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(std::string name,Point location) : Ninja(name, location, 120, 12) {}
        ~TrainedNinja() = default;
    };
}