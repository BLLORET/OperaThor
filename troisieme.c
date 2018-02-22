#include "troisieme.h"
#include "fonction.h"
void poly(double a1,double b1, double c1, double d1, double a2, double b2,
 double c2, double d2)
{
	a1 -= a2;
	b1 -= b2;
	c1 -= c2;
	d1 -= d2;
	
	printf("Voici votre equation remise à 0 : %lfX^3+%lfX²+%lfX+%lf = 0 \n", a1,
	b1,c1,d1);
	printf("Grâce au changement de variable, x = t - b/3a \n, nous trouvons :");
	
	double p = (3*a1*c1 - pow(b1,2)) / 3*pow(a1,2);
	double q = (2*pow(b1,3)-9*a1*b1*c1+27*pow(a1,2)*d1)/27*pow(a1,3);
	printf("p = %lf, q = %lf \n", p,q);
	
	double delta1 = pow(q,2)+((4*pow(p,3))/27);
	printf("Delta1 = q²+4p^3/27 = %lf \n", delta1);
	
	double x11 = ((q * -1) - pow(delta1,1/2)) /2;
	x11 = pow(x11,1/3);
	double x12 =((q * -1) + pow(delta1,1/2)) /2;
	x12 = pow(x12,1/3);
	double x1 = x11 + x12 - (b1/3*a1);
	printf("x1 = %lf", x1); 
	
	double b3 = b1 + a1*x1;
	double c3 = c1 + (b1+(a1*x1)*x1);
	
	printf("Voici l equation reecrite : (X-%lf)(%lfX² + %lf) =0",x1,a1,b3,c3);
	
	//résoudre l'équation du second degré avec a1,b3,c3 :)
	Print_Second_degre(a1,b3,c3);  
}

/*int main()
{
		poly(1,-6,11,-6,0,0,0,0);
		return 0;
}*/
