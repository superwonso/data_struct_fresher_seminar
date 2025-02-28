#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNING

typedef struct {
	int value;
	struct Node* prev;
	struct Node* next;
} node;

typedef struct {
	node* front, * rear;
	int size;
} deque;

void init(deque* dq) {
	dq->front = dq->rear = NULL;
	dq->size = 0;
}

node* create(int value) {
	node* new = (node*)malloc(sizeof(node));
	new->value = value;
	new->prev = new->next = NULL;
	return new;
}

void push_back(deque* dq, int value) {
	node* new = create(value);
	if (dq->size == 0) {
		dq->front = dq->rear = new;
	}
	else {
		dq->rear->next = new;
		new->prev = dq->rear;
		dq->rear = new;
	}
	dq->size++;
}

int pop_front(deque* dq) {
	if (dq->size == 0) return 1;
	node* temp = dq->front;
	int value = temp->value;

	if (dq->size == 1) {
		dq->front = dq->rear = NULL;
	}
	else {
		dq->front = dq->front->next;
		dq->front->prev = NULL;
	}

	free(temp);
	dq->size--;
	return value;
}

int pop_back(deque* dq) {
	if (dq->size == 0) return 1;
	node* temp = dq->rear;
	int value = temp->value;

	if (dq->size == 1) {
		dq->front = dq->rear = NULL;
	}
	else {
		dq->rear = dq->rear->prev;
		dq->rear->next = NULL;
	}

	free(temp);
	dq->size--;
	return value;
}

int peek(deque* dq, int target) {
	node* current = dq->front;
	int idx = 0;
	while (current) {
		if (current->value == target) return idx;
		current = current->next;
		idx++;
	}
	return 1;
}

void case2(deque* dq) {
	int value = pop_front(dq);
	push_back(dq, value);
}

void case3(deque* dq) {
	int value = pop_back(dq);
	node* new = create(value);
	if (dq->size == 0) {
		dq->front = dq->rear = new;
	}
	else {
		new->next = dq->front;
		dq->front->prev = new;
		dq->front = new;
	}
	dq->size++;
}

void freedeque(deque* dq) {
	while (dq->size > 0) {
		pop_front(dq);
	}
}

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int* arr = (int*)malloc(M * sizeof(int));

	for (int i = 0; i < M; i++) {
		scanf("%d", &arr[i]);
	}

	deque* dq;
	init(&dq);

	for (int i = 1; i <= N; i++) {
		push_back(&dq, i);
	}

	int count = 0;

	for (int i = 0; i < M; i++) {
		int num = arr[i];
		int curr = peek(&dq, num);

		if (curr == 0) {
			pop_front(&dq);
		}
		else {
			if (curr <= dq->size / 2) {
				for (int j = 0; j < curr; j++) {
					case2(&dq);
					count++;
				}
			}
			else {
				for (int j = 0; j < (dq->size - curr); j++) {
					case3(&dq);
					count++;
				}
			}
			pop_front(&dq);
		}
	}
	printf("%d\n", count);
	free(arr);
	freedeque(&dq);

	return 0;
}