/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    ////////////////////////////////////////////////////////////
    /// \def CROSSBOW_P
    ////////////////////////////////////////////////////////////
    #define CROSSBOW_P "assets/player/crossbow_man.png"

    ////////////////////////////////////////////////////////////
    /// \def ARCHER_P
    ////////////////////////////////////////////////////////////
    #define ARCHER_P "assets/player/bow_man.png"

    ////////////////////////////////////////////////////////////
    /// \def COOKER_P
    ////////////////////////////////////////////////////////////
    #define COOKER_P "assets/player/cooker.png"

    ////////////////////////////////////////////////////////////
    /// \def KNIGHT_P
    ////////////////////////////////////////////////////////////
    #define KNIGHT_P "assets/player/knight.png"

    ////////////////////////////////////////////////////////////
    /// \def VALKYRIE_P
    ////////////////////////////////////////////////////////////
    #define VALKYRIE_P "assets/player/valkyrie.png"

    ////////////////////////////////////////////////////////////
    /// \def MAGE_P
    ////////////////////////////////////////////////////////////
    #define MAGE_P "assets/player/mage.png"

    typedef struct element_s element_t;
    typedef struct player_s player_t;
    typedef struct inventory_s inventory_t;

    ////////////////////////////////////////////////////////////
    /// \brief Player struct.
    ///
    /// Contain the element, the hp, the strenght, the speed and the defense
    /// base stats of the player
    ///
    ////////////////////////////////////////////////////////////
    struct player_s {
        element_t *elem;
        inventory_t **inventory;
        sfClock *timer;
        char *class;
        char *save;
        int hp;
        int strg;
        int spd;
        int def;
        int xp;
        int pt_stat;
        int *quest;
        int nbquest;
    };

    struct inventory_s {
        char *type;
        int value;
        element_t *elem;
        button_t *button;
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
