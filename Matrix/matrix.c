#include <stdio.h>
#include <err.h>
#include <string.h>

#define lines1 3
#define cols1  4
 
double add1[] = {
  1.0, 2.0, 3.0, 4.0,
  5.0, 6.0, 7.0, 8.0,
  9.0, 10.0, 11.0, 12.0
};
double add2[] = {
  4.0, 3.0, 12.0, 2.0,
  8.0, 9.0, 4.0, 8.0,
  11.0, 5.0, 7.0, 1.0
};
 
#define lines2 4
#define cols2  3

 
double sub1[] = {
  3.0, 7.0, 4.0,
  5.0, 6.0, 19.0,
  8.0, 14.0, 0.0,
  18.0, 1.0, 5.0
};
 
double sub2[] = {
  1.0, 2.0, 3.0,
  4.0, 5.0, 6.0,
  7.0, 8.0, 9.0,
  10.0, 11.0, 12.0
};
 
#define lines3 3
#define cols3  3
double m3[] = {
  1, 2, 3,
  4, 5, 6,
  7, 8, 9
};
 
double id[] = {
  1.0, 0.0, 0.0,
  0.0, 1.0, 0.0,
  0.0, 0.0, 1.0
};

double resT[]= {
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0
};

double resA[]= {
  0.0, 0.0, 0.0,0.0,
  0.0, 0.0, 0.0,0.0,
  0.0, 0.0, 0.0,0.0
};
double resB[]= {
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0,
  0.0, 0.0, 0.0,
  0.0,0.0,0.0,
};

double resM[]= {
  0.0, 0.0,0.0,0.0,
  0.0, 0.0,0.0,0.0,
  0.0,0.0,0.0,0.0,
  0.0,0.0,0.0,0.0
};
double testwiki[]= {
	1.0, 2.0,
	3.0, 4.0,
	5.0, 6.0
	};
	
double matrixmul[]= {
	1.0, 4.0,
	2.0, 3.0,
	3.0, 2.0,
	4.0, 1.0
	};
double matrixmul2[]= {
	1.0, 2.0, 3.0, 4.0,
	4.0, 3.0, 2.0, 1.0
	};


/*
 * transpose(mat, lines, cols, res)
 * transpose the lines X cols matrix mat into a cols X lines matrix
 * result will be stored in res
 */
void transpose(double mat[], size_t lines, size_t cols, double res[])
{
	for(size_t i=0; i<lines;i++ )
	{
		for(size_t j=0;j<cols;j++)
		{
			size_t c= j+i*cols;
			size_t l= i+j*lines;
			res[l]=mat[c];
		}
	}
} 
/*
 * add(mat1, mat2, lines, cols, res)
 * computes res = mat1 + mat2
 * All 3 matrices have the form lines X cols
 */
void add(double mat1[], double mat2[], size_t lines, size_t cols, double res[])
{	
	for(size_t i=0; i<lines;i++)
	{
		for(size_t j=0;j<cols;j++)
		{
			size_t c= j+i*cols;
			res[c]= mat1[c]+mat2[c];
		}
	}
}

void sub(double mat1[], double mat2[], size_t lines, size_t cols, double res[])
{	
	for(size_t i=0; i<lines;i++)
	{
		for(size_t j=0;j<cols;j++)
		{
			size_t c= j+i*cols;
			res[c]= mat1[c]-mat2[c];
		}
	}
}
 
/*
 * mul(m1, m2, n, m, p, res)
 * computes res = m1 * m2
 * Where:
 *        m1 is a n X m matrix
 *        m2 is a m X p matrix
 *        res is a n X p matrix
 */
void mul(double m1[], double m2[], size_t n, size_t m, size_t p, double res[])
{
	for(size_t i=0; i<n;i++)
	{
		for(size_t j=0; j<p;j++)
		{
			size_t sum=0;
			for(size_t k=0; k<m;k++)
			{
				sum+= m1[k+i*m]*m2[j+k*p];
				res[j+i*n]= sum;
			
			}
		}
	}
}
 
/*
 * print_matrix(mat, lines, cols)
 * prints the lines X cols matrix mat
 * All coeficient will be printed using the format " %4g ", line by line
 */
void print_matrix(double mat[], size_t lines, size_t cols)
{
	
	for(size_t i=0; i< lines; i++)
	{ printf("[");
		for(size_t j=0; j< cols; j++)
		{
			printf("%4g", mat[j+i*cols]);
		}
		printf("]\n");
	}	
}
void Print_Matrix(char* fonction)
{
	if(strncmp(fonction,"addition",8)== 0)
	{
		printf("soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
		printf("La somme de deux matrices de type (m, n), A = (a(i,j))");
		printf(" et B = (b(i,j)), notée A + B, est à nouveau une matrice");
		printf(" (c(i,j)) de type (m, n) obtenue en additionnant les");
		printf(" éléments correspondants :\n");
		printf("			=> c(i,j) = a(i,j) + b(i,j)\n");
		printf("EXEMPLE: \n");
		printf(" 		pour :\n");
		printf("A  =\n");
		print_matrix(add1, lines1, cols1);
		printf("B =\n");
		print_matrix(add2, lines1, cols1);
		printf("RESULTAT : \n");
		printf(" C=\n");
		add(add1,add2,3,4, resA);
		print_matrix(resA,3,4);
	}
	
	if(strncmp(fonction,"soustraction",12)==0)
	{
		printf("soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
		printf("La somme de deux matrices de type (m, n), A = (a(i,j))");
		printf(" et B = (b(i,j)), notée A - B, est à nouveau une matrice");
		printf(" (c(i,j)) de type (m, n) obtenue en additionnant les");
		printf(" éléments correspondants :\n");
		printf("			=> c(i,j) = a(i,j) - b(i,j)\n");
		printf("EXEMPLE: \n ");
		printf(" 		pour :\n");
		printf("A  =\n");
		print_matrix(sub1, lines2, cols2);
		printf("B =\n");
		print_matrix(sub2, lines2, cols2);
		printf("RESULTAT : \n");
		printf(" C=\n");
		sub(sub1,sub2,4,3,resB);
		print_matrix(resB,4,3);
	}
	if(strncmp(fonction,"transpose",9)==0)
	{
		printf("La transposée d'une matrice A de type (m,n) notée At du type");
		printf(" (n,m) est obtenue en échangeant les lignes et ");
		printf("les colonnes de A \n");
		printf("			=> Si B = At alors : b(i,j) = a(j,i)\n");
		printf("EXEMPLE : \n ");
		printf(" 		pour : \n");
		printf("A =\n");
		print_matrix(testwiki,3,2);
		printf("RESULTAT :\n");
		printf(" At =\n");
		transpose(testwiki,3,2,resT);
		print_matrix(resT,2,3);
	}
	if(strncmp(fonction,"multiplication",14)==0)
	{
		printf("Si A = (a(i,j)) est une matrice de type (m,n) et B = (b(i,j))");
		printf("est une matrice de type (n,p), alors leur produit, ");
	  printf("noté A*B = (c(i,j)) est une matrice de type (m,p) donnée par :\n");
	  printf("soit i le nombre de lignes et j le nombre de colonnes, alors :\n");
	  printf(" c(i,j) = SOMME( de 1 à n) a(i,k)*b(k,j)\n");
	  printf("Autrement dit : c(i,j)= a(i,1)*b(j,1) + a(i,2)*b(2,j)+ ... + ");
	  printf("a(i,n)*b(n,j)\n");
	  printf("EXEMPLE : \n ");
	  printf("			Nous allons multiplier ces deux matrices :\n");
	  printf("A =\n");
	  print_matrix(matrixmul,4,2);
	  printf("B =\n");
	  print_matrix(matrixmul2,2,4);
	 	printf("RESULTAT : \n ");
	 	printf("C =\n");
	  mul(matrixmul,matrixmul2,4,2,4,resM);
    print_matrix(resM,4,4);
	}
}
int main(int argc, char** argv)
{
	if(argc < 2){
		printf("Opérations svp\n");
		printf("			=> addition \n");
		printf("			=> soustraction \n");
		printf("			=> transposer\n");
		printf("			=> multiplication\n");
		return 0;
	}
	printf("Voici quelques exemples d application de l addition,");
	printf("multiplication,transpose de matrices\n");
	Print_Matrix(argv[1]);
}
