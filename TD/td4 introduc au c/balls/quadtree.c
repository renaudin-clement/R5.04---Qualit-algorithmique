#include <SDL.h>

#define CAPACITE 5

struct qTreeNode {
    SDL_Rect area;
    struct qTreeNode* enfants[4];
    int sprites[CAPACITE];
    int nbSprites;
};

// donne le SDL_Rect représentant le i-ième quartier de r dans l'ordre
// NW, NE, SW, SE
// 0 | 1
// -----
// 2 | 3
SDL_Rect quartier(SDL_Rect *r, int i) {
    SDL_Rect res;
    res.w = r->w / 2;
    res.h = r->h / 2;
    res.y = r->y + (i < 2 ? 0 : res.h);
    res.x = r->x + (i % 2 ? res.w : 0);
    return res; 
}

// Renvoie un pointeur vers un qtree alloué pour contenir les sprites
// du tableau sprites.
struct qTreeNode *creer_qtree(
    SDL_Rect area,
    SDL_Rect tous_sprites[],
    int indice_de_mes_sprites[],
    int nbSprites)
{
    struct qTreeNode *res = malloc(sizeof(qTreeNode));
    struct qTreeNode *enfants = NULL;
    res.area = area;
    res.nbSprites = 0;

    if (nbSprites <= CAPACITE) {
        res.enfants[0] = NULL;
        res.nbSprites = nbSprites;
        for(i = 0; i < nbSprites; i++) {
            res.sprites[i] = tous_sprites[indice_de_mes_sprites[i]];
        }
    } else {
        for(int i = 0; i < 4; i++) {
            SDL_Rect area_e = quartier(area, i);
            nbSprites_e = 0;
            int indice_sprites_enfants = malloc(nbSprites*sizeof(int));
            for (i = 0; i < nbSprites; i++) {
                int j = indice_de_mes_sprites[i];
                if(SDL_HasIntersection(tous_sprites[j], area_e)) {
                    indice_sprites_enfants[nbSprites_e] = j;
                    nbSprites_e += 1;
                }
            }
            res.enfants[i] = cree_qtree(area_e, indice_sprites_enfants, nbSprites_e);
        }
    }

    return res;
}