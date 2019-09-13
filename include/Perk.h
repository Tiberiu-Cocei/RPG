#ifndef PERK_H
#define PERK_H
#include <iostream>
#include <string.h>
#include "PlayerStats.h"
#include "Inventory.h"
#include <windows.h>


class Perk
{
    public:
        Perk(std::string, std::string, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
        ~Perk();
        void attune_perk(PlayerStats*&, Inventory*&);
        void display_perk(int);
        bool get_state();
        std::string get_name();
        std::string get_description();

    private:
        const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        std::string name;
        std::string description;
        bool state;
        int xpCost;
        int dmgBonus;
        int dmgReduction;
        int healthPoints;
        int attack;
        int strength;
        int defense;
        int luck;
        int evasion;
        int weightBonus;
        int hpRegen;
        int bonusHealing;
        int escapeBonus;
        int uniquePerkId;
};

#endif
