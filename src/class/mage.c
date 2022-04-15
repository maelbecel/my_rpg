/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void mage(game_t *game, ...)
{
    reset(game);
    game->scenes->page = GAME;
}

void draw_mage_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/mage.json", "health");
    char *strength = parser("config/mage.json", "strength");
    char *speed = parser("config/mage.json", "speed");
    char *defense = parser("config/mage.json", "defense");

    if (!health || !strength || !speed || !defense)
        return;
    draw_text("MAGE", font, (sfVector3f){850, 760, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){850, 840, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){850, 880, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){850, 920, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){850, 960, 30}, window);
}