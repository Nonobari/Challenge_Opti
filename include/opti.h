#ifndef OPTI_H
#define OPTI_H

#include <stdbool.h>
#include "model.h"

//structure de cible
typedef struct {
    int x;
    int y;
    bool couvert;
} Cible;


void init_cibles(Model *m, Cible *cibles);

#endif