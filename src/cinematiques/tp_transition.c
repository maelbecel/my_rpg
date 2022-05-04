/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static sfCircleShape *init_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setPosition(circle, (sfVector2f){960, 540});
    sfCircleShape_setFillColor(circle, sfBlack);
    sfCircleShape_setRadius(circle, 1);
    return circle;
}

static void draw_game(game_t *game)
{
    for (int e = 0; game->scenes[GAME].elements[e];)
        draw_element(game->window, game->scenes[GAME].elements[e++]);
    display_npc(game);
    for (int b = 0; game->scenes[GAME].buttons[b];)
        draw_button(game->window, game->scenes[GAME].buttons[b++]);
}

static void draw_all(game_t *game, sfCircleShape *circle,
                                            sfVector2f pos, int radius)
{
    sfRenderWindow_clear(game->window, sfBlack);
    draw_game(game);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, radius);
    sfRenderWindow_drawCircleShape(game->window, circle, NULL);
    sfRenderWindow_display(game->window);

}

void transition(game_t *game, void func(game_t *game, ...))
{
    sfCircleShape *circle = init_circle();
    sfVector2f pos = {960, 540};
    int update = 10;

    for (int radius = 1; radius > 0;) {
        my_sleep(0.001, game->window);
        if (radius > 1920) {
            func(game);
            radius -= update;
            update *= -1;
        } else {
            radius += update;
            pos = (sfVector2f) {pos.x - update, pos.y - update};
        }
        draw_all(game, circle, pos, radius);
    }
    sfCircleShape_destroy(circle);
}
