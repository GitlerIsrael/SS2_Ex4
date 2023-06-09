//
// Created by israel on 5/15/23.
//

#include "Cowboy.hpp"

namespace ariel{
    // Shoot func
    void Cowboy::shoot(Character *enemy) {
        if (!this->isAlive() || !enemy->isAlive()) throw std::runtime_error("Can't attack if dead");
        if (this==enemy) throw std::runtime_error("No self harm");
        if (this->Bullets == 0) {
            // out of ammo
            return;
        }

        // Reduce bullets and shoot enemy
        this->Bullets--;
        enemy->hit(10);
    }

    // Returns if cowboy has bullets in his magazine.
    bool Cowboy::hasboolets() {
        return Bullets > 0;
    }

    // Reload cowboy magazine with 6 bullets.
    void Cowboy::reload() {
        if (!isAlive()) throw std::runtime_error("DEAD- Can't reload");
        Bullets = 6;
    }

    // Prints cowboy details.
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