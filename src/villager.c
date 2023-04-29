/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** villager
*/

#include "core.h"
#include <stdio.h>
#include <unistd.h>

void update_pot_druid(villager_t *villager)
{
    pthread_mutex_lock(&villager->pot->mutex);
    printf("Villager %i: I need a drink... I see %i"
    " servings left.\n", villager->id, villager->pot->pot_left);
    if (villager->pot->pot_left > 0) {
        villager->pot->pot_left -= 1;
        pthread_mutex_unlock(&villager->pot->mutex);
        villager->have_drink = true;
    } else {
        printf("Villager %i: Hey Pano wake up! "
        "We need more potion.\n", villager->id);
        pthread_cond_signal(&villager->druid->cond);
        pthread_mutex_unlock(&villager->pot->mutex);
    }
}

void *villager(void *args)
{
    villager_t *villager = (villager_t *)args;
    printf("Villager %i: Going into battle! %i\n", villager->id,
        villager->fights_left);
    while (villager->fights_left > 0) {
        if (villager->have_drink == true) {
            villager->fights_left -= 1;
            villager->have_drink = false;
            printf("Villager %i: Take that roman scum! Only %i left.\n",
                villager->id, villager->fights_left);
        } else {
            update_pot_druid(villager);
        }
    }
    printf("Villager %i: I'm going to sleep now.\n", villager->id);
    return (NULL);
}
