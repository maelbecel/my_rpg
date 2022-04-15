/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void archere(game_t *game, ...)
{
    reset(game);
    game->scenes->page = GAME;
}

void draw_archere_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/archere.json", "health");
    char *strength = parser("config/archere.json", "strength");
    char *speed = parser("config/archere.json", "speed");
    char *defense = parser("config/archere.json", "defense");

    if (!health || !strength || !speed || !defense)
        return;
    draw_text("ARCHER", font, (sfVector3f){850, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){850, 320, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){850, 360, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){850, 400, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){850, 440, 30}, window);
}