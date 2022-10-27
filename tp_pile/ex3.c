#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>


typedef struct Element{
	
	char val ;
	struct Element* suiv ;
	
}Elem;

typedef struct {
	
	Elem* pr;
	Elem* dr;
	int nb;
	
}Pile;


Elem* CreeElem(char v){
	
	Elem* e ;
	e=(Elem*)malloc(sizeof(Elem));
	e->val = v;
	e->suiv= NULL;
	return e ;
}

Pile* CreerPile(){
	Pile* P=(Pile*)malloc(sizeof(Pile));
	P->pr =NULL;
	P->dr=NULL ;
	P->nb=0;
	return P;
}

bool est_vide(Pile* p){
   if(p->nb==0)
      return true;
   else 
   return false; 
}


void empiler(Pile* p ,char* v){
	Elem* e;
	e=CreeElem(*v);
	if(est_vide(p)){
		p->dr = e;
	}else{	
 		e->suiv=p->pr ;	
	}
	p->pr=e;
	p->nb++ ;
}

//int sommet(Pile* p, char x){
//	if(est_vide(p)){
//		return 0;
//	}else{
//		x=p->pr->val;
//	}
//	return 1;
//}

char sommet(Pile *p)
{  if(est_vide(p))
      printf("pile vide!");
  else
   return p->pr->val;
}

Elem* depiler(Pile* p){
	Elem* e;
	if(est_vide(p)) return NULL ;
	else{
		e=p->pr;
		p->pr=p->pr->suiv;
		p->nb--;
		e->suiv=NULL;
	}
	return e;
}


void    afficherPile(Pile* p){
	Elem* e=p->pr;
	if(est_vide(p))
	{
		printf("pile est vide");
	}
	else{
	 	while(e!=NULL){
			printf("\n la valeur est :%c \t",e->val);
			e=e->suiv;
		}
	}
}


/////////////////////////////////////////////////

  bool estOperateur(char* chaine)
{
    if(strcmp(chaine,"+") == 0) return true;
    if(strcmp(chaine,"-") == 0) return true;
    if(strcmp(chaine,"/") == 0) return true;
    if(strcmp(chaine,"*") == 0) return true;
    return false;

int calcul(char* op ,char a , char b ){
	int x, y , res;
	x= atoi(&a);
	y=atoi(&b);
	
	switch(*op){
		case '+' : res=x+y  ;break;
		case '-' : res=x-y  ;break;
		case '*' : res=x*y  ;break;
		case '/' : if(y!=0) res=x/y ;
					else printf("probleme de division sur un 0");
				break;
	}
	return res;
}


int  polonaise(char** c,int n){
	int i ;
	char s;
	Elem *a , *b ;
	int res;
	char* resultat; 
	Pile* p = CreerPile();
	for(i=0;i<n;i++){
		resultat =(char*)malloc(10*sizeof(char));
		if(!estOperateur(c[i])){
			empiler(p,c[i]);
			
		}else{
			a=depiler(p);
			b=depiler(p);
			
			res=calcul(c[i],a->val,b->val);
			itoa(res,resultat,10);
			empiler(p,resultat);
		}	
	}
	s=sommet(p);
	return atoi(&s);
}

char** saisir(char str[], int* n){
	char** tab=(char**)malloc(50*sizeof(char*));
	char* token=strtok(str," ");
	int i=0;
	while(token){
		tab[i]=(char*)malloc(10*sizeof(char));
		strpcpy(tab[i],token);
		token=strtok(NULL," ");
		i++;
	}
	*n=i;
	return tab;
}


int main(){
	char* c;
	int n;
	char** tab=(char**)malloc(50*sizeof(char*));
	int res;
	c=(char*)malloc(20*sizeof(char));
	printf("donner une polonaise :");
	gets(c);
	tab=saisir(c,&n);
	res=polonaise(tab,n);
	
	printf("resultat = %d",res);
}}













