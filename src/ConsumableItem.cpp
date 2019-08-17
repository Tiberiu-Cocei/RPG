#include "ConsumableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

ConsumableItem::ConsumableItem(short int healing, short int healthBoost, short int attackBoost, short int strengthBoost,
                               short int defenseBoost, short int luckBoost, short int evasionBoost, short int maxStack,
                               std::string name, std::string findDescription, std::string useDescription)
: Item(name, findDescription, useDescription, maxStack)
{
    this->healing = healing;
    this->healthBoost = healthBoost;
    this->attackBoost = attackBoost;
    this->strengthBoost = strengthBoost;
    this->defenseBoost = defenseBoost;
    this->luckBoost = luckBoost;
    this->evasionBoost = evasionBoost;
}

void ConsumableItem::use_item(PlayerStats playerStats) {

}

ConsumableItem::~ConsumableItem()
{
}
