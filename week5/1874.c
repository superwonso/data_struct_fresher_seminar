#include <stdio.h>
#include <stdlib.h>

typedef int element;

char* op;  
int* stack;
int top = -1;

int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    stack = (int*)malloc(sizeof(int) * n);
    op = (char*)malloc(sizeof(char) * (n * 2));

    int num = 1; // 스택에 들어갈 원소
    int idx = 0; // arr 인덱스
    int op_idx = 0; // 연산자 인덱스

    while (idx < n) {
        // push
        if (top == -1 || stack[top] < arr[idx]) {
            stack[++top] = num++;
            op[op_idx++] = '+';
        }
        // pop
        else if (stack[top] == arr[idx]) {
            top--;
            op[op_idx++] = '-';
            idx++;
        }
        // 배열 만들기 불가능
        else {
            printf("NO\n");
            free(arr);
            free(stack);
            free(op);
            return 0;
        }
    }

    for (int i = 0; i < op_idx; i++) {
        printf("%c\n", op[i]);
    }
    free(arr);
    free(stack);
    free(op);

    return 0;
}
