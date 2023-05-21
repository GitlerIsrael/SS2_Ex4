//
// Created by israel on 5/15/23.
//
#include "Point.hpp"
#include "Character.hpp"
namespace ariel{
    // returns if character is alive.
    bool Character::isAlive() {
        return hitPoints > 0;
    }

    // returns the distance from other character.
    double Character::distance(Character* other) {
        return location.distance(other->getLocation());
    }

    // reducing object hit points.
    void Character::hit(int damage) {
        if (damage<0) throw std::invalid_argument ("Can't hit with negative argument");
        hitPoints -= damage;
    }

    // returns character name.
    std::string Character::getName() {
        return name;
    }

    // returns character location.
    Point Character::getLocation() {
        return location;
    }

    //returns character hit points.
    int Character::getHitPoints() {
        return hitPoints;
    }

    // set character location.
    void  Character::setLocation(ariel::Point &point) {
        location = point;
    }

    //returns if character is already in team.
    bool Character::getIsINTeam() {
        return isInTeam;
    }

    // set that character joined a team.
    void Character::setIsInTeam(){
        isInTeam = true;
    }
}