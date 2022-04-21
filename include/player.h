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
    typedef struct inventory inventory_t;

    ////////////////////////////////////////////////////////////
    /// \brief Player struct.
    ///
    /// Contain the element, the hp, the strenght, the speed and the defense
    /// base stats of the player
    ///
    ////////////////////////////////////////////////////////////
    struct player {
        element_t *elem;
        inventory_t *inventory;
        char *class;
        char *save;
        int hp;
        int strg;
        int spd;
        int def;
        int pt_stat;
    };

    struct inventory {
        char *type;
        int value;
        element_t *elem;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Initialize the player with it's base stats
    ///
    /// \param class Name of the class of the player
    ///
    /// \return struct player_t * with the player base stats
    ///
    ////////////////////////////////////////////////////////////
    player_t *init_player(char *class);

    ////////////////////////////////////////////////////////////
    /// \brief Get old stat player
    ///
    /// \param game Actual game state
    /// \param ...  Other uselful data
    ///
    ////////////////////////////////////////////////////////////
    void reset(game_t *game, ...);

#endif /* !PLAYER_H_ */
