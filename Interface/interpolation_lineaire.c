#include "interpole.h"


static float ABS(float a)
{
	if(a < 0)
		return -a;
	else
		return a;

}
void interpole_lineaire(FILE *file,int x[],int fx[])
{
	fprintf(file,"1. PREMIERE METHODE :\n\n");
	fprintf(file,"RAPPEL : \n ");
	fprintf(file,"Dans le cas d'une interpolation linéaire, on constitue une courbe d'interpolation qui est une succession de segments. Entre deux points p1 et p2 de coordonnées respectives (x1 , y1) et (x2 , y2),\n l'interpolation est donnée par la formule suivante\n");
	fprintf(file,"				y = p * (x - x1) + y1 ,  c'est une formule de Taylor-Young de premier ordre\n");
	fprintf(file, "avec p la pente donnée par cette formule: \n");
	fprintf(file,"				p = (y2 - y1) / (x2 -x1) \n\n");
	float p = ((float)fx[1]-(float)fx[0])/((float)x[1]-(float)x[0]);
	if(p == 0)
	{
			fprintf(file,"y = %d\n",fx[0]);
	}
	else if(x[0]==0)
			fprintf(file,"y = %.2f * x + %d\n",p,fx[0]);
	else if(x[0] > 0 && fx[0]>0)
			fprintf(file,"y = %.2f * (x - %d) + %d\n",p,x[0],fx[0]);
	else if(x[0] <0 && fx[0] <0)
			fprintf(file,"y = %.2f * (x + %d) - %d\n",p,abs(x[0]),abs(fx[0]));
	else if(x[0]>0 && fx[0]<0)
			fprintf(file,"y = %.2f * (x - %d) - %d\n",p,x[0],abs(fx[0]));
	else
			fprintf(file,"y = %.2f * (x + %d) + %d\n\n",p,abs(x[0]),fx[0]);
	fprintf(file,"2. SECONDE METHODE : \n\n");
	fprintf(file,"RAPPEL :\n On peut aussi approcher la fonction qui passe par ces points avec une fonction affine qui se calcule ainsi :\n");
	fprintf(file," soit g la fonction affine :  g(x) = ((y1 - y2) / (x1 - x2)) * x + ((x1 * y2) - (x2 * y1)) / (x1 - x2)\n\n");
	fprintf(file,"Ce qui donne avec nos points : \n x : %d , %d et f(x) : %d , %d \n",x[0],x[1],fx[0],fx[1]);
	float p_terme= ((float)fx[0]-(float)fx[1])/((float)x[0] - (float)x[1]);
	int numerateur = (x[0]*fx[1]) - (x[1]*fx[0]);
	int denominateur = x[0] - x[1];
	float d_terme = (float)numerateur / (float)denominateur;
	if(fx[1] <0 && x[1] <0)
		fprintf(file,"							g(x) = ((%d + %d) / (%d + %d)) * x + ((%d * %d) - (%d * %d)) / (%d + %d)\n",fx[0],abs(fx[1]),x[0],abs(x[1]),x[0],fx[1],x[1],fx[0],x[0],abs(x[1]));
	else if(fx[1] > 0 && x[1] < 0)
		fprintf(file,"							g(x) = ((%d - %d) / (%d + %d)) * x + ((%d * %d) - (%d * %d)) / (%d + %d)\n",fx[0],fx[1],x[0],abs(x[1]),x[0],fx[1],x[1],fx[0],x[0],abs(x[1]));
	else if(fx[1] < 0 && x[0] > 0)
		fprintf(file,"							g(x) = ((%d + %d) / (%d - %d)) * x + ((%d * %d) - (%d * %d)) / (%d - %d)\n",fx[0],abs(fx[1]),x[0],x[1],x[0],fx[1],x[1],fx[0],x[0],x[1]);
	else
		fprintf(file,"							g(x) = ((%d - %d) / (%d - %d)) * x + ((%d * %d) - (%d * %d)) / (%d - %d)\n",fx[0],fx[1],x[0],x[1],x[0],fx[1],x[1],fx[0],x[0],x[1]);		
	if(p_terme == 0)
	{
		if(d_terme == 0)
				fprintf(file,"							g(x) = 0 \n");
		else
			if (x[1] < 0)
				fprintf(file,"							g(x) = ((%d * %d) - (%d * %d)) / (%d + %d) = %.2f",x[0],fx[1],x[1],fx[0],x[0],abs(x[1]),d_terme);
			else
				fprintf(file,"							g(x) = ((%d * %d) - (%d * %d)) / (%d - %d) = %.2f",x[0],fx[1],x[1],fx[0],x[0],x[1],d_terme);
	}			
	else
	{
		if(d_terme == 0){
			if(fx[1] <0 && x[1] <0)
				fprintf(file,"							g(x) = ((%d + %d) / (%d + %d)) * x = %.2fx , car ((%d * %d) - (%d * %d)) / (%d + %d) = 0  \n",fx[0],abs(fx[1]),x[0],abs(x[1]),p_terme,x[0],fx[1],x[1],fx[0],x[0],abs(x[1]));
			else if(fx[1] > 0 && x[1] < 0)
				fprintf(file,"							g(x) = ((%d - %d) / (%d + %d)) * x = %.2fx , car ((%d * %d) - (%d * %d)) / (%d + %d) = 0  \n",fx[0],fx[1],x[0],abs(x[1]),p_terme,x[0],fx[1],x[1],fx[0],x[0],abs(x[1]));
			else if(fx[1] < 0 && x[0] > 0)
				fprintf(file,"							g(x) = ((%d + %d) / (%d - %d)) * x = %.2fx , car ((%d * %d) - (%d * %d)) / (%d - %d) = 0  \n",fx[0],abs(fx[1]),x[0],x[1],p_terme,x[0],fx[1],x[1],fx[0],x[0],x[1]);
			else
				fprintf(file,"							g(x) = ((%d - %d) / (%d - %d)) * x = %.2fx , car ((%d * %d) - (%d * %d)) / (%d - %d) = 0  \n",fx[0],fx[1],x[0],x[1],p_terme,x[0],fx[1],x[1],fx[0],x[0],x[1]);
		}
		else if(d_terme > 0) 
			fprintf(file,"							g(x) = %.2fx + %.2f \n",p_terme,d_terme);
		else
			fprintf(file,"							g(x) = %.2fx - %.2f \n\n",p_terme,ABS(d_terme));
	}
	fprintf(file,"3. TROISIEME METHODE :\n\n");
	fprintf(file,"RAPPEL :\n On peut aussi écrire cette fonction affine en une autre formule que voici :\n" );
	fprintf(file,"									h(x) = ((x2 - x)/(x2 - x1))*y1 + ((x - x1)/(x2 - x1))*y2 \n"); 
	fprintf(file,"Ce qui donne pour nos points : \n");
	float Den1 = ((float)1 /((float)x[1] -(float)x[0]))*(float)fx[0];
	float Den2 = ((float)1 /((float)x[1] -(float)x[0]))*(float)fx[1];
	if(x[0] < 0){
		fprintf(file,"									h(x) = ((%d - x)/(%d + %d))*%d + ((x + %d)/(%d + %d))*%d\n",x[1],x[1],abs(x[0]),fx[0],abs(x[0]),x[1],abs(x[0]),fx[1]);
		if(Den2 < 0)
			fprintf(file,"Ainsi:  	h(x) = %.2f(%d - x) - %.2f(x + %d)\n",Den1,x[1],ABS(Den2),abs(x[0]));
		else
			fprintf(file,"Ainsi:  	h(x) = %.2f(%d - x) + %.2f(x + %d)\n",Den1,x[1],Den2,abs(x[0]));
	}
	else{
		fprintf(file,"									h(x) = ((%d - x)/(%d - %d))*%d + ((x - %d)/(%d - %d))*%d\n",x[1],x[1],x[0],fx[0],x[0],x[1],x[0],fx[1]);
		if(Den2 < 0)
			fprintf(file,"Ainsi:  	h(x) = %.2f(%d - x) - %.2f(x - %d)\n",Den1,x[1],ABS(Den2),x[0]);
		else
			fprintf(file,"Ainsi:  	h(x) = %.2f(%d - x) + %.2f(x - %d)\n",Den1,x[1],Den2,x[0]);
	}
	
	
}
