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

int main()
{
  //generating random seed
  srand (time(NULL));

  //changing console text color
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int colorText = 14;
  SetConsoleTextAttribute(hConsole, colorText);

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
  enemy->enemy_attack(playerStats);
  enemy->enemy_attack(playerStats);
  enemy->enemy_defend(playerStats);
  enemy->enemy_defend(playerStats);

  bool roomLayout[7][7] = {
      { 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 1, 1, 0 },
      { 0, 1, 1, 1, 0, 0, 0 },
      { 0, 1, 0, 0, 0, 0, 0 },
      { 0, 1, 1, 1, 1, 0, 0 },
      { 0, 0, 0, 0, 1, 1, 0 },
      { 0, 0, 0, 0, 0, 0, 0 }
  };
  //initial coordinates (bottom-right corner)
  int x = 5, y = 5, commandKey, itemIndexInt;

  std::string command, directions, itemIndex;
  std::cout<<"Write 'help' to view all the commands.\n";

  while (strcmp(command.c_str(), "exit"))
  {
      std::cout << "\n---------------------------------------------------------\n\n";
      directions.clear();
      directions += "The direction(s) you can move in are:";
      if (roomLayout[x-1][y] == 1) {
        directions += " north";
      }
      if (roomLayout[x][y+1] == 1) {
        directions += " east";
      }
      if (roomLayout[x+1][y] == 1) {
        directions += " south";
      }
      if (roomLayout[x][y-1] == 1) {
        directions += " west";
      }
      std::cout << directions << std::endl;
      std::cout << "Enter command: ";
      getline (std::cin, command);
      std::transform(command.begin(), command.end(), command.begin(),
        [](unsigned char c){ return std::tolower(c); });
//      std::cout << "Your command is " << command << std::endl;
      commandMappingIterator = commandMapping.find(command);
      if(commandMappingIterator != commandMapping.end()) {
          commandKey = commandMappingIterator->second;
      }
      else {
          commandKey = 0;
      }
      switch(commandKey) {
          case 1 :
            std::cout<<"The possible commands are: 'exit', 'move north/south/west/east', 'my stats', 'equipment', 'inventory', 'use item', 'drop item'.\n";
            break;
          case 2 :
            if (roomLayout[x-1][y] == 1) {
              x--;
              std::cout<<"You have moved north.\n";
            }
            else {
              std::cout<<"You cannot move north.\n";
            }
            break;
          case 3 :
            if (roomLayout[x][y+1] == 1) {
              y++;
              std::cout<<"You have moved east.\n";
            }
            else {
              std::cout<<"You cannot move east.\n";
            }
            break;
          case 4 :
            if (roomLayout[x][y-1] == 1) {
              y--;
              std::cout<<"You have moved west.\n";
            }
            else {
              std::cout<<"You cannot move west.\n";
            }
            break;
          case 5 :
            if (roomLayout[x+1][y] == 1) {
              x++;
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
      if(commandKey > 1 && commandKey < 6) {
        std::cout << "Your current coordinates are : " << x << " " << y << std::endl;
      }
  }
  return 0;
}
