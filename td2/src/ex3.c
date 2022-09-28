#include <stdio.h>
#include <stdlib.h>
//fonction itérative de fibonacci
long fibonacci(int n);
// la compléxité de cette fonction est: 3n
long fibonacci(int n){
    long c0=0, c1=1, c;
    if(n==0) return c0;
    if(n==1) return c1;
    for(int i=0;i<=(n-2);i++){
        c=c0+c1;
        c0=c1;
        c1=c;
    }
    return c;
}

//fonction recursive de fibonacci
long fibonaccirec(int n);
// la compléxité de cette fonction est: 
long fibonaccirec(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonaccirec(n-1)+fibonaccirec(n-2);
}


int main(){
    int n=30;
    printf ("le %dième nombre de la suite de fibonacci est: %ld\n",n,fibonacci(n));
    printf ("le %dième nombre de la suite de fibonacci récursive est: %ld\n",n,fibonaccirec(n));
    return 0;
}

