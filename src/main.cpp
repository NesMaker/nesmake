#include <cstdio>
#include <cstdlib>
#include <string>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

int compareTwoString(char[],char[]);  

int compareTwoString(char a[],char b[])  
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
    if(argv[1] == NULL) {
      printf("No arguments provided \n");
      printf("For info on how to use nesmake run \n");
      printf("%s help \n", argv[0]);
    }
    else {
      int c2 = compareTwoString(argv[1], "help");  
      if(c2 == 0) {
        printf("To create a project do \n");
        printf("%s create projectnamehere \n", argv[0]);
      }
      int c1 = compareTwoString(argv[1], "create"); 
      if(c1 == 0) {
        if(argv[2] == NULL) {
          printf("No project name provided \n");
        }
        else {
          mkdir(argv[2], 0700);
          // printf("%s is your project name \n", argv[2]);
        }
      }
    }
}