#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct coordonnee {
  float lat;
  float lon;
} T;

typedef struct _cellule {
  T element;
  struct _cellule* suivante;
} cellule;
typedef cellule* liste;



typedef struct {
  liste* table;
  unsigned capacite; /* capacité de la table */
  unsigned nb_elements; /* nombres d'éléments dans la table */
  unsigned capacite_initiale; /* utile lors du redimensionnement */
} table_hachage;

int hash(T element);
bool identiques(T element_1, T element_2);
bool est_present(T element, table_hachage* ht);
void inserer_sans_redimensionner(T element, table_hachage* ht);
void afficher_table(table_hachage* ht);
void affiche(liste l);

int hash(T element){
  return element.lat+element.lon;
}

bool identiques(T element_1, T element_2){
    return (element_1.lat==element_2.lat && element_1.lon==element_2.lon);
}

bool est_present(T element, table_hachage* ht){
  liste l=ht->table[hash(element)%ht->capacite];
  if(l==NULL) return false;
  else{
    while (l!=NULL){
      if(identiques(l->element,element)) return true;
      l=l->suivante;
    }
    return false;
  }
}

void inserer_sans_redimensionner(T element, table_hachage* ht){
  if (est_present(element,ht)) return;
  else{
    liste l1=ht->table[hash(element)%(ht->capacite)];
    liste l2;
    if(l1==NULL){
      ht->table[hash(element)%(ht->capacite)]=calloc(1,sizeof(*l1));
      ht->table[hash(element)%(ht->capacite)]->element.lat=element.lat;
      ht->table[hash(element)%(ht->capacite)]->element.lon=element.lon;
    }
    else{
      l2=calloc(1,sizeof(*l2));
      l2->element.lat=element.lat;
      l2->element.lon=element.lon;
      l2->suivante=l1;
      ht->table[hash(element)%(ht->capacite)]=l2;
    }
    ht->nb_elements++;
  }
}

void affiche(liste l){
    if(l==NULL){
      printf("liste vide \n");
      return;
    }
    do{
        printf("[%f,%f] ",l->element.lat,l->element.lon);
        l=l->suivante;
    }while(l!=NULL);
    puts(" ");
}

void afficher_table(table_hachage* ht){
  if(ht==NULL)printf("table vide \n");
  else{
    for(int i=0;i<ht->capacite;i++){
      printf("la case numèro %d contient ces éléments: \n",i);
      affiche(ht->table[i]);
      printf("\n");
    }
  }
}

#define TAILLE 500000
int main(){
  //initialisation de la table de hashage:
  table_hachage ht;
  ht.capacite=TAILLE;
  ht.nb_elements=0;
  ht.capacite_initiale=0;
  ht.table=calloc(TAILLE,sizeof(*(ht.table)));
  //insertion dans la table:
  printf("insertion dans la table: \n");
  T e1;
  int i=0;
  while(i<82540){
    e1.lat=i;
    e1.lon=i+1;
    inserer_sans_redimensionner(e1,&ht);
    i++;
  }
  /*e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12;
  e1.lat=0;e1.lon=5;e2.lat=1;e2.lon=1;e3.lat=3;e3.lon=1;
  e4.lat=4;e4.lon=1;e5.lat=1;e5.lon=5;e6.lat=6;e6.lon=1;
  e7.lat=7;e7.lon=1;e8.lat=4;e8.lon=2;e9.lat=3;e9.lon=3;
  e10.lat=2;e10.lon=5;e11.lat=11;e11.lon=1;e12.lat=6;e12.lon=2;
  printf("affichage table vide: \n");
  afficher_table(&ht);
  printf("insertion premier element: \n");
  inserer_sans_redimensionner(e1,&ht);
  afficher_table(&ht);
  printf("insertion autres elements: \n");
  inserer_sans_redimensionner(e1,&ht);
  inserer_sans_redimensionner(e2,&ht);
  inserer_sans_redimensionner(e3,&ht);
  inserer_sans_redimensionner(e4,&ht);
  inserer_sans_redimensionner(e5,&ht);
  inserer_sans_redimensionner(e6,&ht);
  inserer_sans_redimensionner(e7,&ht);
  inserer_sans_redimensionner(e8,&ht);
  inserer_sans_redimensionner(e9,&ht);
  inserer_sans_redimensionner(e10,&ht);
  inserer_sans_redimensionner(e11,&ht);
  inserer_sans_redimensionner(e12,&ht);*/
  est_present(e1,&ht);
  afficher_table(&ht);

  return 0;
}
