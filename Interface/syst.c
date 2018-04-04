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
