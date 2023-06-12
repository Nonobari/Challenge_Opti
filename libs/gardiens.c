#include "gardiens.h"

// retourne un tableau de points couverts (tab_points) par un gardien en coordonéne i,j
int cases_couvertes(Model *m,int i, int j, Point *tab_points) 
{    
    int n_cases = 0;
    //regarder à gauche
    if (m->tab[i][j] == 'o') {
        //printf("Je suis sur un obstacle\n");
        return 0;
    }
    else {
        //printf("Je regarde en %d %d", i, j);
        tab_points[n_cases].x = i;
        tab_points[n_cases].y = j;
        n_cases++;
    }
    for (int c = j-1; c >= 0; c --) {
        //printf("Je regarde à gauche\n");
        if (m->tab[i][c] == 'o') {
            break;
        }
        tab_points[n_cases].x = i;
        tab_points[n_cases].y = c;
        n_cases++;
    }
    //regarder à droite
    for (int c = j+1; c < m->n_colonnes; c ++) {
        //printf("Je regarde à droite\n");
        if (m->tab[i][c] == 'o') {
            break;
        }
        tab_points[n_cases].x = i;
        tab_points[n_cases].y = c;
        n_cases++;
    }
    //regarder en haut
    for (int l = i-1; l >= 0; l --) {
        //printf("Je regarde en haut\n");

        if (m->tab[l][j] == 'o') {
            break;
        }
        tab_points[n_cases].x = l;
        tab_points[n_cases].y = j;
        n_cases++;
    }
    //regarder en bas
    for (int l = i+1; l < m->n_lignes; l ++) {
        //printf("Je regarde en bas\n");

        if (m->tab[l][j] == 'o') {
            break;
        }
        tab_points[n_cases].x = l;
        tab_points[n_cases].y = j;
        n_cases++;
    }
    return n_cases;
}

void print_cases_couvertes(Point tab_points[], int n_cases) {
    for (int i = 0; i < n_cases; i++) {
        printf("x: %d, y: %d\n", tab_points[i].x, tab_points[i].y);
    }
}