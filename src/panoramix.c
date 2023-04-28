/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** panoramix
*/

#include "core.h"
#include <stdlib.h>

int panoramix(char *nb_villagers, char *pot_size, char *nb_fights,
    char *nb_refills)
{
    core_t core = {0};

    if (init_core(&core, (args_t){.nb_fights=nb_fights, .nb_refills=nb_refills,
    .nb_villagers=nb_villagers, .pot_size=pot_size}) == 84)
        return (84);
    for (int i = 0; i < atoi(nb_villagers); i++)
        pthread_create(&core.villagers[i].thread, NULL, villager,
        &core.villagers[i]);
    pthread_create(&core.druid.thread, NULL, druid, &core.druid);
    for (int i = 0; i < atoi(nb_villagers); i++)
        pthread_join(core.villagers[i].thread, NULL);
    pthread_join(core.druid.thread, NULL);
    return (0);
}
