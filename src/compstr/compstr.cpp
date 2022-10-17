#include "compstr.h"

int compareTwoString(char a[], const char b[]) {  
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
