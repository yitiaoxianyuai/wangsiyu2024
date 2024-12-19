#include <stdio.h>
#include <curses.h>
#include <unistd.h>

int main() {
    initscr();  // 初始化ncurses库
    noecho();   // 关闭回显
    curs_set(0);  // 隐藏光标

    int row = 10;  // 设定显示位置的行
    int col = 10;  // 设定显示位置的列
    char ch = '*';  // 要显示的字符（模拟LED点亮的点）
    while (1) {
    // 多次显示*
    for (int i = 0; i < 150; i++) {
        mvaddch(row, col + i, '*');
    }
    refresh();
    usleep(500000);
    // 清除*
    for (int i = 0; i < 150; i++) {
        mvaddch(row, col + i,'');
    }
    refresh();
    usleep(500000);
}
    while (1) {
        mvaddch(row, col, ch);  // 在指定位置显示字符
        refresh();  // 刷新屏幕显示
        usleep(500000);  // 暂停一段时间，单位是微秒，这里暂停0.5秒
        mvaddch(row, col,'');  // 清除字符（模拟熄灭）
        refresh();
        usleep(500000);
    }

    endwin();  // 结束ncurses库使用，恢复终端默认设置
    return 0;
}

