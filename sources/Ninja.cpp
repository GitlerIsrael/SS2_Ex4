//
// Created by israel on 5/15/23.
//
#include "Ninja.hpp"
#include "Point.hpp"

namespace ariel{
    //Returns ninja's speed.
    int Ninja::getSpeed(){
        return speed;
    }

    // Move the ninja towards an enemy.
    void Ninja::move(Character *enemy) {
        if (!isAlive() || !enemy->isAlive()) {
            return;
        }
        Point new_location = Point::moveTowards(getLocation(), enemy->getLocation(), speed);
        setLocation(new_location);
    }

    // Ninja attack enemy.
    void Ninja::slash(Character *enemy) {
        if (!isAlive() || !enemy->isAlive()) throw std::runtime_error("Can't attack if dead");
        if (this==enemy) throw std::runtime_error("No self harm");
        double distance = getLocation().distance(enemy->getLocation());
        if (distance <= 1.0) {
            enemy->hit(40);
        }
    }

    //Prints ninja's details.
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