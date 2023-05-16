#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(std::string name,Point location) : Ninja(name, location, 150, 8) {}

        ~OldNinja() = default;
    };
}