#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "troisieme_interface.h"
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
void Print_degre_trois(FILE *file,int a, int b,int c,char* argv,int degre)
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
  fprintf(file,"On cherche à résoudre l'équation suivante: %s \n",argv);
  fprintf(file,"C'est une équation de degré: %d \n",degre);

		fprintf(file,"Pour résoudre une équation de degré 3 voici les étapes:\n");
		fprintf(file,"On a :\n");
		fprintf(file,"		f(x) = %s\n",argv);
	    struct Complex *x2 = malloc(sizeof(struct Complex));
			fprintf(file,"1. Calcul des coefficients : \n\n");
			fprintf(file,"Soit p = b - a²/3\n");
			fprintf(file,"On remplace a et b par leur valeur, on obtient :\n");
			fprintf(file,"			p = %d - %d²/3\n",b,a);
			float p = (float)b-(float)pow(a,2)/3;
			fprintf(file,"Donc :   p =%f\n",p);
			if(b>0)
			{
				if(c<0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²-9*%d)-%d\n",a,a,b,abs(c));}
				else if(c>0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²-9*%d)+%d\n",a,a,b,c);}
				else{
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²-9*%d)\n",a,a,b);}
			}
			else if(b<0){
				if(c<0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²+9*%d)-%d\n",a,a,abs(b),abs(c));}
				else if(c>0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²+9*%d)+%d\n",a,a,abs(b),c);}
				else{
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²+9*%d)\n",a,a,abs(b));}
			}
			else{
				if(c<0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²)-%d\n",a,a,abs(c));}
				else if(c>0){
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²)+%d\n",a,a,c);}
				else{
					fprintf(file,"Soit q = a/27*(2a²-9*b)-c\n");
					fprintf(file,"On remplace a,b,c par leur valeur, on otient : \n");
					fprintf(file,"			q = %d/27*(2*%d²)\n",a,a);}
			}
			float q = (float)(((float)a/27)*(float)((2*pow(a,2)-9*b))+c);
			fprintf(file,"Donc : 	 q = %.2f\n\n",q);
			fprintf(file,"2. Calcul de l'expression sous la racine carrée\n\n");
			fprintf(file,"C'est-à-dire : Rc = (q/2)² + (p/3)³\n");
			fprintf(file,"On remplace q et p par leur valeur, on obtient :\n");
			if(q == 0 && p !=0)
				fprintf(file,"		Rc = (%.2f/3)³\n",p);
			else if(p == 0 && q!=0)
				fprintf(file,"		Rc = (%.2f/2)² \n",q);
			else
				fprintf(file,"		Rc = (%.2f/2)² + (%.2f/3)³\n",q,p);
			float Q = q/2;
			float P= p/3;
			float Rc = sqrt(powf(Q,2)+ powf(P,3));
			fprintf(file,"Donc : Rc =%.2f\n\n",Rc);
			fprintf(file,"3. Calcul de u et v : \n");
			fprintf(file,"\n");
			fprintf(file,"			Soit u³= -q/2 + Rc\n");
			fprintf(file,"			Donc u = sqrt3(u³)\n");
			float u3 = -q/2 +Rc;
			float u = cbrt(u3);
			fprintf(file,"On remplace q et Rc par leur valeur, on obtient : \n");
			if(q ==0){
				if(Rc == 0)
					fprintf(file,"		u³ = -%.2f/2 + %.2f\n",q,Rc);
				else if(Rc <0)
					fprintf(file,"		u³ = -%.2f\n",Abs(Rc));
				else
					fprintf(file,"		u³ = %.2f\n",Rc);
			}
			else if( q > 0){
				if(Rc == 0)
					fprintf(file,"		u³ = -%.2f/2 + %.2f\n",q,Rc);
				else if(Rc <0)
					fprintf(file,"		u³ = -%.2f/2 - %.2f\n",q,Abs(Rc));
				else
					fprintf(file,"		u³ = -%.2f/2 +%.2f\n",q,Rc);
			}
			else{
				if(Rc == 0)
					fprintf(file,"		u³ = %.2f/2 + %.2f\n",Abs(q),Rc);
				else if(Rc <0)
					fprintf(file,"		u³ = %.2f/2 - %.2f\n",Abs(q),Abs(Rc));
				else
					fprintf(file,"		u³ = %.2f/2 +%.2f\n",Abs(q),Rc);
			}
			fprintf(file,"Donc,	  u³ = %.2f\n",u3);
			fprintf(file,"RAPPEL : cbrt() = racine cubique\n");
			fprintf(file,"Ainsi u = cbrt(u³) = cbrt(%.2f) = %.2f\n\n",u3,u);
		  	fprintf(file,"				Soit v³ = -q/2 - Rc\n");
			fprintf(file,"				Donc v = cbrt(v³)\n");
			float v3 =-q/2 -Rc;
			float v = cbrt(v3);
			fprintf(file,"Comme pour u on remplace q et Rc, on obtient : \n");
			if(q ==0){
				if(Rc == 0)
					fprintf(file,"		v³ = -%.2f/2 - %.2f\n",q,Rc);
				else if(Rc <0)
					fprintf(file,"		v³ = %.2f\n",Abs(Rc));
				else
					fprintf(file,"		v³ = -%.2f\n",Rc);
			}
			else if( q > 0){
				if(Rc == 0)
					fprintf(file,"		v³ = -%.2f/2 - %.2f\n",q,Rc);
				else if(Rc <0)
					fprintf(file,"		v³ = -%.2f/2 + %.2f\n",q,Abs(Rc));
				else
					fprintf(file,"		v³ = -%.2f/2 - %.2f\n",q,Rc);
			}
			else{
				if(Rc == 0)
					fprintf(file,"		v³ = %.2f/2 - %.2f\n",Abs(q),Rc);
				else if(Rc <0)
					fprintf(file,"		v³ = %.2f/2 + %.2f\n",Abs(q),Abs(Rc));
				else
					fprintf(file,"		v³ = %.2f/2 - %.2f\n",Abs(q),Rc);
			}
			fprintf(file,"Donc,   v³ = %.2f\n",v3);
			fprintf(file,"Ainsi v = cbrt(v³)= cbrt(%.2f) = %.2f\n\n",v3,v);
			fprintf(file,"4.  Calcul des racines\n\n");
			fprintf(file,"				Soit x1 = u + v - 1/3\n");
	    		fprintf(file,"On remplace u et v par leur valeur, on obtient : \n");
			if(u == 0){
				if(v == 0)
					fprintf(file,"		x1 = %.2f + %.2f - 1/3\n",u,v);
				else if(v < 0)
					fprintf(file,"		x1 = - %.2f - 1/3\n",Abs(v));
				else
					fprintf(file,"		x1 = %.2f - 1/3\n",v);
			}
			else if(u <0){
				if(v == 0)
					fprintf(file,"		x1 = %.2f - 1/3\n",u);
				else if(v < 0)
					fprintf(file,"		x1 = %.2f - %.2f - 1/3\n",u,Abs(v));
				else
					fprintf(file,"		x1 = %.2f + %.2f - 1/3\n",u,v);
			}
			else{
				if(v == 0)
					fprintf(file,"		x1 = %.2f - 1/3\n",u);
				else if(v < 0)
					fprintf(file,"		x1 = %.2f - %.2f - 1/3\n",u,Abs(v));
				else
					fprintf(file,"		x1 = %.2f + %.2f - 1/3\n",u,v);
			}
			float x1 =u+v-((float)1/(float)3);
			fprintf(file,"Donc,	x1 = %.2f\n\n",x1);
			fprintf(file,"				Soit x2 = (-u/2 - v/2 -1/3) + 1/2*i*sqrt(3)*(u-v))\n");
		  	fprintf(file,"On remplace u et v par leur valeur, on obtient : \n");
		  if(u == 0)
			{
				if(v==0)
				{
				fprintf(file,"	 x2 = (-%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,u,v,u,v);}
				else if(v <0){
					fprintf(file,"		x2 = (%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f\n",
						Abs(v),Abs(v));}
				else{
						fprintf(file,"	 x2 = (-%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f\n",v,v);}
			}
			else if(u < 0)
			{
				if(v==0){
					fprintf(file,"	 x2 = (%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*(%.2f))\n",Abs(u),u);
					}
				else if(v <0)
				{
					fprintf(file,"	 x2 = (%.2f/2 + %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f+%.2f))\n"
			,Abs(u),Abs(v),u,Abs(v));
				}
				else
				{
					fprintf(file,"	 x2 = (%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,Abs(u),v,u,v);
				}
			}
			else
			{
				if(v==0)
				{
					fprintf(file,"	 x2 = (-%.2f/2 - 1/3)+ 1/2*i*sqrt(3)*%.2f)\n",u,u);
				}
				else if( v <0)
				{
					fprintf(file,"	 x2 = (-%.2f/2 + %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f+%.2f))\n"
			,u,Abs(v),u,Abs(v));
				}
				else
				{
					fprintf(file,"	 x2 = (-%.2f/2 - %.2f/2 -1/3)+ 1/2*i*sqrt(3)*(%.2f-%.2f))\n"
			,u,v,u,v);
				}
			}
      x2->real =(-u/2 -v/2 -((float)1/(float)3));
      x2->img = (((float)1/(float)2)*sqrt(3)*(u-v));
      if( x2 ->real == 0)
      {
				if(x2->img == 0)
				 fprintf(file,"Donc,	x2 = %.2f + i%.2f = 0 \n",x2->real,x2->img);
				else if( x2->img < 0)
					fprintf(file,"Donc,	x2 = -i%.2f\n",Abs(x2->img));
				else
				  fprintf(file,"Donc,	x2 = i%.2f\n",x2->img);
			}
			else 
			{
				if(x2->img ==0)
					fprintf(file,"Donc,	x2 = %.2f \n",x2->real);
				else if (x2->img <0)
					fprintf(file,"Donc,	x2 = %.2f - i%.2f\n",x2->real,Abs(x2->img));
				else
					fprintf(file,"Donc,	x2 = %.2f + i%.2f\n",x2->real,x2->img);
			}
			fprintf(file,"Soit x3 le conjugué de x2\n");
			fprintf(file,"RAPPEL : x2 = a + ib, son conjugué x3 = a - ib\n");
			if( x2 ->real == 0)
      {
				if(x2->img == 0)
				 fprintf(file,"Donc,	x3 = %.2f - i%.2f = 0 \n",x2->real,x2->img);
				else if( x2->img < 0)
					fprintf(file,"Donc,	x3 = i%.2f\n",Abs(x2->img));
				else
				  fprintf(file,"Donc,	x3 = -i%.2f\n",x2->img);
			}
			else 
			{
				if(x2->img ==0)
					fprintf(file,"Donc,	x3 = %.2f \n",x2->real);
				else if (x2->img <0)
					fprintf(file,"Donc,	x3 = %.2f + i%.2f\n",x2->real,Abs(x2->img));
				else
					fprintf(file,"Donc,	x3 = %.2f - i%.2f\n",x2->real,x2->img);
			}
			free(x2);
}

