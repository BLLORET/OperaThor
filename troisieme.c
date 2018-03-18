#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Complex{
		float real;
		float img;
};
float Abs(float nb)
{
	if( nb <0)
		return -nb;
	else
		return nb;
}
void troisieme(int a, int b,int c)
{
	    struct Complex *x2 = malloc(sizeof(struct Complex));
			printf("1. Calcul des coefficients : \n\n");
			printf("Soit p = b - a²/3\n");
			printf("On remplace a et b par leur valeur, on obtient :\n");
			printf("			p = %d - %d²/3\n",b,a);
			float p = (float)b-(float)pow(a,2)/3;
			printf("Donc :   p =%f\n",p);
			if(b>0)
			{
				if(c<0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²-9*%d)-%d\n",a,a,b,abs(c));}
				else if(c>0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²-9*%d)+%d\n",a,a,b,c);}
				else{
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²-9*%d)\n",a,a,b);}
			}
			else if(b<0){
				if(c<0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²+9*%d)-%d\n",a,a,abs(b),abs(c));}
				else if(c>0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²+9*%d)+%d\n",a,a,abs(b),c);}
				else{
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²+9*%d)\n",a,a,abs(b));}
			}
			else{
				if(c<0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²)-%d\n",a,a,abs(c));}
				else if(c>0){
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²)+%d\n",a,a,c);}
				else{
					printf("Soit q = a/27*(2a²-9*b)-c\n");
					printf("On remplace a,b,c par leur valeur, on otient : \n");
					printf("			q = %d/27*(2*%d²)\n",a,a);}
			}
			float q = (float)(((float)a/27)*(float)((2*pow(a,2)-9*b))+c);
			printf("Donc : 	 q = %.2f\n\n",q);
			printf("2. Calcul de l'expression sous la racine carrée\n\n");
			printf("C'est-à-dire : Rc = (q/2)² + (p/3)³\n");
			printf("On remplace q et p par leur valeur, on obtient :\n");
			if(q == 0 && p !=0)
				printf("		Rc = (%.2f/3)³\n",p);
			else if(p == 0 && q!=0)
				printf("		Rc = (%.2f/2)² \n",q);
			else
				printf("		Rc = (%.2f/2)² + (%.2f/3)³\n",q,p);
			float Q = q/2;
			float P= p/3;
			float Rc = sqrt(powf(Q,2)+ powf(P,3));
			printf("Donc : Rc =%.2f\n\n",Rc);
			printf("3. Calcul de u et v : \n");
			printf("\n");
			printf("			Soit u³= -q/2 + Rc\n");
			printf("			Donc u = sqrt3(u³)\n");
			float u3 = -q/2 +Rc;
			float u = cbrt(u3);
			printf("On remplace q et Rc par leur valeur, on obtient : \n");
			if(q ==0){
				if(Rc == 0)
					printf("		u³ = -%.2f/2 + %.2f\n",q,Rc);
				else if(Rc <0)
					printf("		u³ = -%.2f\n",Abs(Rc));
				else
					printf("		u³ = %.2f\n",Rc);
			}
			else if( q > 0){
				if(Rc == 0)
					printf("		u³ = -%.2f/2 + %.2f\n",q,Rc);
				else if(Rc <0)
					printf("		u³ = -%.2f/2 - %.2f\n",q,Abs(Rc));
				else
					printf("		u³ = -%.2f/2 +%.2f\n",q,Rc);
			}
			else{
				if(Rc == 0)
					printf("		u³ = %.2f/2 + %.2f\n",Abs(q),Rc);
				else if(Rc <0)
					printf("		u³ = %.2f/2 - %.2f\n",Abs(q),Abs(Rc));
				else
					printf("		u³ = %.2f/2 +%.2f\n",Abs(q),Rc);
			}
			printf("Donc,	  u³ = %.2f\n",u3);
			printf("RAPPEL : cbrt() = racine cubique\n");
			printf("Ainsi u = cbrt(u³) = cbrt(%.2f) = %.2f\n\n",u3,u);
		  printf("				Soit v³ = -q/2 - Rc\n");
			printf("				Donc v = cbrt(v³)\n");
			float v3 =-q/2 -Rc;
			float v = cbrt(v3);
			printf("Comme pour u on remplace q et Rc, on obtient : \n");
			if(q ==0){
				if(Rc == 0)
					printf("		v³ = -%.2f/2 - %.2f\n",q,Rc);
				else if(Rc <0)
					printf("		v³ = %.2f\n",Abs(Rc));
				else
					printf("		v³ = -%.2f\n",Rc);
			}
			else if( q > 0){
				if(Rc == 0)
					printf("		v³ = -%.2f/2 - %.2f\n",q,Rc);
				else if(Rc <0)
					printf("		v³ = -%.2f/2 + %.2f\n",q,Abs(Rc));
				else
					printf("		v³ = -%.2f/2 - %.2f\n",q,Rc);
			}
			else{
				if(Rc == 0)
					printf("		v³ = %.2f/2 - %.2f\n",Abs(q),Rc);
				else if(Rc <0)
					printf("		v³ = %.2f/2 + %.2f\n",Abs(q),Abs(Rc));
				else
					printf("		v³ = %.2f/2 - %.2f\n",Abs(q),Rc);
			}
			printf("Donc,   v³ = %.2f\n",v3);
			printf("Ainsi v = cbrt(v³)= cbrt(%.2f) = %.2f\n\n",v3,v);
			printf("4.  Calcul des racines\n\n");
			printf("				Soit x1 = u + v - 1/3\n");
	    printf("On remplace u et v par leur valeur, on obtient : \n");
			if(u == 0){
				if(v == 0)
					printf("		x1 = %.2f + %.2f - 1/3\n",u,v);
				else if(v < 0)
					printf("		x1 = - %.2f - 1/3\n",Abs(v));
				else
					printf("		x1 = %.2f - 1/3\n",v);
			}
			else if(u <0){
				if(v == 0)
					printf("		x1 = %.2f - 1/3\n",u);
				else if(v < 0)
					printf("		x1 = %.2f - %.2f - 1/3\n",u,Abs(v));
				else
					printf("		x1 = %.2f + %.2f - 1/3\n",u,v);
			}
			else{
				if(v == 0)
					printf("		x1 = %.2f - 1/3\n",u);
				else if(v < 0)
					printf("		x1 = %.2f - %.2f - 1/3\n",u,Abs(v));
				else
					printf("		x1 = %.2f + %.2f - 1/3\n",u,v);
			}
			float x1 =u+v-((float)1/(float)3);
			printf("Donc,	x1 = %.2f\n\n",x1);
			printf("				Soit x2 = (-u/2 - v/2 -1/3) + 1/2*i*sqrt(3)*(u-v))\n");
		  printf("On remplace u et v par leur valeur, on obtient : \n");
		  if(u == 0)
			{
				if(v==0)
				{
				printf("	 x2 = (-%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,u,v,u,v);}
				else if(v <0){
					printf("		x2 = (%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f\n",
						Abs(v),Abs(v));}
				else{
						printf("	 x2 = (-%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f\n",v,v);}
			}
			else if(u < 0)
			{
				if(v==0){
					printf("	 x2 = (%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*(%.2f))\n",Abs(u),u);
					}
				else if(v <0)
				{
					printf("	 x2 = (%.2f/2 + %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f+%.2f))\n"
			,Abs(u),Abs(v),u,Abs(v));
				}
				else
				{
					printf("	 x2 = (%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,Abs(u),v,u,v);
				}
			}
			else
			{
				if(v==0)
				{
					printf("	 x2 = (-%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f)\n",u,u);
				}
				else if( v <0)
				{
					printf("	 x2 = (-%.2f/2 + %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f+%.2f))\n"
			,u,Abs(v),u,Abs(v));
				}
				else
				{
					printf("	 x2 = (-%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,u,v,u,v);
				}
			}
      x2->real =(-u/2 -v/2 -((float)1/(float)3));
      x2->img = (((float)1/(float)2)*sqrt(3)*(u-v));
      if( x2 ->real == 0)
      {
				if(x2->img == 0)
				 printf("Donc,	x2 = %.2f + i%.2f = 0 \n",x2->real,x2->img);
				else if( x2->img < 0)
					printf("Donc,	x2 = -i%.2f\n",Abs(x2->img));
				else
				  printf("Donc,	x2 = i%.2f\n",x2->img);
			}
			else 
			{
				if(x2->img ==0)
					printf("Donc,	x2 = %.2f \n",x2->real);
				else if (x2->img <0)
					printf("Donc,	x2 = %.2f - i%.2f\n",x2->real,Abs(x2->img));
				else
					printf("Donc,	x2 = %.2f + i%.2f\n",x2->real,x2->img);
			}
			printf("Soit x3 le conjugué de x2\n");
			printf("RAPPEL : x2 = a + ib, son conjugué x3 = a - ib\n");
			if( x2 ->real == 0)
      {
				if(x2->img == 0)
				 printf("Donc,	x3 = %.2f - i%.2f = 0 \n",x2->real,x2->img);
				else if( x2->img < 0)
					printf("Donc,	x3 = i%.2f\n",Abs(x2->img));
				else
				  printf("Donc,	x3 = -i%.2f\n",x2->img);
			}
			else 
			{
				if(x2->img ==0)
					printf("Donc,	x3 = %.2f \n",x2->real);
				else if (x2->img <0)
					printf("Donc,	x3 = %.2f + i%.2f\n",x2->real,Abs(x2->img));
				else
					printf("Donc,	x3 = %.2f - i%.2f\n",x2->real,x2->img);
			}
			free(x2);
}
/*void  troisieme(int a, int b, int c)
{
			 struct Complex *x2 = malloc(sizeof(struct Complex));
			//struct complex x3 = malloc(sizeof(*x3));
			printf("1. Calcul des coefficients : \n");
			printf("Soit p = b - a^2/3\n");
			printf("On remplace a et b par leur valeur, on obtient :\n");
			if(a>0)
				printf("			p = %d - %d^2/3\n",b,a);
			else if(a<0)
				printf("			p = %d + %d^2/3\n",b,a);
			else
				printf("			p = %d\n",b);
			float p = (float)b-(float)pow(a,2)/3;
			printf("Donc :   p =%f\n",p);
			printf("Soit q = a/27*(2a^2-9*b)+c\n");
			printf("On remplace a,b,c par leur valeur, on otient : \n");
			printf("			q = %d/27*(2*%d^2-9*%d)+%d\n",a,a,b,c);
			float q = (float)(((float)a/27)*(float)((2*pow(a,2)-9*b))+c);
			printf("Donc : 	 q = %.2f\n",q);
			printf("2. Calcul de l'expression sous la racine carree\n");
			printf("C'est-a-dire : Rc = (q/2)^2 + (p/3)^3\n");
			printf("On remplace q et p par leur valeur, on obtient :\n");
			printf("		Rc = (%.2f/2)^2 + (%.2f/3)^3\n",q,p);
			float Q = q/2;
			float P= p/3;
      float Rc = sqrt(powf(Q,2)+ powf(P,3));
			printf("Donc : Rc =%.2f\n",Rc);
			printf("3. Calcul de u et v : \n");
			printf("Soit u^3 = -q/2 + Rc\n");
			printf("Donc u = sqrt3(u^3)\n");
			float u3 = -q/2 +Rc;
			float u = cbrt(u3);
			printf("On remplace q et Rc par leur valeur, on obtient : \n");
			printf("		u3 = -%.2f/2 + %.2f\n",q,Rc);
			printf("	Donc, u3 = %.2f\n",u3);
			printf("Ainsi u = sqrt3(%.2f) = %.2f\n",u3,u);
		  printf("Soit v3 = -q/2 - Rc\n");
			printf("Donc v = sqrt3(|v3|)\n");
			float v3 =-q/2 -Rc;
			float v = cbrt(v3);
			printf("Comme pour u on remplace q et Rc, on obtient : \n");
			printf("		v3 = -%.2f/2 - %.2f\n",q,Rc);
			printf("Donc, v3 = %.2f\n",v3);
			printf("Ainsi v = sqrt3(v3) = %.2f\n",v);
			printf("4.  Calcul des racines\n");
			printf("Soit x1 = u+v - 1/3\n");
	    printf("On remplace u et v par leur valeur, on obtient : \n");
			printf("		x1 = %.2f + %.2f -1/3\n",u,v);
			float x1 =u+v-((float)1/(float)3);
			printf("Donc,	x1 = %.2f\n",x1);
			printf("Soit x2 = (-u/2 - v/2 -1/3)+ 1/2*i*sqrt(3)*(u-v))\n");
		  printf("On remplace u et v par leur valeur, on obtient : \n");
			printf("Soit x2 = (-%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,u,v,u,v);
      x2->real =(-u/2 -v/2 -((float)1/(float)3));
      x2->img = (((float)1/(float)2)*sqrt(3)*(u-v));
      printf("Donc,	x2 = %.2f + i%.2f\n",x2->real,x2->img);
			printf("Soit x3 = -x2\n");
			printf("Donc, x3 = %.2f - i%.2f\n",x2->real,x2->img);
			free(x2);

}

int main(void)
{
	int a=1,b=-1,c=2;
	troisieme(a,b,c);
}*/
