#include <stdio.h>
#include <err.h>
#include <string.h>
#include "matrice.h"

static void transpose(int mat[], int lines, int cols, int res[])
{
	for(int i=0; i<lines;i++ )
	{
		for(int j=0;j<cols;j++)
		{
			int c= j+i*cols;
			int l= i+j*lines;
			res[l]=mat[c];
		}
	}
} 
static void add(int mat1[], int mat2[], int lines, int cols, int res[])
{	
	for(int i=0; i<lines;i++)
	{
		for(int j=0;j<cols;j++)
		{
			int c= j+i*cols;
			res[c]= mat1[c]+mat2[c];
		}
	}
}

static void sub(int mat1[], int mat2[], int lines, int cols, int res[])
{	
	for(int i=0; i<lines;i++)
	{
		for(int j=0;j<cols;j++)
		{
			int c= j+i*cols;
			res[c]= mat1[c]-mat2[c];
		}
	}
}

static void mul(int m1[], int m2[],int n, int m, int p, int res[])
{
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<p;j++)
		{
			int sum=0;
			for(int k=0; k<m;k++)
			{
				sum+= m1[k+i*m]*m2[j+k*p];
				res[j+i*n]= sum;
			
			}
		}
	}
}
static void print_matrix(FILE* file,int mat[], int lines, int cols)
{
	
	for(int i=0; i< lines; i++)
	{ fprintf(file,"[");
		for(int j=0; j< cols; j++)
		{
			fprintf(file,"%4d", mat[j+i*cols]);
		}
		fprintf(file,"]\n");
	}	
}
static int resT[]= {
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0
};

void PMatrix(FILE* file,int mat1[],int mat2[],int res[],char* fonction)
{
	int lines =3;
	int cols= 3;
	if(strncmp(fonction,"addition",8)== 0)
	{
		fprintf(file,"soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
		fprintf(file,"La somme de deux matrices de type (m, n), A = (a(i,j))");
		fprintf(file," et B = (b(i,j)), notée A + B, est à nouveau une matrice");
		fprintf(file," (c(i,j)) de type (m, n) obtenue en additionnant les");
		fprintf(file," éléments correspondants :\n");
		fprintf(file,"			=> c(i,j) = a(i,j) + b(i,j)\n");
		fprintf(file,"			Donc: \n");
		fprintf(file," 					pour :\n");
		fprintf(file,"A  =\n");
		print_matrix(file,mat1, lines, cols);
		fprintf(file,"B =\n");
		print_matrix(file,mat2, lines, cols);
		fprintf(file,"RESULTAT : \n");
		fprintf(file," C=\n");
	  add(mat1,mat2,lines,cols, res);
		print_matrix(file,res,lines,cols);
	}
	
	if(strncmp(fonction,"soustraction",12)==0)
	{
		fprintf(file,"soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
		fprintf(file,"La somme de deux matrices de type (m, n), A = (a(i,j))");
		fprintf(file," et B = (b(i,j)), notée A - B, est à nouveau une matrice");
		fprintf(file," (c(i,j)) de type (m, n) obtenue en additionnant les");
		fprintf(file," éléments correspondants :\n");
		fprintf(file,"			=> c(i,j) = a(i,j) - b(i,j)\n");
		fprintf(file,"						Donc: \n ");
		fprintf(file," 							pour :\n");
		fprintf(file,"A  =\n");
		print_matrix(file,mat1, lines, cols);
		fprintf(file,"B =\n");
		print_matrix(file,mat2, lines, cols);
		fprintf(file,"RESULTAT : \n");
		fprintf(file," C=\n");
		sub(mat1,mat2,lines,cols,res);
		print_matrix(file,res,lines,cols);
	}
	if(strncmp(fonction,"transpose",9)==0)
	{
		fprintf(file,"La transposée d'une matrice A de type (m,n) notée At du type");
		fprintf(file," (n,m) est obtenue en échangeant les lignes et ");
		fprintf(file,"les colonnes de A \n");
		fprintf(file,"			=> Si B = At alors : b(i,j) = a(j,i)\n");
		fprintf(file,"			Donc : \n ");
		fprintf(file," 				pour : \n");
		fprintf(file,"A =\n");
		print_matrix(file,mat1,lines,cols);
		fprintf(file,"RESULTAT :\n");
		fprintf(file," At =\n");
		transpose(mat1,lines,cols,res);
		print_matrix(file,res,lines,cols);
		fprintf(file," 				et pour : \n");
		fprintf(file,"B =\n");
		print_matrix(file,mat2,lines,cols);
		fprintf(file,"RESULTAT :\n");
		fprintf(file," Bt =\n");
		transpose(mat2,lines,cols,resT);
		print_matrix(file,resT,lines,cols);
		
	}
	if(strncmp(fonction,"multiplication",14)==0)
	{
		fprintf(file,"Si A = (a(i,j)) est une matrice de type (m,n) et B = (b(i,j))");
		fprintf(file,"est une matrice de type (n,p), alors leur produit, ");
	  fprintf(file,"noté A*B = (c(i,j)) est une matrice de type (m,p) donnée par :\n");
	  fprintf(file,"soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
	  fprintf(file," c(i,j) = SOMME( de 1 à n) a(i,k)*b(k,j)\n");
	  fprintf(file,"Autrement dit : c(i,j)= a(i,1)*b(j,1) + a(i,2)*b(2,j)+ ... + ");
	  fprintf(file,"a(i,n)*b(n,j)\n");
	  fprintf(file,"EXEMPLE : \n ");
	  fprintf(file,"			Nous allons multiplier ces deux matrices :\n");
	  fprintf(file,"A =\n");
	  print_matrix(file,mat1,lines,cols);
	  fprintf(file,"B =\n");
	  print_matrix(file,mat2,lines,cols);
	 	fprintf(file,"RESULTAT : \n ");
	 	fprintf(file,"C =\n");
	  mul(mat1,mat2,cols,lines,cols,res);
    print_matrix(file,res,lines,cols);
	}
}
