#ifndef STATS_H
#define STATS_H


class Stats
{
    public:
        Stats(short int, short int, short int, short int, short int, short int);
        virtual ~Stats();
        virtual void get_stats() = 0;
        virtual bool take_damage(short int, short int, short int) = 0;
        virtual void gain_health(short int) = 0;

    protected:
        short int healthPoints; //determines how much damage you can take before dying
        short int currentHealthPoints; //current hp; 0 means death
        short int attack; //determines chance of hitting the target
        short int strength; //determines damage potential
        short int defense; //determines damage reduction
        short int luck; //determines the bonus to random rolls
        short int evasion; //determines the chance of evading an attack
};

#endif
