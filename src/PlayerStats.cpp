#include "PlayerStats.h"
#include <string.h>
#include <iostream>

PlayerStats::PlayerStats(int healthPoints, int attack, int strength, int defense, int luck, int evasion)
: Stats(healthPoints, attack, strength, defense, luck, evasion)
{
    tempHealthPoints = 0;
    tempAttack = 0;
    tempStrength = 0;
    tempDefense = 0;
    tempLuck = 0;
    tempEvasion = 0;
    dmgBonus = 0;
    dmgReduction = 0;
    experience = 0;
    hpRegen = 0;
    bonusHealing = 0;
    escapeBonus = 0;
}

void PlayerStats::gain_experience(int experience) {
    std::cout<<"You have gained " + std::to_string(experience) + " experience from the encounter!\n";
    this->experience += experience;
}

bool PlayerStats::take_damage(int attack, int strength, int luck, int dmgBonus) {
    int evade = rand() % 50 + 1 + get_luck()/10 + get_evasion()/3.5  - attack/10 + this->tempLuck/10 + this->tempEvasion/3.5;
    if(evade > 42) {
        std::cout<<"You have avoided the attack.\n";
        return false;
    }
    else {
        int damage = dmgBonus + strength/1.4f - get_defense()/2.9f - this->tempDefense/2.9f - this->dmgReduction;
        if(damage < 0) {
            damage = 0;
        }
        set_current_health_points(get_current_health_points() - damage);
        std::cout<<"You have suffered " + std::to_string(damage);
        if(get_current_health_points() <= 0) {
            std::cout<<" damage and have died.\n";
            set_current_health_points(0);
            return true;
        }
        std::cout<<" damage and have " + std::to_string(get_current_health_points()) + " health points left.\n";
        return false;
    }
}

void PlayerStats::gain_health(int healing) {
    int initialHp = get_current_health_points();
    if(get_current_health_points() + healing > get_health_points() + this->tempHealthPoints) {
        set_current_health_points(get_health_points() + this->tempHealthPoints);
    }
    else {
        set_current_health_points(get_current_health_points() + healing);
    }
    std::cout<<"You have gained " + std::to_string(get_current_health_points() - initialHp) + " health for a total of " + std::to_string(get_current_health_points()) + ".\n";
}

void PlayerStats::modify_temp_stats(int tempHealthPoints, int tempAttack, int tempStrength, int tempDefense, int tempLuck, int tempEvasion) {
    if(this->tempHealthPoints < tempHealthPoints) {
        set_current_health_points(get_current_health_points() + tempHealthPoints - this->tempHealthPoints);
        this->tempHealthPoints = tempHealthPoints;
    }
    if(this->tempAttack < tempAttack) {
        this->tempAttack = tempAttack;
    }
    if(this->tempStrength < tempStrength) {
        this->tempStrength = tempStrength;
    }
    if(this->tempDefense < tempDefense) {
        this->tempDefense = tempDefense;
    }
    if(this->tempLuck < tempLuck) {
        this->tempLuck = tempLuck;
    }
    if(this->tempEvasion < tempEvasion) {
        this->tempEvasion = tempEvasion;
    }
}

void PlayerStats::reset_temp_stats() {
    if(get_current_health_points() > get_health_points()) {
        set_current_health_points(get_health_points());
    }
    this->tempHealthPoints = 0;
    this->tempAttack = 0;
    this->tempStrength = 0;
    this->tempDefense = 0;
    this->tempLuck = 0;
    this->tempEvasion = 0;
}

void PlayerStats::gain_stats_from_equip(int healthPoints, int attack, int strength, int defense,
                                        int luck, int evasion, int dmgBonus, int dmgReduction) {
    set_health_points(get_health_points() + healthPoints);
    set_attack(get_attack() + attack);
    set_strength(get_strength() + strength);
    set_defense(get_defense() + defense);
    set_luck(get_luck() + luck);
    set_evasion(get_evasion() + evasion);
    this->dmgBonus += dmgBonus;
    this->dmgReduction += dmgReduction;
}

void PlayerStats::lose_stats_from_unequip(int healthPoints, int attack, int strength, int defense,
                                          int luck, int evasion, int dmgBonus, int dmgReduction) {
    set_health_points(get_health_points() - healthPoints);
    if(get_current_health_points() > get_health_points()) {
        set_current_health_points(get_health_points());
    }
    set_attack(get_attack() - attack);
    set_strength(get_strength() - strength);
    set_defense(get_defense() - defense);
    set_luck(get_luck() - luck);
    set_evasion(get_evasion() - evasion);
    this->dmgBonus -= dmgBonus;
    this->dmgReduction -= dmgReduction;
}

int PlayerStats::get_total_attack() {
    return get_attack() + this->tempAttack;
}

int PlayerStats::get_total_strength() {
    return get_strength() + this->tempStrength;
}

int PlayerStats::get_total_luck() {
    return get_luck() + this->tempLuck;
}

int PlayerStats::get_dmgBonus() {
    return this->dmgBonus;
}

void PlayerStats::get_stats() {
    std::string ownStats = "Your current stats are:\n";

    int currentHealthPoints = get_current_health_points();
    int healthPoints = get_health_points() + tempHealthPoints;
    ownStats += std::to_string(currentHealthPoints) + " health points out of " + std::to_string(healthPoints) + ". ";
    if(currentHealthPoints <= 10) ownStats += "You're on death's door.\n";
    else if(currentHealthPoints <= 20) ownStats += "You have lost a lot of blood and feel weak.\n";
    else if(currentHealthPoints <= 30) ownStats += "You're wounded and in pain.\n";
    else if(currentHealthPoints <= 40) ownStats += "You have seen better days.\n";
    else if(currentHealthPoints <= 50) ownStats += "The pain is barely manageable.\n";
    else if(currentHealthPoints <= 60) ownStats += "You still feel alright.\n";
    else if(currentHealthPoints <= 70) ownStats += "You're injured and in pain.\n";
    else if(currentHealthPoints <= 90) ownStats += "A few cuts and bruises.\n";
    else if(currentHealthPoints <= 100) ownStats += "You feel fine.\n";
    else ownStats += "You feel better than ever.\n";

    int attack = get_attack() + tempAttack;
    ownStats += std::to_string(attack) + " total attack. ";
    if(attack <= 10) ownStats += "You feel extremely disoriented.\n";
    else if(attack <= 20) ownStats += "You feel as if you're drunk.\n";
    else if(attack <= 30) ownStats += "You lack combat training.\n";
    else if(attack <= 40) ownStats += "You're getting better at hitting your opponents.\n";
    else if(attack <= 60) ownStats += "Your accuracy is decent.\n";
    else if(attack <= 80) ownStats += "You feel like your accuracy training has been paying off.\n";
    else if(attack <= 100) ownStats += "You can anticipate your opponents movements and strike with ease.\n";
    else ownStats += "You have mastered the art of attacking a target.\n";

    int strength = get_strength() + tempStrength;
    ownStats += std::to_string(strength) + " total strength. ";
    if(strength <= 10) ownStats += "You feel extremely weak.\n";
    else if(strength <= 20) ownStats += "Your muscle are not developed.\n";
    else if(strength <= 30) ownStats += "You regret not training your muscles.\n";
    else if(strength <= 40) ownStats += "You can probably lift a boulder.\n";
    else if(strength <= 60) ownStats += "You're strong enough to fist fight a weaker enemy.\n";
    else if(strength <= 80) ownStats += "Your muscles are pronounced and developed.\n";
    else if(strength <= 100) ownStats += "You feel very strong and your muscles look sculpted.\n";
    else ownStats += "You could be confused with a pillar man.\n";

    int defense = get_defense() + tempDefense;
    ownStats += std::to_string(defense) + " total defense. ";
    if(defense <= 10) ownStats += "Your reflexes are very slow.\n";
    else if(defense <= 20) ownStats += "You lack eye-hand coordination.\n";
    else if(defense <= 30) ownStats += "You can block an attack with a shield but not much more.\n";
    else if(defense <= 40) ownStats += "You're starting to learn how to defend yourself.\n";
    else if(defense <= 60) ownStats += "You can reliably use your equipment to protect yourself.\n";
    else if(defense <= 80) ownStats += "You're starting to learn how to parry attacks.\n";
    else if(defense <= 100) ownStats += "Your defenses make you very hard to be killed.\n";
    else ownStats += "You're a walking fortress that can take head-on any foe.\n";

    int luck = get_luck() + tempLuck;
    ownStats += std::to_string(luck) + " total luck. ";
    if(luck <= 10) ownStats += "You're afraid the ceiling will give in and kill you.\n";
    else if(luck <= 20) ownStats += "You feel cursed.\n";
    else if(luck <= 30) ownStats += "You're quite unlucky.\n";
    else if(luck <= 40) ownStats += "You don't feel like you're particularly lucky.\n";
    else if(luck <= 60) ownStats += "Lucky things sometimes happen to you.\n";
    else if(luck <= 80) ownStats += "Luck seems to be on your side.\n";
    else if(luck <= 100) ownStats += "Through pure luck you manage to avoid precise attacks.\n";
    else ownStats += "You feel as if there's a divine intervention every time you fight.\n";

    int evasion = get_evasion() + tempEvasion;
    ownStats += std::to_string(evasion) + " total evasion. ";
    if(evasion <= 10) ownStats += "You're barely able to dodge a slow falling tree.\n";
    else if(evasion <= 20) ownStats += "You are not agile at all.\n";
    else if(evasion <= 30) ownStats += "You're agile enough to avoid a sluggish attack.\n";
    else if(evasion <= 40) ownStats += "You're starting to feel more agile.\n";
    else if(evasion <= 60) ownStats += "You're agile enough to avoid the attacks of inexperienced foes.\n";
    else if(evasion <= 80) ownStats += "You're agile enough to often avoid attacks.\n";
    else if(evasion <= 100) ownStats += "You feel very agile, being able to evade even the fastest attacks.\n";
    else ownStats += "Even the most trained and accurate enemies have a hard time hitting you.\n";

    ownStats += std::to_string(dmgBonus) + " damage bonus and " + std::to_string(dmgReduction) + " damage reduction.\n";
    ownStats += "You have " + std::to_string(experience) + " experience points.\n";

    std::cout<<ownStats;
}

int PlayerStats::get_experience() {
    return this->experience;
}

void PlayerStats::gain_stats_from_perk(int xpCost, int dmgBonus, int dmgReduction, int healthPoints, int attack, int strength, int defense,
                                       int luck, int evasion, int hpRegen, int bonusHealing, int escapeBonus) {
    this->experience -= xpCost;
    this->dmgBonus += dmgBonus;
    this->dmgReduction += dmgReduction;
    this->hpRegen += hpRegen;
    this->bonusHealing += bonusHealing;
    this->escapeBonus += escapeBonus;
    set_health_points(get_health_points() + healthPoints);
    set_current_health_points(get_current_health_points() + healthPoints);
    set_attack(get_attack() + attack);
    set_strength(get_strength() + strength);
    set_defense(get_defense() + defense);
    set_luck(get_luck() + luck);
    set_evasion(get_evasion() + evasion);
}

void PlayerStats::regen_health() {
    gain_health(hpRegen);
}

int PlayerStats::get_bonus_healing() {
    return bonusHealing;
}

int PlayerStats::get_escape_bonus() {
    return escapeBonus;
}

int PlayerStats::get_temp_attack() {
    return this->tempAttack;
}

int PlayerStats::get_temp_strength() {
    return this->tempStrength;
}

int PlayerStats::get_temp_luck() {
    return this->tempLuck;
}

int PlayerStats::get_hp_regen() {
    return this->hpRegen;
}

PlayerStats::~PlayerStats()
{
}
