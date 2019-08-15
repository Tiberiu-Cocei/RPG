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

void Stats::set_health_points(short int healthPoints) {
    this->healthPoints = healthPoints;
}

short int Stats::get_health_points() {
    return this->healthPoints;
}

void Stats::set_attack(short int attack) {
    this->attack = attack;
}

short int Stats::get_attack() {
    return this->attack;
}

void Stats::set_strength(short int strength) {
    this->strength = strength;
}

short int Stats::get_strength() {
    return this->strength;
}

void Stats::set_defense(short int defense) {
    this->defense = defense;
}

short int Stats::get_defense() {
    return this->defense;
}

void Stats::set_luck(short int luck) {
    this->luck = luck;
}

short int Stats::get_luck() {
    return this->luck;
}

void Stats::set_evasion(short int evasion) {
    this->evasion = evasion;
}

short int Stats::get_evasion() {
    return this->evasion;
}

bool Stats::take_damage(short int damage) {
    this->currentHealthPoints -= damage;
    if(this->currentHealthPoints <= 0) {
        return true;
    }
    return false;
}

void Stats::gain_health(short int healing) {
    if(this->currentHealthPoints + healing >= this->healthPoints) {
        this->currentHealthPoints = this->healthPoints;
    }
    else {
        this->currentHealthPoints += healing;
    }
}

Stats::~Stats()
{
}
