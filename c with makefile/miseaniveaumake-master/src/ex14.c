#include "stdlib.h"
#include "stdio.h"


int max2(int x, int y){
  if (x<y) return y;
  else return x;
}
int max3(int x, int y, int z){
  int p;
  p=max2(x,y);
  p=max2(p,z);
  return p;
}

int main(){
  int x,a,b,c;
  printf("entrer un nombre entier:\n");
  scanf ("%d",&a);
  printf("entrer un nombre entier:\n");
  scanf ("%d",&b);
  printf("entrer un nombre entier:\n");
  scanf ("%d",&c);
  x=max2(a,b);
  printf("max de %d et %d est: %d\n",a,b,x);
  x=max3(a,b,c);
  printf("max de %d et %d et %d est: %d\n",a,b,c,x);

}
