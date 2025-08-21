//Maximum Subarray最大子数列问题 标准 动态规划
// 给出一个数列，规定在里面连续的几个数字为子数列
// 要求算出子数列的数字和最大为多少
// eg.[-2, 1, -3, 4, -1, 2, 1, -5, 4]中，[4, -1, 2, 1]和为6，最大。
//int maxSumArray(int* nums, int numSize){}

#include<stdio.h>
//动态规划法，时间复杂度o(n)
//可以理解为一个链，记数组dp[], 其中dp[i]表示以下标i为最后一个数字的连续子数列中，最大的那一个
//我们发现，当dp[i-1]>0时，dp[i]=dp[i-1]+nums[i]，当dp[i-1]<0时，dp[i]=nums[i]
//于是，一路平推到dp[numSize-1]，找到dp数组中的最大值，即为最后答案

int maxSumArray(int* nums, int numsSize){
    int dp[1000]={0};
    int answer=nums[0];
    dp[0]=nums[0];
    for(int i=1; i<numsSize; i++){
        if(dp[i-1]>0){
            dp[i]=dp[i-1]+nums[i];
        }else{
            dp[i]=nums[i];
        }
        if(dp[i]>answer){
            answer=dp[i];
        }
    }
    return answer;

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