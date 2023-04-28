/*
** EPITECH PROJECT, 2023
** panoramix-mirror [WSL : Ubuntu]
** File description:
** core
*/

#pragma once

#include <pthread.h>
#include <semaphore.h>

typedef struct {
    pthread_t thread;
    int id;
    int fights_left;
} villager_t;

typedef struct {
    int pot_left;
    pthread_mutex_t mutex;
} pot_t;

typedef struct {
    pthread_t thread;
    int ingredients;
    pot_t *pot;
} druid_t;

typedef struct {
    villager_t *villagers;
    druid_t druid;
    pot_t pot;
} core_t;

typedef struct {
    char *nb_villagers;
    char *pot_size;
    char *nb_fights;
    char *nb_refills;
} args_t;

void help(void);
int panoramix(char *nb_villagers, char *pot_size, char *nb_fights,
    char *nb_refills);
int init_core(core_t *core, args_t args);
void *villager(void *args);
void *druid(void *args);
