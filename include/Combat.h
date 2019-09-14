#ifndef COMBAT_H
#define COMBAT_H
#include "Enemy.h"
#include "Equipment.h"
#include <iostream>
#include <string.h>
#include "Inventory.h"
#include "Perk.h"
#include "PlayerStats.h"
#include <vector>
#include <map>

class Combat
{
    public:
        Combat();
        ~Combat();
        bool encounter(Equipment*&, PlayerStats*&, std::vector<Perk*>, Inventory*&, Enemy*&, bool = false);

    private:
        bool player_normal_attack(PlayerStats*&, std::vector<Perk*>, Enemy*&);
        bool enemy_turn(PlayerStats*&, Enemy*&);

        std::map<std::string, int> combatMapping;
        std::map<std::string, int>::iterator combatMappingIterator;
        std::string commandKey, itemIndex;
        int commandValue, itemIndexInt;
        bool isDead;
};

#endif
