/*
** EPITECH PROJECT, 2022
** weather
** File description:
** weather for rpg
*/

#include "rpg.h"

void random_rain(weather_t *weather)
{
    size_t ran_drop;

    for (size_t i = 0; i != (1920 * 1580); i++)
        weather->pix[i] = sfTransparent;
    for (;weather->count <= (1920 * 1580); weather->count += 1482) {
        ran_drop = my_random() % 14 + 6;
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
        weather->next_start += 1920;
        weather->count = weather->next_start;
    } if (weather->next_start >= (1920 * 124 * 2))
        weather->next_start = 0;
    if (fmodf(weather->timer, 2) == 0)
        random_rain(weather);
    sfTexture_updateFromPixels(weather->tex, (sfUint8*)weather->pix,
                                                            1920, 1580, 0, 0);
    sfSprite_setTexture(weather->sprite, weather->tex, sfTrue);
    sfSprite_setPosition(weather->sprite, (sfVector2f){0, -500});
    sfRenderWindow_drawSprite(game->window, weather->sprite, NULL);
}

void weather(game_t *game, weather_t *weather)
{
    int speed = int_from_json(CONFIG_FILE, "weather_speed");
    weather->time = sfClock_getElapsedTime(weather->clock);
    weather->seconds = weather->time.microseconds / 1000000.0;
    if (weather->seconds > 0.03) {
        weather->timer++;
        sfClock_restart(weather->clock);
    } if (fmodf(weather->timer, speed) == 0)
        weather->rand_weather = my_random() % 5;
    if (weather->rand_weather == 1)
        rain(game, weather);
    if (weather->rand_weather == 2)
        snow(game, game->weather);
    if (weather->timer == 2000)
        weather->timer = 0;

}
