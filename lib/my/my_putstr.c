/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return 0;
}
