#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int* data;      // 主栈，存储所有元素
    int* min_data;  // 最小栈，存储当前最小值
    int size;       // 当前栈中元素个数
} MinStack;

MinStack* minStackCreate() {
    MinStack* s = malloc(sizeof(MinStack));
    s->data = NULL;
    s->min_data = NULL;
    s->size = 0;
    return s;
}

void minStackPush(MinStack* obj, int x) {
    // 扩展主栈
    obj->data = realloc(obj->data, sizeof(int) * (obj->size + 1));
    obj->data[obj->size] = x;
    
    // 扩展最小栈并计算新的最小值
    obj->min_data = realloc(obj->min_data, sizeof(int) * (obj->size + 1));
    if (obj->size == 0 || x < obj->min_data[obj->size - 1]) {
        obj->min_data[obj->size] = x;
    } else {
        obj->min_data[obj->size] = obj->min_data[obj->size - 1];
    }
    
    obj->size++;
}

void minStackPop(MinStack* obj) {
    if (obj == NULL || obj->size == 0) return;
    obj->size--;
}

int minStackTop(MinStack* obj) {
    if (obj == NULL || obj->size == 0) return INT_MIN;
    return obj->data[obj->size - 1];
}

int minStackGetMin(MinStack* obj) {
    if (obj == NULL || obj->size == 0) return INT_MIN;
    return obj->min_data[obj->size - 1];
}

void minStackFree(MinStack* obj) {
    if (obj == NULL) return;
    
    if (obj->data != NULL) {
        free(obj->data);
    }
    
    if (obj->min_data != NULL) {
        free(obj->min_data);
    }
    
    free(obj);
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    printf("创建最小栈...\n");
    MinStack* obj = minStackCreate();
    
    printf("推入元素: -2\n");
    minStackPush(obj, -2);
    printf("栈顶: %d, 最小值: %d\n", minStackTop(obj), minStackGetMin(obj));
    
    printf("推入元素: 0\n");
    minStackPush(obj, 0);
    printf("栈顶: %d, 最小值: %d\n", minStackTop(obj), minStackGetMin(obj));
    
    printf("推入元素: -3\n");
    minStackPush(obj, -3);
    printf("栈顶: %d, 最小值: %d\n", minStackTop(obj), minStackGetMin(obj));
    
    printf("弹出栈顶元素\n");
    minStackPop(obj);
    printf("栈顶: %d, 最小值: %d\n", minStackTop(obj), minStackGetMin(obj));
    
    printf("弹出栈顶元素\n");
    minStackPop(obj);
    printf("栈顶: %d, 最小值: %d\n", minStackTop(obj), minStackGetMin(obj));
    
    minStackFree(obj);
    printf("栈已释放\n");
    
    return 0;
}