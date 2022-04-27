/*
** EPITECH PROJECT, 2022
** display_key_with_pnj
** File description:
** display_key_with_pnj for rpg
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

char *getkey(int);

weather_t *init_weather()
{
    weather_t *weather = malloc(sizeof(weather_t));

    weather->count = 0;
    weather->i = 0;
    weather->pix = malloc(sizeof(sfColor) * (1920 * 1080));
    weather->sprite = sfSprite_create();
    weather->tex = sfTexture_create(1920, 1080);
    return weather;
}