#pragma once

#include <iostream>
#include "Character.hpp"
#include "Point.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int speed;
    public:
        Ninja(std::string name, Point &location, int hitPoints, int speed) : Character(name, location, hitPoints), speed(speed){}
        virtual ~Ninja() = default;
        int getSpeed();
        void move(Character *enemy);
        void slash(Character *enemy);
        std::string print() override;
    };
}