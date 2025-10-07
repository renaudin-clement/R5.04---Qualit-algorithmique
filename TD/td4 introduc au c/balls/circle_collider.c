#include <stdio.h>
#include "circle_collider.h"

//Circle collider

int hite(c1x,c1y,c1r,c2x,c2y,c2r){


    float distX = c1x - c2x;
    float distY = c1y - c2y;

    float distance = sqrt( (distX*distX) + (distY*distY) );

    if (distance <= c1r+c2r) {
        return 1;
    }
    return 0;

}