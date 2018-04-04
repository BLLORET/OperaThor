#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quatrieme_terminal.h"


void quat(float a1, float b1, float c1, float d1, float e1 ,float a2, float b2, float c2, float d2, float e2)
{
	a1-=a2;
	b1-=b2;
	c1-=c2;
	d1-=d2;
	printf("L'equation est : %fx^4 + %fx^3+%f^2 + %fx + %f = 0\n",a1,b1,c1,d1,e1);
	float A = (-3 * pow(b1,2))/8*(pow(a1,2) + c1/a1);
	float B = pow((b1/2),2)/pow(a1,3) - 0.5*b1*c1/pow(a1,2) + d1/a1;
  float C = (-3*pow((b1/4*a1),4))+ c1*(pow(b1/4,2))/pow(a1,3)-0.25*b1*d1/pow(a1,2)+e1/a1;
	printf("Grace au changement de variable : x= X-b/4a, on peut ecrire : \n");
	printf("X^4 +%fX^2+%fX+%f =0",A,B,C);
	printf("En introduisant une auxilaire de calcul u (X^2+u/2)^2, on peut poser \n");
	printf("u^3 - %fu^2-4%fu+4*%f*%f-%f^2 = 0",A,C,A,C,B);
	troisieme(1,-A, -(4*C),4*A*C-B*B);

}
