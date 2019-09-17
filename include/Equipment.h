#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "EquipableItem.h"
#include <iostream>
#include <string.h>
#include "PlayerStats.h"

class Equipment
{
    public:
        Equipment(PlayerStats*&);
        ~Equipment();
        EquipableItem* equip_item(EquipableItem*, PlayerStats*&);
        void get_equipment();
        void get_save_data(std::string&);

    private:
        EquipableItem* helmet;
        EquipableItem* body;
        EquipableItem* legs;
        EquipableItem* gloves;
        EquipableItem* boots;
        EquipableItem* mainHand;
        EquipableItem* offhand;
        EquipableItem* equip_helmet(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_body(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_legs(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_gloves(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_boots(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_main_hand(EquipableItem*, PlayerStats*&);
        EquipableItem* equip_offhand(EquipableItem*, PlayerStats*&);
};

#endif
