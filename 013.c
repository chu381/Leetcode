//给出一个只包含0或者1的数组，当某一连续子列中的0和1个数相等，则称这个连续子列为“A子列”
//求A子列长度的最大值
//nums.length<=50000
//int findMaxLength(int* nums, int numsSize){}

#include<stdio.h>
#include <windows.h>

int findMaxLength(int* nums, int numsSize){
    //count=0，遇到1加1，遇到0减1，构造count数组，寻找相同两数字距离的最大值
    int count=0;
    for(int i=0; i<numsSize; i++){
        nums[i]=count+nums[i]*2-1;
    }
    int head=-1;
    int tail=numsSize-1;
    while(nums[tail]>0 && nums[tail-1]<nums[tail]){
        tail--;
    }
    while(nums[tail]<0 && nums[tail-1]>nums[tail]){
        tail--;
    }
    while(nums[tail]>0 && nums[head+1]>0){
        head++;
    }
    while(nums[tail]<0 && nums[head+1]<0){
        head++;
    }
    if(head=-1 && nums[tail]==0)return tail-head;
    if(nums[head]=nums[tail])return tail-head;
    return findMaxLength(&nums[head+1], numsSize-2);
    //哇，这个代码结构真的是依托答辩，难绷，等着优化吧
}

int main ()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    int nums[1000];
    int numsSize = 0;
    int num;

    printf("请输入数组（以非数字字符结束输入）：\n");
    while (scanf("%d", &num) == 1 &&(num==0 || num==1)) {
        nums[numsSize++] = num;
    }

    printf("结果：%d\n", findMaxLength(nums, numsSize));
    return 0;
}