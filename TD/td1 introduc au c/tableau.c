#include <stdio.h>


void
affichertableau(int tab[],int tai){
    for (int i = 0; i<tai; i++){

        //printf("tableau ligne [%d] = %d ",i,tab[i]);
        printf("[%d] ",tab[i]);
        if (i % 2==1){
            printf("\n");
        }
    }
    printf("\n");

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
    affichertableau(tab,10);
}



int main(void){
    int tab[10] = {1,2,-3,-4,5,6,7,8,9,10};
    tab[7] =35;
    affichertableau(tab,10);
    printf("\n");
    triSelection(tab,10);

    return 0;
}