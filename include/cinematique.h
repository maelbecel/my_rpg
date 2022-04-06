/*
** EPITECH PROJECT, 2022
** rpg.c
** File description:
** rpg
*/

#ifndef CINE
    #define CINE

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
#endif
