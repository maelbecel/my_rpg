/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void set_vert(game_t *game)
{
    sfText_setString(game->scenes[KEY].buttons[1]->base->text,
                                conc("UP : ", getkey(game->settings->key_up)));
    sfText_setString(game->scenes[KEY].buttons[1]->hoover->text,
                                conc("UP : ", getkey(game->settings->key_up)));
    sfText_setString(game->scenes[KEY].buttons[1]->clicked->text,
                                conc("UP : ", getkey(game->settings->key_up)));
    sfText_setString(game->scenes[KEY].buttons[2]->base->text,
                            conc("DOWN : ", getkey(game->settings->key_down)));
    sfText_setString(game->scenes[KEY].buttons[2]->hoover->text,
                            conc("DOWN : ", getkey(game->settings->key_down)));
    sfText_setString(game->scenes[KEY].buttons[2]->clicked->text,
                            conc("DOWN : ", getkey(game->settings->key_down)));
}

void set_hori(game_t *game)
{
    sfText_setString(game->scenes[KEY].buttons[3]->base->text,
                            conc("LEFT : ", getkey(game->settings->key_left)));
    sfText_setString(game->scenes[KEY].buttons[3]->hoover->text,
                            conc("LEFT : ", getkey(game->settings->key_left)));
    sfText_setString(game->scenes[KEY].buttons[3]->clicked->text,
                            conc("LEFT : ", getkey(game->settings->key_left)));
    sfText_setString(game->scenes[KEY].buttons[4]->base->text,
                        conc("RIGHT : ", getkey(game->settings->key_right)));
    sfText_setString(game->scenes[KEY].buttons[4]->hoover->text,
                        conc("RIGHT : ", getkey(game->settings->key_right)));
    sfText_setString(game->scenes[KEY].buttons[4]->clicked->text,
                        conc("RIGHT : ", getkey(game->settings->key_right)));
}

void set_othr(game_t *game)
{
    sfText_setString(game->scenes[KEY].buttons[5]->base->text,
                        conc("PAUSE : ", getkey(game->settings->key_pause)));
    sfText_setString(game->scenes[KEY].buttons[5]->hoover->text,
                        conc("PAUSE : ", getkey(game->settings->key_pause)));
    sfText_setString(game->scenes[KEY].buttons[5]->clicked->text,
                        conc("PAUSE : ", getkey(game->settings->key_pause)));
    sfText_setString(game->scenes[KEY].buttons[6]->base->text,
                            conc("MENU : ", getkey(game->settings->key_menu)));
    sfText_setString(game->scenes[KEY].buttons[6]->hoover->text,
                            conc("MENU : ", getkey(game->settings->key_menu)));
    sfText_setString(game->scenes[KEY].buttons[6]->clicked->text,
                            conc("MENU : ", getkey(game->settings->key_menu)));
}

void set_action(game_t *game)
{
    sfText_setString(game->scenes[KEY].buttons[7]->base->text,
                        conc("SKIP : ", getkey(game->settings->key_skip)));
    sfText_setString(game->scenes[KEY].buttons[7]->hoover->text,
                        conc("SKIP : ", getkey(game->settings->key_skip)));
    sfText_setString(game->scenes[KEY].buttons[7]->clicked->text,
                        conc("SKIP : ", getkey(game->settings->key_skip)));
    sfText_setString(game->scenes[KEY].buttons[8]->base->text,
                        conc("ACTION : ", getkey(game->settings->key_action)));
    sfText_setString(game->scenes[KEY].buttons[8]->hoover->text,
                        conc("ACTION : ", getkey(game->settings->key_action)));
    sfText_setString(game->scenes[KEY].buttons[8]->clicked->text,
                        conc("ACTION : ", getkey(game->settings->key_action)));
}
