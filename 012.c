//给定一个整数数组，我们将其中最大的数字和第二大的数字拿出来，两者相等则全部消掉，两者不等则留下差值
//输出最后剩余的数字，若最后不剩数字，则输出0
//1<=stone.length<=30
//1<=stone[i]<=1000

//int lastStoneWeight(int* stones, int stonesSize){}

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void step(int* stones, int stonesSize) {
    int max_index = 0;
    int smax_index = -1;
    
    for (int i = 1; i < stonesSize; i++) {
        if (stones[i] > stones[max_index]) {
            max_index = i;
        }
    }
    
    for (int i = 0; i < stonesSize; i++) {
        if (i != max_index && stones[i] > 0) {
            if (smax_index == -1 || stones[i] > stones[smax_index]) {
                smax_index = i;
            }
        }
    }
    
    if (smax_index != -1) {
        if (stones[max_index] == stones[smax_index]) {
            // 两者相等，都消掉
            stones[max_index] = 0;
            stones[smax_index] = 0;
        } else {
            // 两者不等，留下差值
            stones[max_index] = stones[max_index] - stones[smax_index];
            stones[smax_index] = 0;
        }
    }
}

bool check(int* stones, int stonesSize) {
    int count = 0;
    for (int i = 0; i < stonesSize; i++) {
        if (stones[i] != 0) count++;
    }
    return count > 1;
}

int lastStoneWeight(int* stones, int stonesSize) {
    while (check(stones, stonesSize)) {
        step(stones, stonesSize);
    }

    for (int i = 0; i < stonesSize; i++) {
        if (stones[i] != 0) {
            return stones[i];
        }
    }
    return 0;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    int nums[1000];
    int numsSize = 0;
    int num;

    printf("请输入整数数组（以非数字字符结束输入）：\n");
    while (scanf("%d", &num) == 1) {
        nums[numsSize++] = num;
    }

    printf("最后剩余的数字：%d\n", lastStoneWeight(nums, numsSize));

    return 0;
}