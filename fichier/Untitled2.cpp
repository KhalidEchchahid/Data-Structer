#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <process.h>

typedef struct Classe {
	 char nom[20];
	 char num[17];
	 struct Classe* sv ;
}Classe;

typedef struct Liste{
	Classe* pr;
	Classe* dr; 
	int nb;
}Liste;
bool est_vide(Liste* li)
{
   if(li->nb==0)
      return true;
   else 
   return false; 
}

Classe* CreeClasse(Classe* c)
{
Classe* nouveau;
nouveau=(Classe*)malloc(sizeof(Classe));
nouveau=c;
nouveau->sv=NULL; 
return nouveau;
}

void initListeC(Liste *li)
{
li->pr =NULL;
li->dr =NULL;
li->nb=0;
}
Liste* CreeListe()
{
Liste* li;
li=(Liste*)malloc(sizeof(Liste));
initListeC (li);
return li;
}

void ajouterEnTeteC (Liste* li, Classe* c)
{
Classe* nouveau;
nouveau=CreeClasse(c);
if (est_vide(li))
{ li->pr =nouveau;
li->dr =nouveau;
li->nb++;
}
else { 
nouveau->sv=li->pr ;
li->pr =nouveau;
li->nb++;
}
}

void ajouterFinC (Liste* li, Classe* c)
{
Classe* nouveau;
nouveau=CreeClasse(c);
if (est_vide(li))
   ajouterEnTeteC (li,c);
else 
{ 
li->dr->sv=nouveau;
li->dr=nouveau;
li->nb++;
}
}

Liste* ajouter(){
	Liste* l=CreeListe();
     int t=0;
     while(t==0){
     	Classe* e= (Classe*)malloc(sizeof(Classe));
     	printf("entrer le nom ");
     	scanf("%s",e->nom);
     	printf("enter le numero ");
     	scanf("%s",e->num);
     	e=CreeClasse(e);
         ajouterFinC (l,e);
     	printf("si vous voulez continuer entre 0 else 1");
     	scanf("%d",&t);
	 }
	 return l;
}

void afficher(Liste*l){
	Classe*e=l->pr;
	 while(e){
	 	printf("\nle nom est %s \t\t le numero est %s",e->nom,e->num);
	 	e=e->sv;
	 }
}
 void remplirF(Liste*l){
 	 FILE * f=NULL;
 	  f=fopen("khalid.csv","a");
 	    if(f!=NULL){
 	    	Classe*e=l->pr;
 	    	while(e!=NULL){
 	    		fprintf(f,"%s;%s\n",e->nom,e->num);
 	    		 e=e->sv;
			 }
			 fclose(f);
 	    	
		 }
		 else {
		 	printf("impossi d'ouvrire ce fichier");
		 }
 }
 
 
 Liste* lire_de_fichier(){
 	   Liste* l=CreeListe();
	    FILE* f=NULL;
	    f=fopen("khalid.csv","r+");
	    char* line;
	   line=(char*)malloc(100*sizeof(char));
	    if(f==NULL) printf("erreur");
	    else{
//	    	fscanf(f, "%[^\n]", line); makhdamach
	    	fscanf(f,"%[^\n] ",line); //khdama 
	    	
	    	while(fscanf(f, "%[^\n] ", line) != EOF){
//	    		printf("%s\n",line);
	    		Classe* c=(Classe*)malloc(sizeof(Classe));
	    		char* a=strtok(line ,";");
	    		   strcpy(c->nom,a);
	    		   a=strtok(NULL,";");
 	    		   strcpy(c->num,a);
	    		   c=CreeClasse(c);
 	    		   ajouterFinC(l,c);
			}
			 
		}
		fclose(f);
		return l;
}
//Liste* lire_classes ()
//{
//	Liste* l=CreeListe();
//    FILE* f = NULL;
//    f = fopen("khalid.csv", "r+");
//    char* line;
//    line=(char*)malloc(100*sizeof(char));
//    if (f == NULL)
//    {
//        // On affiche un message d'erreur si on veut
//        printf("Impossible d'ouvrir le fichier classe.csv");
//    }
//   else
//    {
//        fscanf(f, "%[^\n] ", line);
//    	
//    
//        while (fscanf(f, "%[^\n] ", line) != EOF)
//          {
//             printf("%s\n",line);
//              Classe* c=(Classe*)malloc(sizeof(Classe));
//		      char* ch=strtok(line,";");
//			  strcpy(c->num,ch);
//			  
//			  ch=strtok(NULL,";");
//			  strcpy(c->nom,ch);
//			  
//			  c=CreeClasse(c);
//			  ajouterFinC (l,c);
//			  
//          }
//      }
//      fclose(f);
//      return l;
//}
 
 int main(){
 	Liste*l;
// 	l=ajouter();
// 	afficher(l);
// l=lire_classes();
 l=lire_de_fichier();
// remplirF(l);
  afficher(l);
 	
 return 0;	
 	
 }
