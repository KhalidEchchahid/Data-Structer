#include "pile.h"

int main()
{
    pile* pi;char chaine[64];int c;
    pi = creePile();Sleep(120);
    printf("--------------------------------------------------\n");Sleep(120);
    printf("Bonjour a notre programme de test sur les chaines.\n");Sleep(120);
    printf("--------------------------------------------------\n");Sleep(120);
 
    do
    {
        c = menu();
        switch(c)
        {
            case 1:
            printf("Entrez une chaine de charactere:");Sleep(120);fflush(stdin);gets(chaine);
            if(valide(pi,chaine) == true) {printf("la chaine \"%s\" est validee\n",chaine);Sleep(120);}
            else printf("la chaine \"%s\" est non validee\n",chaine);supprissionPile(pi);system("pause");break;
            
            case 0:
            printf("Au revoir.\n");Sleep(120);system("pause");break;
            default:
            printf("Erreur de choix .\n");Sleep(120);system("pause");

        }
    } while (c != 0);
    
    return 0;
}
