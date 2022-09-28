# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

bool est_reflexive(int r[10][10]){
    int mul[10][10];
    int n,i,j,k;
    printf("taille?:");
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mul[i][j]=0;
            for(k = 0; k < n; k++)  mul[i][j] += r[i][k] * r[k][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) if (mul[i][j]!=r[i][j]) return 0;
    }
    return 1;


}

void main(){
    int matrice[10][10];
    int i,j,n;
    printf("Entrez le nombre de lignes :\n");
    scanf("%d",&n);

    printf("Entrez les éléments de la matrice\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++) scanf("%d", &matrice[i][j]);
    }
    printf("La matrice:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) printf("%d\t", matrice[i][j]);

    }
    printf("\n");
    int p=est_reflexive(matrice);
    if (p==0) printf("non reflexive\n");
    else printf("reflexive\n");
}
