#ifndef STATS_H
#define STATS_H


class Stats
{
    public:
        Stats(int, int, int, int, int, int);
        virtual ~Stats();
        virtual void get_stats() = 0;
        virtual bool take_damage(int, int, int, int) = 0;
        virtual void gain_health(int) = 0;

        void set_health_points(int);
        int get_health_points();
        void set_current_health_points(int);
        int get_current_health_points();
        void set_attack(int);
        int get_attack();
        void set_strength(int);
        int get_strength();
        void set_defense(int);
        int get_defense();
        void set_luck(int);
        int get_luck();
        void set_evasion(int);
        int get_evasion();

    private:
        int healthPoints; //determines how much damage you can take before dying
        int currentHealthPoints; //current hp; 0 means death
        int attack; //determines chance of hitting the target
        int strength; //determines damage potential
        int defense; //determines damage reduction
        int luck; //determines the bonus to random rolls
        int evasion; //determines the chance of evading an attack
};

#endif
