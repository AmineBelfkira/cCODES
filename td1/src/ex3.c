#include<stdio.h>
#include<stdlib.h>


void echange(int* x, int* y);

void echange(int* x, int* y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

int main(){
    int x, y;
    printf("entrez deux nombres: \n");
    scanf("%d %d",&x,&y);
    echange(&x,&y);
    printf("la valeur de x est: %d \n la valeur de y est: %d\n",x,y);
    return 0;
}