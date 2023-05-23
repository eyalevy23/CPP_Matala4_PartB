#include <iostream>
#include "Character.hpp"
#include "Team.hpp"
#include "Point.hpp"

#ifndef TEAM2_H
#define TEAM2_H

namespace ariel
{
    class Team2 : public Team
    {
        public:
            Team2(Character *leader);
            void attack(Team* teamToAttack) override;
    };
}
#endif
