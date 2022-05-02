/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void new_game(game_t *game, ...)
{
    va_list arg;
    va_start(arg, game);
    int i = va_arg(arg, int);
    i++;
    game->player->save[0] = i + '0';
    game->scenes->page = CHOOSING;
    game->scenes[GAME].elements[0]->rect.left = 0;
    game->scenes[GAME].elements[2]->pos.x = 800;
    game->scenes[GAME].elements[0]->rect.top = 0;
    game->scenes[GAME].elements[2]->pos.y = 800;
    game->player->xp = 0;
    game->player->map = 0;
    game->player->nbquest = 1;
    game->player->quest = malloc(sizeof(int));
    game->player->quest[0] = 0;
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
    va_end(arg);
}

void load_1(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE1, "posx"),
                                    int_from_json(SAVE1, "posy")};

    game->player->save[0] = '1';
    check_save(game);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE1, "quests",
                                                    &game->player->nbquest);
    game->player->xp = int_from_json(SAVE1, "xp");
    game->player->map = int_from_json(SAVE1, "map");
    set_player_inventory(game, SAVE1);
    if (game->player->map == 0) {
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
    } else if (game->player->map == 1) {
        free_elements(game->scenes[GAME].elements[0]);
        free_elements(game->scenes[GAME].elements[5]);
        game->scenes[GAME].elements[0] = init_element("assets/village.jpg", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[5] = init_element("assets/roof.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[6]->scale = (sfVector2f){1, 1};
        game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
        sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                            game->scenes[GAME].elements[6]->scale);
    }
    set_player(game, getpos);
}

void load_2(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE2, "posx"),
        int_from_json(SAVE2, "posy")};

    game->player->save[0] = '2';
    check_save(game);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE2, "quests",
                                                    &game->player->nbquest);
    game->player->xp = int_from_json(SAVE2, "xp");
    game->player->map = int_from_json(SAVE2, "map");

    set_player_inventory(game, SAVE2);
    if (game->player->map == 0) {
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
    } else if (game->player->map == 1) {
        free_elements(game->scenes[GAME].elements[0]);
        free_elements(game->scenes[GAME].elements[5]);
        game->scenes[GAME].elements[0] = init_element("assets/village.jpg", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[5] = init_element("assets/roof.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[6]->scale = (sfVector2f){1, 1};
        game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
        sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                            game->scenes[GAME].elements[6]->scale);
    }
    set_player(game, getpos);
}

void load_3(game_t *game, ...)
{
    sfVector2f getpos = (sfVector2f){int_from_json(SAVE3, "posx"),
        int_from_json(SAVE3, "posy")};

    game->player->save[0] = '3';
    check_save(game);
    reset(game);
    game->scenes->page = GAME;
    game->player->nbquest = 0;
    game->player->quest = int_array_from_json(SAVE3, "quests",
                                                    &game->player->nbquest);
    game->player->xp = int_from_json(SAVE3, "xp");
    game->player->map = int_from_json(SAVE3, "map");
    set_player_inventory(game, SAVE3);
    if (game->player->map == 0) {
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
    } else if (game->player->map == 1) {
        free_elements(game->scenes[GAME].elements[0]);
        free_elements(game->scenes[GAME].elements[5]);
        game->scenes[GAME].elements[0] = init_element("assets/village.jpg", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[5] = init_element("assets/roof.png", (sfVector2f){0, 0},
                            (sfVector2f){1920, 1080}, (sfVector2f){1, 1});
        game->scenes[GAME].elements[6]->scale = (sfVector2f){1, 1};
        game->hitbox = sfImage_createFromFile("assets/hitboxes/hitbox.png");
        sfSprite_setScale(game->scenes[GAME].elements[6]->sprite,
                            game->scenes[GAME].elements[6]->scale);
    }
    set_player(game, getpos);
}

void load(game_t *game, ...)
{
    for (int i = 0; i < SIZE_INVENTORY; i++) {
        game->player->inventory[i]->type = NULL;
        game->player->inventory[i]->value = 0;
        game->player->inventory[i]->elem = NULL;
    }
    game->scenes->page = LOAD;
}
