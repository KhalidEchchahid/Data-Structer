#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef struct noeud *pnoeud;
typedef struct noeud{
	char *mot ;
	pnoeud fg;
	pnoeud fd;
}noeud;
typedef struct noeud *ARB;
ARB creeARB(){
	ARB A=(ARB)malloc(sizeof(ARB));
	return A;
}
pnoeud creenoeud(char *e){
   pnoeud p=(pnoeud)malloc(sizeof(noeud));
    strcpy(p->mot,e);
    p->fg = NULL;
    p->fd = NULL;
    return p;
}
bool est_vide(ARB A){
    return A == NULL;
}
ARB construire(pnoeud r,ARB g,ARB d){
    r->fg = g;
    r->fd = d;
    return r;
}
ARB insereMot(ARB A, char *mot){
	if(est_vide(A)== true){
		noeud *r=creenoeud(mot);
		return construire(r,NULL,NULL);
	}
	else{
		if(strcmp(A->mot, mot)<0){
			return construire(A,A->fg,insereMot(A->fd,mot));
		}
		else{
			return construire(A,insereMot(A->fg,mot),A->fd);
		}
	}
}

ARB insere(ARB A,char *mot){
	char *c=strtok(mot," ");
	A=insereMot(A,c);
	while(c!=NULL){
		c=strtok(NULL," ");
		A=insereMot(A, c);
	}
	return A;
}
void majic(ARB A){
	if(!est_vide(A)){
		printf("%s",A->mot);
		majic(A->fd);
		majic(A->fg);
	}
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
bool REchercherm(ARB A,char *mot){
	if(est_vide(A)){
		return false;
	}
	else{
		if(strcmp(A->mot,mot)==0){
		    return true;
        }
	    else if(strcmp(A->mot,mot)<0){
		   return REchercherm(A->fd,mot);
	    }
	    else{
		 return REchercherm(A->fg,mot);
        }
	}
}
void Recherch(ARB A,char *ch){
	char *c=strtok(ch," ");
	while(c){
		if(REchercherm(A,ch)){
			printf("%s:True",c);
		}
		else{
			printf("%s:False",c);
		}
		c=strtok(NULL," ");
	}
}
int nombre_mot(ARB A,char c){
	if(est_vide(A)){
		return 0;
	}
	else{
		if(A->mot[0]==c){
			return 1+nombre_mot(A->fd,c)+nombre_mot(A->fg,c);
		}
		else{
			return nombre_mot(A->fd,c)+nombre_mot(A->fg,c);
		}
	}
}
int max(int a, int b){
	if (a<b)
	   return b;
	else 
	  return a;
}
bool est_feuille(ARB A){
    if(est_vide(A)) 
	     return false;
    else{
    	if(est_vide(A->fg) && est_vide(A->fd)) 
	     return true; 
	}
	return false;
}
int hauteur(ARB A){
	if(est_vide(A))
	   return 0;
	if(est_feuille(A))
	  return 0;
	else 
	   return (1+max(hauteur(A->fg),hauteur(A->fd)));
}
int main(){
	char* c;
	char ch[30];
	char s;
	int a,h;
	ARB A=creeARB();
	printf("donner une expresion :");
	scanf("%s",c);
	insere(A,c);
	majic(A);
	affiche(A,0);
	printf("donner une expresion pour le recherche:");
	scanf("%s",&ch);
	Recherch(A,ch);
	printf("\ndonner une caractere : ");
	scanf("%c",&s);
	a=nombre_mot(A,s);
	printf("\nc=%d",a);
	h=hauteur(A);
	printf("\n h=%d",h);
	return 0;
}

