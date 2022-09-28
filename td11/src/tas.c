#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
  int* data; // Tableau alloué dynamiquement d'éléments
  int max_size;    // Nombre maximal d'éléments
  int number;      // Nombre actuel d'éléments
} tas;
typedef tas* ptas;

void detruire_tas(tas* t);
tas* creer_tas(int n);
size_t fils_gauche(size_t index);
size_t fils_droit(size_t index);
size_t pere(size_t index);
bool est_tas_max(tas* t);
void inserer(tas* t, int nouveau);
int get_max_tas(tas* t);




/* int log2(int x){
    int t=0;
    while (x!=0){
        x/=2;
        t++;
    }
    return t;
} */

tas* creer_tas(int t){
    t=7;
    ptas p=calloc(1,sizeof(*p));
    p->data=calloc(t,sizeof(*(p->data)));
    p->max_size=7;
    p->number=0;
    return p;
}

void detruire_tas(tas* t){
    free(t->data);
    free(t);
}

size_t fils_gauche(size_t index){
    return index*2+1;
}

size_t fils_droit(size_t index){
    return 2*(index+1);
}

size_t pere(size_t index){
    return (index-1)/2;
}

bool est_tas_max(tas* t){
    int n=0;
    while(n<log2(t->number)){
        if(t->data[n]>t->data[fils_droit(n)] && t->data[n]>t->data[fils_droit(n)]) n++;
        else return false;
    }
    return true;
}

void inserer(tas* t, int nouveau){
    if(t->number==t->max_size){
        t->data=realloc(t->data,t->max_size*2*sizeof(*(t->data)));
        t->max_size=(t->max_size)*2;
    }
    t->data[t->number]=nouveau;
    int indice_nouveau=t->number;
    while(indice_nouveau !=0 && nouveau>t->data[pere(indice_nouveau)]){
        int stock=t->data[pere(indice_nouveau)];
        t->data[pere(indice_nouveau)]=nouveau;
        t->data[indice_nouveau]=stock;
        indice_nouveau=pere(indice_nouveau);
        t->number++;
    }
}

int get_max_tas(tas* t){
    return t->data[0];
}


