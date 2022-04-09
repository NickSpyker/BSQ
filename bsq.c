/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** bsq.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include <stdio.h>

static void verif_size(data_t *data, int size, loc_t loc)
{
    if (data->max_size < size - 1) {
        size -= 1;
        data->max_size = size;
        data->max_size_loc_c = loc.col;
        data->max_size_loc_r = loc.row;
    }
}

static int check_right(data_t *data, int x, int y, int nb_of_check)
{
    for (int i = nb_of_check; i > 0; i--) {
        if (data->map[x][y] != '.')
            return 0;
        if (y != data->nb_cols)
            y++;
    }
    return 1;
}

static int check_down(data_t *data, int x, int y, int nb_of_check)
{
    int nb_check = nb_of_check;

    for (int i = nb_of_check; i > 0; i--) {
        if (data->map[x][y] != '.')
            return 0;
        if (!check_right(data, x, y, nb_check))
            return 0;
        if (x != data->nb_rows)
            x++;
    }
    return 1;
}

static void bsq_rec(loc_t loc, data_t *data)
{
    int size = 1;

    while (1) {
        if (check_right(data, loc.row, loc.col, size) &&
            check_down(data, loc.row, loc.col, size))
            size++;
        else {
            verif_size(data, size, loc);
            break;
        }
    }
}

void bsq(data_t *data)
{
    loc_t loc;

    data->max_size = 0;
    for (loc.row = 1; loc.row <= data->nb_rows; loc.row++)
        for (loc.col = 0; loc.col < data->nb_cols; loc.col++)
            bsq_rec(loc, data);
    print_map(data);
}
