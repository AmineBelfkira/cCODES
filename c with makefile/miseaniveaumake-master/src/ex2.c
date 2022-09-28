#include "stdlib.h"
#include "stdio.h"

int main(){
  int x=0,s=0,i=0;
  for (i=0;i<5;i++){
    printf("enter un nombre :\n");
    scanf("%d",&x);
    s+=x;
  }
  printf("la somme est egale à:%d\n",s );
}
