#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>


struct lis{
    int som;
    struct lis* next;
};

typedef struct lis* liste;

void insere_tete(int nouveau, liste* pl){
    liste l=calloc(1,sizeof(*l));
    l->som=nouveau;
    l->next=(*pl);
    *pl=l;
}
void libere(liste* pl){
    if(*pl==NULL) printf("liste vide");
    liste asuprimer;
    while((*pl)!=NULL){
        asuprimer=(*pl);
        (*pl)=(*pl)->next;
        free(asuprimer);
    }
    
}

typedef struct{
    int n;
    double** tab;
    int* parcours;
}graphe;

graphe* creer_graphe_vide(unsigned nb_sommets);
void detruire_graphe(graphe* g);
void parcours_profondeur(graphe* g, unsigned sommet_depart);
void parcours_largeur(graphe* g, unsigned sommet_depart);


graphe* creer_graphe_vide(unsigned nb_sommets){
    graphe* p_graph=calloc(1,sizeof(*p_graph));
    p_graph->n=nb_sommets;
    p_graph->tab=(double**)calloc(1,nb_sommets*sizeof(double*));
    if (p_graph->tab==NULL){
        perror("Error d'allocation \n");
        return NULL;
    }else{
        p_graph->tab[0]=(double*)calloc(nb_sommets*nb_sommets,sizeof(int));
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
            p_graph->tab[i][t]=-1;
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
  double cout;

  FILE* fp_dot = fopen("graph.dot", "r");
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

  while (fscanf(fp_dot, "  %d -> %d [label=%lf]",
                &sommet_source,
                &sommet_cible,&cout) == 3) {
    g->tab[sommet_source][sommet_cible]=cout;
    printf("j'ai ajouté à %d et %d le cout %lf",sommet_source,sommet_cible,cout);
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


int* bellman_ford(graphe* g, unsigned depart){
    //initialiser le tableau des distances : dist
    double* distances=calloc(1,g->n*sizeof(double));
    for(int i=0;i<g->n;i++){
        distances[i]=INT_MAX;
        printf("%lf  ",distances[i]);
    }
    printf("\n");
    //initialiser le tableau des prédécesseurs : pred
    int* predecesseur=calloc(1,g->n*sizeof(int));
    for(int j=0;j<g->n;j++){
        predecesseur[j]=-1;
        printf("%d   ",predecesseur[j]);
    }
    printf("\n");
    /* pour tous les sommets du graphe :
        pour chaque arc (a, b) du graphe :
            si dist[b] > dist[a] + poids(a, b) :
                dist[b] = dist[a] + poids(a, b)
                pred[b] = a
        retourner pred */ 
    distances[depart]=0;
    //predecesseur[depart]=depart;
    for(int t=0;t<g->n;t++){
        for(int r=0;r<g->n;r++){
            if(g->tab[t][r]>=0){
                printf("je suis dans %d,%d\n",t,r);
                if(distances[r]>distances[t]+g->tab[t][r]){
                    distances[r]=distances[t]+g->tab[t][r];
                    predecesseur[r]=t;
                    printf("pred[%d]=%d\n",r,predecesseur[r]);
                }
            }
        }
    }
    printf("j'ai terminé \n");
    for(int a=0;a<g->n;a++){
        printf("a=%d\n",a);
        printf("%d   ",predecesseur[a]);
    }
    printf("\n");
    //free(distances);
    return predecesseur;
}

void affiche_chemin(int* predecesseurs, unsigned depart, unsigned arrivee){
    liste l=NULL;//=malloc(sizeof(*l));
    //l->som=arrivee;
    unsigned pred=arrivee;
    int limit=0;
    while(pred!=-1 && limit<4){
        insere_tete(pred,&l);
        printf("j'ai insérer %d, je passe à son predecesseur qui est %d\n",pred,predecesseurs[pred]);
        pred=predecesseurs[pred];
        limit++;
    }
    liste p=l;
    if(p->som==depart){
        printf("le chemin existe et c'est :\n");
        while (p!=NULL){
            printf("->%d",p->som);
            p=p->next;
        }
        printf("\n");
    }else{
        printf("le chemin n'existe pas :\n");
    }
    
    libere(&l);
}

int main(int argc,char* argv[] ){
    graphe* g=remplir_graphe_avec_fichier_dot("graph.dot");
    printf("le nombre de sommets est %d \n",g->n);
    for(int i=0;i<g->n;i++){
        for(int j=0;j<g->n;j++){
            printf("[ %lf ]",g->tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int* predec=bellman_ford(g,0);
    affiche_chemin(predec,0,3);
    affiche_chemin(predec,0,1);
    affiche_chemin(predec,0,2);
    predec=bellman_ford(g,2);
    affiche_chemin(predec,2,1);
    affiche_chemin(predec,2,3);

    detruire_graphe(g);
    return 0;
}
