
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "fonction.h"
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
	float x= (float)(-b/(2*a));
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
void Print_premier_degre(int a, int b, int c)
{
	int d,f,res,vres;
	float sol;
	printf("1. On passe tout d'un même côté en faisaint attention ");
	printf("aux signes. Si on a deja  = 0 alors cela ne changera rien\n");
	if(c ==0)
	{
			if(b > 0)
			{
				printf("			=> %d * x + %d = 0\n",a,b);
				printf("2. On isole le x d un cote de l equation :\n");
				printf("			=> %d * x = -%d\n",a,b);
				printf("			=>  x = -%d / %d\n",b,a);
				sol = (float)(b/a);
				printf("3. Le resultat de cette equation est donc :\n");
				printf("			=>  x = -%.2f\n",sol);
			}
			else
			{
				f = Valeur_absolu_int(b);
				printf("			=> %d * x - %d = 0\n",a,f);
				printf("2. On isole le x d un cote de l equation :\n");
				printf("			=> %d * x = %d\n",a,b);
				printf("			=>  x = %d / %d\n",b,a);
				sol = (float)(b/a);
				printf("3. Le resultat de cette equation est donc :\n");
				printf("			=>  x = %.2f\n",sol);
			}
		
	}
	else if(c < 0)
	{
		if(b > 0) // c > 0 et b> 0 => res >0
			{
				d = Valeur_absolu_int(c);
				printf("			=> %d * x + %d + %d = 0\n",a,b,d);
				printf("On obtient donc ceci : \n");
				res = b+d;
				printf("			=> %d * x + %d = 0\n",a,res);
				printf("2. On isole le x d un cote de l equation :\n");
				printf("			=> %d * x = -%d\n",a,res);
				printf("			=>  x = -%d / %d\n",res,a);
				sol = (float)(res/a);
				printf("3. Le resultat de cette equation est donc :\n");
				printf("			=>  x = -%.2f\n",sol);
				
			}
		else if(b < 0)
		{
				d = Valeur_absolu_int(c);
				f = Valeur_absolu_int(b);
				printf("			=> %d * x - %d + %d = 0\n",a,f,d);
				printf("On obtient donc ceci : \n");
				res = b+d;
				if(res < 0)
				{ 
					vres = Valeur_absolu_int(res);
					printf("			=> %d * x - %d = 0\n",a,vres);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> %d * x = %d\n",a,vres);
					printf("			=>  x = %d / %d\n",vres,a);
					sol = (float)(vres/a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=>  x = %.2f\n",sol);
				}
				else if(res == 0)
				{
					printf("			=> %d * x = 0\n",a);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> x = 0 /%d\n",a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=> x = 0\n");
				}
				else
				{
					printf("			=> %d * x + %d = 0\n",a,res);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> %d * x = -%d\n",a,res);
					printf("			=>  x = -%d / %d\n",res,a);
					sol = (float)(res/a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=>  x = -%.2f\n",sol);
				}
			}
			else
			{
				printf("			=> %d * x + %d = 0\n",a,d);
				printf("On obtient donc ceci : \n");
				printf("2. On isole le x d un cote de l equation :\n");
				printf("			=> %d * x = -%d\n",a,d);
				printf("			=>  x = -%d / %d\n",d,a);
				sol = (float)(d/a);
				printf("3. Le resultat de cette equation est donc :\n");
				printf("			=>  x = -%.2f\n",sol);
			}
		
	}
	else // c > 0
	{
		if(b > 0)
			{
				printf("			=> %d * x + %d - %d = 0\n",a,b,c);
				printf("On obtient donc ceci : \n");
				res = b-c;
				if(res < 0)
				{
					vres = Valeur_absolu_int(res);
					printf("			=> %d * x - %d = 0\n",a,vres);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> %d * x = %d\n",a,vres);
					printf("			=>  x = %d / %d\n",vres,a);
					sol = (float)(vres/a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=>  x = %.2f\n",sol);
				}
				else if(res == 0)
				{
					printf("			=> %d * x = 0\n",a);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> x = 0 /%d\n",a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=> x = 0\n");
				}
				else
				{
					printf("			=> %d * x + %d = 0\n",a,res);
					printf("2. On isole le x d un cote de l equation :\n");
					printf("			=> %d * x = -%d\n",a,res);
					printf("			=>  x = -%d / %d\n",res,a);
					sol = (float)(res/a);
					printf("3. Le resultat de cette equation est donc :\n");
					printf("			=>  x = -%.2f\n",sol);
				}
				
			}
		else if(b < 0) // c<0 et b< 0 => res < 0
		{
				f = Valeur_absolu_int(b);
				printf("			=> %d * x - %d - %d = 0\n",a,f,c);
				printf("On obtient donc ceci : \n");
				res = b-c;
				printf("%d",res);
				//if(res < 0)
				//{ 
				vres = Valeur_absolu_int(res);
				printf("			=> %d * x - %d = 0\n",a,vres);
				printf("2. On isole le x d un cote de l equation :\n");
				printf("			=> %d * x = %d\n",a,vres);
				printf("			=>  x = %d / %d\n",vres,a);
				sol = (float)(vres/a);
				printf("3. Le resultat de cette equation est donc :\n");
				printf("			=>  x = %.2f\n",sol);
				
		}
		else
		{
			printf("			=> %d * x - %d = 0\n",a,c);
			printf("On obtient donc ceci : \n");
			printf("2. On isole le x d un cote de l equation :\n");
			printf("			=> %d * x = %d\n",a,c);
			printf("			=>  x = %d / %d\n",c,a);
			sol = (float)(c/a);
			printf("3. Le resultat de cette equation est donc :\n");
			printf("			=>  x = %.2f\n",sol);
		}
}
}

//Récupère l'équation à gauche du =
char* gauche(char* data, char* recup)
{
	int i=0;
	while( data[i] != '=')
	{
		*recup= data[i];
		recup ++;
		i++;
	}
	return recup;
}
//Récupère le int à droite du =
int droit(char* data)
{
	int i=0;
	while( data[i] != '=')
	{
		i++;
	}
	int d = char_to_int(data[i+1]);
	return d;
}
int* recup_chiffres(char* data, int* recup)
{
	for(size_t i=0; i< strlen(data);i++)
	{
		if(data[i] >= '0' && data[i] <= '9')
		{
			*(recup)= char_to_int(data[i]);
			recup++;
		}
	}
	return recup;
}	
//Affichage de la forme canonique
static void Print_canonique(int a, int b, int Delta)
{
	printf("5. Nous pouvons aussi obtenir la forme canonique de ce trinome\n");
	printf("\n");
	printf("RAPPEL : la forme canonique de ce trinome s'écrit: ");
	printf("   C(x) = a * [ ( x + ( b / 2 * a) )² - ( D / 4 * a² )]");
	printf(" ou D est le delta de cette equation. \n");
	printf("\n");
	printf("				Ici a = %d , b = %d , D = %d\n",a,b,Delta);
	printf("	On obient donc :\n");
	printf("		=> C(x) = %d * [ ( x + (%d / 2 * %d) )² - ( %d / 4 * %d² )]\n",a,
	b,a,Delta,a);
	float premierTerme= canonique_carre(a,b);
	float secondTerme =canonique_delta(a,Delta);
	float prems = Valeur_absolu(premierTerme);
	float deuz= Valeur_absolu(secondTerme);
	if(a!=1)
	{
		if(premierTerme < 0 && secondTerme <0)
		{
			printf("			= %d * [ ( x - %.2f)² + %.2f]\n",a,prems,deuz);
		}
		else if(premierTerme > 0 && secondTerme >0)
		{
			printf("			= %d * [ ( x + %.2f)² - %.2f]\n",a,prems,deuz);
		}
		else if(premierTerme >0 && secondTerme <0)
		{
			printf("			= %d * [ ( x + %.2f)² + %.2f]\n",a,prems,deuz);
		}
		else
		{
			printf("			= %d * [ ( x - %.2f)² - %.2f]\n",a,prems,deuz);
		}
	}
	else
	{
		if(premierTerme < 0 && secondTerme <0)
		{
			printf("			= ( x - %.2f)² + %.2f\n",prems,deuz);
		}
		else if(premierTerme > 0 && secondTerme >0)
		{
			printf("			= ( x + %.2f)² - %.2f\n",prems,deuz);
		}
		else if(premierTerme >0 && secondTerme <0)
		{
			printf("			= ( x + %.2f)² + %.2f\n",prems,deuz);
		}
		else
		{
			printf("			= ( x - %.2f)² - %.2f\n",prems,deuz);
		}
	}
	
}

//Affichage des equations du second degré
void Print_Second_degre(int a, int b, int c)
{
	float solP[2]={};
	float solution;
	float x1;
	float x;
	float x2;
	//Calcul du Delta
	int Delta= delta(a,b,c);
	printf("Pour résoudre une equation de degre 2 voici les etapes:\n");
	printf("1. On calcul le Delta (note D) :\n");
	printf("			D = b² - 4 * a * c \n");
	printf("			avec a = %d, b = %d, c = %d \n",a,b,c);
	printf("Ce qui donne :\n");
	printf("			D = %d² - 4*%d*%d = %d\n",b,a,c, Delta);
	printf("2. On regarde maintenant la valeur de D pour savoir le nombres de");
	printf(" solutions que possede l equation: \n");
	if(Delta>0)
		{/**************************************************************/
			printf("Le D est positif, l equation a donc deux solutions :\n");
			printf("3. Les solutions s ecrivent donc: \n");
			
			printf("			x1 = (-b + sqrt(D))/ 2*a; x2 = (-b - sqrt(D))/ 2*a \n");
			printf("Ainsi on otient: \n"); 
			solutionP(Delta,a,b,solP);
			printf("			x1 = (-%d + sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[0]);
			printf(" 			x2 = (-%d - sqrt(%d))/ 2*%d = %.2f\n",b,Delta,a,solP[1]);
			x1 = Valeur_absolu(solP[0]);
			x2 = Valeur_absolu(solP[1]);
			printf("RESULATS:\n");
			printf(" 			=> D = %d \n", Delta);
			printf("			=> x1 = %.2f \n", solP[0]);
			printf("			=> x2 = %.2f \n", solP[1]);
			printf("\n");
			printf("4. Nous pouvons maintenant trouver le polynome factorise de");
			printf(" cette equation:\n");
			printf("RAPPEL : f(x) = a * (x - x1) * (x - x2) ou x1,x2 sont les ");
			printf(" solutions de f(x) = 0 ( trouves dans 3. )\n");
			printf("\n");
			printf("Ainsi ici notre polynome factorise s'ecrit:\n");
			if(a!=1)
			{/**************************************************************/
				if(solP[0]==0.00)
				{
					if(solP[1] < 0)
					{
						printf("	f(x) = a * x * ( x + x2) car x1 = 0\n");
						printf("	Donc, f(x) = %d * x * ( x + %.2f)\n", a, x2);
					}
					else
					{
						printf("	f(x) = a * x * ( x - x2) car x1 = 0\n");
						printf("	Donc, f(x) = %d * x * ( x - %.2f)\n", a, x2);
					}
				}
				else if( solP[1]==0.00)
				{
					if(solP[0]<0)
					{
						printf("	f(x) = a* x * ( x - x1) car x2 = 0 \n");
						printf("	Donc, f(x) = %d * x * ( x - %.2f)\n",a,x1);
					}
					else
					{
						printf("	f(x) = a* x * ( x + x1) car x2 = 0 \n");
						printf("	Donc, f(x) = %d * x * ( x + %.2f)\n",a,x1);
					}
				}
				else
				{
					if(solP[0]<0 && solP[1]>0)
					{
						printf(" f(x) = %d * ( x + %.2f)\n",a,x1);
						printf(" * ( x - %.2f)\n",x2);
					}
					else if(solP[0]>0 && solP[1]<0)
					{
						printf(" f(x) = %d * ( x - %.2f)\n",a,x1);
						printf(" * ( x + %.2f)\n",x2);
					}
					else if(solP[0] > 0 && solP[1]>0)
					{
						printf(" f(x) = %d * ( x - %.2f)\n",a,x1);
						printf(" * ( x - %.2f)\n",x2);
					}
					else
					{
						printf(" f(x) = %d * ( x + %.2f)\n",a,x1);
						printf(" * ( x + %.2f)\n",x2);
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
						printf("	f(x) = x * ( x - x2) car x1 = 0 et a = 1 \n");
						printf("	Donc, f(x) = x * ( x - %.2f)\n",x2);
					}
					else
					{
						printf("	f(x) = x * ( x + x2) car x1 = 0 et a = 1 \n");
						printf("	Donc, f(x) = x * ( x + %.2f)\n",x2);
					}
				}
				else if(solP[1]==0.00)
							{
								if(solP[0]>0)
								{
									printf("	f(x) = x * ( x - x1) car x2 = 0 et a= 1 \n");
									printf("	Donc, f(x) = x * ( x - %.2f)\n",x1);
								}
								else
								{
									printf("	f(x) = x * ( x + x1) car x2 = 0 et a= 1 \n");
									printf("	Donc, f(x) = x * ( x + %.2f)\n",x1);
								}					
							}
				else
				{
						if(solP[0]<0 && solP[1]>0)
						{
							printf(" f(x) = x * ( x + %.2f)", x1);
							printf(" * ( x - %.2f) car a = 1 \n",x2);
						}
						else if(solP[0]>0 && solP[1]<0)
						{
							printf(" f(x) = x * ( x - %.2f)", x1);
							printf(" * ( x + %.2f) car a = 1 \n",x2);
						}
						else if(solP[0] > 0 && solP[1]>0)
						{
							printf(" f(x) = x * ( x - %.2f)", x1);
							printf(" * ( x - %.2f) car a = 1 \n",x2);
						}
						else
						{
							printf(" f(x) = x * ( x + %.2f)", x1);
							printf(" * ( x + %.2f) car a = 1 \n",x2);
						}
					}
					}
					/**************************************************************/
			
		}
		/**************************************************************/
		else if(Delta==0)
		{/**************************************************************/
			printf("Le D est nul, l equation a donc une solution :\n");
			printf("3. La solution s ecrit donc:\n");
			printf("			x= a / b ;\n");
			printf("Ainsi on obtient: \n");
			solution = solutionS(a,b);
			printf(" x = %d / %d = %.2f",a,b,solution);
			x = Valeur_absolu(solution);
			printf("RESULATS:\n");
			printf(" 			=> D = %d \n", Delta);
			printf("			=> x = %.2f \n", solution);
			printf("4. Nous pouvons maintenant trouver le polynome factorise de");
			printf(" cette equation:\n");
			printf("RAPPEL : f(x) = a * (x - S) * (x - S) ou S est la ");
			printf(" solution de f(x) = 0 ( trouves dans 3. )\n");
			printf("\n");
			printf("Ainsi ici notre polynome factorise s'ecrit:\n");
			if(a!=1)
			{/**************************************************************/
				if(solution <0)
				{
						printf("	Donc, f(x) = %d * ( x + %.2f) * ( x + %.2f)\n", a,x,x);
				}
				else
				{
					printf("	Donc, f(x) = %d * ( x - %.2f) * ( x - %.2f)\n", a,x,x);
				}
		}
		/**************************************************************/
		else
		{/**************************************************************/
			if(solution <0)
				{
						printf("	Donc, f(x) = ( x + %.2f) * ( x + %.2f)\n",x,x);
				}
				else
				{
					printf("	Donc, f(x) = ( x - %.2f) * ( x - %.2f)\n",x,x);
				}
	  }/**************************************************************/
	}
		/**************************************************************/
		else{/**************************************************************/
			printf("Comme le D est negatif, comme nous sommes dans l ensemble reel");
			printf(" il n a donc pas de solutions, nous sommes actuellement dans");
			printf(" l ensemble des complexes\n");}
			/**************************************************************/
		Print_canonique(a,b, Delta);
}
int main(int argc, char **argv)
{
	//Verification des parametres
	if(argc<6)
		return 0;
	//Initialisation et attribution
	int degre = atoi(argv[5]);
	int a= atoi(argv[2]);
	int b= atoi(argv[3]);
	int c= atoi(argv[4]);
	char chiffres[14]={};
	int numbers[12]={};
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
	if(degre== 2)
	{/**************************************************************/
		printf("On a :\n");
		printf("		f(x) = %s\n",argv[1]);
		Print_Second_degre(a,b,c);
	}                                           
	/**************************************************************/	
	if(degre >4)
	{
		printf("Desole ce solveur ne prends pas les equations de degre superieur");
		printf(" a 3. Merci de votre comprehension\n");
		return 0;
	}
	if(degre == 1)
	{
			printf("Pour résoudre une equation de degre 1 voici les etapes:\n");
			printf("On a :\n");
			printf("		f(x) = %s\n",argv[1]);
			
			gauche(argv[1],chiffres);
			recup_chiffres(chiffres,numbers);
			int d = droit(argv[1]);
			Print_premier_degre(a,b,d);
	}
}
