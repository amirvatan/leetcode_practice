#include <stdio.h>
#include <string.h>
#define COUNTS_SIZE 128

//  assign char counts to the provided pre-allocated array
//  pre-existing values in array aren't guaranteed to be 0
//  from test string: "aaa", counts['a'] should be == to 3

void count(const char *string, unsigned counts[COUNTS_SIZE]) {
  memset(counts, 0, COUNTS_SIZE * sizeof(unsigned));
  if (*string == '\0') {
    return;
  }
  while (*string != '\0') {
    counts[*string] += 1;
    string++;
  }
  return;
}
int main() {
  const char *str = "aba";
  unsigned counts[COUNTS_SIZE] = {0};
  count(str, counts);
  for (int i = 0; i < COUNTS_SIZE; i++) {
    printf("%d", counts[i]);
  }
  return 0;
}
