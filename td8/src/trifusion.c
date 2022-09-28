#include <stdio.h>
#include <stdlib.h>

void tri_fusion(int tab[], unsigned taille);
int* fusionner(int tab1[],unsigned taille1,int tab2[],unsigned taille2);
int* fusionner(int tab1[],unsigned taille1,int tab2[],unsigned taille2){
    /*if (taille1==1 && taille2==1){
        if (*tab1<*tab2){
            return tab1;
        }
        return tab2;
    }*/
    
    int tab[(taille1+taille2)];
    unsigned int i=0,j=0,k=0;
    while(i!=taille1 || j!=taille2){
        if (tab1[i]<tab2[j]){
            tab[k]=tab1[i];
            i++;k++;
        }
        else{
            tab[k]=tab2[j];
            j++;k++;
        }
    }
    while (i<taille1){
        tab[k]=tab1[i];
        i++;k++;
    }
    while (j<taille2){
        tab[k]=tab2[j];
        j++;k++;
    }

    
    /*if(k!=(taille1+taille2)){
        if(i==taille1){
            for(unsigned int t1=k;t1<taille1+taille2;t1++){
                tab[k]=tab2[j];
                j++;
            }
        }
        else{
            for(unsigned int t2=k;t2<taille1+taille2;t2++){
                tab[k]=tab1[i];
                i++;
            }
        }
    }*/
    return tab;
}


void tri_fusion(int tab[], unsigned taille){
    //int stock;
    //if (taille!=1){
        tri_fusion(tab,taille/2);
        tri_fusion(tab+taille/2+1,taille-taille/2);
        tab=fusionner(tab,taille/2,tab+taille/2+1,taille-taille/2);
    //}
    /*else if (taille==1){
        if (*tab>*(tab+taille)){
            stock=*tab;
            *tab=*(tab+taille);
            *(tab+taille)=stock;
        }
        taille=taille*2;
    }*/
}


int main(){
    int tab1[10]={};
    for(int j=0;j<10;j++){
        tab1[j]=rand()%20;
    }
    for(int i=0;i<10;i++){
        printf("%d >",tab1[i]);
    }
    puts(" ");

    printf("Voici tri par fusion : \n");
    tri_fusion(tab1,10);
    for (int i=0;i<10;i++){
        printf("%d >",tab1[i]);
    }
    puts(" ");
    return 0;
}