#include <stdio.h>

// 判断是否为闰年
int is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0);
}

// 计算从1900年1月1日到给定日期的总天数
int total_days(int year, int month, int day) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        days[2] = 29;
    }
    int total = 0;
    for (int y = 1900; y < year; y++) {
        total += is_leap_year(y)? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        total += days[m];
    }
    total += day;
    return total;
}

int main() {
    int year, month, day;
    printf("请输入年 月 日（空格隔开）：");
    scanf("%d %d %d", &year, &month, &day);
    int days_since_1900 = total_days(year, month, day);
    int weekday = (days_since_1900 + 1) % 7;  // 1900年1月1日是周一，加1调整
    char *weekdays[] = {"周一", "周二", "周三", "周四", "周五", "周六", "周日"};
    printf("%d年%d月%d日是 %s\n", year, month, day, weekdays[weekday]);
    return 0;
}
#include <stdio.h>

// 判断是否为闰年
int is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0);
}

// 获取该月的天数
int get_days_in_month(int year, int month) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year) && month == 2) {
        return 29;
    }
    return days[month];
}

// 输出日历头部（星期几的表头）
void print_header() {
    printf("日 一 二 三 四 五 六\n");
}

// 输出日历主体内容
void print_calendar(int year, int month) {
    int days_in_month = get_days_in_month(year, month);
    int first_day = (total_days(year, month, 1) + 1) % 7;  // 计算该月1号是星期几
    int i;
    for (i = 0; i < first_day; i++) {
        printf("   ");
    }
    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        if ((first_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    if ((first_day + days_in_month) % 7!= 0) {
        printf("\n");
    }
}

int total_days(int year, int month, int day) {
    // 同上面计算总天数的函数实现
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        days[2] = 29;
    }
    int total = 0;
    for (int y = 1900; y < year; y++) {
        total += is_leap_year(y)? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        total += days[m];
    }
    total += day;
    return total;
}

int main() {
    int year, month;
    printf("请输入年份 月份（空格隔开）：");
    scanf("%d %d", &year, &month);
    print_header();
    print_calendar(year, month);
    return 0;
}
#include <stdio.h>

// 判断是否为闰年
int is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100!= 0) || year % 400 == 0);
}

// 获取该月的天数
int get_days_in_month(int year, int month) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year) && month == 2) {
        return 29;
    }
    return days[month];
}

// 输出日历头部（星期几的表头）
void print_header() {
    printf("日 一 二 三 四 五 六\n");
}

// 输出日历主体内容
void print_calendar(int year, int month) {
    int days_in_month = get_days_in_month(year, month);
    int first_day = (total_days(year, month, 1) + 1) % 7;  // 计算该月1号是星期几
    int i;
    for (i = 0; i < first_day; i++) {
        printf("   ");
    }
    for (int day = 1; day <= days_in_month; day++) {
        printf("%2d ", day);
        if ((first_day + day) % 7 == 0) {
            printf("\n");
        }
    }
    if ((first_day + days_in_month) % 7!= 0) {
        printf("\n");
    }
}

// 计算从1900年1月1日到给定日期的总天数
int total_days(int year, int month, int day) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_leap_year(year)) {
        days[2] = 29;
    }
    int total = 0;
    for (int y = 1900; y < year; y++) {
        total += is_leap_year(y)? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        total += days[m];
    }
    total += day;
    return total;
}

int main() {
    int year;
    printf("请输入年份：");
    scanf("%d", &year);
    for (int month = 1; month <= 12; month++) {
        printf("    %d月\n", month);
        print_header();
        print_calendar(year, month);
        printf("\n");
    }
    return 0;
}
