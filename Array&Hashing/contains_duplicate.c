#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2) {
  return (*(int *)elem1 - *(int *)elem2);
}

bool containsDuplicate(int *nums, int numsSize) {
  qsort(nums, numsSize, sizeof(int), comp);
  for (int i = 0; i < (numsSize - 1); i++) {
    if (nums[i] == nums[i + 1]) {
      return true;
    }
  }
  return false;
}
