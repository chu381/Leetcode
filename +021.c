//有一个矩阵mat，其中的元素仅有0或者1
//目标是找到这个矩阵含有1的列的下标最小值，若没有1，则返回-1
//1 <= mat.length, mat[i].length <= 100
//mat[i]已经根据从小到大的顺序排列
//要求要用给定的结构BinaryMatrix解决问题


#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct BinaryMatrix{
    int (*get)(struct BinaryMatrix*, int, int);
    int* (*dimensions)(struct BinaryMatrix*);
};

int leftMostColumnWithOne(struct BinaryMatrix* matrix){
    //例如取3行4列的元素，matrix->get(matrix, 3, 4)
    //而这个矩阵的行列数目存在matrix->dimensions(matrix)[0]和matrix->dimensions(matrix)[1]中
    int m=matrix->dimensions(matrix)[0];
    int n=matrix->dimensions(matrix)[1];
    int answer=n;
    for(int i=0; i<m; i++){
        //每行用二分法做，优化为O(nlogn)
        int first_one=n;
        int left=0;
        int right=n-1;
        int mid=-1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(matrix->get(matrix, i, mid)==1){
                first_one=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        if(first_one<answer){
            answer=first_one;
        }
    }
    if(answer==n)answer=-1;
    return answer;
}

// 定义全局变量来存储矩阵信息
static int** mat_data = NULL;
static int rows = 0;
static int cols = 0;

// 实现get函数
int get_func(struct BinaryMatrix* bm, int i, int j) {
    return mat_data[i][j];
}

// 实现dimensions函数
int* dimensions_func(struct BinaryMatrix* bm) {
    static int dim[2];
    dim[0] = rows;
    dim[1] = cols;
    return dim;
}

int main() {

    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);

    // 示例矩阵数据，可以根据需要修改
    int data[3][4] = {
        {0, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 1, 1}
    };
    rows = 3;
    cols = 4;

    // 动态分配二维数组并赋值
    mat_data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        mat_data[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            mat_data[i][j] = data[i][j];
        }
    }

    // 创建BinaryMatrix结构实例
    struct BinaryMatrix bm;
    bm.get = get_func;
    bm.dimensions = dimensions_func;

    // 调用函数并输出结果
    int result = leftMostColumnWithOne(&bm);
    printf("Leftmost column with one: %d\n", result);

    // 释放内存
    for (int i = 0; i < rows; i++) {
        free(mat_data[i]);
    }
    free(mat_data);

    return 0;
}