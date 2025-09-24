#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    int t_stat[10];
    int * t_dyn;
    t_dyn = (int *)malloc(10*sizeof(int));


    t_stat[0] = -13;
    t_dyn[0] = 17;

    t_dyn[10] = 42;

    /* Zone mémoire non initialisée */
    printf("%d ",t_stat[0]);
    printf("%d\n",t_dyn[0]);

    /* Accès à une zone mémoire non allouée */

    printf("%d ",t_stat[10]);
    printf("%d\n",t_dyn[10]);


    /* Fuite mémoire */
    //t_dyn += 11; 
    free(t_dyn);

    /* Mémoire doublement libérée */
    int * t = (int *)malloc(sizeof(int));
    *t = 76;
    free(t);
    //free(t);

    /* pointeur pendant */
    int * t3;
    t3 = malloc(sizeof(int));
    t3[0] = 42;
    printf("%d\n",t3[0]);
    free(t3);
    return 0;
}