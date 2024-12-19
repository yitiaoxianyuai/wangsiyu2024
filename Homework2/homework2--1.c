#include <stdio.h>

// 交换两个整数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 选择排序
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex!= i) {
            swap(&arr[i], &arr[minIndex]);
        }
    }
}

int main() {
    int arr[] = { 5, 4, 3, 2, 1 };  // 这里可以替换成你想要排序的数组
    int n = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
~        
