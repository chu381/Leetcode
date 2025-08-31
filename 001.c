//输入一个列表，其中有奇数个正整数，其中有且仅有一个正整数在整个列表里只出现一次，请输出那个数字。
//int singleNumber(int* nums, int numsSize){}

//关于指针，nums给得是一个指针变量，存储的是数组的开头元素位置。其中*(nums+i)==nums[i]

int singleNumber(int* nums, int numsSize){
    int a[100]={0};
    for(int i=0;i<numsSize;i++){
        a[nums[i]]++;
    }

    for(int i=0;i<100;i++){
        if(a[i]==1){
            return i;
        }
    }
    return -1;
}

#include<stdio.h>
int main ()
{
    int nums[1000];
    int numsSize=0;

    // for(int i=0;;i++){
    //     scanf("%d",&nums[i]);
    //     if (nums[i]==-1){
    //         numsSize=i;
    //         break;
    //     }
    //写得太抽象了，忘如光，for循环不适合用来一次性输入数组如1 1 2 -1
    //一段时间后：似乎可以，我自己搞错了

    int num;
    while (scanf("%d",&num)==1 && num!=-1){
        nums[numsSize++]=num;
    }
    printf("%d",singleNumber(nums, numsSize));
    return 0;
}