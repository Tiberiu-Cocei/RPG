#include "Stats.h"
#include <string.h>
#include <iostream>

Stats::Stats(short int healthPoints, short int attack, short int strength, short int defense, short int luck, short int evasion, short int speed)
{
    this->healthPoints = healthPoints;
    this->currentHealthPoints = healthPoints;
    this->attack = attack;
    this->strength = strength;
    this->defense = defense;
    this->luck = luck;
    this->evasion = evasion;
    this->speed = speed;
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

void Stats::set_speed(short int speed) {
    this->speed = speed;
}

short int Stats::get_speed() {
    return this->speed;
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

void Stats::get_own_stats() {
    std::string ownStats = "Your current stats are :\n";

    ownStats += std::to_string(currentHealthPoints) + " health points out of " + std::to_string(healthPoints) + ". ";
    if(currentHealthPoints <= 10) ownStats += "You're on death's door.\n";
    else if(currentHealthPoints <= 20) ownStats += "You've lost a lot of blood and feel weak.\n";
    else if(currentHealthPoints <= 30) ownStats += "You're wounded and in pain.\n";
    else if(currentHealthPoints <= 40) ownStats += "You've seen better days.\n";
    else if(currentHealthPoints <= 50) ownStats += "The pain is barely manageable.\n";
    else if(currentHealthPoints <= 60) ownStats += "You still feel alright.\n";
    else if(currentHealthPoints <= 70) ownStats += "You're injured and in pain.\n";
    else if(currentHealthPoints <= 90) ownStats += "A few cuts and bruises.\n";
    else if(currentHealthPoints <= 100) ownStats += "You feel fine.\n";
    else ownStats += "You feel better than ever.\n";

    ownStats += attack + " total attack. ";
    if(attack <= 10) ownStats += "You feel extremely disoriented.\n";
    else if(attack <= 20) ownStats += "You feel as if you're drunk.\n";
    else if(attack <= 30) ownStats += "You lack training.\n";
    else if(attack <= 40) ownStats += "You could probably hit a standing target.\n";
    else if(attack <= 60) ownStats += "Your accuracy is decent.\n";
    else if(attack <= 80) ownStats += "You feel like your accuracy training has been paying off.\n";
    else if(attack <= 100) ownStats += "You can anticipate your opponents movements and strike with ease.\n";
    else ownStats += "You have mastered the art of attacking a target.\n";
}

Stats::~Stats()
{
}
