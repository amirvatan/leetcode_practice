#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestConsec(const char *const strings[], int arr_len, int k) {
  if (arr_len == 0 || arr_len < k || k == 0)
    return "";

  int index = 0;
  int max_len = 0;
  int len = 0;
  int temp = 0;
  for (int i = 0; i < arr_len - k + 1; i++) {
    while (temp < k) {
      len += strlen(strings[i + temp]);
      temp++;
    }
    if (len > max_len) {
      max_len = len;
      index = i;
    }
    len = 0;
    temp = 0;
  }
  char *mine = malloc((max_len) * sizeof(char));
  int i = 0;
  while (i < k) {
    strcpy(mine, strings[index + i]);
    mine += strlen(strings[index + i]);
    i++;
  }
  return mine - (max_len);
}

int main() {
  int size = 6;
  const char *const strarr[6] = {"tree", "foling", "trashy",
                                 "blue", "abcdef", "uvwxyz"};
  int k = 2;
  char *mine = longestConsec(strarr, size, k);
  printf("%s", mine);
  free(mine);
  return 0;
}
