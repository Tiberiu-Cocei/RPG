#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "EquipableItem.h"
#include <iostream>
#include <string.h>
#include "PlayerStats.h"

class Equipment
{
    public:
        Equipment(PlayerStats*);
        ~Equipment();
        EquipableItem* equip_item(EquipableItem*);
        void get_equipment();
        PlayerStats*& get_player_stats();

    private:
        PlayerStats* playerStats;
        EquipableItem* helmet;
        EquipableItem* body;
        EquipableItem* legs;
        EquipableItem* gloves;
        EquipableItem* boots;
        EquipableItem* mainHand;
        EquipableItem* offhand;
        EquipableItem* equip_helmet(EquipableItem*);
        EquipableItem* equip_body(EquipableItem*);
        EquipableItem* equip_legs(EquipableItem*);
        EquipableItem* equip_gloves(EquipableItem*);
        EquipableItem* equip_boots(EquipableItem*);
        EquipableItem* equip_main_hand(EquipableItem*);
        EquipableItem* equip_offhand(EquipableItem*);
        void concat_stats(std::string&, EquipableItem*);
};

#endif
