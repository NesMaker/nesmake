#include "stdnes.h"
#include <cstdio>
#include <fstream>

int download(char* arg) 
{
  int down = system("git clone https://github.com/NesMaker/configurer -q");
  int clean1  = system("rm configurer/.git -rf");
  int clean2  = system("rm configurer/.github -rf");
  int clean3  = system("rm configurer/.replit -rf");
  int clean4  = system("rm configurer/replit.nix -rf");
  return 0;
}

int config()
{
  int shut = system("cd $(cat name) && mv Makefile makerfiler");
  int shutup = system("cd $(cat name) && make -f makerfiler");
  int shutuup = system("rm name -rf");
  return 0;
}

int removeproject(char* arg) {
  std::ofstream myfile;
  myfile.open("move");
  myfile << arg;
  myfile.close();
  int reehee = system("rm $(cat move) -rf");
  int uhmmmm = system("rm move -rf");
  printf("Removed project %s \n", arg);
  return 0;
}

int buildproject(char* arg) {
  std::ofstream myfile;
  myfile.open("move");
  myfile << arg;
  myfile.close();
  int reehee = system("cd $(cat move) && make");
  int uhmmmm = system("rm move -rf");
  printf("Built project \n");
  return 0;
}

int cleanproject(char* arg) {
  std::ofstream myfile;
  myfile.open("move");
  myfile << arg;
  myfile.close();
  int reehee = system("cd $(cat move) && make clean");
  int uhmmmm = system("rm move -rf");
  printf("You project is now clean \n");
  return 0;
}
