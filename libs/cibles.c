#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "model.h"
#include "cibles.h"

void init_cibles(Model *m, Cible *cibles)
{
    //Initialiser toutes les cibles à « non couverte »
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


bool cibles_toutes_couvertes(Model *m, Cible *cibles)
/*Teste si toutes les civles sont couvertes*/
{
    for (int i = 0 ; i < m->n_cibles ; i++)
    {
        if (cibles[i].couvert == false)
        {
            return false;
        }
    }
    return true;
}
