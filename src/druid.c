/*
** EPITECH PROJECT, 2022
** B-CCP-400-NCE-4-1-panoramix-morgan.wolff
** File description:
** druid.c
*/

#include "../include/my.h"

void *druid(void *args)
{
    druid_t *d = (druid_t *)args;
    printf("Druid: I'm ready... but sleepy...\n");
    while (d->refills > 0) {
        sem_wait(&d->empty);
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I "
                "can only make %d more refills after this one.\n",
                d->refills - 1);
        d->qty = d->pot_size;
        d->refills--;
        sem_post(&d->full);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
