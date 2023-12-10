#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "level.h"

void exo1() {
    level_list *lst1 = create_list (5);

    cellule *cell1 = create_cell(91, 3);
    cellule *cell2 = create_cell(59, 1);
    cellule *cell3 = create_cell(59, 5);
    cellule *cell4 = create_cell(56, 3);
    cellule *cell5 = create_cell(32, 5);
    cellule *cell6 = create_cell(31, 2);
    cellule *cell7 = create_cell(25, 1);
    cellule *cell8 = create_cell(18, 4);
    insert_head (lst1, cell1);
    insert_head (lst1, cell2);
    insert_head (lst1, cell3);
    insert_head (lst1, cell4);
    insert_head (lst1, cell5);
    insert_head (lst1, cell6);
    insert_head (lst1, cell7);
    insert_head (lst1, cell8);

    print_levels(lst1);
}

void exo2() {
    level_list *lst1 = create_list (5);

    cellule *cell1 = create_cell(91, 3);
    cellule *cell2 = create_cell(59, 1);
    cellule *cell3 = create_cell(59, 5);
    cellule *cell4 = create_cell(56, 3);
    cellule *cell5 = create_cell(32, 5);
    cellule *cell6 = create_cell(31, 2);
    cellule *cell7 = create_cell(25, 1);
    cellule *cell8 = create_cell(18, 4);
    insert_croissant (lst1, cell1);
    insert_croissant (lst1, cell2);
    insert_croissant (lst1, cell3);
    insert_croissant (lst1, cell4);
    insert_croissant (lst1, cell5);
    insert_croissant (lst1, cell6);
    insert_croissant (lst1, cell7);
    insert_croissant (lst1, cell8);

    print_levels(lst1);
}

void exo3(){
    level_list *lst1 = init_list(3);
    print_levels(lst1);
    int x = search_lvl0(lst1, 3);
    int y = search_lvls (lst1, 4);
}


int main() {

    //exo1();

    //exo2();

    exo3();
    return 0;
}
