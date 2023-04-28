/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** villager
*/

#include "core.h"
#include <stdio.h>

void *villager(void *args)
{
    printf("Villager %i: Going into battle!\n", ((villager_t *)args)->id);
    return (NULL);
}
