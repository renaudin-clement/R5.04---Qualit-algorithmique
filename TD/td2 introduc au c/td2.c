#include <stdio.h>

struct maillon {
    int val;
    struct maillon * suivant;
};

struct maillon depart = {0,NULL};

int x = 3;
int *px = &x;