#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"

void load_model(Model *m,char *filename)
{
    printf("Initializing model...\n");
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
         printf("Error opening file!\n");
         exit(1);
    }
    char type[20];
    int x, y;
    fscanf(file, "%s %d", type, &m->n_lignes);
    fscanf(file, "%s %d", type, &m->n_colonnes);
    //On malloc le tableau
    m->tab = malloc(m->n_lignes * sizeof(char*));
    for (int i = 0; i < m->n_lignes ; i++)
    {
        m->tab[i] = malloc(m->n_colonnes * sizeof(char));
    }
    //On initialise le tableau en mettant tout à x
    for (int i = 0; i < m->n_lignes; i++)
    {
        for (int j = 0; j < m->n_colonnes; j++)
        {
            m->tab[i][j] = 'x';
        }
    }
    
    while(fscanf(file, "%s %d %d", type, &x, &y) != EOF)
    {
        if (strcmp(type,"CIBLE")==0)
        {
            m->n_cibles++;
            m->tab[x][y] = 'c';
        }
        else if (strcmp(type,"OBSTACLE")==0)
        {
            m->n_obstacles++;
            m->tab[x][y] = 'o';
        }
    }
    fclose(file);
}


void printModel(Model *m)
{
    printf("Printing model...\n");
    for (int i = 0; i < m->n_lignes; i++)
    {
        for (int j = 0; j < m->n_colonnes; j++)
        {
            printf("%c", m->tab[i][j]);
        }
        printf("\n");
    }
    printf("Nombre de cibles : %d\n", m->n_cibles);
    printf("Nombre d'obstacles : %d\n", m->n_obstacles);
}