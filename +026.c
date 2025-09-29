//给定两个字符串，输出最长的连续子序列的长度值
//1<=text.length<=1000
//int longestCommenSubsequence(char* text1, char* text2){}

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>

// 动态规划定义：dp[i][j] 表示 text1 的前 i 个字符和 text2 的前 j 个字符的最长公共子序列长度。
// 状态转移方程：
// 如果 text1[i-1] == text2[j-1]：dp[i][j] = dp[i-1][j-1] + 1
// 否则：dp[i][j] = max(dp[i-1][j], dp[i][j-1])
// 边界条件：当任一字符串为空时，LCS长度为0。
// 时间复杂度：O(m×n)，其中 m 和 n 分别是两个字符串的长度。
// 空间复杂度：O(m×n)，用于存储动态规划表。

int longestCommonSubsequence(char* text1, char* text2){
    if(text1 == NULL || text2 == NULL) return 0;
    
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    
    // 创建动态规划表
    int** dp = (int**)malloc((len1 + 1) * sizeof(int*));
    for(int i = 0; i <= len1; i++){
        dp[i] = (int*)malloc((len2 + 1) * sizeof(int));
    }
    
    // 初始化边界条件
    for(int i = 0; i <= len1; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j <= len2; j++){
        dp[0][j] = 0;
    }
    
    // 填充dp表
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(text1[i-1] == text2[j-1]){
                // 字符匹配，长度加1
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                // 字符不匹配，取上方或左方的最大值
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
            }
        }
    }
    
    int result = dp[len1][len2];
    
    // 释放内存
    for(int i = 0; i <= len1; i++){
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

// 测试函数
void testCases(){
    char* test1_1 = "abcde";
    char* test1_2 = "ace";
    printf("测试1: '%s' 和 '%s'\n", test1_1, test1_2);
    printf("最长公共子序列长度: %d\n\n", longestCommonSubsequence(test1_1, test1_2));
    
    char* test2_1 = "abc";
    char* test2_2 = "abc";
    printf("测试2: '%s' 和 '%s'\n", test2_1, test2_2);
    printf("最长公共子序列长度: %d\n\n", longestCommonSubsequence(test2_1, test2_2));
    
    char* test3_1 = "abc";
    char* test3_2 = "def";
    printf("测试3: '%s' 和 '%s'\n", test3_1, test3_2);
    printf("最长公共子序列长度: %d\n\n", longestCommonSubsequence(test3_1, test3_2));
    
    char* test4_1 = "abcdefg";
    char* test4_2 = "bdf";
    printf("测试4: '%s' 和 '%s'\n", test4_1, test4_2);
    printf("最长公共子序列长度: %d\n\n", longestCommonSubsequence(test4_1, test4_2));
}

int main(){
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    printf("最长公共子序列测试:\n");
    printf("==================\n\n");
    
    testCases();
    
    // 用户输入测试
    char text1[1001], text2[1001];
    printf("\n请输入第一个字符串: ");
    scanf("%1000s", text1);
    printf("请输入第二个字符串: ");
    scanf("%1000s", text2);
    
    int result = longestCommonSubsequence(text1, text2);
    printf("\n'%s' 和 '%s' 的最长公共子序列长度: %d\n", text1, text2, result);
    
    return 0;
}