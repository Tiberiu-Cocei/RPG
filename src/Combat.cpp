#include "Combat.h"
#include <algorithm>
#include <windows.h>

Combat::Combat() {
    combatMapping.insert(std::make_pair("help", 1));
    combatMapping.insert(std::make_pair("attack", 2));
    combatMapping.insert(std::make_pair("escape", 3));
    combatMapping.insert(std::make_pair("my stats", 4));
    combatMapping.insert(std::make_pair("enemy stats", 5));
    combatMapping.insert(std::make_pair("equipment", 6));
    combatMapping.insert(std::make_pair("inventory", 7));
    combatMapping.insert(std::make_pair("use item", 8));
}

bool Combat::encounter(Equipment*& equipment, PlayerStats*& playerStats, std::vector<Perk*> playerPerks, Inventory*& inventory, Enemy*& enemy, bool isBoss) {
    enemy->enemy_encounter();
    while(1) {
        std::cout << "\nEnter command: ";
        getline (std::cin, commandKey);
        std::transform(commandKey.begin(), commandKey.end(), commandKey.begin(),
          [](unsigned char c){ return std::tolower(c); });
        combatMappingIterator = combatMapping.find(commandKey);
        if(combatMappingIterator != combatMapping.end()) {
            commandValue = combatMappingIterator->second;
        }
        else {
            commandValue = 0;
        }
        switch(commandValue) {
          case 1 :
            std::cout<<"The possible commands are: 'attack', 'escape', 'my stats', 'enemy stats', 'equipment', 'inventory', 'use item'.\n";
            break;
          case 2 :
            std::cout<<"You attempt to strike the enemy!\n";
            isDead = player_normal_attack(playerStats, playerPerks, enemy);
            if(isDead == true) {
                enemy->enemy_death(inventory);
                playerStats->reset_temp_stats();
                enemy->get_enemy_stats()->reset_stats();
                if(playerStats->get_hp_regen() !=0) {
                    playerStats->regen_health();
                }
                playerStats->gain_experience(enemy->get_xp());
                return false;
            }
            else {
                isDead = enemy_turn(playerStats, enemy);
                if(isDead == true) {
                    enemy->get_enemy_stats()->reset_stats();
                    return true;
                }
            }
            break;
          case 3 :
            {
                int escapeRoll = rand() % 100 + 1 + playerStats->get_escape_bonus();
                if(escapeRoll > 60 && isBoss == false) {
                    std::cout<<"You successfully escape and make your way back.\n";
                    playerStats->reset_temp_stats();
                    enemy->get_enemy_stats()->reset_stats();
                    return false;
                }
                else if(escapeRoll <= 60 && isBoss == false) {
                    std::cout<<"You failed to escape from your enemy!\n";
                    isDead = enemy_turn(playerStats, enemy);
                    if(isDead == true) {
                        enemy->get_enemy_stats()->reset_stats();
                        return true;
                    }
                }
                else {
                    std::cout<<"It's too late to think about running!\n";
                }
                break;
            }
          case 4 :
            playerStats->get_stats();
            break;
          case 5 :
            enemy->get_enemy_stats()->get_stats();
            break;
          case 6 :
            equipment->get_equipment();
            break;
          case 7 :
            inventory->show_inventory();
            break;
          case 8 :
            inventory->show_inventory();
            std::cout<<"Enter the number of the item you wish to use: ";
            try {
                getline (std::cin, itemIndex);
                itemIndexInt = stoi(itemIndex);
                inventory->use_item(itemIndexInt, equipment, playerStats);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            isDead = enemy_turn(playerStats, enemy);
            if(isDead == true) {
                enemy->get_enemy_stats()->reset_stats();
                return true;
            }
            break;
          default :
            std::cout<<"Unknown command. Write \"help\" to view all the commands.\n";
      }
    }
}

bool Combat::player_normal_attack(PlayerStats*& playerStats, std::vector<Perk*> playerPerks, Enemy*& enemy) {
    //checks for Executioner perk
    if(playerStats->get_perk_state(0) == true && enemy->get_enemy_stats()->get_current_health_points() <= 50) {
        playerStats->modify_temp_stats(0, 0, playerStats->get_strength()/3, 0, 0, 0);
    }
    return enemy->enemy_defend(playerStats);
}

bool Combat::enemy_turn(PlayerStats*& playerStats, Enemy*& enemy) {
    //TO DO: enemy special attacks -> random roll for type of attack
    Sleep(600);
    if(enemy->is_stunned() == false) {
        std::cout<<"\nThe " + enemy->get_name() + " attacks!\n";
        return enemy->enemy_attack(playerStats);
    }
    else {
        std::cout<<"Your foe is unable to attack this turn!\n";
        return false;
    }
}

Combat::~Combat() {}
