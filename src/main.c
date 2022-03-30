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
    game->scenes = init_scenes();
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, event)) {
            if (analyse_event(game, event) == 0)
                return 0;
        }
        sfRenderWindow_clear(game->window, sfWhite);
        display(game, event);
        sfRenderWindow_display(game->window);
    }
    return 0;
}

int main (int ac, UNUSED char **argv)
{
    if (ac != 1)
        return 84;
    sfVideoMode mode = {1920, 1080, 32};
    sfEvent event;
    game_t *game = malloc(sizeof(game_t));
    game->window = sfRenderWindow_create(mode, "RPG no seed", sfFullscreen, NULL);
    game->settings = init_settings();
    sfRenderWindow_setFramerateLimit(game->window, 30);
    intro(game->window);
    rpg(game, &event);
    sfRenderWindow_destroy(game->window);
    return 0;
}
