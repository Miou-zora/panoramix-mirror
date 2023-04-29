/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** init_core
*/

#include "core.h"
#include <stdlib.h>
#include <stdio.h>

void init_villagers(villager_t *villagers, args_t *args, core_t *core)
{
    for (int i = 0; i < atoi(args->nb_villagers); i++) {
        villagers[i].id = i;
        villagers[i].fights_left = atoi(args->nb_fights);
        villagers[i].pot = &core->pot;
        villagers[i].have_drink = false;
        villagers[i].druid = &core->druid;
    }
}

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
    core->pot.pot_left = atoi(args.pot_size);
    core->pot.pot_size = atoi(args.pot_size);
    core->druid.pot = &core->pot;
    pthread_mutex_init(&core->pot.mutex, NULL);
    core->druid.ingredients = atoi(args.nb_refills);
    core->druid.thread = 0;
    pthread_cond_init(&core->druid.cond, NULL);
    init_villagers(core->villagers, &args, core);
    return (0);
}
