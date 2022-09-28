#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct noeud{
    int elem;
    struct noeud* filsdroit;
    struct noeud* filsgauche;
};

typedef struct noeud noeud;
typedef noeud* arbre;

noeud* creer_noeud(int valeur);//validé
bool arbre_est_vide(arbre a);//validé
void detruire_arbre(arbre a);//validé
unsigned hauteur(arbre a);//validé
unsigned nb_feuilles(arbre a);//validé
bool arbre_est_degenere(arbre a);
void parcours_prefixe(arbre a);
void parcours_postfixe(arbre a);

noeud* creer_noeud(int valeur){
    noeud* pnoeud=calloc(1,sizeof(*pnoeud));
    if (pnoeud==NULL){
        exit(EXIT_FAILURE);
    }
    pnoeud->elem=valeur;
    pnoeud->filsdroit=NULL;
    pnoeud->filsgauche=NULL;
    return pnoeud;
}

bool arbre_est_vide(arbre a){
    return a==NULL;
}

void detruire_arbre(arbre a){
    if (!arbre_est_vide(a)){
        detruire_arbre(a->filsdroit);
        detruire_arbre(a->filsgauche);
        free(a);
    }
}

unsigned hauteur(arbre a){
    unsigned haut=0;
    if (!arbre_est_vide(a)){  
        haut++;
        unsigned hauteur1=hauteur(a->filsdroit);
        unsigned hauteur2=hauteur(a->filsgauche);
        if(hauteur1>hauteur2) haut+=hauteur1;
        else haut+=hauteur2;
    }
    return haut;
}

unsigned nb_noeuds(arbre a){
    unsigned nbnoeuds=0;
    if(!arbre_est_vide(a)){
        nbnoeuds++;
        nbnoeuds+=nb_noeuds(a->filsgauche);
        nbnoeuds+=nb_noeuds(a->filsdroit);
    }
    return nbnoeuds;    
}

unsigned nb_feuilles(arbre a){
    unsigned nbfeuilles=0;
    if(!arbre_est_vide(a) && arbre_est_vide(a->filsgauche) && arbre_est_vide(a->filsdroit)) nbfeuilles=1;
    else{
        if (!arbre_est_vide(a)) nbfeuilles=nb_feuilles(a->filsdroit)+nb_feuilles(a->filsgauche);
    }
    return nbfeuilles;
}

bool arbre_est_degenere(arbre a){
    if (arbre_est_vide(a)) return true;
    return (arbre_est_degenere(a->filsdroit) && !arbre_est_degenere(a->filsgauche)) || (arbre_est_degenere(a->filsgauche) && !arbre_est_degenere(a->filsdroit));
}

void parcours_prefixe(arbre a){
    if(arbre_est_vide(a)) printf("[NULL]");
    else {
    printf("[ [%d] ,",a->elem);
    parcours_prefixe(a->filsgauche);
    parcours_prefixe(a->filsdroit);
    }
}

void parcours_infixe(arbre a){
    if(!arbre_est_vide(a)){
        parcours_infixe(a->filsgauche);
        printf("[ %d , ",a->elem);
        parcours_infixe(a->filsdroit);
    }
    else printf("[NULL]");
}

void parcours_postfixe(arbre a){
    if(!arbre_est_vide(a)){
        parcours_postfixe(a->filsgauche);
        parcours_postfixe(a->filsdroit);
        printf("( %d ), ",a->elem);
    }
    else printf("[NULL]");
}


int main(){
    arbre a=creer_noeud(1);
    if(!arbre_est_vide(a)) printf("arbre non vide de valeur: %d \n",a->elem);
    a->filsgauche=creer_noeud(2);
    if(!arbre_est_vide(a->filsgauche)) printf("arbre gauche non vide de valeur: %d \n",(a->filsgauche)->elem);
    a->filsdroit=creer_noeud(3);
    if(!arbre_est_vide(a->filsdroit)) printf("arbre droit non vide de valeur: %d \n",(a->filsdroit)->elem);
    (a->filsgauche)->filsgauche=creer_noeud(4);
    (a->filsgauche)->filsdroit=creer_noeud(5);
    (a->filsdroit)->filsgauche=creer_noeud(6);
    puts("arbre créé: ");
    printf("la hauteur de l'arbre est : %d \n",hauteur(a));
    printf("le nombre de noeud de l'arbre est : %d \n", nb_noeuds(a));
    printf("le nombre de feuilles de l'arbre est : %d \n", nb_feuilles(a));
    puts(" ");
    puts("parcours préfixe: ");
    parcours_prefixe(a);
    puts(" ");
    puts("parcours infixe :");
    parcours_infixe(a);
    puts(" ");
    puts("parcours postfixe :");
    parcours_postfixe(a);
    puts(" ");
    detruire_arbre(a);
    return 0;
}
