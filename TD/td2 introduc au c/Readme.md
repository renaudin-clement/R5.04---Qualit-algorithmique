# commande utile pour C

de base
gcc -o nom source

avec option

gcc -Werror -Wall -Wconversion -std=c11 -o somme somme.c


si depasse deviens negatif test factoriel 25


----
### resultat en fonction de la taille

#### entier signé (int)

sur 32 bits [-2³¹;2³¹-1]  

    - 2²⁹ -> 2²⁹  
    - 2³⁰-> 2³⁰  
    - 2³¹ -> -2³¹  
    - 2³² -> 0  
    - 2³³ -> 0  
----

    printf("%d\n",22);
    printf("%d %d\n",33,22);

---
c operation preference


### trier algo

>algo (radix sort) = O(n+m) m= plus grande valeur du tableau  
---
>quick-sort (en moyenne)  
>ftc sort fr python          = O(nlogn)  
>merge sort - tri fusion  
---  
>tri par insertion  
>quick sort (precis) => O(n²)  
>tri par selection  

### les maillons et structure
    struct maillon {
        int val;
        struct maillon * suivant;
    };

si m est un struc maillon m a deux champs;  

        int m.val;  

-m.suivront est un printeur sur une struc maillon  

    (struct maillon)* m.suivant
    ||
    (Struc maillon) *(m.suivant)

---
on creer une vairalble x et on creer un pointeur qui regarde a ca memoire  

int x = 3;  
int *px = &x;  

*px = *px + 1  
// quelle sera la valeur de x?
4
car on augmente la valeur de x grace a *px +;

mais 

px =+ 1;  
x vaut toujours 4 mais on change lendroit ou le pointeur regarde ( dangereux) 

---

### recap hexa

    0101 0010
    OX5   2

    4*16 = 64
    64 = OX40
    'A' = 65 = OX41

    OX52
    -OX41
    ------
    OX11 = 'R'

### aligment

dans la representation en memoire d'une struct, chaque champ doit  
commencer à une adresse qui est multiple de la taille des mots de  
l'architecture (ici,32 bits)



---
### struct

>.  
>    struct obj1 {char c; unsigned int i};    
>._________________1 octet  4 octet  
>
> mais la taille doit etre un multiple de 4

    < c > // // // <----i----->
      0    1  2  3  4  5  6  7

---
Obj1.c =='R'  
<br>
obj1.i == OX1f8  

---
### union
quand on est dans une union on utilise la place au meme endroit


      0    1  2  3 
    < c > <----i----->
    objet.c
    <---------------->
         obj2.i
    
obj2.c == 'R' == obj1.c
obj2.i ==Ox52 00 00 00