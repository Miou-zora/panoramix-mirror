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
    pthread_mutex_lock(&druid->pot->mutex);
    do {
        pthread_cond_wait(&druid->cond,
            &druid->pot->mutex);
        if (druid->ingredients > 0) {
            druid->pot->pot_left = druid->pot->pot_size;
            druid->ingredients -= 1;
            printf("Druid: Ah! Yes, yes, I'm awake! Working on it!"
            " Beware I can only make %i"
            " more refills after this one.\n", druid->ingredients);
        }
        pthread_mutex_unlock(&druid->pot->mutex);
    } while (druid->ingredients > 0);
    pthread_mutex_unlock(&druid->pot->mutex);
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return (NULL);
}
