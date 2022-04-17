/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef CINE
    #define CINE

    ////////////////////////////////////////////////////////////
    /// \brief Launch the intro scene
    ///
    /// \param window  sfRenderWindow object where intro should be display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int intro(sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the outro scene
    ///
    /// \param window  sfRenderWindow object where outro should be display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int outro(sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Launch the battle scene
    ///
    /// \param window  sfRenderWindow object where outro should be display
    /// \param a       Player sprite to display
    /// \param b       Enemy sprite to display
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int battle(sfRenderWindow *window, sfSprite *a, sfSprite *b);

    ////////////////////////////////////////////////////////////
    /// \brief Display fight in cinematic
    ///
    /// \param music   sfMusic element with the sound to display
    /// \param window  sfRenderWindow object where outro should be display
    ///
    ////////////////////////////////////////////////////////////
    void fight_display(sfMusic *music, sfRenderWindow *window);

    ////////////////////////////////////////////////////////////
    /// \brief Init epitech sprite
    ///
    /// \return sfSprite element with epitech logo
    ///
    ////////////////////////////////////////////////////////////
    sfSprite *episprite(void);

    ////////////////////////////////////////////////////////////
    /// \brief Init E sprite
    ///
    /// \return sfSprite element with E
    ///
    ////////////////////////////////////////////////////////////
    sfSprite *lettersprite(void);

    ////////////////////////////////////////////////////////////
    /// \brief Init radiant rect
    ///
    /// \return sfRectangleShape element with the radiant
    ///
    ////////////////////////////////////////////////////////////
    sfRectangleShape *init_rect_rad(void);

    ////////////////////////////////////////////////////////////
    /// \brief Choose how many latter should be draw
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param epitech sfSprite element with epitech logo
    /// \param letter  sfSprite element with letter E
    /// \param opmul   Tuple with the opacity and the multiplier
    ///
    ////////////////////////////////////////////////////////////
    void what_draw(sfRenderWindow *window, sfSprite *epitech,
                                        sfSprite *letter, sfVector2f opmul);

    ////////////////////////////////////////////////////////////
    /// \brief Draw radiant
    ///
    /// \param window sfRenderWindow object where intro should be display
    /// \param rect   sfRectangleShape element with the voil
    /// \param op     opaity of the voil
    ///
    ////////////////////////////////////////////////////////////
    void draw_voil(sfRenderWindow *window, sfRectangleShape *rect, int op);

    ////////////////////////////////////////////////////////////
    /// \brief Draw outro scene
    ///
    /// \param window   sfRenderWindow object where intro should be display
    /// \param epitech  sfSprite element to dispaly
    /// \param rect     sfRectangleShape element with the voil
    /// \param opacity  opaity of the voil
    ///
    ////////////////////////////////////////////////////////////
    void draw_outro(sfRenderWindow *window, sfSprite *epitech,
                                        sfRectangleShape *rect, int opacity);

#endif
