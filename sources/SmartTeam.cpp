//
// Created by israel on 5/15/23.
//
#include "SmartTeam.hpp"
#include <limits>

namespace ariel{
    void SmartTeam::attack(Team *other){
        // Throw exceptions
        if(other == nullptr) throw std::invalid_argument("Invalid team pointer - nullptr");
        if(this == other) throw std::runtime_error("No self harm");
        if(!other->stillAlive()) throw std::runtime_error("Dead team");

        if (!getLeader()->isAlive()) {
            Character* newLeader = findLeader();
            if (newLeader) {
                setLeader(newLeader);
            }
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

        Character* target = findTarget(other);

        if (target) {
            for (Character* member : getTeam()) {
                if (member->isAlive()) {
                    if (!target->isAlive()) {
                        target = findTarget(other);
                    }
                    if (target == nullptr) return; // No targets.
                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(target);
                        }
                        else {
                            cowboy->reload();
                        }
                    }
                    else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
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

    void SmartTeam::print() {
        for (Character* member : getTeam()) {
            std::cout << member->print() << std::endl;
        }
    }

    Character* SmartTeam::findTarget(Team *other) {
        Character* target = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* enemy : other->getTeam()) {
            if (enemy->isAlive()) {
                double distance = getLeader()->distance(enemy);
                if (distance < minDistance) {
                    minDistance = distance;
                    target = enemy;
                }
            }
        }
        return target;
    }

    Character* SmartTeam::findLeader() {
        // Find the nearest living character to be the new leader
        Character* newLeader = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character* member : getTeam()) {
            if (member->isAlive()) {
                double distance = getLeader()->distance(member);
                if (distance < minDistance) {
                    minDistance = distance;
                    newLeader = member;
                }
            }
        }
        return newLeader;
    }
}