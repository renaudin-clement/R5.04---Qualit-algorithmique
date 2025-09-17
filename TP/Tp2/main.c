#include <stdio.h>
#include <time.h>
#include "liste.h"

int main () {

    clock_t debut = clock();
    liste l = NULL;
    for (size_t i = 0; i < 10000; i++)
    {
        l = insere_en_tete(l,i);
    }
    clock_t fin = clock();
    double temps = (double)(fin - debut) / CLOCKS_PER_SEC;
    printf('$d',temps);
}