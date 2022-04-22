/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static void update_all_file(game_t *game, char *file)
{
    char *health = parser(CHEVALIER, "health");
    char *strength = parser(CHEVALIER, "strength");
    char *speed = parser(CHEVALIER, "speed");
    char *defense = parser(CHEVALIER, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(game->settings->font, "FAILED TO OPEN\nconfig/chevalier.json");
        return;
    }
    update_file(file, "health", health);
    update_file(file, "strength", strength);
    update_file(file, "speed", speed);
    update_file(file, "defense", defense);
    update_file(file, "class", conc(coat(), conc("chevalier", coat())));
    update_file(file, "new", "0");
    update_file(file, "inventory", conc("[",
                        conc(coat(), conc("sword", conc(coat(), "]")))));
}

void chevalier(game_t *game, ...)
{
    char *file = conc("saves/save", conc(game->player->save, ".json"));

    update_all_file(game, file);
    reset(game);
    game->scenes->page = GAME;
    sfTexture_destroy(game->scenes[GAME].elements[2]->texture);
    game->scenes[GAME].elements[2]->texture =
                                    sfTexture_createFromFile(KNIGHT_P, NULL);
    sfSprite_setTexture(game->scenes[GAME].elements[2]->sprite,
                            game->scenes[GAME].elements[2]->texture, sfFalse);
    set_player_inventory(game, file);
    free(file);
}

void draw_chevalier_char(sfRenderWindow *window, sfFont *font)
{
    char *health = parser(CHEVALIER, "health");
    char *strength = parser(CHEVALIER, "strength");
    char *speed = parser(CHEVALIER, "speed");
    char *defense = parser(CHEVALIER, "defense");

    if (!health || !strength || !speed || !defense) {
        popup(font, "FAILED TO OPEN\nconfig/chevalier.json");
        return;
    }
    draw_text("KNIGHT", font, (sfVector3f){1350, 240, 40}, window);
    draw_text(conc("HEALTH : ", health), font, (sfVector3f){1350, 320, 30},
                                                                    window);
    draw_text(conc("STRENGTH : ", strength), font, (sfVector3f){1350, 360, 30},
                                                                    window);
    draw_text(conc("SPEED : ", speed), font, (sfVector3f){1350, 400, 30},
                                                                    window);
    draw_text(conc("DEFENSE: ", defense), font, (sfVector3f){1350, 440, 30},
                                                                    window);
}
