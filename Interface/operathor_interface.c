
# include "identification.h"
# include "fonction_interface.h"
#include "troisieme_interface.h"

void PrintMain(struct coeff* cf,int degre,char* argv)
{ 
  int a, b, c;
  if(degre == 2) {/**********************************************************/
	
	 a = cf->left[2];
 	 b = cf->left[1];
 	 c = cf->left[0];
	FILE *fichier =NULL;
	fichier = fopen("Second_degré.txt", "w");
	if(fichier != NULL)
	{
	   Print_Second_degre(fichier,a,b,c,argv,degre);
	   fclose(fichier);
	}	
  }                                           
  /**************************************************************/	
  if(degre == 1) {
	a = cf->left[1];
	b = cf->left[0];
	c = cf->right[0];
	FILE* fichier = NULL;
	fichier = fopen("Premier_degré.txt", "w");
	if(fichier != NULL)
	{
	   Print_premier_degre(fichier,a,b,c,argv,degre);
	   fclose(fichier);
	}	
	
	
  }
	if(degre ==3)
	{
		int b1 = cf->left[2];
 		int c1 = cf->left[1];
 		int d1 = cf->left[0];
		FILE* fichier = NULL;
		fichier = fopen("Troisième_degré.txt", "w");
		if(fichier != NULL)
		{
		   Print_degre_trois(fichier,b1,c1,d1,argv,degre);
		   fclose(fichier);
		}
		//int a1 = cf->left[3];
		
		/*double a2 = cf->right[3];
		double b2 = cf->right[2];
		double c2 = cf->right[1];
		double d2 = cf->right[0];*/
		
		
	}
}
int main(int argc, char *argv[]) {

  if (argc < 2) errx(1 ,"Il manque des arguments, Écrire une équation svp");
  if (argc > 2) errx(1 ,"Too much arguments");

  struct coeff *cf = PutExpression(argv[1]);

  //Initialisation et attribution
  int degre = FindDegree(cf->left);
  if(degre > 5) {
  	printf("Désolé ce solveur ne prend pas les équations de degré supérieur");
    printf(" à 5. Merci de votre compréhension\n");
	return 0;
  }
 
  PrintMain(cf,degre,argv[1]);
  FreeCoeff(cf);
  return 0;
}
