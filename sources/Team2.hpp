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
        void attack(Team *other) override;
        void print() override;
        Character* findTarget(Team *other) override;
        Character* findLeader() override;
    };
}