#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define max 140

typedef struct video
{
    char nom[32];
    char titre[32];
    int anne;
    int nbmin;
}video;

video* lireFile(char* c,int *n)
{
    FILE *fic;
    fic = fopen(c,"r");
    if(fic == NULL)
    {
        fprintf(stderr,"Errer d'overture de fichier \n");
        exit(EXIT_FAILURE);
    }
    else
    {   
        char ch[max];
        fgets(ch,max,fic);
        *n = atoi(ch);
        video* t;
        t = (video*)malloc((*n)*sizeof(*t));
        int i = 0;
        char del[] = ":";
        while(fgets(ch,max,fic) != NULL)
        {
            char *tok = strtok(ch,del);
            strcpy(t[i].nom,tok);

            tok = strtok(NULL,del);
            strcpy(t[i].titre,tok);

            tok = strtok(NULL,del);
            t[i].anne = atoi(tok);

            tok = strtok(NULL,del);
            t[i].nbmin = atoi(tok);

            i++;
        }
        return t;
    }
}

void affichage(video* t, int n)
{
	int i;
    for(i = 0 ; i < n ; i++)
    {
        printf("\t\tFilm %d \n",i+1);
        printf("le nom de realisteur : %s \n",t[i].nom);
        printf("le titre de film :%s \n",t[i].titre);
        printf("l'anne de production : %d \n",t[i].anne);
        printf("la duree de film : %d \n");
        printf("\t\t **********");
    }
}
void trie_struct(video* t , int n)
{
    int i,j;
    video temp;
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(strcmp(t[i].nom,t[j].nom) > 0)
        {
            temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
        else if( strcmp(t[i].nom,t[j].nom) == 0)   
            if(strcmp(t[i].titre,t[j].titre) > 0)
            {
                  temp = t[i];
                  t[i] = t[j];
                  t[j] = temp;
            }
    }
}

int recherche_tab_struct(char *c , video *t ,int g,int d)
{
	int m;
	do
	{
		m=(g+d)/2;
		if(strcmp(c,t[m].nom) == 0) return m;
		if(strcmp(c,t[m].nom) < 0 ) d=m-1;
		else g=m+1;
	}while(g<=d);
	return -1;
}
