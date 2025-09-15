//有一个由小到大排列的数列，每一个元素向右平移若干格（最右边的元素移动到最左侧）
//我们要在这个数列nums中寻找一个元素并输出它的下标，没有则输出下标
//int search(int* nums; int numsSize; int target){}

#include<stdio.h>
#include<windows.h>

//时间复杂度控制在O(logn)
//就是用二分法，只不过判断逻辑多一层而已
int search(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        
        // 判断左半部分是否有序
        if (nums[left] <= nums[mid]) {
            // 目标值在有序的左半部分
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } 
        // 否则右半部分有序
        else {
            // 目标值在有序的右半部分
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    
    return -1;
}

int main()
{
    // 设置控制台输出编码为UTF-8（Windows）
    SetConsoleOutputCP(65001);
    
    // 测试用例1：正常情况
    int nums1[] = {4, 5, 6, 7, 0, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int target1 = 0;
    int result1 = search(nums1, size1, target1);
    printf("测试用例1：在数组 {4,5,6,7,0,1,2} 中查找 %d\n", target1);
    printf("结果：下标 %d\n\n", result1);
    
    // 测试用例2：查找不存在的元素
    int target2 = 3;
    int result2 = search(nums1, size1, target2);
    printf("测试用例2：在数组 {4,5,6,7,0,1,2} 中查找 %d\n", target2);
    printf("结果：下标 %d\n\n", result2);
    
    // 测试用例3：查找第一个元素
    int target3 = 4;
    int result3 = search(nums1, size1, target3);
    printf("测试用例3：在数组 {4,5,6,7,0,1,2} 中查找 %d\n", target3);
    printf("结果：下标 %d\n\n", result3);
    
    // 测试用例4：查找最后一个元素
    int target4 = 2;
    int result4 = search(nums1, size1, target4);
    printf("测试用例4：在数组 {4,5,6,7,0,1,2} 中查找 %d\n", target4);
    printf("结果：下标 %d\n\n", result4);
    
    // 测试用例5：完全升序的数组（未旋转）
    int nums2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int target5 = 3;
    int result5 = search(nums2, size2, target5);
    printf("测试用例5：在数组 {1,2,3,4,5} 中查找 %d\n", target5);
    printf("结果：下标 %d\n\n", result5);
    
    return 0;
}