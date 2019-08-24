#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "PlayerStats.h"

class Item
{
    public:
        Item(short int, short int, short int, short int, short int, short int, std::string, std::string, std::string, short int);
        virtual ~Item();
        virtual void use_item(PlayerStats*& playerStats) = 0;
        virtual void find_item() = 0;

        std::string get_name();
        std::string get_find_description();
        std::string get_use_description();
        short int get_health_boost();
        short int get_attack_boost();
        short int get_strength_boost();
        short int get_defense_boost();
        short int get_luck_boost();
        short int get_evasion_boost();

    private:
        short int healthBoost;
        short int attackBoost;
        short int strengthBoost;
        short int defenseBoost;
        short int luckBoost;
        short int evasionBoost;
        std::string name;
        std::string findDescription;
        std::string useDescription;
        short int maxStack;
};

#endif
