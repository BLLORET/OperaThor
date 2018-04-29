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

struct coeff *Diff(FILE* file,struct coeff *cf);

int FindDegree(int *tab);

int FindNumber(char *str, char *nb);

//void Printpositivity(FILE* file,int n);

//void printdegree(FILE* file,int n);

void FreeCoeff(struct coeff *cf);
