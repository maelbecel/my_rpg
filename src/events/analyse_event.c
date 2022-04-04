/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int analyse_event(UNUSED game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed )
        return 0;
    if (event->key.code == sfKeyEscape)
        return 0;
    return 1;
}

void analyse_game(game_t *game, UNUSED sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(game->settings->key_down)) {
        if (game->scenes[GAME].elements[1]->pos.y > 680)
            game->scenes[GAME].elements[0]->rect.top += 5;
        else
            game->scenes[GAME].elements[1]->pos.y += 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_up)) {
        if (game->scenes[GAME].elements[1]->pos.y < 200)
            game->scenes[GAME].elements[0]->rect.top -= 5;
        else
            game->scenes[GAME].elements[1]->pos.y -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_left)) {
        if (game->scenes[GAME].elements[1]->pos.x < 200)
            game->scenes[GAME].elements[0]->rect.left -= 5;
        else
            game->scenes[GAME].elements[1]->pos.x -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_right)) {
        if (game->scenes[GAME].elements[1]->pos.x > 1520)
            game->scenes[GAME].elements[0]->rect.left += 5;
        else
            game->scenes[GAME].elements[1]->pos.x += 5;
    }
    if (event->key.code == game->settings->key_menu && game->scenes->page == GAME) {
        menu_event(game);
    }
    sfSprite_setTextureRect(game->scenes[GAME].elements[0]->sprite, game->scenes[GAME].elements[0]->rect);
}
