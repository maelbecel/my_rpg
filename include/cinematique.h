/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef CINE_H_
    #define CINE_H_

    #include "display.h"

    ////////////////////////////////////////////////////////////
    /// \def EPITECH
    ////////////////////////////////////////////////////////////
    #define EPITECH "assets/cinematiques/epitech.png"

    ////////////////////////////////////////////////////////////
    /// \def E LETTER
    ////////////////////////////////////////////////////////////
    #define E_LETTER "assets/cinematiques/E_letter.png"

    ////////////////////////////////////////////////////////////
    /// \brief Launch the intro scene
    ///
    /// \param window  sfRenderWindow object where intro should be display
    /// \param mul
    /// \param opacity
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int intro(sfRenderWindow *window, int mul, int opacity);

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
    /// \param ...     other useful arguments
    ///
    /// \return 0
    ///
    ////////////////////////////////////////////////////////////
    int battle(game_t *game, ...);

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

    ////////////////////////////////////////////////////////////
    /// \brief Draw a transition scene
    ///
    /// \param game game object to use
    /// \param func function to use
    ///
    ////////////////////////////////////////////////////////////
    void transition(game_t *game, void func(game_t *game, ...));

#endif
