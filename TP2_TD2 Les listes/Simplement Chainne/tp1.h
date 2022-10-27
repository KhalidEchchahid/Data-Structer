#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char nom[64];
    char titre[64];
    int annee;
    int duree;
}Objet;

typedef struct film
{
    Objet O;
    struct film *suiv;
}film;

typedef struct 
{
    film *prem;
    film *dern;
    int nb;
}list;

int estVide(list* li)
{
    if(li->nb == 0) return 1;
    return 0;
}

void initialList(list* li)
{
    li->prem = NULL;
    li->dern = NULL;
    li->nb = 0;
}

list* creelist()
{
    list* li;
    li= (list*)malloc(sizeof(list));
    initialList(li);
    return li;
}

void aficherList(list* li)
{
    if(estVide(li))
    {
        printf("la list est vide .\n\n");
        return;
    }
    film* e; e = li->prem;int i=1;
    printf("\t-------------------------------------------------\n");
    printf("\tNom\t\tTitre\t   annee   duree\n");
    printf("\t-------------------------------------------------\n");
    while( e != NULL)
    {
        printf("Film %d :",i);
        printf("%s   ",e->O.nom);
        printf("%s   ",e->O.titre);
        printf("%d     ",e->O.annee);
        printf("%d",e->O.duree);
        e = e->suiv;i++;
        printf("\n");
    }
    printf("\n\n");
}
void tailleDeLalist(list* li)
{
    printf("le nombre d'element = %d .\n",li->nb);
}
 film* creeFilm(Objet Ob)
 {
     film* e;
     e = (film*)malloc(sizeof(film));
     e->suiv = NULL;
     strcpy(e->O.nom , Ob.nom);
     strcpy(e->O.titre,Ob.titre);
     e->O.annee = Ob.annee;
     e->O.duree = Ob.duree;
     return e;
 }

void ajouterEnTete(list* li,Objet O)
{
    film* e;
    e = creeFilm(O);
    if(estVide(li))
    {
        li->prem = e;
        li->dern = e;
    }
    else
    {
        e->suiv = li->prem;
        li->prem = e ;      
    }
    li->nb++;
}
 void ajouterAlaFin(list* li ,Objet O)
 {
     if(estVide(li))
     {
         ajouterEnTete(li,O);return;
     }
     film* e;
     e = creeFilm(O);
     li->dern->suiv = e;
     li->dern = e;
     li->nb++;
 }

 void ajouterAuMilieu(list* li,film* precedent,Objet O)
 {
    if(precedent == NULL)
    {
        ajouterEnTete(li,O);
    }
    else if(precedent->suiv == NULL) //precedent == li->dern;
    {
        ajouterAlaFin(li,O);
    }
    else
    {
        film* e; e = creeFilm(O);
        e->suiv = precedent->suiv;
        precedent->suiv = e ;
        li->nb++;
    }
 }

 void supprimerEnTete(list* li)
 {
     if(estVide(li)) return;
     film* e; e = li->prem;
     if(li->nb == 1)
     {
         initialList(li);
         free(e);e = NULL;
     }
     else
     {
         li->prem = e->suiv;
         free(e);e = NULL;
         li->nb--;
     }
 }

 void supprimerAlaFin(list* li)
 {
     if(estVide(li) || li->nb == 1) supprimerEnTete(li);
     else
     {
         film* e; e = li->prem;
         while( e->suiv->suiv != NULL) e = e->suiv;
         free(e->suiv) ; e->suiv = NULL;
         li->nb--;   
     }
 }

 void supprimerAuMilieu(list* li,film* precedent)
 {
     if(precedent == NULL) supprimerEnTete(li);
     else if(precedent == li->dern) return;
     else if(precedent->suiv == li->dern)
     {
         supprimerAlaFin(li);
     }
     else
     {
         film* e ; e = precedent->suiv;
         precedent->suiv = e->suiv;
         free(e) ; e = NULL;
         li->nb--;
     }
 }

void viderList(list *li)
{
    while(!estVide(li)) supprimerEnTete(li);
}

film* positionFilm(list* li,int P)
{
    if(P>li->nb || P<1) return NULL;
    film* e;e=li->prem;int i=1;
    while(i<P) 
    {e=e->suiv;i++;}
    return e;
}

void afficherFilm(film* e,int i)
{
    printf("Film %d :",i);
    printf("%s   ",e->O.nom);
    printf("%s   ",e->O.titre);
    printf("%d     ",e->O.annee);
    printf("%d",e->O.duree);
    printf("\n");
}

void ajouterAlaPosition(list* li,int P,Objet O)
{
    if(P == 1) ajouterEnTete(li,O);
    film* e; e = positionFilm(li,P-1);
    if(e == NULL) return;
    ajouterAuMilieu(li,e,O);
}

void supprimerAlaPosition(list* li,int P)
{
    if(P == 1) supprimerEnTete(li);
    film* e; e = positionFilm(li,P-1);
    if(e == NULL) return;
    supprimerAuMilieu(li,e);
}

list* inverserList(list* li)
{
    list* temp; temp=creelist();
    film* e;e= li->prem;
    while(e!=NULL)
    {
        ajouterEnTete(temp,e->O) ;e=e->suiv;
    }
    free(li);li=NULL;
    return temp;
}

void insertFilmParOredre(list*li,film* f)
{
    if(estVide(li) || strcmp(f->O.nom,li->prem->O.nom) <= 0 ) ajouterEnTete(li,f->O);
    else if(strcmp(f->O.nom,li->dern->O.nom) >= 0) ajouterAlaFin(li,f->O);
    else
    {
        film* e; e=li->prem;
        while(strcmp(f->O.nom,e->suiv->O.nom) > 0 && e->suiv!= li->dern) e=e->suiv;
        ajouterAuMilieu(li,e,f->O);
    }
}

list* trieList(list* li)
{
    list* temp; temp=creelist();
    film* e; e=li->prem;
    while(e!=NULL)
    {
        insertFilmParOredre(temp,e);e=e->suiv;
    }
    free(li);li=NULL;
    return temp;
}

void lireFile(list* li,char* c)
{
    FILE *fic;char ch[300];
    fic=fopen(c,"r");
    if(fic == NULL) return;
    Objet O;
    while(fgets(ch,300,fic) != NULL)
    {
        char* tok=strtok(ch,":");
        strcpy(O.nom,tok);

        tok=strtok(NULL,":");
        strcpy(O.titre,tok);

        tok=strtok(NULL,":");
        O.annee=atoi(tok);

        tok=strtok(NULL,":");
        O.duree=atoi(tok);
        ajouterAlaFin(li,O);
    }
    fclose(fic);
}
void remplissageObjet(Objet* O)
{
    printf("Entrer le nom :");fflush(stdin);gets(O->nom);
    printf("Entrer le titre :");fflush(stdin);gets(O->titre);
    printf("Entrez l'annee :");scanf("%d",&O->annee);
    printf("Entrez la duree :");scanf("%d",&O->duree);
    printf("\n");
}

int menu()
{
    int c;
    printf("\t\t-----------------------------------\n");
    printf("Affichage de la liste tapez <1> .\n");
    printf("Ajouter un film en tete  tapez <2> .\n");
    printf("Ajouter un film a la fin tapez <3> .\n");
    printf("Ajouter un film a la postion tapez <4> .\n");
    printf("Supprimer le film en tete  tapez <5> .\n");
    printf("Supprimer le film a la fin  tapez <6> .\n");
    printf("Supprimer un film a la postion tapez <7> .\n");
    printf("Afficher le film a la position : tapez <8> .\n");
    printf("Trier la liste par ordre alphabitique croissant tapez<9> .\n");
    printf("Inverser l'ordere de la liste tapez <10> .\n");
    printf("Pour Quiter tapez <0>\n");
    printf("Votre choix! :");
    scanf("%d",&c);
    printf("\n\n");
    printf("\t\t-----------------------------------\n");
    return c;

}

