#include "Item.h"
#include <string.h>
#include <iostream>

Item::Item(int healthBoost, int attackBoost, int strengthBoost, int defenseBoost, int luckBoost,
           int evasionBoost, int weight, std::string name, std::string findDescription, std::string useDescription)
           : name(name), findDescription(findDescription), useDescription(useDescription)
{
    this->healthBoost = healthBoost;
    this->attackBoost = attackBoost;
    this->strengthBoost = strengthBoost;
    this->defenseBoost = defenseBoost;
    this->luckBoost = luckBoost;
    this->evasionBoost = evasionBoost;
    this->weight = weight;
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

int Item::get_health_boost() {
    return this->healthBoost;
}

int Item::get_attack_boost() {
    return this->attackBoost;
}

int Item::get_strength_boost() {
    return this->strengthBoost;
}

int Item::get_defense_boost() {
    return this->defenseBoost;
}

int Item::get_luck_boost() {
    return this->luckBoost;
}

int Item::get_evasion_boost() {
    return this->evasionBoost;
}

int Item::get_weight() {
    return this->weight;
}

Item::~Item()
{
}
