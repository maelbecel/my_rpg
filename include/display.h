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
    typedef struct inventory_s inventory_t;

    enum menu_player {
        PLAYER,
        STAT,
        QUEST,
        INVENTORY
    };

    ////////////////////////////////////////////////////////////
    /// \brief Displau struct.
    ///
    /// Contain the scene number and the display function
    ///
    /// \struct display_s display_t
    ///
    ////////////////////////////////////////////////////////////
    struct display_s {
        int scene;
        void (*func)(game_t *game, sfEvent *event);
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
    /// \param font    Font element
    /// \param pos     Position of the text in the window and z is the size
    /// \param window  sfRenderWindow object where text should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text(char *text, sfFont *font, sfVector3f pos,
                                                    sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw white a text on a window
    ///
    /// \param text    Text that need to be display
    /// \param size    Size of the text
    /// \param pos     Position of the text in the window
    /// \param window  sfRenderWindow object where text should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text_white(char *text, int size, sfVector2f pos,
                                                    sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Display the settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_settings(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_frame(game_t *game, sfEvent *event);

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

    ////////////////////////////////////////////////////////////
    /// \brief Display a popup
    ///
    /// \param font  sfFont element to use
    /// \param str   String to display on the popup
    ///
    ////////////////////////////////////////////////////////////
    void popup(sfFont *font, char *str);

    ////////////////////////////////////////////////////////////
    /// \brief Display the stat menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_stat(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the quest menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_quest(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Select the tab to display
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_tab(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Draw stat of the player
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void draw_stat_char(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Display the inventory
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_inventory(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display one case of the inventory
    ///
    /// \param game  game_t object who contain all game info
    /// \param pos position of the case
    /// \param inventory case of the inventory
    ///
    ////////////////////////////////////////////////////////////
    void display_case_inventory(game_t *game, sfVector2f pos,
                                inventory_t *inventory);

    ////////////////////////////////////////////////////////////
    /// \brief Display the player info
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_player(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the buttons for menu player
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    /// \param nb    nb of the button cliked
    ///
    ////////////////////////////////////////////////////////////
    void display_button_menu_player(game_t *game, sfEvent *event, int nb);

    ////////////////////////////////////////////////////////////
    /// \brief Display the choosing character menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_choosing(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the load save menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_load(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the main menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_main_menu(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the pause menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_pause(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the game
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_game(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Set string form up and down
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void set_vert(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Set string form left and right
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void set_hori(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Set string form pause and menu
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void set_othr(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Get touch name from key input
    ///
    /// \param key  key input
    ///
    /// \return Return the name of the \a key
    ///
    ////////////////////////////////////////////////////////////
    char *getkey(int key);

    ////////////////////////////////////////////////////////////
    /// \brief Set player to base coordinates
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   UNUSED information
    ///
    ////////////////////////////////////////////////////////////
    void set_good(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Get quest registered
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    char *get_quests(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Delete first and last charactersof a string
    ///
    /// \param str String to clean
    ///
    /// \return Returns the string clean
    ///
    ////////////////////////////////////////////////////////////
    char *clean_string(char *str);

#endif
