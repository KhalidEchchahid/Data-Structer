#include "arbre.h"

int main()
{
    arbre A;pnoeud a,b,c,d,e,f,g,h,i,j,k,l,m,n;
    A = arbreVide();
    a = creeNoeud("*");
    b = creeNoeud("-");
    c = creeNoeud("+");
    d = creeNoeud("3");
    e = creeNoeud("2");
    g = creeNoeud("/");
    h = creeNoeud("7");
    k = creeNoeud("10");
    l = creeNoeud("2");
    
    A = construire(a,b,c);b = construire(b,d,e) ;c = construire(c,h,g);
    g = construire(g,k,l); 


    printf("la methode infixe \n");
    parcoursInfixe(A);
    printf("\n");
 //   printf("%d \n",valide(A));
    printf("le resultat = %d \n",eval(A));
   // printf("%d \n",calcul(b,b->fg,b->fd));
   printf("la hauteur de l'arbre %d \n",hauteur(a));
    system("pause");
    return 0;
}
