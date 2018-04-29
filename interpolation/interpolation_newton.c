#include "interpolation_newton.h"

static void PrintX(FILE* file,int x[],int len)
{
	for(int i=0; i<len; i++)
	{
		if(x[i] < 0)
			fprintf(file,"(x + %d)",abs(x[i]));
		else if(x[i] > 0)
			fprintf(file,"(x - %d)",x[i]);
		else 
			fprintf(file,"x");
	}
	
}
/* Pour multiplier (x - 1)(5x + 2) par exemple où
  p1 = [-1; 1] et p2 = [2; 5]. p est un polynome du 2nd degré
  qui peut valoir par exemple 5x²+42x-3 et p = [-3; 42; 5] 
  (Pas fait les calculs c'est juste pour que tu comprennes)
static int* dev2(int  p1[], int p2[], int p[]) {
  
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
static int* dev3(int deg2[] , int deg1[],int p[]) {
 
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
static int* dev4(int deg3[],int deg1[],int p[])
{
	p[4]=deg1[1]*deg3[3];
	p[3]=deg1[1]*deg3[2]+deg1[0]*deg3[3];
	p[2]=deg1[1]*deg3[1]+deg1[0]*deg3[2];
	p[1]=deg1[1]*deg3[0]+deg1[0]*deg3[1];
	p[0]= deg1[0]*deg3[0];
	return p;
}
static int char_to_int(char c)
{
	int res= c -'0';
	return res;
}
static void REMPLIR(int index,int debut, int fin,int* rempli, int* aremplir)
{
	for(int i= debut; i >= fin; i--){
		aremplir[index]= rempli[i];
		index++;
	}
}*/
static void SaveX(FILE* file,int x[],int len)
{
	for(int i=0; i<len; i++)
	{
		if(x[i] < 0)
			fprintf(file,"(x+%d)",abs(x[i]));
		else 
			fprintf(file,"(x-%d)",x[i]);
	}
	fprintf(file,"\n");
}
static int differences_divisees(FILE* file,int x1,int x2,int fx1,int fx2)
{
	fprintf(file,"				Ce qui donne: \n");
	if(fx1 <0 && x1 <0)
		fprintf(file," 						        %d + %d / %d + %d",fx2,abs(fx1),x2,abs(x1));
	else if(fx1 >0 && x1 <0)
		fprintf(file," 						        %d - %d / %d + %d",fx2,fx1,x2,abs(x1));
	else if(fx1 <0 && x1 >0)
		fprintf(file," 						        %d + %d / %d - %d",fx2,abs(fx1),x2,x1);
	else
		fprintf(file," 						        %d - %d / %d - %d",fx2,fx1,x2,x1);
	int res = (fx2 - fx1)/(x2-x1);
	fprintf(file," = %d",res);
	fprintf(file,"\n\n");
	return res;
}
/*static int CountNumber(const char *equation)
{
	int count =0;

	for(unsigned int i =0; i<strlen(equation);i++)
	{
		if(equation[i] >= '0'&& equation[i]<='9')
			count++;
	}
	return count;
}
static int COUNTx(char* tab)
{	
	int count = 0;
	for(unsigned int i=0; i< strlen(tab);i++){
		if(tab[i]=='x')
			count++;
}
	return count;
}*/
static int* MULTIPLIER(int size,int mult,int* tab,int* final)
{
	for(int i= 0; i< size; i++){
		int nb = tab[i];
		if(nb == 0)
			final[i]=0;
		else
			final[i]= mult * nb;
		printf("leproduit[%d] = %d= %d * %d\n",i,final[i],mult,nb);
	}
	return final;
}
static int* RecupNumber(char *equation,/*float res,*/int* recup)
{
	int j=0;
	for(int i =0 ;i<strlen(equation);i++)
	{
		if(equation[i] == 'x'){
			recup[j] = char_to_int('1');
			j++;
		}
		if(equation[i]>='0' && equation[i] <='9'){
			if(equation[i-1]=='-'){
				recup[j]=-char_to_int(equation[i]);
				j++;
			}
			else{
				recup[j]=char_to_int(equation[i]);
				j++;	
			}
		}
	}
	return recup;
}
/*static void Printpositivity(FILE* file,int n) {
  if (n < 0)
    fprintf(file," - %d", - n);
  else
    fprintf(file," + %d", n);
}

static void printdegree(FILE* file,int n){
  if (n == 4)
    fprintf(file,"X⁴");
  else if (n == 3)
    fprintf(file,"X³");
  else if (n == 2)
    fprintf(file,"X²");
  else if (n == 1)
    fprintf(file,"X");
}*/
static void printCoeff(FILE* file,struct coeff *cf) {
  int degreel = FindDegree(cf->left);
  //int degreer = FindDegree(cf->right);
  // Left part
  //if (degreel == 0 )&& cf->left[0] == 0)
    //fprintf(file,"          0 = ");
  //else {
    fprintf(file,"%d", cf->left[degreel]);
    printdegree(file,degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(file,cf->left[degreel]);
        printdegree(file,degreel);
      }
      degreel--;
    }
  //}
}
/*static void PRINT_PART(int *tab,int size, int num)
{
	for(int i=0; i<size;i++)
			fprintf(stdout,"PART : %d: %d,\n",num,tab[i]);
	fprintf(stdout,"\n");
}
static void REMPLISTRUCT(int size,struct coeff *cf,int* tab)
{
	for(int i=0;i<size;i++)
		cf->left[i] = tab[i];
}*/
static void Poly_newton3(FILE* Fichier,int x[], int diff[])
{
	struct coeff* cf= malloc(sizeof(struct coeff));
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
	
	fprintf(Fichier,"2. Ici on est en degré 3 donc \n\n 	        P3(x) = f(x0) + f[x0,x1](x - x0) + f[x0,x1,x2](x - x0)(x - x1) + f[x0,x1,x2,x3](x - x0)(x - x1)(x - x2)\n\n");
	fprintf(Fichier,"Ce qui donne : \n\n");
	if(diff[0]!= 0)
		fprintf(Fichier,"	P3(x) = %d ",diff[0]);
	else 
		fprintf(Fichier,"	P3(x) = ");	
	for(int i=1; i < 4;i++){
			if(diff[i] > 0)
				fprintf(Fichier,"+ %d * ",abs(diff[i]));
			else if(diff[i] < 0)
				fprintf(Fichier," - %d * ",abs(diff[i]));
			else
				fprintf(Fichier," ");
		PrintX(Fichier,x,i);
	}
	fprintf(Fichier,"\n");
	int rec[15];
	int index=0;
	char equation[20];
	//FILE *ok = NULL;
	FILE *ok=fopen("test.txt","w");
	if(ok !=NULL){
		for(int j=1; j<4; j++)
			SaveX(ok,x,j);
		
	}
	fclose(ok);
	int res =0, j=0;
	int polyfinal[100];
	int dex =0;
	int p1[2];
	int p2[2];
	int p3[2];
	int second_degre[3];
	int troisieme_degre[4];
	ok = fopen("test.txt","r");
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		int res1[2];
		MULTIPLIER(2,diff[1],p1,res1);
		REMPLISTRUCT(2,PARTIE1,res1);
	}
	long position = ftell(ok);
	fseek(ok,position,SEEK_SET);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		dev2(p1,p2,second_degre);
		int res2[3];
		MULTIPLIER(3,diff[2],second_degre,res2);
		REMPLISTRUCT(3,PARTIE2,res2);
	}
	position = ftell(ok);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);	
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		REMPLIR(0,5,4,NUMBER,p3);
		dev2(p1,p2,second_degre);
		dev3(second_degre,p3,troisieme_degre);
		int res3[4];
		MULTIPLIER(4,diff[3],troisieme_degre,res3);
		REMPLISTRUCT(4,PARTIE3,res3);
	}
	fclose(ok);
	fprintf(Fichier,"Ainsi : \n\n");
	if(diff[0]!= 0){
		if(diff[0] < 0)
			fprintf(Fichier,"	P3(x) = %d - ",abs(diff[0]));
		else
			fprintf(Fichier,"	P3(x) = %d + ",diff[0]);}
	else 
		fprintf(Fichier,"	P3(x) = ");	
	printCoeff(Fichier,PARTIE1);
	if (PARTIE2->left[2] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE2);
	if (PARTIE3->left[3] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE3);
	fprintf(Fichier,"\n\n");
	cf->left[0]= diff[0]+PARTIE1->left[0]+PARTIE2->left[0]+PARTIE3->left[0];
	cf->left[1]=PARTIE1->left[1]+PARTIE2->left[1]+PARTIE3->left[1];
	cf->left[2]= PARTIE2->left[2]+PARTIE3->left[2];
	cf->left[3]=PARTIE3->left[3];
	fprintf(Fichier,"On rassemble tout et on obtient : \n\n");
	fprintf(Fichier,"	P3(x) = ");	
	printCoeff(Fichier,cf);
	fprintf(Fichier,"\n");
	FreeCoeff(cf);
	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
	FreeCoeff(PARTIE3);
}
static void Poly_newton2(FILE* Fichier,int x[], int diff[])
{
	struct coeff* cf= malloc(sizeof(struct coeff));
	cf->left = calloc(5,sizeof(float));
	cf->right = calloc(5,sizeof(float));
	struct coeff* PARTIE1= malloc(sizeof(struct coeff));
	PARTIE1->left = calloc(5,sizeof(int));
	PARTIE1->right = calloc(5,sizeof(int));
	struct coeff* PARTIE2= malloc(sizeof(struct coeff));
	PARTIE2->left = calloc(5,sizeof(int));
	PARTIE2->right = calloc(5,sizeof(int));

	fprintf(Fichier,"2. Ici on est en degré 2 donc \n\n 	        P3(x) = f(x0) + f[x0,x1](x - x0) + f[x0,x1,x2](x - x0)(x - x1)\n\n");
	fprintf(Fichier,"Ce qui donne : \n\n");
	if(diff[0]!= 0)
		fprintf(Fichier,"	P2(x) = %d ",diff[0]);
	else 
		fprintf(Fichier,"	P2(x) = ");	
	for(int i=1; i < 3;i++){
			if(diff[i] > 0)
				fprintf(Fichier,"+ %d * ",abs(diff[i]));
			else if(diff[i] < 0)
				fprintf(Fichier," - %d * ",abs(diff[i]));
			else
				fprintf(Fichier," ");
		PrintX(Fichier,x,i);
	}
	fprintf(Fichier,"\n");
	int rec[15];
	int index=0;
	char equation[20];
	//FILE *ok = NULL;
	FILE *ok=fopen("test.txt","w");
	if(ok !=NULL){
		for(int j=1; j<3; j++)
			SaveX(ok,x,j);
		
	}
	fclose(ok);
	int res =0, j=0;
	int polyfinal[100];
	int dex =0;
	int p1[2];
	int p2[2];
	int second_degre[3];
	ok = fopen("test.txt","r");
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		int res1[2];
		MULTIPLIER(2,diff[1],p1,res1);
		REMPLISTRUCT(2,PARTIE1,res1);
	}
	long position = ftell(ok);
	fseek(ok,position,SEEK_SET);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		dev2(p1,p2,second_degre);
		int res2[3];
		MULTIPLIER(3,diff[2],second_degre,res2);
		REMPLISTRUCT(3,PARTIE2,res2);
	}
	fprintf(Fichier,"Ainsi : \n\n");
	if(diff[0]!= 0){
		if(diff[0] < 0)
			fprintf(Fichier,"	P2(x) = %d - ",abs(diff[0]));
		else
			fprintf(Fichier,"	P2(x) = %d + ",diff[0]);}
	else 
		fprintf(Fichier,"	P2(x) = ");	
	printCoeff(Fichier,PARTIE1);
	if (PARTIE2->left[2] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE2);
	fprintf(Fichier,"\n\n");
	cf->left[0]= diff[0]+PARTIE1->left[0]+PARTIE2->left[0];
	cf->left[1]=PARTIE1->left[1]+PARTIE2->left[1];
	cf->left[2]= PARTIE2->left[2];
	fprintf(Fichier,"On rassemble tout et on obtient : \n\n");
	fprintf(Fichier,"	P2(x) = ");	
	printCoeff(Fichier,cf);
	fprintf(Fichier,"\n");
	FreeCoeff(cf);
	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
}
static void Poly_newton4(FILE* Fichier,int x[], int diff[])
{
	struct coeff* cf= malloc(sizeof(struct coeff));
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
	fprintf(Fichier,"2. Ici on est en degré 4 donc \n\n 	        P3(x) = f(x0) + f[x0,x1](x - x0) + f[x0,x1,x2](x - x0)(x - x1) + f[x0,x1,x2,x3](x - x0)(x - x1)(x - x2) + f[x0,x1,x2,x3,x4](x - x0)(x -x1)(x - x2)(x - x3)\n\n");
	fprintf(Fichier,"Ce qui donne : \n\n");
	if(diff[0]!= 0)
		fprintf(Fichier,"	P4(x) = %d ",diff[0]);
	else 
		fprintf(Fichier,"	P4(x) = ");	
	for(int i=1; i < 5;i++){
			if(diff[i] > 0)
				fprintf(Fichier,"+ %d * ",abs(diff[i]));
			else if(diff[i] < 0)
				fprintf(Fichier," - %d * ",abs(diff[i]));
			else
				fprintf(Fichier," ");
		PrintX(Fichier,x,i);
	}
	fprintf(Fichier,"\n");
	int rec[15];
	int index=0;
	char equation[20];
	//FILE *ok = NULL;
	FILE *ok=fopen("test.txt","w");
	if(ok !=NULL){
		for(int j=1; j<5; j++)
			SaveX(ok,x,j);
		
	}
	fclose(ok);
	int res =0, j=0;
	int polyfinal[100];
	int dex =0;
	int p1[2];
	int p2[2];
	int p3[2];
	int p4[2];
	int second_degre[3];
	int troisieme_degre[4];
	int quatrieme_degre[5];
	ok = fopen("test.txt","r");
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		int res1[2];
		MULTIPLIER(2,diff[1],p1,res1);
		REMPLISTRUCT(2,PARTIE1,res1);
	}
	long position = ftell(ok);
	fseek(ok,position,SEEK_SET);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		dev2(p1,p2,second_degre);
		int res2[3];
		MULTIPLIER(3,diff[2],second_degre,res2);
		REMPLISTRUCT(3,PARTIE2,res2);
	}
	position = ftell(ok);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);	
		REMPLIR(0,1,0,NUMBER,p1);
		REMPLIR(0,3,2,NUMBER,p2);
		REMPLIR(0,5,4,NUMBER,p3);
		dev2(p1,p2,second_degre);
		dev3(second_degre,p3,troisieme_degre);
		int res3[4];
		MULTIPLIER(4,diff[3],troisieme_degre,res3);
		REMPLISTRUCT(4,PARTIE3,res3);
	}
	position = ftell(ok);
	if(fgets(equation,20,ok)!=NULL)
	{
		//printf("%s\n",equation);
		j =CountNumber(equation)+COUNTx(equation);
		//RECUP LES NOMBRES DE L'EQUATION
    	int NUMBER[j];
		RecupNumber(equation,NUMBER);	
		REMPLIR(0,1,0,NUMBER,p1);
		
		REMPLIR(0,3,2,NUMBER,p2);
	
		REMPLIR(0,5,4,NUMBER,p3);
		
		REMPLIR(0,7,6,NUMBER,p4);
		
		dev2(p1,p2,second_degre);
	
		dev3(second_degre,p3,troisieme_degre);
		
		dev4(troisieme_degre,p4,quatrieme_degre);
		
		int res4[5];
		MULTIPLIER(5,diff[4],quatrieme_degre,res4);
		
		REMPLISTRUCT(5,PARTIE4,res4);
	}
	fclose(ok);
	fprintf(Fichier,"Ainsi : \n\n");
	if(diff[0]!= 0){
		if(diff[0] < 0)
			fprintf(Fichier,"	P4(x) = %d - ",abs(diff[0]));
		else
			fprintf(Fichier,"	P4(x) = %d + ",diff[0]);}
	else 
		fprintf(Fichier,"	P4(x) = ");	
	printCoeff(Fichier,PARTIE1);
	if (PARTIE2->left[2] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE2);
	if (PARTIE3->left[3] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE3);
	if (PARTIE4->left[4] > 0)
		fprintf(Fichier," + ");
	printCoeff(Fichier,PARTIE4);
	fprintf(Fichier,"\n\n");
	cf->left[0]= diff[0]+PARTIE1->left[0]+PARTIE2->left[0]+PARTIE3->left[0]+PARTIE4->left[0];
	cf->left[1]=PARTIE1->left[1]+PARTIE2->left[1]+PARTIE3->left[1]+ PARTIE4->left[1];
	cf->left[2]= PARTIE2->left[2]+PARTIE3->left[2]+ PARTIE4->left[2];
	cf->left[3]=PARTIE3->left[3]+PARTIE4->left[3];
	cf->left[4] =PARTIE4->left[4];
	fprintf(Fichier,"On rassemble tout et on obtient : \n\n");
	fprintf(Fichier,"	P4(x) = ");	
	printCoeff(Fichier,cf);
	fprintf(Fichier,"\n");
	FreeCoeff(cf);
	FreeCoeff(PARTIE1);
	FreeCoeff(PARTIE2);
	FreeCoeff(PARTIE3);
	FreeCoeff(PARTIE4);
}
void interpolation_newton(int degre,FILE* file,int x[], int fx[])
{
	fprintf(file,"RAPPEL :\n\n");
	fprintf(file,"		Un polynôme de Newton s'écrit de cette façon :\n");
	fprintf(file,"								Pn(x) = f(x0) + f[x0,x1](x - x0) + f[x0,x1,x2](x - x0)(x - x1) + ....");
	fprintf(file," f[x0,_,xn](x - x0)--(x - x(n-1))\n \n");
	fprintf(file,"où pour tout k >=1 : \n");
	fprintf(file,"					f[x0,_,xk] = f[x1,_xk]-f[x0,_,x(k-1)] / xk -x0 et où f[xk] =f(xk)\n\n");
	fprintf(file,"1. Procédons d'abords par la construction du tableau des differences divisées aussi appelé arbre de Newton\n");
	int diff[4];
	int diff2[5];
	int fx0 = fx[0];
	diff[0] =fx0;
	diff2[0]=fx0;
	int size =degre +1;
	fprintf(file,"Tout d'abord les abcisses et les ordonnées données : \n\n");
	for(int i=0; i<size;i++)
	{
		fprintf(file,"x%d : %d   ",i,x[i]);
	}

	fprintf(file,"\n");
	for(int i=0; i<size;i++)
	{
		fprintf(file,"f(x%d) : %d  ",i,fx[i]);
	}
	fprintf(file,"\n\n");
	fprintf(file,"Les différences divisées : \n\n");
	if(degre ==3)
	{

		fprintf(file,"							f[x2,x3] = f(x3)-f(x2) / x3-x2\n");
		int fx2x3 = differences_divisees(file,x[2],x[3],fx[2],fx[3]);
		fprintf(file,"							f[x1,x2] = f(x2)-f(x1) / x2-x1\n");
		int fx1x2 = differences_divisees(file,x[1],x[2],fx[1],fx[2]);
		fprintf(file,"							f[x0,x1] = f(x1)-f(x0) / x1-x0\n");
		int fx0x1 = differences_divisees(file,x[0],x[1],fx[0],fx[1]);
		diff[1]=fx0x1;
		fprintf(file,"							f[x1,x2,x3] = f[x2,x3]-f[x1,x2] / x3-x1\n");
		int fx1x2x3 = differences_divisees(file,x[1],x[3],fx1x2,fx2x3);
		fprintf(file,"							f[x0,x1,x2] = f[x1,x2]-f[x0,x1] / x2-x0\n");
		int fx0x1x2 = differences_divisees(file,x[0],x[2],fx0x1,fx1x2);
		diff[2]=fx0x1x2;
		fprintf(file,"							f[x0,x1,x2,x3] = f[x1,x2,x3]-f[x0,x1,x2] / x3-x0\n");
		int fx0x1x2x3= differences_divisees(file,x[0],x[3],fx0x1x2,fx1x2x3);
		diff[3]= fx0x1x2x3;
		Poly_newton3(file,x,diff);
	}
	else if(degre ==2)
	{
		fprintf(file,"							f[x1,x2] = f(x2)-f(x1) / x2-x1\n");
		int fx1x2 = differences_divisees(file,x[1],x[2],fx[1],fx[2]);
		fprintf(file,"							f[x0,x1] = f(x1)-f(x0) / x1-x0\n");
		int fx0x1 = differences_divisees(file,x[0],x[1],fx[0],fx[1]);
		diff[1]=fx0x1;
		fprintf(file,"							f[x0,x1,x2] = f[x1,x2]-f[x0,x1] / x2-x0\n");
		int fx0x1x2 = differences_divisees(file,x[0],x[2],fx0x1,fx1x2);
		diff[2]=fx0x1x2;
		Poly_newton2(file,x,diff);
	}
	else if(degre == 4)
	{
		fprintf(file,"							f[x3,x4] = f(x4)-f(x3) / x4-x3\n");
		int fx3x4 = differences_divisees(file,x[3],x[4],fx[3],fx[4]);

		fprintf(file,"							f[x2,x3] = f(x3)-f(x2) / x3-x2\n");
		int fx2x3 = differences_divisees(file,x[2],x[3],fx[2],fx[3]);

		fprintf(file,"							f[x1,x2] = f(x2)-f(x1) / x2-x1\n");
		int fx1x2 = differences_divisees(file,x[1],x[2],fx[1],fx[2]);

		fprintf(file,"							f[x0,x1] = f(x1)-f(x0) / x1-x0\n");
		int fx0x1 = differences_divisees(file,x[0],x[1],fx[0],fx[1]);
		diff2[1]=fx0x1;

		fprintf(file,"							f[x2,x3,x4] = f[x3,x4]-f[x2,x3] / x4-x2\n");
		int fx2x3x4 = differences_divisees(file,x[2],x[4],fx2x3,fx3x4);

		fprintf(file,"							f[x1,x2,x3] = f[x2,x3]-f[x1,x2] / x3-x1\n");
		int fx1x2x3 = differences_divisees(file,x[1],x[3],fx1x2,fx2x3);

		fprintf(file,"							f[x0,x1,x2] = f[x1,x2]-f[x0,x1] / x2-x0\n");
		int fx0x1x2 = differences_divisees(file,x[0],x[2],fx0x1,fx1x2);
		diff2[2]=fx0x1x2;

		fprintf(file,"							f[x1,x2,x3,x4] = f[x2,x3,x4]-f[x1,x2,x3] / x4-x1\n");
		int fx1x2x3x4= differences_divisees(file,x[1],x[4],fx1x2x3,fx2x3x4);

		fprintf(file,"							f[x0,x1,x2,x3] = f[x1,x2,x3]-f[x0,x1,x2] / x3-x0\n");
		int fx0x1x2x3= differences_divisees(file,x[0],x[3],fx0x1x2,fx1x2x3);
		diff2[3]= fx0x1x2x3;

		fprintf(file,"							f[x0,x1,x2,x3,x4] = f[x1,x2,x3,x4]-f[x0,x1,x2,x3] / x4-x0\n");
		int fx0x1x2x3x4= differences_divisees(file,x[0],x[4],fx0x1x2x3,fx1x2x3x4);
		diff2[4] = fx0x1x2x3x4;
		Poly_newton4(file,x,diff2);
	}

}
/*void main(void)
{
	int x[4] = {-2,-1,0,1};
	int fx[4] = {-32,26,30,28};
	int x2[3] = {2,3,-1};
	int fx2[3] = {5,9,40};
	int x3[5] = {4,6,8,15,5};
	int fx3[5] = {2,12,33,28,25};
	FILE *file = NULL;
	//FILE *ok=NULL;
	file =fopen("interpolation_newton.txt","w");
	if(file !=NULL){
		fprintf(file," DEGRE 3 : \n");
		interpolation_newton(3,file,x,fx);
		fprintf(file, "DEGRE 2 : \n");
		interpolation_newton(2,file,x2,fx2);
		fprintf(file, "DEGRE 4 : \n");
		interpolation_newton(4,file,x3,fx3);
		fclose(file);
	}
}*/