//字符串的平移变换，给定一个字符串s，其中仅包含小写字母
//给定一个变换阵列shift，其中每个元素形为[int, int]
//shift中元素的前一个数字若为1，表示向右平移，0表示向左平移，后一个数字表示平移的次数
//输出这个字符串根据shift中所有变换后得到的结果

//1 <= s.length <= 100
//1 <= shift.length <= 100
//1 <= shift[i][1] <= 100

//char* stringShift(char* s, int** shift, int shiftSize, int* shiftColSize){}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 使用三次反转法实现循环右移
void reverse(char* s, int start, int end) {    //从start到end镜像翻转
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void trans(char* s, int right, int len) {
    if (right == 0 || len == 0) return;
    
    // 三次反转法实现循环右移
    reverse(s, 0, len - right - 1);    // 反转前部分
    reverse(s, len - right, len - 1);  // 反转后部分
    reverse(s, 0, len - 1);            // 整体反转
}

//解释：
// 若0<=i<=len-right-1，则有i -> len-right-1-i -> len-1-(len-right-1-i)=i+right
// 若len-right<=i<=len-1，则有i -> 2len-right-1-i -> len-1-(2len-right-1-i)=i+right-len
// 这个 i+right 必然大于len，所以需要消去进位
// 综上，当一列元素的后n个数字翻转，前面数字翻转，再整体翻转之后，等价于右移n格

char* stringShift(char* s, int** shift, int shiftSize, int* shiftColSize) {
    int totalShift = 0;
    int len = strlen(s);
    
    // 计算总平移量
    for (int i = 0; i < shiftSize; i++) {
        if (shift[i][0] == 1) { // 向右平移
            totalShift += shift[i][1];
        } else { // 向左平移
            totalShift -= shift[i][1];
        }
    }
    
    // 处理总平移量，确保在 [0, len-1] 范围内
    totalShift %= len;
    if (totalShift < 0) {
        totalShift += len;
    }
    
    // 执行平移操作
    trans(s, totalShift, len);
    
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
    char* result1 = stringShift(s1, shiftArray1, 2, &shiftColSize1);
    printf("变换后: %s (期望: cab)\n\n", result1);
    
    return 0;
}