#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct noeud
{
  int valeur;
  struct noeud *left;
  struct noeud *right;
};

typedef struct noeud *arbre;
unsigned
max (unsigned a, unsigned b)
{
  if (a > b)
    return a;
  return b;
}

arbre
creer_noeud (int valeur)
{
  arbre a = malloc (sizeof (*a));
  a->valeur = valeur;
  return a;
}

bool
arbre_est_vide (arbre a)
{
  if (a != NULL)
    return false;
  else
    return true;
}

void
affiche (arbre a)
{
  if (a != NULL)
    {
      affiche (a->right);
      if (a->right != NULL)
	printf (" , ");
      printf ("%d", a->valeur);
      if (a->left != NULL)
	printf (" , ");
      affiche (a->left);
    }
}

void affiche_arbre (arbre a)
{
  affiche (a);
  printf ("\n");
}

void detruire_arbre (arbre a)
{
  if (arbre_est_vide (a))
    return;
  detruire_arbre (a->left);
  detruire_arbre (a->right);
  free (a);
}

unsigned hauteur (arbre a)
{
  int h1 = 0, h2 = 0;
  if (arbre_est_vide (a))
    return 0;
  if (!arbre_est_vide (a->left))
    h1 = 1 + hauteur (a->left);
  else if (!arbre_est_vide (a->right))
    h2 = 1 + hauteur (a->right);
  return max (h1, h2);
}

arbre insere (arbre arbre, int valeur)
{
  if (arbre == NULL)
    return creer_noeud (valeur);
  else
    {
      if (valeur < arbre->valeur)
	arbre->right = insere (arbre->right, valeur);
      else
	arbre->left = insere (arbre->left, valeur);
      return arbre;

    }
}

void affiche_arbre2_rec (arbre arbre)
{
  if (arbre == NULL)
    printf ("_");
  else
    {
      printf (" { ");
      affiche_arbre2_rec (arbre->right);
      printf (",%d,", arbre->valeur);
      affiche_arbre2_rec (arbre->left);
      printf (" } ");
    }
}

void affiche_arbre2 (arbre arbre){
  affiche_arbre2_rec (arbre);
  printf (" \n");
}

int main ()
{
  arbre a = creer_noeud (5);
  //arbre arbre=NULL;
  for (size_t i = 0; i < 5; i++)
    insere (a, i);
  /*insere(a,8);
     insere(a,1); */

  affiche_arbre (a);
  affiche_arbre2 (a);
  printf ("hauteur=%d\n", hauteur (a));
  bool b = arbre_est_vide (a);
  if (b)
    printf ("vide\n");
  else
    printf ("no vide\n");

  return 0;
}
