#include <stdio.h>
#include <stdlib.h>
#include "model.h"

int main(int argc, char* argv[]) {
    Model m;
    char *filename = argv[1];
    load_model(&m, filename);
    printModel(&m);
    return 0;
}