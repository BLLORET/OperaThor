
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int delta(int a, int b, int c)
{
	return ((b*b) - (4*a*c));
}
/*int imaginaire(int n)
{
	if (n%4 == 0)
		return 1;
	else if(n%4==1)
		return 2;
	else if(n%4 ==2)
		return -1;
	else
		return 3;
}

char* Imaginaire(int i,char* letter)
{
	if(i ==2)
	{letter[0]='i';}
	else {if(i ==3)
		{
			letter[0]='-';
			letter[1]='i';
		}}
	return letter;
}*/
int int_sqrt(int n) 
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
float* solutionP(int delta,int a, int b,float* solutions)
{
	double nb= delta;

	float x1= (-b + int_sqrt(nb))/ (2*a);
	float x2 =( -b - int_sqrt(nb))/(2*a);
	solutions[0]=x1;
	solutions[1]=x2;
	return solutions;
}
int solutionS(int b, int a)
{
	int x= -b/(2*a);
	return x;
}
/*char* solutionN(int nb, int a, int b, char* solutions)
{
	double bis= nb;
	int x1 = -b/(2*a);
	int x1b = sqrt(-bis)/(2*a);
	char prems= x1;
	char deuz =x1b;
	solutions[0]= prems;
	solutions[1]= '-';
	solutions[2]='i';
	solutions[3]=deuz;
	solutions[4]=';';
	solutions[5]= prems;
	solutions[6]= '+';
	solutions[7]='i';
	return solutions;
	
	
}*/

int main(int argc, char **argv)
{
	//Verification des parametres
	if(argc<6)
		return 0;
	//Initialisation et attribution
	float solP[2]={};
	int solution;
	int a= atoi(argv[2]);
	int b= atoi(argv[3]);
	int c= atoi(argv[4]);
	//Calcul du Delta
	int Delta= delta(a,b,c);
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
	printf("C est une equation de degre: %d \n",atoi(argv[5]));
	printf("\n");
	if(atoi(argv[5])== 2)
	{
		printf("Pour résoudre une equation de degre 2 voici les etapes:\n");
		printf("1. On calcul le Delta (note D) :\n");
		printf("			D = b² - 4 * a * c \n");
		printf("			avec a = %d, b = %d, c = %d \n",a,b,c);
		printf("Ce qui donne :\n");
		printf("			D = %d² - 4*%d*%d = %d\n",b,a,c, Delta);
		printf("2. On regarde maintenant la valeur de D pour savoir le nombres de");
		printf(" solutions que possede l equation: \n");                                           
		if(Delta>0){
			printf("Le D est positif, l equation a donc deux solutions :\n");
			printf("3. Les solutions s ecrivent donc: \n");
			
			printf("			x1 = (-b + sqrt(D))/ 2*a; x2 = (-b - sqrt(D))/ 2*a \n");
			printf("Ainsi on otient: \n"); 
			solutionP(Delta,a,b,solP);
			printf("			x1 = (-%d + sqrt(%d))/ 2*%d = %f\n",b,Delta,a,solP[0]);
			printf(" 			x2 = (-%d - sqrt(%d))/ 2*%d = %f\n",b,Delta,a,solP[1]);}
		else if(Delta==0){
			printf("Le D est nul, l equation a donc une solution :\n");
			printf("3. La solution s ecrit donc:\n");
			printf("			x= a / b ;\n");
			printf("Ainsi on obtient: \n");
			solution = solutionS(a,b);
			printf(" x = %d / %d = %d",a,b,solution);}
		else{
			printf("Comme le D est negatif, comme nous sommes dans l ensemble reel");
			printf(" il n a donc pas de solutions, nous sommes actuellement dans");
			printf(" l ensemble des complexes\n");}
	}
	
	
}
