#include <stdio.h>
#include <time.h>

#include "liste.h"

liste insere_en_tete(liste l,int i);

int main () {

    struct timespec ts_debut; // contient un champ tv_sec (seconde) et un champ tv_nsec (nano
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_debut);

    clock_t debut = clock();
    liste l = NULL;
    for (size_t i = 0; i < 10000; i++)
    {
        l = insere_en_tete(l, i);
    }

    affiche(l);
    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf("%f",temps);

    struct timespec ts_fin;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts_fin);
    double temps_s = ts_fin.tv_sec- ts_debut.tv_sec ;
    double temps_ns = ts_fin.tv_nsec - ts_debut.tv_nsec ;
    printf("temps (seconde): %f\n",temps_s);
    printf("temps (nanoseconde): %f\n",temps_ns);
    printf("temps: %f\n",temps_s + temps_ns*1e-9);
}

