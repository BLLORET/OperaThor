# include <stdlib.h>
# include <stdio.h>

/* Pour multiplier (x - 1)(5x + 2) par exemple où
  p1 = [-1; 1] et p2 = [2; 5]. p est un polynome du 2nd degré
  qui peut valoir par exemple 5x²+42x-3 et p = [-3; 42; 5] 
  (Pas fait les calculs c'est juste pour que tu comprennes)*/
int[] dev2(int[] p1, int[] p2) {
  int p[3];
  p[2] = p1[1] * p2[1];
  p[1] = p1[0] * p2[1] + p1[1] * p2[0];
  p[0] = p1[0] * p2[0];
  return p;
}

// deg2 est le polynôme de degré 2 obtenus via la fonction d'avant
// et deg1 est un monôme de degré 1 le résultat est un polynôme
// de degré 3 qui suit la même règle de stockage
int[] dev3(int[] deg2, int[] deg1) {
  int p[4];
  p[3] = deg2[2] * deg1[1];
  p[2] = deg2[2] * deg1[0] + deg2[1] * deg1[1];
  p[1] = deg2[1] * deg1[0] + deg2[0] * deg1[1]];
  p[0] = deg2[0] * deg1[0];
  return p;
}