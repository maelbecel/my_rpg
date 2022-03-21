/*
** EPITECH PROJECT, 2021
** star.c
** File description:
** star.c
*/

#ifndef PRINTF_H_
    #define PRINTF_H_
    #include <stdarg.h>
    #include <unistd.h>

    int displaychar(va_list argv);
    int displaystr(va_list argv);
    int displaynbr(va_list argv);
    int displaynbr_long(va_list argv);
    int displaybinary(va_list argv);
    int displaypercent(va_list argv);
    int displaypointer(va_list argv);
    int displaynbr_hexa(va_list argv);
    int displaynbr_hexa_capital(va_list argv);
    int displaystr_unprintable(va_list argv);
    int displaynbr_dec(va_list argv);
    int displaynbr_octal(va_list argv);
    int displaynbr_octal_hashtag(va_list argv);
    int displaynbr_hexa_hashtag(va_list argv);
    int displaynbr_hexa_capital_hashtag(va_list argv);
    int my_printf(char const *str, ...);

    struct flags {
        int(*func)(va_list);
        char flag;
    };

#endif
