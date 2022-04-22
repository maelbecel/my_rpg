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
    npc_t **npc = malloc(sizeof(npc_t *) * (2 + 1));

    npc[0] = create_npc("bob");
    npc[1] = create_npc("erwann");
    npc[2] = NULL;
    return npc;
}