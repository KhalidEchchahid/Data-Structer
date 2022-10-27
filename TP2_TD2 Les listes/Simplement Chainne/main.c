#include "tp1.h"

int main()
{
    int c;
    list* li;film* e;Objet O; li = creelist();lireFile(li,"file.txt");int P;
    printf("\t\t-----------------------------------\n");
    printf("\t\t  Bonjour A la list des videoTech \n");
    do
    {
        c=menu();
        switch(c)
        {
            case 1:aficherList(li);system("pause");;break;
            case 2:remplissageObjet(&O);ajouterEnTete(li,O);printf("done!\n\n");system("pause");;break;
            case 3:remplissageObjet(&O);ajouterAlaFin(li,O);system("pause");;break;
            case 4:printf("Entrez la position :");scanf("%d",&P);remplissageObjet(&O);
            ajouterAlaPosition(li,P,O);printf("done!\n\n");system("pause");;break;
            case 5:supprimerEnTete(li);printf("done!\n\n");system("pause");;break;
            case 6:supprimerAlaFin(li);printf("done!\n\n");system("pause");;break;
            case 7:printf("Entrez la position :");scanf("%d",&P);supprimerAlaPosition(li,P);
            printf("done!\n\n");system("pause");;break;
            case 8:printf("Entrez la position :");scanf("%d",&P);e=positionFilm(li,P);afficherFilm(e,P);
            printf("done!\n\n");system("pause");;break;
            case 9:li=trieList(li);printf("done!\n\n");system("pause");;break;
            case 10:li=inverserList(li);printf("done!\n\n");system("pause");;break;
            case 0:printf("Au revoir .\n");break;
            default :printf("Erreur de choix .\n");system("pause");break;
        }
    }while(c!=0);

    system("pause");
    return 0;
}
