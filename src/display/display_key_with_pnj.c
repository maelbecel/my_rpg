/*
** EPITECH PROJECT, 2022
** display_key_with_pnj
** File description:
** display_key_with_pnj for rpg
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_key_with_pnj(game_t *game)
{
    draw_text("CLICK ON : ", 30, (sfVector2f){400, 500}, game->window);
}