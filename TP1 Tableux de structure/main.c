#include "tp.h"

int main()
{  
    video *t;int n,i;int c;char ch[40];

    t = lireFile("file.txt",&n);
    do
    {
        printf("Taper 1 pour afficher la list des film :\n");
        printf("Taper 2 pour trier le tableau selon l'ordere alphabetique :\n");
        printf("Taper 3 pour la Recherche d'un realisateur :\n");
        printf("Taper 0 pour quitter :\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: affichage(t,n);break;
            case 2 :trie_struct(t,n);affichage(t,n);break;
            case 3 :trie_struct(t,n);printf("Entrez le nom de realisateur a chercher :\n");
                    gets(ch);
                    i=recherche_tab_struct(ch,t,0,n-1);
                    if(i == -1) printf("realisateur introuvable .\n");
                    else printf("realisateur %s se trouve au film %d",ch,i+1);
                    break;
            case 0 :printf("Au revoir");break;
            default : printf("erreur de choix \n");
       }
    } while (c != 0);
    return 0;
}
