
# include "identification.h"
# include "fonction.h"
#include "troisieme.h"
int main(int argc, char *argv[]) {

  if (argc < 2) errx(1 ,"Missing arguments, this program need an equation");
  if (argc > 2) errx(1 ,"Too much arguments");

  struct coeff *cf = PutExpression(argv[1]);

  //Initialisation et attribution
  int degre = FindDegree(cf->left);
  if(degre > 4) {
  	printf("Desole ce solveur ne prends pas les equations de degre superieur");
    printf(" a 3. Merci de votre comprehension\n");
	return 0;
  }
  printcoeff(cf);
  int a, b, c;

  //INDICATION
  printf("INDICATION:\n");
  printf("						=> On ne cherchera les solutions de l equation");
  printf(" que dans l ensemble des reels\n");
  printf("						=> sqrt() = racine carre \n");
  printf("						=> Les valeurs des racines carre sont arrondis a l");
  printf(" entier pres ex: sqrt(20) = 4 au lieu de 4,47\n");
  //RESOLUTION
  printf("RESOLUTION:\n");
  printf("\n");
  printf("On cherche a resoudre l equation suivante: %s \n",argv[1]);
  printf("C est une equation de degre: %d \n",degre);
  if(degre == 2) {/**********************************************************/
	printf("On a :\n");
	printf("		f(x) = %s\n",argv[1]);
	a = cf->left[2];
	b = cf->left[1];
	c = cf->left[0];

	Print_Second_degre(a, b, c);
  }                                           
  /**************************************************************/	
  if(degre == 1) {
	printf("Pour résoudre une equation de degre 1 voici les etapes:\n");
	printf("On a :\n");
  printf("		f(x) = %s\n",argv[1]);
			
	a = cf->left[1];
	b = cf->left[0];
	c = cf->right[0];
	Print_premier_degre(a,b,c);
  }
	if(degre ==3)
	{
		printf("Pour résoudre une equation de degre 3 voici les etapes:\n");
		printf("On a :\n");
		printf("		f(x) = %s\n",argv[1]);
		double a1 = cf->left[3];
		double b1 = cf->left[2];
		double c1 = cf->left[1];
		double d1 = cf->left[0];
		double a2 = cf->right[3];
		double b2 = cf->right[2];
		double c2 = cf->right[1];
		double d2 = cf->right[0];
		poly(a1,b1,c1,d1,a2,b2,c2,d2);
		
	}

  FreeCoeff(cf);
  return 0;
}
