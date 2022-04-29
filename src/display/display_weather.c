/*
** EPITECH PROJECT, 2022
** weather
** File description:
** weather for rpg
*/

#include "rpg.h"

void random_rain(weather_t *weather)
{
    size_t ran_num = rand() % 2 + 1480;
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

void rain(game_t *game, weather_t *weather)
{
    if (weather->count >= (1920 * 1080)) {
        weather->i += 1920;
        weather->count = weather->i;
    }
    if (weather->i >= (1920 * 72))
        weather->i = 0;
    if (fmodf(weather->timer, 2) == 0)
        random_rain(weather);
    sfTexture_updateFromPixels(weather->tex, (sfUint8*)weather->pix,
    1920, 1180, 0, 0);
    sfSprite_setTexture(weather->sprite, weather->tex, sfTrue);
    sfSprite_setPosition(weather->sprite, (sfVector2f){0, -100});
    sfRenderWindow_drawSprite(game->window, weather->sprite, NULL);
}

void weather(game_t *game, weather_t *weather)
{
    weather->time = sfClock_getElapsedTime(weather->clock);
    weather->seconds = weather->time.microseconds / 1000000.0;
    printf("%f\n", weather->seconds);
    if (weather->seconds > 0.03) {
        weather->timer++;
        sfClock_restart(weather->clock);
    }
    if (fmodf(weather->timer, 10000) == 0)
        weather->rand_weather = rand() % 3;
    if (weather->rand_weather == 1)
        rain(game, weather);

}
