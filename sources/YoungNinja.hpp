#pragma once

#include <iostream>
#include "Ninja.hpp"

namespace ariel {
    class YoungNinja : public Ninja {
    public:
        YoungNinja(std::string name, Point location) : Ninja(name, location, 100, 14){}
        ~YoungNinja() = default;
    };
}