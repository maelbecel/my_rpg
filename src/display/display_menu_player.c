/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_menu_player
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void display_button_menu_player(game_t *game, sfEvent *event, int nb)
{
    for (int b = 0; game->scenes[MENU_PLAYER].buttons[b]; b++) {
        if (event->type == sfEvtMouseButtonPressed &&
            is_click(game, b, MENU_PLAYER) && b != nb) {
            draw_clicked(game->window, game->scenes[MENU_PLAYER].buttons[b]);
            game->scenes[MENU_PLAYER].buttons[b]->action_clicked(game, b);
        } else if (is_hoover(game, b, MENU_PLAYER) && b != nb)
            draw_hoover(game->window, game->scenes[MENU_PLAYER].buttons[b]);
        else
            draw_button(game->window, game->scenes[MENU_PLAYER].buttons[b]);
    }
}

int get_level(int xp)
{
    int level = 1;

    for (; xp >= 500 * level * level; level++);
    return (level);
}

void display_player(game_t *game, sfEvent *event)
{
    char *hp = inttochar(game->player->hp);
    char *strg = inttochar(game->player->strg);
    char *spd = inttochar(game->player->spd);
    char *def = inttochar(game->player->def);
    char *lvl = inttochar(game->player->def);
    char *xp = inttochar(game->player->xp);

    for (int e = 0; game->scenes[MENU_PLAYER].elements[e]; e++)
        draw_element(game->window, game->scenes[MENU_PLAYER].elements[e]);
    display_button_menu_player(game, event, 0);
    draw_text(conc("HP : ", hp), game->settings->font,
                                    (sfVector3f){100, 150, 40}, game->window);
    draw_text(conc("STRENGHT : ", strg),
            game->settings->font, (sfVector3f){100, 250, 40}, game->window);
    draw_text(conc("SPEED : ", spd),
            game->settings->font, (sfVector3f){100, 350, 40}, game->window);
    draw_text(conc("DEFENSE : ", def),
            game->settings->font, (sfVector3f){100, 450, 40}, game->window);
    draw_text(conc("Level : ", lvl),
            game->settings->font, (sfVector3f){100, 550, 40}, game->window);
    draw_text(conc("Total XP : ", xp),
            game->settings->font, (sfVector3f){100, 650, 40}, game->window);
    draw_xp_bar(game);
    free(hp);
    free(strg);
    free(spd);
    free(def);
    free(lvl);
    free(xp);
}

void draw_stat_char(game_t *game)
{
    char *hp = inttochar(game->player->hp);
    char *strg = inttochar(game->player->strg);
    char *spd = inttochar(game->player->spd);
    char *def = inttochar(game->player->def);
    char *pt = inttochar(game->player->pt_stat);

    draw_text(conc("HP : ", hp),
            game->settings->font, (sfVector3f){100, 200, 40}, game->window);
    draw_text(conc("STRENGHT : ", strg),
            game->settings->font, (sfVector3f){100, 300, 40}, game->window);
    draw_text(conc("SPEED : ", spd),
            game->settings->font, (sfVector3f){100, 400, 40}, game->window);
    draw_text(conc("DEFENSE : ", def),
            game->settings->font, (sfVector3f){100, 500, 40}, game->window);
    draw_text(conc("POINT STAT : ", pt),
            game->settings->font, (sfVector3f){100, 600, 40}, game->window);
    free(hp);
    free(strg);
    free(spd);
    free(def);
    free(pt);
}
