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
    int dist = 0;
    sfVector2f playerpos = {game->scenes[GAME].elements[0]->rect.left +
                                    game->scenes[GAME].elements[2]->pos.x,
                            game->scenes[GAME].elements[0]->rect.top +
                                    game->scenes[GAME].elements[2]->pos.y};
    npc_t **npc = game->scenes[GAME].npc;
    sfVector2f npcpos;

    for (int i = 0; npc[i]; i++)
    {
        npcpos = npc[i]->elem->pos;
        dist = sqrt(((npcpos.x - playerpos.x) * (npcpos.x - playerpos.x)) +
                    ((npcpos.y - playerpos.y) * (npcpos.y - playerpos.y)));
        if (dist < 100) {
            // draw_text(conc(npc[i]->name, conc(" :\n", npc[i]->text)),
            //     game->settings->font, (sfVector3f){50, 900, 80}, game->window);
            draw_text("Press 'T' to talk to the npc", game->settings->font,
                    (sfVector3f){200, 800, 70}, game->window);
            sfRenderWindow_pollEvent(game->window, event);
            if (event->key.code == sfKeyT) {
                go_talk_npc(game);
            }
            return;
        }
    }
}