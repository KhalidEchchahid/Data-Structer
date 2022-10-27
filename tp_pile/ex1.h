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


void empiler(Pile* p ,char v){
	Elem* e;
	e=CreeElem(v);
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


/********************************************/

bool valide(char* c){
	Pile* p=CreerPile();
	int i=0 ;
	Elem *e;
	while(i<strlen(c)){
		if(c[i] == '[' || c[i] == '(' || c[i]=='{'){
			empiler(p,c[i]);
		}
		if(c[i] == ']' && sommet(p)=='['){
			depiler(p);
		}
		if(c[i] == ')' && sommet(p)=='('){
			depiler(p);
		}
		if(c[i] == '}' && sommet(p)=='{'){
			depiler(p);
		}
		i++;
	}
	return est_vide(p);
}



