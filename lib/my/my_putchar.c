/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
