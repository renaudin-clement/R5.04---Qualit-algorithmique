#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

/**
BUT3 Info Orleans R504 - implémentation possible des listes chainées
*/

lst
creerListe()
{
    lst nouvelleListe = (lst) malloc(sizeof(struct liste));
    nouvelleListe->nbElem = 0;
    return nouvelleListe;
}

void 
ajouterEnTete(lst l, int x)
{
    ml nouvelElem = (ml) malloc(sizeof(struct maillon));
    nouvelElem->val = x;
    nouvelElem->suivant = l->debut;
    l->debut = nouvelElem;
    l->nbElem++;
}

void
inserer(lst l, int val, int i)
{
    if(l->nbElem > i)
    {
        if (i==0){ajouterEnTete(l, val);}
        else {
            int j = 0;
            ml iter = l->debut;
            while( j< (i-1) ){
                iter=iter->suivant;
                j++;
            }
            ml elem = (ml) malloc(sizeof(struct maillon));
            elem->val = val;
            elem->suivant = iter->suivant;
            iter->suivant = elem;
        }
    }
}

void
afficherListe(lst l)
{
    printf("[");
    ml iter = l->debut;
    while (iter != NULL) {
        printf("%d ",iter->val);
        iter = iter->suivant;
    }
    printf("]");
}

int
supprimerEnTete(lst l)
{
    if(l->nbElem > 0){
        // on commence par sauvegarder l'adresse du 2nd élément de la liste
        ml suiv = l->debut->suivant;
        // on sauvegarde ensuite la valeur du premier élément de la liste
        int val = l->debut->val;
        // on supprime cet élément
        free(l->debut);
        // on met à jour la liste
        l->debut = suiv;
        l->nbElem--;
        // on renvoie l'élément
        return val;
    }
    return NULL;
}

void
supprimerListe(lst l)
{
    // on supprime d'abord tous les éléments, puis on supprime la liste
   
    while (l->nbElem > 0) {
        supprimerEnTete(l);
    }
    free(l);
    
}