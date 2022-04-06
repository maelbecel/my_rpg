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
void draw_text(char *text, int size, sfVector2f pos, sfRenderWindow *window);

void display_key_with_pnj(game_t *game)
{
    printf("2\n");
    draw_text("click on : ", 30, (sfVector2f){400, 500}, game->window);
}