//给出一个数组nums，生成一个新数组，使得这个新数组的每个元素都是nums所有整数乘积除以nums中同一位置的元素
//eg. nums=[1, 2, 3, 4], output=[24, 12, 8, 6]
//nums 中元素均为正整数
//int* productExceptSelf(int* nums, int numsSize, int* returnSize){}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        result[i] = 1;
    }
    for (int j = 0; j < numsSize; j++) {
        for (int m = 0; m < numsSize; m++) {
            if (m == j) continue;
            result[j] *= nums[m];
        }
    }
    *returnSize = numsSize;
    return result;
}

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = productExceptSelf(nums, numsSize, &returnSize);
    
    printf("输入数组: ");
    printArray(nums, numsSize);
    
    printf("输出数组: ");
    printArray(result, returnSize);
    
    free(result); // 释放动态分配的内存
    
    return 0;
}