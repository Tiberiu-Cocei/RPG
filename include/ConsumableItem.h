#ifndef CONSUMABLEITEM_H
#define CONSUMABLEITEM_H

#include <Item.h>
#include "PlayerStats.h"
#include <string>

class ConsumableItem : public Item
{
    public:
        ConsumableItem(short int, short int, short int, short int, short int, short int, short int, short int, std::string, std::string, std::string);
        ~ConsumableItem();
        void use_item(PlayerStats playerStats);
        void set_healing(short int);
        short int get_healing();
        void set_healthBoost(short int);
        short int get_healthBoost();
        void set_attackBoost(short int);
        short int get_attackBoost();
        void set_strengthBoost(short int);
        short int get_strengthBoost();
        void set_defenseBoost(short int);
        short int get_defenseBoost();
        void set_luckBoost(short int);
        short int get_luckBoost();
        void set_evasionBoost(short int);
        short int get_evasionBoost();

    protected:
        short int healing;
        short int healthBoost;
        short int attackBoost;
        short int strengthBoost;
        short int defenseBoost;
        short int luckBoost;
        short int evasionBoost;
};

#endif
