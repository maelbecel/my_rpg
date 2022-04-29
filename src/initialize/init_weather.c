/*
** EPITECH PROJECT, 2022
** init_weather
** File description:
** init_weather for rpg
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

weather_t *init_weather()
{
    weather_t *weather = malloc(sizeof(weather_t));

    weather->count = 0;
    weather->i = 0;
    weather->pix = malloc(sizeof(sfColor) * (1920 * 2160) * 2);
    weather->sprite = sfSprite_create();
    weather->tex = sfTexture_create(1920, 2160);
    weather->clock = sfClock_create();
    weather->rand_weather = 0;
    weather->timer = 0;
    return weather;
}