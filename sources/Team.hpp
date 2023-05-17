#pragma once

#include <iostream>
#include <vector>

#include "Character.hpp"
#include "Cowboy.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"

namespace ariel {

    class Team {
    private:
        Character* leader;
        std::vector<Character*> team;
    public:
        Team(Character* leader) : leader(leader){}
        ~Team() = default;

        //for tidy:
        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;

        int getTeamSize();
        void add(Character* character);
        void attack(Team *other);
        int stillAlive();
        void print();

    };
}