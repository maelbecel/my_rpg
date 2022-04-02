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
        if (game->scenes[1].elements[1]->pos.y > 800)
            game->scenes[1].elements[0]->rect.top += 5;
        else
            game->scenes[1].elements[1]->pos.y += 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_up)) {
        if (game->scenes[1].elements[1]->pos.y < 150)
            game->scenes[1].elements[0]->rect.top -= 5;
        else
            game->scenes[1].elements[1]->pos.y -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_left)) {
        if (game->scenes[1].elements[1]->pos.x < 150)
            game->scenes[1].elements[0]->rect.left -= 5;
        else
            game->scenes[1].elements[1]->pos.x -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_right)) {
        if (game->scenes[1].elements[1]->pos.x > 1500)
            game->scenes[1].elements[0]->rect.left += 5;
        else
            game->scenes[1].elements[1]->pos.x += 5;
    }
    sfSprite_setTextureRect(game->scenes[1].elements[0]->sprite, game->scenes[1].elements[0]->rect);
}
