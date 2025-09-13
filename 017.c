//小岛判定问题，输入一个仅包含元素0或者1的矩阵，其中1表示土地，0表示海水
//当一块土地上下左右四个方向上有其它土地，则视为同一个岛屿
//输出岛屿的数量
//int numIslands(char** grid, int gridSize, int* gridColSize){}

#include<stdio.h>
#include<windows.h>

//标记并消除同一作岛屿
void turn(char** grid, int gridSize, int* gridColSize, int i, int j){
    if(grid[i][j]=='0')return;
    grid[i][j]='0';
    if(i!=0)turn(grid, gridSize, gridColSize, i-1, j);
    if(i!=gridSize-1)turn(grid, gridSize, gridColSize, i+1, j);
    if(j!=0)turn(grid, gridSize, gridColSize, i, j-1);
    if(j!=*gridColSize-1)turn(grid, gridSize, gridColSize, i, j+1);
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int answer=0;
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<*gridColSize; j++){
            if(grid[i][j]=='1'){
                answer++;
                turn(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return answer;
}

int main() {
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    // 定义测试网格
    char gridData[][5] = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    int gridSize = 4;
    int gridColSize = 5;

    // 动态分配二维数组 grid
    char** grid = (char**)malloc(gridSize * sizeof(char*));
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (char*)malloc(gridColSize * sizeof(char));
        for (int j = 0; j < gridColSize; j++) {
            grid[i][j] = gridData[i][j];
        }
    }

    // 调用函数计算岛屿数量
    int result = numIslands(grid, gridSize, &gridColSize);
    printf("岛屿数量: %d\n", result);

    // 释放动态分配的内存
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}