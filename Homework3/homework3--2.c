#include <stdio.h>
#include <stdlib.h>

// 链表节点结构体
typedef struct list_item {
    int data;
    struct list_item *next;
} list_item;

// 创建新节点函数
list_item *create_node(int value) {
    list_item *new_node = (list_item *)malloc(sizeof(list_item));
    if (new_node == NULL) {
        perror("Memory allocation failed");
        return NULL;
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

// 在链表末尾添加节点函数
void append_node(list_item **head, int value) {
    list_item *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    list_item *current = *head;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_node;
}

// 非递归版本的链表空间释放函数
void erase_list(list_item *head) {
    list_item *current = head;
    list_item *next;

    while (current!= NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    list_item *head = NULL;

    // 创建并添加一些节点到链表
    append_node(&head, 10);
    append_node(&head, 20);
    append_node(&head, 30);

    // 释放链表空间
    erase_list(head);

    // 此时链表已被释放，head应该为NULL
    if (head == NULL) {
        printf("链表空间已成功释放。\n");
    } else {
        printf("链表空间释放失败。\n");
    }

    return 0;
}
