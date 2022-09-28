#include "stdlib.h"
#include "stdio.h"

int main(){
  int x=0,s=0,i=0,precedent=NULL;
  int p=1;

  for (i=0;i<5;i++){
    printf("enter un nombre :\n");
    scanf("%d",&x);
    if (precedent<x && i!=0) p*=1;
    else if (i!=0) p*=0;
    s+=x;
    precedent=x;
  }
  printf("la somme est egale à:%d\n",s );
  if (p==0) printf("suite non stc croissant!\n");
  else printf("suite stc croissante!\n");
}
