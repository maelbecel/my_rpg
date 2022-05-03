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
    music_t *music = malloc(sizeof(music_t));

    music[1].sound = sfMusic_createFromFile("assets/sounds/battle.ogg");
    return music;
}