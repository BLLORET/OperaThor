# include "syst.h"

static void Printpositivity(FILE *file,float n) {
  if (n < 0) {
  	if (n != -1)
      fprintf(file," - %.0f", - n);
    else 
      fprintf(file," -  ");
  } else {
  	if (n != 1)
      fprintf(file," + %.0f", n);
    else
      fprintf(file," +  ");
  }
}

static void Printpositivity2(FILE *file,float n) {
  if (n < 0) {
  	if (n != -1)
      fprintf(file," - %.0f", - n);
    else 
      fprintf(file," - ");
  } else {
  	if (n != 1)
      fprintf(file," + %.0f", n);
    else
      fprintf(file," + ");
  }
}

static void Printpositivity3(FILE *file,float n) {
  if (n < 0) {
  	if (n != -1)
      fprintf(file," - %.2f", - n);
    else 
      fprintf(file," - ");
  } else {
  	if (n != 1)
      fprintf(file," + %.2f", n);
    else
      fprintf(file," + ");
  }
}

static void printSyst1(FILE *file,float M[]) {
  if (M[0] == 1)
  	fprintf(file,"| X");
  else
    fprintf(file,"|%.0fX", M[0 * 3 + 0]);
  Printpositivity(file,M[0 * 3 + 1]);
  fprintf(file,"Y = %.0f\n", M[0 * 3 + 2]);
  if (M[3] != 0) {
    fprintf(file,"|%.0fX", M[1 * 3 + 0]);
    Printpositivity(file,M[1 * 3 + 1]);
    fprintf(file,"Y = %.0f", M[1 * 3 + 2]);
  } else 
    if (M[4] < 0){
      if (M[4] != -1)
    	fprintf(file,"|    %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);
      else
      	fprintf(file,"|     Y = %.0f", M[1 * 3 + 2]);
    } else {
      if (M[4] != 1 )
        fprintf(file,"|     %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);  
      else
      	fprintf(file,"|      Y = %.0f", M[1 * 3 + 2]);      
    }
}

static void printSyst2(FILE *file,float M[]) {
  if (M[0] == 1)
  	fprintf(file,"| X");
  else
    fprintf(file,"|%.0fX", M[0 * 3 + 0]);
  Printpositivity(file,M[0 * 3 + 1]);
  fprintf(file,"Y = %.0f\n", M[0 * 3 + 2]);
  if (M[3] != 0) {
    fprintf(file,"|%.0fX", M[1 * 3 + 0]);
    Printpositivity(file,M[1 * 3 + 1]);
    fprintf(file,"Y = %.0f", M[1 * 3 + 2]);
  } else 
    if (M[4] < 0){
      if (M[4] != -1)
    	fprintf(file,"|    %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);
      else
      	fprintf(file,"|     Y = %.2f", M[1 * 3 + 2]);
    } else {
      if (M[4] != 1 )
        fprintf(file,"|     %.0fY = %.0f", M[1 * 3 + 1], M[1 * 3 + 2]);  
      else
      	fprintf(file,"|      Y = %.2f", M[1 * 3 + 2]);      
    }
}



void solveur_2_inconnu(FILE *file,float M[]) {
  fprintf(file,"Nous avons le système linéaire de la forme:\n\n");
  printSyst1(file,M);
  fprintf(file,"\n\n");
  fprintf(file,"En appliquant le théorème de Gauss, nous obtenons:\n\n");
  float cf1 = M[0];
  float cf2 = M[3];
  for (int i = 3; i < 6; ++i) {
  	M[i] = M[i] * cf1 - M[i - 3] * cf2;
  }
  printSyst1(file,M);
  if (cf1 == 1)
  	fprintf(file,"      (L2");
  else if (cf1 == -1)
  	fprintf(file,"      (-L2");
  else
    fprintf(file,"      (%.0fL2", cf1);
  Printpositivity(file,-cf2);
  fprintf(file,"L1)\n\n");

  // isolation du Y
  fprintf(file,"Nous passons le coefficient de Y à droite afin d'isoler le Y.\n");
  fprintf(file,"Nous obtenons ainsi le système suivant:\n\n");
  M[5] /= M[4];
  M[4] = 1;
  printSyst2(file,M);
  fprintf(file,"\n\n");
  fprintf(file,"Maintenant que nous avons isolé le Y, nous pouvons remplacer\n");
  fprintf(file,"le Y dans l'équation de la ligne 1.\n");
  fprintf(file,"Pour plus de clarté, récupérons l'équation 1 hors du système.\n");
  if (M[0] == 1)
  	fprintf(file,"\nL'équation 1 est donc: X");
  else 
  	fprintf(file,"\nL'équation 1 est donc: %.0fX", M[0]);
  Printpositivity2(file,M[1]);
  fprintf(file,"Y = %.0f\n\n", M[2]);

  fprintf(file,"En remplaçant le Y par sa valeur nous obtenons: ");
  if (M[0] == 1)
  	fprintf(file,"X");
  else 
  	fprintf(file,"%.0fX", M[0]);
  Printpositivity2(file,M[1]);
  fprintf(file," * ");
  if (M[5] < 0)
  	fprintf(file,"(%.2f)", M[5]);
  else
  	fprintf(file,"%.2f",M[5]);
  fprintf(file," = %.0f\n", M[2]);
  fprintf(file,"Il ne nous reste plus qu'à isoler le X.\n\n");
  if (M[0] == 1)
  	fprintf(file,"X");
  else 
  	fprintf(file,"%.0fX", M[0]);
  Printpositivity2(file,M[1]);
  fprintf(file," * ");
  if (M[5] < 0)
  	fprintf(file,"(%.2f)", M[5]);
  else
  	fprintf(file,"%.2f",M[5]);
  fprintf(file," = %.0f\n", M[2]);
  M[1] *= M[5];
  if (M[0] == 1)
  	fprintf(file,"X");
  else 
  	fprintf(file,"%.0fX", M[0]);
  Printpositivity3(file,M[1]);
  fprintf(file," = %.0f\n", M[2]);
  // passage de tout à droite
  M[2] -= M[1];
  M[1] = 0;
  if (M[0] == 1)
  	fprintf(file,"X = %.2f\n", M[2]);
  else {
  	fprintf(file,"%.0fX = %.2f\n", M[0], M[2]);
    M[2] /= M[0];
    M[0] = 1;
    fprintf(file,"X = %.2f\n", M[2]);
  }
  fprintf(file,"\nNous avons ainsi les résultats suivants:\n\n");
  fprintf(file,"| X = %.2f\n", M[2]);
  fprintf(file,"| Y = %.2f\n\n", M[5]);
} 

static void PrintSyst3incoetape1(FILE *file,float M[], float cf1, float cf2, float cf3) {
  if (M[0] == 1)
    fprintf(file, "| X");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity(file, M[1]);
  fprintf(file, "Y");
  Printpositivity(file, M[2]);
  fprintf(file, "Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    fprintf(file, "|%.0fX", M[4]);
    Printpositivity(file, M[5]);
    fprintf(file, "Y");
    Printpositivity(file, M[6]);
    fprintf(file, "Z = %.0f", M[7]);
    if (cf1 == 1)
      fprintf(file, "      (L2");
    else if (cf1 == -1)
      fprintf(file, "      (-L2");
    else
      fprintf(file, "      (%.0fL2", cf1);
    Printpositivity2(file, -cf2);
    fprintf(file, "L1)\n");
  } else {
    if (M[5] != 0) {
      fprintf(file, "|   %.0fY", M[5]);
      Printpositivity(file, M[6]);
      fprintf(file, "Z = %.0f", M[7]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf2);
      fprintf(file, "L1)\n");
    } else {
      fprintf(file, "|     %.0fZ = %.0f", M[6], M[7]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf2);
      fprintf(file, "L1)\n");
    }
    
  }
  // 3e ligne
  if (M[8] != 0) {
    fprintf(file, "|%.0fX", M[8]);
    Printpositivity(file, M[9]);
    fprintf(file, "Y");
    Printpositivity(file, M[10]);
    fprintf(file, "Z = %.0f", M[11]);
    if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf3);
      fprintf(file, "L1)\n\n");
  } else {
    if (M[9] != 0) {
      fprintf(file, "|   %.0fY", M[9]);
      Printpositivity(file, M[10]);
      fprintf(file, "Z = %.0f", M[11]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf3);
      fprintf(file, "L1)\n\n");
    } else {
      fprintf(file, "|     %.0fZ = %.0f\n", M[10], M[11]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf3);
      fprintf(file, "L1)\n\n");
    }
  }
}

static void PrintSyst3incoetape2(FILE *file,float M[], float cf1, float cf2) {
  if (M[0] == 1)
    fprintf(file, "| X");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity(file, M[1]);
  fprintf(file, "Y");
  Printpositivity(file, M[2]);
  fprintf(file, "Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    fprintf(file, "|%.0fX", M[4]);
    Printpositivity(file, M[5]);
    fprintf(file, "Y");
    Printpositivity(file, M[6]);
    fprintf(file, "Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      fprintf(file, "|   %.0fY", M[5]);
      Printpositivity(file, M[6]);
      fprintf(file, "Z = %.0f\n", M[7]);
    } else 
      fprintf(file, "|     %.0fZ = %.0f\n", M[6], M[7]); 
  }
  // 3e ligne
  if (M[8] != 0) {
    fprintf(file, "|%.0fX", M[8]);
    Printpositivity(file, M[9]);
    fprintf(file, "Y");
    Printpositivity(file, M[10]);
    fprintf(file, "Z = %.0f", M[11]);
    if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf2);
      fprintf(file, "L1)\n\n");
  } else {
    if (M[9] != 0) {
      fprintf(file, "|   %.0fY", M[9]);
      Printpositivity(file, M[10]);
      fprintf(file, "Z = %.0f", M[11]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf2);
      fprintf(file, "L1)\n\n");
    } else {
      fprintf(file, "|     %.0fZ = %.0f", M[10], M[11]);
      if (cf1 == 1)
        fprintf(file, "      (L2");
      else if (cf1 == -1)
        fprintf(file, "      (-L2");
      else
        fprintf(file, "      (%.0fL2", cf1);
      Printpositivity2(file, -cf2);
      fprintf(file, "L1)\n\n");
    }
  }
}

static void PrintSyst3inco(FILE *file,float M[]) {
  if (M[0] == 1)
    fprintf(file, "| X");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity(file, M[1]);
  fprintf(file, "Y");
  Printpositivity(file,M[2]);
  fprintf(file, "Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    fprintf(file, "|%.0fX", M[4]);
    Printpositivity(file,M[5]);
    fprintf(file, "Y");
    Printpositivity(file,M[6]);
    fprintf(file, "Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      fprintf(file, "|   %.0fY", M[5]);
      Printpositivity(file, M[6]);
      fprintf(file, "Z = %.0f\n", M[7]);
    } else
      fprintf(file, "|     %.0fZ = %.0f\n", M[6], M[7]);
  }
  // 3e ligne
  if (M[8] != 0) {
    fprintf(file, "|%.0fX", M[8]);
    Printpositivity(file, M[9]);
    fprintf(file, "Y");
    Printpositivity(file, M[10]);
    fprintf(file, "Z = %.0f\n", M[11]);
  } else {
    if (M[9] != 0) {
      fprintf(file, "|   %.0fY", M[9]);
      Printpositivity(file, M[10]);
      fprintf(file, "Z = %.0f\n", M[11]);
    } else
      fprintf(file, "|     %.0fZ = %.0f\n", M[10], M[11]);
  }
}

static void PrintSyst3incoF(FILE *file,float M[]) {
  if (M[0] == 1)
    fprintf(file, "| X");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity(file, M[1]);
  fprintf(file, "Y");
  Printpositivity(file, M[2]);
  fprintf(file, "Z = %.0f\n", M[3]);
  // 2e ligne
  if (M[4] != 0) {
    fprintf(file, "|%.0fX", M[4]);
    Printpositivity(file, M[5]);
    fprintf(file, "Y");
    Printpositivity(file, M[6]);
    fprintf(file, "Z = %.0f\n", M[7]);
  } else {
    if (M[5] != 0) {
      fprintf(file, "|   %.0fY", M[5]);
      Printpositivity(file, M[6]);
      fprintf(file, "Z = %.0f\n", M[7]);
    } else
      fprintf(file, "|     %.0fZ = %.0f\n", M[6], M[7]);
  }
  // 3e ligne
    fprintf(file, "|           Z = %.2f\n", M[11]);
}

static void premiersyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity2(file, M[1]);
  fprintf(file, "Y");
  Printpositivity2(file, M[2]);
  fprintf(file, " * (%.2f) = %.0f\n", M[11], M[3]);
  // 2e ligne
  if (M[5] == 1)
    fprintf(file, "|   Y");
  else
    fprintf(file, "|   %.0fY", M[5]);
  Printpositivity2(file, M[6]);
  fprintf(file, " * (%.2f) = %.0f\n", M[11], M[7]);
  // 3e ligne
  fprintf(file, "|                   Z = %.2f\n\n Après calcul le système devient:\n\n", M[11]);
}

static void deuxiemesyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity2(file, M[1]);
  fprintf(file, "Y");
  M[2] *= M[11];
  if (M[2] >= 0)
    fprintf(file, " + %.2f = %.0f\n", M[2], M[3]);
  else
    fprintf(file, " - %.2f = %.0f\n", -M[2], M[3]);
  // 2e ligne
  if (M[5] == 1)
    fprintf(file, "|   Y");
  else
    fprintf(file, "|   %.0fY", M[5]);
  M[6] *= M[11];
  if (M[6] >= 0)
    fprintf(file, " + %.2f = %.0f\n", M[6], M[7]);
  else
    fprintf(file, " - %.2f = %.0f\n", -M[6], M[7]);
  // 3e ligne
  fprintf(file, "|             Z = %.2f\n\n", M[11]);
}

static void troisiemesyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity2(file, M[1]);
  fprintf(file, "Y");
  M[3] -= M[2];
  M[2] = 0;
  fprintf(file, "   = %.2f\n", M[3]);
  // 2e ligne
  if (M[5] == 1)
    fprintf(file, "|   Y  ");
  else
    fprintf(file, "|   %.0fY  ", M[5]);
  M[7] -= M[6];
  M[6] = 0;
  fprintf(file, " = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "|         Z = %.2f\n\n", M[11]);
}

static void quatriemesyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity2(file, M[1]);
  fprintf(file, "Y");
  fprintf(file, "   = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  fprintf(file, "|      Y   = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "|        Z = %.2f\n\n", M[11]);
}

static void cinquiemesyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  Printpositivity2(file, M[1]);
  fprintf(file, " * (%.2f)", M[7]);
  fprintf(file, "   = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  fprintf(file, "|               Y   = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "|                 Z = %.2f\n\n", M[11]);
}

static void sixiemesyst(FILE *file,float M[]) {
  //premiere ligne
  if (M[0] == 1)
    fprintf(file, "| ");
  else
    fprintf(file, "|%.0fX", M[0]);
  M[1] *= M[7];
  fprintf(file, " %.2f = %.2f\n", M[1], M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  fprintf(file, "|     Y   = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "|       Z = %.2f\n\n", M[11]);
}

static int septiemesyst(FILE *file,float M[]) {
  int un = 0;
  //premiere ligne
  if (M[0] == 1) {
    fprintf(file, "| ");
    un++;
  } else
    fprintf(file, "|%.0fX", M[0]);
  M[3] -= M[1];
  M[1] = 0;
  fprintf(file, " = %.2f\n", M[3]);
  // 2e ligne
  M[7] /= M[5];
  M[5] = 1;
  fprintf(file, "| Y = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "| Z = %.2f\n\n", M[11]);
  return un;
}

static void huitiemesyst(FILE *file,float M[]) {
  //premiere ligne
  M[3] /= M[0];
  M[0] = 1;
  fprintf(file, "| X = %.2f\n", M[3]);
  // 2e ligne
  fprintf(file, "| Y = %.2f\n", M[7]);
  // 3e ligne
  fprintf(file, "| Z = %.2f\n\n", M[11]);
}

void solveur_3_inconnu(FILE *file, float M[]) {
  fprintf(file, "Nous avons le système linéaire de la forme:\n\n");
  PrintSyst3inco(file, M);
  fprintf(file, "\n\nEn appliquant le théorème de Gauss, nous obtenons:\n\n");
  float cf1 = M[0];
  float cf2 = M[4];
  float cf3 = M[8];
  for (int i = 4; i < 7; ++i)
    M[i] = M[i] * cf1 - M[i - 4] * cf2;
  for (int i = 8; i < 12; ++i)
    M[i] = M[i] * cf1 - M[i - 8] * cf3;
  PrintSyst3incoetape1(file, M, cf1, cf2, cf3);
  fprintf(file, "Nous réappliquons le théorème de Gauss entre la seconde et\n");
  fprintf(file, "la troisième ligne afin d'isoler le Z de la troisième.\n\n");
  cf1 = M[5];
  cf2 = M[9];
  for (int i = 9; i < 12; ++i)
    M[i] = M[i] * cf1 - M[i - 4] * cf2;
  PrintSyst3incoetape2(file, M, cf1, cf2);
  fprintf(file, "Maintenant, il ne reste plus qu'à obtenir la valeur de Z.\n\n");
  M[11] /= M[10];
  M[10] = 1;
  PrintSyst3incoF(file, M);
  fprintf(file, "Et remplacer le Z par sa valeur dans la deuxième ligne.\n");
  fprintf(file, "Nous obtenons ainsi: \n\n");
  premiersyst(file, M);
  deuxiemesyst(file, M);
  troisiemesyst(file, M);
  if (M[5] != 1) {
    fprintf(file, "Isolons maintenant le Y et réinjectons le comme pour le Z.\n\n");
    quatriemesyst(file, M);
  }
  fprintf(file, "Réinjectons le Y dans la première ligne:\n\n");
  cinquiemesyst(file, M);
  sixiemesyst(file, M);
  if (!septiemesyst(file, M))
    huitiemesyst(file, M);
  fprintf(file, "Nous avons donc nos solutions pour nos trois inconnus.\n\n");
}

/*int main() {
	//printf("3 / 3 = %f\n",(float) 3/3);
	//printf("-3 / 3 = %f\n",(float) -3/3);
	//printf("2 * 2.5 = %f\n", (float)2 * 2.5);
	//printf("-3 / -3 = %f\n",(float) -3/-3);
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
}*/
