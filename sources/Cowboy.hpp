#pragma once

#include <iostream>
#include "Character.hpp"

static const int DEFAULT_HIT_POINTS_COWBOY = 110;
static const int BULLETS = 6;

namespace ariel {
    class Cowboy : public Character {
    private:
        int Bullets = BULLETS;
    public:
        Cowboy(std::string name, Point location) : Character(std::move(name), location, DEFAULT_HIT_POINTS_COWBOY) {}
        ~Cowboy() override = default;

        //for tidy:
        Cowboy(const Cowboy&) = delete;
        Cowboy& operator=(const Cowboy&) = delete;
        Cowboy(Cowboy&&) = delete;
        Cowboy& operator=(Cowboy&&) = delete;

        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
        std::string print() override;
    };
}