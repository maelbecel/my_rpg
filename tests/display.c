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


static game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->settings = init_settings();
    if (game->settings == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    game->scenes = init_scenes(game->window);
    game->player = init_player("chevalier");
    game->player->save = "1";
    game->hitbox = sfImage_createFromFile(
                                        HITBOX);
    return game;
}

Test(Display, Display_settings, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_settings(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_main_menu, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_main_menu(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

// Test(Display, Display_game, .timeout = 20)
// {
//     game_t *game = init_game();
//     sfEvent *event = malloc(sizeof(sfEvent));

//     game->scenes->page = GAME;
//     event->type = 1;
//     cr_assert_not_null(game);
//     display_game(game, event);
//     sfRenderWindow_destroy(game->window);
//     free(game);
// }
