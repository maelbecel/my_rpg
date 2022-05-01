/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static char *fill_inv(inventory_t **inventory)
{
    char *buffer = malloc(sizeof(inventory_t **));

    if (!buffer)
        return NULL;
    buffer = "[";
    for (int i = 0; inventory[i]->type ; i++)
        for (int j = 0; j < inventory[i]->value; j++) {
            buffer = conc(buffer, conc("\"", conc(inventory[i]->type, "\"")));
            buffer = (inventory[i + 1]->type == NULL &&
                        j == inventory[i]->value - 1)
                    ? buffer : conc(buffer, ",");
        }
    buffer = conc(buffer, "]\n");
    return buffer;

}

void update_inventory(game_t *game)
{
    char *buffer = fill_inv(game->player->inventory);
    char *file = conc("saves/save", conc(game->player->save, ".json"));

    if (!game->player->inventory[0]->type)
        buffer = "[\"none\"]";
    update_file(file, "inventory", buffer);
    free(file);
    free(buffer);
}
