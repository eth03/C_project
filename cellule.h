//
// Created by ethan on 04/12/2023.
//

#ifndef PROJET_C_TEST_CELLULE_H
#define PROJET_C_TEST_CELLULE_H


typedef struct cellule
{
    int value;
    int max_level;
    struct cellule **next;
} cellule;

cellule * create_cell(int x, int y);
void free_cellule(cellule* pCellule);

#endif //PROJET_C_TEST_CELLULE_H
