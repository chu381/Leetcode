//小括号配对问题，给定一个字符串s，其中包含"("")""*"三种字符，其中*可以代指任意一种括号或者空白
//输入s，输出判断，若配对，则输出True，否则输出False
//bool checkValidString(char* s){}

#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

bool checkValidString(char* s){
    int i=0;
    int minCount=0;  //最小的（数量
    int maxCount=0;  //最大的（数量
    while(s[i]!='\0'){
        if(s[i]=='('){
            minCount++;
            maxCount++;
        }else if(s[i]==')'){
            minCount--;
            maxCount--;
        }else if(s[i]=='*'){
            minCount--;
            maxCount++;
        }
        if(maxCount<0)return false;   //右）无论如何多于左（，输出false
        if(minCount<0)minCount=0;     //这是在maxCount>=0的情况下发生的，所以其实是因为某个*当）导致）太多，看作是把一颗*变成空格即可
        i++;
    }
    return minCount==0;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 测试用例
    char* test_cases[] = {
        "()",      // True
        "(*)",     // True
        "(*))",    // True
        "((*)",    // True
        ")",       // False
        "(",       // False
        "*)",      // True
        "((*",     // False
        ")*",      // False
        "()(*",    // True
        "()*()",   // True
        "*(()",    // False
        "(*()",    // True
        "**())",   // True
        "**(())",  // True
        "*("       // False
    };
    
    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    
    for (int i = 0; i < num_tests; i++) {
        bool result = checkValidString(test_cases[i]);
        printf("测试用例 \"%s\": %s\n", test_cases[i], result ? "True" : "False");
    }
    
    return 0;
}