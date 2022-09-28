#include <stdlib.h>
#include <stdio.h>

void traitement_sequentiel(){
  int courant,avant,p=1;
  int somme=0, max,i=2;
  int occpremier=0,occdernier=0;
  printf("entrer un nombre:\n");
  scanf("%d", &courant);
  somme=courant;
  max=courant;
  while (courant != -1) {
    avant=courant;
    printf("entrer un nombre:\n");
    scanf("%d", &courant);
    if(max<courant) occpremier=i;
    if (max<=courant) {
        max=courant;
        occdernier=i;
    }
    if (courant<avant) p*=0;
    else p*=1;
    somme+=courant;
    i++;
    
  }
  printf("la somme est egale à: %d\n",somme);
  if (p==1) printf("la suite est bien croissante\n");
  else printf("la suite n'est pas croissante\n");
  printf("le maximum est %d\n",max);
  printf("premiere occurance du max %d\n",occpremier);
  printf("derniere occurance du max %d\n",occdernier);
}

int main() {
    traitement_sequentiel();
}
