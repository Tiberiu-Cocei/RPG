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
        void equip_item(EquipableItem*);
        void get_equipment();
        PlayerStats* get_player_stats();

    private:
        PlayerStats* playerStats;
        EquipableItem* helmet;
        EquipableItem* body;
        EquipableItem* legs;
        EquipableItem* gloves;
        EquipableItem* boots;
        EquipableItem* mainHand;
        EquipableItem* offhand;
        void equip_helmet(EquipableItem*);
        void equip_body(EquipableItem*);
        void equip_legs(EquipableItem*);
        void equip_gloves(EquipableItem*);
        void equip_boots(EquipableItem*);
        void equip_main_hand(EquipableItem*);
        void equip_offhand(EquipableItem*);
        void concat_stats(std::string&, EquipableItem*);
};

#endif
