#include <iostream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <map>
#include "PlayerStats.h"

int main()
{
  //command string-int mapping for the switch case
  std::map<std::string, int> commandMapping;
  std::map<std::string, int>::iterator commandMappingIterator;
  commandMapping.insert(std::make_pair("help", 1));
  commandMapping.insert(std::make_pair("move north", 2));
  commandMapping.insert(std::make_pair("move east", 3));
  commandMapping.insert(std::make_pair("move west", 4));
  commandMapping.insert(std::make_pair("move south", 5));
  commandMapping.insert(std::make_pair("my stats", 6));
  commandMapping.insert(std::make_pair("exit", 100));

  PlayerStats * playerStats = new PlayerStats(100, 25, 25, 25, 25, 25);
//  playerStats->get_own_stats();
//  playerStats->set_strength(playerStats->get_strength()+105);
//  playerStats->get_own_stats();

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
  int x = 5, y = 5, commandKey;

  std::string command, directions;
  std::cout<<"Write \"help\" to view all the commands.\n";

  while (strcmp(command.c_str(), "exit"))
  {
      std::cout << "---------------------------------------------------------\n";
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
            std::cout<<"The possible commands are: 'exit', 'move north/south/west/east', 'my stats'.\n";
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
            playerStats->get_own_stats();
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
