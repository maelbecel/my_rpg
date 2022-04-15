/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void arbaletier(game_t *game, ...)
{
    char *file = conc("config/save", conc(game->player->save, ".json"));
    char *health = parser("config/arbaletier.json", "health");
    char *strength = parser("config/arbaletier.json", "strength");
    char *speed = parser("config/arbaletier.json", "speed");
    char *defense = parser("config/arbaletier.json", "defense");

    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "new", "0");
    reset(game);
    game->scenes->page = GAME;
    free(file);
}

void draw_arbaletier_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/arbaletier.json", "health");
    char *strength = parser("config/arbaletier.json", "strength");
    char *speed = parser("config/arbaletier.json", "speed");
    char *defense = parser("config/arbaletier.json", "defense");

    if (!health || !strength || !speed || !defense)
        return;
    draw_text("CROSSBOWMAN", font, (sfVector3f){260, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){350, 320, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){350, 360, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){350, 400, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){350, 440, 30}, window);
}