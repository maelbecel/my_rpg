/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void update_hitbox(game_t *game)
{
    if (game->scenes[GAME].elements[6] == NULL ||
        game->scenes[GAME].elements[5] == NULL)
        return;
    game->scenes[GAME].elements[5]->rect =
                                    game->scenes[GAME].elements[0]->rect;
    game->scenes[GAME].elements[6]->rect =
                                    game->scenes[GAME].elements[0]->rect;
    sfSprite_setTextureRect(game->scenes[GAME].elements[6]->sprite,
                            game->scenes[GAME].elements[6]->rect);
    sfSprite_setTextureRect(game->scenes[GAME].elements[5]->sprite,
                            game->scenes[GAME].elements[5]->rect);
    sfSprite_setTextureRect(game->scenes[GAME].elements[0]->sprite,
                            game->scenes[GAME].elements[0]->rect);
    sfClock_restart(game->player->timer);
}