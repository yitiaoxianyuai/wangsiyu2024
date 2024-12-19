#include <stdio.h>
#include <stdlib.h>

#define N 8

// 检查当前位置是否可以放置皇后
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // 检查同一列
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // 检查左上方对角线
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // 检查右上方对角线
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// 解决八皇后问题的递归函数
void solveNQueens(int board[N][N], int row) {
    if (row == N) {
        // 找到一个解决方案，打印棋盘
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == 1) {
                    printf("Q ");
                } else {
                                                                                                                                                               1,1          顶端                  printf(". ");
                }
            }
            printf("\n");
        }
        printf("\n");
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            board[row][col] = 0;
        }
    }
}

// 主函数调用解决八皇后问题的函数
int main() {
    int board[N][N] = {0};
    solveNQueens(board, 0);
    return 0;
}
