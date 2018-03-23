
# include "identification.h"
# include "fonction_terminal.h"
#include "troisieme_terminal.h"
int main(int argc, char *argv[]) {

  if (argc < 2) errx(1 ,"Il manque des arguments, Écrire une équation svp");
  //if (argc > 2) errx(1 ,"Too much arguments");

  //struct coeff *cf = PutExpression(argv[1]);
  struct coeff *cf = malloc(sizeof(struct coeff));
  cf->left = calloc(5, sizeof(int));
  cf->right = calloc(5, sizeof(int));

  cf->left[0] = atoi(argv[1]);
  cf->left[1] = atoi(argv[2]);
  cf->left[2] = atoi(argv[3]);
  cf->left[3] = atoi(argv[4]);
  cf->left[4] = atoi(argv[5]);

  cf->right[0] = atoi(argv[6]);
  cf->right[1] = atoi(argv[7]);
  cf->right[2] = atoi(argv[8]);
  cf->right[3] = atoi(argv[9]);
  cf->right[4] = atoi(argv[10]);
  //Initialisation et attribution
  int degre = FindDegree(cf->left);
  if(degre > 5) {
  	printf("Desole ce solveur ne prends pas les equations de degre superieur");
    printf(" a 5. Merci de votre comprehension\n");
	return 0;
  }
  printcoeff(cf);
  Diff(cf);
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
		//int a1 = cf->left[3];
		int b1 = cf->left[2];
		int c1 = cf->left[1];
		int d1 = cf->left[0];
		/*double a2 = cf->right[3];
		double b2 = cf->right[2];
		double c2 = cf->right[1];
		double d2 = cf->right[0];*/
		troisieme(b1,c1,d1);
		
	}

  FreeCoeff(cf);
  return 0;
}
