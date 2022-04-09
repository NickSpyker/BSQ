/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** the_main.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include <stdio.h>

static void calc_nbrows_nbcols(data_t *data, char *buffer, int sizeof_buffer)
{
    int stop_count_cols = 0;
    int nb = 1;

    data->nb_rows = 1;
    data->nb_cols = 0;
    while (*buffer != '\n') {
        buffer++;
        nb++;
    }
    buffer++;
    for (int i = 0; i < sizeof_buffer - nb; i++) {
        if (buffer[i] == '\n') {
            data->nb_rows++;
            stop_count_cols = 1;
        }
        if (!stop_count_cols)
            data->nb_cols++;
    }
}

static void create_data(data_t *data, char *buffer)
{
    int i = 0;
    int k = 0;
    int sizeof_first_row = 0;

    data->map = mem_alloc_2d_array(data->nb_rows + 1, data->nb_cols);
    for (int sfr = 0; buffer[sfr] != '\n'; sfr++)
        sizeof_first_row++;
    sizeof_first_row++;
    data->map[0] = malloc(sizeof(char) * sizeof_first_row);
    for (int j = 0; buffer[j]; j++) {
        data->map[i][k] = buffer[j];
        k++;
        if (buffer[j] == '\n') {
            i++;
            k = 0;
        }
    }
}

int main(int argc, char *argv[])
{
    data_t data;
    struct stat var_stat;
    char *buffer;
    int fd;

    if (verif(argc, argv))
        return 84;
    fd = open(argv[1], O_RDONLY);
    stat(argv[1], &var_stat);
    buffer = malloc(sizeof(char) * (var_stat.st_size + 1));
    for (int i = 0; i < var_stat.st_size + 1; i++)
        buffer[i] = '\0';
    read(fd, buffer, var_stat.st_size);
    calc_nbrows_nbcols(&data, buffer, var_stat.st_size);
    create_data(&data, buffer);
    bsq(&data);
    free(buffer);
    close(fd);
    return 0;
}
