/*
** EPITECH PROJECT, 2022
** display_key_with_pnj
** File description:
** display_key_with_pnj for rpg
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

char *conc(char *a, char *b);
char *getkey(int key);

void display_key_with_pnj(game_t *game, UNUSED pos_perso_t *pos_perso)
{
    printf("%f\n%d\n", (game->scenes[GAME].elements[2]->pos.x - 900), game->scenes[GAME].elements[1]->rect.left);
    if ((game->scenes[GAME].elements[2]->pos.x - 900) < game->scenes[GAME].elements[1]->rect.left)
        draw_text(conc("CLICK ON : ", getkey(game->settings->key_menu)), 30,
                    (sfVector2f){860, 940}, game->window);
}