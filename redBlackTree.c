// Compile and run using Omega
// gcc -o redBlackTree redBlackTree.c
// ./redBlackTree < file.dat

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char inputString[200];
    scanf("%s", inputString);
    printf("%s\n", inputString);

    int i;
    int l = strlen(inputString);
    
    // check if it is a tree  
    if (strlen(inputString) % 2 == 0)
    {
        printf("Input String does not represent a tree\n\n");
        exit(0);
    }
    // check for bad characters
    for (i=0; i<l; i++)
    {
        if(inputString[i]!='.' && inputString[i]!='R' && inputString[i]!='B')
        {
            printf("Bad character\n\n");
            exit(0);
        }
    }
    // check if Red node is root
    if(inputString[l-1] == 'R')
    {
        printf("Black height error\n\n");
        exit(0);
    }
    // check it it is a legal RB tree
    for (i=0; i<l-1; i++)
    {
        if (inputString[i]=='R' && inputString[i+1]=='R')
        {
            printf("Consecutive red node error\n\n");
            exit(0);
        }
        if (i>0 && inputString[i-1]=='B' && inputString[i]=='B' && inputString[i+1]=='B')
        {
            printf("Black height error\n\n");
            exit(0);
        }
    }
    printf("Input is a legal RB tree\n\n");
    return 0;
}