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

void analyse_game(game_t *game, UNUSED sfEvent *event)
{
    if (sfKeyboard_isKeyPressed(game->settings->key_down)) {
        move_down(game);
    } if (sfKeyboard_isKeyPressed(game->settings->key_up)) {
        move_up(game);
    } if (sfKeyboard_isKeyPressed(game->settings->key_left)) {
        move_left(game);
    } if (sfKeyboard_isKeyPressed(game->settings->key_right)) {
        move_right(game);
    }
    sfSprite_setTextureRect(game->scenes[GAME].elements[0]->sprite,
                            game->scenes[GAME].elements[0]->rect);
}
