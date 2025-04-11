
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_max(int numbers[], int n) {
  numbers[0] = abs(numbers[0]);
  int max = numbers[0];
  for (int i = 1; i < n; i++) {
    numbers[i] = abs(numbers[i]);
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}
int prime_num(int number) {
  int i;
  for (i = 2; i * i <= number; i++) {
    if (number % i == 0)
      return false;
  }
  return true;
}
void find_primes(short *isprime, int n) {

  for (int i = 0; i < n; i++) {
    if (prime_num(i)) {
      isprime[i] = 1;
    }
  }
}
char *sumOfDivided(const int numbers[/*count*/], int count) {
  if (count == 0)
    return "";
  int *number = malloc(count * sizeof(int));
  memcpy(number, numbers, count * sizeof(int));
  int max = find_max(number, count);
  max++;
  int *sums = calloc(max, sizeof(int));
  short *isprime = calloc(max, sizeof(short));
  find_primes(isprime, max);
  for (int i = 0; i < count; i++) {
    for (int j = 2; j <= number[i]; j++) {
      if (number[i] % j == 0) {
        if (isprime[j] > 0) {
          isprime[j] = 2;
          sums[j] += numbers[i];
        }
      }
    }
  }
  char *mine = malloc(10000);
  int index = 0;
  int size = 0;
  for (int i = 0; i < max; i++) {
    if (isprime[i] == 2) {

      index = sprintf(mine, "(%d %d)", i, sums[i]);
      mine += index;
      size += index;
    }
  }
  return mine - size;
}

int main() {

  int numbers[5] = {-29804, -4209, -28265, -72769, -31744};
  char *mine = sumOfDivided(numbers, 5);
  printf("\n%s\n", mine);
  return 0;
}
