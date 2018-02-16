# include "identification.h"


struct coeff *initcoeff(int degree) {
  struct coeff *cf = malloc(sizeof(struct coeff) * (degree + 1));
  coeff ->next = NULL;
  coeff->value = 0;
  coeff->degree = degree;
}

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

int identification(char *str, struct coeff *cf) {
  size_t len = strlen(str);
  char *nb = calloc(4, sizeof(char));
  int j = 0;
  int signe = 1;
  for(size_t i = 0; i < len; i++) {
  	switch (NumOrChar(str[i])) {
  	  case 0:
        nb[j] = str[i];
        j++;
  	    break;
  	  case 1:
        if (!nb)
          cf->value = 1;
        else
          cf->value = CharToInt(*nb) * signe;
  	    break;
  	  case 2:

  	    break;
  	  case 3:
        signe = 1;
  	    break;
  	  case 4:
  	    signe = -1;
  	    break;
  	  case 5:
        i++;
  	    break;
  	  case 6:

  	    break;
  	  default:
        errx(1, "Invalid expression");
  	    break;
  	}

  }
  free(nb);
}

// type -1 is an error
// 0 is a number
// 1 is a letter
// 2 is a degre
// 3 is + 
// 4 is -
// 5 is *
// 6 is /
int NumOrChar(char *str) {
  if (*str >= '0' && *str <= '9')
    return 0;
  if (*str == 'X')
  	return 1;
  if (*str == '^')
  	return 2;
  if (*str == '+')
  	return 3;
  if (*str == '-')
  	return 4;
  if (*str == '*')
    return 5;
  if (*str == '/')
  	return 6;
  return -1;
}

int main(int argc, char const *argv[]) {
  	
  return 0;
}