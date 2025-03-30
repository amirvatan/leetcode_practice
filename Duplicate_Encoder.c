#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *DuplicateEncoder(const char *string) {
  int vals[128] = {0};
  const char *temp = string;
  while (*temp != '\0') {
    vals[tolower(*temp)] += 1;
    temp++;
  }
  char *mine = malloc(strlen(string) * sizeof(char));
  temp = string;
  while (*temp != '\0') {
    if (vals[tolower(*temp)] != 1) {
      *mine++ = ')';
    } else {
      *mine++ = '(';
    }
    temp++;
  }
  return mine - strlen(string);
}
int main() {
  const char *str = "(( @";
  char *mine = DuplicateEncoder(str);
  printf("%s", mine);
  return 0;
}
