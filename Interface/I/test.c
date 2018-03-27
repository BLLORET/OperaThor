#include <stdio.h>
#include <err.h>
#include <string.h>

/*static int res[]= {
  0, 0, 0,
  0, 0, 0,
  0, 0, 0
};*/
static int res[] ={};
void Make_matrix(int Matrice[], int elm[])
{
	for(int i =0; i <9;i++)
	{
				Matrice[i]=elm[i];
	}
}
static void printx(int mat[], int lines, int cols)
{
	
	for(int i=0; i< lines; i++)
	{ printf("[");
		for(int j=0; j< cols; j++)
		{
			printf("%4d", mat[j+i*cols]);
		}
		printf("]\n");
	}	
}
int main(void)
{
	int elm[9]= {1,2,3,4,5,6,7,8,9};
	Make_matrix(res,elm);
	printx(res,3,3);
}
