/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void cuisiniere(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    char *health = parser("config/cuisiniere.json", "health");
    char *strength = parser("config/cuisiniere.json", "strength");
    char *speed = parser("config/cuisiniere.json", "speed");
    char *defense = parser("config/cuisiniere.json", "defense");

    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "new", "0");
    reset(game);
    game->scenes->page = GAME;
    free(file);
}

void draw_cuisiniere_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/cuisiniere.json", "health");
    char *strength = parser("config/cuisiniere.json", "strength");
    char *speed = parser("config/cuisiniere.json", "speed");
    char *defense = parser("config/cuisiniere.json", "defense");

    if (!health || !strength || !speed || !defense)
        return;
    draw_text("CHEF", font, (sfVector3f){350, 760, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){350, 840, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){350, 880, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){350, 920, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){350, 960, 30}, window);
}