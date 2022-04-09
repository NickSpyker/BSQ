/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** verif.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include <stdio.h>

static int error(void)
{
    write(2, "error\n", 6);
    return 1;
}

static int check_num(char **buffer)
{
    while (**buffer != '\n') {
        if (**buffer < '0' || '9' < **buffer)
            return 1;
        (*buffer)++;
    }
    (*buffer)++;
    return 0;
}

static int verif_map(char *buffer)
{
    if (check_num(&buffer))
        return 1;
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] != '.' && buffer[i] != 'o' &&
            buffer[i] != '\n' && buffer[i] != '\0')
            return 1;
    return 0;
}

static int verif_size(char *buffer)
{
    char *nb_lines;
    int real_nb_lines = 0;
    int size = 0;
    int loop = 0;

    for (int i = 0; buffer[i] != '\n'; i++)
        size++;
    nb_lines = malloc(sizeof(char) * (size + 1));
    nb_lines[size + 1] = '\0';
    while (*buffer != '\n') {
        nb_lines[loop++] = *buffer;
        buffer++;
    }
    buffer++;
    for (int j = 0; buffer[j]; j++)
        if (buffer[j] == '\n')
            real_nb_lines++;
    if (real_nb_lines != my_getnbr(nb_lines))
        return 1;
    return 0;
}

int verif(int argc, char *argv[])
{
    struct stat var_stat;
    char *buffer;
    int fd;

    if (argc != 2)
        return error();
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return error();
    stat(argv[1], &var_stat);
    buffer = malloc(sizeof(char) * (var_stat.st_size + 1));
    for (int i = 0; i < var_stat.st_size + 1; i++)
        buffer[i] = '\0';
    read(fd, buffer, var_stat.st_size);
    if (verif_map(buffer) || verif_size(buffer))
        return error();
    verif_format(buffer);
    free(buffer);
    close(fd);
    return 0;
}
