/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef INIT
    #define INIT

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

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct game_s game_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct settings_s settings_t;
    typedef struct type_button_s type_button_t;

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the main menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **main_menu_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the main menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **main_menu_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the game
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **game_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the game
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **game_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the settings menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the settings menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the player menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **menu_player_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the player menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **menu_player_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the key settings  menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_key_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the key settings menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_key_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the sounds settings menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_sounds_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the sounds settings menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_sounds_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the first page of how to play
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_first_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the first page of how to play
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_first_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the second page of how to play
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_second_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the second page of how to play
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_second_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the third page of how to play
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_third_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the third page of how to play
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_third_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the pause menu
    ///
    /// \return struct button_t** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **pause_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the pause menu
    ///
    /// \return struct element_t** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **pause_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get all scenes with elements and buttons
    ///
    /// \return struct scene_t* with all elements and buttons for all scenes
    ///
    ////////////////////////////////////////////////////////////
    scene_t *init_scenes(void);

    ////////////////////////////////////////////////////////////
    /// \brief Create an element from a file
    ///
    /// \param texture Path to the texture
    /// \param pos     sfVector2f struct with the position of the element
    /// \param size    sfVector2f struct with the size of the element
    /// \param scale   sfVector2f struct with the scale of the element
    ///
    /// \return struct element_t* with the element
    ///
    ////////////////////////////////////////////////////////////
    element_t *init_element(char *texture, sfVector2f pos,
                        sfVector2f size, sfVector2f scale);

    ////////////////////////////////////////////////////////////
    /// \brief Create a button from a file and a text
    ///
    /// \param text    Text of the button
    /// \param texture Path to the texture
    /// \param pos     sfVector2f struct with the position of the element
    /// \param size    sfVector2f struct with the size of the element
    ///
    /// \return struct button_t* with the button
    ///
    ////////////////////////////////////////////////////////////
    button_t *init_button(char *text, char *texture,
                        sfVector2f pos, sfVector2i size);

    ////////////////////////////////////////////////////////////
    /// \brief Create a button aspect from a file and a text
    ///
    /// \param text    Text of the button
    /// \param texture Path to the texture
    /// \param size    sfVector2f struct with the size of the element
    ///
    /// \return struct type_button_t* with the button aspect
    ///
    ////////////////////////////////////////////////////////////
    type_button_t *init_button_type(char *text, char *texture,
                                    sfVector2i size);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize all basic settings,
    ///
    /// basic settings are arrow movement, 'escape' for pause and
    /// 'p' for player menu.
    ///
    /// \return struct settings_t* with the base settings
    ///
    ////////////////////////////////////////////////////////////
    settings_t *init_settings(void);

#endif
