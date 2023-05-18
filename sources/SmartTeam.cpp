//
// Created by israel on 5/15/23.
//
#include "SmartTeam.hpp"
#include <limits>
#include <algorithm>

namespace ariel {

    void SmartTeam::attack(Team* other) {
        // Throw exceptions
        if (other == nullptr) throw std::invalid_argument("Invalid team pointer - nullptr");
        if (this == other) throw std::runtime_error("No self harm");
        if (!other->stillAlive()) throw std::runtime_error("Dead team");

        if (!getLeader()->isAlive()) {
            Character* newLeader = findLeader();
            if (newLeader)
                setLeader(newLeader);
            else {
                // No living members in the attacking team, attack ends
                return;
            }
        }

        Character* target = findTarget(other);

        if (target) {
            std::vector<Character*> enemyTeam = other->getTeam();
            std::sort(enemyTeam.begin(), enemyTeam.end(), [](Character* a, Character* b) {
                return a->getHitPoints() > b->getHitPoints();
            });

            for (Character* member : enemyTeam) {
                if (member->isAlive()) {
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
        std::vector<Character*> sortedTeam = getTeam();
        std::sort(sortedTeam.begin(), sortedTeam.end(), [](Character* a, Character* b) {
            return a->getHitPoints() > b->getHitPoints();
        });

        for (Character* member : sortedTeam) {
            std::cout << member->print() << std::endl;
        }
    }

    Character* SmartTeam::findTarget(Team* other) {
        Character* target = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        std::vector<Character*> enemyTeam = other->getTeam();
        std::sort(enemyTeam.begin(), enemyTeam.end(), [](Character* a, Character* b) {
            return a->getHitPoints() > b->getHitPoints();
        });

        for (Character* enemy : enemyTeam) {
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

        std::vector<Character*> sortedTeam = getTeam();
        std::sort(sortedTeam.begin(), sortedTeam.end(), [](Character* a, Character* b) {
            return a->getHitPoints() > b->getHitPoints();
        });

        for (Character* member : sortedTeam) {
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
