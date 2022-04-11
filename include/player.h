/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    typedef struct element_s element_t;
    typedef struct player player_t;

    ////////////////////////////////////////////////////////////
    /// \brief Player struct.
    ///
    /// Contain the element, the hp, the strenght, the speed and the defense
    /// base stats of the player
    ///
    ////////////////////////////////////////////////////////////
    struct player {
        element_t *elem;
        char *class;
        int hp;
        int strg;
        int spd;
        int def;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Initialize the player with it's base stats
    ///
    /// \param class Name of the class of the player
    ///
    /// \return struct player_t* with the player base stats
    ///
    ////////////////////////////////////////////////////////////
    player_t *init_player(char *class);

#endif /* !PLAYER_H_ */
