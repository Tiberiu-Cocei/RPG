#include "Stats.h"
#include <string.h>
#include <iostream>

Stats::Stats(short int healthPoints, short int attack, short int strength, short int defense, short int luck, short int evasion)
{
    this->healthPoints = healthPoints;
    this->currentHealthPoints = healthPoints;
    this->attack = attack;
    this->strength = strength;
    this->defense = defense;
    this->luck = luck;
    this->evasion = evasion;
}

Stats::~Stats()
{
}
