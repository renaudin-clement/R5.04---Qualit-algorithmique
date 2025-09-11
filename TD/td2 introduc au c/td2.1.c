#include <stdio.h>


struct maillon {
    int val;
    struct maillon * suivant;
};


typedef struct maillon * liste;



int main(){
    liste liste_vide = NULL;
    struct maillon depart = {0,NULL};
    struct maillon m3 = {3,NULL};
    struct maillon m7 = {7,NULL};
    m3.suivant = &m7;
    
    liste liste_un_elt = &depart;
    liste liste_deux_elt = &m3;
    
    

    return 1;
}

