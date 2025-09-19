//给出一个数组nums和一个目标值k，要求在数组中找到连续的子数列，使其和等于k，输出这种子数列的数量
//数字的大小在[-1000, 1000]中，1<=nums.length<=20000，-1e7<=k<=1e7

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define HASH_TABLE_SIZE 10007  // 选择一个合适的质数作为哈希表大小

typedef struct HashNode {
    int key;
    int count;
    struct HashNode *next;
} HashNode;

HashNode *hashTable[HASH_TABLE_SIZE];

unsigned int hash(int key) {
    return (unsigned int)(key % HASH_TABLE_SIZE + HASH_TABLE_SIZE) % HASH_TABLE_SIZE;
}

void insert(int key) {
    unsigned int index = hash(key);
    HashNode *current = hashTable[index];
    
    while (current != NULL) {
        if (current->key == key) {
            current->count++;
            return;
        }
        current = current->next;
    }
    
    HashNode *newNode = malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int getCount(int key) {
    unsigned int index = hash(key);
    HashNode *current = hashTable[index];
    
    while (current != NULL) {
        if (current->key == key) {
            return current->count;
        }
        current = current->next;
    }
    return 0;
}

int subarraySum(int *nums, int numsSize, int k) {
    // 初始化哈希表
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    
    insert(0);  // 前缀和为0出现1次
    int currSum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        currSum += nums[i];
        int target = currSum - k;
        count += getCount(target);
        insert(currSum);
    }
    
    // 清理哈希表
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        HashNode *current = hashTable[i];
        while (current != NULL) {
            HashNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return count;
}

int main() {
    SetConsoleOutputCP(65001);
    int nums[20000];
    int numsSize = 0;
    int num;
    int k = 100;

    while (scanf("%d", &num) == 1) {
        nums[numsSize++] = num;
    }

    printf("%d", subarraySum(nums, numsSize, k));
    return 0;
}