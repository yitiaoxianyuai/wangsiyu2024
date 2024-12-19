#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

// 分割字符串得到单词数组
void split_string(char *str, char *words[], int *num_words) {
    char *token = strtok(str, " ");
    *num_words = 0;

    while (token!= NULL) {
        words[*num_words] = token;
        (*num_words)++;
        token = strtok(NULL, " ");
    }
}

// 处理输入并统计单词相关信息
void process_input() {
    char *input[MAX_LINES];
    int line_count = 0;

    printf("请输入多行英文字符串，输入END结束：\n");

    // 接收用户输入
    while (line_count < MAX_LINES) {
        input[line_count] = (char *)malloc(MAX_LENGTH * sizeof(char));
        fgets(input[line_count], MAX_LENGTH, stdin);

        // 去除换行符
        input[line_count][strcspn(input[line_count], "\n")] = '\0';

        // 判断是否结束输入
        if (strcmp(input[line_count], "END") == 0) {
            break;
        }

        line_count++;
    }

    // 用于存储单词及其相关计数信息
    char *words[MAX_LINES * MAX_LENGTH];
    int word_line_count[MAX_LINES * MAX_LENGTH][MAX_LINES];
    int word_total_count[MAX_LINES * MAX_LENGTH];
    int unique_word_count = 0;

    // 初始化计数数组
    for (int i = 0; i < MAX_LINES * MAX_LENGTH; i++) {
        for (int j = 0; j < MAX_LINES; j++) {
            word_line_count[i][j] = 0;
        }
        word_total_count[i] = 0;
    }

    // 处理每一行输入，统计单词信息
    for (int i = 0; i < line_count; i++) {
        int num_words;
        char *line_words[MAX_LENGTH];

        split_string(input[i], line_words, &num_words);

        for (int j = 0; j < num_words; j++) {
            int found = 0;

            for (int k = 0; k < unique_word_count; k++) {
                if (strcmp(line_words[j], words[k]) == 0) {
                    word_line_count[k][i]++;
                    word_total_count[k]++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                words[unique_word_count] = line_words[j];
                for (int l = 0; l < MAX_LINES; l++) {
                    word_line_count[unique_word_count][l] = 0;
                }
                word_line_count[unique_word_count][i] = 1;
                word_total_count[unique_word_count] = 1;
                unique_word_count++;
            }
        }
    }

    // 输出统计结果
    printf("\n统计结果如下：\n");
    for (int i = 0; i < unique_word_count; i++) {
        printf("单词：%s\n", words[i]);
        printf("在每一行出现的次数：");
        for (int j = 0; j < line_count; j++) {
            printf("%d ", word_line_count[i][j]);
        }
        printf("\n在输入中总共出现的次数：%d\n\n", word_total_count[i]);
    }

    // 释放为存储输入字符串分配的内存
    for (int i = 0; i < line_count; i++) {
        free(input[i]);
    }
}

int main() {
    process_input();

    return 0;
}
