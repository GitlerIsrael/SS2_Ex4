//
// Created by israel on 5/15/23.
//
#include "SmartTeam.hpp"

namespace ariel{
    void SmartTeam::attack(Team *other){

    }

    void SmartTeam::print() {
        for (Character* member : team) {
            std::cout << member->print() << std::endl;
        }
    }
}