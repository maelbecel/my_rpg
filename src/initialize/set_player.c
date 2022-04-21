/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void set_player(game_t *game, sfVector2f getpos)
{
    if (getpos.x > 900) {
        game->scenes[GAME].elements[0]->rect.left = getpos.x - 900;
        game->scenes[GAME].elements[2]->pos.x = 900;
    } else
        game->scenes[GAME].elements[2]->pos.x = getpos.x;
    if (getpos.y > 500) {
        game->scenes[GAME].elements[0]->rect.top = getpos.y - 500;
        game->scenes[GAME].elements[2]->pos.y = 500;
    } else
        game->scenes[GAME].elements[2]->pos.y = getpos.y;
}

void set_player_inventory(game_t *game, char *file)
{
    char **elements = str_array_from_json(file, "inventory");

    if (elements == NULL || elements[0] == NULL ||
        my_strcmp(clean_string(elements[0]), "none") == 0)
        return;
    else if (my_strcmp(clean_string(elements[0]), "none") == 0 &&
            my_strarraylen(elements) != 1) {
        popup(game->settings->font, conc("Error corupted file:\n", file));
        quit(game);
    } else
        for (int i = 0; elements[i]; i++) {
            add_elem(game, clean_string(elements[i]));
        }
}
