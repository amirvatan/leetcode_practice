#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *highestScoringWord(const char *str) {

  int len = 0;
  int max_len = 0;
  int score = 0;
  int max_score = 0;
  int index = 0;
  int max_index = 0;
  const char *me = str;
  while (*me != '\0') {
    if (*me == ' ') {
      index += len + 1;
      len = 0;
      score = 0;
      me++;
      continue;
    }
    score += *me - 96;
    len++;
    if (score > max_score) {
      max_score = score;
      max_len = len;
      max_index = index;
    }
    me++;
  }
  char *mine = malloc(max_len);
  memcpy(mine, str + max_index, max_len);
  return mine;
}
int main() {
  const char *str = "man i need a taxi up to ubud";
  char *mine = highestScoringWord(str);
  printf("%s", mine);
  return 0;
}
