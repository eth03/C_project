//
// Created by ethan on 04/12/2023.
//

#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>


cellule * create_cell(int val , int nb_max)
{
    cellule * cel = malloc  (sizeof(cellule));
    cel->next = malloc (nb_max * (sizeof(cellule **)));
    cel->value = val;
    cel->max_level = nb_max;
    for (int i = 0; i < nb_max; i++)
    {
        cel->next[i] = NULL;
    }
    return cel;
}

void free_cellule(cellule* pCellule) {
    free(pCellule);
}