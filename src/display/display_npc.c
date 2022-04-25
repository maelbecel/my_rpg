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
    sfVector2f tmp = {0, 0};

    if (pos.x > (0 - npc->elem->rect.width * npc->elem->scale.x) &&
        pos.y > (0 - npc->elem->rect.height * npc->elem->scale.y) &&
        pos.x < 1920 && pos.y < 1080) {
        tmp = npc->elem->pos;
        npc->elem->pos.x = pos.x * game->scenes[GAME].elements[0]->scale.x;
        npc->elem->pos.y = pos.y * game->scenes[GAME].elements[0]->scale.y;
        draw_element(game->window, npc->elem);
        npc->elem->pos = tmp;
    }
}

void display_npc(game_t *game)
{
    for (int i = 0; game->scenes[GAME].npc[i] != NULL; i++) {
        draw_npc(game, game->scenes[GAME].npc[i]);
    }
}

void display_talk_npc(game_t *game, sfEvent *event)
{
    display_game(game, event);
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEnter)
        go_game(game);
}
