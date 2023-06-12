#ifndef GARDIENS_H
#define GARDIENS_H

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "cibles.h"



typedef struct {
    int x;
    int y;
    int nb_couvert;
} Gardien;

typedef struct {
    int x;
    int y;
} Point;

int cases_couvertes(Model *m,int i, int j, Point *tab_points);
void print_cases_couvertes(Point *tab_points, int n_cases);
#endif