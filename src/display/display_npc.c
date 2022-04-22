/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static sfVector2f get_pos(game_t *game, npc_t *npc)
{
    sfVector2f pos = {
        (npc->elem->pos.x - game->scenes[GAME].elements[0]->rect.left),
        (npc->elem->pos.y - game->scenes[GAME].elements[0]->rect.top)};
    return pos;
}

void draw_npc(game_t *game, npc_t *npc)
{
    sfVector2f pos = get_pos(game, npc);
    if (pos.x > 0 && pos.y > 0)
        draw_element(game->window, npc->elem);
}

void display_npc(game_t *game)
{
    for (int i = 0; game->scenes[GAME].npc[i] != NULL; i++) {
        draw_npc(game, game->scenes[GAME].npc[i]);
    }
}