/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** init_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int go_talk_npc(game_t *game)
{
    game->scenes->page = NPC;
    return EXIT_SUCCESS;
}

int go_game(game_t *game, ...)
{
    if (game->music[0].sound)
        sfMusic_stop(game->music[0].sound);
    sfMusic_play(game->music[1].sound);
    game->scenes->page = GAME;
    return EXIT_SUCCESS;
}

int init_talk_npc(scene_t *scenes)
{
    if (!(scenes[NPC].elements = npc_elements()))
        return EXIT_FAILURE;
    if (!(scenes[NPC].buttons = npc_buttons()))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

npc_t **game_npc(void)
{
    npc_t **npc = malloc(sizeof(npc_t *) * (6 + 1));

    if (!npc)
        return NULL;
    if (!(npc[0] = create_npc("merlin")))
        return NULL;
    if (!(npc[1] = create_npc("erwann")))
        return NULL;
    if (!(npc[2] = create_npc("marine")))
        return NULL;
    if (!(npc[3] = create_npc("pascal")))
        return NULL;
    if (!(npc[4] = create_npc("patrick")))
        return NULL;
    if (!(npc[5] = create_npc("karim")))
        return NULL;
    npc[6] = NULL;
    return npc;
}
