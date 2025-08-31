//判断happy数字。对一个数字的每一位上的数计算平方和
// 如123 => 1*1 + 2*2 + 3*3 =14，记为一次操作
// 经过若干次操作之后，如果结果=1，则为happy数字
// 若无论经过多少操作（循环）都无法得到1，则不是happy数字
// 输入一个数字，输出判断结果。
//bool isHappy(int n){}

//思路：判断循环路径

#include<stdio.h>
#include<stdbool.h>

int change(int n){
    //计算每一位数字平方和
    int copy=n;
    int answer=0;
    while(copy){
        answer+=(copy%10)*(copy%10);
        copy/=10;
    }
    return answer;
}

bool isHappy(int n){
    //思路：龟兔赛跑，乌龟一次往前走一格，兔子一次往前走两格
    //若数字不循环，则两者不可能相等
    //当数字循环时，由于进入循环的时间不同，龟兔可能会处在循环不同的位置
    //但是由于兔子速度快1，所以这个追及模型下兔子一定会追上乌龟
    // 于是当两者数字相等时，意味着此时数列存在循环
    // 又因为循环中如果出现数字1，则必定是11111自己循环，即happy数字
    // 所以只要判断到数字相等时的大小，若不是1，则不是happy数字
    int slow=n;
    int fast=n;
    do{
        slow=change(slow);
        fast=change(fast);
        fast=change(fast);
    }while(slow!=fast);
    return slow==1;
    //这样将不会有越界问题，而且时间复杂度仅有o(n)
}

int main ()
{
    int n=0;
    scanf("%d",&n);
    printf("%d",isHappy(n));
    return 0;
}