#ifndef EQUIPABLEITEM_H
#define EQUIPABLEITEM_H

#include <Item.h>
#include <string>
#include "PlayerStats.h"

class EquipableItem : public Item
{
    public:
        EquipableItem(short int, short int, short int, short int, short int, short int, short int, short int, short int, std::string, std::string, std::string);
        ~EquipableItem();
        void use_item(PlayerStats*& playerStats);
        void unequip_item(PlayerStats*& playerStats);
        void find_item();

    private:
        short int dmgBonus;
        short int dmgReduction;
};

#endif
