//给出两个字符串，其中“#”代表删除，判断两个字符串是否完全一致
//bool backspaceCompare(char* S, char* T){}

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>

char* process(char* str){
    int head = -1;
    int tail = -1;
    while(str[tail + 1] != '\0'){
        tail += 1;
        if(str[tail] == '#'){
            if(head != -1){
                head--;
            }
        }else{
            head++;
            str[head] = str[tail];
        }
    }
    head++;
    str[head] = '\0';
    return str;
}

bool backspaceCompare(char* S, char* T){
    // 先处理两个字符串
    S = process(S);
    T = process(T);
    
    // 然后比较处理后的结果
    return strcmp(S, T) == 0;
}

int main()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 测试用例
    char S1[] = "ab#c";
    char T1[] = "ad#c";
    printf("S: %s, T: %s, 结果: %s\n", S1, T1, 
           backspaceCompare(S1, T1) ? "相同" : "不同");
    
    char S2[] = "ab##";
    char T2[] = "c#d#";
    printf("S: %s, T: %s, 结果: %s\n", S2, T2, 
           backspaceCompare(S2, T2) ? "相同" : "不同");
    
    char S3[] = "a##c";
    char T3[] = "#a#c";
    printf("S: %s, T: %s, 结果: %s\n", S3, T3, 
           backspaceCompare(S3, T3) ? "相同" : "不同");
    
    char S4[] = "a#c";
    char T4[] = "b";
    printf("S: %s, T: %s, 结果: %s\n", S4, T4, 
           backspaceCompare(S4, T4) ? "相同" : "不同");
    
    return 0;
}