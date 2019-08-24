#ifndef EQUIPABLEITEM_H
#define EQUIPABLEITEM_H

#include <Item.h>
#include <string>
#include "PlayerStats.h"

class EquipableItem : public Item
{
    public:
        EquipableItem(short int, short int, short int, short int, short int, short int, short int, short int, short int, short int, std::string, std::string, std::string);
        ~EquipableItem();
        void use_item(PlayerStats*& playerStats);
        void unequip_item(PlayerStats*& playerStats);
        void find_item();
        short int get_dmg_bonus();
        short int get_dmg_reduction();
        short int get_equipment_type();

    private:
        short int dmgBonus;
        short int dmgReduction;
        // 1 - helmet, 2 - body, 3 - legs, 4 - gloves, 5 - boots, 6 - weapon, 7 - offhand
        short int equipmentType;
};

#endif
