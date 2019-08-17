#include "PlayerStats.h"
#include <string.h>
#include <iostream>

PlayerStats::PlayerStats(short int healthPoints, short int attack, short int strength, short int defense, short int luck, short int evasion)
: Stats(healthPoints, attack, strength, defense, luck, evasion)
{
}

bool PlayerStats::take_damage(short int attack, short int strength, short int luck) {
    short int evade = rand() % 50 + 1 + this->luck/10 + this->evasion/5  - attack/10 + this->tempLuck/10 + this->tempEvasion/5;
    if(evade > 42) {
        std::cout<<"You have avoided the attack.\n";
        return false;
    }
    else {
        short int damage = strength/2.3f - this->defense/3.2f - this->tempDefense/3.2f;
        if(damage < 0) {
            damage = 0;
        }
        this->currentHealthPoints -= damage;
        std::cout<<"You have suffered " + std::to_string(damage);
        if(this->currentHealthPoints <= 0) {
            std::cout<<" damage and have died.\n";
            this->currentHealthPoints = 0;
            return true;
        }
        std::cout<<" damage and have " + std::to_string(currentHealthPoints) + " health points left.\n";
        return false;
    }
}

void PlayerStats::gain_health(short int healing) {
    if(this->currentHealthPoints + healing > this->healthPoints + this->tempHealthPoints) {
        this->currentHealthPoints = this->healthPoints + this->tempHealthPoints;
    }
    else {
        this->currentHealthPoints += healing;
    }
    std::cout<<"You have gained " + std::to_string(healing) + " health for a total of " + std::to_string(currentHealthPoints) + ".\n";
}

void PlayerStats::modifyTempStats(short int tempHealthPoints, short int tempAttack, short int tempStrength, short int tempDefense, short int tempLuck, short int tempEvasion) {
    this->tempHealthPoints += tempHealthPoints;
    this->currentHealthPoints += tempHealthPoints;
    this->tempAttack += tempAttack;
    this->tempStrength += tempStrength;
    this->tempDefense += tempDefense;
    this->tempLuck += tempLuck;
    this->tempEvasion += tempEvasion;
}

void PlayerStats::resetTempStats() {
    if(this->currentHealthPoints > this->healthPoints) {
        this->currentHealthPoints = this->healthPoints;
    }
    this->tempHealthPoints = 0;
    this->tempAttack = 0;
    this->tempStrength = 0;
    this->tempDefense = 0;
    this->tempLuck = 0;
    this->tempEvasion = 0;
}

short int PlayerStats::get_tempAttack() {
    return this->tempAttack;
}

short int PlayerStats::get_tempStrength() {
    return this->tempStrength;
}

short int PlayerStats::get_tempLuck() {
    return this->tempLuck;
}

void PlayerStats::get_stats() {
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

    ownStats += std::to_string(attack) + " total attack. ";
    if(attack <= 10) ownStats += "You feel extremely disoriented.\n";
    else if(attack <= 20) ownStats += "You feel as if you're drunk.\n";
    else if(attack <= 30) ownStats += "You lack combat training.\n";
    else if(attack <= 40) ownStats += "You're getting better at hitting your opponents.\n";
    else if(attack <= 60) ownStats += "Your accuracy is decent.\n";
    else if(attack <= 80) ownStats += "You feel like your accuracy training has been paying off.\n";
    else if(attack <= 100) ownStats += "You can anticipate your opponents movements and strike with ease.\n";
    else ownStats += "You have mastered the art of attacking a target.\n";

    ownStats += std::to_string(strength) + " total strength. ";
    if(strength <= 10) ownStats += "You feel extremely weak.\n";
    else if(strength <= 20) ownStats += "Your muscle aren't at all that developed.\n";
    else if(strength <= 30) ownStats += "You regret not training your muscles.\n";
    else if(strength <= 40) ownStats += "You can probably lift a boulder.\n";
    else if(strength <= 60) ownStats += "You're strong enough not to worry about getting pinned down by an enemy.\n";
    else if(strength <= 80) ownStats += "Your muscles are pronounced and developed.\n";
    else if(strength <= 100) ownStats += "You feel very strong and your muscles look sculpted.\n";
    else ownStats += "You could be confused with a pillar man.\n";

    ownStats += std::to_string(defense) + " total defense. ";
    if(defense <= 10) ownStats += "Your reflexes are very slow.\n";
    else if(defense <= 20) ownStats += "You lack eye-hand coordination.\n";
    else if(defense <= 30) ownStats += "You can block an attack with a shield but not much more.\n";
    else if(defense <= 40) ownStats += "You're starting to learn how to defend yourself.\n";
    else if(defense <= 60) ownStats += "You can reliably use your equipment to protect yourself.\n";
    else if(defense <= 80) ownStats += "You're starting to learn how to parry attacks.\n";
    else if(defense <= 100) ownStats += "Your defenses make you very hard to be killed.\n";
    else ownStats += "You're a walking fortress that can take head-on any foe.\n";

    ownStats += std::to_string(luck) + " total luck. ";
    if(luck <= 10) ownStats += "You're afraid the ceiling will give in and kill you.\n";
    else if(luck <= 20) ownStats += "You feel cursed.\n";
    else if(luck <= 30) ownStats += "You're quite unlucky.\n";
    else if(luck <= 40) ownStats += "You don't feel like you're particularly lucky.\n";
    else if(luck <= 60) ownStats += "Lucky things sometimes happen to you.\n";
    else if(luck <= 80) ownStats += "Luck seems to be on your side.\n";
    else if(luck <= 100) ownStats += "Through pure luck you manage to often strike vital points.\n";
    else ownStats += "You feel as if there's a divine intervention every time you fight.\n";

    ownStats += std::to_string(evasion) + " total evasion. ";
    if(evasion <= 10) ownStats += "You're barely able to dodge a slow falling tree.\n";
    else if(evasion <= 20) ownStats += "You aren't agile at all.\n";
    else if(evasion <= 30) ownStats += "You're agile enough to sometimes avoid a slow attack.\n";
    else if(evasion <= 40) ownStats += "You're starting to feel more agile.\n";
    else if(evasion <= 60) ownStats += "You're agile enough to rarely avoid attacks.\n";
    else if(evasion <= 80) ownStats += "You're agile enough to often avoid attacks.\n";
    else if(evasion <= 100) ownStats += "You feel very agile, being able to evade even the fastest attacks.\n";
    else ownStats += "Even the most trained and accurate enemies have a hard time hitting you.\n";

    std::cout<<ownStats;
}

PlayerStats::~PlayerStats()
{
}
