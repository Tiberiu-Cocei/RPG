#include "Perk.h"

Perk::Perk(std::string name, std::string description, int xpCost, int dmgBonus, int dmgReduction, int healthPoints, int attack, int strength,
           int defense, int luck, int evasion, int weightBonus, int hpRegen, int bonusHealing, int escapeBonus, int uniquePerkId, int id)
           : name(name), description(description) {
    this->state = false;
    this->xpCost = xpCost;
    this->dmgBonus = dmgBonus;
    this->dmgReduction = dmgReduction;
    this->healthPoints = healthPoints;
    this->attack = attack;
    this->strength = strength;
    this->defense = defense;
    this->luck = luck;
    this->evasion = evasion;
    this->weightBonus = weightBonus;
    this->hpRegen = hpRegen;
    this->bonusHealing = bonusHealing;
    this->escapeBonus = escapeBonus;
    this->uniquePerkId = uniquePerkId;
    this->id = id;
}

void Perk::attune_perk(PlayerStats*& playerStats, Inventory*& inventory) {
    if(playerStats->get_experience() >= this->xpCost && this->state == false) {
        this->state = true;
        if(this->uniquePerkId >= 0) {
            playerStats->set_perk_state(uniquePerkId);
        }
        playerStats->gain_stats_from_perk(this->xpCost, this->dmgBonus, this->dmgReduction, this->healthPoints, this->attack, this->strength,
                                          this->defense, this->luck, this->evasion, this->hpRegen, this->bonusHealing, this->escapeBonus);
        inventory->gain_max_weight(this->weightBonus);
        std::cout<<"You have successfully attuned the perk " + name + "!\n";
    }
    else {
        std::cout<<"You do not have enough experience to attune this perk or have already attuned it.\n";
    }
}

void Perk::display_perk(int textColorNr) {
    if(this->state == false) {
        SetConsoleTextAttribute(hConsole, 12);
        std::cout<< this->name << " - " << this->description << "\n";
    }
    else {
        SetConsoleTextAttribute(hConsole, 10);
        std::cout<< this->name << " - " << this->description << "\n";
    }
    SetConsoleTextAttribute(hConsole, textColorNr);
}

bool Perk::get_state() {
    return this->state;
}

std::string Perk::get_name() {
    return this->name;
}

std::string Perk::get_description() {
    return this->description;
}

int Perk::get_id() {
    return this->id;
}

void Perk::get_save_data(std::string& saveData) {
    saveData += std::to_string(id) + " " + std::to_string(state) + " ";
}

Perk::~Perk() {}
