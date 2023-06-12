#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "model.h"
#include "cibles.h"

void init_cibles(Model *m, Cible *cibles)
{
    //Initialiser toutes les cibles à « non couverte »
    cibles = malloc(m->n_cibles * sizeof(Cible));
    int n = 0;
    for (int i = 0; i < m->n_lignes; i++)
    {   
        for (int j = 0; j < m->n_colonnes; j++)
        {
            if (m->tab[i][j] == 'c')
            {
                cibles[n].x = i;
                cibles[n].y = j;
                cibles[n].couvert = false;
                n++;
            }
        }
    }
        
}

