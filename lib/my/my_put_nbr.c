/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-nicolas.spijkerman
** File description:
** my_put_nbr.c
*/

#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb == -2147483648) {
        my_putstr("-214748364");
        nb = 8;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb < 10 && nb / 10 == 0)
        my_putchar(nb + 48);
    return 0;
}
