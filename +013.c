//给出一个只包含0或者1的数组，当某一连续子列中的0和1个数相等，则称这个连续子列为“A子列”
//求A子列长度的最大值
//nums.length<=50000
//int findMaxLength(int* nums, int numsSize){}

#include <stdio.h>
#include <windows.h>
#define MAX_SIZE 50000
#define HASH_SIZE (2 * MAX_SIZE + 1)  // 从 -50000 到 +50000

int findMaxLength(int* nums, int numsSize) {
    int count = 0;
    int hash[HASH_SIZE];
    int answer = 0;
    
    // 初始化哈希表
    for (int i = 0; i < HASH_SIZE; i++) {
        hash[i] = -1;
    }
    
    // 初始状态：count=0 出现在索引 -1 处
    hash[MAX_SIZE] = -1;
    
    for (int j = 0; j < numsSize; j++) {
        count += (nums[j] == 1) ? 1 : -1;
        int hash_index = count + MAX_SIZE;  // 将count映射到[0, 100000]范围
        
        if (hash[hash_index] == -1) {
            // 第一次出现这个count值，记录当前位置
            hash[hash_index] = j;
        } else {
            // 之前出现过这个count值，计算子数组长度
            int length = j - hash[hash_index];
            if (length > answer) {
                answer = length;
            }
        }
    }
    
    return answer;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    int nums[50000];
    int numsSize = 0;
    int num;

    printf("请输入数组（以非数字字符结束输入）：\n");
    while (scanf("%d", &num) == 1 && (num == 0 || num == 1)) {
        nums[numsSize++] = num;
    }

    printf("结果：%d\n", findMaxLength(nums, numsSize));
    return 0;
}