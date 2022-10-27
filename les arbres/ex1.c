#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct noeud *Pnoeud;
typedef struct noeud{
	char* mot;
	Pnoeud fg;
	Pnoeud fd;
}Noeud;

typedef struct noeud* ARB;

ARB creeARB(){
	ARB A=(ARB)malloc(sizeof(ARB));
	return A;
}

Pnoeud creeNoeud(char* e){
	Pnoeud N=(Pnoeud)malloc(sizeof(Noeud));
	strcpy(N->mot,e);
	N->fd=NULL;
	N->fg=NULL;
	return N;
}

bool est_vide(ARB A){
	return (A==NULL);
}


ARB construire(Pnoeud r ,ARB g ,ARB d){
	r->fd=d;
	r->fg=g;
	return r;
}

ARB insererMot(ARB A ,char* mot){
	if(est_vide(A)){
		Pnoeud r=creeNoeud(mot);
		return construire(r,NULL,NULL);
	}else if(strcmp(A->mot,mot)>=0)
		return construire(A,insererMot(A->fg,mot),A->fd);
	else 
		return construire(A,A->fg,insererMot(A->fd,mot));
}

ARB insere(ARB A,char* mot){
	char* c=strtok(mot," ");
	while(c){
		insererMot(A,c);
		c=strtok(NULL," ");
	}
	return A;
}

int t=5;
void affiche(ARB A,int nv){
	if(est_vide(A)){
		exit(1);
	}
	else{
		int i;
		nv=nv+t;
		affiche(A->fd,nv);
		for(i=0;i<nv-t;i++)
		printf("*");
		printf("%s\n",A->mot);
		affiche(A->fg,nv);
	}
}

bool Erecherche(ARB A ,char* mot){
	if(est_vide(A)) return false ;
	else if(strcmp(A->mot,mot)==0) return true;
	else if(strcmp(A->mot,mot)<0)
		return Erecherche(A->fd,mot);
	else 
	  	return Erecherche(A->fd,mot);	
}
void Recherch(ARB A,char *ch){
	char *c=strtok(ch," ");
	while(c){
		if(Erecherche(A,ch)){
			printf("%s:True",c);
		}
		else{
			printf("%s:False",c);
		}
		c=strtok(NULL," ");
	}
}

int recherche_nb(ARB A ,char c){
	if(est_vide(A)) return 0 ;
	else if(A->mot[0]==c) return 1 + recherche_nb(A->fd,c) + recherche_nb(A->fg,c);
    else  return recherche_nb(A->fg,c)+recherche_nb(A->fg,c);

}

int max(int a,int b){
	if(a>b) return a;
	else return b ;
}

bool est_feuille(ARB A){
	if(est_vide(A)) return false ;
	else if(A->fg== NULL && A->fd==NULL) return true ;
	else return false ;
}

int hauteur(ARB A){
	if(est_vide(A)) return 0 ;
	if(est_feuille(A)) return 0;
	else{
		return 1 + max(hauteur(A->fd),hauteur(A->fd));
	}
}


int main(){
	char c[30];
	char ch[30];
	char s;
	int a,h;
	ARB A=creeARB();
	printf("donner une expresion :");
	scanf("%s",&c);
	insere(A,c);
//	affiche(A,0);
	printf("donner une expresion pour le recherche:");
	scanf("%s",&ch);
	Recherch(A,ch);
	printf("\ndonner une caractere : ");
	scanf("%c",&s);
	a=recherche_nb(A,s);
	printf("\nc=%d",a);
	h=hauteur(A);
	printf("\n h=%d",h);
	return 0;
}





















