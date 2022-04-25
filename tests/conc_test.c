/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "my.h"
#include "printf.h"
#include "rpg.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Display, Good_key)
{
    char *val = getkey(sfKeySpace);

    cr_assert_eq(my_strcmp(val, "SPACE"), EXIT_SUCCESS);
}

Test(Display, Bad_key)
{
    char *val = getkey(10000);

    cr_assert_eq(my_strcmp(val, "NULL"), EXIT_SUCCESS);
}

Test(Display, Conc_1)
{
    char *val = conc("Hello ", "World");

    cr_assert_eq(my_strcmp(val, "Hello World"), EXIT_SUCCESS);
}

Test(Display, Conc_2)
{
    char *val = conc("", "World");

    cr_assert_eq(my_strcmp(val, "World"), EXIT_SUCCESS);
}

Test(Display, Conc_3)
{
    char *val = conc("", "");

    cr_assert_eq(my_strcmp(val, ""), EXIT_SUCCESS);
}
