#include <stdio.h>


int main(){

    int x = 3;
    int *px = &x;
    *px = *px+1 ;

    printf("%d \n",x);
    printf("j'affiche le pointeur en faisant une tab\t %p \t son address memoire \n",px);
    *px += 1 ;
    printf("j'affiche le pointeur en faisant une tab\t %p \t son address memoire \n",px + 1);


    return 1;
}



/*
    int x = 3;
    int *px = &x
    *px = px + 1
    printf("%d\n",x); // stdout: "-1510730656" ?!
*/