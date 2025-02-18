#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node* right;
    struct node* left;
} node;

void append(char d, node* now) {
    node* new = (node*)malloc(sizeof(node));
    node* pre = now->left;

    new->right = now;
    new->left = pre;
    new->data = d;

    pre->right = new;
    now->left = new;
}

node* delete(node* now) {
    if (now->left == NULL || now->right == NULL) {
        return now;  // 예외 처리: 잘못된 노드 삭제 방지
    }

    node* pre = now->left;
    node* next = now->right;

    pre->right = next;
    next->left = pre;

    free(now);
    return next;
}

void print_list(node* head) {
    node* tmp = head->right;
    while (tmp->right != NULL) {
        putchar(tmp->data);
        tmp = tmp->right;
    }
    printf("\n");
}

int main() {
    // 초기 이중 연결 리스트
    node* head = (node*)malloc(sizeof(node));
    node* tail = (node*)malloc(sizeof(node));
    head->right = tail;
    tail->left = head;
    head->left = tail->right = NULL;

    // 리스트 입력
    char tmp[100000];
    scanf("%s", tmp);

    node* now = tail;
    int len = strlen(tmp);
    for (int i = len - 1; i >= 0; i--) {
        append(tmp[i], now);
        now = now->left;
    }

    // 명령어 개수
    int m;
    scanf("%d", &m);

    // 명령어 처리
    node* cursor = tail;
    for (int i = 0; i < m; i++) {
        char cmd;
        scanf(" %c", &cmd);

        if (cmd == 'L') {
            if (cursor->left != head) {cursor = cursor->left;}
        } else if (cmd == 'D') {
            if (cursor != tail) {cursor = cursor->right;}
        } else if (cmd == 'B') {
            if (cursor->left != head) { cursor = delete(cursor->left);}
        } else if (cmd == 'P') {
            char x;
            scanf(" %c", &x);
            append(x, cursor);
        }
    }

    print_list(head);
    return 0;
}
