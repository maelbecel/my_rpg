/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int display_talk_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);

    for (int e = 0; game->scenes[GAME].elements[e]; e++)
        draw_element(game->window, game->scenes[GAME].elements[e]);
    display_npc(game);
    if (npc->merchant == true) {
        display_merchant(game, npc, event);
    }
    draw_dialogue_box(game->window, format("%s:\n%s", npc->name, npc->text),
                                                        game->settings->font);
    draw_pop_text(format("PRESS %s to leave",
        getkey(game->settings->key_skip)), game->settings->font, game->window);
    if (event->key.code == game->settings->key_skip)
        go_game(game);
    return EXIT_SUCCESS;
}
