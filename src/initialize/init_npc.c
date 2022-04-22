/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

npc_t **game_npc(void)
{
    npc_t **npc = malloc(sizeof(npc_t *) * (5 + 1));

    npc[0] = create_npc("bob");
    npc[1] = create_npc("erwann");
    npc[2] = create_npc("marine_lepen");
    npc[3] = create_npc("pascal");
    npc[4] = create_npc("patrick");
    npc[5] = NULL;
    return npc;
}