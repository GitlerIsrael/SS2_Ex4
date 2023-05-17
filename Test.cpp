//
// Created by israel on 5/15/23.
//
#include "doctest.h"
#include <stdexcept>

#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include <cmath>

using namespace std;
using namespace ariel;



TEST_CASE("Point class TESTS") {
    Point p1(0,0);
    Point p2(0,1);
    Point p3(1,1);

    SUBCASE("Check moveTowards friend func") {
        Point p4 = moveTowards(p1,p2,2);// has to move to p2 because the distance between p1-p2 is less than 2.
        double x4 = p4.getXval();
        double y4 = p4.getYval();
        CHECK_EQ(x4, p2.getXval());
        CHECK_EQ(y4, p2.getYval());

        Point p5 = moveTowards(p1,p3,1);// has to move just 1 in the direction of p2.
        double x5 = p5.getXval();
        double y5 = p5.getYval();
        CHECK_NE(x5, p3.getXval());
        CHECK_NE(y5, p2.getYval());
    }

    SUBCASE("Check distance func") {
        CHECK((p1.distance(p2) == 1));
        CHECK((p1.distance(p3) == sqrt(2.0)));
        CHECK((p2.distance(p3) == 1));
    }

}

TEST_CASE("Cowboy class TESTS") {
    Point p1(0, 0);
    Cowboy cow{"cowboy", p1};
    CHECK(cow.hasboolets());
    CHECK_EQ(cow.getName(), "cowboy");
    CHECK(cow.isAlive());

    Point p2(0, 1);
    Cowboy cow2{"cowboy2", p2};
    CHECK((cow.distance(&cow2) == 1));

    cow.shoot(&cow2);
    CHECK((cow.hasboolets()));
    for (int i = 1; i <= 5; ++i) {
        cow.shoot(&cow2);
    }
    CHECK((!cow.hasboolets())); //out of ammo.
    cow.reload();
    CHECK((cow.hasboolets())); //has ammo after reload.

    Cowboy cow3{"cowboy3", p1};
    cow3.hit(50);
    CHECK(cow3.isAlive());
    CHECK_EQ(cow3.getHitPoints(), 60);
}


TEST_CASE("Ninjas classes TESTS"){
    // Create a YoungNinja
    YoungNinja youngNinja("YoungNinja", Point(2, 2));

    // Create a TrainedNinja
    TrainedNinja trainedNinja("TrainedNinja", Point(4, 4));

    // Create an OldNinja
    OldNinja oldNinja("OldNinja", Point(4.5, 4.5));

    CHECK_EQ(youngNinja.getName(), "YoungNinja");
    CHECK_EQ(youngNinja.getLocation().getXval(), 2);
    CHECK_EQ(youngNinja.getLocation().getYval(), 2);
    youngNinja.move(&trainedNinja);
    CHECK_EQ(youngNinja.getLocation().getXval(), 4);
    CHECK_EQ(youngNinja.getLocation().getYval(), 4);


    CHECK_EQ(trainedNinja.getName(), "TrainedNinja");
    CHECK_EQ(trainedNinja.getLocation().getXval(), 4);
    CHECK_EQ(trainedNinja.getLocation().getYval(), 4);
    trainedNinja.move(&oldNinja);
    CHECK_EQ(trainedNinja.getLocation().getXval(), 4.5);
    CHECK_EQ(trainedNinja.getLocation().getYval(), 4.5);


    CHECK_EQ(oldNinja.getName(), "OldNinja");
    CHECK_EQ(oldNinja.getLocation().getXval(), 4.5);
    CHECK_EQ(oldNinja.getLocation().getYval(), 4.5);
    oldNinja.move(&trainedNinja);
    CHECK_EQ(oldNinja.getLocation().getXval(), 4);
    CHECK_EQ(oldNinja.getLocation().getYval(), 4);

    for (int i = 1; i <= 3; ++i) {
        trainedNinja.slash(&youngNinja);
    }
    CHECK(!youngNinja.isAlive());
    CHECK_EQ(youngNinja.getHitPoints(), -20);
}

TEST_CASE("Teams classes Tests"){
    OldNinja oldNinja("oldNinja", Point(0, 0));
    YoungNinja youngNinja("YoungNinja", Point(1, 1));
    TrainedNinja trainedNinja("TrainedNinja", Point(2, 2));
    OldNinja oldNinja1("oldNinja", Point(0, 0));
    YoungNinja youngNinja1("YoungNinja", Point(1, 1));
    TrainedNinja trainedNinja1("TrainedNinja", Point(2, 2));
    OldNinja oldNinja2("oldNinja", Point(0, 0));
    YoungNinja youngNinja2("YoungNinja", Point(1, 1));
    TrainedNinja trainedNinja2("TrainedNinja", Point(2, 2));
    Point p(0,0);
    Cowboy cowboy("cowboy", p);
    Point p1(1,1);
    Cowboy cowboy1("cowboy", p);

    // Create a Team and add Ninjas to it
    Team team(&oldNinja);
    team.add(&youngNinja);
    team.add(&trainedNinja);
    CHECK_EQ(team.getTeamSize(), 3);
    CHECK_THROWS(team.add(&oldNinja)); // already in the team.
    team.add(&oldNinja1);
    team.add(&oldNinja2);
    team.add(&youngNinja1);
    team.add(&youngNinja2);
    team.add(&trainedNinja1);
    team.add(&trainedNinja2);
    CHECK_NOTHROW(team.add(&cowboy));
    CHECK_THROWS(team.add(&cowboy1)); // can't add more than 10 fighters to team.

    Point p2(2,2);
    Cowboy cowboy2("cowboy", p2);

    // Create a SmartTeam and add Ninjas to it
    SmartTeam smartTeam(&cowboy2);
    CHECK_THROWS(smartTeam.add(&oldNinja)); // already in team. can't be in 2 teams at same time.
    CHECK_EQ(smartTeam.getTeamSize(), 1);
    CHECK_NE(smartTeam.getTeamSize(), 2);

    // Attack all the characters in the smart team
    CHECK_NOTHROW(team.attack(&smartTeam));


    OldNinja oldNinja3("oldNinja", Point(0, 0));
    YoungNinja youngNinja3("YoungNinja", Point(1, 1));
    TrainedNinja trainedNinja3("TrainedNinja", Point(2, 2));
    Point p3(0,0);
    Cowboy cowboy3("cowboy", p);

    // Create a Team2 and add Ninjas to it
    Team2 team2(&trainedNinja3);
    team2.add(&oldNinja3);
    team2.add(&youngNinja3);
    team2.add(&cowboy3);
    CHECK_EQ(team2.getTeamSize(), 4);

    // Attack all the characters in the team2
    CHECK_NOTHROW(team2.attack(&team));
}


