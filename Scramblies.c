#include <stdbool.h>
#include <stdio.h>
#include <string.h>
bool scramble(const char *str1, const char *str2) {
  int i = strlen(str1) - 1;
  int frequence[26] = {0};
  while (i > -1)
    frequence[str1[i--] - 96]++;
  i = strlen(str2) - 1;
  while (i > -1)
    if (--frequence[str2[i--] - 96] < 0)
      return false;

  return true;
}

int main() {

  const char *str1 = "katas";
  const char *str2 = "steak";
  bool mine = scramble(str1, str2);
  printf("%d", mine);
  return 0;
}
