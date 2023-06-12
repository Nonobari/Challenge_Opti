#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "opti.h"

int main(int argc, char* argv[]) {
    Model m;
    Cible cibles;
    char *filename = argv[1];
    load_model(&m, filename);
    printModel(&m);
    init_cibles(&m, &cibles);
    return 0;
}