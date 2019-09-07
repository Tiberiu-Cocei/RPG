#include "Combat.h"
#include <algorithm>
#include <windows.h>

Combat::Combat()
{
    combatMapping.insert(std::make_pair("help", 1));
    combatMapping.insert(std::make_pair("attack", 2));
    combatMapping.insert(std::make_pair("escape", 3));
    combatMapping.insert(std::make_pair("my stats", 4));
    combatMapping.insert(std::make_pair("enemy stats", 5));
    combatMapping.insert(std::make_pair("equipment", 6));
    combatMapping.insert(std::make_pair("inventory", 7));
    combatMapping.insert(std::make_pair("use item", 8));
}

bool Combat::encounter(Equipment*& player, Inventory*& inventory, Enemy*& enemy) {
    enemy->enemy_encounter();
    while(1) {
        std::cout << "\nEnter command: ";
        getline (std::cin, command);
        std::transform(command.begin(), command.end(), command.begin(),
          [](unsigned char c){ return std::tolower(c); });
        combatMappingIterator = combatMapping.find(command);
        if(combatMappingIterator != combatMapping.end()) {
            commandKey = combatMappingIterator->second;
        }
        else {
            commandKey = 0;
        }
        switch(commandKey) {
          case 1 :
            std::cout<<"The possible commands are: 'attack', 'escape', 'my stats', 'enemy stats', 'equipment', 'inventory', 'use item'.\n";
            break;
          case 2 :
            std::cout<<"You attempt to strike the enemy!\n";
            isDead = enemy->enemy_defend(player->get_player_stats());
            if(isDead == true) {
                enemy->enemy_death(inventory);
                return false;
            }
            else {
                isDead = enemy_turn(player->get_player_stats(), enemy);
                if(isDead == true) return true;
            }
            break;
          case 3 :
            {
                int escapeRoll = rand() % 100 + 1;
                if(escapeRoll > 50) {
                    std::cout<<"You successfully escape from your enemy and return to the same place.\n";
                    return false;
                }
                else {
                    isDead = enemy_turn(player->get_player_stats(), enemy);
                    if(isDead == true) return true;
                }
                break;
            }
          case 4 :
            player->get_player_stats()->get_stats();
            break;
          case 5 :
            enemy->get_enemy_stats()->get_stats();
            break;
          case 6 :
            player->get_equipment();
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
                inventory->use_item(itemIndexInt, player);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            isDead = enemy_turn(player->get_player_stats(), enemy);
            if(isDead == true) return true;
            break;
          default :
            std::cout<<"Unknown command. Write \"help\" to view all the commands.\n";
      }
    }
}

bool Combat::enemy_turn(PlayerStats*& playerStats, Enemy*& enemy) {
    //TO DO: enemy special attacks -> random roll for type of attack
    Sleep(600);
    std::cout<<"\nThe " + enemy->get_name() + " attacks!\n";
    return enemy->enemy_attack(playerStats);
}

Combat::~Combat()
{
}
