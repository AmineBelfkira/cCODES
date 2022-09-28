#include "stdlib.h"
#include "stdio.h"

void echange() {
    int t, x, y;

    printf("Entrez l'entier x\n");
    scanf("%d", &x); /* ici x vaut x0 */
    printf("Entrez l'entier y\n");
    scanf("%d", &y); /* ici y vaut y0 */
    t = x;           /* point d'observation (2) : t vaut ... */
    x = y;           /* point d'observation (1) : x vaut ..., y vaut ... */
    y = t;           /* point d'observation (3) : y vaut ... */
    printf("x = %d ; y = %d\n", x, y);
}

int main(void) {
    echange();
    return EXIT_SUCCESS;
}
