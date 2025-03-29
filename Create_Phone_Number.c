#include <stdint.h>
#include <stdio.h>
char *create_phone_number(char phnum[15], const uint8_t digits[10]) {
  snprintf(phnum, 15, "(%hhu%hhu%hhu) %hhu%hhu%hhu-%hhu%hhu%hhu%hhu", digits[0],
           digits[1], digits[2], digits[3], digits[4], digits[5], digits[6],
           digits[7], digits[8], digits[9]);
  // write to phnum and return it
  // it must be nul-terminated
  return phnum;
}
int main() {

  const uint8_t digits[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  char phnum[15];
  char *val = create_phone_number(phnum, digits);
  printf("%s", val);

  return 0;
}
