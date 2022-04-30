/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef RPG
    #define RPG

    ////////////////////////////////////////////////////////////
    /// \def EXIT_ERROR 84
    ////////////////////////////////////////////////////////////
    #define EXIT_ERROR 84

    ////////////////////////////////////////////////////////////
    /// \def UNUSED __attribute__((unused))
    /// \param unused Unused variable
    ////////////////////////////////////////////////////////////
    #define UNUSED __attribute__((unused))

    ////////////////////////////////////////////////////////////
    /// \def Absolute value
    /// \param x Value to check
    ////////////////////////////////////////////////////////////
    #define ABS(x) ((x) < 0 ? -(x) : (x))

    ////////////////////////////////////////////////////////////
    /// \def BASIC_TEXT_SIZE 50
    ////////////////////////////////////////////////////////////
    #define BASIC_TEXT_SIZE 50

    ////////////////////////////////////////////////////////////
    /// \def FIGHT_WAIT
    ////////////////////////////////////////////////////////////
    #define FIGHT_WAIT 2

    ////////////////////////////////////////////////////////////
    /// \def CONFIG_FILE
    ////////////////////////////////////////////////////////////
    #define CONFIG_FILE "config/config.json"

    ////////////////////////////////////////////////////////////
    /// \def SETTINGS_FILE
    ////////////////////////////////////////////////////////////
    #define SETTINGS_FILE "config/settings.json"

    ////////////////////////////////////////////////////////////
    /// \def ARBALETIER
    ////////////////////////////////////////////////////////////
    #define ARBALETIER "config/arbaletier.json"

    ////////////////////////////////////////////////////////////
    /// \def ARCHERE
    ////////////////////////////////////////////////////////////
    #define ARCHERE "config/archere.json"

    ////////////////////////////////////////////////////////////
    /// \def CHEVALIE²²&²
    ////////////////////////////////////////////////////////////
    #define CHEVALIER "config/chevalier.json"

    ////////////////////////////////////////////////////////////
    /// \def CUISINIERE
    ////////////////////////////////////////////////////////////
    #define CUISINIERE "config/cuisiniere.json"

    ////////////////////////////////////////////////////////////
    /// \def MAGE
    ////////////////////////////////////////////////////////////
    #define MAGE "config/mage.json"

    ////////////////////////////////////////////////////////////
    /// \def VALKYRIE
    ////////////////////////////////////////////////////////////
    #define VALKYRIE "config/valkyrie.json"

    ////////////////////////////////////////////////////////////
    /// \def SAVE 1
    ////////////////////////////////////////////////////////////
    #define SAVE1 "saves/save1.json"

    ////////////////////////////////////////////////////////////
    /// \def SAVE 2
    ////////////////////////////////////////////////////////////
    #define SAVE2 "saves/save2.json"

    ////////////////////////////////////////////////////////////
    /// \def SAVE 3
    ////////////////////////////////////////////////////////////
    #define SAVE3 "saves/save3.json"

    ////////////////////////////////////////////////////////////
    /// \def BASIC_FONT "assets/fonts/zorque.ttf"
    ////////////////////////////////////////////////////////////
    #define BASIC_FONT "assets/fonts/zorque.ttf"

    ////////////////////////////////////////////////////////////
    /// \def BACKGROUND
    ////////////////////////////////////////////////////////////
    #define BACKGROUND "assets/ui/background.png"

    ////////////////////////////////////////////////////////////
    /// \def BUTTON
    ////////////////////////////////////////////////////////////
    #define BUTTON "assets/ui/button1.png"

    ////////////////////////////////////////////////////////////
    /// \def HITBOX
    ////////////////////////////////////////////////////////////
    #define HITBOX "assets/hitboxes/hitbox.png"

    ////////////////////////////////////////////////////////////
    /// \def BATTLE_BG
    ////////////////////////////////////////////////////////////
    #define BATTLE_BG "assets/battle_scene.jpg"

    ////////////////////////////////////////////////////////////
    /// \def MICRO 1000000
    ////////////////////////////////////////////////////////////
    #define MICRO 1000000

    ////////////////////////////////////////////////////////////
    /// \def NB_SCENES
    ////////////////////////////////////////////////////////////
    #define NB_SCENES 27

    ////////////////////////////////////////////////////////////
    /// \def BATTLE POSITION
    ////////////////////////////////////////////////////////////
    #define BATTLE_POS (sfVector2f){550, 570}

    ////////////////////////////////////////////////////////////
    /// \def ENEMY POSITION
    ////////////////////////////////////////////////////////////
    #define ENEMY_POS (sfVector2f){1250, 370}

    ////////////////////////////////////////////////////////////
    /// \def BATTLE SCALE
    ////////////////////////////////////////////////////////////
    #define BATTLE_SCALE (sfVector2f){4, 4}

    ////////////////////////////////////////////////////////////
    /// \def SPIDER
    ////////////////////////////////////////////////////////////
    #define SPIDER (sfColor){254, 31, 230, 255}

    ////////////////////////////////////////////////////////////
    /// \def SLIME
    ////////////////////////////////////////////////////////////
    #define SLIME (sfColor){31, 250, 254, 255}

    ////////////////////////////////////////////////////////////
    /// \def TP_VILLAGE
    ////////////////////////////////////////////////////////////
    #define TP_VILLAGE (sfColor){0, 0, 255, 255}

    ////////////////////////////////////////////////////////////
    /// \def TP_FOREST
    ////////////////////////////////////////////////////////////
    #define TP_FOREST (sfColor){0, 255, 0, 255}

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
    #include "player.h"
    #include "class.h"
    #include "error.h"
    #include "npc.h"

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
    /// \struct scene_s scene_t
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
        PAUSE,
        LOAD,
        CHOOSING,
        FRAME,
        NPC,
        BATTLE
    };

    ////////////////////////////////////////////////////////////
    /// \brief Element struct.
    ///
    /// Contain the texture, sprite, scale, rectangle, position
    /// and the max number of sprites.
    ///
    /// \struct element_s element_t
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
    /// \struct type_button_s type_button_t
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
    /// , action when hoover, action when clicked, x and y.
    ///
    /// \struct button_s button_t
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
    /// \struct scene_s scene_t
    ///
    ////////////////////////////////////////////////////////////
    struct scene_s {
        button_t **buttons;
        sfText *text;
        element_t **elements;
        scene_t *tab;
        npc_t **npc;
        int page;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Settings struct.
    ///
    /// Contain the music and FX volume, up, down, left, right, pause and menu
    /// keys.
    ///
    /// \struct settings_s settings_t
    ///
    ////////////////////////////////////////////////////////////
    struct settings_s {
        sfFont *font;
        int music_volume;
        int fx_volume;
        int key_up;
        int key_down;
        int key_left;
        int key_right;
        int key_pause;
        int key_menu;
        int key_skip;
        int key_action;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Game struct.
    ///
    /// Contain the window, the list of scenes and the settings.
    ///
    /// \struct game_s game_t
    ///
    ////////////////////////////////////////////////////////////
    struct game_s {
        sfRenderWindow *window;
        scene_t *scenes;
        settings_t *settings;
        player_t *player;
        sfImage *hitbox;
        enemy_t *enemy;
        bool is_inv;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Key struct.
    ///
    /// Contain the key and the name of the key.
    ///
    /// \struct key_s key_t
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

    ////////////////////////////////////////////////////////////
    /// \brief Display loading bar
    ///
    /// \param number  Scene to load
    /// \param window  Window where the loading bar should be display
    ///
    ////////////////////////////////////////////////////////////
    void loading(int number, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Get a double coat in a string
    ///
    /// \return Return a double coat
    ///
    ////////////////////////////////////////////////////////////
    char *coat(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get char * from a JSON file
    ///
    /// \param file Path to the JSON file
    /// \param var  Variable to search in the JSON file
    ///
    /// \return Value of the variable from the JSON file or NULL if not found.
    ///
    ////////////////////////////////////////////////////////////
    char *str_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get char ** from a JSON file
    ///
    /// \param file Path to the JSON file
    /// \param var  Variable to search in the JSON file
    ///
    /// \return Value of the variable from the JSON file or NULL if not found.
    ///
    ////////////////////////////////////////////////////////////
    char **str_array_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get int from a JSON file
    ///
    /// \param file Path to the JSON file
    /// \param var  Variable to search in the JSON file
    ///
    /// \return Value of the variable from the JSON file or -1 if not found.
    ///
    ////////////////////////////////////////////////////////////
    int int_from_json(char *file, char *var);

    ////////////////////////////////////////////////////////////
    /// \brief Get int * from a JSON file
    ///
    /// \param file Path to the JSON file
    /// \param var  Variable to search in the JSON file
    /// \param size Fill with size of the array
    ///
    /// \return Value of the variable from the JSON file or NULL if not found.
    ///
    ////////////////////////////////////////////////////////////
    int *int_array_from_json(char *file, char *var, int *size);

    ////////////////////////////////////////////////////////////
    /// \brief Clean a double coat at the start and end in a string
    ///
    /// \param str string to clean
    ///
    /// \return Return a str without coats
    ///
    ////////////////////////////////////////////////////////////
    char *clean_string(char *str);

    ////////////////////////////////////////////////////////////
    /// \brief Save inventory into a save file
    ///
    /// \param game game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void update_inventory(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Draw FPS from \a frame
    ///
    /// \param frame frame time actual
    /// \param game  game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void draw_fps(sfTime frame, game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Free all \a game
    ///
    /// \param game  game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void free_all(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Free all scenes from \a game
    ///
    /// \param game  game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void free_scenes(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Free all settings from \a game
    ///
    /// \param game  game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void free_settings(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Free all player from \a game
    ///
    /// \param game  game_t * element to save data
    ///
    ////////////////////////////////////////////////////////////
    void free_player(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Free an element
    ///
    /// \param elements  elements to free
    ///
    ////////////////////////////////////////////////////////////
    void free_elements(element_t *elements);

    ////////////////////////////////////////////////////////////
    /// \brief Free a button type
    ///
    /// \param type  button type to free
    ///
    ////////////////////////////////////////////////////////////
    void free_type(type_button_t *type);

    ////////////////////////////////////////////////////////////
    /// \brief Free a button
    ///
    /// \param type  button to free
    ///
    ////////////////////////////////////////////////////////////
    void free_button(button_t *button);

    ////////////////////////////////////////////////////////////
    /// \brief Get a random int
    ///
    /// \return random number
    ///
    ////////////////////////////////////////////////////////////
    int my_random(void);

    ////////////////////////////////////////////////////////////
    /// \brief Check for enemy
    ///
    /// \param game game_t *struct with all data
    ///
    /// \return Return -1 if there is an enemy, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int check_enemy(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Check if values settings are equal to -1
    ///
    /// \param set settings struct with values
    ///
    /// \return Return 1 if have a problem, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int check_set(settings_t *set);

    ////////////////////////////////////////////////////////////
    /// \brief Write a string in the error output
    ///
    /// \param str string to write
    ///
    /// \return 1
    ///
    ////////////////////////////////////////////////////////////
    int my_put_error(char const *str);

#endif
