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

    int num = 1; // ���ÿ� �� ����
    int idx = 0; // arr �ε���
    int op_idx = 0; // ������ �ε���

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
        // �迭 ����� �Ұ���
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