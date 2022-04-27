/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int is_hoover_menu(game_t *game, int b, int s, int t)
{
    sfVector2f pos = game->scenes[s].tab[t].buttons[b]->pos;
    sfVector2f scale = game->scenes[s].tab[t].buttons[b]->base->scale;
    sfVector2u size = sfTexture_getSize(
                        game->scenes[s].tab[t].buttons[b]->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(game->window);
    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            game->scenes[s].tab[t].buttons[b]->action_hoover(game, b, t);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int is_click_menu(game_t *game, int b, int s, int t)
{
    if (!is_hoover_menu(game, b, s, t) || !sfRenderWindow_isOpen(game->window))
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}

int is_hoover(game_t *game, int b, int s)
{
    sfVector2f pos = game->scenes[s].buttons[b]->pos;
    sfVector2f scale = game->scenes[s].buttons[b]->base->scale;
    sfVector2u size = sfTexture_getSize(
                                game->scenes[s].buttons[b]->hoover->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(game->window);

    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x)) {
        if (click.y > pos.y && click.y < (pos.y + size.y)) {
            game->scenes[s].buttons[b]->action_hoover(game, b);
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int is_click(game_t *game, int b, int s)
{
    if (!is_hoover(game, b, s) || !sfRenderWindow_isOpen(game->window))
        return EXIT_SUCCESS;
    return EXIT_FAILURE;
}
