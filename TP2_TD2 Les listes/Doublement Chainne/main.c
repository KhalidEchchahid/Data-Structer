#include "list.h"

int main()
{
    poly* p1,*p2,*p;objet o = {3,2}, a = {5,1},b = {2,0},f = {7,2},d = {2,1} ,g = {1,0},ob;int c,or;
    monome* e;
    p1 = creePoly();p2 = creePoly();p = creePoly();

    ajouterEntete(p1,a);
    ajouterEntete(p1,b);
    ajouterEntete(p2,d);
    ajouterEntete(p2,g);

    Sleep(150);
    printf("\n");Sleep(150);
    Sleep(150);
    printf("\n");Sleep(150);
    Sleep(150);
    printf("\n");Sleep(150);

    printf("Bonjour a notre programe des polynomes\nOn vas faire des operation sur les 2 polynomes suivants:\n");Sleep(150);
    p1 = triePoly(p1);afficherPoly(p1,"p1");
    p2 = triePoly(p2);afficherPoly(p2,"p2");
    Sleep(150);system("pause");Sleep(150);
    do
    {
        c = menu();
        switch(c)
        {
            case 1:
            afficherPoly(p1,"p1");
            Sleep(150);system("pause");break;

            case 2:
            afficherPoly(p2,"p2");
            Sleep(150);system("pause");break;

            case 3:
            remplirObjet(&ob);e = creeMonome(ob);
            insertMonome(p1,e);p1 = correctPoly(p1);
            printf("Done!\nSelectioner afficher pour avoir le nouvelle resultat:\n");Sleep(150);
            Sleep(150);system("pause");break;

            case 4:
            remplirObjet(&ob);e = creeMonome(ob);
            insertMonome(p2,e);p2 = correctPoly(p2);
            printf("Done!\nSelectioner afficher pour avoir le nouvelle resultat:\n");Sleep(150);
            Sleep(150);system("pause");break;

            case 5:Sleep(150);
            printf("Entrer l'ordre :");scanf("%d",&or);
            supprimerParOrdre(p1,or);Sleep(150);
            printf("Done!\nSelectioner afficher pour avoir le nouvelle resultat:\n");
            Sleep(150);system("pause");break;

            case 6:Sleep(150);
            printf("Entrer l'ordre :");scanf("%d",&or);
            supprimerParOrdre(p2,or);Sleep(150);
            printf("Done!\nSelectioner afficher pour avoir le nouvelle resultat:\n");
            Sleep(150);system("pause");break;

            case 7:Sleep(150);
            afficherPoly(p1," p1");
            printf("      + ");
            afficherPoly(p2," p2");Sleep(150);
            printf("      = ");
            p = sommePoly(p1,p2);
            afficherPoly(p,"res");
            Sleep(150);system("pause");break;

            case 8:Sleep(150);
            afficherPoly(p1," p1");
            printf("      - ");
            afficherPoly(p2," p2");Sleep(150);
            printf("      = ");
            p = soustractionPoly(p1,p2);
            afficherPoly(p,"res");
            Sleep(150);system("pause");break;

            case 9:Sleep(150);
            afficherPoly(p2," p2");
            printf("      - ");Sleep(150);
            afficherPoly(p1," p1");
            printf("      = ");
            p = soustractionPoly(p2,p1);
            afficherPoly(p,"res");
            Sleep(150);system("pause");break;

            case 10:Sleep(150);
            afficherPoly(p1," p1");
            printf("      x ");
            afficherPoly(p2," p2");Sleep(150);
            printf("      = ");
            p = produitPoly(p1,p2);
            afficherPoly(p,"res");
            Sleep(150);system("pause");break;
            
            case 11:Sleep(150);
            printf("Entrer le X = ");scanf("%d",&or);Sleep(150);
            afficherPoly(p1," p1");
            printf(" %s(%d) = %d \n","p1",or,evaluerPoly(p1,or));
            Sleep(150);system("pause");break;

            case 12:Sleep(150);
            printf("Entrer le X = ");scanf("%d",&or);Sleep(150);
            afficherPoly(p2," p2");
            printf(" %s(%d) = %d \n","p2",or,evaluerPoly(p2,or));
            Sleep(150);system("pause");break;

            case 13:Sleep(150);
            printf("Entrer le X = ");scanf("%d",&or);Sleep(150);
            afficherPoly(p," res");
            printf(" %s(%d) = %d \n","res",or,evaluerPoly(p,or));
            Sleep(150);system("pause");break;


            
            case 0:Sleep(150);
            printf("Au revoir \n");Sleep(150);
            system("pause");break;

            default:Sleep(150);
            printf("Erreur de choix :\n");
        }
    }while(c != 0);
    
    
    


    return 0;
}
