/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef RPG
    #define RPG
    #include <stdbool.h>
    #include <stddef.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    #define UNUSED __attribute__((unused))

    int analyse_event(sfRenderWindow *window, sfEvent *event);

#endif
