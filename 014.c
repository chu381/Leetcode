//字符串的平移变换，给定一个字符串s，其中仅包含小写字母
//给定一个变换阵列shift，其中每个元素形为[int, int]
//shift中元素的前一个数字若为1，表示向右平移，0表示向左平移，后一个数字表示平移的次数
//输出这个字符串根据shift中所有变换后得到的结果

//1 <= s.length <= 100
//1 <= shift.length <= 100
//1 <= shift[i][1] <= 100

//char* stringShift(char* s, int** shift, int shiftSize, int* shiftColSize){}

#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

void trans(char* s, int right, int len){
    if (right==0)return;
    for(int i=len+right-1; i>=right; i--){
        s[i]=s[i-right];
    }
    for(int j=0; j<right; j++){
        s[j]=s[len+j];
    }
    s[len]='\0';
}

char* stringShift(char* s, int** shift, int shiftSize){
    int right=0;
    int len=0;
    for(int i=0; i<shiftSize; i++){
        right+=shift[i][0]==1?shift[i][1]:-shift[i][1];
    }
    for(int j=0; s[j]!='\0'; j++)len++;      //s[len]=='\0'
    right%=len;
    if(right<0){
        right+=len;
    }
    trans(s, right, len);
    return s;
}

int main() {
    SetConsoleOutputCP(65001);
    
    // 测试用例
    char s1[] = "abc";
    int shift1[2][2] = {{0, 1}, {1, 2}};
    int* shiftArray1[2];
    for (int i = 0; i < 2; i++) {
        shiftArray1[i] = shift1[i];
    }
    int shiftColSize1 = 2;
    
    printf("测试1 - 原始: %s\n", s1);
    char* result1 = stringShift(s1, shiftArray1, 2);
    printf("变换后: %s (期望: cab)\n\n", result1);
    
    return 0;
}