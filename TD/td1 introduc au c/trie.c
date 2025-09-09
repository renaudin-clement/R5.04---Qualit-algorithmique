
void triInsertion(int tab[], int taille){

    for(int i = 1; i < taille; ++i){
        int j = i;
        int elem = tab[i];

        while(j>0 && tab[j-1]>elem){
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = elem;
    }
}