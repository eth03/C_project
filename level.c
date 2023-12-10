//
// Created by ethan on 04/12/2023.
//

#include "level.h"
#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include <math.h>
#include <limits.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

level_list * create_list(int h)
{
    level_list * lst = malloc(sizeof (level_list));
    lst->head = malloc(h * sizeof (cellule **));
    lst->hauteur = h;
    for (int i = 0; i < lst->hauteur; i++)
    {
        lst->head[i] = NULL;
    }
    return lst;
}

void insert_head(level_list *lst, cellule *cell)
{
    for (int i = 0; i < cell->max_level; i ++)
    {
        if (lst->head[0] == NULL)
        {
            lst->head[0] = cell;
            //printf("1 inserted %d at %d -> %p\n", cell->value, i, &lst->head[0]);
        }
        else
        {
            if (lst->head[i] == NULL)
            {
                lst->head[i] = cell;
                //printf("2 inserted %d ar %d -> %p\n", cell->value, i, &lst->head[i]);
            } else {
                cell->next[i] = lst->head[i];
                lst->head[i] = cell;
                //printf("3 inserted %d at %d, -> %p\n", cell->value, i, &cell->next[i]);
            }
        }
    }
}

void print_nvx(level_list * lst, int nvx)
{
    int i = 0;
    if(lst->head[nvx] == NULL)
    {
        printf("invalid level");
        return;
    }
    else
    {
        cellule * current = lst->head[nvx];
        while(current != NULL) //il peut y avoir un décallage, donc un bug
        {
            printf("[%d @-]--> ", current->value);
            current = current->next[nvx];
        }
    }
}


void print_levels(level_list * lst)
{
    if (lst == NULL)
    {
        printf("invalid list \n");
        return;
    }
    else
    {
        for (int i = 0; i < lst->hauteur; i++)
        {
            printf ("head_%d ", i);
            print_nvx(lst, i);
            printf("NULL \n");
        }
    }
}



void insert_croissant(level_list *lst, cellule *cell)
{
    for (int i = 0; i < cell->max_level; i ++)
    {
        // Première vide
        if (lst->head[0] == NULL)
        {
            lst->head[0] = cell;
            //printf("1 inserted %d at %d -> %p\n", cell->value, i, &lst->head[0]);
        }
        else
        {
            // plus petit, on ajoute en tête
            if (lst->head[i] != NULL)
            {
                if (cell->value < lst->head[i]->value)
                {
                    cell->next[i] = lst->head[i];
                    lst->head[i] = cell;
                    //printf("2 inserted %d ar %d -> %p\n", cell->value, i, &lst->head[i]);
                }
                else
                {
                    cellule * current = lst->head[i];
                    do
                    {
                        if (cell->value < current->next[i]->value)
                        {
                            cell->next[i] = current->next[i];
                            current = cell;
                            break;
                        }
                    } while (current->next[i] != NULL);
                }
            } else {
                lst->head[i] = cell;
            }
        }

    }
}


long long int puissance(int base, int exposant) {
    long long int resultat = 1;

    for (int i = 0; i < exposant; i++) {
        resultat *= base;
    }

    return resultat;
}



void remplissage(int size, int* tab)
{
    int i = 2;
    do {
        for (int j = i-1; j < size; j += i) {
            tab[j] += 1;
        }
        for (int k = 0; k < size; k++)
            printf("%d " , tab[k]);
        printf ("\n");
        i = 2 * i;
    } while (i < size);
}

void super_remplissage(int* tab , int size)
{

    remplissage(size, tab);
    //int k;
    /*
    for (k = 0; k < size ; k++)
    {
        //printf("%d " , tab[k]);
    }
    //val += 2;
    */
}


level_list * init_list(int n)
{
    level_list * lst = create_list(n);
    unsigned int max_size = pow(2, n) - 1; //nombre d'éléments dans un tableau (2^n - 1)
    max_size = min(max_size, INT_MAX); //on ne peut pas dépasser la taille d'un entier
    int *tab = (int*) calloc(max_size, sizeof(int));
    super_remplissage(tab, max_size);
    for (int i = max_size ; i > 0; i--)
    {
        cellule *cell = create_cell(i, tab[i] + 1);
        insert_head(lst, cell);
    }
    return lst;
}



int search_lvl0(level_list *lst, int val)
{
    if (lst == NULL)
    {
        return 0;
    }
    cellule * current = lst->head[0];
    while (current != NULL)
    {
        if (current->value == val)
        {
            printf("la valeur est presente \n");
            return 1;
        }
        current = current->next[0];
    }
    printf("la valeur n'est pas presente \n");
    return 0;
}

int search_lvls(level_list *lst, int val)
{
    if (lst == NULL)
    {
        return 0;
    }
    //on peut essayer de le faire de manière récursive
    for(int i = lst->hauteur - 1; i >= 0; i--)  //car on part du level_max
    {
        cellule * current = lst->head[i];
        while (current != NULL)
        {
            if(current->value == val)
            {
                printf("la valeur est presente \n");
                return i;
            }
            current = current->next[i];
        }
    }
    printf("la valeur n'est pas presente \n");
    return 0;
}

void free_list (level_list *lst)
{
    for(int i = 0; i < lst->hauteur; i++)
    {
        cellule * current = lst->head[i];
        while(current != NULL)
        {
            free_cellule(current);
            current = current->next[i];
        }
    }
}

