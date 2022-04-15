/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef DISPLAY
    #define DISPLAY

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct game_s game_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct settings_s settings_t;
    typedef struct pos_perso_s pos_perso_t;

    enum menu_player {
        PLAYER,
        STAT,
        QUEST,
        INVENTORY
    };

    ////////////////////////////////////////////////////////////
    /// \brief Draw a button on a window
    ///
    /// \param window  sfRenderWindow object where button should be display
    /// \param button  Button object who will be draw on the window
    ///
    ////////////////////////////////////////////////////////////
    void draw_button(sfRenderWindow *window, button_t *button);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a button in hoover state on a window
    ///
    /// \param window  sfRenderWindow object where button should be display
    /// \param button  Button object who will be draw on the window
    ///
    ////////////////////////////////////////////////////////////
    void draw_hoover(sfRenderWindow *window, button_t *button);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a button in clicked state on a window
    ///
    /// \param window  sfRenderWindow object where button should be display
    /// \param button  Button object who will be draw on the window
    ///
    ////////////////////////////////////////////////////////////
    void draw_clicked(sfRenderWindow *window, button_t *button);

    ////////////////////////////////////////////////////////////
    /// \brief Draw an element on a window
    ///
    /// \param window  sfRenderWindow object where element should be display
    /// \param element Element object who will be draw on the window
    ///
    ////////////////////////////////////////////////////////////
    void draw_element(sfRenderWindow *window, element_t *element);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a text on a window
    ///
    /// \param text    Text that need to be display
    /// \param size    Size of the text
    /// \param pos     Position of the text in the window
    /// \param window  sfRenderWindow object where text should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text(char *text, int size, sfVector2f pos, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw white a text on a window
    ///
    /// \param text    Text that need to be display
    /// \param size    Size of the text
    /// \param pos     Position of the text in the window
    /// \param window  sfRenderWindow object where text should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text_white(char *text, int size, sfVector2f pos, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Display the settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_settings(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the sound settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_settings_sounds(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the key settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_settings_key(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the first how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_htp_first(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the second how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_htp_second(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the third how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_htp_third(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Select what menu need to be display and display it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Show the actual key in the key settings menu
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void concat_settings(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief show the key to expand with a pnj
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void display_key_with_pnj(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Concatenate the settings
    ///
    /// \param a  first element to concat
    /// \param b  second element to concat
    ///
    /// \return The concatenated string of a and b
    ///
    ////////////////////////////////////////////////////////////
    char *conc(char *a, char *b);

    ////////////////////////////////////////////////////////////
    /// \brief Display the menu of the player
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_menu_player(game_t *game, sfEvent *event);

#endif
