/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void treeman_exception(game_t *game, char *type)
{
    if (my_strcmp(type, "treeman") == 0) {
        game->enemy->elem->pos.x -= 50;
        game->enemy->elem->rect = (sfIntRect){0, 0, 150, 180};
        game->enemy->elem->scale = (sfVector2f){1.5, 1.5};
        sfSprite_setScale(game->enemy->elem->sprite,
                            game->enemy->elem->scale);
    } else if (my_strcmp(type, "boss") == 0) {
        game->enemy->elem->pos.x -= 350;
        game->enemy->elem->pos.y -= 80;
        game->enemy->elem->rect = (sfIntRect){0, 0, 400, 300};
        game->enemy->elem->scale = (sfVector2f){1.5, 1.5};
        sfSprite_setScale(game->enemy->elem->sprite,
                            game->enemy->elem->scale);
    }
}
