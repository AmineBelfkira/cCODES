#include<stdio.h>
#include<stdlib.h>


int main(){
    int x1, x2, x3, x4, x5, x6;
    printf("Entrez les 6 chiffres à opérer: \n");
    scanf("%d %d %d %d %d %d",&x1,&x2,&x3,&x4,&x5,&x6);
    printf("la somme de ces nombre est : %d \n",x1+x2+x3+x4+x5+x6);
    printf("la comb de ces nombre est : %d \n",x1*x2+x3*x4+x5*x6);
    return 0;

}