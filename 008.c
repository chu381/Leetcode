//链表题，找到一个链表的中间一项（若为偶数，取中间偏后的一项）
// struct ListNode{
//     int val;
//     struct ListNode* next;
// };

//struct ListNode* middleNode(struct ListNode* head){}


#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast == NULL) {
            break;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

//之后的内容由AI补全

// 创建链表节点
struct ListNode* createNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 释放链表内存
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    int num;
    
    printf("请输入一串数字（以空格分隔，按回车结束）: ");
    
    // 读取输入的数字并构建链表
    while (scanf("%d", &num) == 1) {
        struct ListNode* newNode = createNode(num);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        // 检查下一个字符，如果是换行符则退出循环
        char c = getchar();
        if (c == '\n') {
            break;
        }
        ungetc(c, stdin); // 如果不是换行符，放回输入流
    }
    
    if (head == NULL) {
        printf("链表为空！\n");
        return 0;
    }
    
    // 找到中间节点
    struct ListNode* middle = middleNode(head);
    printf("中间节点的值为: %d\n", middle->val);
    
    // 释放链表内存
    freeList(head);
    
    return 0;
}