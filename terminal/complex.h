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

void Addition(struct Complex *a, struct Complex *b);

void Soustration(struct Complex *a, struct Complex *b);

void Multiplication(struct Complex *a, struct Complex *b);

void Division(struct Complex *a, struct Complex *b);