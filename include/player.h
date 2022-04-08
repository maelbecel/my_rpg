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

    struct player {
        element_t *elem;
        int pv;
        int strg;
        int spd;
        int def;
    };

#endif /* !PLAYER_H_ */
