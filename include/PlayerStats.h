#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <Stats.h>


class PlayerStats : public Stats
{
    public:
        PlayerStats(int, int, int, int, int, int);
        ~PlayerStats();
        void get_stats();
        int get_total_attack();
        int get_total_strength();
        int get_total_luck();
        int get_dmgBonus();
        bool take_damage(int, int, int, int);
        void gain_health(int);
        void modify_temp_stats(int, int, int, int, int, int);
        void reset_temp_stats();
        void gain_stats_from_equip(int, int, int, int, int, int, int, int);
        void lose_stats_from_unequip(int, int, int, int, int, int, int, int);

    private:
        int tempHealthPoints;
        int tempAttack;
        int tempStrength;
        int tempDefense;
        int tempLuck;
        int tempEvasion;
        int dmgBonus;
        int dmgReduction;
};

#endif
