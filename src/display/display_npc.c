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

static sfVector2f init_vect(game_t *game)
{
   sfVector2f pos = {game->scenes[GAME].elements[0]->rect.left +
                            game->scenes[GAME].elements[2]->rect.width / 2 +
                            game->scenes[GAME].elements[2]->pos.x,
                            game->scenes[GAME].elements[0]->rect.top +
                            game->scenes[GAME].elements[2]->rect.height / 2 +
                            game->scenes[GAME].elements[2]->pos.y};
    return pos;
}

npc_t *find_npc(game_t *game)
{
    int dist = 0;
    sfVector2f playerpos = init_vect(game);
    npc_t **npc = game->scenes[GAME].npc;
    sfVector2f npcpos;

    for (int i = 0; npc[i]; i++)
    {
        npcpos = npc[i]->elem->pos;
        dist = sqrt(((npcpos.x - playerpos.x) * (npcpos.x - playerpos.x)) +
                    ((npcpos.y - playerpos.y) * (npcpos.y - playerpos.y)));
        if (dist < 100 && npc[i]->map == game->player->map) {
            move_npc(game, npcpos, playerpos, i);
            return npc[i];
        } else
        game->scenes[GAME].npc[i]->elem->rect.top = 0;
    }
    return NULL;
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
        if (game->scenes[GAME].npc[i]->map == game->player->map)
            draw_npc(game, game->scenes[GAME].npc[i]);
    }
    draw_element(game->window, game->scenes[GAME].elements[6]);
    draw_element(game->window, game->scenes[GAME].elements[2]);
    draw_element(game->window, game->scenes[GAME].elements[5]);
}
