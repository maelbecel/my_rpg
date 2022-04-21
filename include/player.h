/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #define CROSSBOW_P "ressources/player/crossbow_man.png"
    #define ARCHER_P "ressources/player/bow_man.png"
    #define COOKER_P "ressources/player/cooker.png"
    #define KNIGHT_P "ressources/player/knight.png"
    #define VALKYRIE_P "ressources/player/valkyrie.png"
    #define MAGE_P "ressources/player/mage.png"

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
        inventory_t *inventory;
        char *class;
        char *save;
        int hp;
        int strg;
        int spd;
        int def;
        int pt_stat;
        int *quest;
        int nbquest;
    };

    struct inventory_s {
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
