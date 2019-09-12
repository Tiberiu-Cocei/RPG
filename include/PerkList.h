#ifndef PERKLIST_H
#define PERKLIST_H
#include "Perk.h"

class PerkList
{
    public:
        PerkList();
        ~PerkList();
        Perk* get_perk(int);
};

#endif
