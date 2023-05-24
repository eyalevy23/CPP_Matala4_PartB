#ifndef TEAM_H
#define TEAM_H

#include "Character.hpp"
#include <iostream>
#include <string>
#include <vector>


namespace ariel{
    class Team
    {
        public:
        // std::vector<Character*> myTeam;
            Character **members;
            int currentTeamSize;
            Character *leader;

            Team(Character *leader);//declare default constructor
            virtual ~Team();//declare destructor
            void add(Character *leader);
            virtual void attack(Team *team);
            int stillAlive();
            int getTeamSize();
            // std::string getTeamName();
            std::string getTeamLeaderName();
            Character getCharacter();
            void print();
            Character* findClosestEnemy(Team *teamToAttack);
            void teamOrder();
            int changeLeader(Team* team);

            // copy constructor
            Team(Team &);
            // copy assignment operator
            Team &operator=(const Team &) noexcept;
            // move constructor
            Team(Team &&) noexcept;
            // move assignment operator
            Team &operator=(Team &&) noexcept;
    };
}

#endif