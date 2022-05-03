/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_

    ////////////////////////////////////////////////////////////
    // Structures
    ////////////////////////////////////////////////////////////
    typedef struct element_s element_t;
    typedef struct npc_s npc_t;
    typedef struct enemy_s enemy_t;
    typedef struct trade_s trade_t;

    struct npc_s {
        element_t *elem;
        char *name;
        char *text;
        int quest;
        bool merchant;
        int map;
    };

    struct enemy_s {
        element_t *elem;
        char *name;
        char **text;
        int life;
        int total_life;
        int damage;
        int exp;
        int level;
        char *buf_text;
        char **loot;
    };

    struct trade_s {
        char *want;
        int want_quantity;
        char *give;
        int give_quantity;
    };

    ////////////////////////////////////////////////////////////
    /// \brief create a npc
    ///
    /// \param name name of the npc
    ///
    ////////////////////////////////////////////////////////////
    npc_t *create_npc(char *name);

    ////////////////////////////////////////////////////////////
    /// \brief Check distance about npc and player
    ///
    /// \param game game_t struct with all game data
    /// \param event sfEvent object where events are register
    ///
    ////////////////////////////////////////////////////////////
    void check_npc(game_t *game, sfEvent *event);

    ////////////////////////////////////////////////////////////
    /// \brief Go to scene talk to npc
    ///
    /// \param game game_t struct with all game data
    ///
    ////////////////////////////////////////////////////////////
    int go_talk_npc(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Go to scene game
    ///
    /// \param game game_t struct with all game data
    ///
    ////////////////////////////////////////////////////////////
    int go_game(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Return npc_t if the npc is near
    ///
    /// \param game game_t struct with all game data
    ///
    ////////////////////////////////////////////////////////////
    npc_t *find_npc(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Return npc_t if the npc is near
    ///
    /// \param game       game_t struct with all game data
    /// \param npcpos     position of the npc
    /// \param playerpos  position of the player
    /// \param i          index of the npc
    ///
    ////////////////////////////////////////////////////////////
    void move_npc(game_t *game, sfVector2f npcpos,
                                    sfVector2f playerpos, int i);

    ////////////////////////////////////////////////////////////
    /// \brief Return trade struct of an npc
    ///
    /// \param npc npc_t *struct
    ///
    ////////////////////////////////////////////////////////////
    trade_t **get_trade(npc_t *npc);

    ////////////////////////////////////////////////////////////
    /// \brief give quest
    ///
    /// \param game  game_t struct with all game data
    /// \param npc   npc_t *struct
    ///
    ////////////////////////////////////////////////////////////
    void give_quest(game_t *game, npc_t *npc);

    ////////////////////////////////////////////////////////////
    /// \brief trade
    ///
    /// \param game  game_t struct with all game data
    /// \param ... other useful arguments
    ///
    ////////////////////////////////////////////////////////////
    int trade(game_t *game, ...);

    ////////////////////////////////////////////////////////////
    /// \brief Create a new ennemy
    ///
    /// \param type   type of ennemy
    /// \param player players info
    ///
    ////////////////////////////////////////////////////////////
    enemy_t *create_enemy(char *type, player_t *player);

#endif /* !NPC_H_ */
