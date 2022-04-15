/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void valkyrie(game_t *game, ...)
{
    reset(game);
    game->scenes->page = GAME;
}

void draw_valkyrie_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/valkyrie.json", "health");
    char *strength = parser("config/valkyrie.json", "strength");
    char *speed = parser("config/valkyrie.json", "speed");
    char *defense = parser("config/valkyrie.json", "defense");

    if (!health || !strength || !speed || !defense)
        return;
    draw_text("VALKYRIE", font, (sfVector3f){1350, 760, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){1350, 840, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){1350, 880, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){1350, 920, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){1350, 960, 30}, window);
}