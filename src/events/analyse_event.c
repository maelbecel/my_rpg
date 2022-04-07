/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int analyse_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed )
        return 0;
    if (event->type == sfEvtKeyPressed &&
        event->key.code == game->settings->key_pause &&
        game->scenes->page == GAME)
        game->scenes->page = PAUSE;
    else if (event->type == sfEvtKeyPressed &&
            event->key.code == game->settings->key_pause &&
            game->scenes->page == PAUSE)
        game->scenes->page = GAME;
    if (game->scenes->page == MAIN_MENU) {
        game->scenes[SETTINGS].buttons[0]->action_clicked = main_menu;
        sfText_setString(game->scenes[SETTINGS].buttons[0]->base->text,
                                                                "MAIN MENU");
        sfText_setString(game->scenes[SETTINGS].buttons[0]->clicked->text,
                                                                "MAIN MENU");
        sfText_setString(game->scenes[SETTINGS].buttons[0]->hoover->text,
                                                                "MAIN MENU");
    } if (game->scenes->page == PAUSE) {
        game->scenes[SETTINGS].buttons[0]->action_clicked = pause_menu;
        sfText_setString(game->scenes[SETTINGS].buttons[0]->base->text,
                                                                "PAUSE MENU");
        sfText_setString(game->scenes[SETTINGS].buttons[0]->clicked->text,
                                                                "PAUSE MENU");
        sfText_setString(game->scenes[SETTINGS].buttons[0]->hoover->text,
                                                                "PAUSE MENU");
    } if (event->type == sfEvtKeyPressed &&
        event->key.code == game->settings->key_menu &&
        (game->scenes->page == GAME || game->scenes->page == MENU_PLAYER)) {
        menu_event(game);
        return 1;
    }
    return 1;
}

void analyse_game(game_t *game, UNUSED sfEvent *event, UNUSED pos_perso_t *pos_perso)
{
    if (sfKeyboard_isKeyPressed(game->settings->key_down)) {
        if (game->scenes[GAME].elements[2]->pos.y > 680) {
            game->scenes[GAME].elements[0]->rect.top += 6;
            game->scenes[GAME].elements[1]->rect.top += 30;
        } else
            game->scenes[GAME].elements[2]->pos.y += 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_up)) {
        if (game->scenes[GAME].elements[2]->pos.y < 200) {
            game->scenes[GAME].elements[1]->rect.top -= 30;
            game->scenes[GAME].elements[0]->rect.top -= 6;
        } else
            game->scenes[GAME].elements[2]->pos.y -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_left)) {
        if (game->scenes[GAME].elements[2]->pos.x < 200) {
            game->scenes[GAME].elements[0]->rect.left -= 6;
            game->scenes[GAME].elements[1]->rect.left -= 40;
        } else
            game->scenes[GAME].elements[2]->pos.x -= 5;
    } if (sfKeyboard_isKeyPressed(game->settings->key_right)) {
        if (game->scenes[GAME].elements[2]->pos.x > 1520) {
            game->scenes[GAME].elements[1]->rect.left += 40;
            game->scenes[GAME].elements[0]->rect.left += 6;
        } else
            game->scenes[GAME].elements[2]->pos.x += 5;
    }
    sfSprite_setTextureRect(game->scenes[GAME].elements[0]->sprite,
                            game->scenes[GAME].elements[0]->rect);
}
