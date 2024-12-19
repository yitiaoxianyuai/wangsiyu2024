#include <stdio.h>

// 交换两个整数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = { 5, 4, 3, 2, 1 };  // 可替换为你要排序的数组
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
~                                                                                                                                                                                
~                                                                                                                                                                                
~                                                                                                                                                                                
~                                                                                                                                                                                
~                                                                                                                                                                                
~                                                                                                                                                                                
~                           
