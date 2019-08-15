#ifndef STATS_H
#define STATS_H


class Stats
{
    public:
        Stats(short int, short int, short int, short int, short int, short int);
        virtual ~Stats();
        void set_health_points(short int);
        short int get_health_points();
        void set_attack(short int);
        short int get_attack();
        void set_strength(short int);
        short int get_strength();
        void set_defense(short int);
        short int get_defense();
        void set_luck(short int);
        short int get_luck();
        void set_evasion(short int);
        short int get_evasion();

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
