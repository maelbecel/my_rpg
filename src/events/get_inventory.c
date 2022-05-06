/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_talk_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void add_element_n(game_t *game, char *type, int n)
{
    for (int i = 0; i < n; i++)
        add_elem(game, type);
}

void delete_element_n(game_t *game, char *type, int n)
{
    for (int i = 0; i < n; i++)
        delete_element(game, type);
}

void delete_element(game_t *game, char *type)
{
    int i = SIZE_INVENTORY;

    for (; i >= 0 ; i--) {
        if (game->player->inventory[i]->type != NULL &&
            !my_strcmp(type, game->player->inventory[i]->type)) {
            game->player->inventory[i]->value--;
        }
        if (game->player->inventory[i]->type != NULL &&
            game->player->inventory[i]->value == 0) {
            game->player->inventory[i]->value = 0;
            game->player->inventory[i]->type = NULL;
            free(type);
            game->player->inventory[i]->elem = NULL;
        }
    }
}

int get_nb_elem(game_t *game, char *type)
{
    int i = 0;
    int x = 0;

    for (; i < SIZE_INVENTORY && game->player->inventory[i]->type != NULL; i++)
        if (my_strcmp(type, game->player->inventory[i]->type) == 0)
            x += game->player->inventory[i]->value;
    return x;
}
