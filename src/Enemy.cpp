#include "Enemy.h"

Enemy::Enemy(EnemyStats* enemyStats, std::string name, std::string encounterDescrption, std::string deathDescription,
             std::vector<ConsumableItem*> consumableDrops, std::vector<EquipableItem*> equipableDrops, int combatLevel, int xp)
{
    this->enemyStats = enemyStats;
    this->name += name;
    this->encounterDescrption += encounterDescrption;
    this->deathDescription += deathDescription;
    this->consumableDrops = consumableDrops;
    this->equipableDrops = equipableDrops;
    this->combatLevel = combatLevel;
    this->xp = xp;
}

EnemyStats*& Enemy::get_enemy_stats() {
    return this->enemyStats;
}

std::string Enemy::get_name() {
    return this->name;
}

std::string Enemy::get_encounter_description() {
    return this->encounterDescrption;
}

std::string Enemy::get_death_description() {
    return this->deathDescription;
}

std::vector<ConsumableItem*> Enemy::get_consumable_drops() {
    return this->consumableDrops;
}

std::vector<EquipableItem*> Enemy::get_equipable_drops() {
    return this->equipableDrops;
}

int Enemy::get_combat_level() {
    return this->combatLevel;
}

int Enemy::get_xp() {
    return this->xp;
}

void Enemy::enemy_attack(PlayerStats*& playerStats) {
    playerStats->take_damage(enemyStats->get_attack(), enemyStats->get_strength(), enemyStats->get_luck(), 0);
}

void Enemy::enemy_defend(PlayerStats*& playerStats) {
    this->enemyStats->take_damage(playerStats->get_attack(), playerStats->get_strength(), playerStats->get_luck(), playerStats->get_dmgBonus());
}

void Enemy::enemy_encounter() {
    std::cout<<this->encounterDescrption<<"\n";
    std::cout<<"You are fighting a level " + std::to_string(combatLevel) + " " + name + "!\n";
}

void Enemy::normal_death(int randomRoll, Inventory*& inventory) {
    std::cout<<"\n"<<this->deathDescription<<"\n";
    ConsumableItem* itemDrop;
    if(randomRoll > 1 && randomRoll <= 25) {
        itemDrop = consumableDrops.at(0);
    }
    else if(randomRoll > 25 && randomRoll <= 50) {
        itemDrop = consumableDrops.at(1);
    }
    else if(randomRoll > 50 && randomRoll <= 75) {
        itemDrop = consumableDrops.at(2);
    }
    else if(randomRoll > 75 && randomRoll <= 85) {
        itemDrop = consumableDrops.at(3);
    }
    else {
        itemDrop = new ConsumableItem(0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
    std::cout<<"You have found a " + itemDrop->get_name() + ". Do you wish to pick it up? (Yes/no) ";
    std::string command;
    getline(std::cin,command);
    if(command.compare("Yes") == 0 || command.compare("yes") == 0) {
        inventory->pickup_item(itemDrop);
    }
    else{
        std::cout<<"You drop the item to the ground and move on.\n";
    }
}

void Enemy::rare_death(int randomRoll, Inventory*& inventory) {
    std::cout<<"\n"<<this->deathDescription<<"\n";
    EquipableItem* itemDrop;
    if(randomRoll > 85 && randomRoll <= 95) {
        itemDrop = equipableDrops.at(0);
    }
    else if(randomRoll > 95 && randomRoll <= 100) {
        itemDrop = equipableDrops.at(1);
    }
    else {
        itemDrop = new EquipableItem(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "ERROR_ITEM", "ERROR_ITEM", "ERROR_ITEM");
    }
    std::cout<<"You have found a " + itemDrop->get_name() + ". Do you wish to pick it up? (Yes/no) ";
    std::string command;
    getline(std::cin,command);
    if(command.compare("Yes") == 0 || command.compare("yes") == 0) {
        inventory->pickup_item(itemDrop);
    }
    else{
        std::cout<<"You drop the item to the ground and move on.\n";
    }
}

Enemy::~Enemy()
{
}
