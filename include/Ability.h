#ifndef ABILITY_H
#define ABILITY_H
#include <iostream>
#include <string.h>
#include "PlayerStats.h"
#include "Enemy.h"


class Ability
{
    public:
        Ability(std::string, std::string, std::string, bool, bool, int, int, float, int, int, int, int, int);
        ~Ability();
        bool use_ability(PlayerStats*&, Enemy*&);
        int get_cost();
        std::string get_name();
        std::string get_description();

    private:
        std::string name;
        std::string description;
        std::string useDescription;
        bool affectsPlayer;
        bool stuns;
        int cost;
        int element;
        float multiplier;
        int attack;
        int defense;
        int strength;
        int evasion;
        int luck;
};

#endif
