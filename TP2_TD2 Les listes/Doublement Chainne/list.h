#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

typedef struct
{
    int coefficient;
    int degre;
}objet;

typedef struct monome
{
    objet o;
    struct monome* suiv;
    struct monome* prec;
}monome;

typedef struct
{
    monome* prem;
    monome* dern;
    int nb;
}poly;

void taillePoly(poly* p1);

int estVide(poly* p1)
{
    if(p1->nb == 0) return 1;
    return 0;
}

void initialPoly(poly* p1)
{
    p1->prem = NULL;
    p1->dern = NULL;
    p1->nb = 0;
}

poly* creePoly()
{
    poly* p1;
    p1 = (poly*)malloc(sizeof(poly));
    initialPoly(p1);
    return p1;
}

monome* creeMonome(objet o)
{
    monome* e;
    e = (monome*)malloc(sizeof(monome));
    e->o.degre = o.degre ;
    e->o.coefficient = o.coefficient;
    e->suiv = NULL;
    e->prec = NULL;
    return e;
}

void ajouterEntete(poly* p1,objet o)
{
    monome* e;
    e = creeMonome(o);
    if(estVide(p1))
    {
        p1->prem = e;
        p1->dern = e;
    }
    else
    {
        e->suiv = p1->prem;
        p1->prem->prec = e;
        p1->prem = e;
    }
    p1->nb++;
}
void afficherPoly(poly* p1,char* ch)
{
    if(estVide(p1)) return;
    Sleep(150);
    printf("\n--------------------------------\n");Sleep(150);
    printf("%s(X) = ",ch);Sleep(150);
    monome* e;
    e = p1->prem;
    while(e->suiv)
    {
        if(e->o.coefficient == 1 && e->o.degre != 0 && e->o.degre != 1)
        {
            printf("X^(%d) + ",e->o.degre);Sleep(150);
        }
        else if(e->o.degre == 1)
        {
            printf("%dX + ",e->o.coefficient); Sleep(150);
        }
        else if(e->o.degre == 0)
        {
            printf("%d + ",e->o.coefficient);  Sleep(150);
        }
        else
        {
            printf("%dX^(%d) + ",e->o.coefficient,e->o.degre);Sleep(150);
        }
        e = e->suiv;
    }
    if(e->o.coefficient == 1 && e->o.degre != 0 && e->o.degre != 1)
        {
            printf("X^(%d) ",e->o.degre);Sleep(150);
        }
    else if(e->o.degre == 1)
    {
        printf("%dX ",e->o.coefficient);          Sleep(150);
    }
    else if(e->o.degre == 0)
    {
        printf("%d ",e->o.coefficient);Sleep(150);
    }
    else
    {
        printf("%d.X^(%d) ",e->o.coefficient,e->o.degre);Sleep(150);
    }
    
    printf("\n--------------------------------\n");Sleep(150);
}

void ajouterAlaFin(poly* p1,objet o)
{
    if(estVide(p1))
    {
        ajouterEntete(p1,o);
    }
    else
    {
        monome* e;
        e = creeMonome(o);
        e->prec = p1->dern;
        p1->dern->suiv = e;
        p1->dern = e;
        p1->nb++;
    }
}

void taillePoly(poly* p1)
{
    printf("taille = %d \n",p1->nb);
}

void ajouterAuMilieu(poly* p1,monome* precedent,objet o)
{
    if(precedent == NULL) ajouterEntete(p1,o);

    else if(precedent->suiv == NULL) ajouterAlaFin(p1,o);
    else
    {
        monome* e;
        e = creeMonome(o);
        e->suiv = precedent->suiv;
        precedent->suiv->prec =  e;
        e->prec = precedent;
        precedent->suiv = e;
        p1->nb++;
    }
}

void supprimerEnTete(poly* p1)
{
    if(estVide(p1)) return;
    monome* e; e = p1->prem;
    if(p1->nb == 1)
    {
        initialPoly(p1);
    }
    else
    {
        p1->prem = e->suiv;
        p1->prem->prec = NULL;
        p1->nb--;
    }
    free(e); e = NULL;
}

void detruirePoly(poly* p1)
{
    while(!estVide(p1))
    {
        supprimerEnTete(p1);
    }
}

void supprimerAlaFin(poly* p1)
{
    if(estVide(p1) || p1->nb == 1) supprimerEnTete(p1);
    else
    {
        monome* e;
        e = p1->dern;
        p1->dern = e->prec;
        p1->dern->suiv = NULL;
        p1->nb--;
        free(e);e = NULL;
    }
}

void supprimerAuMilieu(poly* p1,monome* precedent)
{
    if(estVide(p1)  || precedent == p1->dern) return;
    else if(precedent == NULL) supprimerEnTete(p1);
    else if (precedent->suiv == p1->dern ) supprimerAlaFin(p1);
    else
    {
        monome* e;
        e = precedent->suiv;
        precedent->suiv = e->suiv;
        e->suiv->prec = precedent;
        p1->nb--; free(e); e = NULL;
    }
}

void insertMonome(poly* p1,monome* f)
{
   if(estVide(p1) || f->o.degre >= p1->prem->o.degre)  ajouterEntete(p1,f->o);
   else if(f->o.degre <= p1->dern->o.degre ) ajouterAlaFin(p1,f->o);
   else
   {
       monome* e;
       e = p1->prem;
       while(f->o.degre < e->suiv->o.degre && e->suiv != p1->dern) e=e->suiv;
       ajouterAuMilieu(p1,e,f->o);
   }
}

poly* triePoly(poly* p1)
{
    poly* temp; temp = creePoly();
    monome* e; e = p1->prem;
    while(e != NULL)
    {
        insertMonome(temp,e);
        e = e->suiv;
    }
    return temp;
}

void supprimerParOrdre(poly* p1,int P)
{
    if(estVide(p1)) return;
    if(p1->prem->o.degre == P) supprimerEnTete(p1);
    else if(p1->dern->o.degre == P) supprimerAlaFin(p1);
    else
    {
        monome* e;e = p1->prem;
        while(e->suiv->o.degre != P && e->suiv != p1->dern) e = e->suiv;
        if(e->suiv != p1->dern) supprimerAuMilieu(p1,e);
    }
    
}

poly* copyPoly(poly* p1)
{
    poly* temp;temp = creePoly();
    monome* e; e = p1->prem;
    while(e != NULL)
    {
        ajouterAlaFin(temp,e->o);
        e = e->suiv;
    }
    return temp;
}

void additionMonome(poly* p1,monome* f)
{
    monome* e;e = p1->prem;
    while(e != NULL && e->o.degre != f->o.degre) e = e->suiv;
    if(e == NULL) insertMonome(p1,f);
    else e->o.coefficient += f->o.coefficient;
}

poly* sommePoly(poly* p1,poly*p2)
{
    poly* temp; temp = copyPoly(p1);
    monome* e; e = p2->prem;
    while(e != NULL)
    {
        additionMonome(temp,e);e = e->suiv;
    }
    return temp;
}

void soustraireMonome(poly* p1,monome* f)
{
    monome* e;e = p1->prem;
    while(e != NULL && e->o.degre != f->o.degre) e = e->suiv;
    if(e == NULL) insertMonome(p1,f);
    else e->o.coefficient -= f->o.coefficient;
}

poly* soustractionPoly(poly* p1,poly*p2)
{
    poly* temp; temp = copyPoly(p1);
    monome* e; e = p2->prem;
    while(e != NULL)
    {
        soustraireMonome(temp,e);e = e->suiv;
    }
    return temp;
}

poly* multiplicationMonome(poly* p1,monome* f)
{
    poly* temp;temp = copyPoly(p1);
    monome* e;e = temp->prem;
    while(e != NULL)
    {
        e->o.coefficient *= f->o.coefficient;
        e->o.degre += f->o.degre;
        e = e->suiv;
    }
    return temp;
}


poly* produitPoly(poly* p1,poly* p2)
{
    poly* temp;temp = creePoly();
    monome* e;e = p2->prem;
    while(e != NULL)
    {
        temp = sommePoly(temp,multiplicationMonome(p1,e));e = e->suiv;
    }
    return temp;
}

int evaluerPoly(poly* p1,int x)
{
    int som = 0;
    monome* e;
    e = p1->prem;
    while(e != NULL)
    {
        som += e->o.coefficient*pow(x,e->o.degre);
        e = e->suiv;
    }
    return som;
}

int menu()
{
    int c;
    Sleep(150);
    printf("\t\t----------------------\n");Sleep(150);
    printf("\t\tLe menu des polynome :\n");Sleep(150);
    printf("\t\t----------------------\n");Sleep(150);
    printf("Afficher p1(X) ,Taper 1 :\n");Sleep(150);
    printf("Afficher p2(X) ,Taper 2 :\n");Sleep(150);
    printf("inserer un Monome en p1(X) ,Taper 3:\n");Sleep(150);
    printf("inserer un Monome en p2(X) ,Taper 4:\n");Sleep(150);
    printf("Supprimer un monome par son ordre en p1(X) ,Taper 5:\n");Sleep(150);
    printf("Supprimer un monome par son ordre en p2(X) ,Taper 6:\n");Sleep(150);
    printf("Sommer p1(X) avec p2(X),Taper 7 :\n");Sleep(150);
    printf("Soustraire p2(X) de p1(X),Taper 8 :\n");Sleep(150);
    printf("Soustraire p1(X) de p2(X),Taper 9 :\n");Sleep(150);
    printf("porduit de p2(X) avec p1(X),Taper 10 :\n");Sleep(150);
    printf("Evaluer p1(X) a l'aide d'un entier,Taper 11 :\n");;Sleep(150);
    printf("Evaluer p2(X) a l'aide d'un entier,Taper 12 :\n");;Sleep(150);
    printf("Evaluer le resultat res(X)a l'aide d'un entier ,Taper 13 :\n");;Sleep(150);
    printf("pour quiter ,Taper 0 :\n");Sleep(150);
    printf("votre choix :? ");Sleep(150);
    scanf("%d",&c);Sleep(150);
    return c;
}
void remplirObjet(objet* o)
{
    printf("Entrer le coefficient :\n");scanf("%d",&o->coefficient);Sleep(150);
    printf("Entrer le degre :\n");scanf("%d",&o->degre);Sleep(150);
}

poly* correctPoly(poly* p1)
{
    poly* temp; temp =creePoly();
    monome* e; e = p1->prem;
    while(e != NULL) 
    {
        additionMonome(temp,e);e = e->suiv;
    }
    return temp;
}



















//Boussaid Mohammed