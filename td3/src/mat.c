#include <stdio.h>
#include <stdlib.h>

//Cette fonction indique si un élément est présent dans un tableau.
bool est_present(int tab[], unsigned taille, int valeur);

bool est_permut1(unsigned p[], unsigned taille);
bool est_permut2(unsigned p[], unsigned taille);

bool est_permut2(unsigned p[], unsigned taille){
    for(int i=0;i<taille;i++){
        bool v=est_present(tab, taille,i);
        if(v==0) return 0;
        if(p[i]<i) return 0;
    }
    return 1
}

bool est_permut1(unsigned p[], unsigned taille){
    for(int i=0;i<taille;i++){
        if(p[i]<1 || p[i]>taille) return 0;
        bool v=est_present(tab, taille,i);
        if(v==0) return 0;
    }
    return 1
}
bool est_present(int tab[], unsigned taille, int valeur){
    for(int i=0;i<taille;i++){
        if(valeur==*(tab+i)) return true;
    }
    return false;
}


int main(void){
    unsigned taille = 10;
    /* allocation sur le tas */
    int* tab = malloc(taille * sizeof(int));
    tab[0] = 2; tab[1] = 8; tab[2] = 1; tab[3] = 4; tab[4] = 10;
    tab[5] = 5; tab[6] = 6; tab[7] = 3; tab[8] = 9; tab[9] = 7;
    affiche(tab, taille);
    /* quand on n'a plus besoin de tab, il faut libérer la mémoire utilisée */
    free(tab);
    return EXIT_SUCCESS;
}