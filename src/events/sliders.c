/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int is_elem_hoover(game_t *game, int i)
{
    sfVector2f pos = game->scenes[SETTINGS_SOUNDS].elements[i]->pos;
    sfVector2f scale = game->scenes[SETTINGS_SOUNDS].elements[i]->scale;
    sfVector2u size = sfTexture_getSize(game->scenes[SETTINGS_SOUNDS].elements[i]->texture);
    sfVector2i click = sfMouse_getPositionRenderWindow(game->window);
    size.x *= scale.x;
    size.y *= scale.y;
    if (click.x > pos.x && click.x < (pos.x + size.x))
        if (click.y > pos.y && click.y < (pos.y + size.y))
            return 1;
    return 0;
}

void set_slider_pos(game_t * game)
{
    float pos_music = (float)game->settings->music_volume / 100.00 * game->scenes[SETTINGS_SOUNDS].elements[1]->rect.width + game->scenes[SETTINGS_SOUNDS].elements[1]->pos.x - 30;
    float pos_fx = (float)game->settings->fx_volume / 100.00 * game->scenes[SETTINGS_SOUNDS].elements[2]->rect.width + game->scenes[SETTINGS_SOUNDS].elements[2]->pos.x - 30;

    game->scenes[SETTINGS_SOUNDS].elements[3]->pos.x = pos_music;
    game->scenes[SETTINGS_SOUNDS].elements[4]->pos.x = pos_fx;
}

void move_slider(game_t *game, sfEvent *event)
{
    sfVector2i click = sfMouse_getPositionRenderWindow(game->window);
    sfRenderWindow_pollEvent(game->window, event);
    while (event->type == sfEvtMouseButtonPressed && is_elem_hoover(game, 1)) {
        click = sfMouse_getPositionRenderWindow(game->window);
        game->scenes[SETTINGS_SOUNDS].elements[3]->pos.x = (float)click.x - 30;
        draw_element(game->window, game->scenes[SETTINGS_SOUNDS].elements[3]);
        sfRenderWindow_pollEvent(game->window, event);
    }
    while (event->type == sfEvtMouseButtonPressed && is_elem_hoover(game, 2)) {
        click = sfMouse_getPositionRenderWindow(game->window);
        game->scenes[SETTINGS_SOUNDS].elements[4]->pos.x = (float)click.x - 30;
        draw_element(game->window, game->scenes[SETTINGS_SOUNDS].elements[3]);
        sfRenderWindow_pollEvent(game->window, event);
    }
    game->settings->music_volume = 100.00 * ((game->scenes[SETTINGS_SOUNDS].elements[3]->pos.x + 30 - game->scenes[SETTINGS_SOUNDS].elements[1]->pos.x) / game->scenes[SETTINGS_SOUNDS].elements[1]->rect.width);
    game->settings->fx_volume = 100.00 * ((game->scenes[SETTINGS_SOUNDS].elements[4]->pos.x + 30 - game->scenes[SETTINGS_SOUNDS].elements[2]->pos.x) / game->scenes[SETTINGS_SOUNDS].elements[2]->rect.width);

}