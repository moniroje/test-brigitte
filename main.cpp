/* quelleCaseTableauContientCertaineValeur
 * Écrire une fonction f ayant en paramètres un tableau t de taille quelconque
 * et un entier n indiquant la taille du tableau. f doit renvoyer par un return
 * un entier égal à l'indice de la première case du tableau (parmi les n)
 * contenant une valeur comprise entre min et MAX. S'il n'existe pas de telle
 * valeur, la fonction renvoie -1. Tester cette fonction. */

#include<iostream>
using namespace std;
// je crée la variable i dont j'aurais besoin pour itérer dans le tableau:
/* int i ; ici, elle est globale et c'est pas bon dit linux5623!
 *  Moi, je croyais que c'était bien parce que i sert pour les fonctions
 * saisir() et f()... note c+ec027: "Les variables globales sont définies
 * hors de tout corps de fonction et sont disponibles pour tous les éléments
 * du programme (même le code d'autres fichiers).
 * Les variables globales ne sont pas affectées par les portées et sont toujours
 * disponibles (une variable globale dure jusqu'à la fin du programme)." et donc
 * pourquoi c'est pas bien ?? */
// je crée la fonction saisir() qui servira à remplir un tableau:
void saisir(int t[],int n)
   {
    int i; // OK, je déclare ici la variable d'itération i (variable locale)
    for(i=0;i<n;i++)
      {  // accolades pour la boucle for
       cout<<"Tapez la valeur de la case numero "<<i<<" : ";
       cin>> t[i];
      }
   }

// je crée la fonction f() demandée:
int f(int t[], int n)  /* ce qui => ! unused parameter 'n' si j'utilise plus bas, le
                        * while (ind==-1) */
     {
      int min=0, MAX=0; /*je déclare les variables minimale et maximale de la
                         * fourchette et je les initialise = 0 sinon il me
                         * balance ce message aux cout: "Problème: min is used
                         * uninitialized in this function"   */
      int ind=-1; /* je déclare et initialise ind qui contiendra le numéro de
                   * la case gagnante; ou bien -1; je fais de même pour la
                   * variable d'itération i dans le cadre de cette fonction:*/
      int i=0; // la première case se nomme 0 (variable locale)
      cout<<"Tape la valeur minimale de ta recherche: "<<min<<" : ";
      cin>> min;
      cout<<"Maintenant donne la valeur maxi de ta fourchette: "<<MAX<<" : ";
      cin>>MAX;
      /* maintenant la fonction va chercher dans chacune des cases du tableau:
       * il faut donc une boucle... essayons la boucle while qui se construit ainsi :
       * while (condition) {// instructions à répéter }
       * tout ce qui est entre les accolades est répété tant que la condition est
       * vérifiée. Dans mon cas, la condition pour que ça se répète est ind=-1 */
      /* while (ind==-1) /* le code fonctionne; mais il me dit toujours "Pas de valeur
                       * dans la fourchette fixée", même si j'en ai mis une. shit!
                       * le corrigé a en plus de moi: && i<n: faisons: */
       while (ind==-1 && i<n) /* ==-1 signifie "Pas de valeur dans la fourchette fixée",
                               * même si j'en ai mis une. */
        {
         // si t[i] dans la fourchette gagnante, tu mets la valeur i dans ind
         if(t[i]>=min && t[i]<=MAX)ind=i;
         // et comme ind n'est pas -1, hop, la boucle while s'arrête
         else i++; // si ce n'est pas le cas, alors tu vas à la case suivante
         return ind;  // quand la boucle while s'arrête, ça retourne ind
        }
    }  // fin de la fonction f() => ! control reaches  end of non-void function

int main()
{
 int a[10];  // soit le tableau a de taille 10
 int w;  // on déclare la variable w qui sera le résultat de la fonction f()
 int i=0; // pour que le cout ci-dessous ne soit pas en ERROR

 saisir(a,10);  // on utilise saisir() pour le tableau a de taille 10
 w=f(a,10);  // dans w on met la valeur retournée par la fonction f()
 // ci-dessous est dit: si (w n'est pas -1): soit le numéro de la case gagnante
 if(w!=-1)
  {cout<<"Il existe une valeur dans la fourchette que tu as fixée. "<<endl;
   cout<<"la case contenant cette valeur dans la fourchette fixée est la "<<w<<"ième"<<endl;
   // zut!! toujours le même résultat: est la 10 ième mêm si je mets en case 3!
   cout<<" et cette valeur est  "<<a[i]<<endl;
   // ce qui => ERROR: i was not declared in this scope; OK, je déclare ci-dessus
  }
 else cout<<"Pas de valeurs dans la fourchette que tu as fixée. "<<endl;
 return 0;
}




