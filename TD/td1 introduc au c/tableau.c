#include <stdio.h>



int main(void){

    int tab[10] = {1,2,-3,-4,5,6,7,8,9,10};
    tab[7] =35;

    for (int i = 0; i<10; i++){
        printf("tableau ligne [%d] = %d ",i,tab[i]);
        if (i % 3==2){
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}



int
indiceMinimum(int tab[], int debut, int fin){
    int i_min = debut;
    for(int i=debut;i<=fin;i++){
        if (tab[i] <tab[i_min]) {
            i_min = i;
        }
    }
    return i_min;
}

void
triSelection(int tab[], int taille) {
    if (taille > 0) {
        for (int i=0;i<taille-1;i++){
            int i_min = indiceMinimum(tab,i,taille-1);
            int tmp = tab[i];
            tab[i] = tab[i_min];
            tab[i_min] = tmp;
        }
    }
}