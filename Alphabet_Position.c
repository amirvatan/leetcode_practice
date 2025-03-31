#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alphabet_position(const char *text) {
  size_t size = strlen(text) * 3;
  char *mine = malloc(size);

  *mine = '\0';
  char *me = mine;
  while (*text != '\0') {
    char c = tolower(*text++);
    if (isalpha(c)) {
      mine += sprintf(mine, "%d ", c - 96);
    }
  }

  *--mine = '\0';

  return me;
}
int main() {
  const char *str = "this is how you sould do this";
  char *mine = alphabet_position(str);
  printf("%s", mine);
  return 0;
}
