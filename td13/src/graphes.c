#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int n;
    int** tab;
    int* parcours;
}graphe;

graphe* creer_graphe_vide(unsigned nb_sommets);
void detruire_graphe(graphe* g);
void parcours_profondeur(graphe* g, unsigned sommet_depart);
void parcours_largeur(graphe* g, unsigned sommet_depart);


graphe* creer_graphe_vide(unsigned nb_sommets){
    graphe* p_graph=calloc(1,sizeof(*p_graph));
    p_graph->n=nb_sommets;
    p_graph->tab=(int**)calloc(1,nb_sommets*sizeof(int*));
    if (p_graph->tab==NULL){
        perror("Error d'allocation \n");
        return NULL;
    }else{
        p_graph->tab[0]=(int*)calloc(nb_sommets*nb_sommets,sizeof(int));
        if(p_graph->tab[0]==NULL){
            free(p_graph->tab);
            perror("Error deuxieme alloc");
            return NULL;
        }else{
            for(int j=1;j<(int)nb_sommets;j++){
                p_graph->tab[j]=p_graph->tab[j-1]+nb_sommets;
            }
        }
    }
    p_graph->parcours=calloc(1,(p_graph->n)*sizeof(int));
    for(int i=0;i<(int)nb_sommets;i++){
        for(int t=0;t<(int)nb_sommets;t++){
            p_graph->tab[i][t]=0;
        }
    }
    return p_graph;
}


void detruire_graphe(graphe* g){
    free(g->tab[0]);
    free(g->tab);
    free(g);
}

graphe* remplir_graphe_avec_fichier_dot(const char* chemin_fichier_dot){
  graphe* g = NULL;
  int nb_sommets;
  unsigned sommet_source;
  unsigned sommet_cible;

  FILE* fp_dot = fopen(chemin_fichier_dot, "r");
  if (fp_dot == NULL) {
    fprintf(stderr, "Erreur d'ouverture du fichier %s\n", chemin_fichier_dot);
    exit(EXIT_FAILURE);
  }

  if (fscanf(fp_dot, "// %d nodes", &nb_sommets) != 1) {
    printf("nombre de sommets %d \n",nb_sommets);
    fprintf(stderr, "Erreur de lecture du nombre de sommets\n");
    exit(EXIT_FAILURE);
  }
  printf(" le nombre de sommets est : %d \n",nb_sommets);
  g=creer_graphe_vide(nb_sommets);  

  fscanf(fp_dot, "%*s {"); // Opérateur * pour ne pas réaliser d'affectation

  while (fscanf(fp_dot, "%d -> %d",
                &sommet_source,
                &sommet_cible) == 2) {
    g->tab[sommet_source][sommet_cible]=1;
  }
  fclose(fp_dot);
  return g;
}


void parcours_profondeur(graphe* g, unsigned sommet_depart){
    /*int parcours[sommet_depart]=1;
    for(int i=0;i<n;i++){
       parcours[i]=0;
        for(int j=0;j<n;j++){
            if(g->tab[sommet_depart][j]==1 && parcours[j]==1){
                printf("%d ,",j);
                parcours[j]=1;
                parcours_profondeur(g,j);
            }
        }
    } */
    g->parcours[sommet_depart]=1;
    printf("%d ,",sommet_depart);    
    for(int j=0;j<g->n;j++){
        //if(g->parcours[sommet_depart]!=1){
            if(g->tab[sommet_depart][j]==1 && g->parcours[j]==0 ){
                //printf("%d ,",j);
                parcours_profondeur(g,j);
            }
        //}
    }
}

void init_parcours(graphe* g){
    for(int i=0;i<g->n;i++){
        g->parcours[i]=0;
    }
}
void parcours_largeur(graphe* g, unsigned sommet_depart){
    g->parcours[sommet_depart]=1;
    printf("%d ,",sommet_depart);
    for(int i=0;i<g->n;i++){
        if(g->parcours[i]==1){
            for (int j = 0; j <g->n; j++){
                if(g->tab[i][j]==1 && g->parcours[j]==0){
                printf("%d ,",j);
                g->parcours[j]=1;
                }
            }
            
        }
    }
    
} 

void vider_parcours(graphe* g){
    for(int i=0;i<g->n;i++){
        g->parcours[i]=0;
    }
}



int main(int argc,char* argv[] ){
    graphe* g=remplir_graphe_avec_fichier_dot(argv[1]);
    printf("le nombre de sommets est %d \n",g->n);
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("[ %d ]",g->tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    parcours_profondeur(g,0);
    printf("\n");
    vider_parcours(g);
    parcours_largeur(g,0);
    printf("\n");
    return 0;
}

