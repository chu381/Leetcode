//给定一个自然数数组，其中一些数字+1之后依旧存在于这个数组中，我们需要求出这种数字的数量并输出
//已知这个数组的长度 1 <= arr.length <= 1000, 0 <= arr[i] <= 1000
//int countElements(int* arr, int arrSize){}

#include<stdio.h>

int countElements(int* arr, int arrSize){
    int count[1001]={0};
    int answer=0;
    for(int i=0; i<arrSize; i++){
        count[arr[i]]++;
    }
    for(int j=0; j<1000; j++){
        if(count[j]>0 && count[j+1]>0){
            answer+=count[j];
        }
    }
    return answer;
}

int main ()
{    
    int arr[1000];
    int arrSize=0;
    int num;

    while (scanf("%d",&num)==1){
        arr[arrSize++]=num;
    }

    printf("%d", countElements(arr, arrSize));
    return 0;
}