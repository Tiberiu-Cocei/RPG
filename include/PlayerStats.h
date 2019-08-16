#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <Stats.h>


class PlayerStats : public Stats
{
    public:
        PlayerStats(short int, short int, short int, short int, short int, short int);
        ~PlayerStats();
        void get_stats();
        bool take_damage(short int, short int, short int);
        void gain_health(short int);
};

#endif
