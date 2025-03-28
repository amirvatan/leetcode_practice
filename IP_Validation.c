#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int is_valid_ip(const char *addr) {
  unsigned char a, b, c, d;
  char test[30];
  sscanf(addr, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
  snprintf(test, 30, "%hhu.%hhu.%hhu.%hhu", a, b, c, d);
  return strcmp(addr, test) == 0;
};
int main() {
  const char *str = "12.34.56.1";
  bool val = is_valid_ip(str);
  printf("%d", val);
  return 0;
}
