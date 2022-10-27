#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct element
{
    char* chaine;
    struct element* suiv;
}element;

typedef struct
{
    element* prem;
    element* dern;
    int nb;
}pile;

typedef enum
{
    false,
    true,
}bool;

bool estVide(pile* pi)
{
    if(pi->nb == 0) return true;
    return false;
}

void initialPile(pile* pi)
{
    pi->dern = NULL;
    pi->prem = NULL;
    pi->nb = 0;
}

pile* creePile()
{
    pile* pi;
    pi = (pile*)malloc(sizeof(pile));
    initialPile(pi);
    return pi;
}

element* creeElement(char* chaine)
{
    element* e;
    e = (element*)malloc(sizeof(element));
    e->chaine = chaine;
    e->suiv = NULL;
    return e;
}

void empiler(pile* pi,char* chaine)
{
    element* e;
    e = creeElement(chaine);
    if(estVide(pi))
    {
        pi->prem = e;
        pi->dern = e;
    }
    else
    {
        e->suiv = pi->prem;
        pi->prem = e;
    }
    pi->nb++;
}

void afficherPile(pile* pi)
{
    if(estVide(pi))
    {
        printf("rien a afficher \n");return;
    }
    element* e;e = pi->prem;
    while(e != NULL)
    {
        printf("%s ",e->chaine);
        e = e->suiv;
    }
    printf("\n");
}

int depiler(pile* pi)
{
    if(estVide(pi)) return -1;
    element* e;e = pi->prem;
    if(pi->nb == 1)
    {
        initialPile(pi);
    }
    else
    {
        pi->prem = e->suiv;
        pi->nb--;
    }
    free(e);e = NULL;
    return 0;
}

char* sommet(pile* pi)
{
    return pi->prem->chaine;
}

void supprissionPile(pile* pi)
{
    while(!estVide(pi)) depiler(pi);
}


bool estOperateur(char* chaine)
{
    if(strcmp(chaine,"+") == 0) return true;
    if(strcmp(chaine,"-") == 0) return true;
    if(strcmp(chaine,"/") == 0) return true;
    if(strcmp(chaine,"*") == 0) return true;
    return false;
}


int calcul(char* op,char* a,char* b)
{
    if(strcmp(op,"+") == 0) return atoi(a) + atoi(b);
    if(strcmp(op,"-") == 0) return atoi(a) - atoi(b);
    if(strcmp(op,"*") == 0) return atoi(a) * atoi(b);
    if(strcmp(op,"/") == 0) return atoi(a) / atoi(b);
}

int polonaise(char** tab,int n,pile* pi)
{
	int i;
    for(i=0;i<n;i++)
    {
        char* resultat; resultat =(char*)malloc(10*sizeof(char));int res;
        if(estOperateur(tab[i]))
        {
            char* b=sommet(pi);
            depiler(pi);
            char* a=sommet(pi);
            depiler(pi);
            res = calcul(tab[i],a,b);
            
            itoa(res,resultat,10);
            empiler(pi,resultat);

        }
        else
        {
            empiler(pi,tab[i]);
        }
    }
    return atoi(sommet(pi));
}

char** saisirTab(int *N,char* ch)
{
   int i = 0;
   char** tab ; tab = (char**)malloc(64*sizeof(char*));
   char* tok;
   do
   {
        tab[i] = (char*)malloc(10*sizeof(char));
        if( i == 0)
        {
            tok = strtok(ch," ");
            strcpy(tab[i],tok);
        }else
        {
            tok = strtok(NULL," ");
            if(tok != NULL) strcpy(tab[i],tok);
        }
        i++;
   }while(tok != NULL);
   *N = (i -1);
   return tab;
}
int menu()
{
    int c;
    printf("\n------------------\n");Sleep(110);
    printf("le menu des choix:\n");Sleep(110);
    printf("------------------\n");Sleep(110);
    printf("Taper 1,pour calculer avec la notation polonaise:\n");Sleep(110);
    printf("Tapez 0 ,pour quiter:\n");Sleep(110);
    printf("Votre choix :? ");scanf("%d",&c);Sleep(110);
    return c;
}
