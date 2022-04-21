/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void move_down(game_t *game)
{
    if (game->scenes[GAME].elements[2]->pos.y > 680) {
            game->scenes[GAME].elements[0]->rect.top += 5;
    } else
        game->scenes[GAME].elements[2]->pos.y += 5;
}

void move_up(game_t *game)
{
    if (game->scenes[GAME].elements[2]->pos.y < 200) {
            game->scenes[GAME].elements[0]->rect.top -= 5;
    } else
        game->scenes[GAME].elements[2]->pos.y -= 5;
}

void move_left(game_t *game)
{
    if (game->scenes[GAME].elements[2]->pos.x < 200) {
            game->scenes[GAME].elements[0]->rect.left -= 5;
    } else
        game->scenes[GAME].elements[2]->pos.x -= 5;
}

void move_right(game_t *game)
{
    if (game->scenes[GAME].elements[2]->pos.x > 1520) {
            game->scenes[GAME].elements[0]->rect.left += 5;
    } else
        game->scenes[GAME].elements[2]->pos.x += 5;
}
