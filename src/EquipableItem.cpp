#include "EquipableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

EquipableItem::EquipableItem(short int dmgBonus, short int dmgReduction, short int healthBoost, short int attackBoost, short int strengthBoost,
                               short int defenseBoost, short int luckBoost, short int evasionBoost, short int weight,
                               std::string name, std::string findDescription, std::string useDescription)
: Item(healthBoost, attackBoost, strengthBoost, defenseBoost, luckBoost, evasionBoost, weight, name, findDescription, useDescription)
{
    this->dmgBonus = dmgBonus;
    this->dmgReduction = dmgReduction;
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

EquipableItem::~EquipableItem()
{
}
