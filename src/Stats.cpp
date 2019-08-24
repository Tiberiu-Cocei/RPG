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

void Stats::set_current_health_points(short int currentHealthPoints) {
    this->currentHealthPoints = currentHealthPoints;
}

short int Stats::get_current_health_points() {
    return this->currentHealthPoints;
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

Stats::~Stats()
{
}
