//给出一个数组nums，生成一个新数组，使得这个新数组的每个元素都是nums所有整数乘积除以nums中同一位置的元素
//eg. nums=[1, 2, 3, 4], output=[24, 12, 8, 6]
//nums 中元素均为正整数
//int* productExceptSelf(int* nums, int numsSize, int* returnSize){}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 第一次遍历计算每个位置左侧所有元素的乘积（前缀积）
// 第二次遍历计算每个位置右侧所有元素的乘积（后缀积）
// 将每个位置的前缀积和后缀积相乘得到最终结果

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = malloc(sizeof(int) * numsSize);
    
    // 计算左侧乘积
    result[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    // 计算右侧乘积并同时计算最终结果
    int right = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * right;
        right = right * nums[i];
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
    SetConsoleOutputCP(65001);
    
    int nums[] = {1, 2, 3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    
    int* result = productExceptSelf(nums, numsSize, &returnSize);
    
    printf("输入数组: ");
    printArray(nums, numsSize);
    
    printf("输出数组: ");
    printArray(result, returnSize);
    
    free(result);
    
    return 0;
}