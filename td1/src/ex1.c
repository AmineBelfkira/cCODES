#include<stdio.h>
#include<stdlib.h>

void echange() {
    int t, x, y;

    printf("Entrez l'entier x\n");
    scanf("%d", &x); /* ici x vaut x0 */
    printf("Entrez l'entier y\n");
    scanf("%d", &y); /* ici y vaut y0 */
    /*x=1 et y=2*/
    t = x;
    x = y;           /* point d'observation (1) : x vaut 2, y vaut 2 */
    //t = x;           /* point d'observation (2) : t vaut 2 */
    y = t;           /* point d'observation (3) : y vaut 2 */
    printf("x = %d ; y = %d\n", x, y);
}

int main(void) {
    echange();
    return EXIT_SUCCESS;
}