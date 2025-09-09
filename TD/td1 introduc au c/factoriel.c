#include <stdio.h>

int factorielle(int n){

    int res =1;
    for(int i=2;i<n;i++){
        res*=i;
    }
    return res;
}


int main(void){
    printf("%d\n",factorielle(25));
    printf("%d\n",22);
    printf("%d %d\n",33,22);
    return 0;
}