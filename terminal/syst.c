# include "syst.h"

static void Printpositivity(float n) {
  if (n < 0) {
  	if (n != -1)
      printf(" - %.0f", - n);
    else 
      printf(" -  ");
  } else {
  	if (n != 1)
      printf(" + %.0f", n);
    else
      printf(" +  ");
  }
}

static void Printpositivity2(float n) {
  if (n < 0) {
  	if (n != -1)
      printf(" - %.0f", - n);
    else 
      printf(" - ");
  } else {
  	if (n != 1)
      printf(" + %.0f", n);
    else
      printf(" + ");
  }
}

static void Printpositivity3(float n) {
  if (n < 0) {
  	if (n != -1)
      printf(" - %.2f", - n);
    else 
      printf(" - ");
  } else {
  	if (n != 1)
      printf(" + %.2f", n);
    else
      printf(" + ");
  }
}

static void printSyst1(float M[]) {
  if (M[0] == 1)
  	printf("| X");
  else
    printf("|%.0fX", M[0 * 3 + 0]);
  Printpositivity(M[0 * 3 + 1]);
  printf("Y = %.0f\n", M[0 * 3 + 2]);
  if (M[3] != 0) {
    printf("|%.0fX", M[1 * 3 + 0]);
    Printpositivity(M[1 * 3 + 1]);
    printf("Y = %.0f", M[1 * 3 + 2]);
  } else 
    if (M[4] < 0){
      if (M[4] != -1)
    	printf("|    %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);
      else
      	printf("|     Y = %.0f", M[1 * 3 + 2]);
    } else {
      if (M[4] != 1 )
        printf("|     %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);  
      else
      	printf("|      Y = %.0f", M[1 * 3 + 2]);      
    }
}

static void printSyst2(float M[]) {
  if (M[0] == 1)
  	printf("| X");
  else
    printf("|%.0fX", M[0 * 3 + 0]);
  Printpositivity(M[0 * 3 + 1]);
  printf("Y = %.0f\n", M[0 * 3 + 2]);
  if (M[3] != 0) {
    printf("|%.0fX", M[1 * 3 + 0]);
    Printpositivity(M[1 * 3 + 1]);
    printf("Y = %.0f", M[1 * 3 + 2]);
  } else 
    if (M[4] < 0){
      if (M[4] != -1)
    	printf("|    %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);
      else
      	printf("|     Y = %.2f", M[1 * 3 + 2]);
    } else {
      if (M[4] != 1 )
        printf("|     %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);  
      else
      	printf("|      Y = %.2f", M[1 * 3 + 2]);      
    }
}



void solveur_2_inconnu(float M[]) {
  printf("Nous avons le système linéaire de la forme:\n\n");
  printSyst1(M);
  printf("\n\n");
  printf("En appliquant le théorème de Gauss, nous obtenons:\n\n");
  float cf1 = M[0];
  float cf2 = M[3];
  for (int i = 3; i < 6; ++i) {
  	M[i] = M[i] * cf1 - M[i - 3] * cf2;
  }
  printSyst1(M);
  if (cf1 == 1)
  	printf("      (L2");
  else if (cf1 == -1)
  	printf("      (-L2");
  else
    printf("      (%.0fL2", cf1);
  Printpositivity(-cf2);
  printf("L1)\n\n");

  // isolation du Y
  printf("Nous passons le coefficient de Y à droite afin d'isoler le Y.\n");
  printf("Nous obtenons ainsi le système suivant:\n\n");
  M[5] /= M[4];
  M[4] = 1;
  printSyst2(M);
  printf("\n\n");
  printf("Maintenant que nous avons isolé le Y, nous pouvons remplacer\n");
  printf("le Y dans l'équation de la ligne 1.\n");
  printf("Pour plus de clarté, récupérons l'équation 1 hors du système.\n");
  if (M[0] == 1)
  	printf("\nL'équation 1 est donc: X");
  else 
  	printf("\nL'équation 1 est donc: %.0fX", M[0]);
  Printpositivity2(M[1]);
  printf("Y = %.0f\n\n", M[2]);

  printf("En remplaçant le Y par sa valeur nous obtenons: ");
  if (M[0] == 1)
  	printf("X");
  else 
  	printf("%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf(" * ");
  if (M[5] < 0)
  	printf("(%.2f)", M[5]);
  else
  	printf("%.2f",M[5]);
  printf(" = %.0f\n", M[2]);
  printf("Il ne nous reste plus qu'à isoler le X.\n\n");
  if (M[0] == 1)
  	printf("X");
  else 
  	printf("%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf(" * ");
  if (M[5] < 0)
  	printf("(%.2f)", M[5]);
  else
  	printf("%.2f",M[5]);
  printf(" = %.0f\n", M[2]);
  M[1] *= M[5];
  if (M[0] == 1)
  	printf("X");
  else 
  	printf("%.0fX", M[0]);
  Printpositivity3(M[1]);
  printf(" = %.0f\n", M[2]);
  // passage de tout à droite
  M[2] -= M[1];
  M[1] = 0;
  if (M[0] == 1)
  	printf("X = %.2f\n", M[2]);
  else {
  	printf("%.0fX = %.2f\n", M[0], M[2]);
    M[2] /= M[0];
    M[0] = 1;
    printf("X = %.2f\n", M[2]);
  }
  printf("\nNous avons ainsi les résultats suivants:\n\n");
  printf("| X = %.2f\n", M[2]);
  printf("| Y = %.2f\n\n", M[5]);

} 


int main() {
	printf("3 / 3 = %f\n",(float) 3/3);
	printf("-3 / 3 = %f\n",(float) -3/3);
	printf("2 * 2.5 = %f\n", (float)2 * 2.5);
	printf("-3 / -3 = %f\n",(float) -3/-3);
	//printf("-2 % 1 = %f\n",(float) (-2%1));
	size_t column = 3;
	float inco[1 * 3 + 2];
	// ligne * nbcolumn + comlumn
	inco[0 * 3 + 0] = 16; // 0
	inco[0 * 3 + 1] = 22;  // 1
	inco[0 * 3 + 2] = -3;  // 2
	inco[1 * 3 + 0] = 44;  // 3
	inco[1 * 3 + 1] = -6;  // 4
	inco[1 * 3 + 2] = 87;  // 5
	solveur_2_inconnu(inco);
	return 0;
}