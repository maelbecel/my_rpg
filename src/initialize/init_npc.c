/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void go_talk_npc(game_t *game)
{
    game->scenes->page = NPC;
}

void go_game(game_t *game)
{
    game->scenes->page = GAME;
}

void init_talk_npc(scene_t *scenes)
{
    scenes[NPC].elements = npc_elements();
    scenes[NPC].buttons = npc_buttons();
}

npc_t **game_npc(void)
{
    npc_t **npc = malloc(sizeof(npc_t *) * (6 + 1));

    npc[0] = create_npc("merlin");
    npc[1] = create_npc("erwann");
    npc[2] = create_npc("marine_lepen");
    npc[3] = create_npc("pascal");
    npc[4] = create_npc("patrick");
    npc[5] = create_npc("karim");
    npc[6] = NULL;
    return npc;
}
