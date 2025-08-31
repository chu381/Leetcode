//给一个数列nums[]，将里面的0元素移动到末尾，其余数字顺序不变排在前面
//void moveZeroes(int* nums; int numsSize){}

#include<stdio.h>

void moveZeroes(int* nums, int numsSize){
    int count=0;
    int head=0;
    for(int i=0; i<numsSize; i++){
        if(nums[i]==0){
            count++;
        }else{
            nums[head]=nums[i];
            head++;
        }
    }
    for(int j=0; j<count; j++){
        nums[head]=0;
        head++;
    }
    return;
}

int main ()
{    
    int nums[1000];
    int numsSize=0;
    int num;

    while (scanf("%d",&num)==1){
        nums[numsSize++]=num;
    }

    printf("%d", nums[0]);
    moveZeroes(nums, numsSize);
    for(int i=1; i<numsSize ;i++){
        printf(" %d",nums[i]);
    }
    return 0;
}