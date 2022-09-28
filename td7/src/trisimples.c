#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TAILLE 1000

int* generer_donnees_test(unsigned n);
void tri_insertion(int tab[], unsigned taille);
void tri_max(int tab[], unsigned taille);


int* generer_donnees_test(unsigned n){
  int* donnees_test = malloc(n * sizeof(int));
  srand(time(NULL));
  for (size_t i = 0; i < n; i++) {
    donnees_test[i] = rand() % (10 * n);
  }
  return donnees_test;
}

void tri_max(int tab[], unsigned taille){
    int t=taille;
    while (t>0){
        if(t==1) break;
        int j=0;
        int max=tab[0];
        for (int i=1;i<t;i++){
            if(tab[i]>max){
                max=tab[i];
                j=i;
            }
        }
        if(j==t-1) t--;
        else{
            tab[j]=tab[t-1];
            tab[t-1]=max;
            t--;
        }   
    }
}
    

void tri_insertion(int tab[], unsigned taille){
    //int nombre;
    int stock;
    for (unsigned int i=1;i<taille;i++){
        //nombre=tab[i];
        for (unsigned int j=0;j<i;j++){
            if(tab[i]<tab[j]){
               stock=tab[j];
               tab[j]=tab[i];
               tab[i]=stock;
            }

        }
    }
    

}

    /*assert(taille!=0);
    if(taille==1) return;
    int j;
    int max=tab[0];
    for (int i = 1; i < taille; i++){
        if(tab[i]>max){
            max=tab[i];
            j=i;
        }
    }
    if(j==taille-1) tri_max(tab,taille-1);
    else{
        tab[j]=tab[taille-1];
        tab[taille-1]=max;
        tri_max(tab,taille-1);
    }   */


int main(){
    int tab1[TAILLE]={},tab2[TAILLE]={};
    for(int j=0;j<TAILLE;j++){
        tab1[j]=rand()%10000;
        tab2[j]=tab1[j];
    }
    for(int i=0;i<TAILLE;i++){
        printf("%d >",tab1[i]);
    }
    
    printf("\n");

    for(int i=0;i<TAILLE;i++){
        printf("%d >",tab1[i]);
    }
    puts(" ");

    printf("Voici tri par maximum : \n");
    tri_max(tab1,TAILLE);
    for (int i=0;i<TAILLE;i++){
        printf("%d >",tab1[i]);
    }
    puts(" ");
    printf("Voici tri par insertion : \n");
    tri_insertion(tab2,TAILLE);
    for (int i=0;i<TAILLE;i++){
        printf("%d >",tab2[i]);
    }    
    puts(" ");
    return 0;
}

