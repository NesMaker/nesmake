#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>


int download(char* arg) 
{
  int down = system("git clone https://github.com/NesMaker/configurer -q");
  int clean1  = system("rm configurer/.git -rf");
  int clean2  = system("rm configurer/.github -rf");
  return 0;
}

int config(char* arg)
{
  int shut = system("cd hello && mv Makefile makerfiler && make -f makerfiler && rm makefiler -rf");
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
    const char* cre = "create";
    if(argv[1] == NULL) {
      printf("No arguments provided \n");
      printf("For info on how to use nesmake run \n");
      printf("%s help \n", argv[0]);
    }
    else {
      int c2 = compareTwoString(argv[1], help);  
      if(c2 == 0) {
        printf("To create a project do \n");
        printf("%s create projectnamehere \n", argv[0]);
      }
      int c1 = compareTwoString(argv[1], cre); 
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
            config(argv[2]);
            DIR* dir1 = opendir(argv[2]);
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
      if(c2 + c1 == 2) {
        printf("%s: Unknown argument for the list of arguments run \n", argv[1]);
        printf("%s help \n", argv[0]);
       }
    }
}