#include "pile.h"

int main()
{
    pile* pi;pi = creePile();int N,c;char** tab,ch[64];
    do
    {
        c =menu();
        switch(c)
        {
            case 1:
            printf("Entrer des chaines separer par espace : \n");fflush(stdin);gets(ch);Sleep(110);
            tab = saisirTab(&N,ch);
            printf("le resultat est = %d \n\n",polonaise(tab,N,pi));Sleep(110);
            system("pause");break;
            case 0:printf("Au revoir.\n");Sleep(110);system("pause");break;
            default: printf("Erreur de choix.\n");Sleep(110);system("pause");break;
        }
    }while(c != 0);

   
    return 0;
}
