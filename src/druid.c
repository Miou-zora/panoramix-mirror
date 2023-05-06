/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** druid
*/

#include "core.h"
#include <stdio.h>

void *druid(void *args)
{
    druid_t *druid = (druid_t *)args;
    printf("Druid: I'm ready... but sleepy...\n");
    do {
        sem_wait(&druid->sem_empty);
        if (druid->ingredients > 0) {
            druid->pot->pot_left = druid->pot->pot_size;
            druid->ingredients -= 1;
            printf("Druid: Ah! Yes, yes, I'm awake! Working on it!"
            " Beware I can only make %i"
            " more refills after this one.\n", druid->ingredients);
        }
        sem_post(&druid->sem_full);
    } while (druid->ingredients > 0);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
