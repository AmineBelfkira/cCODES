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

bool arbre_est_vide(arbre a);//validé
void affiche_valeurs_croissantes(arbre a);
noeud* creer_noeud(int valeur);//validé
bool present_rec(arbre a, int valeur);//validé
bool present_iter(arbre a, int valeur);//validé
int get_min(arbre a);//validé
bool arbre_est_ABR(arbre a);

bool arbre_est_vide(arbre a){
    return a==NULL;
}

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

void affiche_valeurs_croissantes(arbre a){
    if(!arbre_est_vide(a)){
        affiche_valeurs_croissantes(a->filsgauche);
        printf("%d < ",a->elem);
        affiche_valeurs_croissantes(a->filsdroit);
    }
    else printf(" ");
}

bool present_rec(arbre a, int valeur){
    if(arbre_est_vide(a)) return false;
    else{
        if (a->elem==valeur) return true;
        else{
            if(valeur<(a->elem)) return present_rec(a->filsgauche,valeur);
            else return present_rec(a->filsdroit,valeur);
        }
    }
}

bool present_iter(arbre a, int valeur){
    arbre nv=a;
    while (!arbre_est_vide(nv)){
        if (nv->elem == valeur) return true;
        else if(valeur<(nv->elem)) nv=nv->filsgauche;
        else nv=nv->filsdroit;
    }
    return false;
}
 
int get_min(arbre a){
    arbre nv=a;
    if(arbre_est_vide(a)) return -1;
    while(!arbre_est_vide(nv->filsgauche)){
        nv=nv->filsgauche;
    }
    return nv->elem;
}

bool arbre_est_ABR(arbre a){
    if (a==NULL) return true;
    else if(!arbre_est_vide(a->filsgauche) && !arbre_est_vide(a->filsdroit){
        if (((a->filsgauche)->elem)>(a->elem) || (a->elem)>((a->filsdroit)->elem)){
            return false;
        }
    }
    else if(arbre_est_vide(a->filsgauche) && !arbre_est_vide(a->filsdroit)) return (a->elem) < ((a->filsdroit)->elem);
    else if(!arbre_est_vide(a->filsgauche) && arbre_est_vide(a->filsdroit)) return (a->elem) > ((a->filsgauche)->elem);
    
    return arbre_est_ABR(a->filsgauche) && arbre_est_ABR(a->filsdroit);
}

int main(){
    arbre a=creer_noeud(5);
    if(!arbre_est_vide(a)) printf("arbre non vide de valeur: %d \n",a->elem);
    a->filsgauche=creer_noeud(2);
    if(!arbre_est_vide(a->filsgauche)) printf("arbre gauche non vide de valeur: %d \n",(a->filsgauche)->elem);
    a->filsdroit=creer_noeud(9);
    if(!arbre_est_vide(a->filsdroit)) printf("arbre droit non vide de valeur: %d \n",(a->filsdroit)->elem);
    (a->filsgauche)->filsgauche=creer_noeud(1);
    (a->filsgauche)->filsdroit=creer_noeud(4);
    (a->filsdroit)->filsgauche=creer_noeud(8);
    //(a->filsdroit)->filsdroit=creer_noeud(52);
    affiche_valeurs_croissantes(a);
    puts(" ");
    /*
    puts("facon récursive");
    for (int i = 0; i < 10; i++){
        if (present_rec(a,i)) printf("l'élément %d existe dans l'arbre \n",i);
        else printf("l'élément %d n'existe pas dans l'arbre \n",i);
    }*/
    puts("facon iterative");
    for (int i = 0; i < 10; i++){
        if (present_iter(a,i)) printf("l'élément %d existe dans l'arbre \n",i);
        else printf("l'élément %d n'existe pas dans l'arbre \n",i);
    }
    printf("le minimum de l'arbre est : %d \n", get_min(a));
        
    return 0;
}