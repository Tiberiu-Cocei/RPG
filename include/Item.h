#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "PlayerStats.h"

class Item
{
    public:
        Item(short int, short int, short int, short int, short int, short int, std::string, std::string, std::string, short int);
        virtual ~Item();
        virtual void use_item(PlayerStats& playerStats) = 0;
        virtual void find_item() = 0;

    protected:
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
