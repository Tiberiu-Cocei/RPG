#ifndef RUNELIST_H
#define RUNELIST_H
#include "AbilityList.h"
#include "Rune.h"


class RuneList
{
    public:
        RuneList();
        ~RuneList();
        Rune* get_rune(int);

    private:
        AbilityList abilityList;
};

#endif
