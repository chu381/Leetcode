//二叉树，搜寻树，这个树结构的任意一个节点，左子树上的所有元素比它小，右子树的所有元素比它大
//输入这个树的前序遍历（根左右），输出这个树的顺序存储（空元素为NULL）

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct TreeNode {
    int val;
    struct TreeNode* Left;
    struct TreeNode* Right;
};

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) {
    if (preorder == NULL) {
        return NULL;
    }
    if (preorderSize == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->val = preorder[0];
    
    if (preorderSize == 1) {
        root->Left = NULL;
        root->Right = NULL;
        return root;
    }
    
    int rightStart = -1;
    for (int i = 1; i < preorderSize; i++) {
        if (preorder[i] > preorder[0]) {
            rightStart = i;
            break;
        }
    }
    
    if (rightStart == -1) {
        root->Left = bstFromPreorder(preorder + 1, preorderSize - 1);
        root->Right = NULL;
    } else if (rightStart == 1) {
        root->Left = NULL;
        root->Right = bstFromPreorder(preorder + 1, preorderSize - 1);
    } else {
        root->Left = bstFromPreorder(preorder + 1, rightStart - 1);
        root->Right = bstFromPreorder(preorder + rightStart, preorderSize - rightStart);
    }
    
    return root;
}

int treeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = treeHeight(root->Left);
    int rightHeight = treeHeight(root->Right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void treeToArray(struct TreeNode* root, struct TreeNode*** array, int index, int size) {
    if (root == NULL || index >= size) {
        return;
    }
    (*array)[index] = root;
    if (2 * index + 1 < size) {
        treeToArray(root->Left, array, 2 * index + 1, size);
    }
    if (2 * index + 2 < size) {
        treeToArray(root->Right, array, 2 * index + 2, size);
    }
}

void printArrayStorage(struct TreeNode* root) {
    if (root == NULL) {
        printf("[NULL]\n");
        return;
    }
    
    int height = treeHeight(root);
    int size = (1 << height) - 1; // 2^height - 1
    struct TreeNode** array = (struct TreeNode**)calloc(size, sizeof(struct TreeNode*));
    if (array == NULL) {
        printf("内存分配失败\n");
        return;
    }
    
    treeToArray(root, &array, 0, size);
    printf("[");
    for (int i = 0; i < size; i++) {
        if (array[i] == NULL) {
            printf("NULL");
        } else {
            printf("%d", array[i]->val);
        }
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
    free(array);
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->Left);
    freeTree(root->Right);
    free(root);
}

int main() {
    SetConsoleOutputCP(65001);
    printf("二叉搜索树前序遍历转顺序存储测试:\n\n");
    
    // 测试用例1
    int preorder1[] = {8, 5, 1, 7, 10, 12};
    int size1 = sizeof(preorder1) / sizeof(preorder1[0]);
    struct TreeNode* root1 = bstFromPreorder(preorder1, size1);
    printf("测试用例1 - 前序遍历: [8, 5, 1, 7, 10, 12]\n");
    printf("顺序存储结果: ");
    printArrayStorage(root1);
    freeTree(root1);
    printf("\n");
    
    // 测试用例2
    int preorder2[] = {4, 2, 1, 3, 6, 5, 7};
    int size2 = sizeof(preorder2) / sizeof(preorder2[0]);
    struct TreeNode* root2 = bstFromPreorder(preorder2, size2);
    printf("测试用例2 - 前序遍历: [4, 2, 1, 3, 6, 5, 7]\n");
    printf("顺序存储结果: ");
    printArrayStorage(root2);
    freeTree(root2);
    printf("\n");
    
    // 测试用例3 - 单节点
    int preorder3[] = {5};
    int size3 = sizeof(preorder3) / sizeof(preorder3[0]);
    struct TreeNode* root3 = bstFromPreorder(preorder3, size3);
    printf("测试用例3 - 前序遍历: [5]\n");
    printf("顺序存储结果: ");
    printArrayStorage(root3);
    freeTree(root3);
    printf("\n");
    
    // 测试用例4 - 只有右子树
    int preorder4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(preorder4) / sizeof(preorder4[0]);
    struct TreeNode* root4 = bstFromPreorder(preorder4, size4);
    printf("测试用例4 - 前序遍历: [1, 2, 3, 4, 5]\n");
    printf("顺序存储结果: ");
    printArrayStorage(root4);
    freeTree(root4);
    printf("\n");
    
    // 测试用例5 - 空树
    printf("测试用例5 - 前序遍历: []\n");
    printf("顺序存储结果: ");
    printArrayStorage(NULL);
    
    return 0;
}