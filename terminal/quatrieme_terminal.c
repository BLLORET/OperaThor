#include "quatrieme_terminal.h"

void quat(float a1, float b1, float c1, float d1, float e1 ,float a2, float b2, float c2, float d2, float e2)
{
	a1-=a2;
	b1-=b2;
	c1-=c2;
	d1-=d2;
	e1-=e2;
	print_poly4(a1,b1,c1,d1,e1,'x');
	float A = (-3 * pow(b1,2))/8*(pow(a1,2) + c1/a1);
	float B = pow((b1/2),2)/pow(a1,3) - 0.5*b1*c1/pow(a1,2) + d1/a1;
  float C = (-3*pow((b1/4*a1),4))+ c1*(pow(b1/4,2))/pow(a1,3)-0.25*b1*d1/pow(a1,2)+e1/a1;
	printf("Grace au changement de variable : x= X-b/4a, on peut ecrire : \n");
	print_poly4(1.,0.,A,B,C,'X');
	//printf("X^4 +%fX^2+%fX+%f =0",A,B,C);
	printf("En introduisant une auxilaire de calcul u (X^2+u/2)^2, on peut poser \n");
	print_poly4(0,1,-A,-(4*C),4*A*C-B*B,'u');
	//printf("u^3 - %fu^2-4%fu+4*%f*%f-%f^2 = 0",A,C,A,C,B);
	troisieme((int)-A, (int)-(4*C),(int)(4*A*C-B*B));

}

void print_poly4(float a,float b,float c,float d, float e, char var)
{
		print_min_pl(a,4,var);
	print_min_pl(b,3,var);
	print_min_pl(c,2,var);
	print_min_pl(d,1,var);
	print_min_pl(e,0,var);
}

void print_min_pl(float a, int deg, char var)
{
	if(a !=0)
		{
			if(a>0)
				printf("+%.2f",a);
			else
				printf("%.2f",a);
		
			if(deg == 0)
				printf(" = 0 \n");
			if(deg == 1)
				printf("%c",var);
			else
				printf("%c^%d",var,deg);
		}
}

void main()
{
	quat(-1,0,4,-2,3,0,0,0,0,0);
	//troisieme(1,2,3);
}
