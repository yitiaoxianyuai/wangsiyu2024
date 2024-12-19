#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 15

// 五子棋棋盘结构体
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} GobangBoard;

// 初始化棋盘
void initBoard(GobangBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = '.';
        }
    }
}

// 打印棋盘
void printBoard(GobangBoard board) {
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board.board[i][j]);
        }
        printf("\n");
    }
}

// 判断某个方向上是否有连续相同棋子达到五子
int countSameInDirection(GobangBoard board, int x, int y, int dx, int dy, char player) {
    int count = 0;
    for (int i = x, j = y; i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && board.board[i][j] == player; i += dx, j += dy) {
        count++;
    }
    for (int i = x - dx, j = y - dy; i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && board.board[i][j] == player; i -= dx, j -= dy) {
        count++;
    }
    return count;
}

// 判断是否有玩家获胜
int checkWin(GobangBoard board, char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j] == player) {
                // 检查水平方向
                if (countSameInDirection(board, i, j, 0, 1, player) >= 5) return 1;
                // 检查垂直方向
                if (countSameInDirection(board, i, j, 1, 0, player) >= 5) return 1;
                // 检查正斜线方向
                if (countSameInDirection(board, i, j, 1, 1, player) >= 5) return 1;
                // 检查反斜线方向
                if (countSameInDirection(board, i, j, 1, -1, player) >= 5) return 1;
            }
        }
    }
    return 0;
}

// 双人对战模式
void twoPlayerMode(GobangBoard *board) {
    char players[] = {'X', 'O'};
    int currentPlayer = 0;
    int moveX, moveY;
    while (1) {
        printBoard(*board);
        printf("玩家 %c 请输入行和列（用空格隔开）: ", players[currentPlayer]);
        scanf("%d %d", &moveX, &moveY);
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE || board->board[moveX][moveY]!= '.') {
            printf("非法移动，请重新输入！\n");
            continue;
        }
        board->board[moveX][moveY] = players[currentPlayer];
        if (checkWin(*board, players[currentPlayer])) {
            printBoard(*board);
            printf("玩家 %c 获胜！\n", players[currentPlayer]);
            break;
        }
        currentPlayer = (currentPlayer + 1) % 2;
    }
}

// 简单的五子棋智能体（随机选择空位下棋，只是示例，可优化策略）
void computerMove(GobangBoard *board, char computerPlayer) {
    int emptyCells[BOARD_SIZE * BOARD_SIZE][2];
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == '.') {
                emptyCells[count][0] = i;
                emptyCells[count][1] = j;
                count++;
            }
        }
    }
    if (count > 0) {
        int randomIndex = rand() % count;
        board->board[emptyCells[randomIndex][0]][emptyCells[randomIndex][1]] = computerPlayer;
    }
}

// 人机对战模式
void humanVsComputerMode(GobangBoard *board) {
    char humanPlayer = 'X';
    char computerPlayer = 'O';
    int moveX, moveY;
    while (1) {
        printBoard(*board);
        // 人类玩家回合
        printf("你（%c）请输入行和列（用空格隔开）: ", humanPlayer);
        scanf("%d %d", &moveX, &moveY);
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE || board->board[moveX][moveY]!= '.') {
            printf("非法移动，请重新输入！\n");
            continue;
        }
        board->board[moveX][moveY] = humanPlayer;
        if (checkWin(*board, humanPlayer)) {
            printBoard(*board);
            printf("你获胜了！\n");
            break;
        }
        // 电脑玩家回合
        computerMove(board, computerPlayer);
        if (checkWin(*board, computerPlayer)) {
            printBoard(*board);
            printf("电脑获胜了！\n");
            break;
        }
    }
}

int main() {
    GobangBoard board;
    initBoard(&board);
    srand((unsigned int)time(NULL));
    int choice;
    printf("1. 双人对战\n2. 人机对战\n请选择游戏模式: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        twoPlayerMode(&board);
        break;
    case 2:
        humanVsComputerMode(&board);
        break;
    default:
        printf("无效选择\n");
    }
    return 0;
}
