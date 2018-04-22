# include <stdio.h>
# include <stdlib.h>
# include <math.h>

//#define _DEFAULT_SOURCE

struct Complex {
  float real;
  float img;
};

void Print_Complex0f(struct Complex *comp) {
  if (comp->real == 0 && comp->img == 0) {
  	printf("0 ");
  } else {
    if (comp->real != 0)
      printf("%.0f ", comp->real);
    if (comp->img < 0) {
  	  if (comp->img == -1)
  	    printf("- i ");
  	  else
  	    printf("- %.0f i ", -comp->img);
    } else if (comp->img > 0) {
  	  if (comp->img == 1)
  	    printf("+ i ");
  	  else
  	    printf("+ %.0f i ", comp->img);
    }
  }
}

void Print_Complex(struct Complex *comp) {
  if (comp->real == 0 && comp->img == 0) {
  	printf("0 ");
  } else {
    if (comp->real != 0)
      printf("%.3f ", comp->real);
    if (comp->img < 0) {
  	  if (comp->img == -1)
  	    printf("- i ");
  	  else
  	    printf("- %.3f i ", -comp->img);
    } else if (comp->img > 0) {
  	  if (comp->img == 1)
  	    printf("+ i ");
  	  else
  	    printf("+ %.3f i ", comp->img);
    }
  }
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

struct Complex *div_comp(struct Complex *a, struct Complex *b) {
  struct Complex *conj = conjugue(b);
  struct Complex *deno = mult_comp(b, conj);
  float den = deno->real;
  free(deno);
  struct Complex *res = mult_comp(a, conj);
  free(conj);
  res->real /= den;
  res->img /= den; 
  return res;
}

/*float Module(struct Complex *a) {
  return sqrt(a->real * a->real + a->img * a->img);
}*/

float Im(struct Complex *a) {
  return a->img;
}

float Re(struct Complex *a) {
  return a->real;
}

void Addition(struct Complex *a, struct Complex *b) {
  printf("Afin d'additionner deux nombres complexes de la forme a + bi où i est\n");
  printf("la marque de l'imaginaire, il suffit d'additionner ensemble les réels\n");
  printf ("qui sont à la place du a et les imaginaires à la place du b ensemble.\n\n");
  printf("       Ainsi nous avons ( ");
  Print_Complex0f(a);
  printf(") + ( ");
  Print_Complex0f(b);
  struct Complex *res = add_comp(a, b);
  printf(") = ");
  Print_Complex0f(res);
  printf("\n\n");
  free(a);
  free(b);
  free(res);
}

void Soustration(struct Complex *a, struct Complex *b) {
  printf("Afin de soustraire deux nombres complexes de la forme a + bi où i est\n");
  printf("la marque de l'imaginaire, il suffit de soustraire ensemble les réels\n");
  printf ("qui sont à la place du a et les imaginaires à la place du b ensemble.\n\n");
  printf("       Ainsi nous avons ( ");
  Print_Complex0f(a);
  printf(") - ( ");
  Print_Complex0f(b);
  b->img *= -1;
  b->real *= -1;
  struct Complex *res = add_comp(a, b);
  printf(") = ");
  Print_Complex0f(res);
  printf("\n\n");
  free(a);
  free(b);
  free(res);
}

void PrintMulInt2(struct Complex *a, struct Complex *b) {
  // a * c
  printf("%0.f * ", a->real);
  if (b->real < 0)
  	printf("(%0.f)", b->real);
  else
  	printf("%0.f", b->real);
  // - (b * d)
  printf(" - (%0.f * ", a->img);
  if (b->img < 0)
  	printf("(%0.f)", b->img);
  else
  	printf("%0.f", b->img);
  // + a * d * i
  printf(") + ( %0.f * ", a->real);
  if (b->img < 0)
  	printf("(%0.f)", b->img);
  else
  	printf("%0.f", b->img);

}

void Multiplication(struct Complex *a, struct Complex *b) {
  printf("Afin de multiplier deux nombres complexes de la forme a + bi où i est\n");
  printf("la marque de l'imaginaire, il suffit d'appliquer la formule de la \n");
  printf("distributivité.\n");
  printf("                      Ainsi (a + bi) * (c + di) = ac + (ad)i + (bc)i + (bd)i²\n\n");
  printf ("Et comme i² = -1 nous avons (a + bi) * (c + di) = ac - (bd) + (ad)i + (bc)i\n\n\n");
  printf("       Ainsi nous avons ( ");
  Print_Complex0f(a);
  printf(") * ( ");
  Print_Complex0f(b);
  printf(") = ");
  PrintMulInt2(a, b);
  printf("\n\n                        ( ");
  Print_Complex0f(a);
  printf(") * ( ");
  Print_Complex0f(b);
  struct Complex *res = mult_comp(a, b);
  printf(") = ");
  Print_Complex0f(res);
  printf("\n\n");
  free(a);
  free(b);
  free(res);
}

int main(int argc, char const *argv[])
{
	
  struct Complex *a = malloc(sizeof(struct Complex));
  a->real = 5;
  a->img = 3;
  /*struct Complex *b = conjugue(a);
  Print_Complex(a);
  printf("\n");
  Print_Complex(b);
  printf("\n");
  struct Complex *res = add_comp(a, b);
  Print_Complex(res);
  printf("\n");
  free(res);
  res = mult_comp(a, b);
  Print_Complex(res);
  printf("\n");
  free(res);
  res = div_comp(a, b);
  Print_Complex(res);
  printf("\n");
  free(a);
  free(b);
  free(res);*/
  struct Complex *b = malloc(sizeof(struct Complex));
  b->real = 7;
  b->img = -5;
  //Addition(a, b);
  //Soustration(a, b);
  Multiplication(a, b);
  return 0;
}