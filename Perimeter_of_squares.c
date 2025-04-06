#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ull;

ull perimeter(int n) {
  if (n == 0)
    return 4;

  n++;
  ull *numbers = malloc(n * sizeof(ull));
  numbers[0] = 1;
  numbers[1] = 1;
  ull res = 2;
  for (int i = 2; i < n; i++) {
    numbers[i] = numbers[i - 1] + numbers[i - 2];
    res += numbers[i];
  }
  return res * 4;
}

int main() {

  int n = 7;
  ull mine = perimeter(n);
  printf("%llu", mine);
}
