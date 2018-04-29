#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Coeff {
  float *left;
  float *right;
};
struct coeff {
  int *left;
  int *right;
};
float RES(int x[],int j,int k)
{
	int res =1;
	float Res =1;
	for(int i=0;i<j;i++)
	{
		if( i!=k)
			res *= (x[k]-x[i]);
	}
	Res = (float)1/(float)res;
	return Res;
}

void PrintL(int j,int k)
{
	//int degre = len-1;
	
	printf("					=> L%d(x) = ",k);
	for(int i=0; i < j;i++)
	{
		if(i !=k){
		  	printf(" (x-x%d)",i);
			
		}
	}
	printf(" / ");
	for(int i=0; i<j;i++)
	{
		if(i !=k){
		  	printf(" (x%d-x%d)",k,i);
			
		}
	}
	printf("\n");
}
void L(int x[],int j,int k)
{
	//int degre = len-1;
	
	printf("					         = ");
	float res = RES(x,j,k);
	printf("%.2f * ",res);
	for(int i=0; i < j;i++)
	{
		if(i !=k){
		  	printf("(x-%d)",x[i]);
			
		}
	}
	printf("\n");
}
void SAVEL(FILE *file,int x[],int j,int k)
{
	//int degre = len-1;
	
	//fprintf(file,"L%d(x)=",k);
	//float res = RES(x,j,k);
	//fprintf(file,"%.2f",res);
	for(int i=0; i < j;i++)
	{
		if(i !=k){
		  	fprintf(file,"(x-%d)",x[i]);
			
		}
	}
	fprintf(file,"\n");
}

float Produit(int fx,float res)
{
	float prod =1;
	prod = (float)fx*res;
	return prod;
}

void interpole_lineaire(int x[],int fx[])
{
	float p = ((float)fx[1]-(float)fx[0])/((float)x[1]-(float)x[0]);
	if(p == 0)
	{
			printf("y = %d\n",fx[0]);
	}
	else if(x[0]==0)
			printf("y = %.2f * x + %d\n",p,fx[0]);
	else if(x[0] > 0 && fx[0]>0)
				printf("y = %.2f * (x - %d) + %d\n",p,x[0],fx[0]);
	else if(x[0] <0 && fx[0] <0)
					printf("y = %.2f * (x + %d) - %d\n",p,abs(x[0]),abs(fx[0]));
	else if(x[0]>0 && fx[0]<0)
				  printf("y = %.2f * (x - %d) - %d\n",p,x[0],abs(fx[0]));
	else
					printf("y = %.2f * (x + %d) + %d\n",p,abs(x[0]),fx[0]);

}
int CountNumber(const char *equation)
{
	int count =0;

	for(unsigned int i =0; i<strlen(equation);i++)
	{
		/*if(equation[i] == 'x')
			count++;*/
		if(equation[i] >= '0'&& equation[i]<='9')
			count++;
	}
	return count;
}
int COUNTx(char* tab)
{	
	int count = 0;
	for(unsigned int i=0; i< strlen(tab);i++){
		if(tab[i]=='x')
			count++;
}
	return count;
}
int char_to_int(char c)
{
	int res= c -'0';
	return res;
}

int* RecupNumber(char *equation,/*float res,*/int* recup)
{
	//int count =0;
	int j = 0;
	if(equation[0]=='x')
	{
		recup[j] = 1;
		j =1;
		for(unsigned int i =1; i<strlen(equation);i++)
		{
			if(equation[i] == 'x'){
				recup[j] =char_to_int('1');//*res;
				j++;
			}
			if(equation[i] >= '0'&& equation[i]<='9')
			{	
				if(equation[i-1] == '-')
				{recup[j]=-char_to_int(equation[i]);//*res;
				j++;}
				else{
				recup[j]=-char_to_int(equation[i]);//*res;
			}	j++;}
		}
				
	}
	else
	{
		for(unsigned int i =0; i<strlen(equation);i++)
		{
			if(equation[i] == 'x'){
				recup[j] =char_to_int('1');//*res;
				j++;
			}
			if(equation[i] >= '0'&& equation[i]<='9')
			{	
				if(equation[i-1] == '-')
				{recup[j]= -char_to_int(equation[i]);//*res;
				j++;}
			}
		}
	}
	return recup;
}

/* Pour multiplier (x - 1)(5x + 2) par exemple où
  p1 = [-1; 1] et p2 = [2; 5]. p est un polynome du 2nd degré
  qui peut valoir par exemple 5x²+42x-3 et p = [-3; 42; 5] 
  (Pas fait les calculs c'est juste pour que tu comprennes)*/
int* dev2(int  p1[], int p2[], int p[]) {
  
  p[2] = p1[1] * p2[1];
  //printf("p[2] = %d = %d* %d\n",p[2],p1[1],p2[1]);
  p[1] = p1[0] * p2[1] + p1[1] * p2[0];
 //printf("p[1] = %d = %d * %d + %d * %d\n",p[1],p1[0],p2[1],p1[1],p2[0]);
  p[0] = p1[0] * p2[0];
  //printf("p[0] = %d = %d * %d\n",p[2],p1[0],p2[0]);
  return p;
}

// deg2 est le polynôme de degré 2 obtenus via la fonction d'avant
// et deg1 est un monôme de degré 1 le résultat est un polynôme
// de degré 3 qui suit la même règle de stockage
int* dev3(int deg2[] , int deg1[],int p[]) {
 
  p[3] = deg2[2] * deg1[1];
  //printf("p[3] = %d = %d * %d\n",p[3],deg2[2],deg1[1]);
  p[2] = deg2[2] * deg1[0] + deg2[1] * deg1[1];
  //printf("p[2] = %d =  %d * %d + %d * %d\n",p[2],deg2[2],deg1[0],deg2[1],deg1[1]);
  p[1] = deg2[1] * deg1[0] + deg2[0] * deg1[1];
  //printf("p[1] = %d = %d * %d+ %d * %d\n",p[1],deg2[1],deg1[0],deg2[0],deg1[1]);
  p[0] = deg2[0] * deg1[0];
  //printf("p[0] = %d = %d* %d\n",p[0],deg2[0],deg1[0]);
  return p;
}
int* dev4(int deg3[],int deg1[],int p[])
{
	p[4]=deg1[1]*deg3[3];
	p[3]=deg1[1]*deg3[2]+deg1[0]*deg3[3];
	p[2]=deg1[1]*deg3[1]+deg1[0]*deg3[2];
	p[1]=deg1[1]*deg3[0]+deg1[0]*deg3[1];
	p[0]= deg1[0]*deg3[0];
	return p;
}
int FindDegreeF(float* tab) {
  int degree = 4;
  while(tab[degree] == 0 && degree > 0)
    degree--;
  return degree;
}
int FindDegree(int* tab) {
  int degree = 4;
  while(tab[degree] == 0 && degree > 0)
    degree--;
  return degree;
}
static void Printpositivity(int n) {
  if (n < 0)
    printf(" - %d", - n);
  else
    printf(" + %d", n);
}

static void printdegree(int n){
  if (n == 4)
    printf("X⁴");
  else if (n == 3)
    printf("X³");
  else if (n == 2)
    printf("X²");
  else if (n == 1)
    printf("X");
}
void printCoeffs(struct coeff *cf,int num) {
  printf("					=> L%d(x) = ",num);
  int degreel = FindDegree(cf->left);
  //int degreer = FindDegree(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    printf("          0 = ");
  else {
    printf("%d", cf->left[degreel]);
    printdegree(degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(cf->left[degreel]);
        printdegree(degreel);
      }
      degreel--;
    }
  }
  printf("\n\n");
}
void printCoeffsF(struct Coeff *cf) {
  
  int degreel = FindDegreeF(cf->left);
  //int degreer = FindDegreeF(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    printf("          0 = ");
  else {
    printf(" %.2f", cf->left[degreel]);
    printdegree(degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(cf->left[degreel]);
        printdegree(degreel);
      }
      degreel--;
    }
  }
}
void printCoeffsFinal(struct Coeff *cf,int degre) {
  
  printf("			 P%d(x) = ",degre);
  int degreel = FindDegreeF(cf->left);
  //int degreer = FindDegreeF(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    printf("          0 = ");
  else {
    printf(" %.2f", cf->left[degreel]);
    printdegree(degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(cf->left[degreel]);
        printdegree(degreel);
      }
      degreel--;
    }
  }
}
void REMPLIR(int index,int debut, int fin,int* rempli, int* aremplir)
{
	for(int i= debut; i >= fin; i--){
		aremplir[index]= rempli[i];
		index++;
	}
}
void REMPLIRbis(int debut, int fin,int* rempli, int* aremplir)
{
	int k=0;
	for(int i= debut; i< fin; i++){
		aremplir[k]= rempli[i];
		k++;
		
	}
	//for(int i =0; i < 4; i++)
	//	printf("degré %d = %d\n",i,aremplir[i]);
	//printf("\n");
}
float* MULTIPLIER(int size,float mult,int* tab,float* final)
{
	for(int i= 0; i< size; i++){
		float nb = (float)tab[i];
		if(nb == 0)
			final[i]=0;
		else
			final[i]= mult * nb;
		//printf("leproduit[%d] = %.2f= %.2f * %.2f\n",i,final[i],mult,nb);
	}
	return final;
}
void REMETA0(int *tab, int size)
{
	for(int i=0;i<size;i++)
		tab[i]=0;
}
void FreeCoeff(struct coeff*cf) {
  free(cf->right);
  free(cf->left);
  free(cf);
}
void FreeCoeffF(struct Coeff*cf) {
  free(cf->right);
  free(cf->left);
  free(cf);
}
void PRINT_PART(int *tab,int size, int num)
{
	for(int i=0; i<size;i++)
			printf("PART : %d: %d,\n",num,tab[i]);
	printf("\n");
}
void PL(int j, int degre)
{
	printf("		=> P%d(x) = ",degre);
	for(int i=0; i<j;i++)
	{
		if(i != 0){
			printf("+f(x%d)*L%d(x)",i,i);}
		else{
			printf("f(x%d)*L%d(x)",i,i);}
		
	}
}
void printCoeff(struct coeff *cf) {
  int degreel = FindDegree(cf->left);
  //int degreer = FindDegree(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    printf("          0 = ");
  else {
    printf("%d", cf->left[degreel]);
    printdegree(degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(cf->left[degreel]);
        printdegree(degreel);
      }
      degreel--;
    }
  }
}
void PrintP(struct coeff *cf,float* res ,int position, int fx[])
{

	if(position != 0){
			printf(" + %d * ( %.2f*(",fx[position],res[position]);
			printCoeff(cf);
			printf("))");}
	else{
			printf(" %d * (%.2f*(",fx[position],res[position]);
			printCoeff(cf);
			printf("))");}
}
void REMPLISTRUCT(int size,struct coeff *cf,int* tab)
{
	for(int i=0;i<size;i++)
		cf->left[i] = tab[i];
}
void interpolation_polynomiale_2(int x[], int fx[], int degre)
{
	struct Coeff* cf= malloc(sizeof(struct Coeff));
	cf->left = calloc(5,sizeof(float));
	cf->right = calloc(5,sizeof(float));
	struct coeff* PARTIE1= malloc(sizeof(struct coeff));
	PARTIE1->left = calloc(5,sizeof(int));
	PARTIE1->right = calloc(5,sizeof(int));
	struct coeff* PARTIE2= malloc(sizeof(struct coeff));
	PARTIE2->left = calloc(5,sizeof(int));
	PARTIE2->right = calloc(5,sizeof(int));
	struct coeff* PARTIE3= malloc(sizeof(struct coeff));
	PARTIE3->left = calloc(5,sizeof(int));
	PARTIE3->right = calloc(5,sizeof(int));
	/*struct coeff* PARTIE4= malloc(sizeof(struct coeff));
	PARTIE4->left = calloc(5,sizeof(int));
	PARTIE4->right = calloc(5,sizeof(int));*/
	int size = degre +1;
	float P[size];
	float PRODUIT[size];
	FILE *file =NULL;
	char equation[80];
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Pour Déterminer le polynôme d’interpolation de Lagrange, satisfaisant ces points : \n\n");
	printf("\n 				x : ");
	for(int i=0; i<size; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<size;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("NOTATION : \n\n 		=> S(k=0->n) : Somme des k = 0 à n \n\n");
	printf("		=> Pr(j=0,j!=k->n) : Produit de j= 0 et j !=k à n \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Rappelons que le polynôme de Lagrange basé sur les points d’appui d’abscisses x0,x1, . . . ,xn est de degré n et s’écrit :\n");
	printf("\n");
	printf(" 					P(n)(x)= S(k=0->n)f(xk)*L(k)(x), avec L(k)(x) = Pr(j=0,j!=k->n)(x-xj)/(xk-xj)\n\n");
	printf("1. Ici on remarque que le degré qu'aura notre polynôme est 3 donc n = 3\n");
	printf("	\n 			 		P3(x)= S(k=0->3)f(xk)*L(k)(x)\n\n");
	printf("2. On calcule les L(k)(x) de 0 à 3 \n\n");
	for(int i=0; i< size; i++)
		{
			PrintL(size,i);
			printf("\n");
			L(x,size,i);
			printf("\n");
		}
	printf("Après développement en polynôme les L(k)(x) sont :\n\n");
	file = fopen("data.txt", "w");
    	if (file != NULL) {
		for(int i=0; i< size; i++)
		{
			SAVEL(file,x,size,i);
			P[i] = RES(x,size,i);//INSERE LE QUOTIENT QUI MULTIPLIE L'EQUATION
			//printf("P[%d] : %.2f \n",i,P[i]);
			PRODUIT[i]= Produit(fx[i],P[i]);
			//printf("PRODUIT[%d] : %.2f \n",i,PRODUIT[i]);
			//PL(file,x,4,3,fx);
		}

        	fclose(file);
	}
	//for(int i=0;i<4;i++)
		//printf("PRODUIT: %.2f",PRODUIT[i]);
	int j =0;
	int res =0;
	int polyfinal[100];
	int dex =0;
	file = fopen("data.txt","r");
	while(fgets(equation,80,file) !=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		res++;
		int p1[2];
		int p2[2];
		//int p3[2];
		int poly2[3];
 		//int poly3[4];
		int len=j/2;
		//INSERE LES NB DANS LES POLY SIMPLES CORRESPONDANT
		REMPLIR(0,len-1,0,NUMBER,p1);
		//PRINT_PART(p1,2,1);
		REMPLIR(0,3,2,NUMBER,p2);
		//PRINT_PART(p2,2,2);
		//REMPLIR(0,5,4,NUMBER,p3);
		//PRINT_PART(p3,2,3);
		dev2(p1,p2,poly2);
		//PRINT_PART(poly2,3,12);
		//dev3(poly2,p3,poly3);
		//PRINT_PART(poly3,4,13);
		REMETA0(p1,2);
		REMETA0(p2,2);
		//REMETA0(p3,2);
		//REMETA0(poly2,3);

		for(int i =0; i <size;i++)
		{
			polyfinal[dex] = poly2[i];
			dex++;
		}
		//REMETA0(poly3,4);
	}
	float PolyF[3];
	int polypartie1[3];
	int polypartie2[3];
	int polypartie3[3];
	//int polypartie4[4];
	float partie1[3];
	float partie2[3];
	float partie3[3];
	//float partie4[4];
	REMPLIRbis(0,3,polyfinal,polypartie1);
	REMPLISTRUCT(3,PARTIE1,polypartie1);
	/*PARTIE1->left[0] = polypartie1[0];
	PARTIE1->left[1] = polypartie1[1];
	PARTIE1->left[2] = polypartie1[2];
	PARTIE1->left[3] = polypartie1[3];*/
	//REMETA0(polypartie1,4);
	//PRINT_PART(PARTIE1->left,3,1);

	printCoeffs(PARTIE1,1);

	REMPLIRbis(3,6,polyfinal,polypartie2);

	PARTIE2->left[0] = polypartie2[0];
	PARTIE2->left[1] = polypartie2[1];
	PARTIE2->left[2] = polypartie2[2];
	//PARTIE2->left[3] = polypartie2[3];
	//REMETA0(polypartie2,4);
	//PRINT_PART(PARTIE2->left,4,2);
	printCoeffs(PARTIE2,2);

	REMPLIRbis(6,9,polyfinal,polypartie3);
	PARTIE3->left[0] = polypartie3[0];
	PARTIE3->left[1] = polypartie3[1];
	PARTIE3->left[2] = polypartie3[2];
	//PARTIE3->left[3] = polypartie3[3];
	//REMETA0(polypartie3,4);
	//PRINT_PART(PARTIE3->left,4);
	printCoeffs(PARTIE3,3);


	//REMPLIRbis(12,16,polyfinal,polypartie4);
	//PARTIE4->left[0] = polypartie4[0];
	//PARTIE4->left[1] = polypartie4[1];
	//PARTIE4->left[2] = polypartie4[2];
	//PARTIE4->left[3] = polypartie4[3];
	//REMETA0(polypartie4,4);
	//PRINT_PART(PARTIE4->left,4);
	//printCoeffs(PARTIE4,4);

	MULTIPLIER(3,PRODUIT[0],polypartie1,partie1);
	MULTIPLIER(3,PRODUIT[1],polypartie2,partie2);
	MULTIPLIER(3,PRODUIT[2],polypartie3,partie3);
	//MULTIPLIER(PRODUIT[3],polypartie4,partie4);
	for(int i=0; i <3;i++){
		PolyF[i] = partie1[i]+partie2[i]+partie3[i];//+partie4[i];
		//printf("PolyF[i] = partie1[i]+partie2[i]+partie3[i]+partie4[i] \n");
		//printf(" = %.2f = %.2f +%.2f+%.2f+%.2f\n",PolyF[i],partie1[i],partie2[i],partie3[i],partie4[i]);
	}
	printf("3. Ainsi le polynôme de Lagrange s'écrit :\n\n\n");
	PL(3,2);
	printf("Ce qui donne :\n\n");
	printf("		        = ");
	PrintP(PARTIE1,P,0,fx);
	PrintP(PARTIE2,P,1,fx);
	PrintP(PARTIE3,P,2,fx);
	//PrintP(x,PARTIE4,3,P,3,fx);
	printf("\n");
	cf->left[0] = PolyF[0];
	cf->left[1] = PolyF[1];
	cf->left[2] = PolyF[2];
	//cf->left[3] = PolyF[3];
	printf("		        = ");
	printCoeffsF(cf);
	printf("\n");
	printf("Ainsi le polynôme qui passe par les points suivants : \n");
	printf("\n 				x : ");
	for(int i=0; i<3; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<3;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("Est : \n");
	printCoeffsFinal(cf,2);
	printf("\n");
	 	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
	FreeCoeff(PARTIE3);
	//FreeCoeff(PARTIE4);
	FreeCoeffF(cf);
}
void interpolation_polynomiale_3(int x[], int fx[], int degre)
{
	struct Coeff* cf= malloc(sizeof(struct Coeff));
	cf->left = calloc(5,sizeof(float));
	cf->right = calloc(5,sizeof(float));
	struct coeff* PARTIE1= malloc(sizeof(struct coeff));
	PARTIE1->left = calloc(5,sizeof(int));
	PARTIE1->right = calloc(5,sizeof(int));
	struct coeff* PARTIE2= malloc(sizeof(struct coeff));
	PARTIE2->left = calloc(5,sizeof(int));
	PARTIE2->right = calloc(5,sizeof(int));
	struct coeff* PARTIE3= malloc(sizeof(struct coeff));
	PARTIE3->left = calloc(5,sizeof(int));
	PARTIE3->right = calloc(5,sizeof(int));
	struct coeff* PARTIE4= malloc(sizeof(struct coeff));
	PARTIE4->left = calloc(5,sizeof(int));
	PARTIE4->right = calloc(5,sizeof(int));
	int size = degre +1;
	float P[size];
	float PRODUIT[size];
	FILE *file =NULL;
	char equation[80];
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Pour Déterminer le polynôme d’interpolation de Lagrange, satisfaisant ces points : \n\n");
	printf("\n 				x : ");
	for(int i=0; i<size; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<size;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("NOTATION : \n\n 		=> S(k=0->n) : Somme des k = 0 à n \n\n");
	printf("		=> Pr(j=0,j!=k->n) : Produit de j= 0 et j !=k à n \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Rappelons que le polynôme de Lagrange basé sur les points d’appui d’abscisses x0,x1, . . . ,xn est de degré n et s’écrit :\n");
	printf("\n");
	printf(" 					P(n)(x)= S(k=0->n)f(xk)*L(k)(x), avec L(k)(x) = Pr(j=0,j!=k->n)(x-xj)/(xk-xj)\n\n");
	printf("1. Ici on remarque que le degré qu'aura notre polynôme est 3 donc n = 3\n");
	printf("	\n 			 		P3(x)= S(k=0->3)f(xk)*L(k)(x)\n\n");
	printf("2. On calcule les L(k)(x) de 0 à 3 \n\n");
	for(int i=0; i< size; i++)
		{
			PrintL(size,i);
			printf("\n");
			L(x,size,i);
			printf("\n");
		}
	printf("Après développement en polynôme les L(k)(x) sont :\n\n");
	file = fopen("data.txt", "w");
    	if (file != NULL) {
		for(int i=0; i< size; i++)
		{
			SAVEL(file,x,size,i);
			P[i] = RES(x,size,i);//INSERE LE QUOTIENT QUI MULTIPLIE L'EQUATION
			//printf("P[%d] : %.2f \n",i,P[i]);
			PRODUIT[i]= Produit(fx[i],P[i]);
			//printf("PRODUIT[%d] : %.2f \n",i,PRODUIT[i]);
			//PL(file,x,4,3,fx);
		}

        	fclose(file);
	}
	//for(int i=0;i<4;i++)
		//printf("PRODUIT: %.2f",PRODUIT[i]);
	int j =0;
	int res =0;
	int polyfinal[100];
	int dex =0;
	file = fopen("data.txt","r");
	while(fgets(equation,80,file) !=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		res++;
		int p1[2];
		int p2[2];
		int p3[2];
		int poly2[3];
 		int poly3[4];
		int len=j/3;
		//INSERE LES NB DANS LES POLY SIMPLES CORRESPONDANT
		REMPLIR(0,len-1,0,NUMBER,p1);
		//PRINT_PART(p1,2,1);
		REMPLIR(0,3,2,NUMBER,p2);
		//PRINT_PART(p2,2,2);
		REMPLIR(0,5,4,NUMBER,p3);
		//PRINT_PART(p3,2,3);
		dev2(p1,p2,poly2);
		//PRINT_PART(poly2,3,12);
		dev3(poly2,p3,poly3);
		//PRINT_PART(poly3,4,13);
		REMETA0(p1,2);
		REMETA0(p2,2);
		REMETA0(p3,2);
		REMETA0(poly2,3);

		for(int i =0; i <size;i++)
		{
			polyfinal[dex] = poly3[i];
			dex++;
		}
		//REMETA0(poly3,4);
	}
	float PolyF[4];
	int polypartie1[4];
	int polypartie2[4];
	int polypartie3[4];
	int polypartie4[4];
	float partie1[4];
	float partie2[4];
	float partie3[4];
	float partie4[4];
	REMPLIRbis(0,4,polyfinal,polypartie1);
	REMPLISTRUCT(4,PARTIE1,polypartie1);
	/*PARTIE1->left[0] = polypartie1[0];
	PARTIE1->left[1] = polypartie1[1];
	PARTIE1->left[2] = polypartie1[2];
	PARTIE1->left[3] = polypartie1[3];*/
	//REMETA0(polypartie1,4);
	//PRINT_PART(PARTIE1->left,4);

	printCoeffs(PARTIE1,1);

	REMPLIRbis(4,8,polyfinal,polypartie2);

	PARTIE2->left[0] = polypartie2[0];
	PARTIE2->left[1] = polypartie2[1];
	PARTIE2->left[2] = polypartie2[2];
	PARTIE2->left[3] = polypartie2[3];
	//REMETA0(polypartie2,4);
	//PRINT_PART(PARTIE2->left,4,2);
	printCoeffs(PARTIE2,2);

	REMPLIRbis(8,12,polyfinal,polypartie3);
	PARTIE3->left[0] = polypartie3[0];
	PARTIE3->left[1] = polypartie3[1];
	PARTIE3->left[2] = polypartie3[2];
	PARTIE3->left[3] = polypartie3[3];
	//REMETA0(polypartie3,4);
	//PRINT_PART(PARTIE3->left,4);
	printCoeffs(PARTIE3,3);


	REMPLIRbis(12,16,polyfinal,polypartie4);
	PARTIE4->left[0] = polypartie4[0];
	PARTIE4->left[1] = polypartie4[1];
	PARTIE4->left[2] = polypartie4[2];
	PARTIE4->left[3] = polypartie4[3];
	//REMETA0(polypartie4,4);
	//PRINT_PART(PARTIE4->left,4);
	printCoeffs(PARTIE4,4);

	MULTIPLIER(4,PRODUIT[0],polypartie1,partie1);
	MULTIPLIER(4,PRODUIT[1],polypartie2,partie2);
	MULTIPLIER(4,PRODUIT[2],polypartie3,partie3);
	MULTIPLIER(4,PRODUIT[3],polypartie4,partie4);
	for(int i=0; i <4;i++){
		PolyF[i] = partie1[i]+partie2[i]+partie3[i]+partie4[i];
		//printf("PolyF[i] = partie1[i]+partie2[i]+partie3[i]+partie4[i] \n");
		//printf(" = %.2f = %.2f +%.2f+%.2f+%.2f\n",PolyF[i],partie1[i],partie2[i],partie3[i],partie4[i]);
	}
	printf("3. Ainsi le polynôme de Lagrange s'écrit :\n\n\n");
	PL(4,3);
	printf("Ce qui donne :\n\n");
	printf("		        = ");
	PrintP(PARTIE1,P,0,fx);
	PrintP(PARTIE2,P,1,fx);
	PrintP(PARTIE3,P,2,fx);
	PrintP(PARTIE4,P,3,fx);
	printf("\n");
	cf->left[0] = PolyF[0];
	cf->left[1] = PolyF[1];
	cf->left[2] = PolyF[2];
	cf->left[3] = PolyF[3];
	printf("		        = ");
	printCoeffsF(cf);
	printf("\n");
	printf("Ainsi le polynôme qui passe par les points suivants : \n");
	printf("\n 				x : ");
	for(int i=0; i<4; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<4;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("Est : \n");
	printCoeffsFinal(cf,3);
	printf("\n");
	 	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
	FreeCoeff(PARTIE3);
	FreeCoeff(PARTIE4);
	FreeCoeffF(cf);
}
void interpolation_polynomiale_4(int x[], int fx[], int degre)
{
	struct Coeff* cf= malloc(sizeof(struct Coeff));
	cf->left = calloc(5,sizeof(float));
	cf->right = calloc(5,sizeof(float));
	struct coeff* PARTIE1= malloc(sizeof(struct coeff));
	PARTIE1->left = calloc(5,sizeof(int));
	PARTIE1->right = calloc(5,sizeof(int));
	struct coeff* PARTIE2= malloc(sizeof(struct coeff));
	PARTIE2->left = calloc(5,sizeof(int));
	PARTIE2->right = calloc(5,sizeof(int));
	struct coeff* PARTIE3= malloc(sizeof(struct coeff));
	PARTIE3->left = calloc(5,sizeof(int));
	PARTIE3->right = calloc(5,sizeof(int));
	struct coeff* PARTIE4= malloc(sizeof(struct coeff));
	PARTIE4->left = calloc(5,sizeof(int));
	PARTIE4->right = calloc(5,sizeof(int));
	struct coeff* PARTIE5= malloc(sizeof(struct coeff));
	PARTIE5->left = calloc(5,sizeof(int));
	PARTIE5->right = calloc(5,sizeof(int));
	int size = degre +1;
	float P[size];
	float PRODUIT[size];
	FILE *file =NULL;
	char equation[80];
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Pour Déterminer le polynôme d’interpolation de Lagrange, satisfaisant ces points : \n\n");
	printf("\n 				x : ");
	for(int i=0; i<size; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<size;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("\n");
	printf("NOTATION : \n\n 		=> S(k=0->n) : Somme des k = 0 à n \n\n");
	printf("		=> Pr(j=0,j!=k->n) : Produit de j= 0 et j !=k à n \n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Rappelons que le polynôme de Lagrange basé sur les points d’appui d’abscisses x0,x1, . . . ,xn est de degré n et s’écrit :\n");
	printf("\n");
	printf(" 					P(n)(x)= S(k=0->n)f(xk)*L(k)(x), avec L(k)(x) = Pr(j=0,j!=k->n)(x-xj)/(xk-xj)\n\n");
	printf("1. Ici on remarque que le degré qu'aura notre polynôme est 4 donc n = 4\n");
	printf("	\n 			 		P3(x)= S(k=0->4)f(xk)*L(k)(x)\n\n");
	printf("2. On calcule les L(k)(x) de 0 à 4 \n\n");
	for(int i=0; i< size; i++)
		{
			PrintL(size,i);
			printf("\n");
			L(x,size,i);
			printf("\n");
		}
	printf("Après développement en polynôme les L(k)(x) sont :\n\n");
	file = fopen("data.txt", "w");
    	if (file != NULL) {
		for(int i=0; i< size; i++)
		{
			SAVEL(file,x,size,i);
			P[i] = RES(x,size,i);//INSERE LE QUOTIENT QUI MULTIPLIE L'EQUATION
			//printf("P[%d] : %.2f \n",i,P[i]);
			PRODUIT[i]= Produit(fx[i],P[i]);
			//printf("PRODUIT[%d] : %.2f \n",i,PRODUIT[i]);
			//PL(file,x,4,3,fx);
		}

        	fclose(file);
	}
	//for(int i=0;i<4;i++)
		//printf("PRODUIT: %.2f",PRODUIT[i]);
	int j =0;
	int res =0;
	int polyfinal[100];
	int dex =0;
	file = fopen("data.txt","r");
	while(fgets(equation,80,file) !=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		res++;
		int p1[2];
		int p2[2];
		int p3[2];
		int p4[2];
		int poly2[3];
 	  int poly3[4];
	  int poly4[5];
		int len=j/3;
		//INSERE LES NB DANS LES POLY SIMPLES CORRESPONDANT
		REMPLIR(0,len-1,0,NUMBER,p1);
		PRINT_PART(p1,2,1);
		REMPLIR(0,3,2,NUMBER,p2);
		PRINT_PART(p2,2,2);
		REMPLIR(0,5,4,NUMBER,p3);
		PRINT_PART(p3,2,3);
		REMPLIR(0,7,6,NUMBER,p4);
		PRINT_PART(p4,2,4);
		dev2(p1,p2,poly2);
		PRINT_PART(poly2,3,12);
		dev3(poly2,p3,poly3);
		//PRINT_PART(poly3,4,13);
		dev4(poly3,p4,poly4);
		//PRINT_PART(poly3,4,14);
		REMETA0(p1,2);
		REMETA0(p2,2);
		REMETA0(p3,2);
		REMETA0(poly2,3);
		REMETA0(poly3,4);

		for(int i =0; i <size;i++)
		{
			polyfinal[dex] = poly4[i];
			dex++;
		}
		//REMETA0(poly3,4);
	}
	float PolyF[5];
	int polypartie1[5];
	int polypartie2[5];
	int polypartie3[5];
	int polypartie4[5];
	int polypartie5[5];
	float partie1[5];
	float partie2[5];
	float partie3[5];
	float partie4[5];
	float partie5[5];
	
	REMPLIRbis(0,5,polyfinal,polypartie1);
	REMPLISTRUCT(5,PARTIE1,polypartie1);
	//PRINT_PART(PARTIE1->left,5);
	printCoeffs(PARTIE1,1);

	REMPLIRbis(5,10,polyfinal,polypartie2);
	REMPLISTRUCT(5,PARTIE2,polypartie2);
	//PRINT_PART(PARTIE2->left,5);
	printCoeffs(PARTIE2,2);

	REMPLIRbis(10,15,polyfinal,polypartie3);
	REMPLISTRUCT(5,PARTIE3,polypartie3);
	//PRINT_PART(PARTIE3->left,5);
	printCoeffs(PARTIE3,3);


	REMPLIRbis(15,20,polyfinal,polypartie4);
	REMPLISTRUCT(5,PARTIE4,polypartie4);
	
	//PRINT_PART(PARTIE4->left,5);
	printCoeffs(PARTIE4,4);
	
	REMPLIRbis(20,25,polyfinal,polypartie5);
	REMPLISTRUCT(5,PARTIE5,polypartie5);
	
	//PRINT_PART(PARTIE5->left,5);
	printCoeffs(PARTIE5,5);
	
	
	MULTIPLIER(5,PRODUIT[0],polypartie1,partie1);
	MULTIPLIER(5,PRODUIT[1],polypartie2,partie2);
	MULTIPLIER(5,PRODUIT[2],polypartie3,partie3);
	MULTIPLIER(5,PRODUIT[3],polypartie4,partie4);
	MULTIPLIER(5,PRODUIT[4],polypartie5,partie5);
	for(int i=0; i <5;i++){
		PolyF[i] = partie1[i]+partie2[i]+partie3[i]+partie4[i]+partie5[i];
		//printf("PolyF[i] = partie1[i]+partie2[i]+partie3[i]+partie4[i] \n");
		//printf(" = %.2f = %.2f +%.2f+%.2f+%.2f\n",PolyF[i],partie1[i],partie2[i],partie3[i],partie4[i]);
	}
	printf("3. Ainsi le polynôme de Lagrange s'écrit :\n\n\n");
	PL(5,4);
	printf("Ce qui donne :\n\n");
	printf("		        = ");
	PrintP(PARTIE1,P,0,fx);
	PrintP(PARTIE2,P,1,fx);
	PrintP(PARTIE3,P,2,fx);
	PrintP(PARTIE4,P,3,fx);
	PrintP(PARTIE5,P,4,fx);
	printf("\n");
	cf->left[0] = PolyF[0];
	cf->left[1] = PolyF[1];
	cf->left[2] = PolyF[2];
	cf->left[3] = PolyF[3];	
	cf->left[4] = PolyF[4];
	printf("		        = ");
	printCoeffsF(cf);
	printf("\n");
	printf("Ainsi le polynôme qui passe par les points suivants : \n");
	printf("\n 				x : ");
	for(int i=0; i<5; i++){
		printf("%d,",x[i]);
	}
	printf("\n\n");
	printf("			     f(x) : " );
	for(int i=0;i<5;i++){
		printf("%d,",fx[i]);
	}
	printf("\n");
	printf("\n");
	printf("Est : \n");
	printCoeffsFinal(cf,4);
	printf("\n");
	 	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
	FreeCoeff(PARTIE3);
	FreeCoeff(PARTIE4);
	FreeCoeff(PARTIE5);
	FreeCoeffF(cf);
}
int main(int argc, char** argv)
{ 
	
	if(argc <2)
	{
		printf("Veuillez écrire l'interpolation que vous voulez : \n");
		printf("		=> linéaire\n 		=> polynomiale\n");
		return 0;
	}
	if(strcmp(argv[1],"lineaire")==0)
	{	
		int x[2];
		int res;
		int fx[2];
		int res2;
		printf("Entrez 2 valeurs de x en les espaçant: ");
		res = scanf("%d %d",&x[0],&x[1]);
		if (res < 2)
		{
  			printf("Il manques des valeurs\n");
  			return 0;
  	}
		printf("Entrez 2 valeurs de f(x) en les espaçant: ");
		res2 = scanf("%d %d",&fx[0],&fx[1]);
  		if (res2 < 2)
  		{
  			printf("Il manques des valeurs\n");
  			return 0;
  		}
  		interpole_lineaire(x,fx);
}
  	else if(strcmp(argv[1],"polynomiale")==0)
  	{
  		int reponse;
  		int degre;
  		printf("Entrez le degré de votre équation final svp : ");	
  		reponse = scanf("%d",&degre);
  		if(reponse == 1 && degre == 2)
  		{
  			int x[3];
			int res;
			int fx[3];
			int res2;
			printf("Entrez 3 valeurs de x en les espaçant: ");
			res = scanf("%d %d %d",&x[0],&x[1],&x[2]);
			if (res < 3)
			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
			printf("Entrez 3 valeurs de f(x) en les espaçant: ");
			res2 = scanf("%d %d %d",&fx[0],&fx[1],&fx[2]);
			
  			if (res2 < 3)
  			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
  			interpolation_polynomiale_2(x,fx,degre);
  		}
  		else if(reponse ==1 && degre == 3)
  		{
  			int x[4];
			int res;
			int fx[4];
			int res2;
			printf("Entrez 4 valeurs de x en les espaçant: ");
			res = scanf("%d %d %d %d",&x[0],&x[1],&x[2],&x[3]);
			if (res < 4)
			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
			printf("Entrez 4 valeurs de f(x) en les espaçant: ");
			res2 = scanf("%d %d %d %d",&fx[0],&fx[1],&fx[2],&fx[3]);
		
  			if (res2 < 4)
  			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
  			interpolation_polynomiale_3(x,fx,degre);
  	}
		else if(reponse ==1 && degre ==4)
		{
  		int x[5];
			int res;
			int fx[5];
			int res2;
			printf("Entrez 5 valeurs de x en les espaçant: ");
			res = scanf("%d %d %d %d %d",&x[0],&x[1],&x[2],&x[3],&x[4]);
			if (res < 5)
			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
			printf("Entrez 5 valeurs de f(x) en les espaçant: ");
			res2 = scanf("%d %d %d %d %d",&fx[0],&fx[1],&fx[2],&fx[3],&fx[4]);
		
  			if (res2 < 5)
  			{
  				printf("Il manques des valeurs\n");
  				return 0;
  			}
  			interpolation_polynomiale_4(x,fx,degre);
  		}
 }
}
