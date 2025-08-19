//输入一个列表，其中有奇数个正整数，其中有且仅有一个正整数在整个列表里只出现一次，请输出那个数字。
//int singleNumber(int* nums, int numsSize){}

//关于指针，nums给得是一个指针变量，存储的是数组的开头元素位置。其中*(nums+i)==nums[i]

int singleNumber(int* nums, int numsSize){
    //使用到运算符^，XOR互斥或，相同得0，不同出1
    //由于性质：A^A = 0, A^0 = A, A^B = B^A
    //不难得出，经过交换律，最后能化为0^A = A, 其中A为落单数字
    int n=nums[0];
    for (int i=1; i<numsSize; i++){
        n^=nums[i];
    }
    return n;
}

#include<stdio.h>
int main ()
{
    int nums[1000];
    int numsSize=0;
    int num;

    while (scanf("%d",&num)==1 && num!=-1){
        nums[numsSize++]=num;
    }
    printf("%d",singleNumber(nums, numsSize));

    return 0;
}