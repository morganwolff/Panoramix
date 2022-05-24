/*
** EPITECH PROJECT, 2022
** B-CCP-400-NCE-4-1-panoramix-morgan.wolff
** File description:
** villager.c
*/

#include "../include/my.h"

bool villager_need_drinks(villager_t *v)
{
    pthread_mutex_lock(&v->druid->mutex);
    printf("Villager %d: I need a drink... I see %d serving left.\n",
            v->id, v->druid->qty);
    if (v->druid->qty <= 0) {
        if (v->druid->refills <= 0) {
            pthread_mutex_unlock(&v->druid->mutex);
            return false;
        }
        printf("Villager %d: Hey Pano wake up! We need more potion.\n",
                v->id);
        sem_post(&v->druid->empty);
        sem_wait(&v->druid->full);
    }
    v->druid->qty--;
    pthread_mutex_unlock(&v->druid->mutex);
    return true;
}

void villager_fight(villager_t *v)
{
    v->fights_left--;
    printf("Villager %d: Take that roman scum! Only %d left.\n", v->id,
            v->fights_left);
}

void villager(void *args)
{
    villager_t *v = (villager_t *)args;

    printf("Villager %d: Going into battle!\n", v->id);
    while (v->fights_left > 0) {
        if (!villager_need_drinks(v))
            return;
        villager_fight(v);
    }
    return;
}
