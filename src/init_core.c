/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** init_core
*/

#include "core.h"
#include <stdlib.h>
#include <stdio.h>

int init_core(core_t *core, args_t args)
{
    if (atoi(args.nb_villagers) <= 0 || atoi(args.pot_size) <= 0 ||
    atoi(args.nb_fights) <= 0 || atoi(args.nb_refills) <= 0) {
        fprintf(stderr, "Values must be >0.\n");
        return (84);
    }
    core->villagers = calloc(sizeof(villager_t), atoi(args.nb_villagers));
    if (!core->villagers)
        return (84);
    for (int i = 0; i < atoi(args.nb_villagers); i++) {
        core->villagers[i].id = i;
        core->villagers[i].fights_left = atoi(args.nb_fights);
    }
    core->pot.pot_left = atoi(args.pot_size);
    core->druid.pot = &core->pot;
    pthread_mutex_init(&core->pot.mutex, NULL);
    core->druid.ingredients = atoi(args.pot_size);
    core->druid.thread = 0;
    return (0);
}
