# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <err.h>
# include <string.h>
# include <fcntl.h>

struct coeff {
  int left[5];
  int right[5];
};

int CharToInt(char *str) {
  int n = 0;
  int d = 1;
  while (*str) {
    n = n * d + (*str - '0');
    d *= 10;
    str++;
  }
  return n;
}

int[] FillZero() {
  int coeff[5];
  for (int i = 0, i < 5, i++)
    coeff[i] = 0;
  return coeff;
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

struct coeff PutExpression(char *str) {
  struct coeff cf;
  cf.left = FillZero();
  cf.right = FillZero();
  
  int l = 1;

  char *nb = calloc(42, sizeof(char));
  int signe = 1;
  if (*str == '-') {
    signe = -1;
    str++;
  } else if (*str == '+') str++;

  while(*str) {
    str += FindNumber(str, nb);
    free(nb);
    nb = calloc(42, sizeof(char));
    str += 2;
    if (l) cf.left[*str] = atoi(nb) * signe;
    else cf.right[*str] = atoi(nb) * signe;
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
      if (*str == '-') {
        signe = -1;
        str++;
      } else if (*str == '+') {
        signe = 1;
        str++;
      }
    }
  }
  return coeffs;
}


static void print(struct coeff cf) {
  printf('[ ');
  for (int i = 0; i < 5; ++i)
    printf("%d; ", cf.left[i]);
  printf("]\n");
  for (int i = 0; i < 5; ++i)
    printf("%d; ", cf.right[i]);
}
int main(/*int argc, char *argv[]*/) {
  /*if (argc < 2) errx(1 ,"Missing arguments");
  if (argc > 2) errx(1 ,"Too much arguments");*/

  int cf[] = PutExpression(/*argv[1]*/ "4X^3+5X^1=0");
  print(cf);

  return 0;
}