/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static int rpg(game_t *game, sfEvent *event)
{
    sfClock *fps = sfClock_create();
    sfTime frame;

    while (sfRenderWindow_isOpen(game->window)) {
        frame = sfClock_getElapsedTime(fps);
        sfClock_restart(fps);
        while (sfRenderWindow_pollEvent(game->window, event)) {
            analyse_game_state(game, event, frame);
        }
        if (sfRenderWindow_isOpen(game->window) &&
            game->scenes->page == GAME) {
            display(game, event);
            draw_fps(frame, game);
            sfRenderWindow_display(game->window);
        }
    }
    return EXIT_SUCCESS;
}

static int do_intro(game_t *game)
{
    if (intro(game->window, -4, 249) == EXIT_FAILURE) {
        free(game);
        return EXIT_FAILURE;
    }
    sfRenderWindow_setFramerateLimit(game->window, 0);
    if (!(game->scenes= init_scenes(game->window)))
        return EXIT_FAILURE;
    game->scenes[GAME].npc = game_npc();
    sfRenderWindow_setFramerateLimit(game->window,
                        int_from_json(CONFIG_FILE, "framerate"));
    game->player = init_player("chevalier");
    game->hitbox = sfImage_createFromFile(HITBOX);
    return EXIT_SUCCESS;
}

static game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return NULL;
    game->settings = init_settings();
    if (!game->settings || check_set(game->settings) == EXIT_FAILURE) {
        free(game);
        return NULL;
    }
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    if (!game->window) {
        free(game);
        return NULL;
    }
    sfRenderWindow_setFramerateLimit(game->window, 31);
    game->is_inv = false;
    if (do_intro(game) == EXIT_FAILURE)
        return NULL;
    return game;
}

int main(int ac, UNUSED char **argv)
{
    int exit_code = EXIT_SUCCESS;
    sfEvent event;
    game_t *game = init_game();

    if (ac != 1)
        return EXIT_ERROR;
    if (!game)
        return EXIT_ERROR;
    exit_code = rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    free_all(game);
    free(game);
    return exit_code;
}
