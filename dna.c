#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t) {
  if (fscanf(file, "%d", p) != 1) {
    fprintf(stderr, "erro ao ler tamanho do teste %d\n", t);
  }

  char c;
  do {
    c = getc(file);
  } while (c != '\n');

  if (!fgets(s, *p + 1, file)) {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
  if (length[n][m] != -1){
    printf("e ");
    return length[n][m];
  }
  if (m == 0 || n == 0){
    length[n][m] = 0;
    printf("z ");
    return 0;
  }
  printf("%d ", a[n]);
  printf("%d ", b[m]);
  printf("%d ", m);
  printf("%d ", n);
  printf("%d ", b[m-1] == a[n-1]);
  if(a[n-1] == b[m-1]){
    printf("q11 ");
    length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
    printf("q2 ");
    return length[n][m];
  }
  else{
    if (length[n-1][m] == -1){
      printf("n ");
      length[n-1][m] = mlcs_w(a, n-1, b, m, length);
    }
    if (length[n][m-1] == -1){
      printf("m ");
      length[n][m-1] = mlcs_w(a, n, b, m-1, length);
    }
    
    if (length[n-1][m] > length[n][m-1]){
      printf("rn ");
      return length[n-1][m];
    }
    else{
      printf("rm ");
      return length[n][m-1];
    }
  }
}

int mlcs(char a[], int n, char b[], int m) {
  int length[MAX_SIZE + 1][MAX_SIZE + 1];

  for(int i = 0; i < MAX_SIZE + 1; i++){
    for(int s = 0; s < MAX_SIZE + 1; s++){
    length[s][i] = -1;
  }
  }
  //mlcs_w(a, n, b, m, length);

  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {
  return 2;
}
