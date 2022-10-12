#include <cstdio>
#include <cstring>
#include <dirent.h>
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
  return 0;
}

int clean()
{
  int shut = system("rm name -rf");
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

int compareTwoString(char a[], const char b[])  
{  
    int flag=0,i=0;
    while(a[i]!='\0' &&b[i]!='\0')
    {  
       if(a[i]!=b[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    } 
    if(a[i]!='\0'||b[i]!='\0')
       return 1;
    if(flag==0)  
    return 0;  
    else  
    return 1;  
} 

int main(int argc, char *argv[]) {
    const char* help = "help";
    const char* mak = "create";
    const char* ree = "remove";
    const char* cle = "clean";
    const char* bul = "build";
    if(argv[1] == NULL) {
      printf("No arguments provided \n");
      printf("For info on how to use nesmake run \n");
      printf("%s help \n", argv[0]);
    }
    else {
      int c1 = compareTwoString(argv[1], mak); 
      if(c1 == 0) {
        if(argv[2] == NULL) {
          printf("No project name provided \n");
        }
        else {
          DIR* dir = opendir(argv[2]);
          if (dir) {
            printf("Not creating project \n");
            printf("Reason: Project exists \n");
            closedir(dir);
            return 0;
           }
          else {
            download(argv[2]);
            rename("configurer", argv[2]);
            int begone = system("touch name");
            std::ofstream myfile;
            myfile.open("name");
            myfile << argv[2];
            myfile.close();
            config();
            clean();
            DIR* dir1 = opendir(strcat(argv[2], "/src"));
            if (dir1) {
            printf("Project created sucessfully \n");
            closedir(dir1);
            return 0;
            }
            else {
            printf("Project create failed");
            }
          }
        }
      }
    int c2 = compareTwoString(argv[1], help);
    if(c2 == 0) {
        printf("To create a project do \n");
        printf("%s create projectnamehere \n", argv[0]);
      }
    int c3 = compareTwoString(argv[1], ree); 
    if(c3 == 0) {
      if(argv[2] == NULL) {
        printf("No project selected to remove \n");
      }
      else {
        DIR* dir = opendir(argv[2]);
        if (dir) {
          removeproject(argv[2]);
        }
        else {
            printf("Not removing project \n");
            printf("Reason: Project does not exist \n");
          }
        }
      }
     int c4 = compareTwoString(argv[1], cle);
     if(c4 == 0) {
        if(argv[2] == NULL) {
          printf("No project selected to clean \n");
        }
        else {
          DIR* dir = opendir(argv[2]);
          if (dir) {
            cleanproject(argv[2]);
          }
          else {
            printf("Cant clean project \n");
            printf("Reason: Project does not exist \n");
          }
        }
      }
      int c5 = compareTwoString(argv[1], bul); 
      if(c5 == 0) {
        if(argv[2] == NULL) {
          printf("No project selected to build \n");
        }
        else {
          DIR* dir = opendir(argv[2]);
          if (dir) {
            buildproject(argv[2]);
          }
          else {
            printf("Cant build project \n");
            printf("Reason: Project does not exist \n");
          }
        }
      }
      if(c2 + c1 + c3 + c4 + c5 == 5) {
        printf("%s: Unknown argument for the list of arguments run \n", argv[1]);
        printf("%s help \n", argv[0]);
      }
   }
}