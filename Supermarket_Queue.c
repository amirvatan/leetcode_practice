#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int find_min(const int *arr, int arr_length) {
  int min = arr[0];
  int index = 0;
  for (int i = 1; i < arr_length; i++) {
    if (min > arr[i]) {
      min = arr[i];
      index = i;
    }
  }

  return index;
}
int find_max(const int *arr, int arr_length) {
  int max = arr[0];
  for (int i = 1; i < arr_length; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }

  return max;
}
int queue_time(const int *customers, int customers_length, int n) {

  int index = 0;
  int *vals = malloc(n * sizeof(int));
  memset(vals, 0, n * sizeof(int));
  for (int i = 0; i < customers_length; i++) {
    index = find_min(vals, n);
    vals[index] += customers[i];
  }
  int value = find_max(vals, n);
  free(vals);
  return value;
}

int main() {

  int customers[] = {2, 2, 3, 3, 4, 4};
  int len = 6;
  int n = 2;
  int val = queue_time(customers, len, n);
  printf("%d", val);
  return 0;
}
