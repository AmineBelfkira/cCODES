#include <stdio.h>
#include <stdlib.h>


struct cellule {
    int valeur;
    struct cellule* suivante;
};
typedef struct cellule* liste;

void affiche(liste l);
void insere_tete(int nouveau, liste* pl);
void insere_queue(int nouveau, liste* pl);
int recherche(int valeur, liste l);
void supprime(int valeur, liste* pl);
void inverse(liste* pl);
void libere(liste* pl);

void affiche(liste l){
    if(l==NULL) exit(EXIT_FAILURE);
    do{
        printf("[ %d ] ",l->valeur);
        l=l->suivante;
    }while(l!=NULL);
    puts(" ");
}

void insere_tete(int nouveau, liste* pl){
    liste l=calloc(1,sizeof(*l));
    l->valeur=nouveau;
    l->suivante=(*pl);
    *pl=l;
}

void insere_queue(int nouveau, liste* pl){
    liste l=calloc(1,sizeof(*l)), l1=*pl;
    l->valeur=nouveau;
    l->suivante=NULL;
    if(*pl==NULL) *pl=l;
    else{
        while(l1->suivante!=NULL){
            l1=l1->suivante;
        }
        l1->suivante=l;
    }    
}

int recherche(int valeur, liste l){
    if(l==NULL) return 0;
    while(l!=NULL){
        if(l->valeur==valeur) return 1;
        l=l->suivante;
    }
    return 0;
}
void supprime(int valeur, liste* pl){
    if((*pl)==NULL) exit(EXIT_FAILURE);
    liste l1=(*pl),l2,asuprimer;
    while(l1!=NULL && l1->valeur==valeur){
        asuprimer=l1;
        l1=l1->suivante;
        free(asuprimer);
    }
    if(l1==NULL) { (*pl)=NULL; exit(EXIT_SUCCESS);}
    (*pl)=l1;
    l2=l1->suivante;
    while(l2!=NULL && l2->valeur==valeur){
        if (l2->suivante==NULL && l2->valeur==valeur)free(l2);
        else {
        asuprimer=l2;
        l2=l2->suivante;
        l1->suivante=l2;
        free(asuprimer);
        }
    }

}

/*void supprime(int valeur, liste* pl){
    if((*pl)==NULL) exit(EXIT_FAILURE);
    liste l1=(*pl)->suivante;
    liste l2;
    liste asuprimer;
    while(l1!=NULL){
        l2=l1->suivante;
        if(l1->valeur==valeur){
            asuprimer=l1;
            l1=l2;
            free(asuprimer);
        }
        l1=l2;
    }
    if((*pl)->valeur==valeur){
        asuprimer=(*pl);
        *pl=(*pl)->suivante;
        free(asuprimer);
    }    
}*/

void inverse(liste* pl){
    if((*pl)==NULL) exit(EXIT_FAILURE);
    int i=0;
    int tab[50]={0};
    liste l=(*pl);
    while(l!=NULL){
        tab[i]=l->valeur;
        i++;
        l=l->suivante;
    }
    l=*pl;
    i--;
    while(i!=(-1)){
        l->valeur=tab[i];
        l=l->suivante;
        i--;
    }
}

void libere(liste* pl){
    if(*pl==NULL) printf("liste vide");
    liste asuprimer;
    while((*pl)!=NULL){
        asuprimer=(*pl);
        (*pl)=(*pl)->suivante;
        free(asuprimer);
    }
    
}


int main(){
    liste maliste;
    maliste=malloc(sizeof(*maliste));
    maliste->valeur=1;
    maliste->suivante=NULL;
    //affichage de la liste et ajout des elements: Validé
    printf("affichage de la liste: \n");
    affiche(maliste);
    printf("ajout d'un 1 à la tête: \n");
    insere_tete(1,&maliste);
    affiche(maliste);
    printf("ajout d'un 3 à la queue: \n");
    insere_queue(3,&maliste);
    affiche(maliste);
    printf("ajout d'un 1 à la tête: \n");
    insere_tete(1,&maliste);
    affiche(maliste);
    printf("ajout d'un 0 à la tête: \n");
    insere_tete(0,&maliste);
    affiche(maliste);
    printf("ajout d'un 5 à la queue: \n");
    insere_queue(5,&maliste);
    affiche(maliste);
    printf("ajout d'un 1 à la tête: \n");
    insere_tete(1,&maliste);
    affiche(maliste);
    printf("ajout d'un 3 à la queue: \n");
    insere_queue(3,&maliste);
    affiche(maliste);
    printf("ajout d'un 1 à la tête: \n");
    insere_tete(1,&maliste);
    affiche(maliste);
    printf("ajout d'un 7 à la queue: \n");
    insere_queue(7,&maliste);
    affiche(maliste);
    printf("ajout d'un 8 à la queue: \n");
    insere_queue(8,&maliste);
    affiche(maliste);
    printf("ajout d'un 1 à la tête: \n");
    insere_tete(1,&maliste);
    affiche(maliste);
    printf("ajout d'un 4 à la queue: \n");
    insere_queue(4,&maliste);
    affiche(maliste);

    //recherche des elements dans la liste: Validé
    if(recherche(0,maliste)) printf("le %d existe dans la liste \n",0);
    else printf("le %d n'existe pas dans la liste \n",0);
    if(recherche(5,maliste)) printf("le %d existe dans la liste \n",5);
    else printf("le %d n'existe pas dans la liste \n",5);
    if(recherche(6,maliste)) printf("le %d existe dans la liste \n",6);
    else printf("le %d n'existe pas dans la liste \n",6);
    if(recherche(1,maliste)) printf("le %d existe dans la liste \n",1);
    else printf("le %d n'existe pas dans la liste \n",1);
    //verification de la suppression: NON Validé
    printf("\n verification de la suppression : \n");
    affiche(maliste);
    printf("suppression de 1 de la liste: \n");
    supprime(1,&maliste);
    affiche(maliste);
    printf("suppression de 0 de la liste: \n");
    supprime(0,&maliste);
    affiche(maliste);
    printf("suppression de 3 de la liste: \n");
    supprime(3,&maliste);
    affiche(maliste);
    printf("suppression de 4 de la liste: \n");
    supprime(4,&maliste);
    affiche(maliste);


    //verification de l'inverse:
    printf("\n verification de l'inversion: \n");
    printf("voici ma liste avant l'inversion: \n");
    affiche(maliste);
    printf("après l'inversion: \n");
    inverse(&maliste);
    affiche(maliste);
    //verification de la liberation
    printf("liberation de ma liste: \n");
    libere(&maliste);
    affiche(maliste);
    

    return 0;
}