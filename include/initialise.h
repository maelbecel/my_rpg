/*
** EPITECH PROJECT, 2022
** rpg.h
** File description:
** rpg
*/

#ifndef INIT
    #define INIT

    #define SIZE_INVENTORY 32

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct game_s game_t;
    typedef struct button_s button_t;
    typedef struct element_s element_t;
    typedef struct scene_s scene_t;
    typedef struct settings_s settings_t;
    typedef struct type_button_s type_button_t;
    typedef struct inventory_s inventory_t;
    typedef struct npc_s npc_t;

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the main menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **main_menu_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the main menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **main_menu_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the game
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **game_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the game
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **game_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the settings menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the settings menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the player menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **menu_player_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the player menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **menu_player_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get tabs for the player menu
    ///
    /// \return struct scene_t ** with all tab for the scene
    ///
    ////////////////////////////////////////////////////////////
    scene_t *menu_player_tab(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the key settings  menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_key_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the key settings menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_key_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the sounds settings menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_sounds_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the sounds settings menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_sounds_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the frame settings menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **settings_buttons_frame(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the frame settings menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **settings_elements_frame(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the first page of how to play
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_first_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the first page of how to play
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_first_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the second page of how to play
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_second_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the second page of how to play
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_second_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the third page of how to play
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **htp_third_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the third page of how to play
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **htp_third_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the pause menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **pause_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the pause menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **pause_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the pause menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **choosing_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the pause menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **choosing_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the load menu
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **load_menu_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the load menu
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **load_menu_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get all scenes with elements and buttons
    ///
    /// \param window window where display loading bar
    ///
    /// \return struct scene_t * with all elements and buttons for all scenes
    ///
    ////////////////////////////////////////////////////////////
    scene_t *init_scenes(sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Create an element from a file
    ///
    /// \param texture Path to the texture
    /// \param pos     sfVector2f struct with the position of the element
    /// \param size    sfVector2f struct with the size of the element
    /// \param scale   sfVector2f struct with the scale of the element
    ///
    /// \return struct element_t * with the element
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
    /// \return struct button_t * with the button
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
    /// \return struct type_button_t * with the button aspect
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
    /// \return struct settings_t * with the base settings
    ///
    ////////////////////////////////////////////////////////////
    settings_t *init_settings(void);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize inventory of the player,
    ///
    /// \return struct inventory_t ** with the inventory of the player
    ///
    ////////////////////////////////////////////////////////////
    inventory_t **init_inventory(void);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize htp scenes
    ///
    /// \param scenes  Scenes to initialize
    /// \param window  Window to display loading bar
    ///
    ////////////////////////////////////////////////////////////
    int init_htp(scene_t *scenes, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize settings menus
    ///
    /// \param scenes  Scenes to initialize
    /// \param window  Window to display loading bar
    ///
    ////////////////////////////////////////////////////////////
    int init_settings_menu(scene_t *scenes, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize player menus
    ///
    /// \param scenes  Scenes to initialize
    /// \param window  Window to display loading bar
    ///
    ////////////////////////////////////////////////////////////
    int init_menu_player(scene_t *scenes, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize new game
    ///
    /// \param scenes  Scenes to initialize
    /// \param window  Window to display loading bar
    ///
    ////////////////////////////////////////////////////////////
    int init_new_game(scene_t *scenes, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Initialize talk npc
    ///
    /// \param scenes  Scenes to initialize
    ///
    ////////////////////////////////////////////////////////////
    int init_talk_npc(scene_t *scenes);

    ////////////////////////////////////////////////////////////
    /// \brief Update buttons for stat tab
    ///
    /// \param buttons  buttons array to update
    ///
    ////////////////////////////////////////////////////////////
    void update_stat(button_t **buttons);

    ////////////////////////////////////////////////////////////
    /// \brief Set player at is old XY
    ///
    /// \param game   game_t struct containing the game data
    /// \param getpos tuple of coordinates
    ///
    ////////////////////////////////////////////////////////////
    void set_player(game_t *game, sfVector2f getpos);

    ////////////////////////////////////////////////////////////
    /// \brief Set player at is old inventory from save
    ///
    /// \param game   game_t struct containing the game data
    /// \param file   file of the save
    ///
    ////////////////////////////////////////////////////////////
    void set_player_inventory(game_t *game, char *file);

    ////////////////////////////////////////////////////////////
    /// \brief initialise npc in game scene
    ///
    ////////////////////////////////////////////////////////////
    npc_t **game_npc(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the npc merchant
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **npc_buttons(void);

    ////////////////////////////////////////////////////////////
    /// \brief Get elements for the npc merchant
    ///
    /// \return struct element_t ** with all elements for the scene
    ///
    ////////////////////////////////////////////////////////////
    element_t **npc_elements(void);

    ////////////////////////////////////////////////////////////
    /// \brief set bad tab to null
    ///
    /// \param scenes scene_t struct containing the scene
    ///
    ////////////////////////////////////////////////////////////
    void set_tab(scene_t *scenes);

    ////////////////////////////////////////////////////////////
    /// \brief Initialise battle scene
    ///
    /// \param scenes scene_t struct containing the scene
    ///
    ////////////////////////////////////////////////////////////
    int init_battle(scene_t *scenes);

    ////////////////////////////////////////////////////////////
    /// \brief Get buttons for the inventory
    ///
    /// \return struct button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    button_t **button_inventory(void);

    ////////////////////////////////////////////////////////////
    /// \brief Initialise buttons scale of htp
    ///
    /// \param buttons button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    void init_htp_buttons(button_t **buttons);


    ////////////////////////////////////////////////////////////
    /// \brief Initialise buttons scale of settings
    ///
    /// \param buttons button_t ** with all buttons for the scene
    ///
    ////////////////////////////////////////////////////////////
    void rescale_frame(button_t **buttons);

#endif
