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
    typedef struct npc_s npc_t;

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
        int (*func)(game_t *game, sfEvent *event);
    };

    typedef struct clock_s {
        sfClock *clock;
        sfTime time;
        float seconds;
        float sec;
        int offset;
        int max;
    } clock_bg_t;

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
    /// \return 1 if failed when loading element, 0 otherwise
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
    int draw_text(char *text, sfFont *font, sfVector3f pos,
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
    int draw_text_white(char *text, int size, sfVector2f pos,
                                                    sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw the npc
    ///
    /// \param game  game_t object who contain all game info
    /// \param npc npc that will be displayed
    ///
    ////////////////////////////////////////////////////////////
    void draw_npc(game_t *game, npc_t *npc);

    ////////////////////////////////////////////////////////////
    /// \brief Display the npc
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void display_npc(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Display the talk to npc
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_talk_npc(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_settings(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_frame(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the sound settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_settings_sounds(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the key settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_settings_key(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the first how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_htp_first(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the second how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_htp_second(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the third how to play scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_htp_third(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Select what menu need to be display and display it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display(game_t *game, sfEvent *event);

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
    int display_menu_player(game_t *game, sfEvent *event);

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
    int display_choosing(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the load save menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_load(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the main menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_main_menu(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the pause menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_pause(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the game
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_game(game_t *game, sfEvent *event);

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
    /// \brief Set string form skip and action
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void set_action(game_t *game);

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
    /// \brief Draw xp bar
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void draw_xp_bar(game_t *game);

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

    ////////////////////////////////////////////////////////////
    /// \brief Draw an element on a window
    ///
    /// \param window  sfRenderWindow object where element should be display
    /// \param str     String who will be draw on the dialogue box
    /// \param font    font to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_dialogue_box(sfRenderWindow *window, char *str, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a fake popup
    ///
    /// \param text    Text to type
    /// \param font    font to use
    /// \param window  sfRenderWindow object where element should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_pop_text(char *text, sfFont *font, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a text in red
    ///
    /// \param text    Text to type
    /// \param font    font to use
    /// \param pos     contain posx posy of the text and the size in posz
    /// \param window  sfRenderWindow object where element should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text_red(char *text, sfFont *font,
                                    sfVector3f pos, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a text in green
    ///
    /// \param text    Text to type
    /// \param font    font to use
    /// \param pos     contain posx posy of the text and the size in posz
    /// \param window  sfRenderWindow object where element should be display
    ///
    ////////////////////////////////////////////////////////////
    void draw_text_green(char *text, sfFont *font,
                                    sfVector3f pos, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a text in green
    ///
    /// \param game    game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int display_battle(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Draw a life bar
    ///
    /// \param at      actual life
    /// \param on      max life
    /// \param game    game_t object who contain all game info
    /// \param pos     position of the bar
    ///
    ////////////////////////////////////////////////////////////
    void draw_life(int at, int on, game_t *game, sfVector2f pos);

    ////////////////////////////////////////////////////////////
    /// \brief Display frames per second or not
    ///
    /// \param frame   the value of frame in real time
    /// \param game    game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    int draw_fps(sfTime frame, game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Display the button of the inventory
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_button_inventory(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Display the button of the inventory
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_tab_inventory(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Skip
    ///
    /// \param window  sfRenderWindow object where element should be display
    ///
    ////////////////////////////////////////////////////////////
    bool skip(sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief sleep
    ///
    /// \param time    seconds to wait
    /// \param window  sfRenderWindow object where element should be display
    ///
    ////////////////////////////////////////////////////////////
    void my_sleep(float time, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief anim the sprite
    ///
    /// \param elem     element_t * element to anim
    /// \param clock    clock_bg_t * clock of the sprite
    ///
    ////////////////////////////////////////////////////////////
    void anim_sprite(element_t *elem, clock_bg_t *clock);

    ////////////////////////////////////////////////////////////
    /// \brief display a merchant npc
    ///
    /// \param game    game_t object who contain all game info
    /// \param npc     npc
    /// \param event   sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void display_merchant(game_t *game, npc_t *npc, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief display particles
    ///
    /// \param game    game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    int particles(UNUSED game_t *game, ...);

#endif
