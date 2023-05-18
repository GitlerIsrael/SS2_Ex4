#pragma once

#include <iostream>
#include "Point.hpp"

namespace ariel {
    class Character {
    private:
        Point location;
        int hitPoints;
        std::string name;
        bool isInTeam = false;
    public:
        Character(std::string name, Point location, int hitPoints) : name(name), location(location), hitPoints(hitPoints) {}
        virtual ~Character()  = default;

        //for tidy:
        Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;

        bool isAlive();
        double distance(Character* other);
        void hit(int num);
        std::string getName();
        Point getLocation();
        int getHitPoints();
        void setLocation(Point &point);
        bool getIsINTeam();
        void setIsInTeam();
        virtual std::string print() = 0;
    };
}