#include "Item.h"
#include <string.h>
#include <iostream>

Item::Item(short int healthBoost, short int attackBoost, short int strengthBoost, short int defenseBoost, short int luckBoost,
           short int evasionBoost,std::string name, std::string findDescription, std::string useDescription, short int maxStack)
{
    this->healthBoost = healthBoost;
    this->attackBoost = attackBoost;
    this->strengthBoost = strengthBoost;
    this->defenseBoost = defenseBoost;
    this->luckBoost = luckBoost;
    this->evasionBoost = evasionBoost;
    this->name += name;
    this->findDescription += findDescription;
    this->useDescription += useDescription;
    this->maxStack = maxStack;
}

std::string Item::get_name() {
    return this->name;
}

std::string Item::get_find_description() {
    return this->findDescription;
}

std::string Item::get_use_description() {
    return this->useDescription;
}

short int Item::get_health_boost() {
    return this->healthBoost;
}

short int Item::get_attack_boost() {
    return this->attackBoost;
}

short int Item::get_strength_boost() {
    return this->strengthBoost;
}

short int Item::get_defense_boost() {
    return this->defenseBoost;
}

short int Item::get_luck_boost() {
    return this->luckBoost;
}

short int Item::get_evasion_boost() {
    return this->evasionBoost;
}

Item::~Item()
{
}
