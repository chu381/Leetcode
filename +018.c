//最小路问题
//给定一个元素为int的矩阵grid，从左上角一次移动一格到右下角，求经过的数字之和的最小值
//int minPathSum(int** grid, int gridSize, int* gridColSize){}

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

int Min(int a, int b){
    return a < b ? a : b;
}

// 动态规划解法（高效）
int minPathSum(int** grid, int gridSize, int* gridColSize){
    if(gridSize == 0 || *gridColSize == 0) return 0;
    
    int rows = gridSize;
    int cols = *gridColSize;
    
    // 创建dp表
    int** dp = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++){
        dp[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // 初始化第一个位置
    dp[0][0] = grid[0][0];
    
    // 初始化第一行（只能从左边来）
    for(int j = 1; j < cols; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    // 初始化第一列（只能从上边来）- 修复这里
    for(int i = 1; i < rows; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];  // 修正为 dp[i-1][0]
    }
    
    // 填充dp表
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            dp[i][j] = Min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }
    
    int result = dp[rows-1][cols-1];
    
    // 释放内存
    for(int i = 0; i < rows; i++){
        free(dp[i]);
    }
    free(dp);
    
    return result;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 测试用例1
    int row1[] = {1, 3, 1};
    int row2[] = {1, 5, 1};
    int row3[] = {4, 2, 1};
    int* grid1[] = {row1, row2, row3};
    int gridSize1 = 3;
    int gridColSize1 = 3;
    
    printf("测试矩阵1:\n");
    for(int i = 0; i < gridSize1; i++){
        for(int j = 0; j < gridColSize1; j++){
            printf("%d ", grid1[i][j]);
        }
        printf("\n");
    }
    
    int result1 = minPathSum(grid1, gridSize1, &gridColSize1);
    printf("最小路径和: %d\n\n", result1);
    
    // 测试用例2
    int row4[] = {1, 2, 3};
    int row5[] = {4, 5, 6};
    int* grid2[] = {row4, row5};
    int gridSize2 = 2;
    int gridColSize2 = 3;
    
    printf("测试矩阵2:\n");
    for(int i = 0; i < gridSize2; i++){
        for(int j = 0; j < gridColSize2; j++){
            printf("%d ", grid2[i][j]);
        }
        printf("\n");
    }
    
    int result2 = minPathSum(grid2, gridSize2, &gridColSize2);
    printf("最小路径和: %d\n", result2);
    
    return 0;
}