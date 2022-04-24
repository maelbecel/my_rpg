/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef EVENT
    #define EVENT

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct game_s game_t;

    ////////////////////////////////////////////////////////////
    /// \brief Check if a button is hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param b  number of the button in the scene
    /// \param s  number of the scene
    ///
    /// \return 1 if button is hoovered, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int is_hoover(game_t *game, int b, int s);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a button in menu player is hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param b  number of the button in the scene
    /// \param s  number of the scene
    /// \param t  number of the tab
    ///
    /// \return 1 if button is hoovered, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int is_hoover_menu(game_t *game, int b, int s, int t);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a button is clicked
    ///
    /// \param game  game_t object who contain all game info
    /// \param b  number of the button in the scene
    /// \param s  number of the scene
    ///
    /// \return 1 if button is clicked, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int is_click(game_t *game, int b, int s);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a button is clicked in menu player
    ///
    /// \param game  game_t object who contain all game info
    /// \param b  number of the button in the scene
    /// \param s  number of the scene
    /// \param t  number of the tab
    ///
    /// \return 1 if button is clicked, 0 if not
    ///
    ////////////////////////////////////////////////////////////
    int is_click_menu(game_t *game, int b, int s, int t);

    ////////////////////////////////////////////////////////////
    /// \brief Analyse events and do some action in function of it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    /// \return 0 if window is closed, 1 if not
    ///
    ////////////////////////////////////////////////////////////
    int analyse_event(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Analyse game events and do some action in function of it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void analyse_game(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Analyse game events and do some action in function of it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    /// \param frame frame obj
    ///
    ////////////////////////////////////////////////////////////
    void analyse_game_state(game_t *game, sfEvent *event, sfTime frame);

    ////////////////////////////////////////////////////////////
    /// \brief Analyse menu player events and do some action in function of it
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    int event_menu_player(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Change button state on clicked
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void clicked(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Change button in menu player state on clicked
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void clicked_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Change button state on hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void hoover(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Change button in menu player state on hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void hoover_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Do none
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void do_none(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Exit the game
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void quit(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to game
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void play(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to main menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void main_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to settings menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void settings(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to sounds settings
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void settings_sounds(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to keys settings
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void settings_key(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to how to play first scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void htp_first(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Save game state
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void save(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Check corrupted save
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void check_save(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Go to how to play second scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void htp_second(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to how to play third scene
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void htp_third(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to pause menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void pause_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key skip
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_skip(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key action
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_action(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key up
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_up(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key down
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_down(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key right
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_right(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key left
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_left(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key pause
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_pause(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Wait for input for key menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void wait_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to load menu
    ///
    /// \param game  game_t object who contain all game info
    /// \param ... other information passed with va_list arguments
    ///
    ////////////////////////////////////////////////////////////
    void load(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Set game to menu
    ///
    /// \param game  game_t object who contain all game info
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int menu_event(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Move sliders at position of the sound volume
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void set_slider_pos(game_t * game);

    ////////////////////////////////////////////////////////////
    /// \brief Move the slider at click position
    ///
    /// \param game  game_t object who contain all game info
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void move_slider(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Move player down
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void move_down(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Move player up
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void move_up(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Move player left
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void move_left(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Move player right
    ///
    /// \param game  game_t object who contain all game info
    ///
    ////////////////////////////////////////////////////////////
    void move_right(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Display menu clicked
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void clicked_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Display clicked
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void clicked(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Display menu hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void hoover_menu(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Display hoover
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void hoover(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Init a new game
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void new_game(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Clear the save 1
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void clear_1(UNUSED game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Clear the save 2
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void clear_2(UNUSED game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Clear the save 3
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void clear_3(UNUSED game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to player tab
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void go_to_player(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to stat tab
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void go_to_stat(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to quest tab
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void go_to_quest(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Go to inventory tab
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void go_to_inventory(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Add HP to player
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void add_hp(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Add Strenght to player
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void add_strenght(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Add Speed to player
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void add_speed(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Add Defense to player
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void add_defense(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Apply save to player struct
    ///
    /// \param game  game_t object who contain all game info
    /// \param ...   other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    void reset(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Check if a key \a i is already use
    ///
    /// \param game  game_t object who contain all game info
    /// \param i     key to check
    ///
    ////////////////////////////////////////////////////////////
    bool already_def(game_t *game, int i);

    ////////////////////////////////////////////////////////////
    /// \brief add an element to the inventory
    ///
    /// \param game  game_t object who contain all game info
    /// \param type  type of the element to add
    ///
    ////////////////////////////////////////////////////////////
    void add_elem(game_t *game, char *type);

#endif
