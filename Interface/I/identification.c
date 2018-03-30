# include "identification.h"

static void Printpositivity(FILE* file,int n) {
  if (n < 0)
    fprintf(file," - %d", - n);
  else
    fprintf(file," + %d", n);
}

static void printdegree(FILE *file,int n){
  if (n == 4)
    fprintf(file,"X⁴");
  else if (n == 3)
    fprintf(file,"X³");
  else if (n == 2)
    fprintf(file,"X²");
  else if (n == 1)
    fprintf(file,"X");
}

static void printCoeffs(FILE* file,struct coeff *cf) {
  
  int degreel = FindDegree(cf->left);
  int degreer = FindDegree(cf->right);
  // Left part
  if (degreel == 0 && cf->left[0] == 0)
    fprintf(file,"          0 = ");
  else {
    fprintf(file,"          %d", cf->left[degreel]);
    printdegree(file,degreel);
    degreel--;
    while (degreel >= 0) {
      if (cf->left[degreel] != 0) {
        Printpositivity(file,cf->left[degreel]);
        printdegree(file,degreel);
      }
      degreel--;
    }
    fprintf(file," = ");
  }
  // Right Part 
  if (degreer == 0 && cf->right[0] == 0)
      fprintf(file,"0 \n\n");
  else {
    fprintf(file,"%d", cf->right[degreer]);
    printdegree(file,degreer);
    degreer--;
    while (degreer >= 0) {
      if (cf->right[degreer] != 0) {
        Printpositivity(file,cf->right[degreer]);
        printdegree(file,degreer);
      }
      degreer--;
    }
    fprintf(file,"\n\n");
  }
}


struct coeff *Diff(FILE* file,struct coeff *cf) {
  fprintf(file,"Afin de résoudre notre équation de la forme:\n\n");
  printCoeffs(file,cf);
  fprintf(file,"Nous devons tout d'abord tout passer à gauche du égal afin de");
  fprintf(file," faciliter la résolution de l'équation.\n");
  fprintf(file,"Nous obtenons donc l'équation de la forme:\n\n");
  for (int i = 0; i < 5; i++) {
    cf->left[i] -= cf->right[i];
    cf->right[i] = 0;
  }
  printCoeffs(file,cf);
  fprintf(file,"Nous pouvons maintenant passer à la résolution de l'équation.\n\n");
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

/*struct coeff *PutExpression(char *str) {
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
}*/

void FreeCoeff(struct coeff*cf) {
  free(cf->right);
  free(cf->left);
  free(cf);
}

/*void printcoeff(struct coeff *cf) {
  printf("cf->left = [ ");
  for (int i = 0; i < 5; ++i)
    printf("%d ", cf->left[i]);
  printf("]\ncf->right = [ ");
  for (int i = 0; i < 5; ++i)
    printf("%d ", cf->right[i]);
  printf("]\n");
}*/
