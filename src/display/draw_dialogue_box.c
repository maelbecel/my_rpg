/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** function that draw dialogue box
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_dialogue_box(sfRenderWindow *window, char *str, sfFont *font)
{
    sfText *text_pop = sfText_create();
    sfVector2f pos = {140, 820};
    element_t *pop = init_element(BUTTON,
        (sfVector2f){50, 750}, (sfVector2f){792, 206}, (sfVector2f){2.3, 1.5});

    sfText_setString(text_pop, str);
    sfText_setFont(text_pop, font);
    sfText_setColor(text_pop, sfBlack);
    sfText_setCharacterSize(text_pop, 50);
    sfText_setPosition(text_pop, pos);
    draw_element(window, pop);
    sfRenderWindow_drawText(window, text_pop, NULL);
    sfText_destroy(text_pop);
    free_elements(pop);
}
