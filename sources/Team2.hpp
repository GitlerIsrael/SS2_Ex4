#pragma once

#include <iostream>
#include <vector>

#include "Team.hpp"

namespace ariel {

    class Team2 : public Team{
    private:
        std::vector<Character*> team;
    public:
        Team2(Character* leader) : Team(leader){}

//        ~Team2() = default;

        void attack(Team *other);
        void print();
    };
}