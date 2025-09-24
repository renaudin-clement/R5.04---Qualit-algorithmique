#include "collision.h"
#include <time.h>
#include <stdio.h>

int
main(){
    struct sprite mes_sprites[100];
    int nb_coll=0;

    for (int i = 0; i < 100; i++)
    {
        mes_sprites[i] = sprite_aleatoire(1080,1920);
    }


    
    for (int n =2;n<100;n++){
        struct timespec ts_debut; // contient un champ tv_sec (seconde) et un champ tv_nsec (nano
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_debut);


        nb_coll = compte_collision(mes_sprites,n);
    

        struct timespec ts_fin;
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_fin);
        double temps_s = ts_fin.tv_sec- ts_debut.tv_sec ;
        double temps_ns = ts_fin.tv_nsec - ts_debut.tv_nsec ;
        printf("temps (seconde): %f\n",temps_s);
        printf("temps (nanoseconde): %f\n",temps_ns);
        printf("temps: %f\n",temps_s + temps_ns*1e-9);


    }
    printf("collision trouver %d\n",nb_coll);
}