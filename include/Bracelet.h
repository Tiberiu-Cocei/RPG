#ifndef BRACELET_H
#define BRACELET_H
#include "Rune.h"
#include <vector>
#include "PlayerStats.h"
#include "Enemy.h"


class Bracelet
{
    public:
        Bracelet();
        ~Bracelet();
        void add_rune(Rune*);
        void equip_rune(int);
        bool use_ability(int, PlayerStats*&, Enemy*&);
        void get_overview();

    private:
        std::vector<Rune*> runes;
        Rune* runeWielded;
};

#endif
