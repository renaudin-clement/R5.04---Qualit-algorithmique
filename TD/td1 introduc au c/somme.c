#include <stdio.h>

int sommeEntiers(int n){
    int somme =0;
    for (int i=0;i<n;i++){
        somme +=i;
    }
    return somme;
}

int main(void){
    printf("%d\n",sommeEntiers(10));
    return 0;
}