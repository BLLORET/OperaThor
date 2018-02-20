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

int FindDegree(int *tab) {
  int degree = 4;
  while(tab[degree] != 0)
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


static void print(struct coeff *cf) {
  printf("[ ");
  for (int i = 0; i < 5; ++i)
    printf("%d; ", cf->left[i]);
  printf("]\n[ ");
  for (int i = 0; i < 5; ++i)
    printf("%d; ", cf->right[i]);
  printf("]\n");
}
int main(int argc, char *argv[]) {
  if (argc < 2) errx(1 ,"Missing arguments");
  if (argc > 2) errx(1 ,"Too much arguments");
  
  struct coeff *cf = PutExpression(argv[1] /*"-4X^2-2X^1+3X^0=3X^2+2X^1-2X^0"*/);
  print(cf);
  free(cf->right);
  free(cf->left);
  free(cf);

  return 0;
}