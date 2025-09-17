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

// une liste est donnée par l'adresse de son
// premier maillon (s'il existe)
// donc le type liste est un alias de (struct maillon *)
typedef struct maillon* liste;

liste ajouterEnTete(liste l, int x);
int longueur(liste l);
struct maillon* recherche(liste l, int x);

liste supprimerListe(liste l);




liste inserer(liste l, int val, int i);
liste supprimerEnTete(liste l);
liste supprimer(liste l, int i);
void affiche_liste(liste l);

#endif