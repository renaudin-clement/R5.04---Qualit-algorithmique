#include <stdio.h>

struct
sprite{
    int x1,y1, x2,y2;

    // pointeur vers les caracteres composant le chemin de l'icone
    // exemple (ex: \ "/user/games/barjo/barjo.png")
    //               ..^
    char *chemin_incone;
    
    // nombre de caracteres dans le chemin de l'icone (ici 27)
    unsigned int len_chemin_incone;

};


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
}
