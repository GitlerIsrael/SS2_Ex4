//
// Created by israel on 5/15/23.
//
#include "Ninja.hpp"
#include "Point.hpp"

namespace ariel{
    int Ninja::getSpeed(){
        return speed;
    }

    void Ninja::move(Character *enemy) {
        if (!isAlive() || !enemy || !enemy->isAlive()) {
            return;
        }
        Point new_location = moveTowards(location, enemy->getLocation(), speed);
        location = new_location;
    }

    void Ninja::slash(Character *enemy) {
        if (!isAlive() || !enemy || !enemy->isAlive()) {
            return;
        }
        double distance = location.distance(enemy->getLocation());
        if (distance < 1.0) {
            enemy->hit(40);
        }
    }

    std::string Ninja::print() {
        std::string s = "";
        if(isAlive()) {
            s += "N: " + getName() + ", Hit points: " + std::to_string(getHitPoints()) +
                 ", Location: (" + std::to_string(getLocation().getXval()) + ", " +
                 std::to_string(getLocation().getYval()) + ")";
        } else{
            s += "C: (" + getName() + "), Location: (" + std::to_string(getLocation().getXval()) + ", " +
                 std::to_string(getLocation().getYval()) + ")";
        }
        return s;
    }
}