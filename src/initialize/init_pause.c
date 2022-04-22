/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void resume(game_t *game, ...)
{
    game->scenes->page = GAME;
}

void pause_menu(game_t *game, ...)
{
    game->scenes->page = PAUSE;
    my_printf("Go to pause\n");
}

element_t **pause_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 1);
    elements[0] = NULL;
    return elements;
}

void save(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));

    update_file(file, "posx",
                        inttochar(game->scenes[GAME].elements[0]->rect.left +
                                    game->scenes[GAME].elements[2]->pos.x));
    update_file(file, "posy",
                        inttochar(game->scenes[GAME].elements[0]->rect.top +
                                    game->scenes[GAME].elements[2]->pos.y));
    update_file(file, "health", inttochar(game->player->hp));
    update_file(file, "strength", inttochar(game->player->strg));
    update_file(file, "speed", inttochar(game->player->spd));
    update_file(file, "defense", inttochar(game->player->def));
    update_file(file, "point_stat", inttochar(game->player->pt_stat));
    update_inventory(game);
}

button_t **pause_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);
    buttons[0] = init_button("MAIN MENU", "assets/ui/button1.png",
                        (sfVector2f){550, 30}, (sfVector2i){300, 100});
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("SETTINGS", "assets/ui/button1.png",
                        (sfVector2f){550, 240}, (sfVector2i){300, 100});
    buttons[1]->action_clicked = settings;
    buttons[2] = init_button("QUIT", "assets/ui/button1.png",
                        (sfVector2f){550, 450}, (sfVector2i){300, 100});
    buttons[2]->action_clicked = quit;
    buttons[3] = init_button("RESUME", "assets/ui/button1.png",
                        (sfVector2f){550, 660}, (sfVector2i){300, 100});
    buttons[3]->action_clicked = resume;
    buttons[4] = init_button("SAVE", "assets/ui/button1.png",
                        (sfVector2f){550, 870}, (sfVector2i){300, 100});
    buttons[4]->action_clicked = save;
    buttons[5] = NULL;
    return buttons;
}
