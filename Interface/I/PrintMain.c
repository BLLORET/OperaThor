#include "PrintMain.h"

void Printmain(FILE* file,struct coeff *cf, int degre)
{
if(degre > 5) {
  	fprintf(file,"Désolé ce solveur ne prends pas les équations de degré superieur");
    fprintf(file," a 5. Merci de votre compréhension\n");
  }
 //INDICATION
  fprintf(file,"INDICATION:\n");
  fprintf(file,"						=> On ne cherchera les solutions de l'équation");
  fprintf(file," que dans l'ensemble des réels\n");
  fprintf(file,"						=> sqrt() = racine carré \n");
  fprintf(file,"						=> Les valeurs des racines carré sont arrondis a l'");
  fprintf(file" entier près ex: sqrt(20) = 4 au lieu de 4,47\n");
  cf = Diff(cf);
  int a, b, c;

 
  //RESOLUTION
  fprintf(file,"RESOLUTION:\n");
  fprintf(file,"\n");
  fprintf(file,"C'est une équation de degré: %d \n",degre);
  if(degre == 2) {/**********************************************************/
	a = cf->left[2];
	b = cf->left[1];
	c = cf->left[0];

	Print_Second_degre(a, b, c);
  }                                           
  /**************************************************************/	
  if(degre == 1) {
	fprintf(file,"Pour résoudre une équation de degré 1 voici les étapes:\n");
	a = cf->left[1];
	b = cf->left[0];
	c = cf->right[0];
	Print_premier_degre(a,b,c);
  }
	if(degre ==3)
	{
		fprintf(file,"Pour résoudre une équation de degré 3 voici les étapes:\n");
		int b1 = cf->left[2];
		int c1 = cf->left[1];
		int d1 = cf->left[0];
		Print_degre_trois(file,b1,c1,d1);
		
	}

}
