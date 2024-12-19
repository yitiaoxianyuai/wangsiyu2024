#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 定义棋盘大小
#define BOARD_SIZE 3

// 井字棋棋盘结构体
typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
} TicTacToeBoard;

// 初始化棋盘
void initBoard(TicTacToeBoard *board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] ='';
        }
    }
}

// 打印棋盘
void printBoard(TicTacToeBoard board) {
    printf("  0 1 2\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board.board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("| ");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            printf("  -----\n");
        }
    }
}

// 判断是否有玩家获胜
int checkWin(TicTacToeBoard board, char player) {
    // 检查行
    for (int i = 0; i < BOARD_SIZE; i++) {
        int win = 1;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board.board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    // 检查列
    for (int j = 0; j < BOARD_SIZE; j++) {
        int win = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board.board[i][j]!= player) {
                win = 0;
                break;
            }
        }
        if (win) return 1;
    }
    // 检查对角线
    int win1 = 1, win2 = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board.board[i][i]!= player) win1 = 0;
        if (board.board[i][BOARD_SIZE - 1 - i]!= player) win2 = 0;
    }
    if (win1 || win2) return 1;

    return 0;
}

// 双人对战模式
void twoPlayerMode(TicTacToeBoard *board) {
    char players[] = {'X', 'O'};
    int currentPlayer = 0;
    int moveX, moveY;
    while (1) {
        printBoard(*board);
        printf("玩家 %c 请输入行和列（用空格隔开）: ", players[currentPlayer]);
        scanf("%d %d", &moveX, &moveY);
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE || board->board[moveX][moveY]!='') {
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

// 简单的井字棋智能体（随机选择空位下棋）
void computerMove(TicTacToeBoard *board, char computerPlayer) {
    int emptyCells[BOARD_SIZE * BOARD_SIZE][2];
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] =='') {
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
void humanVsComputerMode(TicTacToeBoard *board) {
    char humanPlayer = 'X';
    char computerPlayer = 'O';
    int moveX, moveY;
    while (1) {
        printBoard(*board);
        // 人类玩家回合
        printf("你（%c）请输入行和列（用空格隔开）: ", humanPlayer);
        scanf("%d %d", &moveX, &moveY);
        if (moveX < 0 || moveX >= BOARD_SIZE || moveY < 0 || moveY >= BOARD_SIZE || board->board[moveX][moveY]!='') {
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
    TicTacToeBoard board;
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
