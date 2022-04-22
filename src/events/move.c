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
    if (game->scenes[GAME].elements[0]->rect.top >= 2000 &&
        game->scenes[GAME].elements[2]->pos.y > 660)
        return;
    game->scenes[GAME].elements[2]->rect.top = 0;
    if (game->scenes[GAME].elements[2]->pos.y > 680) {
        game->scenes[GAME].elements[0]->rect.top += 8;
    } else {
        game->scenes[GAME].elements[2]->pos.y += 8;
    }
    if (game->scenes[GAME].elements[2]->rect.left < 32 * 3)
        game->scenes[GAME].elements[2]->rect.left += 32;
    else
        game->scenes[GAME].elements[2]->rect.left = 0;
}

void move_up(game_t *game)
{
    if (game->scenes[GAME].elements[0]->rect.top <= 0 &&
        game->scenes[GAME].elements[2]->pos.y < 220)
        return;
    game->scenes[GAME].elements[2]->rect.top = 144;
    if (game->scenes[GAME].elements[2]->pos.y < 200) {
        game->scenes[GAME].elements[0]->rect.top -= 8;
    } else {
        game->scenes[GAME].elements[2]->pos.y -= 8;
    }
    if (game->scenes[GAME].elements[2]->rect.left < 32 * 3)
        game->scenes[GAME].elements[2]->rect.left += 32;
    else
        game->scenes[GAME].elements[2]->rect.left = 0;
}

void move_left(game_t *game)
{
    if (game->scenes[GAME].elements[0]->rect.left <= 0 &&
        game->scenes[GAME].elements[2]->pos.x < 220)
        return;
    game->scenes[GAME].elements[2]->rect.top = 48;
    if (game->scenes[GAME].elements[2]->pos.x < 200) {
        game->scenes[GAME].elements[0]->rect.left -= 8;
    } else {
        game->scenes[GAME].elements[2]->pos.x -= 8;
    }
    if (game->scenes[GAME].elements[2]->rect.left < 32 * 3)
        game->scenes[GAME].elements[2]->rect.left += 32;
    else
        game->scenes[GAME].elements[2]->rect.left = 0;
}

void move_right(game_t *game)
{
    if (game->scenes[GAME].elements[0]->rect.left >= 2000 &&
        game->scenes[GAME].elements[2]->pos.y > 1500)
        return;
    game->scenes[GAME].elements[2]->rect.top = 96;
    if (game->scenes[GAME].elements[2]->pos.x > 1520) {
        game->scenes[GAME].elements[0]->rect.left += 8;
    } else {
        game->scenes[GAME].elements[2]->pos.x += 8;
    }
    if (game->scenes[GAME].elements[2]->rect.left < 32 * 3)
        game->scenes[GAME].elements[2]->rect.left += 32;
    else
        game->scenes[GAME].elements[2]->rect.left = 0;
}
