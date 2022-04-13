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
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (analyse_event(game, event) == 0)
                return 0;
            event_menu_player(game, event);
        }
        sfRenderWindow_clear(game->window, sfWhite);
        display(game, event);
        sfRenderWindow_display(game->window);
    }
    return 0;
}

game_t *init_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game = malloc(sizeof(game_t));

    game->settings = init_settings();
    game->window = sfRenderWindow_create(mode, "RPG no seed",
                                                        sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    intro(game->window);
    game->scenes = init_scenes(game->window);
    game->player = init_player("chevalier");
    return game;
}

int main (int ac, UNUSED char **argv)
{
    if (ac != 1)
        return 84;
    sfEvent event;
    game_t *game = init_game();
    rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    return 0;
}
