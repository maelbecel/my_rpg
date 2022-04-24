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

Test(my_printf, test_my_printf_1)
{
    my_printf("%s", "Hello");
    cr_assert_stdout_eq_str("Hello");
}