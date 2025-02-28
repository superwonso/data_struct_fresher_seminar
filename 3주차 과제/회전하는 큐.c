#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef int element;

typedef struct {
    element data[SIZE];
    int rear, front;
} QueueType;

void init(QueueType* Q) {
    Q->rear = Q->front = 0;
}

int is_empty(QueueType* Q) {
    return Q->front == Q->rear;
}

void enqueue(QueueType* Q, int n) {
    for (int i = 0; i <= n; i++) {
        Q->rear = (Q->rear + 1) % SIZE;
        Q->data[Q->rear] = i+1; 
    }
}

element dequeue(QueueType* Q) {
    if (is_empty(Q)) {
        printf("Empty\n");
        return -1;
    }
    Q->front = (Q->front + 1) % SIZE;
    return Q->data[Q->front];
}

void right(QueueType* Q) { 
    Q->front = (Q->front + 1) % SIZE;
    Q->rear = (Q->rear + 1) % SIZE;
}

void left(QueueType* Q) { 
    Q->front = (Q->front - 1 + SIZE) % SIZE;
    Q->rear = (Q->rear - 1 + SIZE) % SIZE;
}

int size(QueueType* Q) {
    return (Q->rear - Q->front + SIZE) % SIZE;
}

int find(QueueType* Q, element e) {
    int index = (Q->front + 1) % SIZE;
    for (int i = 0; i < size(Q); i++) {
        if (Q->data[index] == e)
            return index;
        index = (index + 1) % SIZE;
    }
    return -1; 
}


int get_front_index(QueueType* Q) {
    return (Q->front + 1) % SIZE;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    QueueType Q;
    init(&Q);
    enqueue(&Q, n);
    int count = 0;

    for (int i = 0; i < m; i++) {
        int qsize = size(&Q);
        int index = find(&Q, arr[i]);
        int front_index = get_front_index(&Q);

        if (index == front_index) { 
            dequeue(&Q);
            continue;
        }

        int left_dist = (index - front_index + SIZE) % SIZE;
        int right_dist = qsize - left_dist;

        if (left_dist <= right_dist) {
            count += left_dist;
            for (int j = 0; j < left_dist; j++)
                left(&Q);
        }
        else { 
            count += right_dist;
            for (int j = 0; j < right_dist; j++)
                right(&Q);
        }
        dequeue(&Q);
    }

    printf("%d\n", count);
    free(arr);
    return 0;
}
