#pragma once

#include <iostream>
#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int Bullets = 6;
    public:
        Cowboy(std::string name, Point &location) : Character(name, location, 110) {}
        ~Cowboy() = default;
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        std::string print() override;
    };
}