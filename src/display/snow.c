/*
** EPITECH PROJECT, 2022
** snow
** File description:
** snow gor rpg
*/

#include "my.h"
#include "rpg.h"

void random_snow(weather_t *weather)
{
    size_t ran_drop;
    for (size_t i = 0; i != (1920 * 1180); i++)
        weather->pix[i] = sfTransparent;
    for (;weather->count <= (1920 * 1180); weather->count += 1482) {
        ran_drop = rand() % 14 + 6;
        for (size_t i = 0; i != ran_drop; i++) {
            weather->pix[weather->count + (1920 * i)] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 1] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 2] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 3] = sfBlue;
        }
    }
}

void snow(game_t *game, weather_t *weather)
{
    if (weather->count >= (1920 * 1080)) {
        weather->next_start += 1920;
        weather->count = weather->next_start;
    }
    if (weather->next_start >= (1920 * 114))
        weather->next_start = 0;
    if (fmodf(weather->timer, 20) == 0)
        random_snow(weather);
    sfTexture_updateFromPixels(weather->tex, (sfUint8*)weather->pix,
    1920, 1180, 0, 0);
    sfSprite_setTexture(weather->sprite, weather->tex, sfTrue);
    sfSprite_setPosition(weather->sprite, (sfVector2f){0, -100});
    sfRenderWindow_drawSprite(game->window, weather->sprite, NULL);
}