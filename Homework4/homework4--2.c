#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>  // for usleep() on Unix-like systems

#ifdef _WIN32
#include <windows.h>  // for Sleep() on Windows
#define usleep(x) Sleep(x / 1000)
#endif

#define WIDTH 80
#define HEIGHT 24
#define DROP_SPEED 100000  // Microseconds (100000 us = 0.1 sec)
#define CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:'\",.<>/?/"

// 函数声明部分
void clear_screen();
void move_down(char screen[HEIGHT][WIDTH], int *drops);

// 函数定义部分
void clear_screen() {
    // ANSI escape code to clear the screen
    printf("\033[H\033[J");
}

void move_down(char screen[HEIGHT][WIDTH], int *drops) {
    for (int i = HEIGHT - 1; i > 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            screen[i][j] = screen[i - 1][j];
        }
    }
    // Clear the top row
    for (int j = 0; j < WIDTH; j++) {
        screen[0][j] =' ';
    }
    // Update the drop positions
    for (int i = 0; i < HEIGHT; i++) {
        if (screen[i][drops[i] % WIDTH] =='') {
            screen[i][drops[i] % WIDTH] = CHARACTERS[rand() % strlen(CHARACTERS)];
        }
        drops[i] += 1;
    }
}

int main() {
    srand(time(NULL));
    char screen[HEIGHT][WIDTH];
    int drops[HEIGHT];

    // Initialize the screen and drop positions
    clear_screen();
    memset(screen,'', sizeof(screen));
    for (int i = 0; i < HEIGHT; i++) {
        drops[i] = rand() % WIDTH;
    }

    while (1) {
        // Print the current screen
        for (int i = 0; i < HEIGHT; i++) {
            printf("%.*s\n", WIDTH, screen[i]);
        }
        // Move the code down and update the screen
        move_down(screen, drops);
        // Clear the screen before the next frame
        clear_screen();
        // Sleep for a short period to control the speed of the animation
        usleep(DROP_SPEED);
    }
    return 0;
}
