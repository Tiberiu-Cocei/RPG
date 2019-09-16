#ifndef ENEMYSTATS_H
#define ENEMYSTATS_H

#include <Stats.h>


class EnemyStats : public Stats
{
    public:
        EnemyStats(int, int, int, int, int);
        ~EnemyStats();
        void get_stats();
        bool take_damage(int, int, int, int, bool = true);
        void gain_health(int);
        void reset_stats();
};

#endif
