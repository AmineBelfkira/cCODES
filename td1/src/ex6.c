#include<stdio.h>
#include<stdlib.h>

unsigned compteur_appels;

int effet(int a) {
    printf(" coucou ! \n"); /* ligne 3 */
    compteur_appels = compteur_appels + 1;
    return a + compteur_appels;
}

void main() {
    int x, y;

    compteur_appels = 0;
    scanf("%d", &x);
    y = effet(x) + effet(x);
    printf("%d\n", y); /* ligne 1 */
    y = 2 * effet(x);
    printf("%d\n", y); /* ligne 2 */
    printf("ca = %u\n", compteur_appels);
}
