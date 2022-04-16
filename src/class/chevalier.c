/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void chevalier(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));
    char *health = parser("config/chevalier.json", "health");
    char *strength = parser("config/chevalier.json", "strength");
    char *speed = parser("config/chevalier.json", "speed");
    char *defense = parser("config/chevalier.json", "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/chevalier.json");
        return;
    }
    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "new", "0");
    reset(game);
    game->scenes->page = GAME;
    free(file);
}

void draw_chevalier_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser("config/chevalier.json", "health");
    char *strength = parser("config/chevalier.json", "strength");
    char *speed = parser("config/chevalier.json", "speed");
    char *defense = parser("config/chevalier.json", "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/chevalier.json");
        return;
    }
    draw_text("KNIGHT", font, (sfVector3f){1350, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){1350, 320, 30}, window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){1350, 360, 30}, window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){1350, 400, 30}, window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){1350, 440, 30}, window);
}