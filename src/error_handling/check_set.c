/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int check_set(settings_t *set)
{
    if (set->key_down == -1 || set->key_up == -1 || set->key_left == -1 ||
                            set->key_right  == -1 || set->key_pause  == -1 ||
                            set->key_menu  == -1 || set->key_action  == -1 ||
                            set->key_skip  == -1 || set->music_volume  == -1 ||
                                                        set->fx_volume  == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
