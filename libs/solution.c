#include "solution.h"

void ecrire_solution(int instance, Gardien *tab_guard, int n)
{
    
    //concaténer le nom du fichier avec le numero de l'instance
    char filename[40];
    sprintf(filename, "solutions/res_%d.txt", instance);
    FILE *file = fopen(filename, "w+");
    if (file == NULL)
    {
         printf("Error opening file!\n");
         exit(1);
    }
    
    /*
    EQUIPE nom de l’équipe 
    INSTANCE n
    x1 y1
    x2 y2*/
    printf("ecriture fichier");
    fprintf(file, "EQUIPE Les 2 fantastiques\n");
    fprintf(file, "INSTANCE %d\n", instance);
    for (int i = 0; i < n; i++)
    {

        if (tab_guard[i].used)
            fprintf(file, "%d %d\n", tab_guard[i].x, tab_guard[i].y);
    }
    fclose(file);

}

void ecrire_toutes_instances(Gardien *tab_guard, int n_gardiens)
// fonctionne pas wsh
{
    for (int i = 1; i < 16 ; i++)
    {
        ecrire_solution(i, tab_guard, n_gardiens);
    }
}