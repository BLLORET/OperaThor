# include "identification.h"

int FindDegree(int *tab) {
  int degree = 4;
  while(tab[degree] == 0)
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
