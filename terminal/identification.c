# include "identification.h"

static void Printpositivity(int n) {
  if (n < 0)
    printf(" - %d", - n);
  else
    printf(" + %d", n);
}

static void printdegree(int n){
  if (n == 4)
    printf("X⁴");
  else if (n == 3)
    printf("X³");
  else if (n == 2)
    printf("X²");
  else if (n == 1)
    printf("X");
}

static void printCoeffs(struct coeff *cf) {
  
  int degreel = FindDegree(cf->left);
  int degreer = FindDegree(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    printf("          0 = ");
  else {
    printf("          %d", cf->left[degreel]);
    printdegree(degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(cf->left[degreel]);
        printdegree(degreel);
      }
      degreel--;
    }
    printf(" = ");
  }
  // Right Part 
  if (degreer == 0 && cf->right[0] == 0)
      printf("0 \n\n");
  else {
    printf("%d", cf->right[degreer]);
    printdegree(degreer);
    degreer--;
    while (degreer >= 0) {
      if (cf->right[degreer] != 0) {
        Printpositivity(cf->right[degreer]);
        printdegree(degreer);
      }
      degreer--;
    }
    printf("\n\n");
  }
}


struct coeff *Diff(struct coeff *cf) {
  printf("Afin de résoudre notre équation de la forme:\n\n");
  printCoeffs(cf);
  printf("Nous devons tout d'abord tout passer à gauche du égal afin de");
  printf(" faciliter la résolution de l'équation.\n");
  printf("Nous obtenons donc l'équation de la forme:\n\n");
  for (int i = 0; i < 5; i++) {
    cf->left[i] -= cf->right[i];
    cf->right[i] = 0;
  }
  printCoeffs(cf);
  printf("Nous pouvons maintenant passer à la résolution de l'équation.\n\n");
  return cf;
}

int FindDegree(int *tab) {
  int degree = 4;
  while(tab[degree] == 0 && degree > 0)
    degree--;
  return degree;
}

int FindNumber(char *str, char *nb) {
  int i = 0;
  while (*str >= '0' && *str <= '9') {
    nb[i] = *str;
    i++;
    str++;
  }
  return i;
}

struct coeff *PutExpression(char *str) {
  struct coeff *cf = malloc(sizeof(struct coeff));
  cf->left = calloc(5, sizeof(int));
  cf->right = calloc(5, sizeof(int));
  
  int l = 1;

  char *nb = calloc(42, sizeof(char));
  int signe = 1;
  if (*str == '-') {
    signe = -1;
    str++;
  } else if (*str == '+') str++;

  while(*str) {
    str += FindNumber(str, nb);
    if (!l && !*str) break;
    str += 2;
    if (l) cf->left[*str - '0'] = atoi(nb) * signe;
    else cf->right[*str - '0'] = atoi(nb) * signe;
    free(nb);
    nb = calloc(42, sizeof(char));
    str++;
    if (*str == '+') {
      signe = 1;
      str++;
    }
    else if (*str == '-') {
      signe = -1;
      str++;
    }
    else if (*str == '=') {
      l = 0;
      str++;
      signe = 1;
      if (*str == '-') {
        signe = -1;
        str++;
      } else if (*str == '+') str++;
    }
  }
  return cf;
}

void FreeCoeff(struct coeff*cf) {
  free(cf->right);
  free(cf->left);
  free(cf);
}

void printcoeff(struct coeff *cf) {
  printf("cf->left = [ ");
  for (int i = 0; i < 5; ++i)
    printf("%d ", cf->left[i]);
  printf("]\ncf->right = [ ");
  for (int i = 0; i < 5; ++i)
    printf("%d ", cf->right[i]);
  printf("]\n");
}
