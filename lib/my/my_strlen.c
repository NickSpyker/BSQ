/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_strlen.c
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}
