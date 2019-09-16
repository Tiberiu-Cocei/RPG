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
        bool take_damage(int, int, int, int, bool = true);
        void gain_health(int);
        void modify_temp_stats(int, int, int, int, int, int);
        void reset_temp_stats();
        void gain_stats_from_equip(int, int, int, int, int, int, int, int);
        void lose_stats_from_unequip(int, int, int, int, int, int, int, int);
        void gain_experience(int);
        int get_experience();
        void gain_stats_from_perk(int, int, int, int, int, int, int, int, int, int, int, int);
        void regen_health();
        int get_bonus_healing();
        int get_escape_bonus();
        int get_temp_attack();
        int get_temp_strength();
        int get_temp_luck();
        int get_hp_regen();
        void set_perk_state(int);
        bool get_perk_state(int);
        void change_current_charges(int);
        int get_current_charges();
        void increase_max_charges(int);
        void gain_stats_from_ability(int, int, int, int, int);

    private:
        int tempHealthPoints;
        int tempAttack;
        int tempStrength;
        int tempDefense;
        int tempLuck;
        int tempEvasion;
        int dmgBonus;
        int dmgReduction;
        int experience;
        int hpRegen;
        int bonusHealing;
        int escapeBonus;
        int currentCharges;
        int maxCharges;
        bool attunedPerks[10]; //0 - Executioner
};

#endif
