//
// Created by israel on 5/15/23.
//

#include "Cowboy.hpp"

namespace ariel{
    void Cowboy::shoot(Character *enemy) {
        if (!this->isAlive() || this->Bullets == 0) {
            // Cowboy is dead or out of ammo
            return;
        }

        // Reduce bullets and shoot enemy
        this->Bullets--;
        enemy->hit(10);
    }

    bool Cowboy::hasboolets() {
        return Bullets > 0;
    }

    void Cowboy::reload() {
        Bullets = 6;
    }

    std::string Cowboy::print() {
        std::string s = "";
        if(isAlive()) {
            s += "C: " + getName() + ", Hit points: " + std::to_string(getHitPoints()) +
                            ", Location: (" + std::to_string(getLocation().getXval()) + ", " +
                            std::to_string(getLocation().getYval()) + ")";
        } else{
            s += "C: (" + getName() + "), Location: (" + std::to_string(getLocation().getXval()) + ", " +
                            std::to_string(getLocation().getYval()) + ")";
        }
        return s;
    }
}


