#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *strsum(const char *a, const char *b) {

  int sa = strlen(a) - 1;
  int sb = strlen(b) - 1;
  char *ma;
  char *mb;
  if (sa == -1 && sb == -1) {
    char *sum = malloc(2);
    sum[0] = '0';
    sum[1] = '\0';
    return sum;
  }
  if (sa == -1) {
    ma = malloc(sb + 2);

    memset(ma, '0', sb + 2);
  } else {
    ma = malloc(sa + 2);

    memcpy(ma, a, sa + 2);
  }
  if (sb == -1) {
    mb = malloc(sa + 2);

    memset(mb, '0', sa + 2);
  } else {
    mb = malloc(sb + 2);

    memcpy(mb, b, sb + 2);
  }

  int i = sa >= sb ? sa + 2 : sb + 2;

  char *sum = malloc(++i);
  memset(sum, '0', i);
  sum[--i] = '\0';
  int index = 0;
  int val;
  while (sa > -1 && sb > -1) {

    index = (val = (ma[sa--] - '0') + (mb[sb--] - '0') + index) > 9 ? 1 : 0;
    sum[i--] = index != 0 ? (val - 10) + '0' : val + '0';
  }
  while (sa > -1) {

    index = (val = (ma[sa--] - '0') + index) > 9 ? 1 : 0;
    sum[i--] = index != 0 ? (val - 10) + '0' : val + '0';
  }

  while (sb > -1) {

    index = (val = (mb[sb--] - '0') + index) > 9 ? 1 : 0;
    sum[i--] = index != 0 ? (val - 10) + '0' : val + '0';
  }
  if (index > 0) {
    sum[i--] = index + '0';
  }
  while (*(++sum) == '0' && *(sum + 1) != '\0') {
  }
  return sum;
}
int main() {
  const char *a = "356404416137372611308451401270973288838874553111173593803138"
                  "567425873230821272867877057364002043134129964741387060779325"
                  "0849919814260342594321304327596167096634407461372359677319";

  const char *b = "3121011409789692622942225132394500962345320382";
  char *output = strsum(a, b);
  printf("%s\n", output);
  if (strcmp("35640441613737261130845140127097328883887455311117359380313856742"
             "58732308212728678770573640020431341299647413870607793250849919814"
             "263463605731094020219109321766801962334704997701",
             output) == 0) {
    printf("%lu", strlen(""));
  }
  return 0;
}
