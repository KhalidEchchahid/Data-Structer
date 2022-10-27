#include "arbre.h"


int main()
{
    ABR A;
    A = cree_ABR(A);
    //Exercice 1:fonction Inserer un valeur on respectant la forme ABR.
    printf("Exercice 1 Insertion\n");
    A = inserer(A,5);A = inserer(A,3);A = inserer(A,9);
    A = inserer(A,1);A = inserer(A,4);A = inserer(A,6);
    affichage_ABR(A);


    //Exercice 2 :fonction de destrucion d'un arbre.
    printf("Exercice 2 Destruction\n");
    ABR B = cree_ABR();
    B = inserer(B,3);B = inserer(B,5);B = inserer(B,67);
    B = inserer(B,1);
    affichage_ABR(B);
    detruire(B);

    //Exercice 3 :fonction d'affichege.
    printf("\nExercice 3 foction d'affichage\naffichage croissant\n");
    afficher1(A);
    printf("\n");
    printf("Affichage 2\n");
    afficher2(A);
    printf("\n");


    //Exercice 4 :
    //Fonction verifie d'un ABR
    //l'ajout d'un arbre e invalid.
    Pnoeud e,f,k,t,j,h,d,q,m;
    e = cree_Noeud(12);f = cree_Noeud(8);k = cree_Noeud(17);t = cree_Noeud(6);
    j = cree_Noeud(9);
    h = cree_Noeud(16);d = cree_Noeud(20);q = cree_Noeud(3);m = cree_Noeud(10);
    e = construire(e,construire(f,construire(t,q,m),j),construire(k,h,d));
    //test sur les arbres .
    printf("\nExercice 4 fonction de verification\n1 vaut valide , 0 vaut non valide\n");
    printf("Arbre A = %d\n",verifie(A));
    printf("Arbre e = %d\n",verifie(e));

    //foction taille
    printf("\nla taille de l'arbre A = %d\n",taille(A));
    printf("\nla hauteur de l'arbre A = %d\n",Hauteur(A));

    //foction de la somme + foction de la moyenne
    printf("\nla somme de A = %d ,la moyenne de A = %.2f\n",somme(A),moyenne(A));

    //Exercice 5
    //fonction de recherche
    printf("\nExercice 5\n\nfonction de recherche\n");
    Pnoeud x = chercher(A,6);
    if( x != NULL) printf("la valeur %d trouver a l'adresse %x\n",x->val,x);
    else printf("NULL\n");

    //foctions de maximum et minimum d'ABR
    Pnoeud mini = minimum(A),maxi = maximum(A);
    printf("\nfoctions de maximum et minimum d'ABR.\n");
    printf("\nElement max = %d,Element min = %d\n",maxi->val,mini->val);
    
    //fonction  successeur et  predecesseur
    printf("\nfonction  successeur et  predecesseur.\n");
    Pnoeud succ,pred;
    succ = successeur(A,5);
    p = NULL;//p variable global
    pred = predecesseur(A,5);
    printf("le successeur de 5 est %d le predecesseur %d\n",succ->val,pred->val);
    
    //Exercice 6 fonction de suppression 
    printf("Exercice 6\nfonction de suppression par valeur :5\n");
    A = supprimer(A,5);
    affichage_ABR(A);

    //Exercice 7 fonction de comparison
    printf("Exercice 7\nfonction d'equivalence\n");
    printf("Equivalence %d. \n",equivalents(A,A));
    system("pause");
    return 0;
}