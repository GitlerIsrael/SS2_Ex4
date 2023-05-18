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
        Team(Character* leader) {
            if(leader->getIsINTeam()) throw std::runtime_error ("Already in team.");
            this->leader = leader;
            team.push_back(leader);
            leader->setIsInTeam();
        }
        ~Team() {
            for (Character* member : team) {
                delete member;
            }
        }

        //for tidy:
        Team(const Team&) = delete;
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;

        int getTeamSize();
        Character* getLeader();
        void setLeader(Character* leader);
        std::vector<Character*>& getTeam();
        void add(Character* character);
        virtual void attack(Team *other);
        int stillAlive();
        virtual void print();
        virtual Character* findTarget(Team *other);
        virtual Character* findLeader();

    };
}