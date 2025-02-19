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
    new->data = d;
    
    new->right = now;
    new->left = now->left;
    
    now->left->right = new;
    now->left = new;
}

node* delete(node* now) {
    node* pre = now->left;
    pre->left->right = now;
    now->left = pre->left;
    
    free(pre);
    return now;
}

void print_list(node* head) {
    for (node* tmp = head->right; tmp->right; tmp = tmp->right)
        putchar(tmp->data);
}

int main() {
    node *head = (node*)malloc(sizeof(node)), *tail = (node*)malloc(sizeof(node));
    head->right = tail, tail->left = head;
    head->left = tail->right = NULL;

    char tmp[100000];
    scanf("%s", tmp);

    for (int i = 0; tmp[i]; i++) 
        append(tmp[i], tail);
    
    int m;
    scanf("%d", &m);

    node* cursor = tail;
    while (m--) {
        char cmd, x;
        scanf(" %c", &cmd);
        if (cmd == 'L' && cursor->left != head) cursor = cursor->left;
        else if (cmd == 'D' && cursor != tail) cursor = cursor->right;
        else if (cmd == 'B'&& cursor->left != head) cursor = delete(cursor);
        else if (cmd == 'P') {
            scanf(" %c", &x);
            append(x, cursor);
        }
    }

    print_list(head);
    return 0;
}
