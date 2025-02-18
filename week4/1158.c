#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* link;
} listNode;

listNode* createList(int N) {
    listNode* head = NULL;
    listNode* temp = NULL;
    listNode* newNode;

    for (int i = 1; i <= N; i++) {
        newNode = (listNode*)malloc(sizeof(listNode));
        newNode->data = i;

        if (head == NULL) {
            head = newNode;
            newNode->link = head;
            temp = newNode;
        }
        else {
            temp->link = newNode;
            newNode->link = head;
            temp = newNode;
        }
    }
    return head;
}

listNode* findKthNode(listNode* start, int K) {
    listNode* temp = start;
    for (int i = 1; i < K; i++) {
        temp = temp->link;
    }
    return temp;
}

listNode* deleteKthNode(listNode* head, listNode* target) {
    listNode* temp = head;

    if (head == target && head->link == head) {
        free(head);
        return NULL;
    }

    while (temp->link != target) {
        temp = temp->link;
    }
    temp->link = target->link;

    if (head == target) {
        if (head->link == head) {
            free(head);
            return NULL;
        }
        head = target->link;
    }

    free(target);
    return head;
}

void josephus(int N, int K) {
    listNode* head = createList(N);
    listNode* current = head;

    printf("<");

    while (head != NULL) {
        current = findKthNode(current, K);
        printf("%d", current->data);

        head = deleteKthNode(head, current);
        if (head != NULL) {
            printf(", ");
            current = current->link;
        }
    }

    printf(">\n");
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    josephus(N, K);
    return 0;
}
