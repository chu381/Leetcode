//给出两个整数m，n，其中0<=m<=n<=2147483647(INT_MAX)
//对区间[m, n]中的数字依次进行逐位and运算（m & m+1 & ··· &n），输出结果
//int rangeBitwiseAnd(int m, int n){}

#include<stdio.h>
#include<windows.h>

int rangeBitwiseAnd(int m, int n){
    int shift = 0;
    // 找到m和n的公共前缀
    //思路，按位次And运算，只要这一位有一个0，答案的这一位就是0
    //所以我们只需要找到区间内全为1的数字即可
    //又因为，这是一个连续的数列，所以假设m和n具有一段相同的头部
    //如（11011）0101和（11011）1001，那么我们就会发现，后面的位数上都是会出现0的
    //最终答案就会是（11011）0000
    //故，先让m和n一起位移shift次直到m=n。这时找到了相同前缀，就再补shift个0就好了
    while (m < n) {
        m >>= 1;   //>>表示二进制右移，如10010101->1001010，<<同理
        n >>= 1;
        shift++;
    }
    return m << shift;
}

int main ()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    int m=0; 
    int n=0;
    scanf("%d %d", &m, &n);
    printf("%d", rangeBitwiseAnd(m, n));
    return 0;
}