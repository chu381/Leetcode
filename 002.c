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
    //我的思路：建数组
    int nums[1000]={0};
    int p=-1;
    p++;
    nums[p]=n;
    while(1){

        n=change(n);
        if(n==1){
            return true;
        }
        p++;
        nums[p]=n;
        for(int i=0;i<p;i++){
            if(nums[i]==n){
                return false;
            }
        }
    }
}

int main ()
{
    int n=0;
    scanf("%d",&n);
    printf("%d",isHappy(n));
    return 0;
}
// 几乎正确了，只不过超过1000的循环会越界，仍然存在瑕疵