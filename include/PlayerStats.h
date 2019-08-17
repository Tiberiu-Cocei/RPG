#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <Stats.h>


class PlayerStats : public Stats
{
    public:
        PlayerStats(short int, short int, short int, short int, short int, short int);
        ~PlayerStats();
        void get_stats();
        short int get_tempAttack();
        short int get_tempStrength();
        short int get_tempLuck();
        bool take_damage(short int, short int, short int);
        void gain_health(short int);
        void modifyTempStats(short int, short int, short int, short int, short int, short int);
        void resetTempStats();

    protected:
        short int tempHealthPoints;
        short int tempAttack;
        short int tempStrength;
        short int tempDefense;
        short int tempLuck;
        short int tempEvasion;
};

#endif
