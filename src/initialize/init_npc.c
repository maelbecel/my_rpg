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
    npc_t **npc = malloc(sizeof(npc_t *) * (1 + 1));

    npc[0] = create_npc("bob");
    npc[1] = NULL;
    return npc;
}