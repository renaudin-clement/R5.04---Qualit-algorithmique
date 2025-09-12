#ifndef LISTE_H
#define LISTE_H

/**
BUT3 Info Orleans R504 - fichier d'en-tête pour les listes chainées
*/

/**
Un maillon contient une valeur entière et un pointer vers un autre maillon
*/
struct maillon {
    int val;
    struct maillon *suivant;
};

/**
Une liste est constitué de son premier maillon (potentiellement vide) et
du nombre d'élément contenus dans la liste.
*/
struct liste {
    struct maillon * debut;
    int nbElem;
};

typedef struct maillon * liste;


liste creerListe();

liste insere_en_tete(liste l, int x);

//void supprimerListe(lst l);
//void inserer(lst l, int val, int i);
//int supprimerEnTete(lst l);
//int supprimer(lst l, int i);
//void afficherListe(lst l);

#endif
