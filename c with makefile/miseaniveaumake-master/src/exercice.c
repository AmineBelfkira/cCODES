#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct cellule {
    int valeur;
    struct cellule* suivante;
};
typedef struct cellule* liste;

void affiche(liste l){
    if (l== NULL){
        exit(EXIT_FAILURE);
    }

    liste p = l;

    while (p != NULL)
    {
        printf("%d -> ", p->valeur);
        p = p->suivante;
    }
    printf("NULL\n");
}
void insere_tete(int nouveau, liste* pl){
    if (pl== NULL){
        exit(EXIT_FAILURE);
    }
    liste p=malloc(sizeof(struct cellule));
    p->valeur = nouveau;
    p->suivante = *pl;
    *pl = p;
    
    
}

void insere_queue(int nouveau, liste* pl){
    //liste l=malloc(sizeof(struct cellule));
    liste p= *pl;
    while ((p->suivante)!=NULL){
        p=p->suivante;
    }
    liste nv=malloc(sizeof(struct cellule));
    nv->valeur=nouveau;
    nv->suivante=NULL;
    p->suivante= nv;
}

bool recherche(int valeur, liste l){
    liste p= l;
    do{
        if((p->valeur)==valeur) return 1;
        p=p->suivante;
    }while (p!=NULL);
    return 0;
}

void supprime(int valeur, liste* pl){

}

void main(){
    liste l = malloc(sizeof(struct cellule)); 
    l->valeur = 30; 
    l->suivante =NULL;
    insere_tete(5,&l);
    insere_tete(50,&l);
    insere_queue(88,&l);
    affiche(l);
    int p=recherche(50,l);
    if (p==1) printf("kayan\n");
    else printf("makaynch\n");
    free(l); 

}

