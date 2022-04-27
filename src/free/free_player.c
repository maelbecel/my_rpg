/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void free_inventory(inventory_t **inventory)
{
    for (int i = 0; i < SIZE_INVENTORY; i++) {
        if (inventory[i]->elem)
            free_elements(inventory[i]->elem);
        free_button(inventory[i]->button);
        free(inventory[i]->type);
        free(inventory[i]);
    }
    free(inventory);
}

void free_player(game_t *game)
{
    if (game->player->quest)
        free(game->player->quest);
    free(game->player->save);
    free(game->player->class);
    if (game->player->elem)
        free_elements(game->player->elem);
    free_inventory(game->player->inventory);
    free(game->player);
}

void free_settings(game_t *game)
{
    sfFont_destroy(game->settings->font);
    free(game->settings);
}
