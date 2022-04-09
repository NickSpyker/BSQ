/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
** File description:
** verif_forma.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "include/my.h"
#include <stdio.h>

static void error(void)
{
    write(2, "error\n", 6);
    exit(84);
}

static int get_nb_cols(char *buffer, int result)
{
    while (*buffer != '\n') {
        buffer++;
        result++;
    }
    return result;
}

static int check_bsn(char *buffer)
{
    for (int i = 0; buffer[i]; i++) {
        if (buffer[i + 1] == '\0' && buffer[i] != '\n')
            return 1;
    }
    return 0;
}

void verif_format(char *buffer)
{
    int nb_cols = 0;
    int verif = 0;

    if (check_bsn(buffer)) error();
    while (*buffer != '\n') buffer++;
    buffer++;
    nb_cols = get_nb_cols(buffer, 0);
    while (*buffer) {
        while (*buffer != '\n') {
            buffer++;
            verif++;
        }
        if (verif != nb_cols) error();
        buffer++;
        verif = 0;
    }
}
