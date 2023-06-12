#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "cibles.h"
#include "gardiens.h"

int main(int argc, char* argv[]) {
    Model m;
    Cible cibles;
    Point tab_points[60];
    
    char *filename = argv[1];
    load_model(&m, filename);
    printModel(&m);
    
    init_cibles(&m, &cibles);
    
    int n_cases_couvertes = cases_couvertes(&m, 3, 3, tab_points);
    printf("Nombre de cases couvertes : %d\n", n_cases_couvertes);
    print_cases_couvertes(tab_points, n_cases_couvertes);

    return 0;
}