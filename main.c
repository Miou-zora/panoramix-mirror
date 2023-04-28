/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** main
*/

#include "core.h"

int main(int ac, char **av)
{
    int ret = 0;
    if (ac != 5) {
        help();
        if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
            return (0);
        else
            return (84);
    }
    ret = panoramix(av[1], av[2], av[3], av[4]);
    return (ret);
}
