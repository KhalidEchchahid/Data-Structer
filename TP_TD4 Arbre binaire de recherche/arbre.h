#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef enum
{
    false,
    true,
}Bool;

typedef int Element;

typedef struct noeud
{
    Element val;
    struct noeud *fg;
    struct noeud *fd;
}Noeud,*ABR,*Pnoeud;

Bool est_vide(ABR A)
{
    return A == NULL;
}

Bool est_feuille(ABR A)
{
    if(est_vide(A)) return false;
    if(est_vide(A->fg) && est_vide(A->fd)) return true;
    return false;
}

ABR cree_ABR()
{
    return NULL;
}

Pnoeud cree_Noeud(Element e)
{
    Pnoeud p = (Pnoeud)malloc(sizeof(Noeud));
    p->val = e;
    p->fg = NULL;
    p->fd = NULL;
    return p;
}

ABR construire(Noeud* r,ABR g,ABR d)
{
    r->fg = g;
    r->fd = d;
    return r;
}

void print2DUtil(ABR A, int space) 
{ 
    int i;
    // Base case 
    if (A == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(A->fd, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", A->val); 
  
    // Process left child 
    print2DUtil(A->fg, space); 
} 
  
// Wrapper over print2DUtil() 
void affichage_ABR(ABR A) 
{ 
   // Pass initial space count as 0 
   print2DUtil(A, 0); 
}


//Execice 1 :fonction Inserer un valeur on respectant la forme ABR
ABR inserer(ABR A,Element valeur)
{
    if(est_vide(A)) 
    {
        Pnoeud p = cree_Noeud(valeur);
        return p ;
    }
    if(valeur < A->val) return construire(A,inserer(A->fg,valeur),A->fd);
    if(valeur > A->val) return construire(A,A->fg,inserer(A->fd,valeur));
    return A;
}

//Exercice 2 :fonction de destrucion d'un arbre.
void detruire(ABR A)
{
    if(est_vide(A)) return;
    detruire(A->fg);
    detruire(A->fd);
    printf("suppression de %d .\n",A->val);//juste pour savoir les noeuds en cours de suppressions
    free(A); A = NULL;
}

//Exercice 3: Affichage.
//affichage croissant
void afficher1(ABR A)
{
    if(!est_vide(A))
    {
        afficher1(A->fg);
        printf("%d ",A->val);
        afficher1(A->fd);
    }
}

void afficher2(ABR A)
{
    if(est_vide(A)) 
    {
        printf("_");return;
    }
    printf("{");afficher2(A->fg);
    printf(",%d,",A->val);
    afficher2(A->fd);printf("}");
}

//Exercice 4 
//fonction de verification d'un ABR

//foction qui copie un ABR Dans un tableau d'une facons croissante
void copy_ABR2Tab(ABR A,int* tab,int* n) //n indice , ou bien a la fin on l'utilise comme la taille de tableu
{
    if(!est_vide(A))
    {
        copy_ABR2Tab(A->fg,tab,n);
        tab[*n] = A->val;(*n)++;
        copy_ABR2Tab(A->fd,tab,n);
    }
}
//Fonction qui verifiet est ce qu'un tableau est trie croissant ou pas
Bool est_trie_tab(int* tab,int n)
{
    int i;
    for(i = 0;i < n - 1;i++) if(tab[i] > tab[i + 1]) return false;
    return true;
}

//fonction verifie

Bool verifie(ABR A)
{
    if(est_vide(A) || est_feuille(A)) return true;
    int tab[100],n = 0,i;
    copy_ABR2Tab(A,tab,&n);
    for(i = 0;i < n;i++) printf("%d ",tab[i]);//juste pour avoir aider sur le trie du tableau
    return est_trie_tab(tab,n);
}

//fonction taille qui renvoit le nombre de noeud

int taille(ABR A)
{
    if(est_vide(A)) return 0;
    return 1 + taille(A->fg) + taille(A->fd);
}

//fonction Hauteur d'ABR

int max(int a ,int b)
{
return (a > b ? a:b);
}

int Hauteur(ABR A)
{
    if(est_vide(A) || est_feuille(A)) return 0;
    else return 1 + max(Hauteur(A->fg),Hauteur(A->fd));
}

//foction de la somme

int somme(ABR A)
{
    if(est_vide(A)) return 0;
    else return A->val + somme(A->fg) + somme(A->fd);
}

// foction de la moyenne

float moyenne(ABR A)
{
    if(est_vide(A)) return 0;
    return ((float)somme(A)/taille(A));
}

//Exercice 5
//fontion de recherche sur un element dans l'arbre

Pnoeud chercher(ABR A, int valeur)
{
    if(est_vide(A)) return NULL;
    if(valeur < A->val) return chercher(A->fg,valeur);
    if(valeur > A->val) return chercher(A->fd,valeur);
    return A;
}
//foctions de maximum et minimum d'ABR

Pnoeud minimum(ABR A)
{
    if(est_vide(A->fg)) return A;
    return minimum(A->fg);
}

Pnoeud maximum(ABR A)
{
    if(est_vide(A->fd)) return A;
    return maximum(A->fd);
}

Pnoeud p;//varialble global
//fonction  successeur et  predecesseur

Pnoeud successeur(ABR A, int valeur)
{
    if(est_vide(A)) return p;
    if(valeur < A->val)
    {
        p = A;
        return successeur(A->fg,valeur);
    }
    else if(valeur > A->val) return successeur(A->fd,valeur);
    else
    {
        if(est_vide(A->fd)) return p;
        else return minimum(A->fd);
    }
}

Pnoeud  predecesseur(ABR A, int valeur)
{
    if(est_vide(A)) return p;
    if(valeur < A->val) return  predecesseur(A->fg,valeur);
    else if(valeur > A->val) 
    {
    p = A;return  predecesseur(A->fd,valeur);
    }
    else
    {
        if(est_vide(A->fg)) return p;
        else return maximum(A->fg);
    }
}

//Exercice 6 fonction de suppression a l'aide de foction max

ABR supp_max(ABR A)
{
    if(est_vide(A->fd)) return A->fg;
    else return construire(A,A->fg,supp_max(A->fd));
}

ABR supprimer(ABR A,int valeur)
{
    if(est_vide(A)) return A;
    if(valeur < A->val) return construire(A,supprimer(A->fg,valeur),A->fd);
    if(valeur > A->val) return construire(A,A->fg,supprimer(A->fd,valeur));
    else
    {
        if(!est_feuille(A))
        {
            ABR maxi; 
            maxi = maximum(A->fg);
            construire(maxi,supp_max(A->fg),A->fd);
        }
        else if(est_vide(A->fg)) return A->fd;
        else return A->fg;
    }
}

//Exercice 7 fonction de comparison

Bool equivalents(ABR A1, ABR A2)
{
    if(est_vide(A1)) return est_vide(A2);
    else if(est_vide(A2)) return false;
    else
    {
        if(A1->val != A2->val) return false;
        return equivalents(A1->fg,A2->fg)*equivalents(A1->fd,A2->fd);
    }
}


