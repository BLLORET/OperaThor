# include "complex.h"

static void Print_Complex0f(FILE *file, struct Complex *comp) {
  if (comp->real == 0 && comp->img == 0) {
  	fprintf(file, "0 ");
  } else {
    if (comp->real != 0)
      fprintf(file, "%.0f ", comp->real);
    if (comp->img < 0) {
  	  if (comp->img == -1)
  	    fprintf(file, "- i ");
  	  else
  	    fprintf(file, "- %.0f i ", -comp->img);
    } else if (comp->img > 0) {
  	  if (comp->img == 1)
  	    fprintf(file, "+ i ");
  	  else
  	    fprintf(file, "+ %.0f i ", comp->img);
    }
  }
}

static void Print_Complex(FILE *file, struct Complex *comp) {
  if (comp->real == 0 && comp->img == 0) {
  	fprintf(file, "0 ");
  } else {
    if (comp->real != 0)
      fprintf(file, "%.3f ", comp->real);
    if (comp->img < 0) {
  	  if (comp->img == -1)
  	    fprintf(file, "- i ");
  	  else
  	    fprintf(file, "- %.3f i ", -comp->img);
    } else if (comp->img > 0) {
  	  if (comp->img == 1)
  	    fprintf(file, "+ i ");
  	  else
  	    fprintf(file, "+ %.3f i ", comp->img);
    }
  }
}

static struct Complex *add_comp(struct Complex *a, struct Complex *b) {
  struct Complex *res = malloc(sizeof(struct Complex));
  res->real = a->real + b->real;
  res->img = a->img + b->img;
  return res;
}

static struct Complex *mult_comp(struct Complex *a, struct Complex *b) {
	struct Complex *res = malloc(sizeof(struct Complex));
	res->real = a->real * b->real - a->img * b->img;
	res ->img = a->real * b->img + b->real * a->img;
	return res;
}

static struct Complex *conjugue(struct Complex *a) {
  struct Complex *b = malloc(sizeof(struct Complex));
  b->real = a->real;
  b->img = -a->img;
  return b;
}

static struct Complex *div_comp(FILE *file, struct Complex *a, struct Complex *b) {
  fprintf(file, "                ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") / ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ( ");
  struct Complex *conj = conjugue(b);
  struct Complex *res = mult_comp(a, conj);
  Print_Complex0f(file, a);
  fprintf(file, ")( ");
  Print_Complex0f(file, conj);
  fprintf(file, ") / (");
  Print_Complex0f(file, b);
  fprintf(file, ")(");
  Print_Complex0f(file, conj);
  fprintf(file, ")\n\n");
  fprintf(file, "                ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") / ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ( ");
  Print_Complex0f(file, res);
  fprintf(file, ") / (%.0f² + ", b->real);
  if (b->img < 0)
    fprintf(file, "%.0f²)\n\n", -b->img);
  else
    fprintf(file, "%.0f²)\n\n", b->img);
  struct Complex *deno = mult_comp(b, conj);
  float den = deno->real;
  free(deno);
  fprintf(file, "                ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") / ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ( ");
  Print_Complex0f(file, res);
  fprintf(file, ") / %.0f\n\n", den);
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

void Addition(FILE *file, struct Complex *a, struct Complex *b) {
  fprintf(file, "Afin d'additionner deux nombres complexes de la forme a + bi où i est\n");
  fprintf(file, "la marque de l'imaginaire, il suffit d'additionner ensemble les réels\n");
  fprintf (file, "qui sont à la place du a et les imaginaires à la place du b ensemble.\n\n");
  fprintf(file, "       Ainsi nous avons ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") + ( ");
  Print_Complex0f(file, b);
  struct Complex *res = add_comp(a, b);
  fprintf(file, ") = ");
  Print_Complex0f(file, res);
  fprintf(file, "\n\n");
  free(a);
  free(b);
  free(res);
}

void Soustration(FILE *file, struct Complex *a, struct Complex *b) {
  fprintf(file, "Afin de soustraire deux nombres complexes de la forme a + bi où i est\n");
  fprintf(file, "la marque de l'imaginaire, il suffit de soustraire ensemble les réels\n");
  fprintf(file, "qui sont à la place du a et les imaginaires à la place du b ensemble.\n\n");
  fprintf(file, "       Ainsi nous avons ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") - ( ");
  Print_Complex0f(file, b);
  b->img *= -1;
  b->real *= -1;
  struct Complex *res = add_comp(a, b);
  fprintf(file, ") = ");
  Print_Complex0f(file, res);
  fprintf(file, "\n\n");
  free(a);
  free(b);
  free(res);
}

static void Print_parenth(FILE *file, float n) {
  if (n < 0)
  	fprintf(file, "(%0.f)", n);
  else
  	fprintf(file, "%0.f", n);
}

static void PrintMulInt1(FILE *file, struct Complex *a, struct Complex *b) {
  // a * c
  fprintf(file, "%0.f * ", a->real);
  Print_parenth(file, b->real);
  // + a * d * i
  fprintf(file, " + (%0.f * ", a->real);
  Print_parenth(file, b->img);
  
  // + b * c * i
  fprintf(file, ") i + (%0.f * ", a->img);
  Print_parenth(file, b->real);
  // + (b * d) i²
  fprintf(file, ") i + (%0.f * ", a->img);
  Print_parenth(file, b->img);
  fprintf(file, ") i²");
}

static void PrintMulInt2(FILE *file, struct Complex *a, struct Complex *b) {
  // a * c
  fprintf(file, "%0.f * ", a->real);
  Print_parenth(file, b->real);
  // - (b * d)
  fprintf(file, " - (%0.f * ", a->img);
  Print_parenth(file, b->img);
  // + a * d * i
  fprintf(file, ") + (%0.f * ", a->real);
  Print_parenth(file, b->img);
  // + b * c * i
  fprintf(file, ") i + (%0.f * ", a->img);
  Print_parenth(file, b->real);
  fprintf(file, ") i");
}

static void PrintMulInt3(FILE *file, struct Complex *a, struct Complex *b) {
  // a * c
  fprintf(file, "%0.f ", a->real* b->real);
  // - (b * d)
  float ret = a->img * b->img;
  if (ret < 0)
    fprintf(file, " + %0.f ", -ret);
  else
  	fprintf(file, "- %0.f ", ret);
  // + a * d * i
  ret = a->real * b->img;
  if (ret < 0)
    fprintf(file, " - %0.f i ", -ret);
  else
  	fprintf(file, "+ %0.f i ", ret);
  // + b * c * i
  ret = a->img * b->real;
  if (ret < 0)
    fprintf(file, " - %0.f i", -ret);
  else
  	fprintf(file, "+ %0.f i", ret);
}

void Multiplication(FILE *file, struct Complex *a, struct Complex *b) {
  fprintf(file, "Afin de multiplier deux nombres complexes de la forme a + bi où i est\n");
  fprintf(file, "la marque de l'imaginaire, il suffit d'appliquer la formule de la \n");
  fprintf(file, "distributivité.\n");
  fprintf(file, "                      Ainsi (a + bi) * (c + di) = ac + (ad)i + (bc)i + (bd)i²\n\n");
  fprintf(file, "Et comme i² = -1 nous avons (a + bi) * (c + di) = ac - (bd) + (ad)i + (bc)i\n\n\n");
  fprintf(file, "       Ainsi nous avons ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") * ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ");
  PrintMulInt1(file, a, b);
  fprintf(file, "\n\n                        Or comme i² = -1 on a:\n\n                        ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") * ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ");
  PrintMulInt2(file, a, b);
  fprintf(file, "\n\n                        ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") * ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ");
  PrintMulInt3(file, a, b);
  fprintf(file, "\n\n                        ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") * ( ");
  Print_Complex0f(file, b);
  struct Complex *res = mult_comp(a, b);
  fprintf(file, ") = ");
  Print_Complex0f(file, res);
  fprintf(file, "\n\n");
  free(a);
  free(b);
  free(res);
}

void Division(FILE *file, struct Complex *a, struct Complex *b) {
  fprintf(file, "Afin de diviser deux nombres complexes de la forme a + bi où i est\n");
  fprintf(file, "la marque de l'imaginaire, nous allons utiliser la méthode du conjugué.\n");
  fprintf(file, "Par exemble le conjugué de a + bi est a - bi. Nous allons multiplier le\n");
  fprintf(file, "numérateur par le conjugué afin d'obtenir un complexe. Le dénominateur\n");
  fprintf(file, "sera lui aussi multiplié par son conjugué afin d'obtenir un dénominateur\n");
  fprintf(file, "réel. Il ne manque plus qu'a diviser a et b par le dénominateur pour\n");
  fprintf(file, "obtenir leurs véritables valeurs.\n");
  fprintf(file, "                      Ainsi (a + bi) / (c + di) = (a + bi)(c - di) / (c + di)(c - di)\n\n");
  fprintf(file, "Et comme multiplié un nombre complexe par son conjugué revient à additionner\n");
  fprintf(file, "les carrés de a et de b, nous avons (a + bi) * (c + di) = (a + bi)(c - di) / c² + d²\n\n\n");
  fprintf(file, "Dans notre cas nous avons \n\n");
  struct Complex *res = div_comp(file, a, b);
  fprintf(file, "                ( ");
  Print_Complex0f(file, a);
  fprintf(file, ") / ( ");
  Print_Complex0f(file, b);
  fprintf(file, ") = ");
  Print_Complex(file, res);
  fprintf(file, "\n\n");
  free(a);
  free(b);
  free(res);
}

int main(int argc, char const *argv[])
{
	
  struct Complex *a = malloc(sizeof(struct Complex));
  a->real = 5;
  a->img = 3;
  struct Complex *b = malloc(sizeof(struct Complex));
  b->real = 7;
  b->img = -5;
  //Addition(a, b);
  //Soustration(a, b);
  //Multiplication(a, b);
  Division(a, b);
  return 0;
}