#include <stdio.h>


struct maillon {
    int val;
    struct maillon * suivant;
};


typedef struct maillon * liste;

int longueur(liste l){
    if (l == NULL)
    {
        return 0;
    } else {
        return longueur(l->suivant) + 1;
    }
    
}

void affiche(liste l){
    printf("[");
    struct maillon * courant = l;
    while ((courant !=NULL)){
        printf("%d ,", courant->val);
        courant = courant->suivant;
    }
    printf("]");
}

liste insere_en_tete(liste l ,int v){
    struct maillon tete ={v, l};
    l = &tete;
    return l;
    
}

int main(){
    liste liste_vide = NULL;
    struct maillon depart = {0,NULL};
    liste liste_un_elt = &depart;
    struct maillon m3 = {3,NULL};
    struct maillon m7 = {7,NULL};
    m3.suivant = &m7;

   
    liste liste_deux_elt = &m3;

    printf("la longueur de la liste_deux-elt est %d\n",longueur(liste_deux_elt));
    affiche(liste_deux_elt);
    printf("\n");
    affiche(liste_un_elt);
    printf("\n");

    liste liste_trois_elt = insere_en_tete(liste_deux_elt,-43);
    affiche(liste_trois_elt);
    printf("\n");
    
    

    return 1;
}

//voir utilisation malloc