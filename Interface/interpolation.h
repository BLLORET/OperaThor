#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Coeff {
  float *left;
  float *right;
};
/*struct coeff {
  int *left;
  int *right;
};*/
void interpolation_polynomiale_2(FILE* file,int x[], int fx[], int degre);
void interpolation_polynomiale_3(FILE* file,int x[], int fx[], int degre);
void interpolation_polynomiale_4(FILE* file,int x[], int fx[], int degre);
