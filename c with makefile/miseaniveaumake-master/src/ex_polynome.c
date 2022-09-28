# include <stdio.h>
      
int main() {
  int n,i;
  float res,a,x;

  printf("Degre:  ");
  scanf("%d",&n);
  printf("Valeur de x:");
  scanf("%f",&x);
  for( i = n ; i >= 0 ; i--){
      printf("Coef à l'ordre %d\n",i);
      scanf("%f",&a);
      if (i==n)
        res = a;
      else
        res=res*x+a;
    }
  printf("La valeur du polynome en x=%f est egale à %f\n",x,res);
}  
