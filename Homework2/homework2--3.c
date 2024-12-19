#include <stdio.h>
#include <string.h>

// 计算一行字符的ASCII码之和
int rowAsciiSum(char row[], int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += row[i];
    }
    return sum;
}

// 交换两行字符数组
void swapRows(char A[][6], int row1, int row2) {
    char temp[6];
    strcpy(temp, A[row1]);
    strcpy(A[row1], A[row2]);
    strcpy(A[row2], temp);
}

// 对二维字符数组进行排序
void sortCharArray(char A[][6], int rows) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (rowAsciiSum(A[i], 6) > rowAsciiSum(A[j], 6)) {
                swapRows(A, i, j);
            } else if (rowAsciiSum(A[i], 6) == rowAsciiSum(A[j], 6)) {
                for (int k = 0; k < 6; k++) {
                    if (A[i][k] > A[j][k]) {
                        swapRows(A, i, j);
                        break;
                    } else if (A[i][k] < A[j][k]) {
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    char A[][6] = {
                                                                                                                                                               1,1          顶端        "abcde",
        "fghij",
        "klmno"
    };
    int rows = sizeof(A) / sizeof(A[0]);

    sortCharArray(A, rows);

    // 输出排序后的二维字符数组
    for (int i = 0; i < rows; i++) {
        printf("%s\n", A[i]);
    }

    return 0;
}
