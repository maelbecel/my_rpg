/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_npc
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void tp_village(game_t *game, ...)
{
    game->player->map = 1;
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    free_elements(game->scenes[GAME].elements[6]);
    sfImage_destroy(game->hitbox);
    game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
    game->scenes[GAME].elements[0] = init_element("assets/village.jpg", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[5] = init_element("assets/roof.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6] = init_element("assets/shop_map.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[2]->pos = (sfVector2f){600, 600};
}

void tp_forest(game_t *game, ...)
{
    game->player->map = 0;
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    sfImage_destroy(game->hitbox);
    game->hitbox = sfImage_createFromFile("assets/hitboxes/forest_hitbox.png");
    game->scenes[GAME].elements[0] = init_element("assets/forest_start.jpg",
        (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->hitbox = sfImage_createFromFile("assets/hitboxes/forest_hitbox.png");
    game->scenes[GAME].elements[5] = init_element("assets/forest_roof.png",
        (sfVector2f){0, 0}, (sfVector2f){2500, 2500}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6]->scale = (sfVector2f){0, 0};
    sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                        game->scenes[GAME].elements[6]->scale);
    game->scenes[GAME].elements[0]->rect.left = 580;
    game->scenes[GAME].elements[2]->pos = (sfVector2f){1000, 200};

}

bool teleportation(game_t *game, sfVector2f move)
{
    float x = (game->scenes[GAME].elements[2]->pos.x + move.x +
                        (float)game->scenes[GAME].elements[0]->rect.left + 30);
    float y = (game->scenes[GAME].elements[2]->pos.y + move.y +
                        (float)game->scenes[GAME].elements[0]->rect.top + 90);
    sfColor col = sfImage_getPixel(game->hitbox, x, y);
    sfColor forest = TP_FOREST;
    sfColor village = TP_VILLAGE;

    if (col.r == forest.r && col.g == forest.g && col.b == forest.b) {
        transition(game, tp_forest);
        return true;
    } else if (col.r == village.r && col.g == village.g && col.b == village.b) {
        transition(game, tp_village);
        return true;
    }
    return false;
}