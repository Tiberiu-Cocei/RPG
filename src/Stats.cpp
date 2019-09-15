#include "Stats.h"
#include <string.h>
#include <iostream>

Stats::Stats(int healthPoints, int attack, int strength, int defense, int luck, int evasion) {
    this->healthPoints = healthPoints;
    this->currentHealthPoints = healthPoints;
    this->attack = attack;
    this->strength = strength;
    this->defense = defense;
    this->luck = luck;
    this->evasion = evasion;
}

void Stats::set_health_points(int healthPoints) {
    this->healthPoints = healthPoints;
}

int Stats::get_health_points() {
    return this->healthPoints;
}

void Stats::set_current_health_points(int currentHealthPoints) {
    this->currentHealthPoints = currentHealthPoints;
}

int Stats::get_current_health_points() {
    return this->currentHealthPoints;
}

void Stats::set_attack(int attack) {
    this->attack = attack;
}

int Stats::get_attack() {
    return this->attack;
}

void Stats::set_strength(int strength) {
    this->strength = strength;
}

int Stats::get_strength() {
    return this->strength;
}

void Stats::set_defense(int defense) {
    this->defense = defense;
}

int Stats::get_defense() {
    return this->defense;
}

void Stats::set_luck(int luck) {
    this->luck = luck;
}

int Stats::get_luck() {
    return this->luck;
}

void Stats::set_evasion(int evasion) {
    this->evasion = evasion;
}

int Stats::get_evasion() {
    return this->evasion;
}

Stats::~Stats() {}
