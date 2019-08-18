#include "ConsumableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

ConsumableItem::ConsumableItem(short int healing, short int healthBoost, short int attackBoost, short int strengthBoost,
                               short int defenseBoost, short int luckBoost, short int evasionBoost, short int maxStack,
                               std::string name, std::string findDescription, std::string useDescription)
: Item(healthBoost, attackBoost, strengthBoost, defenseBoost, luckBoost, evasionBoost, name, findDescription, useDescription, maxStack)
{
    this->healing = healing;
}

void ConsumableItem::find_item() {
    std::cout << this->findDescription << std::endl;
}

void ConsumableItem::use_item(PlayerStats& playerStats) {
    std::cout << this->useDescription << std::endl;
    if(this->healing != 0) {
        playerStats.gain_health(this->healing);
    }
    playerStats.modify_temp_stats(this->healthBoost, this->attackBoost, this->strengthBoost, this->defenseBoost, this->luckBoost, this->evasionBoost);
}

ConsumableItem::~ConsumableItem()
{
}
