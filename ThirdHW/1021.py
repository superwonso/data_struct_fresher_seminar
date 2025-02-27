//큐만 구현
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 큐의 최대 크기

typedef struct {
    int data[MAX_SIZE];
    int front, rear, size;
} CircularQueue;

// 초기화
void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// 삽입
void enqueue(CircularQueue *q, int value) {
    if (q->size == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

// 삭제
void dequeue(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
}

// 왼쪽으로 한 칸 이동
void rotateLeft(CircularQueue *q) {
    if (q->size <= 1) return;
    int first = q->data[q->front];
    dequeue(q);
    enqueue(q, first);
}

// 오른쪽으로 한 칸 이동
void rotateRight(CircularQueue *q) {
    if (q->size <= 1) return;
    int last = q->data[q->rear];
    for (int i = q->rear; i != q->front; i = (i - 1 + MAX_SIZE) % MAX_SIZE) {
        q->data[i] = q->data[(i - 1 + MAX_SIZE) % MAX_SIZE];
    }
    q->data[q->front] = last;
}

// 큐 출력
void printQueue(CircularQueue *q) {
    if (q->size == 0) {
        printf("Queue is empty!\n");
        return;
    }
    int index = q->front;
    for (int i = 0; i < q->size; i++) {
        printf("%d ", q->data[index]);
        index = (index + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {

    return 0;
}
