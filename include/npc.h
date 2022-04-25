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

    struct npc_s {
        element_t *elem;
        char *name;
        char *text;
        int quest;
        bool merchant;
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
    void go_talk_npc(game_t *game);

    ////////////////////////////////////////////////////////////
    /// \brief Go to scene game
    ///
    /// \param game game_t struct with all game data
    ///
    ////////////////////////////////////////////////////////////
    void go_game(game_t *game);

    void move_npc(game_t *game, sfVector2f npcpos,
                                    sfVector2f playerpos, int i);

#endif /* !NPC_H_ */
