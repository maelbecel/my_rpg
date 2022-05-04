/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->base->sprite, button->pos);
    sfText_setColor(button->base->text, sfBlack);
    sfText_setFont(button->base->text, button->base->font);
    sfText_setCharacterSize(button->base->text, button->base->text_size);
    sfText_setPosition(button->base->text,
        (sfVector2f){button->pos.x + button->base->text_pos.x,
                    button->pos.y + button->base->text_pos.y});
    sfSprite_setScale(button->base->sprite, button->base->scale);
    sfRenderWindow_drawSprite(window, button->base->sprite, NULL);
    sfRenderWindow_drawText(window, button->base->text, NULL);

}

void draw_hoover(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->hoover->sprite, button->pos);
    sfText_setColor(button->hoover->text, sfBlack);
    sfText_setFont(button->hoover->text, button->hoover->font);
    sfText_setCharacterSize(button->hoover->text, button->hoover->text_size);
    sfText_setPosition(button->hoover->text,
        (sfVector2f){button->pos.x + button->hoover->text_pos.x,
                    button->pos.y + button->hoover->text_pos.y});
    sfSprite_setScale(button->hoover->sprite, button->hoover->scale);
    sfRenderWindow_drawSprite(window, button->hoover->sprite, NULL);
    sfRenderWindow_drawText(window, button->hoover->text, NULL);
}

void draw_clicked(sfRenderWindow *window, button_t *button)
{
    sfSprite_setPosition(button->clicked->sprite, button->pos);
    sfText_setColor(button->clicked->text, sfBlack);
    sfText_setFont(button->clicked->text, button->clicked->font);
    sfText_setCharacterSize(button->clicked->text, button->clicked->text_size);
    sfText_setPosition(button->clicked->text,
        (sfVector2f){button->pos.x + button->clicked->text_pos.x,
                    button->pos.y + button->clicked->text_pos.y});
    sfSprite_setScale(button->clicked->sprite, button->clicked->scale);
    sfRenderWindow_drawSprite(window, button->clicked->sprite, NULL);
    sfRenderWindow_drawText(window, button->clicked->text, NULL);
}

int draw_text(char *text, sfFont *font,
                                    sfVector3f pos, sfRenderWindow *window)
{
    sfText *score = sfText_create();

    if (!score)
        return EXIT_FAILURE;
    sfText_setColor(score, sfBlack);
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, pos.z);
    sfText_setPosition(score, (sfVector2f){pos.x, pos.y});
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    return EXIT_SUCCESS;
}

void draw_element(sfRenderWindow *window, element_t *element)
{
    sfSprite_setTextureRect(element->sprite, element->rect);
    sfSprite_setPosition(element->sprite, element->pos);
    sfSprite_setScale(element->sprite, element->scale);
    sfRenderWindow_drawSprite(window, element->sprite, NULL);
}
