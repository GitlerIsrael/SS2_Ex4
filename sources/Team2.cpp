//
// Created by israel on 5/15/23.
//
#include "Team2.hpp"

namespace ariel{
    void Team2::attack(Team *other){

    }

    void Team2::print() {
        for (Character* member : team) {
            std::cout << member->print() << std::endl;
        }
    }
}

