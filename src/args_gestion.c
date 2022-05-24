/*
** EPITECH PROJECT, 2022
** avs_gestion
** File description:
** avs_gestion
*/

#include "../include/my.h"

void get_args(village_t *v, int ac, char **av)
{
    switch (ac) {
        case 1:
            v->num_villager = atoi(av[1]);
            break;
        case 2:
            v->druid->pot_size = atoi(av[2]);
            break;
        case 3:
            v->villagers->fights_left = atoi(av[3]);
            break;
        case 4:
            v->druid->refills = atoi(av[4]);
            break;
        default:
            break;
    }
}

bool check_args(village_t *v, int ac, char **av)
{
    for (int i = 1; i != ac; i++) {
        if (atoi(av[i]) <= 0) {
            return false;
        } else
            get_args(v, i, av);
    }
    return true;
}
