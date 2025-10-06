int My_HasIntersection( SDL_Rect *shipPosition,SDL_Rect *astro){
    int max_lef ;
    if(shipPosition->x>astro->x)
        max_lef = shipPosition->x;
    else
        max_lef = astro->x;

    int min_right;
    if (shipPosition->x + shipPosition->w < astro->x + astro->w)
        min_right = shipPosition->x + shipPosition->w;
    else
        min_right = astro->x + astro->w;



    int inter_horizont = max_lef < min_right;

    int max_up;
    if (astro->y + astro->h < shipPosition->y)
        max_up = astro->y + astro->h ;
    else
        max_up = shipPosition->y;
    

    int min_down;

    if (astro->y  > shipPosition->y + shipPosition->h)
        min_down = shipPosition->y + shipPosition->h;
    else
        min_down = astro->y;

    int inter_verical = max_up < min_down;

    
    return inter_verical && inter_horizont ;
    
}

