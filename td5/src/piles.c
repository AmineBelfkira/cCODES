#include <stdio.h>
#include <stdlib.h>


typedef int pile

pile* creer_pile_vide(unsigned taille);
void detruire_pile(pile* p);
bool pile_est_pleine(pile* p);
bool pile_est_vide(pile* p);
void empiler(pile* p, int valeur);
int depiler(pile* p);
void afficher_pile(pile* p);
void vider_pile(pile* p);

pile* creer_pile_vide(unsigned taille){
    pile* p=calloc(taille,sizeof(int));
    return p;
}

void detruire_pile(pile* p){
    free(p);
}


