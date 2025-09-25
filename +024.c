//写一个工具，要求数据元素[a, b]表示键为a，值为b，取出时先入先出类似队列

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head; 
    Node* tail; 
    Node** hashMap;
} LRUCache;

Node* createNode(int key, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LRUCache* lRUCacheCreate(int capacity){
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    
    cache->head = createNode(-1, -1);
    cache->tail = createNode(-1, -1);
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    
    cache->hashMap = (Node**)calloc(10001, sizeof(Node*));
    return cache;
}

void moveToHead(LRUCache* obj, Node* node) {

    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = obj->head->next;
    node->prev = obj->head;
    obj->head->next->prev = node;
    obj->head->next = node;
}

void removeTail(LRUCache* obj) {
    Node* tailNode = obj->tail->prev;
    obj->hashMap[tailNode->key] = NULL; 
    tailNode->prev->next = obj->tail;
    obj->tail->prev = tailNode->prev;
    
    free(tailNode);
    obj->size--;
}

int lRUCacheGet(LRUCache* obj, int key){
    if (key < 0 || key > 10000 || obj->hashMap[key] == NULL) {
        return -1;
    }
    Node* node = obj->hashMap[key];
    moveToHead(obj, node); 
    return node->value;
}

void lRUCachePut(LRUCache* obj, int key, int value){
    if (key < 0 || key > 10000) return;
    if (obj->hashMap[key] != NULL) {
        Node* node = obj->hashMap[key];
        node->value = value;
        moveToHead(obj, node);
        return;
    }
    Node* newNode = createNode(key, value);
    if (obj->size == obj->capacity) {
        removeTail(obj);
    }
    newNode->next = obj->head->next;
    newNode->prev = obj->head;
    obj->head->next->prev = newNode;
    obj->head->next = newNode;
    obj->hashMap[key] = newNode;
    obj->size++;
}

void lRUCacheFree(LRUCache* obj){

    Node* current = obj->head->next;
    while (current != obj->tail) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    free(obj->head);
    free(obj->tail);
    free(obj->hashMap);
    free(obj);
}

int main()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 测试示例
    LRUCache* cache = lRUCacheCreate(2);
    
    lRUCachePut(cache, 1, 1);
    lRUCachePut(cache, 2, 2);
    printf("获取键1: %d\n", lRUCacheGet(cache, 1)); // 返回1
    lRUCachePut(cache, 3, 3); // 该操作会使得键2作废
    printf("获取键2: %d\n", lRUCacheGet(cache, 2)); // 返回-1（未找到）
    lRUCachePut(cache, 4, 4); // 该操作会使得键1作废
    printf("获取键1: %d\n", lRUCacheGet(cache, 1)); // 返回-1（未找到）
    printf("获取键3: %d\n", lRUCacheGet(cache, 3)); // 返回3
    printf("获取键4: %d\n", lRUCacheGet(cache, 4)); // 返回4
    
    lRUCacheFree(cache);
    return 0;
}