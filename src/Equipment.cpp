#include "Equipment.h"
#include <iostream>
#include <string.h>

Equipment::Equipment(PlayerStats*& playerStats) {
    this->helmet = new EquipableItem(0, 0, 0, 0, 0, 0, 2, 1, 1, 1,
                               "Leather helmet", "You have found a crudely made leather helmet.", "Equipped the leather helmet.", 1);
    this->body = new EquipableItem(0, 0, 0, 0, 0, 2, 0, 1, 2, 2,
                               "Leather body armor", "You have found a crudely made leather body armor.", "Equipped the leather body armor.", 51);
    this->legs = new EquipableItem(0, 0, 0, 0, 0, 1, 0, 1, 1, 3,
                               "Leather leg armor", "You have found a crudely made leather leg armor.", "Equipped the leather leg armor.", 101);
    this->gloves = new EquipableItem(0, 0, 0, 1, 0, 1, 0, 0, 1, 4,
                               "Leather gloves", "You have found a pair of crudely made leather gloves.", "Equipped the leather gloves.", 151);
    this->boots = new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 5,
                               "Leather boots", "You have found a pair of crudely made leather boots.", "Equipped the leather boots.", 201);
    this->mainHand = new EquipableItem(1, 0, 0, 2, 2, 0, 0, 0, 3, 6,
                               "Copper sword", "You have found a copper sword. It does not look like it's in good condition.", "Equipped the copper sword.", 251);
    this->offhand = new EquipableItem(0, 1, 0, 0, 0, 2, 0, 1, 2, 7,
                               "Copper shield", "You have found a copper shield. It does not look like it's in good condition.", "Equipped the copper shield.", 301);
    playerStats->gain_stats_from_equip(0, 3, 2, 6, 2, 5, 1, 1);
}

EquipableItem* Equipment::equip_item(EquipableItem* item, PlayerStats*& playerStats) {
    EquipableItem* toReturn;
    std::cout<<item->get_use_description() + "\n";
    int type = item->get_equipment_type();
    switch(type) {
        case 1 :
            toReturn = equip_helmet(item, playerStats);
            break;
        case 2 :
            toReturn = equip_body(item, playerStats);
            break;
        case 3 :
            toReturn = equip_legs(item, playerStats);
            break;
        case 4 :
            toReturn = equip_gloves(item, playerStats);
            break;
        case 5 :
            toReturn = equip_boots(item, playerStats);
            break;
        case 6 :
            toReturn = equip_main_hand(item, playerStats);
            break;
        case 7 :
            toReturn = equip_offhand(item, playerStats);
            break;
        default :
            toReturn = new EquipableItem(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM", 0);
            std::cout<<"ERROR_ITEM_EQUIP\n";
            break;
    }
    return toReturn;
}

EquipableItem* Equipment::equip_helmet(EquipableItem* helmet, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->helmet;
    playerStats->lose_stats_from_unequip(this->helmet->get_health_boost(), this->helmet->get_attack_boost(), this->helmet->get_strength_boost(),
                                               this->helmet->get_defense_boost(), this->helmet->get_luck_boost(), this->helmet->get_evasion_boost(),
                                               this->helmet->get_dmg_bonus(), this->helmet->get_dmg_reduction());
    this->helmet = helmet;
    playerStats->gain_stats_from_equip(this->helmet->get_health_boost(), this->helmet->get_attack_boost(), this->helmet->get_strength_boost(),
                                               this->helmet->get_defense_boost(), this->helmet->get_luck_boost(), this->helmet->get_evasion_boost(),
                                               this->helmet->get_dmg_bonus(), this->helmet->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_body(EquipableItem* body, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->body;
    playerStats->lose_stats_from_unequip(this->body->get_health_boost(), this->body->get_attack_boost(), this->body->get_strength_boost(),
                                               this->body->get_defense_boost(), this->body->get_luck_boost(), this->body->get_evasion_boost(),
                                               this->body->get_dmg_bonus(), this->body->get_dmg_reduction());
    this->body = body;
    playerStats->gain_stats_from_equip(this->body->get_health_boost(), this->body->get_attack_boost(), this->body->get_strength_boost(),
                                               this->body->get_defense_boost(), this->body->get_luck_boost(), this->body->get_evasion_boost(),
                                               this->body->get_dmg_bonus(), this->body->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_legs(EquipableItem* legs, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->legs;
    playerStats->lose_stats_from_unequip(this->legs->get_health_boost(), this->legs->get_attack_boost(), this->legs->get_strength_boost(),
                                               this->legs->get_defense_boost(), this->legs->get_luck_boost(), this->legs->get_evasion_boost(),
                                               this->legs->get_dmg_bonus(), this->legs->get_dmg_reduction());
    this->legs = legs;
    playerStats->gain_stats_from_equip(this->legs->get_health_boost(), this->legs->get_attack_boost(), this->legs->get_strength_boost(),
                                               this->legs->get_defense_boost(), this->legs->get_luck_boost(), this->legs->get_evasion_boost(),
                                               this->legs->get_dmg_bonus(), this->legs->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_gloves(EquipableItem* gloves, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->gloves;
    playerStats->lose_stats_from_unequip(this->gloves->get_health_boost(), this->gloves->get_attack_boost(), this->gloves->get_strength_boost(),
                                               this->gloves->get_defense_boost(), this->gloves->get_luck_boost(), this->gloves->get_evasion_boost(),
                                               this->gloves->get_dmg_bonus(), this->gloves->get_dmg_reduction());
    this->gloves = gloves;
    playerStats->gain_stats_from_equip(this->gloves->get_health_boost(), this->gloves->get_attack_boost(), this->gloves->get_strength_boost(),
                                               this->gloves->get_defense_boost(), this->gloves->get_luck_boost(), this->gloves->get_evasion_boost(),
                                               this->gloves->get_dmg_bonus(), this->gloves->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_boots(EquipableItem* boots, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->boots;
    playerStats->lose_stats_from_unequip(this->boots->get_health_boost(), this->boots->get_attack_boost(), this->boots->get_strength_boost(),
                                               this->boots->get_defense_boost(), this->boots->get_luck_boost(), this->boots->get_evasion_boost(),
                                               this->boots->get_dmg_bonus(), this->boots->get_dmg_reduction());
    this->boots = boots;
    playerStats->gain_stats_from_equip(this->boots->get_health_boost(), this->boots->get_attack_boost(), this->boots->get_strength_boost(),
                                               this->boots->get_defense_boost(), this->boots->get_luck_boost(), this->boots->get_evasion_boost(),
                                               this->boots->get_dmg_bonus(), this->boots->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_main_hand(EquipableItem* mainHand, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->mainHand;
    playerStats->lose_stats_from_unequip(this->mainHand->get_health_boost(), this->mainHand->get_attack_boost(), this->mainHand->get_strength_boost(),
                                               this->mainHand->get_defense_boost(), this->mainHand->get_luck_boost(), this->mainHand->get_evasion_boost(),
                                               this->mainHand->get_dmg_bonus(), this->mainHand->get_dmg_reduction());
    this->mainHand = mainHand;
    playerStats->gain_stats_from_equip(this->mainHand->get_health_boost(), this->mainHand->get_attack_boost(), this->mainHand->get_strength_boost(),
                                               this->mainHand->get_defense_boost(), this->mainHand->get_luck_boost(), this->mainHand->get_evasion_boost(),
                                               this->mainHand->get_dmg_bonus(), this->mainHand->get_dmg_reduction());
    return toReturn;
}

EquipableItem* Equipment::equip_offhand(EquipableItem* offhand, PlayerStats*& playerStats) {
    EquipableItem* toReturn = this->offhand;
    playerStats->lose_stats_from_unequip(this->offhand->get_health_boost(), this->offhand->get_attack_boost(), this->offhand->get_strength_boost(),
                                               this->offhand->get_defense_boost(), this->offhand->get_luck_boost(), this->offhand->get_evasion_boost(),
                                               this->offhand->get_dmg_bonus(), this->offhand->get_dmg_reduction());
    this->offhand = offhand;
    playerStats->gain_stats_from_equip(this->offhand->get_health_boost(), this->offhand->get_attack_boost(), this->offhand->get_strength_boost(),
                                               this->offhand->get_defense_boost(), this->offhand->get_luck_boost(), this->offhand->get_evasion_boost(),
                                               this->offhand->get_dmg_bonus(), this->offhand->get_dmg_reduction());
    return toReturn;
}

void Equipment::get_equipment() {
    std::string equipment = "Your current equipment is:\n";

    equipment += this->helmet->get_name() + " -";
    this->helmet->concat_stats(equipment);
    equipment += this->body->get_name() + " -";
    this->body->concat_stats(equipment);
    equipment += this->legs->get_name() + " -";
    this->legs->concat_stats(equipment);
    equipment += this->gloves->get_name() + " -";
    this->gloves->concat_stats(equipment);
    equipment += this->boots->get_name() + " -";
    this->boots->concat_stats(equipment);
    equipment += this->mainHand->get_name() + " -";
    this->mainHand->concat_stats(equipment);
    equipment += this->offhand->get_name() + " -";
    this->offhand->concat_stats(equipment);

    std::cout<<equipment;
}

void Equipment::get_save_data(std::string& saveData) {
    saveData += "4\n" + std::to_string(helmet->get_id()) + " " + std::to_string(body->get_id()) + " " + std::to_string(legs->get_id()) + " " +
                        std::to_string(gloves->get_id()) + " " + std::to_string(boots->get_id()) + " " + std::to_string(mainHand->get_id()) + " " +
                        std::to_string(offhand->get_id()) + "\n";
}

void Equipment::load_save_data(int helmet, int body, int legs, int gloves, int boots, int mainHand, int offhand) {
    EquipableItemList itemList = EquipableItemList();
    this->helmet = itemList.get_equipable_item(helmet);
    this->body = itemList.get_equipable_item(body);
    this->legs = itemList.get_equipable_item(legs);
    this->gloves = itemList.get_equipable_item(gloves);
    this->boots = itemList.get_equipable_item(boots);
    this->mainHand = itemList.get_equipable_item(mainHand);
    this->offhand = itemList.get_equipable_item(offhand);
}

Equipment::~Equipment() {}
