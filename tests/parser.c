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

// Test(Parser, Bad_file)
// {
//     char *val = parser("badfile.json", "new");

//     cr_assert_eq((val == NULL) ? 0 : 1, EXIT_SUCCESS);
// }

// Test(Parser, Bad_value)
// {
//     char *val = parser("tests/test.json", "badvalue");

//     cr_assert_eq((val == NULL) ? 0 : 1, EXIT_SUCCESS);
// }
