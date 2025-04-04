#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
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
  char *data = calloc(10000, sizeof(char));
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
char *read_code(char *path) {
  FILE *file = fopen(path, "r");
  if (file == NULL) {
    printf("Failed to read file");
    exit(1);
  }
  int size = 100;
  int i = 0;
  char *code = calloc(size, sizeof(char));
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n' || c == '\0' || isblank(c) != 0) {
      continue;
    }
    if (i == size) {
      code = (char *)realloc(code, size * 2 * sizeof(char));
      size = size * 2;
    }
    code[i] = c;
    i++;
  }
  code[i] = '\0';
  return code;
}

int main() {
  char *code = read_code("mine.b");
  const char *input = (char[]){8, 9};
  char output[5000];
  brainfuck(code, input, output);
  printf("%s", output);
  return 0;
}
