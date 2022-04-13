/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef EVENT
    #define EVENT

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

#endif