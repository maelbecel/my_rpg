/*
** EPITECH PROJECT, 2022
** display_key_with_pnj
** File description:
** display_key_with_pnj for rpg
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

char *getkey(int);

void display_key_with_pnj(game_t *game)
{
    if ((game->scenes[GAME].elements[2]->pos.x - 900) <
        game->scenes[GAME].elements[1]->rect.left)
        draw_text(conc("CLICK ON : ", getkey(game->settings->key_menu)),
            game->settings->font, (sfVector3f){860, 940, 30}, game->window);
}
