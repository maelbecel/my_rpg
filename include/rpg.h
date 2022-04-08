/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef RPG
    #define RPG

    #define UNUSED __attribute__((unused))
    #define BASIC_TEXT_SIZE 50
    #define BASIC_FONT "ressources/Fonts/game.ttf"
    #define MICRO 1000000

    ////////////////////////////////////////////////////////////
    // Headers
    ////////////////////////////////////////////////////////////
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
    #include "cinematique.h"
    #include "event.h"
    #include "display.h"
    #include "initialise.h"

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct type_button_s type_button_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct game_s game_t;
    typedef struct settings_s settings_t;
    typedef struct pos_perso_s pos_perso_t;

    ////////////////////////////////////////////////////////////
    /// \brief Enumerates all scenes.
    ///
    ////////////////////////////////////////////////////////////
    enum scenes {
        MAIN_MENU,
        GAME,
        SETTINGS,
        MENU_PLAYER,
        KEY,
        SOUNDS,
        HTP_1,
        HTP_2,
        HTP_3,
        PAUSE
    };

    ////////////////////////////////////////////////////////////
    /// \brief Element struct.
    ///
    /// Contain the texture, sprite, scale, rectangle, position
    /// and the max number of sprites.
    ///
    ////////////////////////////////////////////////////////////
    struct element_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfVector2f pos;
        int max_sprite;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Button aspect struct.
    ///
    /// Contain the texture, sprite, scale, rectangle, text, font, sound
    /// text position and the text size.
    ///
    ////////////////////////////////////////////////////////////
    struct type_button_s {
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfIntRect rect;
        sfText *text;
        sfFont *font;
        sfMusic *sound;
        sfVector2f text_pos;
        int text_size;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Button struct.
    ///
    /// Contain the base aspect, hoover aspect, clicked aspect, button position
    /// ,action when hoover, action when clicked, x and y.
    ///
    ////////////////////////////////////////////////////////////
    struct button_s {
        type_button_t *base;
        type_button_t *hoover;
        type_button_t *clicked;
        sfVector2f pos;
        void (*action_hoover)(game_t *game, ...);
        void (*action_clicked)(game_t *game, ...);
        int x;
        int y;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Scenes struct.
    ///
    /// Contain the list of buttons, the list of elements and the number of the
    /// actual page.
    ///
    ////////////////////////////////////////////////////////////
    struct scene_s {
        button_t **buttons;
        sfText *text;
        element_t **elements;
        int page;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Settings struct.
    ///
    /// Contain the music and FX volume, up, down, left, right, pause and menu
    /// keys.
    ///
    ////////////////////////////////////////////////////////////
    struct settings_s {
        int music_volume;
        int fx_volume;
        int key_up;
        int key_down;
        int key_left;
        int key_right;
        int key_pause;
        int key_menu;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Game struct.
    ///
    /// Contain the window, the list of scenes and the settings.
    ///
    ////////////////////////////////////////////////////////////
    struct game_s {
        sfRenderWindow *window;
        scene_t *scenes;
        settings_t *settings;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Key struct.
    ///
    /// Contain the key and the name of the key.
    ///
    ////////////////////////////////////////////////////////////
    struct key_s {
        int key;
        char *name;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Get arguments from a JSON file
    ///
    /// \param file Path to the JSON file
    /// \param var  Variable to search in the JSON file
    ///
    /// \return Value of the variable from the JSON file or NULL if not found.
    ///
    ////////////////////////////////////////////////////////////
    char *parser(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Update a JSON file
    ///
    /// \param file  Path to the JSON file
    /// \param var   Variable to search in the JSON file
    /// \param value Value to update in the JSON file
    ///
    ////////////////////////////////////////////////////////////
    void update_file(char *file, char *var, char *value);

#endif
