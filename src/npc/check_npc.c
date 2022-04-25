/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void check_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);

    if (npc != NULL) {
        draw_text(conc("Press '", conc(getkey(game->settings->key_action),
                "' to talk to the npc")), game->settings->font,
                (sfVector3f){50, 960, 70}, game->window);
        if (event->key.code == game->settings->key_action) {
            go_talk_npc(game);
        }
    }
}