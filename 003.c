//Maximum Subarray最大子数列问题 标准 动态规划
// 给出一个数列，规定在里面连续的几个数字为子数列
// 要求算出子数列的数字和最大为多少
// eg.[-2, 1, -3, 4, -1, 2, 1, -5, 4]中，[4, -1, 2, 1]和为6，最大。
//int maxSumArray(int* nums, int numSize){}

#include<stdio.h>
//没有思路，暴力计算

int maxSumArray(int* nums, int numsSize){
    if (numsSize == 0) return 0;
    
    int max = nums[0];
    
    for (int i = 0; i < numsSize; i++) {
        int sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            if (sum > max) {
                max = sum;
            }
        }
    }
    return max;
}

int main ()
{
    int nums[1000];
    int numsSize=0;
    int num;

    while (scanf("%d",&num)==1){
        nums[numsSize++]=num;
    }
    printf("%d",maxSumArray(nums, numsSize));

    return 0;
}