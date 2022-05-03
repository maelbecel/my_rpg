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
    game->scenes[GAME].elements[0] = init_element("assets/village.jpg",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[5] = init_element("assets/roof.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6] = init_element("assets/shop_map.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[2]->pos = (sfVector2f){600, 600};
}

void tp_village_from_dungeon(game_t *game, ...)
{
    game->player->map = 1;
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    free_elements(game->scenes[GAME].elements[6]);
    sfImage_destroy(game->hitbox);
    game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
    game->scenes[GAME].elements[0] = init_element("assets/village.jpg",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[5] = init_element("assets/roof.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6] = init_element("assets/shop_map.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[2]->pos = (sfVector2f){1500, 600};
    game->scenes[GAME].elements[0]->rect.left = 500;
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

void tp_dungeon(game_t *game, ...)
{
    game->player->map = 2;
    free_elements(game->scenes[GAME].elements[0]);
    free_elements(game->scenes[GAME].elements[5]);
    sfImage_destroy(game->hitbox);
    game->hitbox = sfImage_createFromFile("assets/hitboxes/dungeon_hitbox.png");
    game->scenes[GAME].elements[0] = init_element("assets/dungeon.jpg",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[5] = init_element("assets/dungeon_roof.png",
            (sfVector2f){0, 0}, (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
    game->scenes[GAME].elements[6]->scale = (sfVector2f){0, 0};
    sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                        game->scenes[GAME].elements[6]->scale);
    game->scenes[GAME].elements[0]->rect.left = 0;
    game->scenes[GAME].elements[0]->rect.top = 1300;
    game->scenes[GAME].elements[2]->pos = (sfVector2f){700, 500};
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
    sfColor dungeon = TP_DUNGEON;
    sfColor village2 = TP_VILLAGE_2;
    void (*func)(game_t *game, ...) = NULL;

    if (col.r == forest.r && col.g == forest.g && col.b == forest.b)
        func = tp_forest;
    if (col.r == village.r && col.g == village.g && col.b == village.b)
        func = tp_village;
    if (col.r == village2.r && col.g == village2.g && col.b == village2.b)
        func = tp_village_from_dungeon;
    if (col.r == dungeon.r && col.g == dungeon.g && col.b == dungeon.b &&
        col.a == dungeon.a) {
        if (get_level(game->player->xp) < 20)
            return true;
        else
            func = tp_dungeon;
    } if (func != NULL) {
        transition(game, func);
        return true;
    }
    return false;
}