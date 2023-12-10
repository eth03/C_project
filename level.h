//
// Created by ethan on 04/12/2023.
//

#ifndef PROJET_C_TEST_LEVEL_H
#define PROJET_C_TEST_LEVEL_H
#include "cellule.h"


typedef struct level_list
{
    cellule **head;
    int hauteur;
} level_list;

level_list * create_list(int h);
void insert_head(level_list *lst, cellule *cell);
void print_nvx(level_list *, int nvx);
void print_levels(level_list * lst);
void insert_croissant(level_list *lst, cellule *cell);
int search_lvl0(level_list *lst, int val);
int search_lvls(level_list *lst, int val);
void remplissage(int size, int* tab);
void super_remplissage(int* tab , int size);
long long int puissance(int base, int exposant);
level_list * init_list(int n);
void free_list (level_list *lst);

#endif //PROJET_C_TEST_LEVEL_H
