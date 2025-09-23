#include "collision.h"

int
main(){
    struct sprite mes_sprites[100];
    
    for (int i = 0; i < 100; i++)
    {
        mes_sprites[i] = sprite_aleatoire(1080,1920);
    }
    
    for (int n =2;n<100;n++){
        compte_collision(mes_sprites,n);
    }
    
}