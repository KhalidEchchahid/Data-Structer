#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 32
#define true 1
#define false 2

typedef struct noeud
{
    char chaine[max];
    struct noeud *fg;
    struct noeud *fd;
}noeud,*arbre,*pnoeud;
//typedef struct noeud *arbre;
//typedef struct noeud *pnoeud;

arbre arbreVide()
{
    return NULL;
}

int estVide(arbre A)
{
    return A == NULL;
}

pnoeud creeNoeud(char* chaine)
{
    pnoeud p; p = (pnoeud)malloc(sizeof(noeud));
    strcpy(p->chaine,chaine);
    p->fg = NULL;
    p->fd = NULL;
    return p;
}

noeud racine(arbre A)
{
    if(!estVide(A))
    return *A;
}
        
arbre construire(noeud *r,arbre g,arbre d)
{
    if(!estVide(r))
    {
        r->fg = g;
        r->fd = d;
    }
}

void parcoursPrefixe(arbre A)
{
    if(!estVide(A))
    {
        noeud r;
        r = racine(A);
        printf("%s ",r.chaine);
        parcoursPrefixe(A->fg);
        parcoursPrefixe(A->fd);
    }    
}

void parcoursInfixe(arbre A)
{
    if(!estVide(A))
    {
        noeud r;
        parcoursInfixe(A->fg);
        r = racine(A);
        printf("%s ",r.chaine);
        parcoursInfixe(A->fd);
    }
}

void parcoursPostfixe(arbre A)
{
    if(!estVide(A))
    {
        noeud r;
        parcoursPostfixe(A->fg);
        parcoursPostfixe(A->fd);
        r = racine(A);
        printf("%s ",r.chaine);
    }
}

int taille(arbre A)
{
    if(!estVide(A))
    {
        return 1 + taille(A->fg) + taille(A->fd);
    }
    return 0;
}

int estFeuille(pnoeud p)
{
    if(!estVide(p))
    {
        if(estVide(p->fg) && estVide(p->fd)) return 1;
    }
    return 0;
}

int estEntier(char* ch)
{
    char chaine[max];
    sprintf(chaine,"%d",atoi(ch));
    if(strcmp(chaine,ch) == 0)
    return 1;
    else
    return 0;
}
int estOperateur(char* op)
{
    if(strcmp(op,"+") == 0) return 1;
    if(strcmp(op,"-") == 0) return 1;
    if(strcmp(op,"*") == 0) return 1;
    if(strcmp(op,"/") == 0) return 1;
    return 0;
}

int valide(arbre a)
{
        noeud r;
        r = racine(a);
        if(estFeuille(a))
        {
            if(!estEntier(r.chaine)) return 0;
            else return 1;
        }else
        {
           if(!estOperateur(r.chaine)) return 0;
           int c,d;
           c = valide(a->fg);d = valide(a->fd);
           return (c && d);
        }
}
int eval(arbre a)
{
    if(!estFeuille(a))
    {
        if(strcmp(a->chaine,"+") == 0) return eval(a->fg) + eval(a->fd);
        if(strcmp(a->chaine,"-") == 0) return eval(a->fg) - eval(a->fd);
        if(strcmp(a->chaine,"*") == 0) return eval(a->fg) * eval(a->fd);
        if(strcmp(a->chaine,"/") == 0) return eval(a->fg) / eval(a->fd);
    }else
    {
        return atoi(a->chaine);
    }
}

int maxi(int a,int b)
{
    if(a>b)return a;
    else return b;
}

int hauteur(arbre a)
{
    if(estFeuille(a)) return 0;
    return 1 + maxi(hauteur(a->fg),hauteur(a->fd));
}

int estComplet(arbre a)
{
    if(estVide(a)) return true;
    else
    if(estComplet(a->fg) && estComplet(a->fd)) return true;
    else false;
}



