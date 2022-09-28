#include <stdlib.h>
#include <stdio.h>
#include <time.h>

long fibonacci(unsigned n){
    if (n==0 || n==1) return n;
    else return(fibonacci(n-1)+fibonacci(n-2));
    
}
long FIBONACCI1(int n){
   int x=0,y=1,z;
   if (n==0 || n==1) return n;
   for (int i=1;i<n;i++){
       z=y;
       y=x+y;
       x=z;
   }
   return y;
}


int main() {
    int x,y,n;
    float temps;
    clock_t t1, t2 ;
    
    printf("entrer un nombre:");
    scanf("%d",&n);
    
    t1 = clock();
    x=fibonacci(n);
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("le valeur est : %d              ",x);
    printf("temps1 = %f\n", temps);
    
    t1 = clock();
    y=FIBONACCI1(n);
    t2 = clock();
    temps = (float)(t2-t1)/CLOCKS_PER_SEC;
    printf("le valeur est : %d              ",y);
    printf("temps2 = %f\n", temps);
    
}
