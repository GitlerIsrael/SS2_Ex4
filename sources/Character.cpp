//
// Created by israel on 5/15/23.
//
#include "Point.hpp"
#include "Character.hpp"
namespace ariel{
    bool Character::isAlive() {
        return hitPoints > 0;
    }

    double Character::distance(Character* other) {
        return location.distance(other->getLocation());
    }

    void Character::hit(int damage) {
        if (damage<0) throw std::invalid_argument ("Can't hit with negative argument");
        hitPoints -= damage;
    }

    std::string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    int Character::getHitPoints() {
        return hitPoints;
    }

    void  Character::setLocation(ariel::Point &point) {
        location = point;
    }

    bool Character::getIsINTeam() {
        return isInTeam;
    }

    void Character::setIsInTeam(){
        isInTeam = true;
    }
}