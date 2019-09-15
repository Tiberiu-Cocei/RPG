#ifndef RUNE_H
#define RUNE_H
#include "Ability.h"
#include <vector>


class Rune
{
    public:
        Rune(std::string, std::string, std::vector<Ability*>);
        ~Rune();
        Ability* get_ability_at(int);
        void get_overview();
        int get_number_of_abilities();

    private:
        std::string name;
        std::string description;
        std::vector<Ability*> abilities;
};

#endif
