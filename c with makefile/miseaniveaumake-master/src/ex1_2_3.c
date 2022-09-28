# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

void affiche(int tab[], unsigned taille){
    for (size_t i = 0; i < taille; i++) {
        printf("tab[ %ld ] = %d\n", i, tab[i]);
    }
}
int min(int tab[], unsigned taille){
    int min=tab[0];
    for (size_t i=1;i<taille;i++){
        if (min>tab[i]) min=tab[i];
    }
    return min;
}
bool est_present(int tab[], unsigned taille, int valeur){
    for (size_t i = 0; i < taille; i++) {
        if(tab[i]==valeur) return 1;
    }
    return 0;

}


int main(void){
    unsigned taille = 10;
    /* allocation sur le tas */
    int* tab = malloc(taille * sizeof(int));
    tab[0] = 2; tab[1] = 8; tab[2] = 100; tab[3] = 4; tab[4] = 10;
    tab[5] = 5; tab[6] = 6; tab[7] = 3; tab[8] = 9; tab[9] = 7;
    /*affiche(tab, taille);*/
    /* quand on n'a plus besoin de tab, il faut libérer la mémoire utilisée */
    int x=min(tab,taille);
    int valeur;
    printf("le min est: %d\n",x);
    printf("valeur à chercher:");
    scanf("%d",&valeur);
    bool v=est_present(tab,10,valeur);
    if (v==1) printf("yesss present\n");
    else printf("nooooo present\n");
    return EXIT_SUCCESS;
    free(tab);
}
