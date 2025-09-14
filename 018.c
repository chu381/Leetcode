//最小路问题
//给定一个元素为int的矩阵grid，从左上角一次移动一格到右下角，求经过的数字之和的最小值
//int minPathSum(int** grid, int gridSize, int* gridColSize){}

#include<stdio.h>
#include<windows.h>

int Min(int a, int b){
    return a < b ? a : b;
}

int minPathSum(int** grid, int row, int col, int i, int j){
    if(i == 0 && j == 0) return grid[0][0];
    if(i == 0) return minPathSum(grid, row, col, i, j-1) + grid[i][j];
    if(j == 0) return minPathSum(grid, row, col, i-1, j) + grid[i][j];
    return Min(minPathSum(grid, row, col, i-1, j), minPathSum(grid, row, col, i, j-1)) + grid[i][j];
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
    
    // 注意：这里传递的是终点坐标 (2, 2)，因为索引从0开始
    int result1 = minPathSum(grid1, gridSize1, gridColSize1, gridSize1-1, gridColSize1-1);
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
    
    // 注意：这里传递的是终点坐标 (1, 2)
    int result2 = minPathSum(grid2, gridSize2, gridColSize2, gridSize2-1, gridColSize2-1);
    printf("最小路径和: %d\n", result2);
    
    return 0;
}