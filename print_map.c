/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** print_map.c
*/

#include "include/my.h"
#include <unistd.h>

static void draw_squar(data_t *data)
{
    int row = data->max_size_loc_r;
    int col = data->max_size_loc_c;
    int size = data->max_size;

    for (int x = row; x < (row + size); x++)
        for (int y = col; y < (col + size); y++)
            data->map[x][y] = 'x';
}

void print_map(data_t *data)
{
    draw_squar(data);
    for (int i = 1; i < data->nb_rows; i++)
        write(1, data->map[i], my_strlen(data->map[i]));
}
