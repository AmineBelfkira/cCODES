#include <stdlib.h>
#include <stdio.h>

void Fusion(int* tab, int deb, int fin){
    int milieu=(deb+fin)/2;
    int j,i=0,a=deb,b=milieu+1;
    int temp[50];
 
    while(a<milieu && b<fin){
        if(tab[a] < tab[b]){
            temp[i]=tab[a];
            a++;
        }
        else{
            temp[i]=tab[b];
            b++;
        }
        i++;
    }
    if(a < milieu){
        for(j=a;j<milieu;j++,i++)     
        temp[i]=tab[j];
    }
    else if(b < fin){
        for(j=b;j<fin;j++,i++)
        temp[i]=tab[j];
    }
    for(i=deb;i<fin;i++) tab[i]=temp[i];
}
/*void TriFusion(int* tab, int deb, int fin){
    int milieu;
    if(deb<fin){
      milieu=(deb+fin)/2;
      TriFusion(tab,deb,milieu);
      TriFusion(tab,milieu+1,fin);
    }
    Fusion(tab,deb,fin);
}*/
void TriFusion(int* tab, int deb, int fin){
    int milieu;
    if(deb<fin){
        milieu=(deb+fin)/2;
        if(milieu>deb) TriFusion(tab,deb,milieu);
        if(milieu+1<fin) TriFusion(tab,milieu+1,fin);
        Fusion(tab,deb,fin); 
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
    for (i = 0; i < nbr; i++){
        printf(" %d - >",tab[i]);
    } printf(" ");
    TriFusion(tab,0,nbr-1);
    printf("\nTableau trié : ");
    for(i = 0; i < nbr; i++)  {
     printf(" -> %d", tab[i]);
    }
    printf("\n");
    return 0;
}