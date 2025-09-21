//给出两个整数m，n，其中0<=m<=n<=2147483647(INT_MAX)
//对区间[m, n]中的数字依次进行逐位and运算（m & m+1 & ··· &n），输出结果
//int rangeBitwiseAnd(int m, int n){}

#include<stdio.h>
#include<windows.h>

int rangeBitwiseAnd(int m, int n){
    int ans=m;
    for(int i=m+1; i<n; i++){
        ans=ans&i;
    }
    ans=ans&n;
    return ans;
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