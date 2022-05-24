/*
** EPITECH PROJECT, 2022
** panoramix
** File description:
** init_struct.c
*/

#include "../include/my.h"

void init_struct(village_t *v, char **av)
{
    v->villagers = malloc(sizeof(villager_t) * atoi(av[1]));
    v->druid = malloc(sizeof(druid_t));
    v->num_villager = 0;

    v->druid->refills = 0;
    v->druid->pot_size = 0;
    v->druid->qty = 0;

    v->villagers->fights_left = 0;
    v->villagers->id = 0;
}
