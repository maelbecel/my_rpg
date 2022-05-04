/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void *choose_tp(sfColor col)
{
    sfColor forest = TP_FOREST;
    sfColor village = TP_VILLAGE;
    sfColor village2 = TP_VILLAGE_2;
    void (*func)(game_t *game, ...) = NULL;

    if (col.r == forest.r && col.g == forest.g && col.b == forest.b)
        func = tp_forest;
    if (col.r == village.r && col.g == village.g && col.b == village.b)
        func = tp_village;
    if (col.r == village2.r && col.g == village2.g && col.b == village2.b)
        func = tp_village_from_dungeon;
    return (func);
}