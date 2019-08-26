#ifndef ENEMY_H
#define ENEMY_H
#include "EnemyStats.h"
#include "ConsumableItem.h"
#include "EquipableItem.h"
#include <iostream>
#include <string.h>
#include <vector>
#include "Inventory.h"


class Enemy
{
    public:
        Enemy(EnemyStats*, std::string, std::string, std::string, std::vector<ConsumableItem*>, std::vector<EquipableItem*>, int, int);
        ~Enemy();

        EnemyStats*& get_enemy_stats();
        std::string get_name();
        std::string get_encounter_description();
        std::string get_death_description();
        std::vector<ConsumableItem*> get_consumable_drops();
        std::vector<EquipableItem*> get_equipable_drops();
        int get_combat_level();
        int get_xp();

        void enemy_attack(PlayerStats*&);
        void enemy_defend(PlayerStats*&);
        void enemy_encounter();
        void normal_death(int, Inventory*&); //if random value is between 1 and 85
        void rare_death(int, Inventory*&); //if random value is between 86 and 100

    private:
        EnemyStats* enemyStats;
        std::string name;
        std::string encounterDescrption;
        std::string deathDescription;
        std::vector<ConsumableItem*> consumableDrops;
        std::vector<EquipableItem*> equipableDrops;
        int combatLevel;
        int xp;
};

#endif
