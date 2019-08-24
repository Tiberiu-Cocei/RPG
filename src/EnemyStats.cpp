#include "EnemyStats.h"
#include <string.h>
#include <iostream>

EnemyStats::EnemyStats(short int healthPoints, short int attack, short int strength, short int defense, short int evasion)
: Stats(healthPoints, attack, strength, defense, 0, evasion)
{
}

bool EnemyStats::take_damage(short int attack, short int strength, short int luck, short int dmgBonus) {
    short int evade = rand() % 50 + 1 - luck/10 + get_evasion()/5  - attack/10;
    if(evade > 42) {
        std::cout<<"Your enemy has avoided the attack.\n";
        return false;
    }
    else {
        short int damage = dmgBonus + strength/1.8f - get_defense()/3.5f;
        if(damage < 0) {
            damage = 0;
        }
        set_current_health_points(get_current_health_points() - damage);
        std::cout<<"The enemy has suffered " + std::to_string(damage);
        if(get_current_health_points() <= 0) {
            std::cout<<" damage and has died.\n";
            set_current_health_points(0);
            return true;
        }
        std::cout<<" damage and has " + std::to_string(get_current_health_points()) + " health points left.\n";
        return false;
    }
}

void EnemyStats::gain_health(short int healing) {
    if(get_current_health_points() + healing >= get_health_points()) {
        set_current_health_points(get_health_points());
    }
    else {
        set_current_health_points(get_current_health_points() + healing);
    }
    std::cout<<"The enemy gained " + std::to_string(healing) + " health for a total of " + std::to_string(get_current_health_points()) + ".\n";
}

void EnemyStats::get_stats() {
    std::string enemyStats = "The stats of your enemy are :\n";

    short int currentHealthPoints = get_current_health_points();
    short int healthPoints = get_health_points();
    enemyStats += std::to_string(currentHealthPoints) + " health points out of " + std::to_string(healthPoints) + ". ";
    if(currentHealthPoints <= healthPoints/10) enemyStats += "They're almost dead.\n";
    else if(currentHealthPoints <= healthPoints/5) enemyStats += "They're missing chunks of themselves.\n";
    else if(currentHealthPoints <= healthPoints/3) enemyStats += "T'is but a scratch.\n";
    else if(currentHealthPoints <= healthPoints/2) enemyStats += "They're wounded and in pain.\n";
    else if(currentHealthPoints <= healthPoints/1.3f) enemyStats += "They've seen better days.\n";
    else if(currentHealthPoints <= healthPoints/1.1f) enemyStats += "They're hurt.\n";
    else enemyStats += "You feel better than ever.\n";

    short int attack = get_attack();
    enemyStats += std::to_string(attack) + " total attack. ";
    if(attack <= 10) enemyStats += "They're incredibly inaccurate.\n";
    else if(attack <= 20) enemyStats += "They seem as if they're drunk.\n";
    else if(attack <= 30) enemyStats += "They lack fighting experience.\n";
    else if(attack <= 40) enemyStats += "They seem to have fought before and know a thing or two.\n";
    else if(attack <= 60) enemyStats += "Their accuracy is decent.\n";
    else if(attack <= 80) enemyStats += "They are very accurate.\n";
    else if(attack <= 100) enemyStats += "They're experienced and should not be taken lightly.\n";
    else enemyStats += "They have fought countless times and know what your next move is going to be most of the time.\n";

    short int strength = get_strength();
    enemyStats += std::to_string(strength) + " total strength. ";
    if(strength <= 10) enemyStats += "They seem to be extremely weak.\n";
    else if(strength <= 30) enemyStats += "They seem weak.\n";
    else if(strength <= 50) enemyStats += "They don't seem to possess much in terms of power.\n";
    else if(strength <= 65) enemyStats += "They seem to be more powerful than your average foe.\n";
    else if(strength <= 80) enemyStats += "They are strong enough not to underestimate.\n";
    else if(strength <= 100) enemyStats += "They are strong and dangerous.\n";
    else enemyStats += "They're much stronger than most enemies that you have encountered before.\n";

    short int defense = get_defense();
    enemyStats += std::to_string(defense) + " total defense. ";
    if(defense <= 10) enemyStats += "They lack any kind of defense.\n";
    else if(defense <= 20) enemyStats += "Their defenses are fragile and weak.\n";
    else if(defense <= 30) enemyStats += "Their defense is on par with leather equipment.\n";
    else if(defense <= 40) enemyStats += "Their defense is worth a bit more than metal scraps.\n";
    else if(defense <= 60) enemyStats += "Their defense is on par with a proper set of iron armor.\n";
    else if(defense <= 80) enemyStats += "Their defense is sturdy and reinforced.\n";
    else if(defense <= 100) enemyStats += "Their defense is on par with armor made using the most expensive of materials.\n";
    else enemyStats += "Their defense is of legend and extremely hard to penetrate.\n";

    short int evasion = get_evasion();
    enemyStats += std::to_string(evasion) + " total evasion. ";
    if(evasion <= 10) enemyStats += "They are extremely unlikely to be able to evade any type of attack.\n";
    else if(evasion <= 20) enemyStats += "Untrained and unskilled, they're not likely to dodge.\n";
    else if(evasion <= 35) enemyStats += "Lacking agility, your opponent will rarely be able to evade any attack.\n";
    else if(evasion <= 50) enemyStats += "Somewhat agile, they may be able to avoid an attack or two.\n";
    else if(evasion <= 75) enemyStats += "Your opponent is very agile and may avoid some of your attacks.\n";
    else if(evasion <= 100) enemyStats += "A slippery foe, likely to avoid your attacks.\n";
    else enemyStats += "They're extremely agile and skilled in dodging attacks.\n";

    std::cout<<enemyStats;
}

EnemyStats::~EnemyStats()
{
}
