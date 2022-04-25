/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_merchant(UNUSED npc_t *npc)
{

}

void display_non_merchant(game_t *game, npc_t *npc)
{
    draw_text(conc(npc->name, ":"), game->settings->font,
                    (sfVector3f){50, 760, 70}, game->window);
    draw_text(npc->text, game->settings->font,
                    (sfVector3f){50, 860, 70}, game->window);
}

void display_talk_npc(game_t *game, sfEvent *event)
{
    npc_t *npc = find_npc(game);

    for (int e = 0; game->scenes[GAME].elements[e]; e++)
        draw_element(game->window, game->scenes[GAME].elements[e]);
    display_npc(game);
    if (npc->merchant == true)
        display_merchant(npc);
    else
        display_non_merchant(game, npc);
    draw_text("Press 'Enter' to skip the talk", game->settings->font,
                    (sfVector3f){50, 960, 70}, game->window);
    if (event->key.code == sfKeyEnter)
        go_game(game);
}