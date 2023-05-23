#include <iostream>
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"
#include "doctest.h"
using namespace ariel;

TEST_CASE("Test Point"){
    Point p1(0,0);
    Point p2(2,2);
    Point p3(4,4);
    Point p4(6,6);
    Point p5(8,8);

    CHECK(p1.distance(p2)==2);
    CHECK(p1.distance(p3)==4);
    CHECK(p1.distance(p4)==6);
    CHECK(p1.distance(p5)==8);
    CHECK(p2.distance(p3)==2);
    CHECK(p2.distance(p4)==4);
    CHECK(p2.distance(p5)==6);
    CHECK(p3.distance(p4)==2);
    CHECK(p3.distance(p5)==4);

}

TEST_CASE("Test Character"){
    Point p1(0,0);
    Point p2(2,2);
    Point p3(4,4);
    Point p4(6,6);
    Point p5(8,8);

    Cowboy *cowboy = new Cowboy("Eyal",p1);
    YoungNinja *yNinja = new YoungNinja("Meir",p2);
    OldNinja *oNinja = new OldNinja("Yossi",p3);
    TrainedNinja *tNinja = new TrainedNinja("Dor",p4);

    CHECK(cowboy->isAlive());
    CHECK(yNinja->isAlive());
    CHECK(oNinja->isAlive());
    CHECK(tNinja->isAlive());

    CHECK(cowboy->getHealth()==100);
    CHECK(yNinja->getHealth()==100);
    CHECK(oNinja->getHealth()==100);
    CHECK(tNinja->getName()=="Dor");
    CHECK(cowboy->getName()=="Eyal");
    CHECK(yNinja->getName()=="Meir");
    CHECK(oNinja->getName()=="Yossi");
    
}

TEST_CASE("Test Team"){
    Point p1(0,0);
    Point p2(2,2);
    Point p3(4,4);
    Point p4(6,6);
    Point p5(8,8);

    Cowboy *cowboy = new Cowboy("Eyal",p1);
    YoungNinja *yNinja = new YoungNinja("Meir",p2);
    OldNinja *oNinja = new OldNinja("Yossi",p3);
    TrainedNinja *tNinja = new TrainedNinja("Dor",p4);

    Team *team = new Team(cowboy);
    team->add(cowboy);
    team->add(yNinja);
    team->add(oNinja);

    
    CHECK(team->getTeamSize()==0);
    CHECK(team->getTeamName()=="");
    


}