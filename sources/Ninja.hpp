#pragma once

#include <iostream>
#include "Character.hpp"
#include "Point.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int speed;
    public:
        Ninja(int speed, const std::string & name, Point &location, int hitPoints) : Character(name, location, hitPoints), speed(speed){}
        ~Ninja() override = default;

        //for tidy:
        Ninja(const Ninja&) = delete;
        Ninja& operator=(const Ninja&) = delete;
        Ninja(Ninja&&) = delete;
        Ninja& operator=(Ninja&&) = delete;

        int getSpeed();
        void move(Character *enemy);
        void slash(Character *enemy);
        std::string print() override;
    };
}