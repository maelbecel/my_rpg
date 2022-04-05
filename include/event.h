/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef EVENT
    #define EVENT
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdarg.h>
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>

    typedef struct game_s game_t;

    int is_hoover(game_t *game, int b, int s);
    int is_click(game_t *game, int b, int s);

    int analyse_event(game_t *game, sfEvent *event);
    void analyse_game(game_t *game, sfEvent *event);

    void clicked(game_t *game, ...);
    void hoover(game_t *game, ...);
    void do_none(game_t *game, ...);
    void quit(game_t *game, ...);
    void play(game_t *game, ...);
    void main_menu(game_t *game, ...);
    void settings(game_t *game, ...);
    void settings_sounds(game_t *game, ...);
    void settings_key(game_t *game, ...);

    void wait_up(game_t *game, ...);
    void wait_down(game_t *game, ...);
    void wait_right(game_t *game, ...);
    void wait_left(game_t *game, ...);
    void wait_pause(game_t *game, ...);
    void wait_menu(game_t *game, ...);

    int menu_event(game_t *game);

#endif