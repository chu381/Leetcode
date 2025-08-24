//给出若干英文字符串，将里面具有相同字母组合的单词归为一类字符串，输出各个类别和对应字符串
//eg.["tan", "nat", "ate", "tea", "eat", "bat"] => [["tan", "nat"], ["ate", "tea", "eat"], ["bat"]]
//该题目用C语言极其难写
//char *** groupAnagrams(char ** strs, int strsSize, int * returnSize, int ** returnColumnSizes){}

#include<stdio.h>
#include <windows.h>

//char *** groupAnagrams(char ** strs, int strsSize, int * returnSize, int ** returnColumnSizes){}
//必要的解释，看这个C语言版本*号多得没边了，先捋一下存储思路
//首先字符串当做列表存，带有一层指针* ，然后strs列表["tan", "nat", "ate", "tea", "eat", "bat"]是存储字符串的
//因此要再多一层指针* 记为char ** strs
//strsSize就是strs列表的长度标量，存入int
//returnSize 是一个指针变量，指向输出的多个列表的长度
//returnColumnSizes 指向一群指针，这些指针指向多个列表中字符串的数量，如[[3,3],[3,3,3],[3]]

//思路：对字符串排序，一样的就是同一组

int main ()
{
     // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    printf("思路很简单其实，但用C语言写那么多*号实在是脑力大爆炸，等以后有实力了再来碰碰");
    return 0;
}