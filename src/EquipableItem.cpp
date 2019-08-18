#include "EquipableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

EquipableItem::EquipableItem(short int dmgBonus, short int dmgReduction, short int healthBoost, short int attackBoost, short int strengthBoost,
                               short int defenseBoost, short int luckBoost, short int evasionBoost,
                               std::string name, std::string findDescription, std::string useDescription)
: Item(healthBoost, attackBoost, strengthBoost, defenseBoost, luckBoost, evasionBoost, name, findDescription, useDescription, 1)
{
    this->dmgBonus = dmgBonus;
    this->dmgReduction = dmgReduction;
}

void EquipableItem::find_item() {
    std::cout << this->findDescription << std::endl;
}

void EquipableItem::use_item(PlayerStats& playerStats) {
    std::cout << this->useDescription << std::endl;
    playerStats.gain_stats_from_equip(this->healthBoost, this->attackBoost, this->strengthBoost, this->defenseBoost,
                                      this->luckBoost, this->evasionBoost, this->dmgBonus, this->dmgReduction);
}

void EquipableItem::unequip_item(PlayerStats& playerStats) {
    std::cout << "You have unequipped the " + this->name + ".\n";
    playerStats.lose_stats_from_unequip(this->healthBoost, this->attackBoost, this->strengthBoost, this->defenseBoost,
                                        this->luckBoost, this->evasionBoost, this->dmgBonus, this->dmgReduction);
}

EquipableItem::~EquipableItem()
{
}
