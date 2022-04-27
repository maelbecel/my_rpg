/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void set_tab(scene_t *scenes)
{
    for (int i = 0; i < 14; i++)
        scenes[i].tab = (i != MENU_PLAYER) ? NULL : scenes[i].tab;
}