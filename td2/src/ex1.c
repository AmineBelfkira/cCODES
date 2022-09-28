#include <stdio.h>
#include <stdlib.h>

void traitement_sequentiel(){
  int courant; /* l'entier lu */
  /* ... variables servant au calcul */  
  int c=1;
  printf("donnez un nombre: \n");
  scanf("%d", &courant);
  /* ... initialisation des variables */
  int s=0, c1=courant, max=courant;
  int procc=1, nbocc=1, drocc=0;
  int j=0;
  while (courant != -1) {
    /* ... traitement a l'interieur de la boucle */
    j++;
    //ici la somme
    s=s+courant;
    scanf("%d", &courant);
    //ici la croissance
    if(c1>courant && courant!=-1 ) c=0;
    c1=courant;
    // ici le max et les occurrences:
    if(max<courant){
        procc=j;
        nbocc=0;
        max=courant;
    }
    if(max==courant){
          nbocc++;
          drocc=j;
    }
  }
  /* ... traitement final */
  printf("la somme des nombre est: %d\n",s);
  if(c==1) printf("la suite est croissante \n");
  else printf("la suite n'est pas croissante \n");
  printf("la maximum de la suite est %d\n",max);
  printf("la position de la premiere occurence du maximum est: %d\n",procc);
  printf("le nombre d'occurrences de maximum est: %d\n", nbocc);
  printf("la derniere occurrence d'un maximum est: %d\n", drocc);
   /* affichage du resultat */
}


int main(){
  traitement_sequentiel();
  return 0;
}