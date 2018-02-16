# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <err.h>
# include <string.h>
# include <fcntl.h>


struct coeff {
  struct coeff *next;
  int value;
  int degree;
};

struct coeff *initcoeff(int degree);

int degree(char *str);

