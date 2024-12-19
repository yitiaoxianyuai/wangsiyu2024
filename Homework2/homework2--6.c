#include <stdio.h>

// 计算二维数组元素地址并返回元素值
int two_dim_array_access(int *x, int i, int j, int m, int n, int C) {
    return *(x + m * C + n);
}

int main() {
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int *ptr = (int *)arr;  // 将二维数组视为一维数组来获取首地址

    int i = 1;  // 示例行索引
    int j = 2;  // 示例列索引
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(arr[0]) / sizeof(int);
    int C = sizeof(arr[0]);

    int value = two_dim_array_access(ptr, i, j, m, n, C);

    printf("二维数组中第 %d 行第 %d 列的元素值为: %d\n", i, j, value);

    return 0;
}
~                   
