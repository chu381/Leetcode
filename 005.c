//有一个数列prices[]，代表每一天的股市价格。我们需要进行交易。
//已知在某天买入之后必须等若干天后卖出，才能进行下一笔交易
//每一笔交易的利润=卖和买的价格之差
//求利润总和的最大值
//int maxProfit(int* prices, int priceSize){}

#include<stdio.h>

//我的思路：将问题转化为寻找数列的高峰和低谷，再根据低谷-高峰的对应关系计算利润
//那不妨假设每过一天就是一步，下坡就是没到低谷，不作操作，上坡就是登山，计入利润
//那这样一步步累加上坡，到了山顶必会出现下坡，停止计数，那算的不就是总利润吗
//遂秒杀

int maxProfit(int* prices, int priceSize){
    int answer=0;

    for(int i=0; i<priceSize-1; i++){
        if(prices[i+1]>prices[i]){
            answer+=prices[i+1]-prices[i];
        }
    }
    return answer;
}


int main ()
{    
    int prices[1000];
    int priceSize=0;
    int num;

    while (scanf("%d",&num)==1){
        prices[priceSize++]=num;
    }

    printf("%d",maxProfit(prices, priceSize));
    return 0;
}