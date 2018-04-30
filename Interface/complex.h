# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//#define _DEFAULT_SOURCE

struct Complex {
  float real;
  float img;
};

float Im(struct Complex *a);

float Re(struct Complex *a);

void Addition(FILE *file, struct Complex *a, struct Complex *b);

void Soustration(FILE *file, struct Complex *a, struct Complex *b);

void Multiplication(FILE *file, struct Complex *a, struct Complex *b);

void Division(FILE *file, struct Complex *a, struct Complex *b);