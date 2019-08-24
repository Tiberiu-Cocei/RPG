#include "Equipment.h"
#include <iostream>
#include <string.h>

Equipment::Equipment(PlayerStats* playerStats)
{
    this->playerStats = playerStats;
    this->helmet = new EquipableItem(0, 0, 0, 0, 0, 0, 2, 1, 1, 1,
                               "Leather helmet", "You have found a crudely made leather helmet.", "Equipped the leather helmet.");
    this->body = new EquipableItem(0, 0, 0, 0, 0, 2, 0, 1, 2, 2,
                               "Leather body armor", "You have found a crudely made leather body armor.", "Equipped the leather body armor.");
    this->legs = new EquipableItem(0, 0, 0, 0, 0, 1, 0, 1, 1, 3,
                               "Leather leg armor", "You have found a crudely made leather leg armor.", "Equipped the leather leg armor.");
    this->gloves = new EquipableItem(0, 0, 0, 1, 0, 1, 0, 0, 1, 4,
                               "Leather gloves", "You have found a pair of crudely made leather gloves.", "Equipped the leather gloves.");
    this->boots = new EquipableItem(0, 0, 0, 0, 0, 0, 0, 1, 1, 5,
                               "Leather boots", "You have found a pair of crudely made leather boots.", "Equipped the leather boots.");
    this->mainHand = new EquipableItem(1, 0, 0, 2, 2, 0, 0, 0, 3, 6,
                               "Copper sword", "You have found a copper sword. It does not look like it's in good condition.", "Equipped the copper sword.");
    this->offhand = new EquipableItem(0, 1, 0, 0, 0, 2, 0, 1, 2, 7,
                               "Copper shield", "You have found a copper shield. It does not look like it's in good condition.", "Equipped the copper shield.");
    this->playerStats->gain_stats_from_equip(0, 3, 2, 6, 2, 5, 1, 1);
}

PlayerStats* Equipment::get_player_stats() {
    return this->playerStats;
}

void Equipment::equip_item(EquipableItem* item) {
    std::cout<<item->get_use_description() + "\n";
    short int type = item->get_equipment_type();
    switch(type) {
        case 1 :
            equip_helmet(item);
            break;
        case 2 :
            equip_body(item);
            break;
        case 3 :
            equip_legs(item);
            break;
        case 4 :
            equip_gloves(item);
            break;
        case 5 :
            equip_boots(item);
            break;
        case 6 :
            equip_main_hand(item);
            break;
        case 7 :
            equip_offhand(item);
            break;
        default :
            std::cout<<"ERROR_ITEM_EQUIP\n";
            break;
    }
}

void Equipment::equip_helmet(EquipableItem* helmet) {
    this->playerStats->lose_stats_from_unequip(this->helmet->get_health_boost(), this->helmet->get_attack_boost(), this->helmet->get_strength_boost(),
                                               this->helmet->get_defense_boost(), this->helmet->get_luck_boost(), this->helmet->get_evasion_boost(),
                                               this->helmet->get_dmg_bonus(), this->helmet->get_dmg_reduction());
    this->helmet = helmet;
    this->playerStats->gain_stats_from_equip(this->helmet->get_health_boost(), this->helmet->get_attack_boost(), this->helmet->get_strength_boost(),
                                               this->helmet->get_defense_boost(), this->helmet->get_luck_boost(), this->helmet->get_evasion_boost(),
                                               this->helmet->get_dmg_bonus(), this->helmet->get_dmg_reduction());
}

void Equipment::equip_body(EquipableItem* body) {
    this->playerStats->lose_stats_from_unequip(this->body->get_health_boost(), this->body->get_attack_boost(), this->body->get_strength_boost(),
                                               this->body->get_defense_boost(), this->body->get_luck_boost(), this->body->get_evasion_boost(),
                                               this->body->get_dmg_bonus(), this->body->get_dmg_reduction());
    this->body = body;
    this->playerStats->gain_stats_from_equip(this->body->get_health_boost(), this->body->get_attack_boost(), this->body->get_strength_boost(),
                                               this->body->get_defense_boost(), this->body->get_luck_boost(), this->body->get_evasion_boost(),
                                               this->body->get_dmg_bonus(), this->body->get_dmg_reduction());
}

void Equipment::equip_legs(EquipableItem* legs) {
    this->playerStats->lose_stats_from_unequip(this->legs->get_health_boost(), this->legs->get_attack_boost(), this->legs->get_strength_boost(),
                                               this->legs->get_defense_boost(), this->legs->get_luck_boost(), this->legs->get_evasion_boost(),
                                               this->legs->get_dmg_bonus(), this->legs->get_dmg_reduction());
    this->legs = legs;
    this->playerStats->gain_stats_from_equip(this->legs->get_health_boost(), this->legs->get_attack_boost(), this->legs->get_strength_boost(),
                                               this->legs->get_defense_boost(), this->legs->get_luck_boost(), this->legs->get_evasion_boost(),
                                               this->legs->get_dmg_bonus(), this->legs->get_dmg_reduction());
}

void Equipment::equip_gloves(EquipableItem* gloves) {
    this->playerStats->lose_stats_from_unequip(this->gloves->get_health_boost(), this->gloves->get_attack_boost(), this->gloves->get_strength_boost(),
                                               this->gloves->get_defense_boost(), this->gloves->get_luck_boost(), this->gloves->get_evasion_boost(),
                                               this->gloves->get_dmg_bonus(), this->gloves->get_dmg_reduction());
    this->gloves = gloves;
    this->playerStats->gain_stats_from_equip(this->gloves->get_health_boost(), this->gloves->get_attack_boost(), this->gloves->get_strength_boost(),
                                               this->gloves->get_defense_boost(), this->gloves->get_luck_boost(), this->gloves->get_evasion_boost(),
                                               this->gloves->get_dmg_bonus(), this->gloves->get_dmg_reduction());
}

void Equipment::equip_boots(EquipableItem* boots) {
    this->playerStats->lose_stats_from_unequip(this->boots->get_health_boost(), this->boots->get_attack_boost(), this->boots->get_strength_boost(),
                                               this->boots->get_defense_boost(), this->boots->get_luck_boost(), this->boots->get_evasion_boost(),
                                               this->boots->get_dmg_bonus(), this->boots->get_dmg_reduction());
    this->boots = boots;
    this->playerStats->gain_stats_from_equip(this->boots->get_health_boost(), this->boots->get_attack_boost(), this->boots->get_strength_boost(),
                                               this->boots->get_defense_boost(), this->boots->get_luck_boost(), this->boots->get_evasion_boost(),
                                               this->boots->get_dmg_bonus(), this->boots->get_dmg_reduction());
}

void Equipment::equip_main_hand(EquipableItem* mainHand) {
    this->playerStats->lose_stats_from_unequip(this->mainHand->get_health_boost(), this->mainHand->get_attack_boost(), this->mainHand->get_strength_boost(),
                                               this->mainHand->get_defense_boost(), this->mainHand->get_luck_boost(), this->mainHand->get_evasion_boost(),
                                               this->mainHand->get_dmg_bonus(), this->mainHand->get_dmg_reduction());
    this->mainHand = mainHand;
    this->playerStats->gain_stats_from_equip(this->mainHand->get_health_boost(), this->mainHand->get_attack_boost(), this->mainHand->get_strength_boost(),
                                               this->mainHand->get_defense_boost(), this->mainHand->get_luck_boost(), this->mainHand->get_evasion_boost(),
                                               this->mainHand->get_dmg_bonus(), this->mainHand->get_dmg_reduction());
}

void Equipment::equip_offhand(EquipableItem* offhand) {
    this->playerStats->lose_stats_from_unequip(this->offhand->get_health_boost(), this->offhand->get_attack_boost(), this->offhand->get_strength_boost(),
                                               this->offhand->get_defense_boost(), this->offhand->get_luck_boost(), this->offhand->get_evasion_boost(),
                                               this->offhand->get_dmg_bonus(), this->offhand->get_dmg_reduction());
    this->offhand = offhand;
    this->playerStats->gain_stats_from_equip(this->offhand->get_health_boost(), this->offhand->get_attack_boost(), this->offhand->get_strength_boost(),
                                               this->offhand->get_defense_boost(), this->offhand->get_luck_boost(), this->offhand->get_evasion_boost(),
                                               this->offhand->get_dmg_bonus(), this->offhand->get_dmg_reduction());
}

void Equipment::get_equipment() {
    std::string equipment = "Your current equipment is:\n";

    equipment += this->helmet->get_name() + " -";
    concat_stats(equipment, this->helmet);
    equipment += this->body->get_name() + " -";
    concat_stats(equipment, this->body);
    equipment += this->legs->get_name() + " -";
    concat_stats(equipment, this->legs);
    equipment += this->gloves->get_name() + " -";
    concat_stats(equipment, this->gloves);
    equipment += this->boots->get_name() + " -";
    concat_stats(equipment, this->boots);
    equipment += this->mainHand->get_name() + " -";
    concat_stats(equipment, this->mainHand);
    equipment += this->offhand->get_name() + " -";
    concat_stats(equipment, this->offhand);

    std::cout<<equipment;
}

void Equipment::concat_stats(std::string& equipment, EquipableItem* item) {
    if(item->get_dmg_bonus() != 0) {
        equipment += " damage bonus: +" + std::to_string(item->get_dmg_bonus()) + ",";
    }
    if(item->get_dmg_reduction() != 0) {
        equipment += " damage reduction: +" + std::to_string(item->get_dmg_reduction()) + ",";
    }
    if(item->get_health_boost() != 0) {
        equipment += " health: +" + std::to_string(item->get_health_boost()) + ",";
    }
    if(item->get_attack_boost() != 0) {
        equipment += " attack: +" + std::to_string(item->get_attack_boost()) + ",";
    }
    if(item->get_strength_boost() != 0) {
        equipment += " strength: +" + std::to_string(item->get_strength_boost()) + ",";
    }
    if(item->get_defense_boost() != 0) {
        equipment += " defense: +" + std::to_string(item->get_defense_boost()) + ",";
    }
    if(item->get_luck_boost() != 0) {
        equipment += " luck: +" + std::to_string(item->get_luck_boost()) + ",";
    }
    if(item->get_evasion_boost() != 0) {
        equipment += " evasion: +" + std::to_string(item->get_evasion_boost()) + ",";
    }
    equipment += " weight: +" + std::to_string(item->get_weight()) + "\n";
}

Equipment::~Equipment()
{
}
