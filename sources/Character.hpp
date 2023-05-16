#pragma once

#include <iostream>
#include "Point.hpp"

namespace ariel {
    class Character {
    protected:
        Point& location;
        int hitPoints;
        std::string name;
    public:
        Character(std::string name, Point &location, int hitPoints) : name(name), location(location), hitPoints(hitPoints) {}
        virtual ~Character()  = default;
        bool isAlive();
        double distance(Character* other);
        void hit(int num);
        std::string getName();
        Point getLocation();
        int getHitPoints();
        void setLocation(Point &point);
        virtual std::string print() = 0;
    };
}