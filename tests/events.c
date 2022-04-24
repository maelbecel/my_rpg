/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

static game_t *initialize_new_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    if ((game->settings = init_settings()) == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    game->scenes = init_scenes(game->window);
    game->settings->key_down = 1;
    game->settings->key_up = 2;
    game->settings->key_left = 3;
    game->settings->key_right = 4;
    game->settings->key_pause = 5;
    game->settings->key_skip = 6;
    game->settings->key_action = 7;
    game->settings->key_menu = 8;
    return game;
}

Test(Initialize, Set_player_inventory_1, .timeout = 20)
{
    game_t *game = initialize_new_game();

    cr_assert_not_null(game);
    set_player_inventory(game, "tests/test.json");
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Initialize, Set_player_1, .timeout = 20)
{
    game_t *game = initialize_new_game();
    sfVector2f pos = {1500, 1500};

    cr_assert_not_null(game);
    set_player(game, pos);
    cr_assert_eq(game->scenes[GAME].elements[2]->pos.x, 1000);
    cr_assert_eq(game->scenes[GAME].elements[2]->pos.y, 1000);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Initialize, Set_player_2, .timeout = 20)
{
    game_t *game = initialize_new_game();
    sfVector2f pos = {400, 400};

    cr_assert_not_null(game);
    set_player(game, pos);
    cr_assert_eq(game->scenes[GAME].elements[2]->pos.x, 400);
    cr_assert_eq(game->scenes[GAME].elements[2]->pos.y, 400);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Events, Key_already_def)
{
    game_t *game = initialize_new_game();
    bool val = already_def(game, 3);

    cr_assert_eq(val, true);
}

Test(Events, Key_not_def)
{
    game_t *game = initialize_new_game();
    bool val = already_def(game, 10);

    cr_assert_eq(val, false);
}