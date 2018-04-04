
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fonction_interface.h"
// Calcul du Delta
static int delta(int a, int b, int c)
{
	return ((b*b) - (4*a*c));
}
//Racine carré arrondis à l'entier près
static int int_sqrt(int n) 
{
	int i=4, k=0,x=0,y=n;
	
	if (n == 0)
	{
		return 0;
	}
	else
	{
		while (k< i)
		{
			x= (y + (n/y))/2 ;
			y=x;
			k++;
		}
		return x;
	}
}
//Solution Delta >0
static float* solutionP(int delta,int a, int b,float* solutions)
{
	double nb= delta;

	float x1= (float)(-b + int_sqrt(nb))/ (float)(2*a);
	float x2 =(float)( -b - int_sqrt(nb))/(float)(2*a);
	solutions[0]=x1;
	solutions[1]=x2;
	return solutions;
}
// Solution Delta == 0
static float solutionS(int b, int a)
{
	float x= ((float)-b/(float)(2*a));
	return x;
}
// Valeur absolu des solutions en float
static float Valeur_absolu(float nombre)
{
	if(nombre <0)
		return -nombre;
	else
		return nombre;
}
//Valeur absolu de int
static int Valeur_absolu_int(int nombre)
{
	if(nombre <0)
		return -nombre;
	else
		return nombre;
}

//Forme canonique
static float canonique_carre(int a, int b)
{
	float c = (float)(b/(float)(2*a));
	return c;
}
float canonique_delta(int a, int Delta)
{
	float c = (float)(Delta/(float)(4 * (a*a)));
	return c; 
}

//Transforme un char en int
int char_to_int(char c)
{
	int n;
	if(c== '0') n=0;
	else n = c - '0'; 
	return n;
}
//Affochage equations premier degré
void Print_premier_degre(FILE *file,int a, int b, int c,int degre)
{
	//INDICATION
  fprintf(file,"INDICATION:\n");
  fprintf(file,"						=> On ne cherchera les solutions de l'équation");
  fprintf(file," que dans l'ensemble des réels\n");
  fprintf(file,"						=> sqrt() = racine carrée \n");
  fprintf(file,"						=> Les valeurs des racines carrée sont arrondis a l'");
  fprintf(file,"entier près ex: sqrt(20) = 4 au lieu de 4,47\n");
  //RESOLUTION
  fprintf(file,"RESOLUTION:\n");
  fprintf(file,"\n");
  //fprintf(file,"On cherche à résoudre l'équation suivante: %s \n",argv);
  fprintf(file,"C'est une équation de degré: %d \n",degre);
	int d,f,res,vres;
	float sol;
	fprintf(file,"Pour résoudre une équation de degré 1 voici les étapes:\n");
	fprintf(file,"1. On a donc cette équation\n");
	if(c ==0)
	{
			if(b > 0)
			{
				fprintf(file,"			=> %d * x + %d = 0\n",a,b);
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=> %d * x = -%d\n",a,b);
				fprintf(file,"			=>  x = -%d / %d\n",b,a);
				sol = ((float)b/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = -%.2f\n",sol);
			}
			else if(b <0)
			{
				f = Valeur_absolu_int(b);
				fprintf(file,"			=> %d * x - %d = 0\n",a,f);
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=> %d * x = %d\n",a,b);
				fprintf(file,"			=>  x = %d / %d\n",b,a);
				sol = ((float)b/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = %.2f\n",sol);
			}
			else
			{
				fprintf(file,"			=> %d * x = 0\n",a);
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=>  x = 0 / %d\n",a);
				sol = ((float)b/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = 0\n");
			}
			
		
	}
	else if(c < 0)
	{
		if(b > 0) // c > 0 et b> 0 => res >0
			{
				d = Valeur_absolu_int(c);
				fprintf(file,"			=> %d * x + %d + %d = 0\n",a,b,d);
				fprintf(file,"On obtient donc ceci : \n");
				res = b+d;
				fprintf(file,"			=> %d * x + %d = 0\n",a,res);
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=> %d * x = -%d\n",a,res);
				fprintf(file,"			=>  x = -%d / %d\n",res,a);
				sol = ((float)res/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = -%.2f\n",sol);
				
			}
		else if(b < 0)
		{
				d = Valeur_absolu_int(c);
				f = Valeur_absolu_int(b);
				fprintf(file,"			=> %d * x - %d + %d = 0\n",a,f,d);
				fprintf(file,"On obtient donc ceci : \n");
				res = b+d;
				if(res < 0)
				{ 
					vres = Valeur_absolu_int(res);
					fprintf(file,"			=> %d * x - %d = 0\n",a,vres);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> %d * x = %d\n",a,vres);
					fprintf(file,"			=>  x = %d / %d\n",vres,a);
					sol = ((float)vres/(float)a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=>  x = %.2f\n",sol);
				}
				else if(res == 0)
				{
					fprintf(file,"			=> %d * x = 0\n",a);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> x = 0 /%d\n",a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=> x = 0\n");
				}
				else
				{
					fprintf(file,"			=> %d * x + %d = 0\n",a,res);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> %d * x = -%d\n",a,res);
					fprintf(file,"			=>  x = -%d / %d\n",res,a);
					sol = ((float)res/ (float)a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=>  x = -%.2f\n",sol);
				}
			}
		else
		{
				d = Valeur_absolu_int(c);
				fprintf(file,"			=> %d * x + %d = 0\n",a,d);
				fprintf(file,"On obtient donc ceci : \n");
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=> %d * x = -%d\n",a,d);
				fprintf(file,"			=>  x = -%d / %d\n",d,a);
				sol = ((float)d/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = -%.2f\n",sol);
			}
		
	}
	else // c > 0
	{
		if(b > 0)
			{
				fprintf(file,"			=> %d * x + %d - %d = 0\n",a,b,c);
				fprintf(file,"On obtient donc ceci : \n");
				res = b-c;
				if(res < 0)
				{
					vres = Valeur_absolu_int(res);
					fprintf(file,"			=> %d * x - %d = 0\n",a,vres);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> %d * x = %d\n",a,vres);
					fprintf(file,"			=>  x = %d / %d\n",vres,a);
					sol = ((float)vres/(float)a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=>  x = %.2f\n",sol);
				}
				else if(res == 0)
				{
					fprintf(file,"			=> %d * x = 0\n",a);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> x = 0 /%d\n",a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=> x = 0\n");
				}
				else
				{
					fprintf(file,"			=> %d * x + %d = 0\n",a,res);
					fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
					fprintf(file,"			=> %d * x = -%d\n",a,res);
					fprintf(file,"			=>  x = -%d / %d\n",res,a);
					sol = ((float)res/(float)a);
					fprintf(file,"3. Le résultat de cette équation est donc :\n");
					fprintf(file,"			=>  x = -%.2f\n",sol);
				}
				
			}
		else if(b < 0) // c<0 et b< 0 => res < 0
		{
				f = Valeur_absolu_int(b);
				fprintf(file,"			=> %d * x - %d - %d = 0\n",a,f,c);
				fprintf(file,"On obtient donc ceci : \n");
				res = b-c;
				fprintf(file,"res = %d\n",res);
				//if(res < 0)
				//{ 
				vres = Valeur_absolu_int(res);
				fprintf(file,"			=> %d * x - %d = 0\n",a,vres);
				fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
				fprintf(file,"			=> %d * x = %d\n",a,vres);
				fprintf(file,"			=>  x = %d / %d\n",vres,a);
				sol = ((float)vres/(float)a);
				fprintf(file,"3. Le résultat de cette équation est donc :\n");
				fprintf(file,"			=>  x = %.2f\n",sol);
				
		}
		else
		{
			fprintf(file,"			=> %d * x - %d = 0\n",a,c);
			fprintf(file,"On obtient donc ceci : \n");
			fprintf(file,"2. On isole le x d'un côté de l'équation :\n");
			fprintf(file,"			=> %d * x = %d\n",a,c);
			fprintf(file,"			=>  x = %d / %d\n",c,a);
			sol = ((float)c/(float)a);
			fprintf(file,"3. Le résultat de cette équation est donc :\n");
			fprintf(file,"			=>  x = %.2f\n",sol);
		}
}
}


//Affichage de la forme canonique
static void Print_canonique(FILE *file,int a, int b, int Delta)
{
	fprintf(file,"5. Nous pouvons aussi obtenir la forme canonique de ce trinôme\n");
	fprintf(file,"\n");
	fprintf(file,"RAPPEL : la forme canonique de ce trinôme s'écrit: ");
	fprintf(file,"   C(x) = a * [ ( x + ( b / 2 * a) )² - ( D / 4 * a² )]");
	fprintf(file," où D est le delta de cette équation. \n");
	fprintf(file,"\n");
	fprintf(file,"				Ici a = %d , b = %d , D = %d\n",a,b,Delta);
	fprintf(file,"	On obient donc :\n");
	fprintf(file,"		=> C(x) = %d * [ ( x + (%d / 2 * %d) )² - ( %d / 4 * %d² )]\n",a,
	b,a,Delta,a);
	float premierTerme= canonique_carre(a,b);
	float secondTerme =canonique_delta(a,Delta);
	float prems = Valeur_absolu(premierTerme);
	float deuz= Valeur_absolu(secondTerme);
	if(a!=1)
	{
		if(premierTerme < 0 && secondTerme <0)
		{
			fprintf(file,"			= %d * [ ( x - %.2f)² + %.2f]\n",a,prems,deuz);
		}
		else if(premierTerme > 0 && secondTerme >0)
		{
			fprintf(file,"			= %d * [ ( x + %.2f)² - %.2f]\n",a,prems,deuz);
		}
		else if(premierTerme >0 && secondTerme <0)
		{
			fprintf(file,"			= %d * [ ( x + %.2f)² + %.2f]\n",a,prems,deuz);
		}
		else
		{
			fprintf(file,"			= %d * [ ( x - %.2f)² - %.2f]\n",a,prems,deuz);
		}
	}
	else
	{
		if(premierTerme < 0 && secondTerme <0)
		{
			fprintf(file,"			= ( x - %.2f)² + %.2f\n",prems,deuz);
		}
		else if(premierTerme > 0 && secondTerme >0)
		{
			fprintf(file,"			= ( x + %.2f)² - %.2f\n",prems,deuz);
		}
		else if(premierTerme >0 && secondTerme <0)
		{
			fprintf(file,"			= ( x + %.2f)² + %.2f\n",prems,deuz);
		}
		else
		{
			fprintf(file,"			= ( x - %.2f)² - %.2f\n",prems,deuz);
		}
	}
	
}

//Affichage des equations du second degré
void Print_Second_degre(FILE *file,int a, int b, int c,int degre)
{
	float solP[2]={};
	float solution;
	float x1;
	float x;
	float x2;
	//INDICATION
  fprintf(file,"INDICATION:\n");
  fprintf(file,"						=> On ne cherchera les solutions de l'équation");
  fprintf(file," que dans l'ensemble des réels\n");
  fprintf(file,"						=> sqrt() = racine carrée \n");
  fprintf(file,"						=> Les valeurs des racines carrée sont arrondis a l'");
  fprintf(file,"entier près ex: sqrt(20) = 4 au lieu de 4,47\n");
  //RESOLUTION
  fprintf(file,"RESOLUTION:\n");
  fprintf(file,"\n");
  //fprintf(file,"On cherche à résoudre l'équation suivante: %s \n",argv);
  fprintf(file,"C'est une équation de degré: %d \n",degre);
	//Calcul du Delta
	int Delta= delta(a,b,c);
	fprintf(file,"Pour résoudre une équation de degré 2 voici les étapes:\n");
	fprintf(file,"1. On calcule le Delta (note D) :\n");
	fprintf(file,"			D = b² - 4 * a * c \n");
	fprintf(file,"			avec a = %d, b = %d, c = %d \n",a,b,c);
	fprintf(file,"Ce qui donne :\n");
	fprintf(file,"			D = %d² - 4*%d*%d = %d\n",b,a,c, Delta);
	fprintf(file,"2. On regarde maintenant la valeur de D pour savoir le nombre de");
	fprintf(file," solutions que possède l'équation: \n");
	if(Delta>0)
		{/**************************************************************/
			fprintf(file,"Le D est positif, l'équation a donc deux solutions :\n");
			fprintf(file,"3. Les solutions s'écrivent donc: \n");
			
			fprintf(file,"			x1 = (-b + sqrt(D))/ 2*a; x2 = (-b - sqrt(D))/ 2*a \n");
			fprintf(file,"Ainsi on otient: \n"); 
			solutionP(Delta,a,b,solP);
			if(b < 0)
			{
				fprintf(file,"			x1 = (%d + sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[0]);
				fprintf(file," 			x2 = (%d - sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[1]);
			}
			else if(b==0)
			{
				fprintf(file,"			x1 = (sqrt(%d))/ 2*%d = %.2f\n",Delta,a,solP[0]);
				fprintf(file," 			x2 = (- sqrt(%d))/ 2*%d = %.2f\n",Delta,a,solP[1]);
			}
			else
			{
				fprintf(file,"			x1 = (-%d + sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[0]);
				fprintf(file," 			x2 = (-%d - sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[1]);
			}
			x1 = Valeur_absolu(solP[0]);
			x2 = Valeur_absolu(solP[1]);
			fprintf(file,"RESULTATS:\n");
			fprintf(file," 			=> D = %d \n", Delta);
			fprintf(file,"			=> x1 = %.2f \n", solP[0]);
			fprintf(file,"			=> x2 = %.2f \n", solP[1]);
			fprintf(file,"\n");
			fprintf(file,"4. Nous pouvons maintenant trouver le polynôme factorisé de");
			fprintf(file," cette équation:\n");
			fprintf(file,"RAPPEL : f(x) = a * (x - x1) * (x - x2) ou x1,x2 sont les ");
			fprintf(file," solutions de f(x) = 0 (trouvées dans 3. )\n");
			fprintf(file,"\n");
			fprintf(file,"Ainsi ici notre polynôme factorisé s'écrit:\n");
			if(a!=1)
			{/**************************************************************/
				if(solP[0]==0.00)
				{
					if(solP[1] < 0)
					{
						fprintf(file,"	f(x) = a * x * ( x + x2) car x1 = 0\n");
						fprintf(file,"	Donc, f(x) = %d * x * ( x + %.2f)\n", a, x2);
					}
					else
					{
						fprintf(file,"	f(x) = a * x * ( x - x2) car x1 = 0\n");
						fprintf(file,"	Donc, f(x) = %d * x * ( x - %.2f)\n", a, x2);
					}
				}
				else if( solP[1]==0.00)
				{
					if(solP[0]<0)
					{
						fprintf(file,"	f(x) = a* x * ( x - x1) car x2 = 0 \n");
						fprintf(file,"	Donc, f(x) = %d * x * ( x - %.2f)\n",a,x1);
					}
					else
					{
						fprintf(file,"	f(x) = a* x * ( x + x1) car x2 = 0 \n");
						fprintf(file,"	Donc, f(x) = %d * x * ( x + %.2f)\n",a,x1);
					}
				}
				else
				{
					if(solP[0]<0 && solP[1]>0)
					{
						fprintf(file," f(x) = %d * ( x + %.2f)",a,x1);
						fprintf(file," * ( x - %.2f)\n",x2);
					}
					else if(solP[0]>0 && solP[1]<0)
					{
						fprintf(file," f(x) = %d * ( x - %.2f)",a,x1);
						fprintf(file," * ( x + %.2f)\n",x2);
					}
					else if(solP[0] > 0 && solP[1]>0)
					{
						fprintf(file," f(x) = %d * ( x - %.2f)",a,x1);
						fprintf(file," * ( x - %.2f)\n",x2);
					}
					else
					{
						fprintf(file," f(x) = %d * ( x + %.2f)",a,x1);
						fprintf(file," * ( x + %.2f)\n",x2);
					}
				}
			}
			/**************************************************************/
			else
			{/**************************************************************/
				if(solP[0]==0.00)
				{
					if(solP[1]>0)
					{
						fprintf(file,"	f(x) = x * ( x - x2) car x1 = 0 et a = 1 \n");
						fprintf(file,"	Donc, f(x) = x * ( x - %.2f)\n",x2);
					}
					else
					{
						fprintf(file,"	f(x) = x * ( x + x2) car x1 = 0 et a = 1 \n");
						fprintf(file,"	Donc, f(x) = x * ( x + %.2f)\n",x2);
					}
				}
				else if(solP[1]==0.00)
							{
								if(solP[0]>0)
								{
									fprintf(file,"	f(x) = x * ( x - x1) car x2 = 0 et a= 1 \n");
									fprintf(file,"	Donc, f(x) = x * ( x - %.2f)\n",x1);
								}
								else
								{
									fprintf(file,"	f(x) = x * ( x + x1) car x2 = 0 et a= 1 \n");
									fprintf(file,"	Donc, f(x) = x * ( x + %.2f)\n",x1);
								}					
							}
				else
				{
						if(solP[0]<0 && solP[1]>0)
						{
							fprintf(file," f(x) = x * ( x + %.2f)", x1);
							fprintf(file," * ( x - %.2f) car a = 1 \n",x2);
						}
						else if(solP[0]>0 && solP[1]<0)
						{
							fprintf(file," f(x) = x * ( x - %.2f)", x1);
							fprintf(file," * ( x + %.2f) car a = 1 \n",x2);
						}
						else if(solP[0] > 0 && solP[1]>0)
						{
							fprintf(file," f(x) = x * ( x - %.2f)", x1);
							fprintf(file," * ( x - %.2f) car a = 1 \n",x2);
						}
						else
						{
							fprintf(file," f(x) = x * ( x + %.2f)", x1);
							fprintf(file," * ( x + %.2f) car a = 1 \n",x2);
						}
					}
					}
					/**************************************************************/
			
		}
		/**************************************************************/
		else if(Delta==0)
		{/**************************************************************/
			fprintf(file,"Le D est nul, l'équation a donc une solution :\n");
			fprintf(file,"3. La solution s'écrit donc:\n");
			fprintf(file,"			x= a / b ;\n");
			fprintf(file,"Ainsi on obtient: \n");
			solution = solutionS(a,b);
			fprintf(file," x = %d / %d = %.2f",a,b,solution);
			x = Valeur_absolu(solution);
			fprintf(file,"RESULTATS:\n");
			fprintf(file," 			=> D = %d \n", Delta);
			fprintf(file,"			=> x = %.2f \n", solution);
			fprintf(file,"4. Nous pouvons maintenant trouver le polynôme factorisé de");
			fprintf(file," cette équation:\n");
			fprintf(file,"RAPPEL : f(x) = a * (x - S) * (x - S) ou S est la ");
			fprintf(file," solution de f(x) = 0 (trouvées dans 3. )\n");
			fprintf(file,"\n");
			fprintf(file,"Ainsi ici notre polynôme factorisé s'écrit:\n");
			if(a!=1)
			{/**************************************************************/
				if(solution <0)
				{
						fprintf(file,"	Donc, f(x) = %d * ( x + %.2f) * ( x + %.2f)\n", a,x,x);
				}
				else
				{
					fprintf(file,"	Donc, f(x) = %d * ( x - %.2f) * ( x - %.2f)\n", a,x,x);
				}
		}
		/**************************************************************/
		else
		{/**************************************************************/
			if(solution <0)
				{
						fprintf(file,"	Donc, f(x) = ( x + %.2f) * ( x + %.2f)\n",x,x);
				}
				else
				{
					fprintf(file,"	Donc, f(x) = ( x - %.2f) * ( x - %.2f)\n",x,x);
				}
	  }/**************************************************************/
	}
		/**************************************************************/
		else{/**************************************************************/
			fprintf(file,"Comme le D est négatif, et comme nous sommes dans l'ensemble");
			fprintf(file," réel");
			fprintf(file," il n'a donc pas de solutions, nous sommes actuellement dans");
			fprintf(file," l'ensemble des complexes\n");}
			/**************************************************************/
		Print_canonique(file,a,b, Delta);
}
