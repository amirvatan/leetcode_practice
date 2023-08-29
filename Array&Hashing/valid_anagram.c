#include <stdbool.h>
#include <string.h>
bool isAnagram(char *s, char *t) {
  int sizes = strlen(s);
  int sizet = strlen(t);

  if (sizet != sizes) {
    return false;
  }
  int h[126] = {0};
  for (; *s != '\0';) {
    h[*(s++)]++;
  }
  for (; *t != '\0';) {
    h[*(t++)]--;
  }
  for (int i = 0; i < 126; i++) {
    if (h[i] > 0) {
      return false;
    }
  }
  return true;
}
