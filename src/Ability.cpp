#include "Ability.h"

Ability::Ability(std::string name, std::string description, std::string useDescription, bool affectsPlayer, bool stuns,
                 int cost, int element, float multiplier, int attack, int strength, int defense, int luck, int evasion)
                 : name(name), description(description), useDescription(useDescription) {
    this->affectsPlayer = affectsPlayer;
    this->stuns = stuns;
    this->cost = cost;
    this->element = element;
    this->multiplier = multiplier;
    this->attack = attack;
    this->strength = strength;
    this->defense = defense;
    this->luck = luck;
    this->evasion = evasion;
}

bool Ability::use_ability(PlayerStats*& playerStats, Enemy*& enemy) {
    if(playerStats->get_current_charges() < this->cost) {
        std::cout<<"You fail to use the spell as you do not have enough charges!\n";
        return false;
    }
    else {
        std::cout<<this->useDescription<<"\n";
        playerStats->change_current_charges(-this->cost);
        if(affectsPlayer == true) {
            if(this->element == 0 && this->multiplier != 0.0f) {
                return playerStats->take_damage(enemy->get_enemy_stats()->get_attack(), enemy->get_enemy_stats()->get_strength() * this->multiplier, 0, 0);
            }
            else if(this->element == 2 && this->multiplier != 0.0f) {
                playerStats->gain_health(playerStats->get_attack() * this->multiplier);
                return false;
            }
            playerStats->gain_stats_from_ability(this->attack, this->strength, this->defense, this->luck, this->evasion);
            return false;
        }
        else {
            if(this->stuns == true) {
                enemy->stun_enemy();
            }
            if(this->element == 1) {
                return enemy->get_enemy_stats()->take_damage(playerStats->get_attack() * 2, playerStats->get_defense() * this->multiplier, playerStats->get_luck(), 0);
            }
            else if(this->element == 2) {
                return enemy->get_enemy_stats()->take_damage(playerStats->get_attack() * 2, playerStats->get_attack() * this->multiplier, playerStats->get_luck(), 0);
            }
            else if(this->element == 3) {
                return enemy->get_enemy_stats()->take_damage(playerStats->get_attack() * 2, playerStats->get_evasion() * this->multiplier, playerStats->get_luck(), 0);
            }
            else {
                return enemy->get_enemy_stats()->take_damage(playerStats->get_attack() * 2, playerStats->get_strength() * this->multiplier, playerStats->get_luck(), 0);
            }
        }
    }
}

int Ability::get_cost() {
    return this->cost;
}

std::string Ability::get_name() {
    return this->name;
}

std::string Ability::get_description() {
    return this->description;
}

Ability::~Ability() {}
