//建立函数找到二叉树任意两个节点之间距离的最大值
// struct TreeNode{
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

// int diameterOfBinaryTree(struct TreeNode* root){

// }

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max_int(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    return 1 + max_int(height(node->left), height(node->right));
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int throughRoot = leftHeight + rightHeight;
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max_int(throughRoot, max_int(leftDiameter, rightDiameter));
}

// 用于写主程序测试的附加函数
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 构建测试二叉树
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    int diameter = diameterOfBinaryTree(root);
    printf("二叉树的直径为: %d\n", diameter); // 应该输出 3
    
    // 构建另一个测试二叉树
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //  /         \
    // 7           8
    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);
    root2->right->right = createNode(6);
    root2->left->left->left = createNode(7);
    root2->right->right->right = createNode(8);
    
    diameter = diameterOfBinaryTree(root2);
    printf("第二个二叉树的直径为: %d\n", diameter); // 应该输出 6
    
    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);
    
    free(root2->left->left->left);
    free(root2->left->left);
    free(root2->left->right);
    free(root2->left);
    free(root2->right->right->right);
    free(root2->right->right);
    free(root2->right);
    free(root2);
    
    return 0;
}