# 스택만 구현
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100000  // 스택의 최대 크기

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 스택 초기화
void initStack(Stack *s) {
    s->top = -1;
}

// 스택이 비어 있는지 확인
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// 스택이 가득 찼는지 확인
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// 삽입
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// 제거
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// 스택의 top 요소 확인
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

// 스택 상태 출력
void printStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

// 테스트 코드 (메인 함수)
int main() {

    return 0;
}
