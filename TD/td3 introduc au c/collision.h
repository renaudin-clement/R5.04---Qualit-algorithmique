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

struct sprite sprite_aleatoire(int w ,int h);

int compte_collision(struct sprite sprites[], unsigned int nb_sprites);