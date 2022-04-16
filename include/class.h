/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef CLASS
    #define CLASS

    ////////////////////////////////////////////////////////////
    /// \brief Draw knight stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_chevalier_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the knight init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void chevalier(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Draw Archery stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_archere_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the archery init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void archere(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Draw arbaletier stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_arbaletier_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the arbaletier init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void arbaletier(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Draw cuisiniere stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_cuisiniere_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the cuisiniere init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void cuisiniere(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Draw mage stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_mage_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the mage init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void mage(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Draw valkyrie stat
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param font    sfFont object to use
    ///
    ////////////////////////////////////////////////////////////
    void draw_valkyrie_char(sfRenderWindow *window, sfFont *font);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the valkyrie init
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void valkyrie(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Load save from save1.json
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void load_1(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Load save from save2.json
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void load_2(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Load save from save3.json
    ///
    /// \param game game_t object where the game is register
    /// \param ... other arguments to pass
    ///
    ////////////////////////////////////////////////////////////
    void load_3(game_t *game, ...);

#endif