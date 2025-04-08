#include <stdio.h>
#include <stdlib.h>

int **matrix_multiplication(int **a, int **b, int n) {
  int **res = malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    *(res + i) = calloc(n, sizeof(int));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        *(*(res + i) + j) += *(*(a + i) + k) * *(*(b + k) + j);
  return res;
}

int main() {

  int **a = malloc(2 * sizeof(int *)), **b = malloc(2 * sizeof(int *));
  for (int i = 0; i < 2; i++) {
    *(a + i) = malloc(2 * sizeof(int));
    *(b + i) = malloc(2 * sizeof(int));
  }
  **a = 1;
  *(*a + 1) = 2;
  **(a + 1) = 3;
  *(*(a + 1) + 1) = 2;
  **b = 3;
  *(*b + 1) = 2;
  **(b + 1) = 1;
  *(*(b + 1) + 1) = 1;
  int n = 2;
  int **mine = matrix_multiplication(a, b, n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%4d", *(*(mine + i) + j));
    printf("\n");
  }
  return 0;
}
