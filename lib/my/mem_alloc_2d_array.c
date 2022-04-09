/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-nicolas.spijkerman
** File description:
** mem _a lloc_2d_array.c
*/

#include <stdlib.h>

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **result;

    result = (char**)malloc(sizeof(char*) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++)
        result[i] = (char*)malloc(sizeof(char) * (nb_cols + 1));
    return result;
}
