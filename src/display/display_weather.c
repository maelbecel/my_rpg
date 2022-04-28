/*
** EPITECH PROJECT, 2022
** weather
** File description:
** weather for rpg
*/

#include "rpg.h"

void random_rain(weather_t *weather)
{
    size_t ran_num = rand() % 3 + 1480;
    size_t ran_drop;
    for (size_t i = 0; i != (1920 * 1180); i++)
        weather->pix[i] = sfTransparent;
    for (;weather->count <= (1920 * 1180); weather->count += ran_num) {
        ran_drop = rand() % 14 + 6;
        for (size_t i = 0; i != ran_drop; i++) {
            weather->pix[weather->count + (1920 * i)] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 1] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 2] = sfBlue;
            weather->pix[weather->count + (1920 * i) + 3] = sfBlue;
        }
    }
}

void weather(game_t *game, weather_t *weather)
{
    if (weather->count >= (1920 * 1080)) {
        weather->i += 1920;
        weather->count = weather->i;
    }
    if (weather->i >= (1920 * 72))
        weather->i = 0;
    random_rain(weather);
    sfTexture_updateFromPixels(weather->tex, (sfUint8*)weather->pix,
    1920, 1180, 0, 0);
    sfSprite_setTexture(weather->sprite, weather->tex, sfTrue);
    sfSprite_setPosition(weather->sprite, (sfVector2f){0, -100});
    sfRenderWindow_drawSprite(game->window, weather->sprite, NULL);
}
