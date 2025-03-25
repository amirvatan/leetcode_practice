/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
typedef struct Node {
  int key;
  int value;
  struct Node *next;
} Node;

Node *createNode(int key, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->key = key;
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insert(Node *hashTable[], int key, int value) {
  int index = abs(key) % 1000;
  if (hashTable[index] == NULL) {
    hashTable[index] = createNode(key, value);
  } else {
    Node *newNode = createNode(key, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
  }
}

int search(Node *hashTable[], int key) {
  int index = abs(key) % 1000;
  Node *currentNode = hashTable[index];
  while (currentNode != NULL) {
    if (currentNode->key == key) {
      return currentNode->value;
    }
    currentNode = currentNode->next;
  }
  return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  *returnSize = 2;
  Node *hashTable[1000] = {NULL};
  int *out = malloc(*returnSize * sizeof(int));

  for (int i = 0; i < numsSize; i++) {
    int complement = target - nums[i];
    int complementIndex = search(hashTable, complement);
    if (complementIndex != -1) {
      out[0] = i;
      out[1] = complementIndex;
      break;
    }
    insert(hashTable, nums[i], i);
  }
  return out;
}
