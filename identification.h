# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <err.h>
# include <string.h>
# include <fcntl.h>

struct coeff {
  int *left;
  int *right;
};

int FindDegree(int *tab);

int FindNumber(char *str, char *nb);

struct coeff *PutExpression(char *str);

void printcoeff(struct coeff *cf);

void FreeCoeff(struct coeff *cf);
