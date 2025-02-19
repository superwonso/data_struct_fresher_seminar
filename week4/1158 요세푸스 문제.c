#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* link;
} node;

node* insert(int d, node* pre) {
    node* tmp = (node*)malloc(sizeof(node));
    tmp->data = d;
    tmp->link = pre->link;
    pre->link = tmp;
    return tmp;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    node* head = (node*)malloc(sizeof(node));
    head->data = 1;
    head->link = head;

    node* tail = head;
    for (int i = 2; i <= n; i++) {
        tail = insert(i, tail);
    }

    printf("<");
    node* pre = tail, *now = head;
    while (n--) {
        for (int i = 1; i < k; i++) {
            pre = now;
            now = now->link;
        }
        printf("%d%s", now->data, n ? ", " : "");

        pre->link = now->link;
        free(now);
        now = pre->link;
    }
    printf(">");
    return 0;
}