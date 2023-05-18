//
// Created by israel on 5/15/23.
//

#include "Team.hpp"
#include <limits>

namespace ariel{
    int Team::getTeamSize() {
        return team.size();
    }

    Character * Team::getLeader() {
        return leader;
    }

    void Team::setLeader(ariel::Character * leader) {
        this->leader = leader;
    }

    std::vector<Character*>& Team::getTeam() {
        return team;
    }

    void Team::add(Character *character) {
        if(team.size()==10) throw std::runtime_error ("Can't add more than 10 fighters to team");
        if(character->getIsINTeam()) throw std::runtime_error ("Already in team.");
        team.push_back(character);
        character->setIsInTeam();
    }

    void Team::attack(Team *other){
        // Throw exceptions
        if(other == nullptr) throw std::invalid_argument("Invalid team pointer - nullptr");
        if(this == other) throw std::runtime_error("No self harm");
        if(!other->stillAlive()) throw std::runtime_error("Dead team");

        if (!leader->isAlive()) {
            Character* newLeader = findLeader();
            if (newLeader) {
                leader = newLeader;
            }
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

        Character* target = findTarget(other);

        if (target) { // If target exist.
            for (Character* member : team) {
                if (member->isAlive()) {
                    if (!target->isAlive()) {
                        target = findTarget(other);
                        if (target == nullptr) return; // No targets.
                    }
                    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(target);
                        } else {
                            cowboy->reload();
                        }
                    }
                }
            }
            for (Character* member : team) {
                if (member->isAlive()) {
                    if (!target->isAlive()) {
                        target = findTarget(other);
                    }
                    if (target == nullptr) return;
                    if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                        if (ninja->distance(target) <= 1.0) {
                            ninja->slash(target);
                        }
                        else {
                            ninja->move(target);
                        }
                    }
                }
            }
        }
    }

    int Team::stillAlive(){
        int counter = 0;
        for (Character* member : team) {
            if (member->isAlive()) {
                counter++;
            }
        }
        return counter;
    }

    void Team::print() {
        // Separate cowboys and ninjas
        for (Character* member : team) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                std::cout << member->print() << std::endl;
            }
        }
        for (Character* member : team) {
            if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                std::cout << member->print() << std::endl;
            }
        }
    }

    Character* Team::findTarget(Team *other) {
        Character* target = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* enemy : other->team) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy)) {
                if (cowboy->isAlive()) {
                    double distance = leader->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        target = cowboy;
                    }
                }
            }
        }
        for (Character* enemy : other->team) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(enemy)) {
                if (ninja->isAlive()) {
                    double distance = leader->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        target = ninja;
                    }
                }
            }
        }
        return target;
    }

    Character* Team::findLeader() {
        // Find the nearest living character to be the new leader
        Character* newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* member : team) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(member)) {
                if (cowboy->isAlive()) {
                    double distance = member->distance(cowboy);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = cowboy;
                    }
                }
            }
        }
        for (Character* member : team) {
            if (Ninja *ninja = dynamic_cast<Ninja *>(member)) {
                if (ninja->isAlive()) {
                    double distance = member->distance(ninja);
                    if (distance < minDistance) {
                        minDistance = distance;
                        newLeader = ninja;
                    }
                }
            }
        }
        return newLeader;
    }
}