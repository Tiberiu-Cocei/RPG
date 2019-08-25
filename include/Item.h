#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "PlayerStats.h"

class Item
{
    public:
        Item(int, int, int, int, int, int, int, std::string, std::string, std::string);
        virtual ~Item();
        virtual void use_item(PlayerStats*& playerStats) = 0;
        virtual void find_item() = 0;

        std::string get_name();
        std::string get_find_description();
        std::string get_use_description();
        int get_health_boost();
        int get_attack_boost();
        int get_strength_boost();
        int get_defense_boost();
        int get_luck_boost();
        int get_evasion_boost();
        int get_weight();

    private:
        int healthBoost;
        int attackBoost;
        int strengthBoost;
        int defenseBoost;
        int luckBoost;
        int evasionBoost;
        int weight;
        std::string name;
        std::string findDescription;
        std::string useDescription;
};

#endif
