#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <Stats.h>


class PlayerStats : public Stats
{
    public:
        PlayerStats(short int, short int, short int, short int, short int, short int);
        virtual ~PlayerStats();
        void get_own_stats();
};

#endif
