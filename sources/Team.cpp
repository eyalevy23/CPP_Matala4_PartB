#include "Team.hpp"
#include "Character.hpp"
#include <iostream>
#include <string>
#include <vector>

unsigned long MAXTEAMSIZE = 10;
using namespace std;
namespace ariel
{

    // copy constructor
    Team::Team(Team &) {}
    // copy assignment operator
    Team &Team::operator=(const Team &_otherTeam) noexcept 
    {
        return *this;
    }
    // move constructor
    Team::Team(Team &&_otherTeam) noexcept {}
    // move assignment operator
    Team &Team::operator=(Team &&_otherTeam) noexcept 
    {
        return _otherTeam = *this;
    }

    // destructor
    Team::~Team()
    {
        for (int i = 0; i < currentTeamSize; i++)
        {
            delete members[i];
        }
        delete[] members;
    }

    Team::Team(Character *leader) : leader(leader) //declare default constructor
    {   
        // std::vector<Character> myTeam;
        // myTeam.push_back(leader);
        this->currentTeamSize = 0;
        this->leader = leader;
        this->members = new Character*[MAXTEAMSIZE];
        this->add(leader);
    }

    void Team::add(Character* character)
    {
        if(character == nullptr)
        {
            throw std::runtime_error("Character is null");
        }
        if(character->isMember())
        {
            throw std::runtime_error("Character is already in a team");
        }
        if(currentTeamSize == 10)
        {
            throw std::runtime_error("Team is full");
        }
        if(currentTeamSize < MAXTEAMSIZE)
        {
            this->members[currentTeamSize] = character;
            character->setIsMember(true);
            currentTeamSize++;
        }
    }

    Character* Team::findClosestEnemy(Team* teamToAttack)
    {
        //find closest enemy with Point
        int closestEnemyIndex = 0;
        double closestEnemyDistance = -1;
        for(int i = 0; i < teamToAttack->getTeamSize(); i++)
        {
            if(teamToAttack->members[i]->isAlive())
            {
                double temp = this->leader->distance(teamToAttack->members[i]);
                if(temp < closestEnemyDistance || closestEnemyDistance == -1)
                {
                    closestEnemyDistance = temp;
                    closestEnemyIndex = i;
                }
            }
        }
        return teamToAttack->members[closestEnemyIndex];
    }

    int Team::changeLeader(Team* team)
    {   
        int leaderIndex = 0;
        double distance = -1;
            Point leaderLocation = team->leader->getLocation();
            for(int i = 0; i < team->currentTeamSize; i++)
            {
                if(team->members[i] == team->leader)
                {
                    continue;
                }
                if(team->members[i]->isAlive())
                {
                    double temp = team->members[i]->getLocation().distance(leaderLocation);
                    if(temp < distance || distance == -1)
                    {
                        distance = temp;
                        team->leader = team->members[i];
                        leaderIndex = i;
                    }
                }
            }
            return leaderIndex;
    }

    void Team::attack(Team* teamToAttack)
    {
        if(teamToAttack == nullptr)
        {
            throw std::invalid_argument("Team is null");
        }
        if(teamToAttack->stillAlive() == 0 )
        {
            throw std::runtime_error("Team is dead");
        }
        if(this->stillAlive() == 0)
        {
            throw std::runtime_error("Team is dead");
        }
        if(this == teamToAttack)
        {
            throw std::runtime_error("Team is attacking itself");
        }
        //change leader if needed
        if(this->leader->isAlive() == false)
        {
            int l = changeLeader(this);
            this->leader = this->members[l];
        }
         
        Character* closestEnemy = findClosestEnemy(teamToAttack);

        //attack
        this->teamOrder();
        for(int i = 0; i < currentTeamSize; i++)
        {

            if(teamToAttack->stillAlive() == 0)
            {
                return;
            }
            
            if(closestEnemy->isAlive() == false)
            {
                closestEnemy = findClosestEnemy(teamToAttack);
            }
            Character* currentCharacter = members[i];
            if(currentCharacter->isAlive())
            {
                //check if cowboy and attack
                if(currentCharacter->getRole() == "Cowboy")
                {
                    currentCharacter->attack(closestEnemy);
                }
                else
                {
                    //check if ninja and attack
                    
                    if(currentCharacter->getRole() == "Ninja")
                    {
                        if(currentCharacter->distance(closestEnemy) > 1)
                        {
                            ((Ninja*)currentCharacter)->move(closestEnemy);
                        }
                        else if(currentCharacter->distance(closestEnemy) < 1)
                        {
                            currentCharacter->attack(closestEnemy);
                        }
                    }
                }
            }
        }
        // if leader of teamToAttack is dead, find new leader
        if(teamToAttack->leader->isAlive() == false)
        {
            int l = changeLeader(teamToAttack);
            teamToAttack->leader = teamToAttack->members[l];
        }
    }

    int Team::getTeamSize()
    {
        return (currentTeamSize);
    }
    
    int Team::stillAlive()
    {
        int alive = 0;
        for(int i = 0; i < this->getTeamSize(); i++)
        {
            if(this->members[i]->isAlive())
            {
                alive++;
            }
        }
        return alive;
    }



    void Team::print()
    {
        std::string printer = "";
        for(int i = 0; i < currentTeamSize; i++)
        {
            printer += members[i]->print() + "\n";
        }
        std::cout << printer << std::endl;
    }

    // std::string Team::getTeamName()
    // {
    //     //team name 
    //     std::string leaderName = members[0]->getName();
    //     return leaderName;
    // }

    std::string Team::getTeamLeaderName()
    {
        std::string leaderName = this->leader->getName();
        return leaderName;
    }

    void Team::teamOrder()
    {
        //set cowboy first
        for(int i = 0; i < currentTeamSize; i++)
        {
            if(members[i]->getRole() == "Cowboy")
            {
                Character* temp = members[0];
                members[0] = members[i];
                members[i] = temp;
            }
        }
    }
}