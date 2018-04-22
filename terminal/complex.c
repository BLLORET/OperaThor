# include <stdio.h>
# include <stdlib.h>
# include <math.h>

struct Complex {
  float real;
  float img;
};

void Print_Complex(struct Complex *comp) {
  if (comp->real != 0)
    printf("%.1f ", comp->real);
  if (comp->img < 0)
    printf("- %.1f i ", -comp->img);
  else if (comp->img > 0)
    printf("+ %.1f i ", comp->img);
}

struct Complex *add_comp(struct Complex *a, struct Complex *b) {
  struct Complex *res = malloc(sizeof(struct Complex));
  res->real = a->real + b->real;
  res->img = a->img + b->img;
  return res;
}

struct Complex *mult_comp(struct Complex *a, struct Complex *b) {
	struct Complex *res = malloc(sizeof(struct Complex));
	res->real = a->real * b->real - a->img * b->img;
	res ->img = a->real * b->img + b->real * a->img;
	return res;
}

struct Complex *conjugue(struct Complex *a) {
  struct Complex *b = malloc(sizeof(struct Complex));
  b->real = a->real;
  b->img = -a->img;
  return b;
}

float Module(struct Complex *a) {
  return sqrtf(a->real * a->real + a->img * a->img);
}

float Im(struct Complex *a) {
  return a->img;
}

float Re(struct Complex *a) {
  return a->real;
}

int main(int argc, char const *argv[])
{
	
  struct Complex *a = malloc(sizeof(struct Complex));
  a->real = 5;
  a->img = 3;
  struct Complex *b = conjugue(a);
  Print_Complex(a);
  printf("\n");
  Print_Complex(b);
  printf("\n");
  struct Complex *res = add_comp(a, b);
  Print_Complex(res);
  printf("\n");
  res = mult_comp(a, b);
  Print_Complex(res);
  printf("\n");
  return 0;
}