#pragma once

#include <iostream>
#include <vector>

#include "Team.hpp"

namespace ariel {

    class SmartTeam : public Team{
    private:
        std::vector<Character*> team;
    public:
        SmartTeam(Character* leader) : Team(leader){}

//        ~SmartTeam() = default;

        void attack(Team *other);
        void print();
    };
}