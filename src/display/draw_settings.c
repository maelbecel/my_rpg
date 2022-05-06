/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"

static const struct key_s Key_list[] = {
    {sfKeyA, "A"},
    {sfKeyB, "B"},
    {sfKeyC, "C"},
    {sfKeyD, "D"},
    {sfKeyE, "E"},
    {sfKeyF, "F"},
    {sfKeyG, "G"},
    {sfKeyH, "H"},
    {sfKeyI, "I"},
    {sfKeyJ, "J"},
    {sfKeyK, "K"},
    {sfKeyL, "L"},
    {sfKeyM, "M"},
    {sfKeyN, "N"},
    {sfKeyO, "O"},
    {sfKeyP, "P"},
    {sfKeyQ, "Q"},
    {sfKeyR, "R"},
    {sfKeyS, "S"},
    {sfKeyT, "T"},
    {sfKeyU, "U"},
    {sfKeyV, "V"},
    {sfKeyW, "W"},
    {sfKeyX, "X"},
    {sfKeyY, "Y"},
    {sfKeyZ, "Z"},
    {sfKeyNum0, "0"},
    {sfKeyNum1, "1"},
    {sfKeyNum2, "2"},
    {sfKeyNum3, "3"},
    {sfKeyNum4, "4"},
    {sfKeyNum5, "5"},
    {sfKeyNum6, "6"},
    {sfKeyNum7, "7"},
    {sfKeyNum8, "8"},
    {sfKeyNum9, "9"},
    {sfKeyEscape, "ESCAPE"},
    {sfKeyLControl, "LEFT CONTROL"},
    {sfKeyLShift, "LEFT SHIFT"},
    {sfKeyLAlt, "LEFT ALT"},
    {sfKeyLSystem, "WINDOWS"},
    {sfKeyRControl, "RIGHT CONTROL"},
    {sfKeyRShift, "RIGHT SHIFT"},
    {sfKeyRAlt, "RIGHT ALT"},
    {sfKeyRSystem, "ALT GR"},
    {sfKeyMenu, "MENU"},
    {sfKeyLBracket, "{"},
    {sfKeyRBracket, "}"},
    {sfKeySemicolon, ";"},
    {sfKeyComma, ", "},
    {sfKeyPeriod, "."},
    {sfKeyQuote, "'"},
    {sfKeySlash, "/"},
    {sfKeyBackslash, "\\"},
    {sfKeyTilde, "~"},
    {sfKeyEqual, " = "},
    {sfKeySpace, "SPACE"},
    {sfKeyEnter, "ENTER"},
    {sfKeyBackspace, "TITLESPACE"},
    {sfKeyTab, "TAB"},
    {sfKeyPageUp, "PAGE UP"},
    {sfKeyPageDown, "PAGE DOWN"},
    {sfKeyEnd, "END"},
    {sfKeyHome, "HOME"},
    {sfKeyInsert, "INSERT"},
    {sfKeyDelete, "SUPPR"},
    {sfKeyAdd, "+"},
    {sfKeySubtract, "-"},
    {sfKeyMultiply, "*"},
    {sfKeyDivide, "/"},
    {sfKeyLeft, "LEFT ARROW"},
    {sfKeyRight, "RIGHT ARROW"},
    {sfKeyUp, "UP ARROW"},
    {sfKeyDown, "DOWN ARROW"},
    {sfKeyNumpad0, "NUMPAD 0"},
    {sfKeyNumpad1, "NUMPAD 1"},
    {sfKeyNumpad2, "NUMPAD 2"},
    {sfKeyNumpad3, "NUMPAD 3"},
    {sfKeyNumpad4, "NUMPAD 4"},
    {sfKeyNumpad5, "NUMPAD 5"},
    {sfKeyNumpad6, "NUMPAD 6"},
    {sfKeyNumpad7, "NUMPAD 7"},
    {sfKeyNumpad8, "NUMPAD 7"},
    {sfKeyNumpad9, "NUMPAD 8"},
    {sfKeyF1, "F1"},
    {sfKeyF2, "F2"},
    {sfKeyF3, "F3"},
    {sfKeyF4, "F4"},
    {sfKeyF5, "F5"},
    {sfKeyF6, "F6"},
    {sfKeyF7, "F7"},
    {sfKeyF8, "F8"},
    {sfKeyF9, "F9"},
    {sfKeyF10, "F10"},
    {sfKeyF11, "F11"},
    {sfKeyF12, "F12"},
    {sfKeyF13, "F13"},
    {sfKeyF14, "F14"},
    {sfKeyF15, "F15"},
    {sfKeyPause, "PAUSE"},
    {-1, "NULL"}
};

char *getkey(int key)
{
    size_t i = 0;

    for (; Key_list[i].key != -1; i++)
        if (Key_list[i].key == key)
            return Key_list[i].name;
    return Key_list[i].name;
}

char *conc(char *a, char *b)
{
    char *res = malloc(my_strlen(a) + my_strlen(b) + 1);
    int x = 0;

    if (!res)
        return NULL;
    for (int i = 0; i < my_strlen(a); i++, x++)
        res[x] = a[i];
    for (int i = 0; i < my_strlen(b); i++, x++)
        res[x] = b[i];
    res[x] = '\0';
    return res;
}

void concat_settings(game_t *game)
{
    sfVector2f pos = (sfVector2f){50, 50};

    set_vert(game);
    set_hori(game);
    set_othr(game);
    set_action(game);
    for (int i = 1; game->scenes[KEY].buttons[i];) {
        game->scenes[KEY].buttons[i]->base->text_pos = pos;
        game->scenes[KEY].buttons[i]->clicked->text_pos = pos;
        game->scenes[KEY].buttons[i++]->hoover->text_pos = pos;
    }
}
