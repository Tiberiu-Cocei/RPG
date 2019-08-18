#ifndef ENEMYSTATS_H
#define ENEMYSTATS_H

#include <Stats.h>


class EnemyStats : public Stats
{
    public:
        EnemyStats(short int, short int, short int, short int, short int);
        ~EnemyStats();
        void get_stats();
        bool take_damage(short int, short int, short int, short int);
        void gain_health(short int);
};

#endif
