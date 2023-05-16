//
// Created by israel on 5/15/23.
//

#include "Team.hpp"

namespace ariel{
    int Team::getTeamSize() {
        return team.size();
    }

    void Team::add(Character *character) {
        if(team.size()==10){
            throw "Can't add more than 10 fighters to team";
        }
        team.push_back(character);
    }

    void Team::attack(Team *other){

    }

    int Team::stillAlive(){
//        int counter = 0;
//        for (Character* member : team) {
//            if (member->isAlive()) {
//                counter++;
//            }
//        }
//        return counter;
        return 0;
    }

    void Team::print() {
        for (Character* member : team) {
            std::cout << member->print() << std::endl;
        }
    }
}