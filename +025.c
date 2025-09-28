//给出一个非负数的整数数列，每个数字代表可以往前“跳跃”的最大距离
//若从数列开头往后，能“跳”到结尾元素，则输出true，否则输出false
//bool canJump(int* nums, int numsSize){}

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

bool canJump(int* nums, int numsSize) {
    //贪心算法O(n)秒了
    if(numsSize <= 1) return true;
    
    int maxReach = 0;  // 当前能到达的最远位置
    
    for(int i = 0; i < numsSize; i++) {
        if(i > maxReach) return false;  // 如果当前位置已经超过了能到达的最远位置
        maxReach = (i + nums[i] > maxReach) ? i + nums[i] : maxReach;
        if(maxReach >= numsSize-1) return true;  // 已经可以到达终点
    }
    
    return false;
}

int main ()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    int nums[1000];
    int numsSize=0;
    int num;

    while (scanf("%d",&num)==1){
        nums[numsSize++]=num;
    }

    printf("%d", canJump(nums, numsSize)?1:0);

    return 0;
}