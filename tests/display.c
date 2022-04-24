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
    if ((game->settings = init_settings()) == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    game->scenes = init_scenes(game->window);
    game->player = init_player("chevalier");
    game->player->save = "1";
    game->hitbox = sfImage_createFromFile(
                                        "assets/hitboxes/village_hitbox.png");
    return game;
}

Test(Display, Draw_xp_bar, .timeout = 20)
{
    game_t *game = init_game();

    game->player->xp = 2000;
    cr_assert_not_null(game);
    draw_xp_bar(game);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Draw_npc, .timeout = 20)
{
    game_t *game = init_game();
    npc_t *npc = create_npc("pascal");

    cr_assert_not_null(game);
    draw_npc(game, npc);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_frame, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_frame(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Draw_choosing, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_choosing(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_load, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_load(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_pause, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_pause(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_htp_third, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_htp_third(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_htp_second, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_htp_second(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_htp_first, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_htp_first(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_menu_player, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_menu_player(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_settings_sounds, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_settings_sounds(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Display_settings_key, .timeout = 30)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    event->type = 1;
    cr_assert_not_null(game);
    display_settings_key(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
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

Test(Display, Display_game, .timeout = 20)
{
    game_t *game = init_game();
    sfEvent *event = malloc(sizeof(sfEvent));

    game->scenes->page = MAIN_MENU;
    event->type = 1;
    cr_assert_not_null(game);
    display_game(game, event);
    sfRenderWindow_destroy(game->window);
    free(game);
}

Test(Display, Good_key)
{
    char *val = getkey(sfKeySpace);

    cr_assert_eq(my_strcmp(val, "SPACE"), EXIT_SUCCESS);
}

Test(Display, Bad_key)
{
    char *val = getkey(10000);

    cr_assert_eq(my_strcmp(val, "NULL"), EXIT_SUCCESS);
}

Test(Display, Conc_1)
{
    char *val = conc("Hello ", "World");

    cr_assert_eq(my_strcmp(val, "Hello World"), EXIT_SUCCESS);
}

Test(Display, Conc_2)
{
    char *val = conc("", "World");

    cr_assert_eq(my_strcmp(val, "World"), EXIT_SUCCESS);
}

Test(Display, Conc_3)
{
    char *val = conc("", "");

    cr_assert_eq(my_strcmp(val, ""), EXIT_SUCCESS);
}
