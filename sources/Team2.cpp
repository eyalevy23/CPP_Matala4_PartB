#include "Team.hpp"
#include "Team2.hpp"
#include <iostream>

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    void Team2::attack(Team* teamToAttack)
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
            // throw std::runtime_error("Team is dead");
        }
        if(this == teamToAttack)
        {
            throw std::runtime_error("Team is attacking itself");
        }

        //change leader if needed
        if(members[0]->isAlive() == false)
        {
            for(int i = 0; i < currentTeamSize; i++)
            {
                if(members[i]->isAlive() == true)
                {
                    this->leader = members[i];
                    break;
                }
            }
        }
        //choose who is going to get attacked
        if(teamToAttack->stillAlive() == 0)
        {
            return;
        }
        Character* closestEnemy = findClosestEnemy(teamToAttack);

        //attack
        for(int i = 0; i < currentTeamSize; i++)
        {

            if(teamToAttack->stillAlive() == 0)
            {
                return;
            }
            if(closestEnemy->isAlive() == false)
            {
                closestEnemy = findClosestEnemy(teamToAttack);
                if(closestEnemy->isAlive() == false)
                {
                    return;
                }
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
                        // Ninja* currentCharacter = dynamic_cast<Ninja*>(currentCharacter);
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
    }
}