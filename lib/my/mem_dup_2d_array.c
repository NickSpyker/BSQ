/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-bsbsq-nicolas.spijkerman
** File description:
** mem_dup_2d_array.c
*/

#include <stdlib.h>
#include "../../include/my.h"

char **mem_dup_2d_array(char **arr, int nb_rows, int nb_cols)
{
    char **result = mem_alloc_2d_array(nb_rows, nb_cols);

    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++)
            result[i][j] = arr[i][j];
        result[i][nb_cols] = '\0';
    }
    result[nb_rows] = 0;
    return result;
}
