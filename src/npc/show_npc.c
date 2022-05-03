/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int getposition(int x)
{
    switch (x) {
        case 0:
            return (3);
        case 1:
            return (2);
        case 2:
            return (1);
        case 3:
            return (0);
    }
    return x;
}

void show_npc(game_t *game, npc_t *npc, sfEvent *event)
{
    int pos;

    if (event->key.code == game->settings->key_action) {
        give_quest(game, npc);
        pos = getposition(npc->elem->rect.top / npc->elem->rect.height);
        game->scenes[GAME].elements[2]->rect.top = pos *
                        game->scenes[GAME].elements[2]->rect.height;
        sfSprite_setTextureRect(game->scenes[GAME].elements[2]->sprite,
                                game->scenes[GAME].elements[2]->rect);
        go_talk_npc(game);
    }
}
