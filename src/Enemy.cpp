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

bool Enemy::enemy_attack(PlayerStats*& playerStats) {
    return playerStats->take_damage(enemyStats->get_attack(), enemyStats->get_strength(), enemyStats->get_luck(), 0);
}

bool Enemy::enemy_defend(PlayerStats*& playerStats) {
    return this->enemyStats->take_damage(playerStats->get_attack(), playerStats->get_strength(), playerStats->get_luck(), playerStats->get_dmgBonus());
}

void Enemy::enemy_encounter() {
    std::cout<<this->encounterDescrption<<"\n";
    std::cout<<"You are fighting a level " + std::to_string(combatLevel) + " " + name + "!\n";
}

void Enemy::enemy_death(Inventory*& inventory) {
    std::cout<<"\n"<<this->deathDescription<<"\n";
    int randomRoll = rand() % 100 + 1;
    ConsumableItem* consumableItemDrop = NULL;
    EquipableItem* equipableItemDrop = NULL;
    if(randomRoll > 1 && randomRoll <= 15) {
        consumableItemDrop = consumableDrops.at(0);
    }
    else if(randomRoll > 15 && randomRoll <= 35) {
        consumableItemDrop = consumableDrops.at(1);
    }
    else if(randomRoll > 35 && randomRoll <= 60) {
        consumableItemDrop = consumableDrops.at(2);
    }
    else if(randomRoll > 60 && randomRoll <= 70) {
        consumableItemDrop = consumableDrops.at(3);
    }
    else if(randomRoll > 70 && randomRoll <= 85) {

        equipableItemDrop = equipableDrops.at(0);
    }
    else if(randomRoll > 85 && randomRoll <= 100) {
        equipableItemDrop = equipableDrops.at(1);
    }
    if(consumableItemDrop != NULL) {
        std::cout<<"You have found a " + consumableItemDrop->get_name() + ". Do you wish to pick it up? (Yes/no) ";
        std::string command;
        getline(std::cin,command);
        if(command.compare("Yes") == 0 || command.compare("yes") == 0) {
            inventory->pickup_item(consumableItemDrop);
        }
        else {
            std::cout<<"You drop the item to the ground and move on.\n";
        }
    }
    else if(equipableItemDrop != NULL) {
        std::cout<<"You have found a " + equipableItemDrop->get_name() + ". Do you wish to pick it up? (Yes/no) ";
        std::string command;
        getline(std::cin,command);
        if(command.compare("Yes") == 0 || command.compare("yes") == 0) {
            inventory->pickup_item(equipableItemDrop);
        }
        else {
            std::cout<<"You drop the item to the ground and move on.\n";
        }
    }
}

Enemy::~Enemy()
{
    delete this->enemyStats;
}
