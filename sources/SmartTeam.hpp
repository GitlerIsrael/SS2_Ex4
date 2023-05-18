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
        void attack(Team *other) override;
        void print() override;
        Character* findTarget(Team *other) override;
        Character* findLeader() override;
    };
}