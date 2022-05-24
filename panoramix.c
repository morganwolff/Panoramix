/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "include/my.h"

void loop(village_t *v, int fights)
{
    pthread_t _druid;
    sem_init(&v->druid->full, 0, 0);
    sem_init(&v->druid->empty, 0, 0);
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    v->druid->mutex = mutex;
    v->druid->qty = v->druid->pot_size;
    pthread_create(&_druid, NULL, druid, v->druid);
    for (int i = 0; i != v->num_villager; i++) {
        v->villagers[i].id = i;
        v->villagers[i].fights_left = fights;
        v->villagers[i].druid = v->druid;
        pthread_create(&v->villagers[i].thread, NULL,
                       (void *(*)(void *)) villager,
                       &v->villagers[i]);
    }
    for (int j = 0; j != v->num_villager; j++) {
        pthread_join(v->villagers[j].thread, NULL);
        printf("Villager %d: I'm going to sleep now.\n", v->villagers[j].id);
    }
    pthread_cancel(_druid);
    pthread_join(_druid, 0);
}

int main(int ac, char **av)
{
    village_t v;
    int ret;

    if (ac == 1) {
        helper();
        return 0;
    } else if (ac == 5) {
        init_struct(&v, av);
        ret = !check_args(&v, ac, av) ? 84 : 0;
        if (ret == 84) {
            helper();
            write(2, "Values must be >0\n", 18);
            return ret;
        }
        loop(&v, atoi(av[3]));
        free(v.druid);
        free(v.villagers);
        return ret;
    } else
        return 84;
}
