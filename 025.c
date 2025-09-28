//给出一个非负数的整数数列，每个数字代表可以往前“跳跃”的最大距离
//若从数列开头往后，能“跳”到结尾元素，则输出true，否则输出false
//bool canJump(int* nums, int numsSize){}

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

bool canJump(int* nums, int numsSize){
    if(numsSize<=1)return true;
    nums[numsSize-1]=-1;
    for(int i=numsSize-2; i>=0; i--){
        for(int j=1; j<=nums[i] && j+i<numsSize; j++){
            if(nums[i+j]==-1){
                nums[i]=-1;
                break;
            }
        }
    }
    return nums[0]==-1;
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