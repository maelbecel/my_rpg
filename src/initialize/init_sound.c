/*
** EPITECH PROJECT, 2022
** init_sound
** File description:
** init_sound for rpg
*/

#include "my.h"
#include "rpg.h"

music_t *init_sound(void)
{
    music_t *music = malloc(sizeof(music_t) * 2);

    if (!(music[0].sound = sfMusic_createFromFile("assets/sounds/battle.ogg")))
        return NULL;
    if (!(music[1].sound =
    sfMusic_createFromFile("assets/sounds/main_menu.ogg")))
        return NULL;
    return music;
}