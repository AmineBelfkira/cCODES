# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


bool est_permut(unsigned p[], unsigned taille){
  /*int n=taille*(taille+1)/2;*/
  for (size_t i=0;i<taille;i++){
    if ((p[i]<0) || (p[i]>taille-1)) return 0;
  }
  int* tab = malloc(taille * sizeof(int));
  for (size_t i=0;i<taille;i++){
    tab[i]=i;
  }
  for(size_t i=0;i<taille;i++){
    if(tab[p[i]]==-1) return 0;
    tab[p[i]]=-1;
  }
  return 1;
  free(tab);
}
int main(){
    unsigned taille = 10;
    /* allocation sur le tas */
    unsigned* tab = malloc(taille * sizeof(int));
    tab[0] = 2; tab[1] = 1; tab[2] = 4; tab[3] = 6; tab[4] = 7;
    tab[5] = 3; tab[6] = 5; tab[7] = 8; tab[8] = 0; tab[9] = 9;
    int i=0;
    while (i<10) {
      printf("tab[%d]=%d  ",i,tab[i]);
      i++;
    }
    printf("\n");
    bool v=est_permut(tab,10);
    if (v==true) printf("C'est une permutation\n");
    else printf("C'est pas une permutation\n");
    return EXIT_SUCCESS;
    free(tab);
}
