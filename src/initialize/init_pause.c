/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

int resume(game_t *game, ...)
{
    game->scenes->page = GAME;
    return EXIT_SUCCESS;
}

int pause_menu(game_t *game, ...)
{
    game->scenes->page = PAUSE;
    return EXIT_SUCCESS;
}

element_t **pause_elements(void)
{
    element_t **elements = malloc(sizeof(element_t *) * 1);

    if (!elements)
        return NULL;
    elements[0] = NULL;
    return elements;
}

int save(game_t *game, ...)
{
    char *file = format("saves/save%s.json", game->player->save);
    char *posx = inttochar(game->scenes[GAME].elements[0]->rect.left +
                                    game->scenes[GAME].elements[2]->pos.x);
    char *posy = inttochar(game->scenes[GAME].elements[0]->rect.top +
                                    game->scenes[GAME].elements[2]->pos.y);
    char *map = inttochar(game->player->map);
    char *hp = inttochar(game->player->hp);
    char *strg = inttochar(game->player->strg);
    char *spd = inttochar(game->player->spd);
    char *def = inttochar(game->player->def);
    char *pt = inttochar(game->player->pt_stat);
    char *xp = inttochar(game->player->xp);

    update_file(file, "posx", posx);
    update_file(file, "posy", posy);
    update_file(file, "map", map);
    update_file(file, "health", hp);
    update_file(file, "strength", strg);
    update_file(file, "speed", spd);
    update_file(file, "defense", def);
    update_file(file, "point_stat", pt);
    update_file(file, "xp", xp);
    update_inventory(game);
    free(file);
    free(map);
    free(hp);
    free(strg);
    free(spd);
    free(def);
    free(pt);
    free(xp);
    return EXIT_SUCCESS;
}

button_t **pause_buttons(void)
{
    button_t **buttons = malloc(sizeof(button_t *) * 6);
    sfVector2i size = {300, 100};

    if (!buttons)
        return NULL;
    buttons[0] = init_button("MAIN MENU", BUTTON, (sfVector2f){550, 30}, size);
    buttons[0]->action_clicked = main_menu;
    buttons[1] = init_button("SETTINGS", BUTTON, (sfVector2f){550, 240}, size);
    buttons[1]->action_clicked = settings;
    buttons[2] = init_button("QUIT", BUTTON, (sfVector2f){550, 450}, size);
    buttons[2]->action_clicked = quit;
    buttons[3] = init_button("RESUME", BUTTON, (sfVector2f){550, 660}, size);
    buttons[3]->action_clicked = resume;
    buttons[4] = init_button("SAVE", BUTTON, (sfVector2f){550, 870}, size);
    buttons[4]->action_clicked = save;
    buttons[5] = NULL;
    return buttons;
}
