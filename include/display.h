/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef DISPLAY
    #define DISPLAY
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
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct settings_s settings_t;

    void draw_button(sfRenderWindow *window, button_t *button);
    void draw_hoover(sfRenderWindow *window, button_t *button);
    void draw_clicked(sfRenderWindow *window, button_t *button);
    void draw_element(sfRenderWindow *window, element_t *element);
    void draw_text(char *text, int size, sfVector2f pos, sfRenderWindow *window);

    void display_settings(game_t *game, sfEvent *event);
    void display_settings_sounds(game_t *game, sfEvent *event);
    void display_settings_key(game_t *game, sfEvent *event);
    void display_htp_first(game_t *game, sfEvent *event);
    void display_htp_second(game_t *game, sfEvent *event);
    void display_htp_third(game_t *game, sfEvent *event);

    void display(game_t *game, sfEvent *event);
    void concat_settings(game_t *game);

#endif
