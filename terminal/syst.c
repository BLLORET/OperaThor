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
    if (M[3] == 1)
      printf("| X");
    else
      printf("|%.0fX", M[1 * 3 + 0]);
    Printpositivity(M[1 * 3 + 1]);
    printf("Y = %.0f", M[1 * 3 + 2]);
  } else {
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
}

static void printSyst2(float M[]) {
  if (M[0] == 1)
  	printf("| X");
  else
    printf("|%.0fX", M[0 * 3 + 0]);
  Printpositivity(M[0 * 3 + 1]);
  printf("Y = %.0f\n", M[0 * 3 + 2]);
  if (M[3] != 0) {
    if (M[3] == 1)
      printf("| X");
    else
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

static void PrintSyst3incoetape1(float M[], float cf1, float cf2, float cf3) {
  if (M[0] == 1)
    printf("| X");
  else
    printf("|%.0fX", M[0]);
  Printpositivity(M[1]);
  printf("Y");
  Printpositivity(M[2]);
  printf("Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    printf("|%.0fX", M[4]);
    Printpositivity(M[5]);
    printf("Y");
    Printpositivity(M[6]);
    printf("Z = %.0f", M[7]);
    if (cf1 == 1)
      printf("      (L2");
    else if (cf1 == -1)
      printf("      (-L2");
    else
      printf("      (%.0fL2", cf1);
    Printpositivity2(-cf2);
    printf("L1)\n");
  } else {
    if (M[5] != 0) {
      printf("|   %.0fY", M[5]);
      Printpositivity(M[6]);
      printf("Z = %.0f", M[7]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf2);
      printf("L1)\n");
    } else {
      printf("|     %.0fZ = %.0f", M[6], M[7]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf2);
      printf("L1)\n");
    }
    
  }
  // 3e ligne
  if (M[8] != 0) {
    printf("|%.0fX", M[8]);
    Printpositivity(M[9]);
    printf("Y");
    Printpositivity(M[10]);
    printf("Z = %.0f", M[11]);
    if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf3);
      printf("L1)\n\n");
  } else {
    if (M[9] != 0) {
      printf("|   %.0fY", M[9]);
      Printpositivity(M[10]);
      printf("Z = %.0f", M[11]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf3);
      printf("L1)\n\n");
    } else {
      printf("|     %.0fZ = %.0f\n", M[10], M[11]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf3);
      printf("L1)\n\n");
    }
  }
}

static void PrintSyst3incoetape2(float M[], float cf1, float cf2) {
  if (M[0] == 1)
    printf("| X");
  else
    printf("|%.0fX", M[0]);
  Printpositivity(M[1]);
  printf("Y");
  Printpositivity(M[2]);
  printf("Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    printf("|%.0fX", M[4]);
    Printpositivity(M[5]);
    printf("Y");
    Printpositivity(M[6]);
    printf("Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      printf("|   %.0fY", M[5]);
      Printpositivity(M[6]);
      printf("Z = %.0f\n", M[7]);
    } else 
      printf("|     %.0fZ = %.0f\n", M[6], M[7]); 
  }
  // 3e ligne
  if (M[8] != 0) {
    printf("|%.0fX", M[8]);
    Printpositivity(M[9]);
    printf("Y");
    Printpositivity(M[10]);
    printf("Z = %.0f", M[11]);
    if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf2);
      printf("L1)\n\n");
  } else {
    if (M[9] != 0) {
      printf("|   %.0fY", M[9]);
      Printpositivity(M[10]);
      printf("Z = %.0f", M[11]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf2);
      printf("L1)\n\n");
    } else {
      printf("|     %.0fZ = %.0f", M[10], M[11]);
      if (cf1 == 1)
        printf("      (L2");
      else if (cf1 == -1)
        printf("      (-L2");
      else
        printf("      (%.0fL2", cf1);
      Printpositivity2(-cf2);
      printf("L1)\n\n");
    }
  }
}

static void PrintSyst3inco(float M[]) {
  if (M[0] == 1)
    printf("| X");
  else
    printf("|%.0fX", M[0]);
  Printpositivity(M[1]);
  printf("Y");
  Printpositivity(M[2]);
  printf("Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    printf("|%.0fX", M[4]);
    Printpositivity(M[5]);
    printf("Y");
    Printpositivity(M[6]);
    printf("Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      printf("|   %.0fY", M[5]);
      Printpositivity(M[6]);
      printf("Z = %.0f\n", M[7]);
    } else
      printf("|     %.0fZ = %.0f\n", M[6], M[7]);
  }
  // 3e ligne
  if (M[8] != 0) {
    printf("|%.0fX", M[8]);
    Printpositivity(M[9]);
    printf("Y");
    Printpositivity(M[10]);
    printf("Z = %.0f\n", M[11]);
  } else {
    if (M[9] != 0) {
      printf("|   %.0fY", M[9]);
      Printpositivity(M[10]);
      printf("Z = %.0f\n", M[11]);
    } else
      printf("|     %.0fZ = %.0f\n", M[10], M[11]);
  }
}

static void PrintSyst3incoF(float M[]) {
  if (M[0] == 1)
    printf("| X");
  else
    printf("|%.0fX", M[0]);
  Printpositivity(M[1]);
  printf("Y");
  Printpositivity(M[2]);
  printf("Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    printf("|%.0fX", M[4]);
    Printpositivity(M[5]);
    printf("Y");
    Printpositivity(M[6]);
    printf("Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      printf("|   %.0fY", M[5]);
      Printpositivity(M[6]);
      printf("Z = %.0f\n", M[7]);
    } else
      printf("|     %.0fZ = %.0f\n", M[6], M[7]);
  }
  // 3e ligne
    printf("|           Z = %.2f\n", M[11]);
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
  Printpositivity2(-cf2);
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

static void premiersyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf("Y");
  Printpositivity2(M[2]);
  printf(" * (%.2f) = %.0f\n", M[11], M[3]);
  // 2e ligne
  if (M[5] == 1)
    printf("|   Y");
  else
    printf("|   %.0fY", M[5]);
  Printpositivity2(M[6]);
  printf(" * (%.2f) = %.0f\n", M[11], M[7]);
  // 3e ligne
  printf("|                   Z = %.2f\n\n Après calcul le système devient:\n\n", M[11]);
}

static void deuxiemesyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf("Y");
  M[2] *= M[11];
  if (M[2] >= 0)
    printf(" + %.2f = %.0f\n", M[2], M[3]);
  else
    printf(" - %.2f = %.0f\n", -M[2], M[3]);
  // 2e ligne
  if (M[5] == 1)
    printf("|   Y");
  else
    printf("|   %.0fY", M[5]);
  M[6] *= M[11];
  if (M[6] >= 0)
    printf(" + %.2f = %.0f\n", M[6], M[7]);
  else
    printf(" - %.2f = %.0f\n", -M[6], M[7]);
  // 3e ligne
  printf("|             Z = %.2f\n\n", M[11]);
}

static void troisiemesyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf("Y");
  M[3] -= M[2];
  M[2] = 0;
  printf("   = %.2f\n", M[3]);
  // 2e ligne
  if (M[5] == 1)
    printf("|   Y  ");
  else
    printf("|   %.0fY  ", M[5]);
  M[7] -= M[6];
  M[6] = 0;
  printf(" = %.2f\n", M[7]);
  // 3e ligne
  printf("|         Z = %.2f\n\n", M[11]);
}


static void quatriemesyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf("Y");
  printf("   = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  printf("|      Y   = %.2f\n", M[7]);
  // 3e ligne
  printf("|        Z = %.2f\n\n", M[11]);
}

static void cinquiemesyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  Printpositivity2(M[1]);
  printf(" * (%.2f)", M[7]);
  printf("   = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  printf("|               Y   = %.2f\n", M[7]);
  // 3e ligne
  printf("|                 Z = %.2f\n\n", M[11]);
}

static void sixiemesyst(float M[]) {
  //premiere ligne
  if (M[0] == 1)
    printf("| ");
  else
    printf("|%.0fX", M[0]);
  M[1] *= M[7];
  printf(" %.2f = %.2f\n", M[1], M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  printf("|     Y   = %.2f\n", M[7]);
  // 3e ligne
  printf("|       Z = %.2f\n\n", M[11]);
}

static int septiemesyst(float M[]) {
  int un = 0;
  //premiere ligne
  if (M[0] == 1) {
    printf("| ");
    un++;
  } else
    printf("|%.0fX", M[0]);
  M[3] -= M[1];
  M[1] = 0;
  printf(" = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  printf("| Y = %.2f\n", M[7]);
  // 3e ligne
  printf("| Z = %.2f\n\n", M[11]);
  return un;
}

static void huitiemesyst(float M[]) {
  //premiere ligne
  M[3] /= M[0];
  M[0] = 1;
  printf("| X = %.2f\n", M[3]);
  // 2e ligne
  printf("| Y = %.2f\n", M[7]);
  // 3e ligne
  printf("| Z = %.2f\n\n", M[11]);
}

void solveur_3_inconnu(float M[]) {
  printf("Nous avons le système linéaire de la forme:\n\n");
  PrintSyst3inco(M);
  printf("\n\n");
  printf("En appliquant le théorème de Gauss, nous obtenons:\n\n");
  float cf1 = M[0];
  float cf2 = M[4];
  float cf3 = M[8];
  for (int i = 4; i < 7; ++i)
    M[i] = M[i] * cf1 - M[i - 4] * cf2;
  for (int i = 8; i < 12; ++i)
    M[i] = M[i] * cf1 - M[i - 8] * cf3;
  PrintSyst3incoetape1(M, cf1, cf2, cf3);
  printf("Nous réappliquons le théorème de Gauss entre la seconde et\n");
  printf("la troisième ligne afin d'isoler le Z de la troisième.\n\n");
  cf1 = M[5];
  cf2 = M[9];
  for (int i = 9; i < 12; ++i)
    M[i] = M[i] * cf1 - M[i - 4] * cf2;
  PrintSyst3incoetape2(M, cf1, cf2);
  printf("Maintenant, il ne reste plus qu'à obtenir la valeur de Z.\n\n");
  M[11] /= M[10];
  M[10] = 1;
  PrintSyst3incoF(M);
  printf("Et remplacer le Z par sa valeur dans la deuxième ligne.\n");
  printf("Nous obtenons ainsi: \n\n");
  premiersyst(M);
  deuxiemesyst(M);
  troisiemesyst(M);
  if (M[5] != 1) {
    printf("Isolons maintenant le Y et réinjectons le comme pour le Z.\n\n");
    quatriemesyst(M);
  }
  printf("Réinjectons le Y dans la première ligne:\n\n");
  cinquiemesyst(M);
  sixiemesyst(M);
  if (!septiemesyst(M))
    huitiemesyst(M);
  printf("Nous avons donc nos solutions pour nos trois inconnus.\n\n");
}
int main() {
	/*printf("3 / 3 = %f\n",(float) 3/3);
	printf("-3 / 3 = %f\n",(float) -3/3);
	printf("2 * 2.5 = %f\n", (float)2 * 2.5);
	printf("-3 / -3 = %f\n",(float) -3/-3);
	//printf("-2 % 1 = %f\n",(float) (-2%1));*/
	//size_t column = 3;
	//float inco[1 * 3 + 2];
	// ligne * nbcolumn + comlumn
	/*inco[0 * 3 + 0] = 1; // 0
	inco[0 * 3 + 1] = 22;  // 1
	inco[0 * 3 + 2] = -3;  // 2
	inco[1 * 3 + 0] = 1;  // 3
	inco[1 * 3 + 1] = -6;  // 4
	inco[1 * 3 + 2] = 87;  // 5*/
	//solveur_2_inconnu(inco);
  float L[12] = { 2, 3, 4 , 5, 8, 1, 5, 6, 6, 8, 7, 9};
  solveur_3_inconnu(L);
	return 0;
}