#include "ConsumableItem.h"
#include <string.h>
#include <iostream>
#include "PlayerStats.h"

ConsumableItem::ConsumableItem(int healing, int healthBoost, int attackBoost, int strengthBoost,
                               int defenseBoost, int luckBoost, int evasionBoost, int weight,
                               std::string name, std::string findDescription, std::string useDescription)
: Item(healthBoost, attackBoost, strengthBoost, defenseBoost, luckBoost, evasionBoost, weight, name, findDescription, useDescription)
{
    this->healing = healing;
}

void ConsumableItem::find_item() {
    std::cout << get_find_description() << std::endl;
}

void ConsumableItem::use_item(PlayerStats*& playerStats) {
    std::cout << get_use_description() << std::endl;
    if(this->healing != 0) {
        playerStats->gain_health(this->healing + playerStats->get_bonus_healing());
    }
    playerStats->modify_temp_stats(get_health_boost(), get_attack_boost(), get_strength_boost(),
                                  get_defense_boost(), get_luck_boost(), get_evasion_boost());
}

int ConsumableItem::get_healing() {
    return this->healing;
}

ConsumableItem::~ConsumableItem()
{
}
