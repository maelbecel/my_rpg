/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static bool is_hitbox(game_t *game, sfVector2f move)
{
    float x = (game->scenes[GAME].elements[2]->pos.x + move.x +
                        (float)game->scenes[GAME].elements[0]->rect.left + 30);
    float y = (game->scenes[GAME].elements[2]->pos.y + move.y +
                        (float)game->scenes[GAME].elements[0]->rect.top + 90);
    sfColor col = sfImage_getPixel(game->hitbox, x, y);

    if (col.r == 255 && !col.g && !col.b && col.a == 255)
        return true;
    return false;
}

void move_down(game_t *game)
{
    if (is_hitbox(game, (sfVector2f){0, 8}) ||
        teleportation(game, (sfVector2f){0, 8}))
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
    if (is_hitbox(game, (sfVector2f){0, -8})  ||
        teleportation(game, (sfVector2f){0, -8}))
        return;
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
    if (is_hitbox(game, (sfVector2f){-8, 0})  ||
        teleportation(game, (sfVector2f){-8, 0}))
        return;
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
    if (is_hitbox(game, (sfVector2f){8, 0})  ||
        teleportation(game, (sfVector2f){8, 0}))
        return;
    if (game->scenes[GAME].elements[0]->rect.left >= 1900 &&
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
