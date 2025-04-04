#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

double mean_square_error(size_t n, const int a[n], const int b[n]) {

  double res = 0;
  for (int i = --n; i > -1; i--)
    res += pow((a[i] - b[i]), 2);
  return res / ++n;
}
int main() {

  const int a[4] = {10, 20, 10, 2};
  const int b[4] = {10, 25, 5, -2};

  double mine = mean_square_error(4, a, b);
  printf("%f", mine);
  return 0;
}
