#include <stdio.h>
#include <stdlib.h>
#include "collision.h"


int
collision_non_vide(struct sprite s1,struct sprite s2){
    int ok_h =(s1.x1 < s2.x2) && (s2.x1 < s1.x2);
    int ok_v =(s1.y1 < s2.y2) && (s2.y1 < s1.y2);

    return ok_h && ok_v;
}

int
compte_collision(struct sprite sprites[], unsigned int nb_sprites){
    int nb_coll =0;

    for ( int i =0; i< nb_sprites; i++){
        for (int j = i+1 ; j< nb_sprites; j++) {
            if (collision_non_vide(sprites[i],sprites[j])){
                nb_coll+=1;
            }
            //or
            // nb_coll+= collision_non_vide(sprites[i],sprites[j]);
        }
    }

    return nb_coll;
}


struct sprite sprite_aleatoire(int w ,int h){
    struct sprite res ;
    res.x1 = rand() % h;
    res.x2 = rand() % w;
    res.y1 = res.x1 + (rand() % (h-res.x1));
    res.y2 = res.x2 + (rand() % (h-res.x2));

    res.chemin_incone=NULL;
    res.len_chemin_incone =0;
    return res;
}

struct  noeud_QT{

struct noeud_QT * enfants[4];   //64 octets
int xg,yh,xd,yb;                //16 octets
struct sprite * sprites[3];     //24 octets

};

typedef noeud_QT * quartree;
//sizeof(struct  noeud_QT)=72;

