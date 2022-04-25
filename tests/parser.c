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

Test(Parser, New)
{
    char *val = parser("tests/test.json", "new");

    cr_assert_eq(my_strcmp(val, "0"), EXIT_SUCCESS);
}

