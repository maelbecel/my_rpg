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
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int battle(sfRenderWindow *window, sfSprite *a, sfSprite *b);
#endif
