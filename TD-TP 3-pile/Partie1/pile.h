#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct element
{
    char c;
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

element* creeElement(char c)
{
    element* e;
    e = (element*)malloc(sizeof(element));
    e->c = c;
    e->suiv = NULL;
    return e;
}

void empiler(pile* pi,char c)
{
    element* e;
    e = creeElement(c);
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
        printf("%c ",e->c);
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

char sommet(pile* pi)
{
    return pi->prem->c;
}

void supprissionPile(pile* pi)
{
    while(!estVide(pi)) depiler(pi);
}

bool valide(pile* pi,char* ch)
{
    int i=0;
    while(ch[i] != '\0')
    {
        if( ch[i] == '['  || ch[i] == '(' || ch[i] == '{' ) empiler(pi,ch[i]);
        else if( ch[i] == ']')
        {
            if(!estVide(pi) && sommet(pi) == '[') depiler(pi);
            else return false;
        }
        else if( ch[i] == ')')
        {
            if(!estVide(pi) && sommet(pi) == '(') depiler(pi);
            else return false;
        }
        else if(ch[i] == '}')
        {
            if(!estVide(pi) && sommet(pi) == '{') depiler(pi);
            else return false;
        }
        i++;
    }
    return estVide(pi);
}

int menu()
{
    int c;

    printf("\t------------------\n");Sleep(120);
    printf("\tle menu des choix.\n");Sleep(120);
    printf("\t------------------\n");Sleep(120);
    printf("Pour tester la validite d'une chaine  taper 1:\n");Sleep(120);
    printf("Pour quiter taper 0:\n");Sleep(120);
    printf("Entrer votre choix :? ");Sleep(120);
    scanf("%d",&c);
    return c;
}