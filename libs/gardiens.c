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

void print_cases_couvertes(Point *tab_points, int n_cases) {
    for (int i = 0; i < n_cases; i++) {
        printf("x: %d, y: %d\n", tab_points[i].x, tab_points[i].y);
    }
}

int cibles_couvertes(Model *m,Cible *cibles,Point *tab_points,int i, int j)
// parcourt les cibles et retourne le nombre de cibles couvertes si on pose un gardien en i,j
{
    int n_cases = cases_couvertes(m,i,j,tab_points);
    int n_cible_couverte = 0;
    int x,y;
    for (int i = 0; i<m->n_cibles; i++)
    {
        x = cibles[i].x;
        y = cibles[i].y;
        //printf("La cible n %d est en %d %d\n", i, x, y);

        for (int n = 0; n < n_cases; n ++)
        {
            if (tab_points[n].x == x && tab_points[n].y == y && cibles[i].couvert == false)
            {
                //la cible est couverte
                //cibles[i].couvert = 1;
                n_cible_couverte ++;
            }
        }

    }
    return n_cible_couverte;
}

void init_gardien(Model *m, Gardien **gardien, Cible *cibles, Point *tab_points)
{
    for (int i = 0; i < m->n_lignes ; i++)
    {
        for (int j = 0; j < m->n_colonnes ; j++)
        {
            gardien[i][j].x = i;
            gardien[i][j].y = j;
            gardien[i][j].nb_couvert = cibles_couvertes(m, cibles, tab_points, i, j);
        }
    }

}

void print_guardien(Gardien **gardien, Model *m)
{
    for (int i = 0; i < m->n_lignes ; i++)
    {
        for (int j = 0; j < m->n_colonnes ; j++)
        {
            printf("%d", gardien[i][j].nb_couvert);
        }
        printf("\n");
    }
}

void matrix_to_tab_guardien(Gardien **gardien, Gardien *tab_guard, Model *m)
{
    int nb_ligne = m->n_lignes;
    int nb_colonne = m->n_colonnes;
    int k = 0;
    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonne; j++) {
            tab_guard[k].x = gardien[i][j].x;
            tab_guard[k].y = gardien[i][j].y;
            tab_guard[k].nb_couvert = gardien[i][j].nb_couvert;
            //printf("gardien[%d] = %d\n", k,tab_guard[k].nb_couvert);
            k++;
        }
    }
}

void afficher_tab(Gardien *tab_guard, int n)
{
    for (int i = 0; i < n; i++) {
        printf("gardien[%d] = %d\n", i,tab_guard[i].nb_couvert);
    }
}

void triFusion(Gardien *tab_guard, int n)
{
    if (n > 1)
    {
        int n1 = n/2;
        int n2 = n - n1;
        triFusion(tab_guard, n1);
        triFusion(tab_guard + n1, n2);
        fusion(tab_guard, n1, n2);
    }
}

void fusion(Gardien *tab_guard, int n1, int n2)
{
    Gardien *tab1 = malloc(n1*sizeof(Gardien));
    Gardien *tab2 = malloc(n2*sizeof(Gardien));
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    for (int i = 0; i < n1; i++) {
        tab1[i] = tab_guard[i];
    }
    for (int i = 0; i < n2; i++) {
        tab2[i] = tab_guard[n1+i];
    }
    while (i1 < n1 && i2 < n2)
    {
        if (tab1[i1].nb_couvert < tab2[i2].nb_couvert)
        {
            tab_guard[i] = tab1[i1];
            i1++;
        }
        else
        {
            tab_guard[i] = tab2[i2];
            i2++;
        }
        i++;
    }
    while (i1 < n1)
    {
        tab_guard[i] = tab1[i1];
        i1++;
        i++;
    }
    while (i2 < n2)
    {
        tab_guard[i] = tab2[i2];
        i2++;
        i++;
    }
    free(tab1);
    free(tab2);
}

void swap(Gardien *tab_guard, int i, int j)
{
    Gardien tmp = tab_guard[i];
    tab_guard[i] = tab_guard[j];
    tab_guard[j] = tmp;
}

void reverse_tab(Gardien *tab_guard, int n)
{
    for (int i = 0; i < n/2; i++) {
        swap(tab_guard, i, n-i-1);
    }
}


void print_guardiens_choisis(Gardien *tab_guard, int n)
{
    for (int i = 0; i < n; i++) {
        if (tab_guard[i].used == 1) {
            printf("gardien[%d] = %d\n", i,tab_guard[i].nb_couvert);
        }
    }
}

void add_coordonnes_cibles(Model *m,Cible *cibles, Gardien *gardien)
{
    Point *tab_points = malloc(m->n_lignes*m->n_colonnes*sizeof(Point));
    int n_cases = cases_couvertes(m,gardien->x,gardien->y,tab_points);
    
    int nbr_cible_vu_gardien = gardien->nb_couvert;
    int k=0;
    gardien->cible_vues = malloc(nbr_cible_vu_gardien*sizeof(Point));
    for (int i = 0; i<m->n_cibles; i++)
    {
        Point adresse;

        adresse.x = cibles[i].x;
        adresse.y = cibles[i].y;
        //printf("La cible n %d est en %d %d\n", i, x, y);

        for (int n = 0; n < n_cases; n ++)
        {
            if (tab_points[n].x == adresse.x && tab_points[n].y == adresse.y)
            {
                //la cible est couverte
                //cibles[i].couvert = 1;
                gardien->cible_vues[k] = adresse;
                k++;
            }
        }

    }
}

void add_cibles(Model *m,Cible *cibles, Gardien **gardiens)
{
    for (int i = 0; i < (m->n_lignes*m->n_colonnes); i++) {
        add_coordonnes_cibles(m,cibles,gardiens[i]);
    }
}