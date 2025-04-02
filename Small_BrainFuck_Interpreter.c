#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *find_match(const char *code, char c) {
  int num = 0;
  if (c == '[') {
    while (*code++ != '\0') {
      if (*code == '[') {
        num++;
      } else if (*code == ']' && num == 0) {
        code++;
        return code;
      } else if (*code == ']') {
        num--;
      }
    }
  } else if (c == ']') {
    while (*code--) {
      if (*code == ']') {
        num++;
      } else if (*code == '[' && num == 0) {
        code++;
        return code;
      } else if (*code == '[') {
        num--;
      }
    }
  }
  return "";
}
void brainfuck(const char *code, const char *input, char *output) {
  char *data = malloc(5000);
  memset(data, 0, 5000);
  int i = 0;
  char *mine = code;
  while (*mine != '\0') {
    switch (*mine) {
    case ',':
      *data = *input++;
      mine++;
      break;
    case '[':
      if (*data == 0) {
        mine = find_match(mine, *mine);
        break;
      } else {
        mine++;
        break;
      }
    case ']':
      if (*data != 0) {
        mine = find_match(mine, *mine);
        break;
      } else {
        mine++;
        break;
      }
    case '.':
      output[i++] = *data;
      mine++;
      break;
    case '>':
      data++;
      mine++;
      break;
    case '<':
      data--;
      mine++;
      break;
    case '+':
      *data = *data + 1;
      mine++;
      break;
    case '-':
      *data = *data - 1;
      mine++;
      break;
    }
  }
  output[i] = '\0';
}
int main() {
  const char *code = ",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.";
  const char *input = (char[]){8, 9};
  char output[1025];
  brainfuck(code, input, output);
  printf("%s", output);
  return 0;
}
