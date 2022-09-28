#include <stdio.h>
#include <stdlib.h>

//affichage du tableau
void affiche(int tab[], unsigned taille);
//calcule du minimum
int min(int tab[], unsigned taille);
//Cette fonction indique si un élément est présent dans un tableau.
bool est_present(int tab[], unsigned taille, int valeur);
//recherche linéaire d'un élément dans un tableau trié.
bool est_present_trie(int tab[], unsigned taille, int valeur);
//recherche dichotomique d'un élément dans un tableau trié
bool est_present_trie_dicho(int tab[], unsigned taille, int valeur);


bool est_present_trie_dicho(int tab[], unsigned taille, int valeur){
    int a=0, b=taille-1;
    while(a<=b){
        int m=(a+b)/2;
        if(valeur==tab[m]) return 1;
        else if(valeur<tab[n]) b=m+1;
        else a=m-1;
    }
    return 0;
    /*int n=taille/2;
    if(taille==1 && *tab==valeur) return 1;
    else return 0;
    if(tab[n]>valeur){
        return est_present_trie_dicho(tab,n,valeur);
    }
    else{
        return est_present_trie_dicho(tab+n,taille-n,valeur);
    }*/
}

bool est_present_trie(int tab[], unsigned taille, int valeur){
    int i=0;
    while(i<taille && valeur<=tab[i]){
        if(valeur==tab[i]) return 1;
    }
    return 0;
}

bool est_present(int tab[], unsigned taille, int valeur){
    for(int i=0;i<taille;i++){
        if(valeur==*(tab+i)) return true;
    }
    return false;
}

int min(int tab[], unsigned taille){
    int min=*tab;
    for(int i=1;i<taille;i++){
        if(tab[i]<min) c=tab[i];
    }
    return min;
}

void affiche(int tab[], unsigned taille){
    for (size_t i = 0; i < taille; i++) {
        printf("tab[%u] = %d\n", i, t[i]);
    }
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