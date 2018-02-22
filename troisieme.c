#include "troisieme.h"
#include "fonction.h"

void poly(double a1,double b1, double c1, double d1, double a2, double b2,
 double c2, double d2)
{
	a1 -= a2;
	b1 -= b2;
	c1 -= c2;
	d1 -= d2;
	
	printf("Voici votre equation remise à 0 : \n");
	printf("		%.2lfX^3+%.2lfX²+%.2lfX+%.2lf = 0 \n", a1,b1,c1,d1);
	printf("Grâce au changement de variable, x = t - b/3a, nous trouvons :\n");
	
	double p = c1/a1 - pow(b1,2) / 3*pow(a1,2);
	double q = (2*pow(b1,3))/(27*pow(a1,3))+d1/a1-(b1*c1)/(3*pow(a1,2));
	printf("p = %.2lf, q = %.2lf \n", p,q);
	
	double delta1 = pow(q,2)/4+pow(p,3)/27;
	printf("Delta1 = q²+4p^3/27 = %.2lf \n", delta1);
	
	double x11 =(q*-1 - pow(delta1,1/2)) /2;
	x11 = pow(x11,1/3);
	double x12 =((q * -1) + pow(delta1,1/2)) /2;
	x12 = pow(x12,1/3);
	double x1 = (x11 + x12  /*-(b1/3*a1)*/)*(-1);
	printf("x1 = %.2lf\n", x1); 
	
	double b3 = b1 + a1*x1;
	double c3 = c1 + (b1+(a1*x1)*x1);
	
	printf("Voici l equation reecrite :\n");
	printf(" 		(X-%.2lf)(%.2lfX² + %.2lfX + %.2lf) =0\n",x1,a1,b3,c3);
	
	//résoudre l'équation du second degré avec a1,b3,c3 :)
	Print_Second_degre(a1,b3,c3);  
}

/*int main()
{
		poly(1,-6,11,-6,0,0,0,0);
		return 0;
}*/
