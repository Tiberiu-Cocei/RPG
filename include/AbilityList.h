#ifndef ABILITYLIST_H
#define ABILITYLIST_H
#include "Ability.h"
#include <iostream>
#include <string.h>


class AbilityList
{
    public:
        AbilityList();
        ~AbilityList();
        Ability* get_ability(int);
};

#endif
