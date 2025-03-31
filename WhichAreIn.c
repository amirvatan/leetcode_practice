#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int pstrcmp(const void *a, const void *b) {
  return strcmp(*(const char **)a, *(const char **)b);
}
char **inArray(char *array1[], int sz1, char *array2[], int sz2, int *lg) {
  char **mine = calloc(sz1, 20 * sizeof(char));
  int index = 0;
  for (int i = 0; i < sz1; i++) {
    for (int j = 0; j < sz2; j++) {
      if (strstr(array2[j], array1[i]) != NULL) {
        mine[index++] = array1[i];
        break;
      }
    }
  }

  qsort(mine, index, sizeof(mine[0]), pstrcmp);
  *lg = index;
  return mine;
}
int main() {
  char *arr1[3] = {"arp", "live", "strong"};
  char *arr2[5] = {"lively", "alive", "harp", "sharp", "armstrong"};
  int lg;
  char **mine = inArray(arr1, 3, arr2, 5, &lg);
  for (int i = 0; i < lg; i++) {
    printf("%s\n", mine[i]);
  }
  return 0;
}
