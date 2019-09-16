#ifndef EQUIPABLEITEM_H
#define EQUIPABLEITEM_H

#include <Item.h>
#include <string>
#include "PlayerStats.h"

class EquipableItem : public Item
{
    public:
        EquipableItem(int, int, int, int, int, int, int, int, int, int, std::string, std::string, std::string);
        ~EquipableItem();
        void use_item(PlayerStats*&);
        void unequip_item(PlayerStats*&);
        void find_item();
        int get_dmg_bonus();
        int get_dmg_reduction();
        int get_equipment_type();
        void concat_stats(std::string&);

    private:
        int dmgBonus;
        int dmgReduction;
        // 1 - helmet, 2 - body, 3 - legs, 4 - gloves, 5 - boots, 6 - weapon, 7 - offhand
        int equipmentType;
};

#endif
