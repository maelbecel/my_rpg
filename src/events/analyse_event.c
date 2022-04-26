/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** analyse_event
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void set_pause(game_t *game)
{
    game->scenes[SETTINGS].buttons[0]->action_clicked = pause_menu;
    sfText_setString(game->scenes[SETTINGS].buttons[0]->base->text,
                                                                "PAUSE MENU");
    sfText_setString(game->scenes[SETTINGS].buttons[0]->clicked->text,
                                                                "PAUSE MENU");
    sfText_setString(game->scenes[SETTINGS].buttons[0]->hoover->text,
                                                                "PAUSE MENU");
}

static void set_menu(game_t *game)
{
    game->scenes[SETTINGS].buttons[0]->action_clicked = main_menu;
    sfText_setString(game->scenes[SETTINGS].buttons[0]->base->text,
                                                                "MAIN MENU");
    sfText_setString(game->scenes[SETTINGS].buttons[0]->clicked->text,
                                                                "MAIN MENU");
    sfText_setString(game->scenes[SETTINGS].buttons[0]->hoover->text,
                                                                "MAIN MENU");
}

int analyse_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed )
        return EXIT_SUCCESS;
    if (event->type == sfEvtKeyPressed &&
        event->key.code == game->settings->key_pause &&
        game->scenes->page == GAME)
        game->scenes->page = PAUSE;
    else if (event->type == sfEvtKeyPressed &&
            event->key.code == game->settings->key_pause &&
            game->scenes->page == PAUSE)
        game->scenes->page = GAME;
    if (game->scenes->page == MAIN_MENU) {
        set_menu(game);
    } if (event->type == sfEvtKeyPressed &&
        event->key.code == game->settings->key_menu &&
        (game->scenes->page == GAME || game->scenes->page == MENU_PLAYER)) {
        menu_event(game);
        return EXIT_FAILURE;
    } if (game->scenes->page == PAUSE)
        set_pause(game);
    return EXIT_FAILURE;
}

void analyse_game(game_t *game, UNUSED sfEvent *event)
{
    sfTime time = sfClock_getElapsedTime(game->player->timer);

    if (time.microseconds > 40000) {
        if (sfKeyboard_isKeyPressed(game->settings->key_down)) {
            move_down(game);
        } if (sfKeyboard_isKeyPressed(game->settings->key_up)) {
            move_up(game);
        } if (sfKeyboard_isKeyPressed(game->settings->key_left)) {
            move_left(game);
        } if (sfKeyboard_isKeyPressed(game->settings->key_right)) {
            move_right(game);
        }
        game->scenes[GAME].elements[5]->rect = game->scenes[GAME].elements[0]->rect;
        game->scenes[GAME].elements[6]->rect = game->scenes[GAME].elements[0]->rect;
        sfSprite_setTextureRect(game->scenes[GAME].elements[6]->sprite,
                                game->scenes[GAME].elements[6]->rect);
        sfSprite_setTextureRect(game->scenes[GAME].elements[5]->sprite,
                                game->scenes[GAME].elements[5]->rect);
        sfSprite_setTextureRect(game->scenes[GAME].elements[0]->sprite,
                                game->scenes[GAME].elements[0]->rect);
        sfClock_restart(game->player->timer);
    }
}

void analyse_game_state(game_t *game, sfEvent *event, sfTime frame)
{
    (void)frame;
    if (analyse_event(game, event) == 0)
        return;
    if (game->scenes->page != GAME) {
        display(game, event);
        sfRenderWindow_display(game->window);
    }
}
