#ifndef GARDIENS_H
#define GARDIENS_H

#include <stdio.h>
#include <stdlib.h>
#include "model.h"
#include "cibles.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
} Point;


typedef struct {
    int x;
    int y;
    int nb_couvert;
    bool used;
    Point *cible_vues;
} Gardien;

int cases_couvertes(Model *m,int i, int j, Point *tab_points);
void print_cases_couvertes(Point *tab_points, int n_cases);
int cibles_couvertes(Model *m,Cible *cibles,Point *tab_points,int i, int j);
void init_gardien(Model *m, Gardien **gardien, Cible *cibles, Point *tab_points);
void print_guardien(Gardien **gardien, Model *m);
void matrix_to_tab_guardien(Gardien **gardien, Gardien *tab_guard, Model *m);
void triFusion(Gardien *tab_guard, int n);
void fusion(Gardien *tab_guard, int n1, int n2);
void afficher_tab(Gardien *tab_guard, int n);
void swap(Gardien *a, int i, int j);
void reverse_tab(Gardien *tab_guard, int n);
void print_guardiens_choisis(Gardien *tab_guard, int n);
#endif