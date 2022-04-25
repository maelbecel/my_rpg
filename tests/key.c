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
    game->settings = init_settings();
    if ((game->settings) == NULL)
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
