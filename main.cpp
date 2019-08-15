#include <iostream>
#include <algorithm>
#include <cctype>
#include <string.h>
#include <map>

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
  commandMapping.insert(std::make_pair("exit", 100));

  //room layout, true represents where you can go and false where you cannot
  bool room[7][7] = {
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
  //the player writes exit when they wish to stop playing
  while (strcmp(command.c_str(), "exit"))
  {
      std::cout << "---------------------------------------------------------\n";
      directions.clear();
      directions += "The direction(s) you can move in are:";
      if (room[x-1][y] == 1) {
        directions += " north";
      }
      if (room[x][y+1] == 1) {
        directions += " east";
      }
      if (room[x+1][y] == 1) {
        directions += " south";
      }
      if (room[x][y-1] == 1) {
        directions += " west";
      }
      std::cout << directions << std::endl;
      std::cout << "Enter command: ";
      getline (std::cin, command);
      std::transform(command.begin(), command.end(), command.begin(),
        [](unsigned char c){ return std::tolower(c); });
      //std::cout << "Your command is " << command << std::endl;
      commandMappingIterator = commandMapping.find(command);
      commandKey = commandMappingIterator->second;
      switch(commandKey) {
          case 1 :
            std::cout<<"The possible commands are: exit, move north/south/west/east.\n";
            break;
          case 2 :
            if (room[x-1][y] == 1) {
              x--;
              std::cout<<"You have moved north.\n";
            }
            else {
              std::cout<<"Cannot move north.\n";
            }
            break;
          case 3 :
            if (room[x][y+1] == 1) {
              y++;
              std::cout<<"You have moved east.\n";
            }
            else {
              std::cout<<"Cannot move east.\n";
            }
            break;
          case 4 :
            if (room[x][y-1] == 1) {
              y--;
              std::cout<<"You have moved west.\n";
            }
            else {
              std::cout<<"Cannot move west.\n";
            }
            break;
          case 5 :
            if (room[x+1][y] == 1) {
              x++;
              std::cout<<"You have moved south.\n";
            }
            else {
              std::cout<<"Cannot move south.\n";
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
}
