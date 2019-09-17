#include "EquipableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

EquipableItem::EquipableItem(int dmgBonus, int dmgReduction, int healthBoost, int attackBoost, int strengthBoost,
                               int defenseBoost, int luckBoost, int evasionBoost, int weight, int equipmentType,
                               std::string name, std::string findDescription, std::string useDescription, int id)
: Item(healthBoost, attackBoost, strengthBoost, defenseBoost, luckBoost, evasionBoost, weight, name, findDescription, useDescription, id) {
    this->dmgBonus = dmgBonus;
    this->dmgReduction = dmgReduction;
    this->equipmentType = equipmentType;
}

void EquipableItem::find_item() {
    std::cout << get_find_description() << std::endl;
}

void EquipableItem::use_item(PlayerStats*& playerStats) {
    std::cout << get_use_description() << std::endl;
    playerStats->gain_stats_from_equip(get_health_boost(), get_attack_boost(), get_strength_boost(), get_defense_boost(),
                                      get_luck_boost(), get_evasion_boost(), this->dmgBonus, this->dmgReduction);
}

void EquipableItem::unequip_item(PlayerStats*& playerStats) {
    std::cout << "You have unequipped the " + get_name() + ".\n";
    playerStats->lose_stats_from_unequip(get_health_boost(), get_attack_boost(), get_strength_boost(),get_defense_boost(),
                                        get_luck_boost(), get_evasion_boost(), this->dmgBonus, this->dmgReduction);
}

int EquipableItem::get_dmg_bonus() {
    return this->dmgBonus;
}

int EquipableItem::get_dmg_reduction() {
    return this->dmgReduction;
}

int EquipableItem::get_equipment_type() {
    return this->equipmentType;
}

void EquipableItem::concat_stats(std::string& itemString) {
    if(this->dmgBonus != 0) {
        itemString += " dmg bonus: " + std::string(this->dmgBonus > 0 ? "+" : "-") + std::to_string(this->dmgBonus) + ",";
    }
    if(this->dmgReduction != 0) {
        itemString += " dmg reduction: " + std::string(this->dmgReduction > 0 ? "+" : "") + std::to_string(this->dmgReduction) + ",";
    }
    if(this->get_health_boost() != 0) {
        itemString += " hp: " + std::string(this->get_health_boost() > 0 ? "+" : "") + std::to_string(this->get_health_boost()) + ",";
    }
    if(this->get_attack_boost() != 0) {
        itemString += " atk: " + std::string(this->get_attack_boost() > 0 ? "+" : "") + std::to_string(this->get_attack_boost()) + ",";
    }
    if(this->get_strength_boost() != 0) {
        itemString += " str: " + std::string(this->get_strength_boost() > 0 ? "+" : "") + std::to_string(this->get_strength_boost()) + ",";
    }
    if(this->get_defense_boost() != 0) {
        itemString += " def: " + std::string(this->get_defense_boost() > 0 ? "+" : "") + std::to_string(this->get_defense_boost()) + ",";
    }
    if(this->get_luck_boost() != 0) {
        itemString += " luk: " + std::string(this->get_luck_boost() > 0 ? "+" : "") + std::to_string(this->get_luck_boost()) + ",";
    }
    if(this->get_evasion_boost() != 0) {
        itemString += " evs: " + std::string(this->get_evasion_boost() > 0 ? "+" : "") + std::to_string(this->get_evasion_boost()) + ",";
    }
    itemString += " weight: +" + std::to_string(this->get_weight()) + "\n";
}

EquipableItem::~EquipableItem() {}
