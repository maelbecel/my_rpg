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

#endif /* !NPC_H_ */
