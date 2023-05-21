//
// Created by israel on 5/15/23.
//
#include "SmartTeam.hpp"
#include <limits>
#include <algorithm>

namespace ariel {

    // SmartTeam attack function.
    void SmartTeam::attack(Team* other) {
        // Throw exceptions
        if (other == nullptr) throw std::invalid_argument("Invalid team pointer - nullptr");
        if (this == other) throw std::runtime_error("No self harm");
        if (!other->stillAlive()) throw std::runtime_error("Dead team");

        // Check if leader alive. if not - find new leader.
        if (!getLeader()->isAlive()) {
            Character* newLeader = findLeader();
            if (newLeader)
                setLeader(newLeader);
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

        // Find target to attack.
        Character* target = findTarget(other);

        if (target) {
            // Iterate over team fighters and attack target.
            for (Character* member : getTeam()) {
                if (member->isAlive()) {
                    // Check target still alive. if not - find new target.
                    if (!target->isAlive()) {
                        target = findTarget(other);
                        if (target == nullptr)
                            return; // No targets.
                    }
                    if (Cowboy* cowboy = dynamic_cast<Cowboy*>(member)) {
                        if (cowboy->hasboolets()) {
                            cowboy->shoot(target);
                        }
                        else {
                            // If cowboy has no bullets - reload.
                            cowboy->reload();
                        }
                    }
                    else if (Ninja* ninja = dynamic_cast<Ninja*>(member)) {
                        if (ninja->distance(target) <= 1.0) {
                            ninja->slash(target);
                        }
                        else {
                            // If ninja can't attack - get closer.
                            ninja->move(target);
                        }
                    }
                }
            }
        }
    }
    // prints team fighters
    void SmartTeam::print() {
        for (Character* member : getTeam()) {
            std::cout << member->print() << std::endl;
        }
    }

    // Find target (ninjas and then cowboys) -- ninjas make more damage.
    Character* SmartTeam::findTarget(Team* other) {
        Character* target = nullptr;

        for (Character* enemy : other->getTeam()) {
            if (enemy->isAlive()) {
                if (Ninja *ninja = dynamic_cast<Ninja *>(enemy)) {
                    target = enemy;
                    break;
                }
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(enemy)) {
                    target = enemy;
                    break;
                }
            }
        }
        return target;
    }

    // Find leader.
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
