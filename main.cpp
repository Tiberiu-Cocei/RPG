#include <iostream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include "PlayerStats.h"
#include "EnemyStats.h"
#include "EquipableItem.h"
#include "EquipableItemList.h"
#include "ConsumableItemList.h"
#include "Equipment.h"
#include "Inventory.h"
#include "Enemy.h"
#include <windows.h>
#include "Combat.h"
#include <array>
#define _WIN32_WINNT 0x0500
#include "LevelList.h"

int main()
{
  //generating random seed
  srand (time(NULL));

  //changing console size
  HWND console = GetConsoleWindow();
  MoveWindow(console, 255, 90, 1100, 700, TRUE);

  //command string-int mapping for the switch case
  std::map<std::string, int> commandMapping;
  std::map<std::string, int>::iterator commandMappingIterator;
  commandMapping.insert(std::make_pair("help", 1));
  commandMapping.insert(std::make_pair("move north", 2));
  commandMapping.insert(std::make_pair("move east", 3));
  commandMapping.insert(std::make_pair("move west", 4));
  commandMapping.insert(std::make_pair("move south", 5));
  commandMapping.insert(std::make_pair("my stats", 6));
  commandMapping.insert(std::make_pair("equipment", 7));
  commandMapping.insert(std::make_pair("inventory", 8));
  commandMapping.insert(std::make_pair("use item", 9));
  commandMapping.insert(std::make_pair("drop item", 10));
  commandMapping.insert(std::make_pair("exit", 100));

  PlayerStats * playerStats = new PlayerStats(100, 47, 47, 52, 44, 53); //32,32
  Equipment * equipment = new Equipment(playerStats);
  EquipableItemList * equipableItemList = new EquipableItemList();
  ConsumableItemList * consumableItemList = new ConsumableItemList();
  Inventory * inventory = new Inventory();

  EnemyStats* enemyStats = new EnemyStats(225, 42, 47, 33, 32);
  std::vector<EquipableItem*> equipableItems;
  equipableItems.push_back(equipableItemList->get_equipable_item(1));
  equipableItems.push_back(equipableItemList->get_equipable_item(2));
  std::vector<ConsumableItem*> consumableItems;
  consumableItems.push_back(consumableItemList->get_consumable_item(1));
  consumableItems.push_back(consumableItemList->get_consumable_item(1));
  consumableItems.push_back(consumableItemList->get_consumable_item(1));
  consumableItems.push_back(consumableItemList->get_consumable_item(1));
  Enemy* enemy = new Enemy(enemyStats, "Shrek", "The swamp rumbles", "It's all ogre now", consumableItems, equipableItems, 100, 2000);
  Combat* combat = new Combat();
  //combat->encounter(equipment, inventory, enemy);
  LevelList* levelList = new LevelList();
  Level* level = levelList->get_level(1);
  int cord = 198;
  //level->move_in_direction(cord, 'N', equipment, inventory);
  //std::cout<<level->get_possible_directions(198);

  std::array<char, 49> roomLayout = {
       '0', '0', '0', '0', '0', '0', '0',
       '0', '0', '0', '1', '1', '1', '0',
       '0', '1', '1', '1', '0', '0', '0',
       '0', '1', '0', '0', '0', '0', '0',
       '0', '1', '1', '1', '1', '0', '0',
       '0', '0', '0', '0', '1', '1', '0',
       '0', '0', '0', '0', '0', '0', '0'
  };
  //initial coordinates (bottom-right corner)
  int x = 40, commandValue, itemIndexInt;

  std::string commandKey, directions, itemIndex;
  std::cout<<"Write 'help' to view all the commands.\n";

  while (strcmp(commandKey.c_str(), "exit"))
  {
      std::cout << "\n---------------------------------------------------------\n\n";
      directions.clear();
      directions += "The direction(s) you can move in are:";
      if (roomLayout.at(x-7) == '1') {
        directions += " north";
      }
      if (roomLayout.at(x+1) == '1') {
        directions += " east";
      }
      if (roomLayout.at(x+7) == '1') {
        directions += " south";
      }
      if (roomLayout.at(x-1) == '1') {
        directions += " west";
      }
      std::cout << directions << std::endl;
      std::cout << "Enter command: ";
      getline (std::cin, commandKey);
      std::transform(commandKey.begin(), commandKey.end(), commandKey.begin(),
        [](unsigned char c){ return std::tolower(c); });
      commandMappingIterator = commandMapping.find(commandKey);
      if(commandMappingIterator != commandMapping.end()) {
          commandValue = commandMappingIterator->second;
      }
      else {
          commandValue = 0;
      }
      switch(commandValue) {
          case 1 :
            std::cout<<"The possible commands are: 'exit', 'move north/south/west/east', 'my stats', 'equipment', 'inventory', 'use item', 'drop item'.\n";
            break;
          case 2 :
            if (roomLayout.at(x-7) == '1') {
              x-=7;
              std::cout<<"You have moved north.\n";
            }
            else {
              std::cout<<"You cannot move north.\n";
            }
            break;
          case 3 :
            if (roomLayout.at(x+1) == '1') {
              x++;
              std::cout<<"You have moved east.\n";
            }
            else {
              std::cout<<"You cannot move east.\n";
            }
            break;
          case 4 :
            if (roomLayout.at(x-1) == '1') {
              x--;
              std::cout<<"You have moved west.\n";
            }
            else {
              std::cout<<"You cannot move west.\n";
            }
            break;
          case 5 :
            if (roomLayout.at(x+7) == '1') {
              x+=7;
              std::cout<<"You have moved south.\n";
            }
            else {
              std::cout<<"You cannot move south.\n";
            }
            break;
          case 6 :
            equipment->get_player_stats()->get_stats();
            break;
          case 7 :
            equipment->get_equipment();
            break;
          case 8 :
            inventory->show_inventory();
            break;
          case 9 :
            inventory->show_inventory();
            std::cout<<"Enter the number of the item you wish to use: ";
            try {
                getline (std::cin, itemIndex);
                itemIndexInt = stoi(itemIndex);
                inventory->use_item(itemIndexInt, equipment);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            break;
          case 10 :
            inventory->show_inventory();
            std::cout<<"Enter the number of the item you wish to drop: ";
            try {
                getline (std::cin, itemIndex);
                itemIndexInt = stoi(itemIndex);
                inventory->drop_item(itemIndexInt);
            } catch(const std::invalid_argument& error) {
                std::cerr << "Not a number.\n";
            }
            break;
          case 100 :
            std::cout<<"Exiting the game.\n";
            break;
          default :
            std::cout<<"Unknown command. Write \"help\" to view all the commands.\n";
      }
      if(commandValue > 1 && commandValue < 6) {
        std::cout << "Your current coordinates are : " << x/7 + 1 << " " << x%7 + 1 << std::endl;
      }
  }
  return 0;
}
