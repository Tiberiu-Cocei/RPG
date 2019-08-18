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

Item::~Item()
{
}
