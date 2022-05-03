/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void handle_forest(game_t *game)
{
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    game->scenes[GAME].elements[0] = init_element("assets/forest_start.jpg",
        (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->hitbox = sfImage_createFromFile("assets/hitboxes/forest_hitbox.png");
    game->scenes[GAME].elements[5] = init_element("assets/forest_roof.png",
        (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6]->scale = (sfVector2f){0, 0};
    sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                        game->scenes[GAME].elements[6]->scale);
}
static void handle_village(game_t *game)
{
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    game->scenes[GAME].elements[0] = init_element("assets/village.jpg",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[5] = init_element("assets/roof.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6]->scale = (sfVector2f){1, 1};
    game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
    sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                        game->scenes[GAME].elements[6]->scale);
}

int handle_map(game_t *game)
{
    if (game->player->map == 0) {
        handle_forest(game);
    } else if (game->player->map == 1) {
        handle_village(game);
    }
    return 0;
}