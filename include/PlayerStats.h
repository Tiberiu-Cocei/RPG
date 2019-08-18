#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <Stats.h>


class PlayerStats : public Stats
{
    public:
        PlayerStats(short int, short int, short int, short int, short int, short int);
        ~PlayerStats();
        void get_stats();
        short int get_attack();
        short int get_strength();
        short int get_luck();
        short int get_dmgBonus();
        bool take_damage(short int, short int, short int);
        void gain_health(short int);
        void modify_temp_stats(short int, short int, short int, short int, short int, short int);
        void reset_temp_stats();
        void gain_stats_from_equip(short int, short int, short int, short int, short int, short int, short int, short int);
        void lose_stats_from_unequip(short int, short int, short int, short int, short int, short int, short int, short int);

    protected:
        short int tempHealthPoints;
        short int tempAttack;
        short int tempStrength;
        short int tempDefense;
        short int tempLuck;
        short int tempEvasion;
        short int dmgBonus;
        short int dmgReduction;
};

#endif
