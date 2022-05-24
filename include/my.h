/*
** EPITECH PROJECT, 2022
** my
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <string.h>
    #include <pthread.h>
    #include <stdarg.h>
    #include <signal.h>
    #include <dirent.h>
    #include <fcntl.h>
    #include <semaphore.h>

typedef struct druid {
    int refills;
    int pot_size;
    int qty;
    sem_t empty;
    sem_t full;
    pthread_mutex_t mutex;
} druid_t;

typedef struct villager {
    int fights_left;
    int id;
    pthread_t thread;
    druid_t *druid;
} villager_t;

typedef struct village {
    int num_villager;
    druid_t *druid;
    villager_t *villagers;
} village_t;

void helper(void);
void init_struct(village_t *v, char **av);
void get_args(village_t *v, int ac, char **av);
bool check_args(village_t *v, int ac, char **av);
void *druid(void *args);
void villager(void *args);

#endif
