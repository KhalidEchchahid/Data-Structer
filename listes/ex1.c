#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element{
 	int n;
 	struct element* suivant;
}Element;

typedef struct{
 	Element *premier;
 	Element *dernier;
 	int nbElt;
}Liste;

Liste* CreeListe(){
	Liste* l ;
	l=(Liste*)malloc(sizeof(Liste));
	l->premier=NULL;
	l->dernier=NULL;
	l->nbElt=0;
	return l;
}

bool est_vide(Liste* l){
	if(l->premier==NULL) 
		return true ;
	else
	 	return false ;
}

Element* CreeElement(int v){
	Element* e;
	e=(Element*)malloc(sizeof(Element));
	e->n=v;
	e->suivant=NULL;
	return e;
}

void AjouterEnFin(Liste* l , int v){
	Element* e=CreeElement(v);
	if(est_vide(l)){
		l->premier=e;
	}else{
		l->dernier->suivant=e;
	}
	
	l->dernier=e;
	l->nbElt++;
}

void AjouterEnTete(Liste* l , int v){
	Element* e=CreeElement(v);
	if(est_vide(l)){
		l->dernier=e;
		l->premier=e;
	}else{
		e->suivant=l->premier;
		l->premier=e;

	}
	l->nbElt++;
}
Liste* constuire(Liste* l){
	int v , t; 
	
	do{
		printf("donner un entier s_positif: ");
		scanf("%d",&v);
		if(v>0){
			AjouterEnFin(l,v);
		}else{
			printf("ce nombre est invalide. \n");
		}
		printf("entrer 0 si vous voulez arreter: ");
		scanf("%d",&t);
		printf("\n");
	}while(t!=0);
	
	return l;
	
}

void Affiche(Liste* l){
	Element* e =l->premier;
	if(est_vide(l)) printf("liste vide");
	else{
		while(e!=NULL){
			printf("%d \t",e->n);
			e=e->suivant;
		}
	}
}



Liste* Inverser(Liste* l){
	Liste* l1 = CreeListe();
	Element* e=l->premier;
	if(est_vide(l)) return NULL ;
	else{
		while(e!=NULL){
			AjouterEnTete(l1 ,e->n);
			e=e->suivant;
		}
	}
	printf("\n");
	Affiche(l1);
	return l1;

}

int Nb_occurrences(Liste* l , int a ){
	Element* e=l->premier;
	int c=0;
	if ( est_vide(l)) return 0 ;
	else{
		while(e!=NULL){
			if(e->n==a) c++;
			e=e->suivant;
		}
	}
	return c;
}

bool est_trie(Liste* l){
	Element* e=l->premier;
	while(e->suivant!=NULL){
		if(e->n >= e->suivant->n){
			printf(" \n liste non triee");
			return false ;
		}
		e=e->suivant;
	}
	printf("\n liste triee ");
	return true;
}
void AjouterPrec(Liste* l,Element* p , int v){
	Element* e=l->premier;
	Element* c=CreeElement(v);
	while(e!=NULL){
		if(p->n == e->n){
			c->suivant=e->suivant;
			e->suivant=c;
			l->nbElt++;
			break;
		}
	}
	
}
void AjouterEnListe(Liste* l,int v){
	Element* e=l->premier;
	if(est_vide(l)) AjouterEnTete(l,v);
	else if (e->n >= v) AjouterEnTete(l,v);
	else if (l->dernier->n <= v) AjouterEnFin(l,v);
	else{
		while(e->suivant != NULL){
			if(e->suivant->n > v){
				AjouterPrec(l,e,v);
				break;
			} 
			e=e->suivant;
		}
	}
}
Liste* constuire2(Liste* l){
	int v , t; 
	
	do{
		printf("donner un entier s_positif: ");
		scanf("%d",&v);
		if(v>0){
			AjouterEnListe(l,v);
		}else{
			printf("ce nombre est invalide. \n");
		}
		printf("entrer 0 si vous voulez arreter: ");
		scanf("%d",&t);
		printf("\n");
	}while(t!=0);
	
	return l;
	
}

int main(){
	int a,c;
	Liste* l=CreeListe();
	Liste* l1=CreeListe();
	constuire(l);
	Affiche(l);
	Inverser(l);
	printf("\n donner un nombre : "); scanf("%d",&a);
	c=Nb_occurrences(l,a);
	printf("\n nombre d occurrences de %d est c=%d ",a,c);
	est_trie(l);
	printf("\n");
	constuire2(l1);
	Affiche(l1);
	return 0;
}





