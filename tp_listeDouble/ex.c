#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct monome{
	struct monome* prec;
	int deg ;
	int cof ;
	struct monome* suiv;
}Monome;

typedef struct {
	Monome* pr;
	Monome* dr;
	int nb;
}PolyCreux;

///////// creation d un monome ////////

Monome* CreeMonome(int deg , int cof){
	Monome* e;
	e=(Monome*)malloc(sizeof(Monome));
	e->deg=deg;
	e->cof=cof;
	e->suiv=NULL;
	e->prec=NULL;
	
	return e;
}

//////// creation d un polynome ///////

PolyCreux* CreeP(){
	PolyCreux* p;
	p=(PolyCreux*)malloc(sizeof(PolyCreux));
	p->dr=NULL;
	p->pr=NULL;
	p->nb=0;
	
	return p;
}

///////////// est_vide ///////////

bool est_vide(PolyCreux* p){
	if(p->nb == 0)
		 return true;
	else 
		return false ;
}

//////////// AjouteEnTete /////////////

void Ajoute_decroissante(PolyCreux* p , int deg , int cof){
	
	Monome* e=CreeMonome(deg,cof);
	
	if(est_vide(p)){
		p->pr= e ;
		p->dr= e ;
	}else{
		Monome* h= p->pr;
		while(h->deg > deg) h=h->suiv ;
		if(h->deg < deg){
			h->prec->suiv = e;
			e->prec=h->prec;
			e->suiv=h;
		}else{
			h->cof+=cof;
		}
		p->nb++;	 
	} 	
}

void suppresion_monome(PolyCreux* p ,int d){
	Monome* e;
	if(est_vide(p)){
		printf("pas d un polynome");
	}else{
		e=p->pr;
		while(e->deg!=d) e=e->suiv;
		if(e->deg==d){
			e->prec->suiv=e->suiv;
			e->suiv->prec=e->prec;
			e->suiv=NULL;
			e->prec=NULL;
			p->nb--;
			if(e==p->dr) p->dr=e->prec;
		}else{
			printf("ne existe pas ");
		}
		free(e);
		
	}
}

void Afficher_dec(PolyCreux* p){
	Monome* e;
	if(est_vide(p)){
		printf("pas d un polynome");
	}else{
		e=p->pr;
		while(e->suiv!=NULL){
			printf("%dx^%d + ",e->cof,e->deg);
		}
		if(e->suiv==NULL) printf("%dx^%d",e->cof,e->deg);
	}
}

void Afficher_c(PolyCreux* p){
	Monome* e;
	if(est_vide(p)){
		printf("pas d un polynome");
	}else{
		e=p->dr;
		while(e->prec!=NULL){
			printf("%dx^%d + ",e->cof,e->deg);
		}
		if(e->prec==NULL) printf("%dx^%d",e->cof,e->deg);
	}
}

void supprimer_debut(PolyCreux* p){
	Monome* e=p->pr;
		if(p->nb==1){
		p->dr=NULL;
		p->pr=NULL;
		p->nb=0;
	}else {
		p->pr=p->pr->suiv;
		p->pr->prec=NULL;
		p->nb--;
		free(e);
	}
}

void destruction(PolyCreux* p){
	Monome* e=p->pr;
	if(est_vide(p)){
		printf("pas poly");
	}else{
		while(e!=NULL){
			supprimer_debut(p);
			e=e->suiv;
		}
	}
}

PolyCreux* m_scalaire(PolyCreux* p, int a){
	Monome* e=p->pr;
	
		while(e!=NULL){
			e->cof *= a;
			e=e->suiv;
	}
	return p;
}

PolyCreux* m_monome(PolyCreux* p , Monome* m){
	Monome* e=p->pr;
	
		while(e!=NULL){
			e->cof *= m->cof;
			e->deg += m->deg ;
			e=e->suiv;
	}
	return p;
}

PolyCreux* somme_polynome(PolyCreux* p1 ,PolyCreux* p2){
	Monome* e2 = p2->pr;
	if(est_vide(p1)); return NULL;
	if(est_vide(p1)); return NULL;
	else{
		while(e2!=NULL){
				Ajoute_decroissante(p1, e2->deg ,e2->cof);
				e2=e2->suiv;
			}
		}
		
	return p1;
}











