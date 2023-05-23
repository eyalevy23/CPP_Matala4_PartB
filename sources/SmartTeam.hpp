#include <iostream>
#include "Character.hpp"
#include "Team.hpp"
#include "Point.hpp"

#ifndef SMARTTEAM_H
#define SMARTTEAM_H

namespace ariel
{
    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character *leader);
    };
}
#endif
