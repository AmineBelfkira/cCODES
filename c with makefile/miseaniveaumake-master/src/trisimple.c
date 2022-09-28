#include <time.h>
#include <stdlib.h>
#include <stdio.h>


int* generer_donnees_test(unsigned n)
{
  int* donnees_test = malloc(n * sizeof(int));
  srand(time(NULL));
  for (size_t i = 0; i < n; i++) {
    donnees_test[i] = rand() % (10 * n);
  }
  return donnees_test;
}

void tri_max(int tab[], unsigned taille){
    int max=tab[0];
    for (int i=taille-1;i>=0;i--){
        max=tab[i];
        for (int j=0;j<i;j++){
            if (tab[j]>max) {
                max=tab[j];
                tab[j]=tab[i];
                tab[i]=max;
                } 
        }
        
    }
}
void tri_insertion(int tab[], int taille){
    int min=tab[0];
    for (int i=0;i<taille;i++){
        min=tab[i];
        for (int j=i;j<taille;j++){
            if (tab[j]<min) {
                min=tab[j];
                tab[j]=tab[i];
                tab[i]=min;
                } 
        }
    }
}

int main() {
    int  nbr, i, tab[100];
 
    printf(" Entrez  nombre d'éléments: ");
    scanf("%d", &nbr);
    for (i = 0; i < nbr; i++){
        printf(" Entrez un entier : ");
        scanf("%d", &tab[i]);
    }
    tri_max(tab,nbr);
    printf("\nTableau trié : ");
    printf("%d", tab[0]);
    for(i = 1; i < nbr; i++)  {
     printf(" < %d", tab[i]);
    }
    printf("\n");
    tri_insertion(tab,nbr);
    printf("\nTableau trié : ");
    printf("%d", tab[0]);
    for(i = 1; i < nbr; i++)  {
     printf(" < %d", tab[i]);
    }
    printf("\n");
    return 0;
}

