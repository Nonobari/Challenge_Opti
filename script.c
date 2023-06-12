#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    
    char si[30];
    for (int i = 1; i < 17; i++)
    {
        //execute main avec i en argument
        sprintf(si, "%d", i);
        printf("%s",si);
        char *args[] = {"main", si, NULL};
        execv("main", args);
    }
}