#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "cibles.h"
#include "gardiens.h"
#include "solution.h"

#define TAILLE_TAB 200
int main(int argc, char *argv[]) {
    Model m;
    Point tab_points[TAILLE_TAB];
    int instance;
    //load le model
    char filename[40];
    if (argc != 2)
    {
        printf("Veuillez entrer un numéro d'instance\n");
        return 0;
    }
    else 
        instance = atoi(argv[1]);

    sprintf(filename,"Instances/gr%d.txt", instance);
    printf("filename %s\n", filename);
    load_model(&m, filename);
    printModel(&m);
    //Cible cibles[m.n_cibles];
    
    //init matrice gardien
    /*Gardien **gardiens;
    gardiens = malloc(sizeof(Gardien*) * m.n_lignes);
    for (int i = 0; i < m.n_lignes ; i++)
    {
        gardiens[i] = malloc(sizeof(Gardien) * m.n_colonnes);
    }*/

    

    //initiale les cibles pour une instance
    //init_cibles(&m, cibles);
    
    //calcul les cibles couvertes par la case i j
    //printf("Cibles couvertes : %d\n", cibles_couvertes(&m, cibles, tab_points, 3, 3));
    //init_gardien(&m, gardiens, cibles, tab_points);
    //add_cibles(&m, cibles, gardiens);
    //print_guardien(gardiens, &m);
    
    //création d'un tableau une dimension pour trier les gardiens
    //Gardien *tab_gardiens = (Gardien*) malloc(sizeof(Gardien) * m.n_lignes * m.n_colonnes);
    //matrix_to_tab_guardien(gardiens, tab_gardiens, &m);
    //afficher_tab(tab_gardiens, m.n_lignes * m.n_colonnes);
    
    //triFusion(tab_gardiens, m.n_lignes * m.n_colonnes);
    //reverse_tab(tab_gardiens, m.n_lignes * m.n_colonnes);
    //afficher_tab(tab_gardiens, m.n_lignes * m.n_colonnes);

    //A cette étape le tableau tab_gardiens est trié par ordre décroissant
    // on sélectionne le meilleur gardien, on met les cibles couvertes à 1
    
    /*int i = 0;
    while(cibles_toutes_couvertes(&m,cibles) == false)
    {
        
    }
    print_guardiens_choisis(tab_gardiens, m.n_lignes * m.n_colonnes);
    ecrire_solution(instance, tab_gardiens,m.n_lignes * m.n_colonnes);*/
}