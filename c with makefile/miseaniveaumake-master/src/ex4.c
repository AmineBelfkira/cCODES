# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool est_present_trie_dicho(int tab[], unsigned taille, int valeur){
  int premier,milieu,dernier;
  premier=0;
  dernier=taille-1;
  while (premier<=dernier){
    milieu=(premier+dernier)/2;
    if (tab[milieu]==valeur) return 1;
    else if(tab[milieu]>valeur) dernier=milieu-1;
    else premier=milieu+1;
  }
  return 0;
}

int main(){
    unsigned taille = 10;
    /* allocation sur le tas */
    int* tab = malloc(taille * sizeof(int));
    tab[0] = 2; tab[1] = 8; tab[2] = 10; tab[3] = 14; tab[4] = 17;
    tab[5] = 50; tab[6] = 60; tab[7] = 300; tab[8] = 900; tab[9] = 970;
    int i=0;
    while (i<10) {
      printf("tab[%d]=%d  ",i,tab[i]);
      i++;
  }
    int x;
    printf("\n");
    printf("entrer une valeur:");
    scanf("%d",&x);
    bool v=est_present_trie_dicho(tab,10,x);
    if (v==1) printf("Cette valeur appartient à la liste\n");
    else printf("Cette valeur n'appartient pas à la liste\n");
    return EXIT_SUCCESS;
    free(tab);
}
